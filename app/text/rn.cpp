#include <iostream>
#include <string.h>

#include "_text.h"

void rn(text txt, int line_number)
{
    if (line_number < 0) {
        std::cerr << "Invalid arguments";
        return;
    }

    int index = 0;
    std::list<std::string>::iterator line_to_delete = txt->lines->begin();
    std::list<std::string>::iterator next_line = line_to_delete;
    next_line++;

    if (line_to_delete == txt->lines->end()) {
        std::cerr << "There are already no any lines in the text!\n";
        return;
    }

    if (next_line == txt->lines->end()) {
        std::cerr << "There are already no any lines in the text!\n";
        return;
    }

    while (line_to_delete != txt->lines->end()) {
        if (index == line_number) {
            next_line = line_to_delete;
            next_line++;
            if (next_line == txt->lines->end()) {
                txt->cursor->line--;
            } else {
                txt->cursor->line++;
            }
            break;
        }
        line_to_delete++;
        index++;
    }

    txt->lines->erase(line_to_delete);

    return;
}
