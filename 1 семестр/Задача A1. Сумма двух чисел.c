// Условие
// Вывести сумму двух заданных чисел.
// Формат входных данных
// На первой строке входного файла находятся два целых числа a и b (−109≤a,b≤109).
// Формат выходных данных
// Вашей программе требуется вывести единственное число — сумму заданных чисел a+b.
// Примеры тестов
// №	Стандартный вход	Стандартный выход
// 1	2 3                 5
// 2	17 -18              -1
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x,y,f;
    scanf("%d%d",&x, &y);
    f=x+y;
    printf("%d", f);
}