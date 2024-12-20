// Условие
// Набором данных называется пара чисел первое из которых называется ключом, второе — данными. Ваша задача состоит в том, чтобы упорядочить данные в порядке возрастания ключей. При совпадении ключей первым в отсортированном массиве должен идти тот же элемент что и в не сортированном.
// Формат входного файла
// Во входном файле содержится число N, за которым следуют N пар чисел — наборы данных.
// Формат выходного файла
// В выходном файле должно содержаться ровно N чисел — данные, упорядоченные в порядке возрастания ключей.
// Ограничения
// 0≤N≤100000, все числа находятся в диапазоне от 1 до 100000
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	4                           1 3 2 4
//     2 1
//     3 2 
//     2 3
//     3 4

#include <stdio.h>
#include <stdlib.h>

int* counting_sort(int arr[][2], int n) {
    int max_key = arr[0][0];
    for (int i = 1; i < n; i++) {
        if (arr[i][0] > max_key) {
            max_key = arr[i][0];
        }
    }
    int* count = (int*)calloc(max_key + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        count[arr[i][0]]++;
    }
    for (int i = 1; i < max_key + 1; i++) {
        count[i] += count[i - 1];
    }
    int* sorted_arr = (int*)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        count[arr[i][0]]--;
        sorted_arr[count[arr[i][0]]] = arr[i][1];
    }
    free(count);
    return sorted_arr;
}
int main() {
    FILE* input_file = fopen("input.txt", "r");
    int n;
    fscanf(input_file, "%d", &n);
    int data[n][2];
    for (int i = 0; i < n; i++) {
        fscanf(input_file, "%d %d", &data[i][0], &data[i][1]);
    }
    fclose(input_file);
    int* sorted_data = counting_sort(data, n);
    FILE* output_file = fopen("output.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(output_file, "%d ", sorted_data[i]);
    }
    fclose(output_file);
    free(sorted_data);
    return 0;
}