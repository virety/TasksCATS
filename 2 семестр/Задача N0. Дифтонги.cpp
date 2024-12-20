// Условие
// Слова марсианского языка состоят из малых латинских букв. Буквы a, e, i, o, u, y считаются гласными, остальные — согласными.
// Дифтонгом называется пара подряд идущих гласных букв, окружённых либо согласными буквами, либо границами слова. Например, в слове preemptio имеется два дифтонга, а в слове aaa — ни одного.
// Требуется среди N данных слов найти те, в которых количество дифтонгов максимально.
// Формат входного файла
// Первая строка входного файла содержит целое число N. Следующие N строк содержат по одному слову каждая.
// Формат выходного файла
// Выходной файл должен содержать слова из входного файла, содержащие максимальное количество дифтонгов, по одному слову в строке. Слова должны располагаться в том же порядке, что и во входном файле.
// Ограничения
// 1≤N≤100
// Слова содержат от 1 до 255 символов.
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	3                           ee
//     e
//     ee
//     eee
// 2	3                          aabbee
//     aabbee                     xiixiixiii
//     cyydyyy  
//     xiixiixiii

#include <iostream>

using namespace std;

bool is_vowel(char el) {
    return el == 'a' || el == 'e' || el == 'i' || el == 'o' || el == 'u' || el == 'y';
}
int count_of_diftongs(string s) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i == 0) {
            if (is_vowel(s[i]) && i + 1 < s.length() && is_vowel(s[i + 1]) && i + 2 < s.length() && !is_vowel(s[i + 2]) )
                count++;
            else if (is_vowel(s[i]) && i + 1 < s.length() && is_vowel(s[i + 1]) && i + 2 == s.length())
                count++;
        }
        else {
            if (!is_vowel(s[i - 1]) && is_vowel(s[i]) && i + 1 < s.length() && is_vowel(s[i + 1]) && i + 2 < s.length() && !is_vowel(s[i + 2]) )
                count++;
            else if (!is_vowel(s[i - 1]) && is_vowel(s[i]) && i + 1 < s.length() && is_vowel(s[i + 1]) && i + 2 == s.length())
                count++;
        }
        }
        return count;
    }
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    string strings[n];
    cin >> s;
    strings[0] = s;
    int max_diftong = count_of_diftongs(s);
    for (int i = 1; i < n; i++) {
        s = "";
        cin >> s;
        strings[i] = s;
        max_diftong = max(max_diftong, count_of_diftongs(s));
    }
    for (int i = 0; i < n; i++) {
        if (max_diftong == count_of_diftongs(strings[i])) {
            cout << strings[i] << endl;
        }
    }
}