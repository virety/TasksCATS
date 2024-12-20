// Условие
// Требуется написать программу, которая скалярно перемножает первый и последний столбец матрицы. Скалярным произведением двух векторов будет скалярная величина, равная сумме попарного произведения координат векторов (Например (1,2,3)⋅(3,4,5)=1∗3+2∗4+3∗5=26).
// Формат входных данных
// Первая строка содержит числа 
// N и M — количество строк и столбцов матрицы. Следующие N строк содержат M чисел каждая — элементы матрицы.
// Формат выходных данных
// Выходные данные должны содержать единственное число — скалярное произведение первого и последнего столбца матрицы.
// Примеры тестов
// №	Стандартный вход	Стандартный выход
// 1	2 2                 23
//     1 3
//     4 5
#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int matrix[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int scalar_product = 0;
    for (int i = 0; i < N; i++) {
        scalar_product += matrix[i][0] * matrix[i][M-1];
    }
    
    printf("%d\n", scalar_product);
    
    return 0;
}