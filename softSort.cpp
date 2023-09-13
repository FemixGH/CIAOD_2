#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> bitSort(int *data, int s) {
    unsigned int a = 0; //00000000
    int n = sizeof(int) * 2;
    unsigned mask = (1 << (n - 1)); //Маска, в которой двигается единица для дальнейшей поразрядной дизъюнкции
    for (int i = 0; i < s; i++) {
        a = a | (mask >> ((n - 1) -
                          data[i])); //Заполняем 00000000 единицами, единица стоит на том месте, номер которого присутствует в исходном массиве
    }
    vector<int> resultArr;
    for (int i = 0; i < n; i++) {
        if ((a & (mask >> i)) != 0) {
            resultArr.push_back(n - i - 1);
        }
    }
    reverse(resultArr.begin(), resultArr.end());
    return resultArr;
}

int main() {
    int arr[7];
    for (int i = 0; i <= 6; i++) {
        cin >> arr[i]; // Вводим с клавиатуры значение ячейки массива
    }

    vector out = bitSort(arr, 7);
    for (int n: out) {
        cout << n << " ";
    }
    return 0;

}