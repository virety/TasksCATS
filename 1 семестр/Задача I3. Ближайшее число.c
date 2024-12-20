// Условие
// Дана последовательность из N целых чисел. Для каждого числа вывести ближайшее к нему справа в этой последовательности, которое будет больше него. Для чисел, которым найти ближайшее большее не удалось, вывести сами эти числа.
// Формат входного файла
// Входной файл содержит целое число N за которым следует N целых чисел ai - исходная последовательность.
// Формат выходного файла
// В выходной файл необходимо вывести N целых чисел bi, таких что bi является ответом на задачу для числа ai.
// Ограничения
// 1≤N≤10^6
// |ai|≤10^9
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	4 1 2 3 4                   2 3 4 4
// 2	1                           1
//      1
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int index;
} Pair;
typedef struct Node {
    Pair data;
    struct Node* next;
} Node;
Node* createNode(Pair data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int isEmpty(Node* top) {
    return top == NULL;
}
void push(Node** top, Pair data) {
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}
Pair pop(Node** top) {
    Node* temp = *top;
    *top = (*top)->next;
    Pair popped = temp->data;
    free(temp);
    return popped;
}
Pair peek(Node** top) {
    return (*top)->data;
}
void findNearestGreater(int n, int* sequence, int* result) {
    Node* stack = NULL; 
    int i;
    for (i = 0; i < n; i++) {
        Pair currentPair;
        currentPair.num = sequence[i];
        currentPair.index = i;
        if (isEmpty(stack)) {
            push(&stack, currentPair);
        } else {
            while (!isEmpty(stack) && currentPair.num > peek(&stack).num) {
                Pair poppedPair = pop(&stack);
                result[poppedPair.index] = currentPair.num;
            }
            push(&stack, currentPair);
        }
    }
    while (!isEmpty(stack)) {
        Pair poppedPair = pop(&stack);
        result[poppedPair.index] = poppedPair.num;  
    }
}
int main() {
    FILE *fp = fopen("input.txt","r");
    FILE *fout = fopen("output.txt","wt");
    int n;
    fscanf(fp,"%d", &n);
    int* sequence = (int*)malloc(n * sizeof(int));
    int* result = (int*)malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++) {
        fscanf(fp,"%d", &sequence[i]);
    }
    findNearestGreater(n, sequence, result);
    for (i = 0; i < n; i++) {
        fprintf(fout,"%d ", result[i]);
    }
    fprintf(fout,"\n");
    free(sequence);
    free(result);
    return 0;
}