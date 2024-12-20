# Условие
# Костяшка домино описывается парой цифр от 0 до 6, например 06 или 33. Цепочка - это последовательность костяшек, скложенных таким образом, чтобы соседние цифры на них совпадали. При этом костяшки можно переворачивать. Например, 15-54-44-46-60 — цепочка.
# Дана строка из 2N символов (цифр), задающая N костяшек домино. Требуется переставить все эти костяшки таким образом, чтобы они образовали цепочку, либо определить, что это невозможно. Если существует несколько способов, вывести любой из них.
# Формат входного файла
# Входной файл содержит строку, задающую костяшки.
# Формат выходного файла
# В выходном файле должна содержаться единственная строка вида d1-d2-...-dN, где d1,d2,…,dN — костяшки из исходного набора, или NO, если сложить цепочку невозможно.
# Ограничения
# 2≤N≤21
# Примеры тестов
# №	Входной файл (input.txt)	Выходной файл (output.txt)
# 1	1234                        NO
# 2	453335                      45-53-33
def find_domino_chain(s):
    def dfs(curr, visited):
        nonlocal result
        if result:
            return
        if len(curr) == len(s):
            result = list(curr)
            return
        for i in range(len(s)):
            if not visited[i]:
                if len(curr) == 0 or curr[-1][1] == s[i][0]:
                    visited[i] = True
                    dfs(curr + [s[i]], visited)
                    visited[i] = False
                elif len(curr) == 0 or curr[-1][1] == s[i][1]:
                    visited[i] = True
                    dfs(curr + [(s[i][1], s[i][0])], visited)
                    visited[i] = False
    
    result = None
    visited = [False] * len(s)
    dfs([], visited)
    return result

with open("input.txt", "r") as file:
    s = file.readline().strip()
    dominoes = [(int(s[i]), int(s[i+1])) for i in range(0, len(s), 2)]
    result = find_domino_chain(dominoes)

with open("output.txt", "w") as file:
    if result:
        file.write('-'.join([f"{x[1]}{x[0]}" for x in result[::-1]]))
    else:
        file.write("NO")
