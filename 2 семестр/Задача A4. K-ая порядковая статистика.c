// Условие
// K-ой порядковой статистикой N-элементной последовательности AN называется число AK, которое будет стоять на K-ом месте после упорядочивания элементов этой последовательности по возрастанию.
// Последовательность AN задаётся следующим образом. A1=P, Ai=(Ai−1⋅Q) mod V.
// Формат входного файла
// Во входном файле содержатся целые числа QVPNK
// Формат выходного файла
// В выходном файле должно содержаться единственное число — K-ая порядковая статистика исходной последовательности.
// Ограничения
// V,Q≠0
// 0≤Q⋅V,Q⋅P≤231−1
// 1≤K≤N≤4⋅107
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	343 32767 3 10 7            16478

#include <stdio.h>

int find_kth_statistic(int Q, int V, int P, int N, int K) {
    int sequence[N];
    sequence[0] = P;
    for (int i = 1; i < N; i++) {
        int Ai = (sequence[i - 1] * Q) % V;
        sequence[i] = Ai;
    }
    int left = 0;
    int right = N - 1;
    while (left < right) {
        int pivot = sequence[left];
        int i = left + 1;
        int j = right;
        while (i <= j) {
            if (sequence[i] > pivot && sequence[j] <= pivot) {
                int temp = sequence[i];
                sequence[i] = sequence[j];
                sequence[j] = temp;
                i++;
                j--;
            }
            if (sequence[i] <= pivot) {
                i++;
            }
            if (sequence[j] > pivot) {
                j--;
            }
        }
        int temp = sequence[left];
        sequence[left] = sequence[j];
        sequence[j] = temp;
        if (j == K - 1) {
            return sequence[j];
        } else if (j < K - 1) {
            left = j + 1;
        } else {
            right = j - 1;
        }
    }
    return sequence[left];
}
int main() {
    int Q, V, P, N, K;
    FILE * inputFile = fopen("input.txt", "r");
    fscanf(inputFile, "%d %d %d %d %d", &Q, &V, &P, &N, &K);
    fclose(inputFile);
    int result = find_kth_statistic(Q, V, P, N, K);
    FILE * outputFile = fopen("output.txt", "w");
    fprintf(outputFile, "%d", result);
    fclose(outputFile);
    return 0;
}