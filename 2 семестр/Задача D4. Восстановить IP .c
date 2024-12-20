// Условие
// Корректная запись IP-адреса — это строка, состоящая из четырёх десятичных чисел в диапазоне от 0 до 255 каждое, разделённых символом "точка" (ASCII 46). Компоненты записи IP-адреса не должны содержать лидирующих нулей.
// Петя записал IP-адрес школьного сервера на листке бумаги и положил его в карман куртки. Петина мама случайно постирала куртку вместе с запиской. После стирки Петя обнаружил в кармане четыре обрывка с фрагментами IP-адреса.
// Помогите Пете восстановить IP-адрес.
// Формат входного файла
// Входной файл содержит четыре строки длиной от 1 до 12 символов каждая, состоящие из десятичных цифр и точек.
// Формат выходного файла
// Выходной файл должен содержать все различные правильные записи IP-адресов, по одной записи в строке. Строки должны быть отсортированы лексикографическом порядке. Исходные данные таковы, что хотя бы одна такая запись существует.
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	7.2                         102.84.17.247
//     102.
//     47
//     84.1
// 2	.0.                         100.0.2.0
//     00                          2.0.0.100
//     1
//     2.0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_element(char *str, char symbol) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == symbol)
            count++;
    return count;
}

int permutate(char *str1, char *str2) {
    for (int i = 0; i < (strlen(str1) < strlen(str2) ? strlen(str1) : strlen(str2)); i++) {
        if (str1[i] < str2[i])
            return 0;
        if (str1[i] > str2[i])
            return 1;
    }
    if (strlen(str1) <= strlen(str2))
        return 0;
    return 1;
}

void sort_string_array(char *str[], int n) {
    int swapped;
    do {
        swapped = 0;
        for (int i = 1; i < n; i++)
            if (permutate(str[i - 1], str[i])) {
                char *temp = str[i - 1];
                str[i - 1] = str[i];
                str[i] = temp;
                swapped = 1;
            }
    } while (swapped);
}

int next_combinate(int arr[], int n) {
    int i = n - 2;
    while (i != -1 && arr[i] >= arr[i + 1])
        i--;
    if (i == -1)
        return 0;

    int j = n - 1;
    while (arr[i] >= arr[j])
        j--;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    int l = i + 1, r = n - 1;
    while (l < r) {
        temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }
    return 1;
}

int ip_is_valid(char *ip_address) {
    if (count_element(ip_address, '.') != 3)
        return 0;
    
    int parts = 4, ptr = 0;
    char *parts_of_ip[parts];
    for (int i = 0; i < parts; i++) {
        parts_of_ip[i] = (char *)malloc(sizeof(char) * 4);
        int j = 0;
        while (ip_address[ptr] != '.' && ptr < strlen(ip_address)) {
            parts_of_ip[i][j++] = ip_address[ptr];
            ptr++;
        }
        parts_of_ip[i][j] = '\0';
        ptr++;
    }

    for (int i = 0; i < parts; i++) {
        if (strlen(parts_of_ip[i]) > 1 && parts_of_ip[i][0] == '0')
            return 0;
        if (strlen(parts_of_ip[i]) == 0)
            return 0;

        int num = atoi(parts_of_ip[i]);
        if (!(num >= 0 && num <= 255))
            return 0;
    }

    for (int i = 0; i < parts; i++)
        free(parts_of_ip[i]);

    return 1;
}

int main() {
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    char *fragments[4];
    for (int i = 0; i < 4; i++) {
        fragments[i] = (char *)malloc(sizeof(char) * 16);
        fscanf(in, "%s", fragments[i]);
    }

    int length_of_addresses = 24;
    int fragments_indexes[] = {0, 1, 2, 3, 4};
    char *ip_addresses[length_of_addresses];
    for (int i = 0; i < length_of_addresses; i++)
        ip_addresses[i] = (char *)malloc(sizeof(char) * 16);

    int ptr = 0;
    do {
        strcpy(ip_addresses[ptr], "");
        for (int i = 0; i < 4; i++)
            strcat(ip_addresses[ptr], fragments[fragments_indexes[i]]);
        ptr++;
    } while (next_combinate(fragments_indexes, 4));
    sort_string_array(ip_addresses, length_of_addresses);

    for (int i = 0; i < length_of_addresses; i++)
        if (ip_is_valid(ip_addresses[i]))
            if (i == 0 || (i > 0 && strcmp(ip_addresses[i - 1], ip_addresses[i]) != 0))
                fprintf(out, "%s\n", ip_addresses[i]);

    for (int i = 0; i < 4; i++)
        free(fragments[i]);
    for (int i = 0; i < length_of_addresses; i++)
        free(ip_addresses[i]);
    fclose(in);
    fclose(out);
    return 0;
}