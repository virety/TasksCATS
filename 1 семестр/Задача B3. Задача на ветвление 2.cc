// Условие
// Даны четыре числа a, b, c, d. Если их сумма - четное число и произведение неотрицательное, то вывести наибольшее из них, если сумма - нечетное число и произведение неотрицательное , то вывести наименьшее из них,если произведение - отрицательное число, то вывести сумму всех четных чисел.
// Формат входного файла
// Входной файл содержит четыре целых числа
// Формат выходного файла
// Выходной файл должен содержать одно целое число
// Ограничения
// −1000≤a,b,c,d≤1000
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	1 2 3 4                     4
#include <stdio.h> 
char * filename1("input.txt"); 
char * filename2("output.txt"); 
FILE * fin = fopen(filename1, "rt"); 
FILE * fout = fopen(filename2, "wt"); 
int main(){ 
    double proiz = 1; 
    int sum = 0, numbers[4], tmp, k, n = 4, sum2 = 0; 
    for (int i = 0; i < 4; i++) 
    { 
        fscanf( fin, "%d", &numbers[i]); 
        sum = sum + numbers[i]; 
        proiz = proiz * numbers[i]; 
    } 
    while (n > 1) 
    { 
        k = 0; 
        for (int j = 1; j < 4; j++) 
        { 
            if (numbers[j-1] > numbers[j]) 
            { 
                tmp = numbers[j]; 
                numbers[j] = numbers[j - 1]; 
                numbers[j - 1] = tmp; 
                k = j; 
            } 
        } 
        n = k; 
    } 
    if ((sum % 2) == 0 && proiz >= 0) 
    { 
        fprintf(fout, "%d", numbers[3]); 
        return 0; 
    } 
    else if ((sum % 2) != 0 && proiz >= 0) 
    { 
        fprintf( fout, "%d", numbers[0]); 
        return 0; 
    } 
    else 
    { 
        for (int x = 0; x < 4; x++) 
        { 
            if (numbers[x] % 2 == 0) 
            { 
                sum2 = sum2 + numbers[x]; 
            } 
        } 
        fprintf( fout, "%d", sum2); 
        return 0; 
    } 
}