// Условие
// Однажды Марфа Геннадьевна пришла в столовую. В меню было N блюд. Блюдо с номером i стоит ci рублей. Для каждого блюда известен также коэффициент сытости блюда — ai.
// Марфа Геннадьевна знает, что для того, чтобы наесться, нужно, чтобы сумма коэффициентов сытости съеденных блюд была не меньше A.
// Какие блюда нужно взять в столовой, чтобы наесться и потратить как можно меньше денег? Обратите внимание, что Марфа Геннадьевна может взять более одной порции блюда (любое целое неотрицательное число порций).
// Формат входного файла
// Входной файл содержит целые числа NA.
// Далее следуют N пар целых чисел ciai.
// Формат выходного файла
// Выходной файл должен содержать минимальную сумму денег, которую нужно потратить, чтобы наесться.
// Ограничения
// 1≤N≤100
// 1≤A≤1000
// 1≤ci≤500
// 1≤ai≤100
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	3 10                      11
//   2 1
//   5 4
//   6 6
// 2	4 32                      4
//   1 8
//   2 4
//   3 2
//   4 1
#include <stdio.h>
#include <limits.h>

#define INFINITY INT_MAX/2

int main() {
  int cost[100], satisfaction[100], minCost[1100];
  int numDishes, minSatisfaction, result, i, satisfactionLevel;

  FILE *input = fopen("input.txt", "r");
  FILE *output = fopen("output.txt", "w");

  fscanf(input, "%d", &numDishes);
  fscanf(input, "%d", &minSatisfaction);

  for (i = 0; i < numDishes; i++) {
    fscanf(input, "%d", &cost[i]);
    fscanf(input, "%d", &satisfaction[i]);
  }

  minCost[0] = 0;

  for (satisfactionLevel = 1; satisfactionLevel < minSatisfaction+100; satisfactionLevel++) {
    minCost[satisfactionLevel] = INFINITY;
    for (i = 0; i < numDishes; i++) {
      if (satisfaction[i] <= satisfactionLevel) {
        if (minCost[satisfactionLevel-satisfaction[i]] + cost[i] < minCost[satisfactionLevel]) {
          minCost[satisfactionLevel] = minCost[satisfactionLevel-satisfaction[i]] + cost[i];
        }
      }
    }
  }

  result = INFINITY;
  for (satisfactionLevel = minSatisfaction; satisfactionLevel < minSatisfaction+100; satisfactionLevel++) {
    if (minCost[satisfactionLevel] < result) {
      result = minCost[satisfactionLevel];
    }
  }

  fprintf(output, "%d", result);

  fclose(input);
  fclose(output);

  return 0;
}