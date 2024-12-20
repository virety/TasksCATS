// Заявление
// Вам нужно написать программу, которая получает две строки и находит позицию, в которой вторая строка появляется в первой в качестве подстроки.
// Формат входного файла
// Первая и вторая строки входного файла содержат заданные строки. Каждая строка представляет собой последовательность строчных латинских букв от 'a' до 'z' и пробелов.
// Формат выходного файла
// Выходной файл должен содержать единственное целое число — позицию первого вхождения подстроки в строке, или −1 если таковых нет. Позиции нумеруются начиная с 1.
// Ограничения
// Длина каждой строки не превышает 100000 Персонажи.
// Примеры тестов
// Нет.	Входной файл (input.txt)	  Выходной файл (output.txt)
// 1	yezhiki nachinayut i vyygryvayut  16
//     yut
#include <stdio.h>
#include <string.h>
int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    char s[100001];
    char pattern[100001];
    fscanf(input, "%s %s", s, pattern);
    int pi[strlen(pattern)];
    size_t n = strlen(s);
    size_t m = strlen(pattern);
    prefix_function(pattern, pi, m);
    int position = -1;
    int j = 0;
    for (size_t i = 0; i < n; ++i) {
        while (j > 0 && s[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (s[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            position = i - m + 2;
            break;
        }
    }
    fprintf(output, "%d", position);
    fclose(input);
    fclose(output);
    return 0;
}
void prefix_function(char *s, int *pi, size_t n) {
    pi[0] = 0;
    for (size_t i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while ((j > 0) && (s[i] != s[j])) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        pi[i] = j;
    }
}