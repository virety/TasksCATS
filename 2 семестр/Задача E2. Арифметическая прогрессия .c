// Условие
// Петя очень любит арифметические прогрессии. Однажды он написал на бумаге числовую последовательность, но, к сожалению, эта последовательность не оказалась арифметической прогрессией.
// Чтобы исправить эту ситуацию, Петя решил вычеркнуть некоторые числа, чтобы полученная в результате вычёркивания последовательность оказалась арифметической прогрессией. При этом Петя хочет вычеркнуть как можно меньше чисел.
// Напишите программу, принимающую на вход последовательность чисел и вычисляющую, какое наименьшее количество чисел нужно из неё вычеркнуть, чтобы оставшаяся последовательность оказалась арифметической прогрессией.
// Формат входного файла
// Входной файл содержит целое число N — количество чисел, за которым следуют N целых чисел ai.
// Формат выходного файла
// Выходной файл должен содержать целое число M — количество чисел, которые останутся после вычёркивания (при этом количество вычеркнутых чисел должно быть минимальным).
// Далее должны следовать 
// M целых чисел — номера чисел, которые останутся после вычёркивания, перечисленные в порядке возрастания.
// Если решений несколько, выведите любое из них.
// Ограничения
// 1≤N≤100
// 1≤ai≤10^6
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	7                           4
//     1 3 4 2 7 8 10              1 3 5 7
#include <stdio.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    int a[100];
    int pos[100], bpos[100];
    int n, i, j, k, l, t, m, bm, p;

    fscanf(input, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(input, "%d", &a[i]);
    }

    bm = 1;
    bpos[0] = 1;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            k = j;
            m = 2;
            pos[0] = i + 1;
            pos[1] = j + 1;
            while (1) {
                p = a[i] + (a[j] - a[i]) * m;
                t = 0;
                for (l = k + 1; l < n; l++) {
                    if (a[l] == p) {
                        t = l;
                        break;
                    }
                }
                if (t == 0) break;
                else {
                    m++;
                    pos[m - 1] = t + 1;
                    k = t;
                }
            }
            if (m > bm) {
                bm = m;
                for (l = 0; l < m; l++) {
                    bpos[l] = pos[l];
                }
            }
        }
    }

    fprintf(output, "%d\n", bm);
    for (i = 0; i < bm; i++) {
        fprintf(output, "%d ", bpos[i]);
    }

    fclose(input);
    fclose(output);

    return 0;
}