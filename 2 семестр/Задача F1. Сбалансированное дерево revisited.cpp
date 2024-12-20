// Условие
// Дана последовательность целых чисел. Каждое прочитанное число обрабатывается следующим образом:
// если число больше нуля, оно добавляется к текущему множеству чисел;
// если число меньше нуля, противоположное ему число удаляется из текущего множества чисел;
// если число равно нулю, множество чисел выводится в порядке возрастания и программа завершает работу.
// Формат входного файла
// Входной файл содержит последовательность чисел.
// Формат выходного файла
// Выходной файл должен содержать последовательность чисел, отсортированных по возрастанию.
// Ограничения
// Количество чисел находится в диапазоне от 
// 0 до 10^6, сами числа — в диапазоне от −2^31 до 2^31−1.
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	3 2 1 3 0                   1 2 3
// 2	5 -1 6 -5 5 0               5 6
#include <iostream>
#include <fstream>
#include <set>

class balancedtree {
private:
    std::set<int> numbers;

public:
    void processnumber(int num) {
        if (num > 0) {
            numbers.insert(num);
        } else if (num < 0) {
            numbers.erase(-num);
        } else {
            std::ofstream outputFile("output.txt", std::ios::app);
            if(outputFile.is_open()){
                for (int n : numbers) {
                    std::cout << n << " ";
                    outputFile << n << " ";
                }
                std::cout << std::endl;
                outputFile << std::endl;
                outputFile.close();
            }
            exit(0);
        }
    }
};

int main() {
    balancedtree balancedtree;
    int num;

    std::ifstream inputFile("input.txt");

    while (inputFile >> num) {
        balancedtree.processnumber(num);
    }

    inputFile.close();

    return 0;
}