#include <iostream>
#include <bitset>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <random>

using namespace std;

int getRandomNumber() {
    random_device rand_dev;
    mt19937 gen(rand_dev());
    uniform_int_distribution<int> random(100000, 999999);
    return random(gen);
}

void Perform() {
    int bytes = (pow(10, 7) + 7) / 8;
    vector<unsigned char> numbers(bytes);
    ofstream outputFile(R"(C:\Users\fedor\CLionProjects\CIAOD_2\output.txt)");

    for (int i = 0; i < 1000000; i++) {
        outputFile << getRandomNumber() << endl;
    }
    outputFile.close();

    ifstream inputFile(R"(C:\Users\fedor\CLionProjects\CIAOD_2\numbers.txt)");
    ofstream sortedOutputFile(R"(C:\Users\fedor\CLionProjects\CIAOD_2\sorted_output.txt)");
    string line;

    cout << "All files opened." << endl;

    int bitIndex, byteIndex, setBit;
    while (getline(inputFile, line)) {
        bitIndex = stoi(line);
        byteIndex = bitIndex / 8;
        setBit = bitIndex % 8;
        numbers[byteIndex] |= (1 << setBit);
    }

    inputFile.close();

    cout << "Bits set." << endl;

    auto t0 = chrono::steady_clock::now();
    for (int byteIndex = 0; byteIndex < bytes; byteIndex++) {
        unsigned char byte = numbers[byteIndex];
        for (int bitIndex = 0; bitIndex < 8; bitIndex++) {
            bool isBitSet = (byte & (1 << bitIndex));
            if (isBitSet == 1)
                sortedOutputFile << (byteIndex * 8 + bitIndex) << endl;
        }
    }

    cout << "Sorted numbers written to file." << endl;

    sortedOutputFile.close();
    auto t1 = chrono::steady_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::microseconds>(t1 - t0);
    cout << "Execution time: " << elapsedTime.count() / 1000000.0 << " seconds." << endl;
    cout << "Memory usage: " << numbers.capacity() / (pow(2, 20)) << " MB." << endl;
}

int main() {
    Perform();
    return 0;
}
