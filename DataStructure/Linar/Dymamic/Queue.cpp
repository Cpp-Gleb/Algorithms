#include <iostream>

using namespace std;

template <typename T>
class Stack {
public:
    Stack();
    void Push(T newValue);
    T Pop();
    bool IsEmpty();
    T Top();
    int GetSize();

private:
    struct Node {
        Node* next = nullptr;
        T value;
    };
    Node* _last;
    int _size;
};

template<typename T>
Stack<T>::Stack() {
    _last = nullptr;
    _size = 0;
}

template<typename T>
bool Stack<T>::IsEmpty() {
    return _size == 0;
}

template<typename T>
void Stack<T>::Push(T newValue) {
    Node* newNode = new Node(nullptr, newValue);
    newNode->next = _last;
    if( IsEmpty()) {
        _last = newNode;
    } else {
        newNode->next = _last;
        _last = newNode;
    }
    _size++;
}

template<typename T>
T Stack<T>::Pop() {
    if (IsEmpty()) { return 0;}
    T value = _last->value;
    _last = _last->next;
    _size--;
    return value;
}

template<typename T>
T Stack<T>::Top() {

}

template<typename T>
int Stack<T>::GetSize() {
    return _size;
}

template <typename T>
class Queue {
public:
    Queue();
    int GetSize();
    bool IsEmpty();
    void EnQueue(T value);
    T DeQueue();
private:
    struct Node {
        Node* next = nullptr;
        T value;
    };
    Node* _head;
    Node* _tail;
    int _size;
};

template<typename T>
Queue<T>::Queue() {
    _head = nullptr;
    _size = 0;
}

template<typename T>
int Queue<T>::GetSize() {
    return _size;
}

template<typename T>
bool Queue<T>::IsEmpty() {
    return _size == 0;
}

template<typename T>
void Queue<T>::EnQueue(T newValue) {
    Node* newNode = new Node(nullptr, newValue);
    if(IsEmpty()) {
        _head = newNode;
        _tail = newNode;
    }
    _tail->next = newNode;
    _tail = newNode;
    _size++;
}

template<typename T>
T Queue<T>::DeQueue() {
    if( IsEmpty()){ return 0;}
    T value = _head->value;
    _head = _head->next;
    if(_head == nullptr) { _tail = nullptr; }
    _size--;
    return value;
}


int main() {
    int countOperation = 0;
    cin >> countOperation;
    Queue<int> arr;
    Queue<int> res1;

    for(int i = 0; i < countOperation; i++) {
        char operation;
        int value;
        cin >> operation;
        if(operation == '+') {
            cin >> value;
            arr.EnQueue(value);
            continue;
        }
        res1.EnQueue(arr.DeQueue());
    }
    int KLenStack =  res1.GetSize();
    for(int i = 0; i <KLenStack; i++) {
        cout << res1.DeQueue() << "\n";
    }
    return 0;
}
