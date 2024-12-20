// Условие
// По данному числу N требуется заполнить квадратную матрицу размером NxN целыми числами от 1 до N2; следующим образом:
// в левом верхнем углу находится число 1
// далее числа располагаются по спирали, закрученной вправо и внутрь
// Формат входного файла
// Входной файл содержит целое число N.
// Формат выходного файла
// Выходной файл должен содержать заполненную матрицу в виде N строк по N целых чисел в каждой.
// Ограничения
// 1 <= N <= 100
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	2                           1 2
//                                 4 3
// 2	3                           1 2 3
//                                 8 9 4
//                                 7 6 5
#include <stdio.h>

int main() {
    char * filename1 = "input.txt";
    char * filename2 = "output.txt";
    FILE * fout = fopen(filename2, "wt");
    FILE * fin = fopen(filename1, "rt");
    int N;
    fscanf(fin,"%d", &N);
    int matrix[100][100]; 
    int num = 1; 
    int direction = 0; 
    int row_start = 0, row_end = N - 1; 
    int col_start = 0, col_end = N - 1; 
    while (num <= N * N) {
        if (direction == 0) {
            for (int i = col_start; i <= col_end; i++) {
                matrix[row_start][i] = num;
                num++;
            }
            row_start++; 
            direction = 1; 
        }
        else if (direction == 1) {
            for (int i = row_start; i <= row_end; i++) {
                matrix[i][col_end] = num;
                num++;
            }
            col_end--; 
            direction = 2; 
        }
        else if (direction == 2) {
            for (int i = col_end; i >= col_start; i--) {
                matrix[row_end][i] = num;
                num++;
            }
            row_end--; 
            direction = 3;
        }
        else if (direction == 3) {
            for (int i = row_end; i >= row_start; i--) {
                matrix[i][col_start] = num;
                num++;
            }
            col_start++;
            direction = 0; 
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(fout,"%d ", matrix[i][j]);
        }
        fprintf(fout,"\n");
    }
    
    return 0;
}