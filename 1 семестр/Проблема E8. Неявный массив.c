// Оператор
// Отсортированный массив целых чисел представлен неявно. Вместо каждого элемента известен набор этого элемента и его соседей справа и слева. Первый и последний элементы массива имеют не более одного соседа. Обратите внимание, что набор не отражает ни порядок элементов, ни повторяющиеся значения.
// Ваша программа должна выводить явное представление массива (все элементы по порядку).
// Формат входного файла
// Первая строка входного файла содержит целое число N — количество элементов в массиве.
// Следующие N строки содержат неявное представление элементов массива: заданный размер si и ся разные целые числа aij — набор i-й элемент массива и его соседи.
// Формат выходного файла
// Выходной файл должен содержать N целые числа — элементы исходного отсортированного массива.
// Ограничения
// 1≤N≤10^5
// −10^9≤aij≤10^9
// Примеры тестов
// Нет.	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	   7                        1 1 1 2 2 3 3
//         1 1
//         1 1
//         2 1 2
//         2 1 2
//         2 2 3
//         2 2 3
//         1 3
// 2	   1                        7
//         1 7
#include <stdio.h>
#include <stdlib.h>

int cmp( const void *a, const void *b){
	return *((long long*)a) > *((long long*)b)? 1:-1;}
struct Set{
	long long *array;
	int size;};
int add(struct Set *set, long long key){
	for(int i = 0; i < set->size; i++){
		if(key==set->array[i]){
			return 0;
		}
	}
	set->array[(set->size)++] = key;
	return 1;
}
long long sort(struct Set *set){
	qsort(set->array,set->size,sizeof(long long),cmp);
}
int contains(struct Set *set, int key){
	for(long long *index = set->array; index < set->array+set->size; index++){
		if(*index == key){
			return 1;
		}
	}
	return 0;
}

int main() {
	FILE *fIn, *fOut;
	fIn = fopen("input.txt","r");
	fOut = fopen("output.txt","w");
	int N;
	fscanf(fIn,"%d\n",&N);
	struct Set *sequence = calloc(N,sizeof(struct Set));
	for(int i = 0; i < N; i++){
		sequence[i].array  = (long long *)calloc(3,sizeof(long long));
		int cnt = 0;
		long long next;
		fscanf(fIn,"%d",&cnt);
		for(int j = 0; j < cnt; j++){
			fscanf(fIn,"%lld",&next);
			add(&sequence[i], next);
		}
		sort(&sequence[i]);
	}
	long long *answer = calloc(N,sizeof(long long));
	answer[0] = sequence[0].array[0];
	answer[N-1] = sequence[N-1].array[sequence[N-1].size-1];
	for(int i = N-2; i >= 1; i--){
		if(sequence[i].size == 3){
			answer[i+1] = sequence[i].array[2];
			answer[i] = sequence[i].array[1];
			answer[i-1] = sequence[i].array[0];
			continue;
		}
		if(sequence[i].size == 1){
			answer[i-1] = sequence[i].array[0];
			answer[i] = sequence[i].array[0];
			answer[i+1] = sequence[i].array[0];
			continue;
		}
		if(contains(&sequence[i-1],sequence[i].array[1])){
			answer[i] = sequence[i].array[1];
			answer[i-1] = sequence[i].array[0];
		}
		else{
			answer[i+1] = sequence[i].array[1];
			answer[i] = sequence[i].array[0];
		}
	}
	
	for(long long *index = answer; index < answer+N;index++){
		fprintf(fOut,"%lld ", *index);
	}
}