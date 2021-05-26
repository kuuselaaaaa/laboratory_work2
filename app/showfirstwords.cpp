#include <iostream>
#include <string.h>
#include <assert.h>

#include "common.h"
#include "text/text.h"

using namespace std;

static void show_first_words(int index, string contents, int cursor, void *data);

/* Выводит первое слово из каждой строки указанного файла на экран */
void showfirstwords(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_first_words, NULL);
}

static void show_first_words(int index, string contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents.c_str() != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(cursor);
    UNUSED(data);
    UNUSED(index);

    int i = 0;
    /* Обрабатываем пробелы в начале строки, идём до первого слова */
    while (contents[i] == ' ') {
        i++;
    }

    /* Идём либо до следующего пробела либо до конца строки */
    while (contents[i] != ' ' && contents[i] != '\0') {
        cout << contents[i];
        i++;
    }

    cout << ("\n");
}


