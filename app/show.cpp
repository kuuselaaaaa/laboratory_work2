#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "common.h"
#include "text/text.h"

using namespace std;

static void show_line(int index, string contents, int cursor, void *data);

/* Выводит содержимое указанного файла на экран */
void show(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
}

/* Выводит содержимое указанного файла на экран */
static void show_line(int index, string contents, int cursor, void *data)
{
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);

    /* Выводим строку на экран */
    if (cursor != -1) {
        printf("%.*s|%.*s\n", cursor, contents.c_str(),
               (int) contents.length() - cursor, contents.c_str() + cursor);
    } else {
        printf("%s\n", contents.c_str());
    }
}
