// Statement
// You are to write a program that receives a sequence of words and sorts it in lexicographical order. Linear order on characters is given by ASCII codes.
// Input file format
// First line of input file contains integer N — the sequence length. Following N lines contain one word per line. Each word is exactly three letters long.
// Output file format
// Output file must consist of N lines, each containing one word from sorted sequence.
// Constraints
// 0 &le; N &le; 1000000.
// Sample tests
// No.	Input file (input.txt)	Output file (output.txt)
// 1	4                       ACM
//     KVN                     FSB
//     ACM                     GGG
//     FSB                     KVN
//     GGG
#include <stdio.h>
#include <stdlib.h>

#define B 58

typedef struct {
    int size, capacity;
    char** data;
} Bucket;

void ensure_capacity(Bucket* bucket) {
    if (bucket->size == bucket->capacity) {
        bucket->capacity += 10;
        bucket->data = realloc(bucket->data, bucket->capacity * sizeof(char*));
    }
}

int main(int argc, char const *argv[]) {
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w");
    
    int n;
    fscanf(input, "%d", &n);
    char data[n][3];
    for (int i = 0; i < n; i++) fscanf(input, "%3s", data[i]);

    char** array = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) array[i] = &data[i][0];
    Bucket* buckets = malloc(B * sizeof(Bucket));
    for (int i = 0; i < B; i++) {
        buckets[i].size = 0;
        buckets[i].capacity = 10;
        buckets[i].data = malloc(10 * sizeof(char*));
    }
    
    for (int i = 2; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            char* word = array[j];
            Bucket* bucket = buckets + (word[i] - 65);
            ensure_capacity(bucket);
            bucket->data[bucket->size++] = word;
        }
        
        int p = 0;
        for (int j = 0; j < B; j++) {
            Bucket* bucket = buckets + j;
            for (int l = 0; l < bucket->size; l++) {
                array[p++] = bucket->data[l];
            }
            bucket->size = 0;
        }
    }
    for (int i = 0; i < n; i++) fprintf(output, "%.3s\n", array[i]);

    free(array);
    for (int i = 0; i < B; i++) free(buckets[i].data);
    free(buckets);

    fclose(input);
    fclose(output);
    
    return 0;
}
