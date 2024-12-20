// Условие
// Вводится массив, состоящий из целых чисел. Найти наибольшее среди них
// Формат входного файла
// Сначала задано число N — количество элементов в массиве (1≤N≤35). Далее через пробел записаны N чисел — элементы массива. Массив состоит из целых чисел в диапазоне от −2^31 до 2^31−1.
// Формат выходного файла
// Необходимо вывести значение наибольшего элемента в массиве.
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	3                           3
//     1 2 3
#include <stdio.h>
#include <math.h>

int main(){
    FILE *fin = fopen("input.txt", "rt");
    FILE *fout = fopen("output.txt", "wt");
    int n; 
    fscanf(fin, "%d", &n);
    long long max, arr[n];
    for (int i = 0; i < n; i++){
        fscanf(fin, "%lld", &arr[i]);
    }
    max=arr[0];
    for(int i=0; i<n;i++){
         if (arr[i] > max) {
          max=arr[i];
            }
    }
    fprintf(fout, "%lld ", max);
    return 0; 
}