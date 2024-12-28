#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    
    for(int i = 0; i < N; i++) a[i] = i + 1;
    
    for(int i = 2; i < N; i++) swap(a[i], a[i/2]);
    
    for(int i = 0; i < N; i++) cout << a[i] << ' ';
    
    return 0;
}
