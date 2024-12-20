// Условие
// Вершины отрезка AB имеют координаты (Xa;Ya) и (Xb;Yb).
// Требуется найти координаты вершин отрезка 
// A∗B∗ (X∗a;Y∗a) и (X∗b;Y∗b), полученного путём поворота отрезка AB вокруг точки O (Xo;Yo) на β градусов.
// Формат входного файла
// Входной файл содержит целые числа 
// Xa,Ya,Xb,Yb,Xo,Yo,β
// Формат выходного файла
// Выходной файл должен содержать четыре вещественных числа 
// X∗a,Y∗a,X∗b,Y∗b с точностью 10−3.
// Ограничения
// 0≤|Xa|,|Ya|,|Xb|,|Yb|,|Xo|,|Yo|≤10^5
// 0≤β≤360
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	1 1  2 2  0 0  90           -1.000000000 1.000000000 -2.000000000 2.000000000
// 2	1 1  2 2                    0.000000000 1.414213562 0.000000000 2.828427125
//     0 0
//     45
// 3	7 5                         11.000000000 11.000000000 7.000000000 5.000000000
//     11 11
//     9 8
//     180
#include <stdio.h>
#include <math.h>
#include <stddef.h>
int main(){
    char * filename1 = "input.txt";
    char * filename2 = "output.txt";
    FILE * fout = fopen(filename2, "wt");
    FILE * fin = fopen(filename1, "rt");
    double xa, ya, xb, yb, xo, yo, angle, xa_new, ya_new, xb_new, yb_new,resx1,resx2,resy1,resy2;
    double PI = 3.141592653589793;
    fscanf(fin,"%lf %lf %lf %lf %lf %lf %lf", &xa, &ya, &xb, &yb, &xo, &yo,&angle);
    xa -= xo;
    ya -= yo;
    xb -= xo;
    yb -= yo;
    xa_new = xa * cos(angle * PI / 180) - ya * sin(angle * PI / 180);
    ya_new = xa * sin(angle * PI / 180) + ya * cos(angle * PI / 180);
    xb_new = xb * cos(angle * PI / 180) - yb * sin(angle * PI / 180);
    yb_new = xb * sin(angle * PI / 180) + yb * cos(angle * PI / 180);
    resx1=xa_new + xo;
    resy1=ya_new + yo;
    resx2=xb_new + xo;
    resy2=yb_new + yo;
    fprintf(fout,"%.4lf %.4lf %.4lf %.4lf", resx1, resy1, resx2, resy2);
}