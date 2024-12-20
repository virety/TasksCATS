// Условие
// Накануне нового года Дед Мороз занимается свим привычным делом: он строит воздушные замки. Пространство в котором Дед Мороз строит замки - это куб, который состоит из NxNxN маленьких кубиков. Каждый маленький кубик может быть занят облаком или не занят. Воздушный замок Деда Мороза - это прямоугольный паралеллепипед с целочисленными координатами, стороны которого параллельны осям координат. Кроме того, в пространсте есть M облаков. Дед Мороз не хочет, чтобы его замок задевал облака. Замок задевает облако, если они имеют общую клетку.
// Помогите Деду Морозу постоить наибольший по объему замок.
// Формат входного файла
// Во входном файле содержатся числа N и M. За ними следуют M троек чисел - координаты облаков. Все координаты находятся в пределах между 1 и N включительно. Облака могут занимать одну и ту же клетку.
// Формат выходного файла
// В выходном файле должно содержаться единственное число - объем самого просторного замка.
// Ограничения
// 1≤N≤80 0≤M≤200000
// Примеры тестов
// №	Входной файл (input.txt)	Выходной файл (output.txt)
// 1	2 1                         4
//     1 1 2
// 2	3 0                         27
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<vector<int>>> build_prefix_sum(int N, const vector<tuple<int, int, int>>& clouds) {
    vector<vector<vector<int>>> prefix_sum(N + 1, vector<vector<int>>(N + 1, vector<int>(N + 1, 0)));
    
    for (const auto& cloud : clouds) {
        int x, y, z;
        tie(x, y, z) = cloud;
        prefix_sum[x][y][z] = 1;
    }
    
    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= N; ++y) {
            for (int z = 1; z <= N; ++z) {
                prefix_sum[x][y][z] += prefix_sum[x - 1][y][z] + prefix_sum[x][y - 1][z] + prefix_sum[x][y][z - 1]
                                     - prefix_sum[x - 1][y - 1][z] - prefix_sum[x - 1][y][z - 1] - prefix_sum[x][y - 1][z - 1]
                                     + prefix_sum[x - 1][y - 1][z - 1];
            }
        }
    }
    
    return prefix_sum;
}

int get_sum(const vector<vector<vector<int>>>& prefix_sum, int x1, int y1, int z1, int x2, int y2, int z2) {
    return prefix_sum[x2][y2][z2] - prefix_sum[x1 - 1][y2][z2] - prefix_sum[x2][y1 - 1][z2] - prefix_sum[x2][y2][z1 - 1]
           + prefix_sum[x1 - 1][y1 - 1][z2] + prefix_sum[x1 - 1][y2][z1 - 1] + prefix_sum[x2][y1 - 1][z1 - 1]
           - prefix_sum[x1 - 1][y1 - 1][z1 - 1];
}

int find_largest_volume(int N, const vector<vector<vector<int>>>& prefix_sum) {
    int max_volume = 0;
    
    for (int x1 = 1; x1 <= N; ++x1) {
        for (int y1 = 1; y1 <= N; ++y1) {
            for (int x2 = x1; x2 <= N; ++x2) {
                for (int y2 = y1; y2 <= N; ++y2) {
                    int max_height = 0;
                    for (int z = 1; z <= N; ++z) {
                        if (get_sum(prefix_sum, x1, y1, z, x2, y2, z) == 0) {
                            max_height++;
                            max_volume = max(max_volume, (x2 - x1 + 1) * (y2 - y1 + 1) * max_height);
                        } else {
                            max_height = 0;
                        }
                    }
                }
            }
        }
    }
    
    return max_volume;
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    
    int N, M;
    input >> N >> M;
    
    vector<tuple<int, int, int>> clouds(M);
    for (int i = 0; i < M; ++i) {
        int x, y, z;
        input >> x >> y >> z;
        clouds[i] = make_tuple(x, y, z);
    }
    
    vector<vector<vector<int>>> prefix_sum = build_prefix_sum(N, clouds);
    int largest_volume = find_largest_volume(N, prefix_sum);
    
    output << largest_volume << endl;
    
    return 0;
}