// Заявление
// Давайте назовем целое число элитным, если оно делится на каждую цифру его десятичного представления.
// Задано целое число 
// x Ваша программа должна найти наименьший элитный номер , больший или равный x.
// Формат входного файла
// Входной файл содержит целое число x.
// Формат выходного файла
// Выходной файл должен содержать единственное целое число — наименьший элитный номер.
// Ограничения
// 1≤x10^10
// Примеры тестов
// Нет.	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	    10                          11
// 2	    7777777777                  7777777777
// 3	    579916                      593595
#include <stdio.h>
#define lli long long int
lli gcd(lli a, lli b) {
    if (a == 0) {
        return b;
    }
    return gcd(b%a, a);
}
lli nok(lli a, lli b) {
    return (a * b / gcd(a, b));
}
void rise_num(lli *n) {
    lli temp_nok, start_num_to_nok = *n/10;
    lli temp_res, need_to_delete = 10, temp_num;
    while (start_num_to_nok) {
        temp_num = start_num_to_nok;
        temp_nok = 1;
        while (temp_num) {
            if (temp_num % 10 == 0) {
                return;
            }
            temp_nok = nok(temp_nok, temp_num%10);
            temp_num /= 10;
        }
        temp_res = (*n - (*n % temp_nok) + temp_nok);
        if ((temp_res / need_to_delete) == start_num_to_nok) {
            *n = temp_res;
            return;
        }
        start_num_to_nok /= 10;
        need_to_delete *= 10;
    }
    return;
}
void remove_0(lli *n) {
    lli right_add = 0, left_add = *n, power = 1,  temp;
    while (left_add) {
        temp = left_add % 10;
        left_add /= 10;
        power *= 10;
        right_add = right_add * 10 + 1;
        if (temp == 0) {
            *n = left_add * power + right_add;
        }
    }
    return;
}
long long int check_to_ok(lli n) {
    lli copy_n = n;
    while (copy_n) {
        if (copy_n % 10 == 0) {
            return 0;
        }
        if (n % (copy_n % 10) != 0) {
            return 0;
        }
        copy_n /= 10;
    }
    return 1;
}
int main() {
    FILE *inp;
    FILE *out;
    inp = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    int size;
    lli res = 0, n, copy_n, len_n = 0;
    fscanf(inp, "%lld", &n);
    if (n <= 1000000000) {
        while (1) {
            res = check_to_ok(n);
            if (res) {
                fprintf(out, "%lld", n);
                break;
            }
            n++;
            remove_0(&n);
        }
        return 0;
    }
    while (1) {
        res = check_to_ok(n);
        if (res) {
            fprintf(out, "%lld", n);
            break;
        }
        rise_num(&n);
        printf("- %lld\n", n);
        remove_0(&n);
    }
    return 0;
}