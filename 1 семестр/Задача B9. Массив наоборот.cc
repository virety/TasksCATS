// Условие
// Во входном файле дан массив целых чисел 
// a1,a2,...,aN. Требуется вывести этот массив в обратном порядке.
// Формат входного файла
// Входной файл содержит целое число N, за которым следуют N целых чисел ai.
// Формат выходного файла
// Выходной файл должен содержать N чисел — массив ai, записанный в обратном порядке.
// Ограничения
// 1≤N≤100000
// −10^9≤ai≤10^9
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	4                           4 3 2 1
//     1 2 3 4
// 2	6                           5 3 -2 3 1 9
//     9 1 3 -2 3 5
#include <stdio.h> 
	char * filename1 = "input.txt";
	char * filename2 = "output.txt";
	FILE * fout = fopen(filename2, "wt");
	FILE * fin = fopen(filename1, "rt");
void rvereseArray(int arr[], int start, int end) 
{ 
	int temp; 
	while (start < end) { 
		temp = arr[start]; 
		arr[start] = arr[end]; 
		arr[end] = temp; 
		start++; 
		end--; 
	} 
} 
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		fprintf(fout, "%d ", arr[i]);

	printf("\n"); 
	fprintf(fout, "\n");
} 
int main() {
	int n;
	fscanf(fin,"%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++){
		fscanf(fin,"%d", &arr[i]);
	}
	rvereseArray(arr, 0, n - 1); 
	printArray( arr, n); 
	return 0;
}
