#include <iostream>

using namespace std;

void countingSort(int arr[], int N) {
    int maxEl = 0;
    for (int i = 0; i < N; i++) maxEl = max(maxEl, arr[i]); //optimize capacity of memory
    int countArr[maxEl];
    for (int i = 0; i < maxEl + 1; i++) countArr[i] = 0;
    for (int i = 0; i < N; i++) countArr[arr[i]]++;
    for (int i = 1; i < maxEl + 1; i++) countArr[i] += countArr[i - 1]; //prefixsum for comfortable positioning elems

    int sortArr[N];
    for (int i = N - 1; i >= 0; i--) {
        sortArr[countArr[arr[i]] - 1] = arr[i];
        countArr[arr[i]]--;
    }

    for (int i = 0; i < N; i++) {
        arr[i] = sortArr[i];
    }
}

int main()
{
    int N;
    cin >> N;
    int arr[N];

    for (int i = 0; i < N; i++) cin >> arr[i];

    countingSort(arr, N);

    for (int i = 0; i < N; i++) cout << arr[i] << ' ';
    
    return 0;
}
