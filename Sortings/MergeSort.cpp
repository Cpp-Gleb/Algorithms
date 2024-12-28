#include <iostream>

using namespace std;

//Variation for two-dimensional array with save stable

void merge(int arr[][2], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int leftArr[leftSize][2], rightArr[rightSize][2];

    for (int i = 0; i < leftSize; i++)
        leftArr[i][0] = arr[left + i][0], leftArr[i][1] = arr[left + i][1];
    for (int j = 0; j < rightSize; j++)
        rightArr[j][0] = arr[mid + 1 + j][0], rightArr[j][1] = arr[mid + 1 + j][1];

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i][0] <= rightArr[j][0]) {
            arr[k][0] = leftArr[i][0];
            arr[k][1] = leftArr[i][1];
            i++;
        } else {
            arr[k][0] = rightArr[j][0];
            arr[k][1] = rightArr[j][1];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k][0] = leftArr[i][0];
        arr[k][1] = leftArr[i][1];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k][0] = rightArr[j][0];
        arr[k][1] = rightArr[j][1];
        j++;
        k++;
    }
}

void mergeSort(int arr[][2], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int N;
    cin >> N;
    int arr[N][2];

    for (int i = 0; i < N; i++) cin >> arr[i][0] >> arr[i][1];

    mergeSort(arr, 0, N - 1);

    for (int i = 0; i < N; i++) cout << arr[i][0] << ' ' << arr[i][1] << '\n';

    return 0;
}
