// Заявление
// В Прибрежном регионе есть большой лес, где растет много реликтовых деревьев. Местные власти решили создать резервационный парк площадью от 0 и С квадратные метры. Парк должен иметь форму прямоугольника со сторонами, параллельными координатным осям.
// Активисты- экологи обследовали лес и обнаружили, что в нем содержится N реликтовые деревья, расположенные в координатах (xi,yi), измеряется в метрах.
// Найдите такое расположение и размер парка, чтобы количество реликтовых деревьев внутри него или на его границе было максимально возможным.
// Формат входного файла
// Входной файл содержит целые числа NS далее следует N пары целых чисел xiyi.
// Формат выходного файла
// Выходной файл должен содержать целые числа xayaxbу — координаты двух противоположных углов парка. Если существует более одного оптимального решения, выведите любое из них.
// Ограничения
// 1≤N≤500, −10^4≤xi,yi≤10^4, 1≤С .
// Выборочные испытания
// Нет.	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	    5 100                       0 0 10 10
//         0 0  10 0  10 10  0 10  15 10
// 2	    3 2                         0 0 20 0
//         0 0  10 0  20 0
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;
int compare(const void* a, const void* b) {
    Point* pointA = (Point*)a;
    Point* pointB = (Point*)b;
    return pointA->x - pointB->x;
}
int main() {
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    int n, s;
    fscanf(fin, "%d %d", &n, &s);
    Point* p = (Point*)malloc(n * sizeof(Point));
    for (int i = 0; i < n; ++i)
        fscanf(fin, "%d %d", &p[i].x, &p[i].y);
    Point* sorted = (Point*)malloc(n * sizeof(Point));
    memcpy(sorted, p, n * sizeof(Point));
    qsort(sorted, n, sizeof(Point), compare);
    int* x = (int*)malloc(n * sizeof(int));
    int bestC = 0;
    int xa = 0, ya = 0, xb = 0, yb = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (p[i].y <= p[j].y) {
                int l;
                if (p[j].y - p[i].y > 0) {
                    l = s / (p[j].y - p[i].y);
                } else {
                    l = 2 * (sorted[n - 1].x - sorted[0].x);
                }
                int m = 0;
                for (int k = 0; k < n; ++k) {
                    if (sorted[k].y >= p[i].y && sorted[k].y <= p[j].y) {
                        x[m] = sorted[k].x;
                        ++m;
                    }
                }
                int k1 = 0;
                int k2 = -1;
                int c = 0;
                while (k2 < m - 1) {
                    ++k2;
                    ++c;
                    while (x[k2] - x[k1] > l) {
                        ++k1;
                        --c;
                    }
                    if (c > bestC) {
                        bestC = c;
                        xa = x[k1];
                        ya = p[i].y;
                        xb = x[k2];
                        yb = p[j].y;
                    }
                }
            }
        }
    }
    fprintf(fout, "%d %d %d %d", xa, ya, xb, yb);
    fclose(fin);
    fclose(fout);
    free(p);
    free(sorted);
    free(x);
    return 0;
}