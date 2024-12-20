// Условие
// Центральным элементом набора из k чисел называется такой элемент, который после сортировки набора будет занимать в нём центральную позицию (то есть позицию номер ⌈k/2⌉, считая с единицы).
// Числа добавляются в изначально пустой набор в заданном порядке. Требуется определить значения центрального элемента после добавления каждого числа.
// Формат входного файла
// Входной файла содержит количество чисел n, за которым следуют n целых чисел ai в порядке их добавления в набор.
// Формат выходного файла
// Выходной файл должен содержать n целых чисел — значения центрального элемента после каждого добавления.
// Ограничения
// 1≤n≤10^6, −10^9≤ai≤10^9.
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	3                         5 3 4
//   5 3 4
// 2	5                         1 1 2 2 2
//   1 2 3 2 4

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Data;

typedef struct Heap {
  Data *array;
  int size;
  int capacity;
  bool (*cmp)(const Data *arg1, const Data *arg2);
} Heap;

void siftUp(Heap *, int);
void siftDown(Heap *, int);
void resize(Heap *);
void insert(Heap *, const Data *);
void initEmptyHeap(Heap *heap, bool (const Data *, const Data *));
Data pop_heap(Heap *heap);
bool heap_empty(Heap *heap);
void print_heap(Heap *heap);

bool Compare_max(const Data *x, const Data *y) {
  return (Data) x > (Data) y;
}

bool Compare_min(const Data *x, const Data *y) {
  return (Data) x < (Data) y;
}

int main() {
  FILE *fin = fopen("input.txt", "rt");
  FILE *fout = fopen("output.txt", "wt");
  int n;
  fscanf(fin, "%d", &n);
  Heap maxHeap;
  Heap minHeap;
  initEmptyHeap(&maxHeap, Compare_max);
  initEmptyHeap(&minHeap, Compare_min);
  Data value;
  for (int i = 0; i < n; i++){
      fscanf(fin, "%d", &value);
      insert(&maxHeap, &value);
      if (maxHeap.size > minHeap.size) {
          Data top_element = pop_heap(&maxHeap);
          insert(&minHeap, &top_element);
      }
      if (minHeap.size > maxHeap.size) {
          Data top_element = pop_heap(&minHeap);
          insert(&maxHeap, &top_element);
      }
      fprintf(fout, "%d ", maxHeap.array[0]);
  }

  fclose(fin);
  fclose(fout);

  return 0;
}

void siftUp(Heap *heap, int index) {
  int x = heap->array[index];
  int y = heap->array[(index - 1) / 2];
  bool test = heap->cmp((const Data *) heap->array[index], (const Data *) heap->array[(index - 1) / 2]);
  while (heap->cmp((const Data *) heap->array[index], (const Data *) heap->array[(index - 1) / 2])) {
    Data temp = heap->array[index];
    heap->array[index] = heap->array[(index - 1) / 2];
    heap->array[(index - 1) / 2] = temp;
    index = (index - 1) / 2;
  }
}

void siftDown(Heap *heap, int index) {
  while (2 * index + 1 < 1 + heap->size) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int j = left;
    if (right < heap->size && heap->cmp((const Data *) heap->array[right], (const Data *) heap->array[left])) {
      j = right;
    }
    if (heap->cmp((const Data *) heap->array[index], (const Data *) heap->array[j])) {
      break;
    }
    Data temp = heap->array[index];
    heap->array[index] = heap->array[j];
    heap->array[j] = temp;
    index = j;
  }
}

void insert(Heap *heap, Data const *value) {
  if (heap->size >= heap->capacity) {
    resize(heap);
  }
  heap->array[heap->size++] = *value;
  siftUp(heap, heap->size - 1);
}

void resize(Heap *heap) {
  heap->array = (Data *) realloc(heap->array, sizeof(Data) * (heap->capacity + 1) * 2);
  heap->capacity = (heap->capacity + 1) * 2;
}

void initEmptyHeap(Heap *heap, bool (*cmp)(const Data *, const Data *)) {
  heap->array = (Data *)malloc(sizeof(Data) * 5);
  heap->size = 0;
  heap->capacity = 5;
  heap->cmp = cmp;
}

Data pop_heap(Heap *heap) {
  if (heap->size > 0) {
    Data top_element = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    siftDown(heap, 0);
    return top_element;
  }
}

bool heap_empty(Heap *heap) {
  return heap->size == 0;
}

void print_heap(Heap* heap){
  for (int i = 0; i < heap->size; i++) {
    printf("%d ", heap->array[i]);
    fflush(stdout);
  }
  printf("\n");
  fflush(stdout);
}