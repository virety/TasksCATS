# Условие
# На шашечной доске размером N×N клеток расположены несколько белых и несколько черных шашек. Горизонтали доски обозначены числами 1,2,3,… снизу вверх. (То есть первая строка входных данных описывает горизонталь доски с номером N, вторая N−1 и т.д.) Вертикали обозначены буквами a,b,c,… слева направо. Клетка, таким образом, задается комбинацией из буквы и числа, например d12. Ход шашки задается перечислением всех клеток, которые она посетила за этот ход, включая начальную и конечную. Обозначения клеток при этом разделяются знаком - (минус). Например: a1-c3-e1.
# Шашка может побить (взять) шашку противоположного цвета, "перепрыгнув" через нее по диагонали в любом направлении. Если после этого имеется возможность взять еще одну шашку, то это можно сделать на том же ходу.
# Требуется определить ход черных, соответствующий наиболее длинному взятию. Если имеется несколько вариантов хода, выдать любой из них.
# Формат входного файла
# В первой строке входного файла содержится число N. В следующих N строках — описание позиции, состоящее из символов '.' (точка), 'O' (заглавная латинская О),'X' (заглавная латинская X). Они определяют пустую клетку, белую шашку и черную шашку соответственно.
# Формат выходного файла
# В выходном файле должна содержаться единственная строка вида L1N1−L2N2−…−LKNK, где K≥1, или Impossible если взятие невозможно.
# Ограничения
# 1≤N≤12
# Примеры тестов
# №	Входной файл (input.txt)	Выходной файл (output.txt)
# 1	5                           e3-c1-a3-c5-e3
#     .....
#     .O.O.
#     ....X
#     .O.O.
#     X....  
# 2	4                           Impossible
#     X...
#     ....
#     ....
#     ...O  
def longest_capture(board):
    N = len(board)
    longest_path = []

    def explore_captures(row, col, path):
        nonlocal longest_path

        for dr, dc in [(-1, -1), (-1, 1), (1, -1), (1, 1)]:
            r, c = row + dr, col + dc
            if 0 <= r < N and 0 <= c < N and board[r][c] == 'O':
                r2, c2 = r + dr, c + dc
                if 0 <= r2 < N and 0 <= c2 < N and board[r2][c2] == '.':
                    board[row][col] = '.'
                    board[r][c] = '.'

                    move = f"{chr(97 + col)}{N - row}-{chr(97 + c2)}{N - r2}"
                    path.append(move)
                    explore_captures(r2, c2, path)

                    board[row][col] = 'X'
                    board[r][c] = 'O'
                    path.pop()

        if len(path) > len(longest_path):
            longest_path = path[:]

    for row in range(N):
        for col in range(N):
            if board[row][col] == 'X':
                explore_captures(row, col, [])

    return "-".join(longest_path) if longest_path else "Impossible"


def reading():
    with open("input.txt") as f:
        N = int(f.readline())
        board = [list(f.readline().strip()) for _ in range(N)]
    return board


def writing(res):
    with open("output.txt", "w") as f:
        f.write(res)


board = reading()
res = longest_capture(board).split("-")
result = []
for i in range(len(res)):
    if i == 0:
        continue

    prev = res[i - 1]
    curr = res[i]
    if prev != curr:
        result.append(res[i - 1])
result.append(res[-1])
result = "-".join(result)
writing(result)
