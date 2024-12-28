#include <iostream>
#include <ctime>

using namespace std;

int PartitionHoare(int* arr, int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[left + rand() % (right - left + 1)];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return j;

}

int PartitionLamuto(int* arr, int left, int right)
{
    int pivot = arr[left + rand() % (right - left + 1)];
    swap(arr[pivot], arr[right]);
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++)
    {
        if (arr[j] <= arr[pivot])
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return (i + 1);
}

void QuickSort(int*arr, int left, int right) {
    if (left < right) {
        int pivot = PartitionHoare(arr, left, right);

        QuickSort(arr, left, pivot); //When use Lamuto need to decrese 1 of pivot (only there)
        QuickSort(arr, pivot + 1, right);
    }
}

int main()
{
    int N;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++) cin >> i[arr];
    srand(time(0));
    QuickSort(arr, 0,N-1);
    for(int i = 0; i < N; i++) cout << arr[i] << ' ';
    return 0;
}
