// Условие
// Дана матрица 2×2, в которой одно из значений неизвестно. Оно обозначено буквой X (X всегда находится в одой и той же позиции). Также известно собственное значение матрицы λ.Требуется определить значение X.
// Формат входных данных
// Первая строка входных данных содержит два вещественных числа a11 и a12. Во второй строке содержится вещественное число a21 и символ X. Третья строка содержит одно вещественное число λ
// Формат выходных данных
// Первая строка выходных данных должна содержать строку NO если такого X не существует, INF если значений X бесконечно много и YES если такое значение одно. В случае, если существует одно значение X, следует вывести число X с точностью не менее 4 знаков после запятой.
// Ограничения
// −10^6≤a11,a12,a21,λ≤10^6
// Примеры тестов
// №	Стандартный вход	Стандартный выход
// 1	1 2                 YES
//     2 X                 4.00000000000000000000
//     5
// 2	5 2                 NO
//     2 X
//     5
// 3	5.0 0.0             INF
//     2.0 X
//     5.0
#include <stdio.h>

int main() {
    double a11, a12, a21, lambda;
    scanf("%lf %lf", &a11, &a12);
    scanf("%lf %*c", &a21);
    scanf("%lf", &lambda);
    
    double x;
    
    if(((a11*lambda)-(lambda*lambda)+(a12*a21))==0&&((a11-lambda)==0)){
        printf("INF");
    }
    else if (a11-lambda==0){
        printf("NO");
    }
    else {
        x = (((a11*lambda)-(lambda*lambda)+(a12*a21))/(a11-lambda));
        printf("YES\n%.4lf\n", x);
    }
}