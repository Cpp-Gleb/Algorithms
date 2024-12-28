#include <iostream>
#include <queue>

using namespace std;

enum Operations {
    Insert,
    Delete,
    Check,
    Min,
    Max
};

class BST {
public:
    BST();
    void Insert(int newValue);
    void Delete(int value);
    void FindMax(int value);
    void FindMin(int value);
    bool IsExist(int value);
    void inOrder();
    void BFS();

private:
    struct Node {
        int value_;
        Node* left_;
        Node* right_;
        Node(int val) : value_(val), left_(nullptr), right_(nullptr) {}
    };

    Node* root_;

    Node* InsertNode(Node* node, int newValue);
    Node* DeleteNode(Node* node, int value);
    Node* FindMax(Node* node);
    Node* FindMin(Node* node);
    void inOrderTraversal(Node* node);
    void BFS(Node* root);
};

BST::BST() : root_(nullptr) {}

void BST::Insert(int newValue) {
    root_ = InsertNode(root_, newValue);
}

BST::Node* BST::InsertNode(Node* node, int newValue) {
    if (!node) return new Node(newValue);

    if (newValue < node->value_) {
        node->left_ = InsertNode(node->left_, newValue);
    } else if (newValue > node->value_) {
        node->right_ = InsertNode(node->right_, newValue);
    }

    return node;
}

BST::Node* BST::DeleteNode(Node* node, int value) {
    if (!node) return node;

    if (value < node->value_) {
        node->left_ = DeleteNode(node->left_, value);
    } else if (value > node->value_) {
        node->right_ = DeleteNode(node->right_, value);
    } else {
        if (!node->left_) {
            Node* temp = node->right_;
            delete node;
            return temp;
        } else if (!node->right_) {
            Node* temp = node->left_;
            delete node;
            return temp;
        }

        Node* minRight = FindMin(node->right_);
        node->value_ = minRight->value_;
        node->right_ = DeleteNode(node->right_, minRight->value_);
    }
    return node;
}

void BST::Delete(int value) {
    root_ = DeleteNode(root_, value);
}

void BST::FindMax(int value) {
    Node* current = root_;
    Node* candidate = nullptr;
    while (current) {
        if (current->value_ < value) {
            candidate = current;
            current = current->right_;
        } else {
            current = current->left_;
        }
    }
    cout << (candidate ? to_string(candidate->value_) : "none") << '\n';
}

void BST::FindMin(int value) {
    Node* current = root_;
    Node* candidate = nullptr;
    while (current) {
        if (current->value_ > value) {
            candidate = current;
            current = current->left_;
        } else {
            current = current->right_;
        }
    }
    cout << (candidate ? to_string(candidate->value_) : "none") << '\n';
}

BST::Node* BST::FindMax(Node* node) {
    while (node && node->right_ != nullptr) {
        node = node->right_;
    }
    return node;
}

BST::Node* BST::FindMin(Node* node) {
    while (node && node->left_ != nullptr) {
        node = node->left_;
    }
    return node;
}

bool BST::IsExist(int value) {
    Node* current = root_;
    while (current != nullptr) {
        if (current->value_ == value) {
            return true;
        }
        current = (current->value_ < value) ? current->right_ : current->left_;
    }
    return false;
}

void BST::BFS() {
    BFS(root_);
}

void BST::BFS(Node* root) {
    if (!root) return;

    std::queue<Node*> queue;
    queue.push(root);

    while (!queue.empty()) {
        int levelSize = queue.size();
        Node* rightmost = nullptr;

        for (int i = 0; i < levelSize; ++i) {
            Node* node = queue.front();
            queue.pop();
            rightmost = node;

            if (node->left_) queue.push(node->left_);
            if (node->right_) queue.push(node->right_);
        }

        if (rightmost) {
            std::cout << rightmost->value_ << " ";
        }
    }
}

void BST::inOrderTraversal(Node *node) {
    if (node == nullptr) {
        return;
    }
    inOrderTraversal(node->left_);
    cout << node->value_ << ' ';
    inOrderTraversal(node->right_);
}

void BST::inOrder() {
    inOrderTraversal(root_);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    BST tree;
    int operation;
    int value;
    while (cin >> operation >> value) {
        if (operation == Operations::Insert) {
            tree.Insert(value);
        } else if (operation == Operations::Delete) {
            tree.Delete(value);
        } else if (operation == Operations::Check) {
            cout << (tree.IsExist(value) ? "true" : "false") << '\n';
        } else if (operation == Operations::Min) {
            tree.FindMin(value);
        } else if (operation == Operations::Max) {
            tree.FindMax(value);
        }
    }
    return 0;
}
