#include <random>
#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;
int GetRandomNumber()
{
    random_device rand_dev;
    mt19937 gen(rand_dev());
    uniform_int_distribution random(10000, 999999);
    return random(gen);
}

void PerformTask() {
    int numBytes = (std::pow(10, 7) + 7) / 8;
    vector<int> numbers(numBytes);
    ofstream file(R"(C:\Users\Theodor\CLionProjects\CIAOD_2\numbers.txt)");


    for (int i = 0; i < 1000000; i++) {
        file << GetRandomNumber() << std::endl;
    }
    file.close();

    ifstream inputFileStream("numbers.txt");
    ofstream outputFile(R"(C:\Users\Theodor\CLionProjects\CIAOD_2\output.txt)");
    string line;



    int bitId, byteIndex, setBit;
    while (getline(inputFileStream, line)) {
        bitId = stoi(line);
        byteIndex = bitId / 8;
        setBit = bitId % 8;
        numbers[byteIndex] |= (1 << setBit);
    }
    inputFileStream.close();

    auto t0 = chrono::steady_clock::now();
    for (int byteIndex = 0; byteIndex < numBytes; byteIndex++)
    {
        unsigned char byte = numbers[byteIndex];
        for (int bitId = 0; bitId < 8; bitId++)
        {
            bool isBitSet = (byte & (1 << bitId));
            if (isBitSet == 1)
                outputFile << (byteIndex * 8 + bitId) << std::endl;
        }
    }
    outputFile.close();
    auto t1 = chrono::steady_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::microseconds>(t1 - t0);
    cout << "lead time: " << elapsed.count() / 1000000.0 << " seconds" << endl;
    cout << "Memory used: " << numbers.capacity() / (pow(2, 20)) << " MB" << endl;
}

int main() {
    PerformTask();
    return 0;
}