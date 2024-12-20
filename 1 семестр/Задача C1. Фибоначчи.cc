// Условие
// Необходимо вывести N первых чисел Фибоначчи, начиная с 0.
// Формат входного файла
// Входной файл содержит одно целое неотрицательное число N.
// Формат выходного файла
// Выходной файл должен содержать N первых чисел последовательности Фибоначчи.
// Ограничения
// 0≤N≤94
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	2                           0 1
#include <stdio.h>
int main() {
    FILE *fp = fopen("input.txt","r");
    FILE *fout = fopen("output.txt","wt");
    int n;
    fscanf(fp,"%d",&n);
    fclose(fp);
    unsigned long long arr[n];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    for (int i = 0; i<n;i++){
        fprintf(fout,"%lld ",arr[i]);
    }
}