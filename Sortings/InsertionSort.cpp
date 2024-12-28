#include <iostream>

using namespace std;

void insertSort(int N, int *arr) {
    for(int i = 0; i < N; i++) {
        int j = i - 1;
        int key = arr[i];
        while(j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int N;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++) cin >> i[arr];
    insertSort(N, arr);
    for(int i = 0; i < N; i++) cout << arr[i] << ' ';
    return 0;
}
