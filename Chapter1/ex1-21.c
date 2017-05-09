//
// Created by Administrator on 2017/5/8 0008.
//

#include <stdio.h>

#define N 4
#define SPACE ' '
#define TAB '\t'

int main() {
    int i;
    int index, c, tab_to_space, space_count;
    int off_set, tab_to_print, space_to_print;

    index = 0;  // current column
    space_count = 0;  // count the continuous spaces
    while ((c = getchar()) != EOF && c != '\n') {

        // count space num, count tab as spaces by the column place.
        if (c == SPACE || c == TAB) {
            space_count = 0;
            while (1) {
                if (c == SPACE) {
                    ++space_count;
                    ++index;
                } else if (c == TAB) {
                    tab_to_space = N - index % N;
                    space_count += tab_to_space;
                    index += tab_to_space;
                } else {
                    ++index;
                    break;
                }

                // getchar until is not space or tab
                c = getchar();

                // break out
                if (c == EOF || c == '\n') {
                    ++index;
                    break;
                }
            }
        } else {
            ++index;
        }

        // if there is some space, print minimum spaces and tabs
        if (space_count > 0) {
            off_set = index - space_count - 1;
            tab_to_print = (index - 1) / N - off_set / N;
            space_to_print = (index - 1) % N;
            for (i = 0; i < tab_to_print; ++i) { putchar(TAB); }
            for (i = 0; i < space_to_print; ++i) { putchar(SPACE); }
            space_count = 0;
        }

        // break out at the end of line
        if (c == EOF || c == '\n') {
            break;
        }

        // put the char unless is space or tab
        putchar(c);
    }
    putchar('\n');
}
