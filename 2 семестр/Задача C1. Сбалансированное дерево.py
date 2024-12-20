# Условие
# Дана последовательность целых чисел. Каждое прочитанное число обрабатывается следующим образом:
# если число больше нуля, оно добавляется к текущему множеству чисел;
# если число меньше нуля, противоположное ему число удаляется из текущего множества чисел;
# если число равно нулю, множество чисел выводится в порядке возрастания и программа завершает работу.
# Формат входного файла
# Входной файл содержит последовательность чисел.
# Формат выходного файла
# Выходной файл должен содержать последовательность чисел, отсортированных по возрастанию.
# Ограничения
# Количество чисел находится в диапазоне от 0 до 10^6, сами числа — в диапазоне от − 2^31 до 2^31−1.
# Примеры тестов
# №	Входной файл (input.txt)	Выходной файл (output.txt)
# 1	3 2 1 3 0                   1 2 3
# 2	5 -1 6 -5 5 0               5 6
def process_data(input_file, output_file):
    
    with open(input_file, "r") as file:
        numbers = list(map(int, file.readline().split()))
    current_set = set()
    output = []
    for num in numbers:
        if num > 0:
            current_set.add(num)
        elif num < 0:
            current_set.discard(abs(num))
        else:
            sorted_set = sorted(list(current_set))
            for item in sorted_set:
                output.append(str(item))
            break
    with open(output_file, "w") as file:
        file.write(" ".join(output))
process_data("input.txt", "output.txt")