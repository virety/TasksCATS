// Условие
// В чемпионате по боксу соревнуется две команды по N боксёров в каждой. Все боксёры разбиты на M весовых категорий. Каждый боксёр характеризуется уровнем мастерства pi (при этом не существует двух боксёров с равным уровнем мастерства) и номером весовой категории в которой он выступает ci. Чемпиона проходит по следующим правилам: все участники разбиваются по весовым категориям и в рамках одной весовой категории каждый боксёр одной команды выходит на ринг против каждого боксёра другой команды, за победу в бое начисляется одно очко. Боксёр точно победит если его уровень мастерства выше уровня мастерства соперника.
// Слон Пахом тренер одной из команд, и он нашёл способ схитрить, а именно переместить одного боксёра в другую весовую категорию. Теперь он хочет максимизировать разность между количеством побед боксёров своей команды и боксёров команды противника.
// Формат входного файла
// Первая строка входного файла содержит два целых числа N, M. Далее N пар чисел pi, сi  — описание боксёров из команды Пахома. Далее N пар чисел pi, сi  — описание команды соперников.
// Формат выходного файла
// Выходной файл должен содержать одно число  — максимальная разница очков которую может получить команда Пахома.
// Ограничения
// 1≤N≤10^6,1≤M≤300,1≤сi≤M;1≤pi≤10^9.Описание подзадач и системы оценивания
// Баллы за каждую подзадачу начисляются только в случае, если все тесты этой подзадачи успешно пройдены.
// Подзадача	Баллы	Дополнительные ограничения
//                     N              M
// 1	        20	    1≤N≤20         1≤M≤2
// 2	        20	    1≤N≤1000       1≤M≤2
// 3	        20	    1≤N≤10^6       1≤M≤2
// 4	        20	    1≤N≤10^6       1≤M≤50
// 5	        20	    1≤N≤10^6       1≤M≤300
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	3 1                         -9
//     1 1
//     2 1 
//     3 1
//     4 1
//     5 1
//     6 1
// 2	4 2                         12
//     60 1
//     100 2
//     110 2
//     120 2
//     200 1
//     50 2
//     40 2
//     30 2
// 3	3 3                         -1
//     5 1
//     10 2
//     15 3
//     6 1
//     11 2
//     16 3

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id, size, capacity;
    int* data;
} Group;
typedef struct {
    int skill, group_id, impact;
} Fighter;
int ints_comparator(const void* a, const void* b) {
    return *((int*)a) - *((int*)b);
}
int Fighters_comparator(const void* a, const void* b) {
    return ((Fighter*)a)->skill - ((Fighter*)b)->skill;
}
void ensure_capacity(Group* group) {
    if (group->size == group->capacity) {
        group->capacity += 10;
        group->data = realloc(group->data, (group->capacity) * sizeof(int));
    }
}
int get_position(int* data, int size, int value) {
    int left = 0, right = size - 1;
    int position = 0;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (data[middle] < value) {
            position = middle + 1;
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return position;
}
int main(int argc, char const *argv[]) {
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w");
    int n, l;
    fscanf(input, "%d %d", &n, &l);
    Fighter* Fighters = malloc(n * sizeof(Fighter)); 
    Group* groups = malloc(l * sizeof(Group)); 
    for (int i = 0; i < l; i++) {
        Group* group = groups + i;
        group->id = i + 1;
        group->size = 0;
        group->capacity = 10;
        group->data = malloc(10 * sizeof(int));
    }
    int skill, group_id;
    for (int i = 0; i < n; i++) {
        fscanf(input, "%d %d", &skill, &group_id);
        Fighters[i].skill = skill;
        Fighters[i].group_id = group_id;
    }
    for (int i = 0; i < n; i++) {
        fscanf(input, "%d %d", &skill, &group_id);
        Group* group = groups + group_id - 1;
        ensure_capacity(group);
        group->data[group->size++] = skill;
    }
    qsort(Fighters, n, sizeof(Fighter), Fighters_comparator);
    for (int i = 0; i < l; i++) {
        Group* group = groups + i;
        qsort(group->data, group->size, sizeof(int), ints_comparator);
    }
    int general_score = 0;
    for (int i = 0; i < n; i++) {
        Fighter* fighter = Fighters + i;
        Group* group = groups + fighter->group_id - 1;
        int position = get_position(group->data, group->size, fighter->skill);
        general_score += (fighter->impact = position - (group->size - position)); 
    }
    int max_group_impact = 0;
    for (int i = 0; i < l; i++) {
        Group* group = groups + i;
        int* data = group->data;
        int p = group->size;
        for (int j = n - 1; j >= 0; j--) {
            Fighter* fighter = Fighters + j;
            if (fighter->group_id == group->id) continue;
            while (p - 1 >= 0 && data[p - 1] > fighter->skill) p--;
            int new_impact = p - (group->size - p);
            if ((new_impact - fighter->impact) > max_group_impact) {
                max_group_impact = new_impact - fighter->impact;
            }
        }
    }
    fprintf(output, "%d", general_score + max_group_impact);
    free(Fighters);
    for (int i = 0; i < l; i++) free(groups[i].data);
    free(groups);
    fclose(input);
    fclose(output);
    
    return 0;
}