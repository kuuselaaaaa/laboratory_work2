#include <iostream>
#include <string.h>

#include "_text.h"

void mwef(text txt) {
    std::list<std::string>::iterator current = txt->cursor->line;

    int length = (*current).length();

    while((*current)[txt->cursor->position] != ' '
        && (*current)[txt->cursor->position] != '.'
        && (*current)[txt->cursor->position] != ','
        && (*current)[txt->cursor->position] != '\n'
        && txt->cursor->position < length) { txt->cursor->position++; }
}
