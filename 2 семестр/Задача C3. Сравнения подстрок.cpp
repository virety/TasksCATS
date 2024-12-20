// Условие
// Дана строка. Нужно уметь отвечать на запросы вида: равны ли подстроки [a…b] и [c…d].
// Формат входных данных
// Сперва строка S из строчных латинских букв. Далее число M — количество запросов.
// В следующих M строках по четыре целых числа — запросы a, b, c, d.
// Формат выходных данных
// Выведите M строк, по одному ответу для каждого запроса. Ответ должен быть Yes, если подстроки совпадают, и No в противном случае.
// Ограничения
// 0≤M≤10^5, 1≤a≤b≤|S|, 1≤c≤d≤|S|, 1≤|S|≤10^5.
// Примеры тестов
// №	Стандартный вход	Стандартный выход
// 1	trololo             Yes
//      3                   Yes
//      1 7 1 7             No
//      3 5 5 7
//      1 1 1 5
#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 1000000;
size_t m;
string s;
const long long PRIME = 1000000009;
long long primePows[MAX + 1];
long long hashes[MAX + 1];
long long getHash(int l, int r) {
    return hashes[r + 1] - hashes[l] * primePows[r - l + 1];
}
bool checkTwoSubs(int a, int b, int c, int d) {
    return getHash(a, b) == getHash(c, d);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    cin >> m;
    memset(hashes, 0, sizeof(hashes));
    memset(primePows, 0, sizeof(primePows));
    hashes[0] = 0;
    primePows[0] = 1;
    for (int i = 0; i < s.length(); ++i) {
        hashes[i + 1] = hashes[i] * PRIME + s[i];
        primePows[i + 1] = primePows[i] * PRIME;
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        cout << (checkTwoSubs(a, b, c, d) ? "Yes\n" : "No\n");
    }
    return 0;
}