// Условие
// Имеется текст и N слов. Длина текста составляет L символов, длина каждого слова — от 1 до 255 символов. Требуется для каждого слова определить, входит ли оно в текст. Все слова и текст состоят из латинских букв. Заглавные и строчные буквы считаются различными. Обратите внимание, данная задача отличается от задачи B только ограничениями.
// Формат входного файла
// В первой строке входного файла содержится текст, во второй — число N, в следующих N строках — слова.
// Формат выходного файла
// В выходном файле должны содержаться N чисел 1 или 0, обозначающих, что соответствующее слово входит или не входит в текст.
// Ограничения
// 1≤L≤20000, 1≤N≤10000.
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	Longlongstring              0 1
//     2
//     short
//     string
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void prefix_function(const char *s, int *pi, size_t n);

int is_substring(const char *text, const char *pattern) {
    size_t n = strlen(text);
    size_t m = strlen(pattern);
    if (m > n)
        return 0;
    int *pi = (int *)malloc(m * sizeof(int));
    prefix_function(pattern, pi, m);

    int j = 0;
    for (size_t i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            free(pi);
            return 1;
        }
    }

    free(pi);
    return 0;
}

void prefix_function(const char *s, int *pi, size_t n) {
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

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    char text[20001];
    int N;

    fscanf(input, "%20000s", text);
    fscanf(input, "%d", &N);

    char words[10000][256];
    for (int i = 0; i < N; ++i) {
        fscanf(input, "%255s", words[i]);
    }

    for (int i = 0; i < N; ++i) {
        fprintf(output, "%d ", is_substring(text, words[i]));
    }

    fclose(input);
    fclose(output);

    return 0;
}