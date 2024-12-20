# Условие
# Когда Петя учился в школе, он часто участвовал в олимпиадах по информатике, математике и физике. Так как он был достаточно способным мальчиком и усердно учился, то на многих из этих олимпиад он получал дипломы. К окончанию школы у него накопилось N дипломов, причем, как оказалось, все они имели одинаковые размеры: W — в ширину и H — в высоту.
# Сейчас Петя учится в одном из лучших российских университетов и живет в общежитии со своими одногруппниками. Он решил украсить свою комнату, повесив на одну из стен свои дипломы за школьные олимпиады. Так как к бетонной стене прикрепить дипломы достаточно трудно, то он решил купить специальную доску из пробкового дерева, чтобы прикрепить ее к стене, а к ней — дипломы. Для того чтобы эта конструкция выглядела более красиво, Петя хочет, чтобы доска была квадратной и занимала как можно меньше места на стене. Каждый диплом должен быть размещен строго в прямоугольнике размером W на H. Прямоугольники, соответствующие различным дипломам, не должны иметь общих внутренних точек.
# Требуется написать программу, которая вычислит минимальный размер стороны доски, которая потребуется Пете для размещения всех своих дипломов.
# Система оценивания
# Решения, правильно работающие только при W,H,N≤1000, будут оцениваться в 40 баллов.
# Формат входного файла
# Входной файл содержит три целых числа: W,H,N
# Формат выходного файла
# В выходной файл необходимо вывести ответ на поставленную задачу.
# Ограничения
# 1≤W,H,N≤10^9
# Примеры тестов
# №	Входной файл (diploma.in)	Выходной файл (diploma.out)
# 1	2 3 10                      9
def MS(W, H, N):
    l = 1
    r = max(W, H) * N
    while l < r:
        mid = (l + r) // 2
        rows = mid // W
        cols = mid // H
        td = rows * cols
        if td >= N:
            r = mid
        else:
            l = mid + 1
    return l
    
    
with open("diploma.in", "r") as file:
    W, H, N = map(int, file.readline().split())
Ms = MS(W, H, N)
with open("diploma.out", "w") as file:
    file.write(str(Ms))