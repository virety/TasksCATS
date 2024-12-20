// Условие
// Инженер Антон зашёл в магазин радиодеталей. В магазине ровно N стеллажей. На i-м стеллаже лежат радиодетали типа ai (на двух различных стеллажах тип радиодеталей может повторяться). Антон обходит с тележкой стеллажи в порядке от первого до N-го.
// Когда Антон подходит к очередному стеллажу, он смотрит в тележку. Если в тележке нет радиодеталей такого типа, как на стеллаже, Антон берёт деталь со стеллажа и складывает в тележку. Если радиодеталь такого типа в тележке уже лежит, Антон просто идет дальше.
// К сожалению, вместимость тележки ограничена K деталями. Поэтому, если тележка заполнена, а Антону необходимо выбрать, какую из имеющихся в тележке радиодеталей нужно убрать, прежде чем складывать новую деталь.
// Антон знает заранее, какие типы радиодеталей лежат на стеллажах, и хочет каждый раз выбрасывать из тележки такую деталь, чтобы как можно меньше раз складывать новые радиодетали в тележку (складывает он их только в случае, если таких деталей в тележке нет на данный момент).
// Помогите Антону узнать, какое минимальное количество раз ему придётся складывать новую деталь в тележку.
// Примечание
// Рекомендуется рассмотреть частичные решения для N≤1000, ai≤10^5.
// Формат входного файла
// Входной файл содержит целое число два целых числа N и K, вторая строка содержит N чисел ai.
// Формат выходного файла
// Выходной файл должен содержать единственное число — минимальное количество раз, которое придётся положить деталь в тележку.
// Ограничения
// 1≤N,K≤10^5
// 0≤ai≤10^9
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	3 3                         3
//     1 2 3
// 2	5 2                         2
//     1 1 1 2 2
// 3	7 3                         4
//     8 2 3 1 1 2 2
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
#define ull unsigned long long
#define ll long long


using namespace std;
const int MAX_N = 1e5 + 1;
vector<ull> A(MAX_N);
vector<ull> Next_Right(MAX_N);
bool compare(const map<ll, ll>::iterator &a, const map<ll, ll>::iterator &b) {
    return a->second < b->second;
}
int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    ll N, K;
    fin >> N >> K;
    for (int i = 0; i < N; i++)
    fin >> A[i];
    ll n = N;
    Next_Right[n - 1] = n++;
    map<ll, ll> Init_map;
    for (int i = N - 1; i >= 0; i--) {
        if (Init_map.find(A[i]) == Init_map.end()) {
        Next_Right[i] = n++;
        Init_map[A[i]] = i;
        } 
        else {
            Next_Right[i] = Init_map[A[i]];
            Init_map[A[i]] = i;
        }
    }
    
    map<ll, ll> values;
    values.emplace(A[0], Next_Right[0]);
    vector<map<ll, ll>::iterator> basket;
    int addCounter = 1;
    basket.push_back(values.find(A[0]));
    for (int i = 1; i < N; i++) {
        auto x = values.find(A[i]);
        values[A[i]] = Next_Right[i];
        if (basket.size() < K && x == values.end()) { 
            basket.push_back(values.find(A[i]));
            push_heap(basket.begin(), basket.end(), compare);
            addCounter++;
        }
        else if (x == values.end()) {
            pop_heap(basket.begin(), basket.end(), compare);
            values.erase(basket.back()->first);
            basket.pop_back();
            basket.push_back(values.find(A[i]));
            push_heap(basket.begin(), basket.end(), compare);
            addCounter++;
        }
        else{
            push_heap(basket.begin(), basket.end(), compare);
        }
    }
    
    fout << addCounter;
    return 0;
}
