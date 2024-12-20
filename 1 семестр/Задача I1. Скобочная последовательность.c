// Условие
// Скобочная последовательность - это последовательность символов скобок (любых видов). Скобочная последовательность называется правильной, если каждой открывающей скобке найдется соответствующая закрывающая того же типа и наоборот. При этом скобочные подпоследовательности правильной скобочной последовательности могут быть вложенны друг в друга, но не могут пересекаться. Будем называть глубиной скобочной последовательности в позиции i количество открывающих скобок левее позиции i+1, которым еще не нашлись соответствующие закрывающие скобки.
// Для заданной скобочной последовательности выведите ее максимальную глубину. В случае, если она не является правильной, выведите −1.
// Формат входных данных
// На вход подается одна строка - набор символов '(', ')', '[', ']', '{', '}'
// Формат выходных данных
// Выходные данные должны содержать одно целое число  — максимальную глубину скобочной последовательности или −1, если она не является правильной.
// Ограничения
// Длина строки не превышает 10^5
// Примеры тестов
// №	Стандартный вход	Стандартный выход
// 1	(())                2
// 2	([]{})              2
// 3	{[}]                -1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100000
typedef struct {
    char* array;
    int top;
} Stack;
void initStack(Stack* stack) {
    stack->array = malloc(MAX_STACK_SIZE * sizeof(char));
    stack->top = -1;
}
void push(Stack* stack, char c) {
    stack->top++;
    stack->array[stack->top] = c;
}
char pop(Stack* stack) {
    char c = stack->array[stack->top];
    stack->top--;
    return c;
}
int isEmpty(Stack* stack) {
    return stack->top == -1;
}
int maxDepth(char* sequence) {
    Stack stack;
    initStack(&stack);
    int length = strlen(sequence);
    int maxDepth = 0;
    int currentDepth = 0;
    for (int i = 0; i < length; i++) {
        if (sequence[i] == '(' || sequence[i] == '[' || sequence[i] == '{') {
            push(&stack, sequence[i]);
            currentDepth++;
            if (currentDepth > maxDepth) {
                maxDepth = currentDepth;
            }
        } else if (sequence[i] == ')' || sequence[i] == ']' || sequence[i] == '}') {
            if (isEmpty(&stack)) {
                return -1;
            }
            char opening = pop(&stack);
            if ((sequence[i] == ')' && opening != '(') ||
                (sequence[i] == ']' && opening != '[') ||
                (sequence[i] == '}' && opening != '{')) {
                return -1;
            }
            currentDepth--;
        }
    }
    if (!isEmpty(&stack)) {
        return -1;
    }
    return maxDepth;
}
int main() {
    char sequence[100000];
    scanf("%s", sequence);
    int depth = maxDepth(sequence);
    printf("%d\n", depth);
    return 0;
}
