// Условие
// Два друга-ирландца Фаолан и Леон очень любят петь, особенно в праздники, когда они могут собраться и петь песни вместе. Хоть они и друзья, у них не так много общих песен, но это не мешает им пытаться петь разные песни одновременно.
// Друзья обнаружили, что разные строки двух песен совместимы и могут быть спеты в унисон, если у строк одинаковая интонация, а количество слогов в этих строках совпадает. Интонация строки считается восклицательной, если в строке есть восклицательный знак (ASCII 33), и нейтральной во всех остальных случаях.
// Для слогораздела Фаолан предлагает использовать общепринятую систему, в которой слогообразующим является гласный звук, и при этом два гласных звука не могут находиться в пределах одного слога. В случае, когда слово целиком состоит из согласных, оно за слог не считается, а производимый им согласный звук сливается со слогом в следующем или предыдущем слове.
// Когда Фаолан и Леон поют, они следуют по текстам своих песен слева направо, сверху вниз, с удовольствием распевая в унисон совместимые строки и пропуская все остальные.
// Сейчас друзья планируют заранее свое выступление, и им интересно, для данных двух песен, сколько суммарно децисекунд они могут пропеть в унисон при условии, что каждый слог пропевается в течение одной децисекунды. Естественно, друзей интересует максимально возможная величина.
// Формат входных данных
// В первой строке входных данных содержатся целые числа NM: количество строк в первой и второй песне соответственно. Далее следуют N+M строк, содержащих текст первой и затем второй песни. Каждая строка может состоять только из печатных ASCII символов.
// Формат выходных данных
// Выходные данные должны содержать одно целое число: максимальное количество децисекунд, в течение которых друзья могут петь в унисон.
// Ограничения
// 1≤N,M≤10^6
// N∗M≤10^7 
// Длина каждой строки не превосходит 50.
// Описание подзадач и системы оценивания
// Баллы за каждую подзадачу начисляются только в случае, если все тесты этой подзадачи успешно пройдены.
// Подзадача	Баллы	Дополнительные ограничения
//                     N              M
// 1	        20	    N=1            1≤M≤10^4
// 1	        30	    1≤N≤10         1≤M≤10
// 1	        50	    1≤N≤10^6       1≤M≤10^6
// Примеры тестов
// №	Стандартный вход	                  Стандартный выход
// 1	3 4                                   17
//     It's funny how the war goes on
//     Without John, without our John
//     La la la la la, la la!
//     We're so young and so gone
//     Let's chase the dragon from our home
//     Ah ah from our home!
//     From our home

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1024

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int isvowel[256] = {0};
    char vowels[] = "aeiouyAEIOUY";
    for (int i = 0; i < strlen(vowels); i++) {
        isvowel[(int)vowels[i]] = 1;
    }
    int N, M;
    fscanf(fin, "%d %d\n", &N, &M);
    int *arrN_num = (int *)malloc(N * sizeof(int));
    int *arrN_exclamation = (int *)malloc(N * sizeof(int));
    int *arrM_num = (int *)malloc(M * sizeof(int));
    int *arrM_exclamation = (int *)malloc(M * sizeof(int));
    char line[MAX_LINE_LENGTH];
    for (int i = 0; i < N; i++) {
        fgets(line, MAX_LINE_LENGTH, fin);
        int num = 0;
        int exclamation = 0;
        for (int j = 0; j < strlen(line); j++) {
            if (isvowel[(int)line[j]]) {
                num++;
            }
            if (line[j] == '!') {
                exclamation = 1;
            }
        }
        arrN_num[i] = num;
        arrN_exclamation[i] = exclamation;
    }
    for (int i = 0; i < M; i++) {
        fgets(line, MAX_LINE_LENGTH, fin);
        int num = 0;
        int exclamation = 0;
        for (int j = 0; j < strlen(line); j++) {
            if (isvowel[(int)line[j]]) {
                num++;
            }
            if (line[j] == '!') {
                exclamation = 1;
            }
        }
        arrM_num[i] = num;
        arrM_exclamation[i] = exclamation;
    }
    int **dp = (int **)malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++) {
        dp[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (arrN_num[j] == arrM_num[i] && arrN_exclamation[j] == arrM_exclamation[i]) {
                dp[i][j] = arrN_num[j];
            } else {
                dp[i][j] = 0;
            }
            if (i > 0 && j > 0) {
                dp[i][j] += dp[i - 1][j - 1];
                int max_val = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
                dp[i][j] = dp[i][j] > max_val ? dp[i][j] : max_val;
            } else {
                if (i > 0 && dp[i][j] <= dp[i - 1][j]) {
                    dp[i][j] = dp[i - 1][j];
                }
                if (j > 0 && dp[i][j] <= dp[i][j - 1]) {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }
    fprintf(fout, "%d\n", dp[M - 1][N - 1]);
    for (int i = 0; i < M; i++) {
        free(dp[i]);
    }
    free(dp);
    free(arrN_num);
    free(arrN_exclamation);
    free(arrM_num);
    free(arrM_exclamation);
    fclose(fin);
    fclose(fout);
    return 0;
}


