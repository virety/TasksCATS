// Условие
// Витя, Петя и Олег решили сходить на рыбалку за селёдками. В море селёдок много и каждая из них весит строго целое количество килограмм. Олег провёл классификацию рыбы и выяснил, что массы селёдок образуют последовательность, заданную следующим образом: xi=xi−1+i. Минимальный вес селёдки составляет один килограмм. Мальчики взяли с собой ведро, в которое помещается 
// N килограмм рыбы. Разумеется, они хотели бы вернуться домой с полным ведром селёдок.
// Так как рыбачить умеет только Витя, а Олег уже свою часть работы закрыл исследованием, то Петя вызвался посчитать, какое минимальное количество селёдок Вите требуется поймать, пока Петя и Олег будут греться у костра.
// Формат входных данных
// Входной файл содержит единственное число 
// N — вместимость ведра в килограммах.
// Формат выходных данных
// В выходной файл выведите число — минимальное число селёдок.
// Ограничения
// 1≤N≤5∗10^11

// Примеры тестов
// №	Стандартный вход	Стандартный выход
// 1	3                 1
// 2	5                 3
#include <math.h>
#include <stdio.h>

int main() {
  long long n;
  double x1, x2, x3;
  scanf("%lld", &n);

  x1 = (sqrt(1+8 * n)-1) / 2;
  if (x1 == (long long)x1) {
    printf("1\n");
    return 0;
  }
  for (x1 = 1; x1 <= (long long)(-1 + sqrt(8 * n + 2)) / 2; x1++) {
    x2 = (-1 + sqrt(1 + 8 * n - 4 * x1 * x1 - 4 * x1)) / 2;
    if (x2 == (long long)x2) {
      printf("2\n");
      return 0;
    }
  }
  printf("3\n");
  return 0;
}