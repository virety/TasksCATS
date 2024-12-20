// Условие
// Поликлиника города N просит вас о помощи. В период пандемии на прием к терапевту стало приходить слишком много посетителей. Прием у терапевта длится ровно K минут. Если очередной посетитель приходит в тот момент, когда терапевт уже принимает кого-то, то он встает в очередь. Никто не любит очереди, поэтому перед тем, как предпринимать какие-то действия, администрация поликлиники попросила вас найти максимальную длину очереди за последний день.
// Формат входных данных
// Первая строка входных данных содержит два целых числа 
// N — количество посетителей за последний день и K — длительность приема одного пациента.
// Вторая строка содержит N чисел, отсортированных по возрастанию: ti  — время, когда i−ый посетитель пришел на прием к терапевту.
// Формат выходных данных
// Выходные данные должны содержать одно целое число  — максимальную длину очереди за последний день.
// Ограничения
// 1≤N≤10^5
// 1≤K≤10^9
// 0≤ti≤10^9
// Примеры тестов
// №	Стандартный вход	Стандартный выход
// 1	5 5                 2
//      0 5 5 6 20
// 2	5 2                 0
//      1 4 6 8 20
// 3	6 5                 1
//      0 5 10 15 19 25
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int *arrival_times = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrival_times[i]);
    }
    int *queue = (int*)malloc(n * sizeof(int));
    int front = 0;
    int rear = 0;
    int max_length = 0;
    for (int i = 0; i < n; i++) {
        int arrival_time = arrival_times[i];
        int end_time = arrival_time + k;
        while (front < rear && queue[front] <= arrival_time) {
            front++;
        }
        if (front < rear) {
            int temp = queue[rear-1] + k;
            if (end_time > temp) {
                end_time = end_time;
            } else {
                end_time = temp;
            }
        }
        queue[rear++] = end_time;
        int length = rear - front - 1;
        if (length > max_length) {
            max_length = length;
        }
    }
    printf("%d\n", max_length);
    free(arrival_times);
    free(queue);
    return 0;
}