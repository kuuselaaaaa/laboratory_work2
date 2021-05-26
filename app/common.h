#ifndef COMMON_H
#define COMMON_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент, корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/* Загружает содержимое указанного файла */
void load(text txt, char *filename);

/* Выводит содержимое указанного файла на экран */
void show(text txt);

/* Сохраняем содержимое в указанный файл */
void save(text txt, char *filename);

/* Выводит первое слово из каждой строки указанного файла на экран */
void showfirstwords(text txt);

#endif
