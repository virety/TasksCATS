#include <stdio.h>

int main() {
    int number, i;
    printf("Введите число: ");
    scanf("%d", &number);
    printf("Разложение числа %d на простые множители: ", number);
    while (number % 2 == 0) {
        printf("%d, ", 2);
        number = number / 2;
    }
    for (i = 3; i * i <= number; i = i + 2) {
        while (number % i == 0) {
            printf("%d, ", i);
            number = number / i;
        }
    }
    if (number > 2) {
        printf("%d ", number);
    }
    printf("\n");
    return 0;
}