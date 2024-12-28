#include <iostream>
#include <vector>

template <typename T>
class LinkedList {
public:
    LinkedList();

    void PushForward(T newValue);
    T PopForward();
    void PushBack(T newValue);
    T PopBack();

    size_t GetSize();
    bool IsEmpty();

private:
    struct Node {
        T value;
        Node* next = nullptr;
        Node* prev = nullptr;
    };
    size_t size;
    Node* head;
    Node* tail;
};

template<typename T>
LinkedList<T>::LinkedList() : size(0), head(nullptr), tail(nullptr) {}

template<typename T>
size_t LinkedList<T>::GetSize() {
     return size;
}

template<typename T>
bool LinkedList<T>::IsEmpty() {
    return size == 0;
}

template<typename T>
void LinkedList<T>::PushForward(T newValue) {
    ++size;
    Node newNode;
    newNode.value = newValue;
    if(head == nullptr) {
        head = &newNode;
        tail = &newNode;
        return;
    }
    newNode.next = head;
    head -> prev = newNode;
    head = newNode;
}

template<typename T>
T LinkedList<T>::PopForward() {
    if(size == 0){ throw std::runtime_error("List is empty");}
    --size;
    if(size == 0) {
        Node* tmp = head;
        T returnValue = tmp->value;
        tail = nullptr;
        head = nullptr;
        delete tmp;
        return returnValue;
    }

    T returnValue = head->value;
    Node* tmp = head;
    head = head.next;
    head -> prev -> next = nullptr;
    head -> prev = nullptr;
    delete tmp;
    return returnValue;
}

template<typename T>
void LinkedList<T>::PushBack(T newValue) {
    ++size;
    Node* newNode = new Node;
    newNode->value = newValue;
    if(tail == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail -> next = newNode;
    newNode -> prev = tail;
    tail = newNode;
}

template<typename T>
T LinkedList<T>::PopBack() {
    if(size == 0){ throw std::runtime_error("List is empty");}
    --size;
    if(size == 0) {
        Node* tmp = tail;
        T returnValue = tmp->value;
        head = nullptr;
        tail = nullptr;
        delete tmp;
        return returnValue;
    }
    T ReturnValue = tail->value;
    Node* tmp = tail;
    tail = tail->prev;
    tail -> next -> prev = nullptr;
    tail -> next = nullptr;
    delete tmp;
    return ReturnValue;
}


int main() {
    LinkedList<int> ll;
    std::vector <int> data = {1, 2, 3, 4, 5};

    for(int i = 0; i < data.size(); i++) {
        ll.PushBack(data[i]);
        std::cout << ll.GetSize() << '\n';
    }
    
    while(!ll.IsEmpty()) {
        std::cout << ll.PopBack() << ' ' << ll.GetSize() << '\n';
    }

}

