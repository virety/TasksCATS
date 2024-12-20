// Условие
// Дана строка, состоящая из одного миллиона букв "Z". Определим операцию замены, которая характеризуется тремя параметрами (α,i,j) и состоит в замене на букву α букв строки начиная с позиции i до позиции j. Требуется определить, сколько различных букв будет в строке после выполнения заданной последовательности операций замены.
// Формат входного файла
// В первой строке входного файла содержится число замен N. В следующих N строках содержатся тройки α i j, где α — заглавная латинская буква, i и j — целые числа.
// Формат выходного файла
// Выходной файл должен содержать единственное целое число — количество различных букв в результирующей строке.
// Ограничения
// 0≤N≤1000, 1≤i≤j≤10^6
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	3                           2
//     A 1 50
//     X 90 1000
//     D 30 1000000
#include <stdio.h>
int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");
    int a;
    fscanf(inputFile, "%d", &a);
    const int size = 1000000;
    char string[size];
    for (int i = 0; i < size; i++) {
        string[i] = 'Z';
    }
    for (int n = 0; n < a; n++) {
        char alpha;
        int start, end;
        fscanf(inputFile, " %c %d %d", &alpha, &start, &end);
        for (int i = start - 1; i <= end - 1; i++) {
            string[i] = alpha;
        }
    }
    int k = 0;
    int count[26] = {0};
    for (int i = 0; i < size; i++) {
        if (count[string[i] - 65] == 0) {
            k++;
            count[string[i] - 65] = 1;
        }
    }
    fprintf(outputFile, "%d", k);
    return 0;
}
