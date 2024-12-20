# Условие
# Король и королева пригласили на пир n рыцарей. Пиршество затянулось допоздна и хозяева изрядно устали. К сожалению, гости не расходятся, пока не услышат от короля с королевой хвалебную речь. У короля есть любимое число k, поэтому он может произнести речь и восславить одного или сразу k рыцарей (естественно, при этом за столом должно сидеть не менее k рыцарей). Сразу после этого один или k рыцарей покидают замок. У королевы тоже есть своё любимое число q, поэтому она может произнести речь и восславить одного или сразу q рыцарей. Сразу после этого один или q рыцарей покидают замок.
# Король с королевой решили устроить игру — тот, кто выставит из замка последнего рыцаря — выигрывает и получает право выбрать для культурной программы следующего праздника свою любимую труппу бродячих артистов. Кто выигрывает при безошибочной игре обоих игроков — король, делающий первый ход, или королева, делающая второй ход? Естественно, игроки ходят по очереди.
# Формат входных данных
# Единственная строка входного файла содержит три натуральных числа, записанных через пробел: n, k и q — количество рыцарей на королевском пиру, а также любимые числа короля и королевы.
# Формат выходных данных
# Выведите титул победителя — "King" или "Queen" (без кавычек).
# Ограничения
# 1≤k,q,n≤10^5
# Система оценки и описание подзадач
# Баллы за каждый тест начисляются независимо.
# Решения, верно работающие при k=q, получат не менее 20 баллов.
# Пояснение к примеру
# На пиру 13 рыцарей. Любимое число короля — 6, королевы — 4. Первым ходом король хвалит 6 рыцарей. После любых ответных ходов королевы ему нужно хвалить по одному рыцарю. Если же король первым ходом восславит одного рыцаря, то он проиграет.
# Примеры тестов
# №	Стандартный вход	Стандартный выход
# 1	13 6 4              King
def determine_winner(n,k,q): 
    win = [[False, False] for _ in range(n+1)]
    win[0][0] = win[0][1] = False 
    for i in range(1,  n + 1): 
        win[i][0] = (i >= 1 and not win[i - 1][1]) or (i >= k and not win[i - k][1]) 
        win[i][1] = (i >= 1 and not win[i - 1][0]) or (i >= q and not win[i - q][0]) 
    return "King" if win[n][0] else "Queen"

n,  k,  q = map(int,  input().strip().split())
print(determine_winner(n,  k,  q))