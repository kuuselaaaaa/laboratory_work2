#include <iostream>
#include <string.h>

#include "_text.h"

using namespace std;

void mwef(text txt) {
    list<string>::iterator current = txt->cursor->line;

    int length = (*current).length();

    while((*current)[txt->cursor->position] != ' '
        && (*current)[txt->cursor->position] != '.'
        && (*current)[txt->cursor->position] != ','
        && (*current)[txt->cursor->position] != '\n'
        && txt->cursor->position < length) { txt->cursor->position++; }
}
