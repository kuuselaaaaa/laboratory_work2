#include <iostream>
#include <string.h>

#include "_text.h"

void rn(text txt, int line_number)
{
    int index = 0;
    std::list<std::string>::iterator line_to_delete = txt->lines->begin();

    while (line_to_delete != txt->lines->end()) {
        if (index == line_number)
            break;
        line_to_delete++;
        index++;
    }

    txt->lines->erase(line_to_delete);

    return;
}
