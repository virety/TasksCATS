// Условие
// Заданы три числа: a, b, c. Необходимо выяснить, существуют ли такие числа x и y, что:x получается перестановкой цифр числа a;y получается перестановкой цифр числа b;x и y не содержат лидирующих нулей;x+y=c.
// Формат входного файла
// Входной файл содержит целые числа abc.
// Формат выходного файла
// Если искомые числа существуют, вывести в первую строку выходного файла слово YES, а во вторую — числа xy, разделённые пробелом. В противном случае вывести слово NO.
// Ограничения
// 1<a,b,c<10^9
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	12 31 25                    YES
//                                 12 13
// 2	12 31 26                    NO
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int value;
    int* digits;
    int length;
} NUMBER;

void swap(int* x, int* y) {
   int temp = *x;
   *x = *y;
   *y = temp;
}

int get_length(int x) {
    return (int) log10(x) + 1;
}

int compare_digits(NUMBER* x, int y) {
    if (x -> length != get_length(y)) return 0;
    int m[10] = {0};
    for (int i = x -> length; i > 0; i--) {
        m[x -> digits[i - 1]]++;
    }
    for (int i = y % 10; y > 0; y /= 10, i = y % 10) {
        m[i]--;
        if (m[i] < 0) return 0;
    }
    return 1;
}

void find_answer(int* result, NUMBER* a, NUMBER* b, NUMBER* c, int n) {
    if(n == 1) {
        int d = c -> value - a -> value;
        if (a -> digits[0] != 0 && compare_digits(b, d)) {
            result[0] = a -> value;
            result[1] = d;
        }
        return;
    }
    for(int i = 0; i < n - 1; i++) {
        find_answer(result, a, b, c, n - 1);
        swap(a -> digits + (n % 2 == 0 ? i : 0), a -> digits + n - 1);
        a -> value = 0;
        for (int i = 0; i < a -> length; i++) {
            a -> value = a -> value * 10 + a -> digits[i];
        }
    }
    find_answer(result, a, b, c, n - 1);
}

NUMBER* create_number(int x) {
    NUMBER* number = malloc(sizeof(NUMBER));
    number -> value = x;
    number -> length = get_length(x);
    number -> digits = malloc(number -> length * sizeof(int));
    for (int i = number -> length; i > 0; i--) {
        number -> digits[i - 1] = x % 10;
        x /= 10;
    }
    return number;
}

void free_number(NUMBER* x) {
    free(x -> digits);
    free(x);
}

int main(int argc, char const *argv[]) {
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w");
    
    int a, b, c;
    fscanf(input, "%d %d %d", &a, &b, &c);
    NUMBER* number_a = create_number(a);
    NUMBER* number_b = create_number(b);
    NUMBER* number_c = create_number(c);
    
    int* result = calloc(2, sizeof(int));
    find_answer(result, number_a, number_b, number_c, number_a -> length);
    
    if (result[0] && result[1]) fprintf(output, "YES\n%d %d", result[0], result[1]);
    else fprintf(output, "NO");

    free(result);
    free_number(number_a);
    free_number(number_b);
    free_number(number_c);
    fclose(input);
    fclose(output);
    
 #include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int value;
    int* digits;
    int length;
} NUMBER;

void swap(int* x, int* y) {
   int temp = *x;
   *x = *y;
   *y = temp;
}

int get_length(int x) {
    return (int) log10(x) + 1;
}

int compare_digits(NUMBER* x, int y) {
    if (x -> length != get_length(y)) return 0;
    int m[10] = {0};
    for (int i = x -> length; i > 0; i--) {
        m[x -> digits[i - 1]]++;
    }
    for (int i = y % 10; y > 0; y /= 10, i = y % 10) {
        m[i]--;
        if (m[i] < 0) return 0;
    }
    return 1;
}

void find_answer(int* result, NUMBER* a, NUMBER* b, NUMBER* c, int n) {
    if(n == 1) {
        int d = c -> value - a -> value;
        if (a -> digits[0] != 0 && compare_digits(b, d)) {
            result[0] = a -> value;
            result[1] = d;
        }
        return;
    }
    for(int i = 0; i < n - 1; i++) {
        find_answer(result, a, b, c, n - 1);
        swap(a -> digits + (n % 2 == 0 ? i : 0), a -> digits + n - 1);
        a -> value = 0;
        for (int i = 0; i < a -> length; i++) {
            a -> value = a -> value * 10 + a -> digits[i];
        }
    }
    find_answer(result, a, b, c, n - 1);
}

NUMBER* create_number(int x) {
    NUMBER* number = malloc(sizeof(NUMBER));
    number -> value = x;
    number -> length = get_length(x);
    number -> digits = malloc(number -> length * sizeof(int));
    for (int i = number -> length; i > 0; i--) {
        number -> digits[i - 1] = x % 10;
        x /= 10;
    }
    return number;
}

void free_number(NUMBER* x) {
    free(x -> digits);
    free(x);
}

int main(int argc, char const *argv[]) {
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w");
    
    int a, b, c;
    fscanf(input, "%d %d %d", &a, &b, &c);
    NUMBER* number_a = create_number(a);
    NUMBER* number_b = create_number(b);
    NUMBER* number_c = create_number(c);
    
    int* result = calloc(2, sizeof(int));
    find_answer(result, number_a, number_b, number_c, number_a -> length);
    
    if (result[0] && result[1]) fprintf(output, "YES\n%d %d", result[0], result[1]);
    else fprintf(output, "NO");

    free(result);
    free_number(number_a);
    free_number(number_b);
    free_number(number_c);
    fclose(input);
    fclose(output);
    
    return 0;
}   return 0;
}