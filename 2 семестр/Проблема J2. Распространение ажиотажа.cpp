// Заявление
// Одна известная автомобильная гонка проходит на стадионе с гоночной трассой. Зрители, наблюдающие за гонкой, сидят на трибуне, состоящей из H строки с W каждому по месту. Во время гонки одни места заняты зрителями, а другие пустуют.
// Маркетинговые исследования показали, что если один зритель громко выкрикнет красиво зарифмованный слоган, зрители на местах, расположенных непосредственно слева, справа, над и под ним, повторят его. Их соседи, в свою очередь, подтянутся, и слоган распространится по всему стенду.
// Рекламная компания изобрела новый слоган и хочет, чтобы он распространился среди как можно большего числа зрителей. Для имитации "спонтанного" появления слогана компания наняла агента, который пересядет на одно из незанятых мест и оттуда прокричит слоган.
// Ваша программа должна определить позицию агента, которая приведет к максимальному проникновению слогана.
// Формат входного файла
// Входной файл содержит целые числа WH в первой строке, за которой следует H линии W каждый персонаж.
// Каждый символ является либо '.' (ASCII 46), либо '#' (ASCII 35), обозначая свободное и занятое место соответственно.
// Есть по крайней мере одно свободное место.
// Формат выходного файла
// Выходной файл должен содержать два целых числа — xy обозначает номер места и ряда, который должен занять агент. Ряды нумеруются, начиная с 1 сверху вниз. Места нумеруются, начиная с 1, слева направо. Если есть несколько оптимальных решений, выведите любое из них.
// Ограничения
// 2 Ш,Ч 2000
// Примеры тестов
// Нет.	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	    2 2                         2 1
//         #.
//         .#
// 2	    5 5                         2 4
//         ..#.#
//         ..###
//         #..##
//         #.##.
//         #....
// 3	    6 4                         3 2
//         ######
//         .....#
//         ..##.#
//         ...#.#

#include <fstream>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;
struct sit {
    short y, x;
};
sit dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void bfs(int** sits, int H, int W, int y, int x, int hash) {
    queue<sit> going_to;
    going_to.push({y, x});
    sit* was_before = new sit[H * W];
    int was_before_count = 0;
    while (!going_to.empty()) {
        sit current = going_to.front();
        going_to.pop();
        if (current.y < 0 || current.y >= H || current.x < 0 || current.x >= W || sits[current.y][current.x] != 1)
            continue;
        was_before[was_before_count++] = current;
        sits[current.y][current.x] = 0;
        for (auto& d : dir) {
            going_to.push({current.y + d.y, current.x + d.x});
        }
    }
    int size = was_before_count;
    for (int i = 0; i < was_before_count; ++i) {
        sits[was_before[i].y][was_before[i].x] = size | (hash << 20);
    }
    delete[] was_before;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    in.tie(0);
    ios_base::sync_with_stdio(false);
    int W, H;
    in >> W >> H;
    int** sits = new int*[H];
    for (int i = 0; i < H; ++i) {
        sits[i] = new int[W];
    }
    string next_input_row;
    for (int i = 0; i < H; i++) {
        in >> next_input_row;
        for (int j = 0; j < W; j++) {
            sits[i][j] = (next_input_row[j] == '#') ? 1 : 0;
        }
    }
    int hash = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (sits[i][j] == 1) {
                bfs(sits, H, W, i, j, hash++);
            }
        }
    }
    int m_sum = -1;
    sit m_sit = {1, 1};
    unordered_set<int> values;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (sits[i][j] != 0) continue;

            int sum = 0;
            for (auto& d : dir) {
                int ni = i + d.y, nj = j + d.x;
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && values.find(sits[ni][nj]) == values.end() && sits[ni][nj] != 0) {
                    sum += sits[ni][nj] & ((1 << 20) - 1);
                    values.insert(sits[ni][nj]);
                }
            }
            values.clear();

            if (sum > m_sum) {
                m_sum = sum;
                m_sit = {i + 1, j + 1};
            }
        }
    }

    out << m_sit.x << " " << m_sit.y << endl;

    for (int i = 0; i < H; ++i) {
        delete[] sits[i];
    }
    delete[] sits;

    return 0;
}