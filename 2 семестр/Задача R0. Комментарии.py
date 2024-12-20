# Условие
# Джон, хотя и пишет на языке С, дает файлам расширение CPP, чтобы использовать в своих программах комментарии в С++-стиле (от // до конца строки). Обычный С-комментарий, который начинается с символов "/*" и заканчивается символами "*/", Джон также иногда использует, обычно для многострочных комментариев. Для участия в конкурсе программ необходимо, чтобы программа соответствовала стандартам языка ANSI С, и Джону нужно заменить все C++-комментарии на стандартные. Для этого в C++-комментарии можно заменить "//" на "/*" и добавить "*/" в конце строки. Иногда в C++-комментарии может встретиться последовательность символов "*/", в этом случае нужно вставить пробел между двумя этими символами: "* /". К счастью внутри строковых констант в программе Джона не встречаются последовательностей "//", "/*" и "*/".
# Напишите программу, которая преобразует в программе Джона C++-комментарии в C-комментарии.
# Формат входного файла
# Во входном файле содержится программа Джона.
# Формат выходного файла
# В выходной файл вывести программу из входного файла, изменив стиль комментариев.
# Ограничения
# Файл состоит из не более 100 строк длиной не более 100 символов.
# Примеры тестов
# №	Входной файл (input.txt)	Выходной файл (output.txt)
# 1	#include &lt;stdio.h&gt;    #include &lt;stdio.h&gt;
#     /* Пример программы         /* Пример программы
#      */                          */
#     int main()                  int main()
#     { printf( //Печать          { printf( /*Печать*/
#           "Hello, world");          "Hello, world");
#       return 0; //*/*             return 0; /** /**/
#     }                           }

BUFFER_SIZE = 20000

def match(buffer, position, chars):
    if position < 0:
        return False
    length = len(chars)
    for i in range(length):
        if buffer[position + i] != chars[i]:
            return False
    return True
def replace(buffer, position, chars):
    if position < 0:
        return
    length = len(chars)
    for i in range(length):
        buffer[position + i] = chars[i]
def main():
    with open("input.txt", "r") as input_file, open("output.txt", "w") as output_file:
        buffer = ['\0'] * BUFFER_SIZE
        i = 0
        _char = -1
        is_single = False
        is_multi = False
        single_start = -2
        multi_start = -2
        multi_end = -2
        while True:
            _char = input_file.read(1)
            if not _char:
                break
            buffer[i] = _char
            if match(buffer, i - 1, "//") and not is_single and not is_multi and multi_end != i - 1:
                replace(buffer, i - 1, "/*")
                single_start = i
                is_single = True
            elif match(buffer, i - 1, "/*") and not is_single and not is_multi and multi_end != i - 1:
                multi_start = i
                is_multi = True
            elif match(buffer, i - 1, "*/"):
                if is_single and single_start != i - 1:
                    replace(buffer, i, " /")
                    i += 1
                elif is_multi and multi_start != i - 1:
                    is_multi = False
                    multi_end = i
            elif match(buffer, i, "\n") and is_single:
                replace(buffer, i, "*/\n")
                is_single = False
                i += 2
            i += 1
        if is_single:
            replace(buffer, i, "*/")
        output_file.write(''.join(buffer).rstrip('\0'))
if __name__ == "__main__":
    main()