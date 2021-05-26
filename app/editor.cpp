#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "text/text.h"

#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    char *arg2;

    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed > ");

        /* Получаем команду */
        fgets(cmdline, MAXLINE, stdin);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }
        
        /* Обработка команды load имя файла */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }

            /* Сдвигаем курсор в нулевую позицию */
            if (m(txt, 0, 0) != 0) {
                fprintf(stderr, "Can't move to zero\n");
            }
            continue;
        }
        
        /* Обработка команды show */
        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }

        /* Обработка команды save */
        if (strcmp(cmd, "save") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: save filename\n");
            } else {
                save(txt, arg);
            }
            continue;
        }

        /* Обработка команды quit */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }

        /* Обработка команды showfirstwords */
        if (strcmp(cmd, "showfirstwords") == 0) {
            showfirstwords(txt);
            continue;
         }
        
        /* Обработка команды m */
        if (strcmp(cmd, "m") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: m line_number cursor\n");
            } else {
                if ((arg2 = strtok(NULL, " \n")) == NULL) {
                    fprintf(stderr, "Usage: m line_number cursor\n");
                } else {
                    if (m(txt, atoi(arg), atoi(arg2)) != 0) {
                        fprintf(stderr, "Invalid arguments\n");
                    }
                }
            }
            continue;
        }

        /* Обработка команды mwef */
        if (strcmp(cmd, "mwef") == 0) {
            mwef(txt);
            continue;
        }

        /* Обработка команды rn номер */
        if (strcmp(cmd, "rn") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: rn line_number\n");
            } else {
                rn(txt, atoi(arg));
            }
            continue;
        }

        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
