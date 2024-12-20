// Условие
// Известно, что наличие кофемашины — это очень важный для программистов фактор при выборе места работы. В одной программистской конторе нужны новые сотрудники, и шеф решил в первую очередь выбирать новую кофемашину, надеясь повысить привлекательность конторы. Поскольку шеф сам программировал когда-то, ему не составило труда разработать математическую модель того, как программисты пьют кофе.
// Каждый программист, придя утром на работу, первым делом идёт на кухню к кофемашине. Если машина свободна, то программист включает её, и она делает кофе в течение t единиц времени. Как только кофе готов, программист забирает его и уходит пить на рабочем месте. Временем выхода программиста из кухни можно пренебречь. Если же машина занята, то программист понимает, что имеет дело с очередью, и занимает место в её конце, разговаривая с коллегами из очереди о работе.
// Шеф знает, что разговоры в очереди к кофемашине плодотворно влияют на дальнейшую производительность программистов в течение всего дня. Поэтому, имеет смысл выбирать кофемашину с наибольшим параметром t. Но если количество программистов в очереди превысит константу p, то программисты перестанут уходить из очереди с готовым кофе и разговор затянется.
// Зная момент времени, в который каждый программист приходит на работу, помогите выбрать шефу наибольший целочисленный параметр t, который не приведёт к очереди длиннее p.
// Если один программист заходит на кухню, а другой в этот же момент времени выходит, то считается что они не стоят в одной очереди.
// Формат входного файла
// В первой строке входного файла содержится два целых числа — n и p. Во второй строке записаны n целых чисел a1, a2, …, an, задающих время прихода каждого программиста на работу (время считается от начала рабочего дня в тех же единицах, в которых необходимо выдать ответ).
// Формат выходного файла
// В выходной файл выведите единственное число — ответ к задаче.
// Ограничения
// 2≤n≤10^6;
// 1≤p<n;
// 0≤ai≤10^9;
// Все ai различны.
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	3 2                         30
//     0 30 10 
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int is_result(int* arrival_times, int n, int k, int p) {
    int* queue = (int*)malloc((n+1) * sizeof(int));
    int front = 0;
    int rear = -1;
    int max_length = 0;
    for (int i = 0; i < n; i++) {
        int arrival_time = arrival_times[i];
        int end_time = arrival_time + k;
        while (front <= rear && queue[front] <= arrival_time) {
            front++;
        }
        if (front <= rear) {
            if (end_time > queue[rear] + k) {
                end_time = end_time;
            } else {
                end_time = queue[rear] + k;
            }
        }
        rear++;
        queue[rear] = end_time;
        if (max_length > rear - front) {
            max_length = max_length;
        } else {
            max_length = rear - front;
        }
    }
    free(queue);
    return max_length < p;
}
int main() {
    FILE *inp = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    int n, p;
    fscanf(inp,"%d %d", &n, &p);
    int *arrival_times = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(inp,"%d", &arrival_times[i]);
    }
    qsort(arrival_times, n, sizeof(int), compare);
    int left = 0;
    int right = 1e9;
    int result;
    while (left <= right) {
        int mid = (left + right) / 2;
        int mid_res = is_result(arrival_times, n, mid, p);
        if (mid_res) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    fprintf(out, "%d", result);
    fclose(inp);
    fclose(out);
    free(arrival_times);
    return 0;
}