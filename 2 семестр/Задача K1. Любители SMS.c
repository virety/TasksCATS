// Условие
// Во время подготовки задач городской олимпиады по информатике отдельные члены жюри пишут остальным много SMS сообщений. Порой размер этих сообщений может исчисляться килобайтами. Естественно, этот процесс был бы очень длительным, если бы не умение указанных членов жюри набирать SMS сообщения за минимально возможное время.
// Известно, что члены жюри набирают сообщения с помощью больших пальцев левой и правой рук. Перед набором каждого символа пальцы лежат в центрах двух различных клавиш телефона. Затем один из пальцев перемещается в центр нужной клавиши и нажимает её. Второй палец при этом остаётся на месте.
// Время перемещения пальца с одной клавиши на другую составляет d секунд, где d — расстояние между центрами клавиш. Время нажатия на клавишу будем считать пренебрежимо малым.
// Расположение клавиш и координаты их центров показаны на приведённой схеме:
//   1 2 3   (1; 1) (1; 2) (1; 3)
//   4 5 6   (2; 1) (2; 2) (2; 3)
//   7 8 9   (3; 1) (3; 2) (3; 3)
//     0            (4; 2)
// Во время набора сообщений пальцы не должны &laquo;скрещиваться&raquo;, то есть палец левой руки не может оказаться правее пальца правой руки.
// Одному члену жюри требуется набрать сообщение, состоящее из N символов. Помогите ему оценить минимальное время, которое для этого потребуется. Клавиша, которую нужно нажать, чтобы ввести i-й символ сообщения, задаётся изображённой на ней цифрой ai. В начальный момент времени палец левой руки находится на клавише 4, а палец правой руки — на клавише 6.
// Рекомендуется рассмотреть частичные решения
// Минимизация расстояния на каждом шаге ведёт к минимизации ответа (жадный алгоритм)1≤N≤20
// Формат входного файла
// Входной файл содержит целое число N, за которым следуют N цифр ai.
// Формат выходного файла
// Выходной файл должен содержать единственное вещественное число t — минимальное время набора сообщения. Абсолютная ошибка ответа не должна превышать 10−3.
// Ограничения
// 1≤N≤10^5, 0≤ai≤9
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	4                           5
//     1 3 2 7
// 2	6                           6.650281540
//     5 2 9 0 0 3
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

double calculateDistance(const int *x, const int *y, int a, int b) {
    return sqrt(pow(x[a] - x[b], 2) + pow(y[a] - y[b], 2));
}

void tryMoveFinger(int *x, int *y, double ***distances, int k, int currentLeft, int currentRight, int left, int right) {
    if (currentLeft == right || currentRight == left) {
        return;
    }
    if (x[left] > x[right]) {
        return;
    }
    double moveTime = (currentLeft == left) ? calculateDistance(x, y, currentRight, right) : calculateDistance(x, y, currentLeft, left);
    if (distances[(k + 1) % 2][left][right] == 0 || distances[(k + 1) % 2][left][right] > distances[k % 2][currentLeft][currentRight] + moveTime) {
        distances[(k + 1) % 2][left][right] = distances[k % 2][currentLeft][currentRight] + moveTime;
    }
}

void solve(FILE *input, FILE *output, int *x, int *y) {
    int n;
    fscanf(input, "%d", &n);
    int *digits = (int *)malloc(n * sizeof(int));
    double ***distances = (double ***)malloc(2 * sizeof(double **));

    for (int i = 0; i < 2; i++) {
        distances[i] = (double **)malloc(10 * sizeof(double *));
        for (int j = 0; j < 10; j++) {
            distances[i][j] = (double *)calloc(10, sizeof(double));
        }
    }

    for (int i = 0; i < n; i++) {
        fscanf(input, "%d", &digits[i]);
    }

    distances[0][4][6] = 1;

    for (int k = 0; k < n; k++) {
        int nextK = (k + 1) % 2;
        for (int l = 0; l < 10; l++) {
            for (int r = 0; r < 10; r++) {
                distances[nextK][l][r] = 0;
            }
        }
        for (int l = 0; l < 10; l++) {
            for (int r = 0; r < 10; r++) {
                if (distances[k % 2][l][r] != 0) {
                    tryMoveFinger(x, y, distances, k, l, r, digits[k], r);
                    tryMoveFinger(x, y, distances, k, l, r, l, digits[k]);
                }
            }
        }
    }

    double minTime = DBL_MAX;

    for (int l = 0; l < 10; l++) {
        for (int r = 0; r < 10; r++) {
            if (distances[n % 2][l][r] != 0) {
                if (distances[n % 2][l][r] < minTime) {
                    minTime = distances[n % 2][l][r];
                }
            }
        }
    }

    minTime -= 1;
    fprintf(output, "%.9f\n", minTime);
    
    free(digits);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++) {
            free(distances[i][j]);
        }
        free(distances[i]);
    }
    free(distances);
}

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    int yCoordinates[10] = {4, 1, 1, 1, 2, 2, 2, 3, 3, 3};
    int xCoordinates[10] = {2, 1, 2, 3, 1, 2, 3, 1, 2, 3};

    solve(inputFile, outputFile, xCoordinates, yCoordinates);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}