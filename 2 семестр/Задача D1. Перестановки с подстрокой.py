# Условие
# Даны строки S и P, состоящие из малых латинских букв. Требуется определить сколько различных слов, составленных из букв строки S, содержат в себе подстроку P.
# Например, если S=dcba, P=bc, то получится 11 строк: bc,abc,bca,dbc,bcd,adbc,dabc,abcd,dbca,bcad,bcda.
# Формат входного файла
# Первая строка содержит строку S, вторая — строку P.
# Формат выходного файла
# В выходном файле должно содержаться единственное число — количество слов.
# Ограничения
# Длины строк находятся в диапазоне от 1 до 12 букв. Все буквы строки S различны.
# Примеры тестов
# №	Входной файл (input.txt)	Выходной файл (output.txt)
# 1	dbca                        11
#   bc
# 2	xyz                         0
#   xx
import math

with open('input.txt', 'r') as file:
    S = file.readline().strip()
    P = file.readline().strip()

def count_insertions(S, P):
    if len(set(P)) != len(P) or not set(P).issubset(set(S)):
        return 0
    
    N = len(S)
    M = len(P)
    
    total_insertions = 0
    
    for i in range(N - M + 1):
        num_words = math.factorial(N - M) // math.factorial(N - M - i)
        num_insertions = i + 1
        total_insertions += num_words * num_insertions
    
    return total_insertions

result = count_insertions(S, P)

with open('output.txt', 'w') as file:
    file.write(str(result))