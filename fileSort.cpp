#include <ctime>
#include <fstream>
#include <vector>
#include <iostream>
#include <random>
#include <set>
#include <algorithm>
#include <bitset>

void createFile();
void sortFile(const std::string& filename);
using namespace std;
const int MAX_NUMBER = 221458999;
string outputFile = "sorted_numbers.txt";
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
    string inputFile = "numbers.txt";

    // Открытие файла для чтения
    ifstream file(inputFile);
    if (!file) {
        cout << "Failed to open file: " << inputFile << endl;
        return 1;
    }

    // Чтение чисел из файла в вектор
    vector<int> data;
    int number;
    while (file >> number) {
        data.push_back(number);
    }

    // Закрытие файла после чтения
    file.close();

    // Вызов битовой сортировки
    vector<int> sortedData = bitSort(data.data(), data.size());

    // Открытие файла для записи отсортированных чисел
    ofstream out(outputFile);
    if (!out) {
        cout << "Failed to open file for writing: " << outputFile << endl;
        return 1;
    }

    // Запись отсортированных чисел в файл
    for (int num : sortedData) {
        out << num << endl;
    }

    // Закрытие файла после записи
    out.close();

    cout << "Bitwise sort completed successfully!" << endl;

    return 0;
}



void createFile()
{
    const int n = 1000000;
    ofstream file(R"(C:\Users\Theodor\CLionProjects\CIAOD_2\numbers.txt)");
    set<int> numbers;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, n);

    while (numbers.size() < n) {
        int num = dis(gen);
        if (numbers.count(num) == 0) {
            numbers.insert(num);
            file << num << "\n";
        }
    }

    file.close();
    cout << "File created successfully!" << std::endl;
}

void sortFile(const std::string& filename) {
    ifstream input(filename, std::ios::binary);

    // Получение размера файла
    input.seekg(0, std::ios::end);
    streampos fileSize = input.tellg();
    input.seekg(0, std::ios::beg);

    // Вычисление количества чисел в файле
    int numCount = fileSize / sizeof(int);

    // Создание битового массива
    bitset<MAX_NUMBER + 1> bitArray;

    // Чтение чисел из файла и установка соответствующих битов в битовом массиве
    int number;
    for (int i = 0; i < numCount; ++i) {
        input.read(reinterpret_cast<char*>(&number), sizeof(number));
        bitArray.set(number);
    }
    input.close();

    // Запись отсортированных чисел обратно в файл
    ofstream output(filename, std::ios::binary);
    for (int i = 0; i <= MAX_NUMBER; ++i) {
        if (bitArray.test(i)) {
            output.write(reinterpret_cast<const char*>(&i), sizeof(i));
        }
    }
    output.close();
}

