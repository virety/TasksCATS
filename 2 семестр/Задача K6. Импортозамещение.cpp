// Условие
// Страна Битландия производит множество товаров. Соседняя страна Байтландия постоянно закупалась у Битландии.
// Недавно в Байтландии произошла эпидемия, из-за которой нарушились каналы для поставки товаров. На восстановление уйдет много времени и денег.
// Из-за этого Байтландия запустила тендер на закупку импортозамещающих товаров. Было определено k различных категорий товаров, которые пользуются спросом в стране. Каждая категория имеет свой код от 1 до k включительно. Свои товары предложили n различных компаний. Они заявили, какой тип товара предоставят, в каком количестве они его поставят и суммарную цену за всю поставку. По условиям тендера каждый товар может быть закуплен только у одной компании.
// Согласно плану необходимо закупить товаров в количестве не менее s штук. При этом распределение товаров по категориям не имеет значения, важно только общее количество. По имеющимся предложениям компаний требуется определить, какую минимальную сумму надо потратить на выполнения плана по закупке.
// Формат входных данных
// В первой строке заданы три натуральных числа n, k и s — количество заявок, количество категорий товаров и минимально необходимое общее количество товаров соответственно.
// В следующих 
// n строках записано по три натуральных числа ti, ai и ci — код товара, количество товара и суммарную стоимость соответственно.
// Формат выходных данных
// Выведите одно целое число — минимальную сумма, которую надо потратить на закупку. Если не закупку совершить невозможно, выведите -1.
// Ограничения
// 1≤n≤10^4
// 1≤ti≤k≤100
// 1≤ai≤s≤1000
// 1≤c≤100
// Пояснение к примеру
// В первом примере мы можем закупить товары у второй, четвертой и пятой компании. Суммарно мы наберем 8 товаров и заплатим 8 единиц денег.
// Примеры тестов
// №	Стандартный вход	Стандартный выход
// 1	7 5 8               8
//     3 2 9
//     4 2 4
//     4 4 7
//     3 2 2
//     2 4 2
//     1 4 10
//     4 3 7
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    int n, k, s;
    inputFile >> n >> k >> s;
    vector<vector<pair<int, int>>> offers(k + 1); 
    for (int i = 0; i < n; ++i) {
        int category, amount, cost;
        inputFile >> category >> amount >> cost;
        offers[category].push_back({cost, amount});
    }
    for (int i = 1; i <= k; ++i) {
        sort(offers[i].begin(), offers[i].end());
    }
    const int INF = 1e9; 
    vector<int> dp(s + 1, INF); 
    dp[0] = 0;
    for (int i = 1; i <= k; ++i) {
        for (int j = s; j >= 0; --j) {
            for (const auto& proposal : offers[i]) {
                int cost = proposal.first;
                int quantity = proposal.second;
                if (j >= quantity && dp[j - quantity] != INF) {
                    dp[j] = min(dp[j], dp[j - quantity] + cost);
                } 
                else if (j < quantity && dp[0] != INF) {
                    dp[j] = min(dp[j], dp[0] + cost);
                }
            }
        }
    }
    int result = dp[s];
    if (result == INF) {
        outputFile << -1 << endl;
    } 
    else {
        outputFile << result << endl;
    }
    return 0;
}