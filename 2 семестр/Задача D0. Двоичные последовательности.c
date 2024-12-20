// Условие
// Здравствуй, юный падаван!
// Прошу тебя вывести все двоичные последовательности длины N.
// Реши задачу двумя способами:рекурсивным переборомприбавлением 1 к числу в двоичной системе счисления
// Да пребудет с тобой произведение массы на ускорение!
// Формат входного файла
// Входной файл содержит единственное целое число N.
// Формат выходного файла
// Требуется вывести в выходной файл все двоичные строки длины N в лексикографическом порядке, по одному в каждой строке.
// Ограничения
// 1≤N≤15
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	2                           00
//                                 01
//                                 10
//                                 11
#include <stdio.h>

void generateBinaryRecursive(FILE* out, char* curr, int n) {
    if (n == 0) {
        fprintf(out, "%s\n", curr);
        return;
    }
    char temp1[100], temp2[100];
    sprintf(temp1, "%s0", curr);
    sprintf(temp2, "%s1", curr);
    generateBinaryRecursive(out, temp1, n - 1);
    generateBinaryRecursive(out, temp2, n - 1);
}
int main() {
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w");
    int n;
    fscanf(input, "%d", &n);
    generateBinaryRecursive(output, "", n);
    fclose(input);
    fclose(output);
    return 0;
}