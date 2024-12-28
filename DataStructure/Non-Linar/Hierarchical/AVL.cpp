#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class AVL {
public:
    AVL();
    ~AVL();

    void Insert(const T& key);
    void Remove(const T& key);

    void InOrderTraversal() const;
    void PreOrderTraversal() const;
    void PostOrderTraversal() const;

private:
    struct Node {
        T value;
        int count;
        Node* left;
        Node* right;
        int height;
        Node(const T& val) : value(val), count(1), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    Node* insert(Node* node, const T& key);
    Node* remove(Node* node, const T& key);
    Node* findMin(Node* node);

    int getHeight(Node* node) const;
    int getBalance(Node* node) const;

    Node* RR(Node* unbalanced);
    Node* LL(Node* unbalanced);
    Node* LR(Node* unbalanced);
    Node* RL(Node* unbalanced);

    Node* rebalance(Node* node);

    void inOrderTraversal(Node* node) const;
    void preOrderTraversal(Node* node) const;
    void postOrderTraversal(Node* node) const;

    void clear(Node* node);
};

template <typename T>
AVL<T>::AVL() : root(nullptr) {}

template <typename T>
AVL<T>::~AVL() {
    clear(root);
}

template <typename T>
void AVL<T>::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template <typename T>
int AVL<T>::getHeight(Node* node) const {
    return node ? node->height : 0;
}

template <typename T>
int AVL<T>::getBalance(Node* node) const {
    if (!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

template <typename T>
typename AVL<T>::Node* AVL<T>::RR(Node* unbalanced) {
    Node* child = unbalanced->left;
    Node* grandChild = child->right;

    child->right = unbalanced;
    unbalanced->left = grandChild;

    unbalanced->height = max(getHeight(unbalanced->left), getHeight(unbalanced->right)) + 1;
    child->height = max(getHeight(child->left), getHeight(child->right)) + 1;

    return child;
}

template <typename T>
typename AVL<T>::Node* AVL<T>::LL(Node* unbalanced) {
    Node* child = unbalanced->right;
    Node* grandChild = child->left;

    child->left = unbalanced;
    unbalanced->right = grandChild;

    unbalanced->height = max(getHeight(unbalanced->left), getHeight(unbalanced->right)) + 1;
    child->height = max(getHeight(child->left), getHeight(child->right)) + 1;

    return child;
}

template <typename T>
typename AVL<T>::Node* AVL<T>::LR(Node* unbalanced) {
    unbalanced->left = LL(unbalanced->left);
    return RR(unbalanced);
}

template <typename T>
typename AVL<T>::Node* AVL<T>::RL(Node* unbalanced) {
    unbalanced->right = RR(unbalanced->right);
    return LL(unbalanced);
}

template <typename T>
typename AVL<T>::Node* AVL<T>::rebalance(Node* node) {
    int balance = getBalance(node);

    if (balance > 1) {
        if (getBalance(node->left) >= 0)
            return RR(node);
        else
            return LR(node);
    }

    if (balance < -1) {
        if (getBalance(node->right) <= 0)
            return LL(node);
        else
            return RL(node);
    }

    return node;
}

template <typename T>
typename AVL<T>::Node* AVL<T>::insert(Node* node, const T& key) {
    if (!node)
        return new Node(key);

    if (key < node->value)
        node->left = insert(node->left, key);
    else if (key > node->value)
        node->right = insert(node->right, key);
    else {
        node->count++;
        return node;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    return rebalance(node);
}

template <typename T>
void AVL<T>::Insert(const T& key) {
    root = insert(root, key);
}

template <typename T>
typename AVL<T>::Node* AVL<T>::findMin(Node* node) {
    while (node->left)
        node = node->left;
    return node;
}

template <typename T>
typename AVL<T>::Node* AVL<T>::remove(Node* node, const T& key) {
    if (!node)
        return node;

    if (key < node->value)
        node->left = remove(node->left, key);
    else if (key > node->value)
        node->right = remove(node->right, key);
    else {
        if (node->count > 1) {
            node->count--;
            return node;
        }

        if (!node->left || !node->right) {
            Node* temp = node->left ? node->left : node->right;
            if (!temp) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            Node* temp = findMin(node->right);
            node->value = temp->value;
            node->count = temp->count;
            temp->count = 1;
            node->right = remove(node->right, temp->value);
        }
    }

    if (!node)
        return node;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    return rebalance(node);
}

template <typename T>
void AVL<T>::Remove(const T& key) {
    root = remove(root, key);
}

template <typename T>
void AVL<T>::inOrderTraversal(Node* node) const {
    if (node) {
        inOrderTraversal(node->left);
        for(int i = 0; i < node->count; ++i)
            cout << node->value << ' ';
        inOrderTraversal(node->right);
    }
}

template <typename T>
void AVL<T>::preOrderTraversal(Node* node) const {
    if (node) {
        for(int i = 0; i < node->count; ++i)
            cout << node->value << ' ';
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

template <typename T>
void AVL<T>::postOrderTraversal(Node* node) const {
    if (node) {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        for(int i = 0; i < node->count; ++i)
            cout << node->value << ' ';
    }
}

template <typename T>
void AVL<T>::InOrderTraversal() const {
    inOrderTraversal(root);
    cout << '\n';
}

template <typename T>
void AVL<T>::PreOrderTraversal() const {
    preOrderTraversal(root);
    cout << '\n';
}

template <typename T>
void AVL<T>::PostOrderTraversal() const {
    postOrderTraversal(root);
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int k;
    AVL<int> tree;
    while (cin >> k){
        tree.Insert(k);
    }

    cout << "In-order Traversal: ";
    tree.InOrderTraversal();

    cout << "Pre-order Traversal: ";
    tree.PreOrderTraversal();

    cout << "Post-order Traversal: ";
    tree.PostOrderTraversal();

    return 0;
}
