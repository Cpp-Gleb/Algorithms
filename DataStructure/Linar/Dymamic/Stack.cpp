#include <iostream>

using namespace std;

template <typename T>
class Stack {
public:
    Stack();

    void Push(const T& newValue);
    T Pop();
    T& Top();

    bool IsEmpty();
    size_t GetSize();

    void Sort();

    ~Stack();

private:
    struct Node {
        Node* next = nullptr;
        T value;

        Node(Node* next, const T& value) : next(next), value(value) {}
    };
    Node* _last;
    size_t _size;
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
void Stack<T>::Push(const T& newValue) {
    Node* newNode = new Node(_last, newValue);
    _last = newNode;
    _size++;
}

template<typename T>
T Stack<T>::Pop() {
    if (IsEmpty()) { return T();}
    T value = _last->value;
    _last = _last->next;
    _size--;
    return value;
}

template<typename T>
T& Stack<T>::Top() {
    if(IsEmpty()){  throw runtime_error("Stack is empty");}
    return _last->value;
}

template<typename T>
size_t Stack<T>::GetSize() {
    return _size;
}

template<typename T>
void Stack<T>::Sort() {
    Stack<T> tempStack;
    while (!IsEmpty()) {
        T temp = this->Pop();

        while (!tempStack.IsEmpty() && tempStack.Top() > temp) {
            this->Push(tempStack.Pop());
        }

        tempStack.Push(temp);
    }

    while (!tempStack.IsEmpty()) {
        this->Push(tempStack.Pop());
    }
}

template<typename T>
Stack<T>::~Stack() {
    while (!IsEmpty()) {
        Pop();
    }
}

int main() {
    int countOperation = 0;
    cin >> countOperation;
    Stack<int> arr;
    Stack<int> res1;
    Stack<int> res2;

    for(int i = 0; i < countOperation; i++) {
        char operation;
        int value;
        cin >> operation;
        if(operation == '+') {
            cin >> value;
            arr.Push(value);
            continue;
        }
        res1.Push(arr.Pop());
    }
    int KLenStack =  res1.GetSize();
    for(int i = 0; i <KLenStack; i++) {
        res2.Push(res1.Pop());
    }
    for(int i = 0; i < KLenStack; i++) {
        cout << res2.Pop() << "\n";
    }

    return 0;
}
