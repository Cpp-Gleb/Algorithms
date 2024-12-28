#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Heap {
public:
    Heap() = default;

    void Insert(int value);
    virtual int ExtractValue();
    virtual int GetValue();
    bool IsHeapEmpty();
    size_t GetSize();

protected:
    vector<int> heap_;
    virtual void SiftUp(int index);
    virtual void SiftDown(int index);
};

void Heap::SiftUp(int index) {}

void Heap::SiftDown(int index) {}

void Heap::Insert(int value) {
    heap_.push_back(value);
    SiftUp(heap_.size() - 1);
}

int Heap::ExtractValue() {
    if (heap_.empty()) return -1;
    int value = heap_[0];
    heap_[0] = heap_.back();
    heap_.pop_back();
    SiftDown(0);
    return value;
}

int Heap::GetValue() {
    return heap_[0];
}

size_t Heap::GetSize() {
    return heap_.size();
}

bool Heap::IsHeapEmpty() {
    return heap_.empty();
}

class MinHeap : public Heap {
protected:
    void SiftUp(int index) override;
    void SiftDown(int index) override;
};

void MinHeap::SiftUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap_[index] < heap_[parent]) {
            swap(heap_[index], heap_[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void MinHeap::SiftDown(int index) {
    int size = heap_.size();
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size && heap_[left] < heap_[largest]) {
            largest = left;
        }
        if (right < size && heap_[right] < heap_[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(heap_[index], heap_[largest]);
            index = largest;
        } else {
            break;
        }
    }
}



class MaxHeap : public Heap {
protected:
    void SiftUp(int index) override;
    void SiftDown(int index) override;
};
void MaxHeap::SiftUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap_[index] > heap_[parent]) {
            swap(heap_[index], heap_[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void MaxHeap::SiftDown(int index) {
    int size = heap_.size();
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size && heap_[left] > heap_[largest]) {
            largest = left;
        }
        if (right < size && heap_[right] > heap_[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(heap_[index], heap_[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    MinHeap MinHeap;
    MaxHeap MaxHeap;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (MaxHeap.IsHeapEmpty() || x <= MaxHeap.GetValue()) {
            MaxHeap.Insert(x);
        } else {
            MinHeap.Insert(x);
        }

        if (MaxHeap.GetSize() > MinHeap.GetSize() + 1) {
            MinHeap.Insert(MaxHeap.ExtractValue());
        } else if (MinHeap.GetSize() > MaxHeap.GetSize()) {
            MaxHeap.Insert(MinHeap.ExtractValue());
        }

        if (MaxHeap.GetSize() > MinHeap.GetSize()) {
            cout << MaxHeap.GetValue() << '\n';
        } else {
            cout << (MaxHeap.GetValue() + MinHeap.GetValue()) / 2 << '\n';
        }
    }

    return 0;
}
