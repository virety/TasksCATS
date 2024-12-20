// Заявление
// Конкурсы ACM, подобные тому, в котором вы участвуете, проводятся с помощью специального программного обеспечения. Это программное обеспечение, помимо прочих функций, выполняет предварительную работу по принятию и оценке решений команд (запусков) и отображению результатов в таблице рангов. Правила подсчета очков следующие:
// Каждый запуск либо принимается, либо отклоняется.
// Задача считается решенной командой, если один из представленных на нее заездов принят.
// Время, затраченное на решение задачи, - это время, прошедшее с начала конкурса до подачи первого принятого решения по этой задаче (в минутах) плюс 20 минут на каждое второе выполнение этой задачи до принятого решения. Для нерешенной задачи затраченное время не вычисляется.
// Общее время - это сумма времени, затраченного на решение каждой задачи.
// Команды ранжируются по количеству решенных задач. Команды, решившие одинаковое количество задач, ранжируются по наименьшему общему времени.
// Хотя время указано в минутах, фактическое время измеряется с точностью до 1 секунды, и секунды учитываются при ранжировании команд.
// Команды с равным рангом в соответствии с вышеуказанными правилами должны быть отсортированы по возрастанию количества команд.
// Ваша задача состоит в том, чтобы, учитывая список из N заездов со временем подачи заявок и результатом каждого заезда, вычислить таблицу рангов для C команд.
// Формат входного файла
// Входные данные содержат целые числа C N, за которыми следуют N квартетов целых чисел ci pi ti ri, где ci — номер команды, pi — номер задачи, ti — время подачи в секундах, ri — 1, в противном случае 0.
// Формат выходного файла
// Выходной файл должен содержать C целых чисел — номера команд, отсортированные по рангу.
// Ограничения
// 1 &le; C, N &le; 1000, 1 &le; ci &le; C, 1 &le; pi &le; 20, 1 &le; ti &le; 36000.
// Примеры тестов
// Нет.	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	2 3                             1 2
//     1 1 5000 0
//     1 1 500 1
//     2 1 10000 1
// 2	3 3                             2 1 3
//     1 2 3000 0
//     1 2 3100 1
//     2 1 4200 1

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int team, problem, time;
} Reject;

typedef struct {
    int number, solved, total_time;
    int problems[20];
} Team;

int compare(const void* a, const void* b) {
    Team* team_a = *(Team**) a;
    Team* team_b = *(Team**) b;
    
    if (team_a -> solved != team_b -> solved) {
        return team_b -> solved - team_a -> solved;
    }
    
    if (team_a -> total_time != team_b -> total_time) {
        return team_a -> total_time - team_b -> total_time;
    }
    
    return team_a -> number - team_b -> number;
}

int main() {
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w");

    int c, n;
    fscanf(input, "%d %d", &c, &n);
    Team* teams[c];
    
    for (int i = 0; i < c; i++) {
        teams[i] = calloc(1, sizeof(Team));
        teams[i] -> number = i + 1;
    }

    Reject rejects[n];
    int r = 0, team, problem, time, status;
    for (int i = 0; i < n; i++) {
        fscanf(input, "%d %d %d %d", &team, &problem, &time, &status);
        int* problem_ptr = &(teams[team - 1] -> problems[problem - 1]);
        if (status && (*problem_ptr > time || !(*problem_ptr))) {
            if (!(*problem_ptr)) teams[team - 1] -> solved++;
            teams[team - 1] -> total_time += -(*problem_ptr) + time;
            *problem_ptr = time;
        } else if (!status) {
            rejects[r].team = team;
            rejects[r].problem = problem;
            rejects[r++].time = time;
        }
    }

    for (int i = 0; i < r; i++) {
        team = rejects[i].team;
        problem = rejects[i].problem;
        time = rejects[i].time;

        if (teams[team - 1] -> problems[problem - 1] > time) {
            teams[team - 1] -> total_time += 20 * 60;
        }
    }
    
    qsort(teams, c, sizeof(Team*), compare);
   
    for (int i = 0; i < c; i++) {
        fprintf(output, "%d ", teams[i] -> number);
        free(teams[i]);
    }

    fclose(input);
    fclose(output);
    
    return 0;
}