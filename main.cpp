#include <iostream>
#include <bitset>

using namespace std;

int set_1(unsigned int a, unsigned int mask) {
    return a = a | mask;
}

int set_2(unsigned int a, unsigned int mask) {
    return a = a & mask;
}
int set_3(unsigned int a)
{
    return a = a << 3;
}
int set_4(unsigned int a)
{
    return a = a >> 3;
}
int set_5(unsigned int a, unsigned int mask, unsigned int n)
{
    mask = mask>>n;
    return a = a ^ mask;
}
int main() {
    unsigned short int x, n;
    setlocale(LC_ALL, "Russian");

    unsigned int a = 0x12345;
    unsigned int mask1 = 0b0010001111100101;
    unsigned int mask2 = 0b1100001111111111;
    unsigned int mask3 = 0b1000000000000000;
    int k;
    cin >> k;
    switch (k) {
        case 1:
            cout << "Исходное число: " << a << endl;
            cout << "Исходное число в 2 сс: " << bitset<16>(a) << endl;
            cout << "Результат в 2 сс: " << bitset<16>(a | mask1) << endl;
            cout << "Результат: " << set_1(a, mask1);
            break;
        case 2:
            cout << "Введите ваше число: ";
            cin >> x;
            cout << endl;
            cout << "Ваше число в 2 сс: " << bitset<16>(x) << endl;
            cout << "Результат в 2 сс: " << bitset<16>(x & mask2) << endl;
            cout << "Результат: " << set_2(x, mask2) << endl;
            break;
        case 3:
            cout<<"Enter your number: ";
            cin>>x;
            cout<<endl;
            cout<<"Your number in 2 notation: "<<bitset<16>(x)<<endl;
            cout<<"Answer in 2 notation: "<<bitset<16>(set_3(x))<<endl;
            cout<<"Answer: "<<set_3(x)<<endl;
        case 4:
            cout<<"Enter your number: ";
            cin>>x;
            cout<<endl;
            cout<<"Your number in 2 notation: "<<bitset<16>(x)<<endl;
            cout<<"Answer in 2 notation: "<<bitset<16>(set_4(x))<<endl;
            cout<<"Answer: "<<set_4(x)<<endl;
        case 5:
            cout<<"Enter your number: ";
            cin>>x;
            cout<<endl;
            cout<<"Enter the number of the bit you want to set to 1: ";
            cin>>n;
            cout<<endl;
            cout<<"Your number in 2 notation: "<<bitset<16>(x)<<endl;
            cout<<"Answer in 2 notation: "<<bitset<16>(set_5(x, mask3, n))<<endl;
            cout<<"Answer: "<<set_5(x, mask3, n)<<endl;
    }
}
