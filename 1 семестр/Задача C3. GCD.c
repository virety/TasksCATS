// Условие
// Дано 3 числа: 
// A, B, C. Необходимо посчитать наибольший общий делитель (НОД) каждой из пар A и B, A и C, B и C
// Формат входных данных
// Входные данные содержат 3 числа — A, B, C.
// Формат выходных данных
// Выходные данные должны содержать 3 числа — НОД A и B, НОД A и C и НОД B и C
// Примеры тестов
// №	Стандартный вход	Стандартный выход
// 1	2 6 3               2 1 3
#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int gcd3(int a, int b, int c)
{
    int result = gcd(a, b);
    result = gcd(result, c);
    return result;
}
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int result = gcd3(a, b, c);
    printf("%d %d %d", gcd(a, b), gcd(a, c), gcd(b, c));
    return 0;
}
