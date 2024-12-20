// Условие
// Требуется написать программу, которая вычисляет среднее арифметическое заданной выборки.
// Формат входного файла
// Входные данные содержат число 
// n, за которым следует n положительных вещественных чисел.
// Формат выходного файла
// Выходные данные должны содержать единственное число — среднее арифметическое выборки с точностью не менее 3 знаков после запятой.
// Ограничения
// 1<n<10^5
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	3                           3
//     1 3 5
#include <stdio.h>
int main() {
    char * filename1 = "input.txt";
    char * filename2 = "output.txt";
    FILE * fout = fopen(filename2, "wt");
    FILE * fin = fopen(filename1, "rt");
    double n;
    double a, b, c, d, res1, res2, kk;
    fscanf(fin, "%lf", &n);
    
    double sum = 0;
    double num;
    
    for (int i = 0; i < n; i++) 
    {
        fscanf(fin, "%lf", &num);
        sum += num;
    }
    double average = sum / n;
    fprintf(fout, "%.3lf\n", average);
    return 0;
}
