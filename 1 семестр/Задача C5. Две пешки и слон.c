// Условие
// На шахматной доске расположены две пешки. Требуется поставить на доску слона так, чтобы обе пешки оказались под боем.Шахматная доска имеет размер 8 на 8. Слон бьет ближайшую фигуру на каждом из четырех диагональных направлений от себя.
// Формат входного файла
// Входной файл содержит числа 
// x1y1x2y2 — координаты первой и второй пешек.
// Формат выходного файла
// Если задача имеет решение, то выходной файл должен содержать два числа — координаты слона. Если решений несколько, вывести любое из них. Если задача не имеет решения, вывести единственное число 0.
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	3 6 7 5                     0
// 2	3 4 5 6                     4 5
// 3	4 5 5 6                     0
#include <stdio.h>
#include<stdlib.h>
#include <math.h>
int slon(int a, int b, int c, int d){
    return (abs(a-c) == abs(b-d));
}
int hit_both(int i, int j, int a1, int b1, int a2, int b2){
    int bool1 = ((a1 > i) == (a2 > i));
    int bool2 = ((b1 > j) == (b2 > j));
    return (bool1 && bool2);
}
int main(){
    FILE *inp;
    FILE *out;
    inp = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    int a1, b1, a2, b2;
    fscanf(inp, "%d %d %d %d", &a1, &b1, &a2, &b2);
    for (int i = 0;i < 8;i++){
        if (i == a1 || i == a2){
            continue;
        }
        for (int j = 0;j < 8;j++){
            if (slon(i, j, a1, b1) && slon(i, j, a2, b2)){
                if (!hit_both(i, j, a1, b1, a2, b2)){
                    fprintf(out, "%d %d", i, j);
                    return 0;
                }
            }
        }
    }
    fprintf(out, "0");
    fclose(inp);
    fclose(out);
    return 0;
}