#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
void fillArrayWithRandomNumbers(int *arr, int s) {
    srand(time(NULL));
    for (int i = 0; i < s; i++) {
        arr[i] = i;
    }
    for (int i = 0; i < s; i++) {
        swap(arr[i], arr[rand() % s]);
    }

}
vector<unsigned char> bitSort(int *data, int s) {
    unsigned long long a = 0;
    int n = sizeof(long long) * 8;
    unsigned mask = (1 << (n - 1));
    for (int i = 0; i < s; i++) {
        a = a | (mask >> ((n - 1) - data[i]));
    }
    vector<unsigned char> resultArr;
    for (int i = 0; i < n; i++) {
        if ((a & (mask >> i)) != 0) {
            resultArr.push_back(n - i - 1);
        }
    }
    reverse(resultArr.begin(), resultArr.end());

    return resultArr;

}
int main() {
    int arr[64];
    fillArrayWithRandomNumbers(arr, 64);
    cout << "Source array: \n";
    for (int n : arr) { cout << n << " "; }
    cout << endl << "Sorted array: \n";
    vector out = bitSort(arr, 64);
    for (int n : out) {
        cout << n << " ";
    }

    return 0;

}