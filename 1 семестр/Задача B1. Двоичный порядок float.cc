// Условие
// Требуется написать программу, которая считывает вещественное число в переменную типа float и выводит его двоичный порядок по стандарту IEEE-754.
// Для поиска порядка необходимо использовать битовые операции.
// Формат входных данных
// Входные данные содержат единственное вещественное число.
// Формат выходных данных
// Выходные данные должны содержать целое число, являющееся двоичным порядком вещественного числа, считанного в переменную типа float.
// Примеры тестов
// №	Стандартный вход	Стандартный выход
// 1	2.0               1
// 2	0.5               -1
#include <stdio.h>
#include <string.h>

int main() {
  float num;
  long long nums_exponent;
  scanf("%f", &num);
  memcpy(&nums_exponent, &num, 4);
  nums_exponent = nums_exponent >> 23;
  nums_exponent %= 256; /* Takes the exponent */
  if (num == 0) {
    printf("0");
    return 0;
  }
  if (nums_exponent == 0)
    nums_exponent = -126; 
  else
    nums_exponent -= 127; 
  printf("%lli\n", nums_exponent);
  return 0;
}
