//
// Created by Administrator on 2017/5/5 0005.
//

#include <stdio.h>

void print_count(int ndigit[], int nwhite, int nother) {
    int d, i, ntotal;
    float fdigit[10], fwhite, fother;

    ntotal = 0;
    for (d = 0; d < 10; ++d) {
        ntotal += ndigit[d];
    }
    ntotal += nwhite;
    ntotal += nother;

    for (d = 0; d < 10; ++d) {
        fdigit[d] = 1.0 * ndigit[d] / ntotal;
    }
    fwhite = 1.0 * nwhite / ntotal;
    fother = 1.0 * nother / ntotal;

    for (d = 0; d <= 9; ++d) {
        printf("count of digit %3d(%%):", d);
        for (i = 0; i < fdigit[d] * 100; ++i) {
            printf("|");
        }
        printf("\n");
    }

    printf("count of white    (%%):");
    for (i = 0; i < fwhite * 100; ++i) {
        printf("|");
    }
    printf("\n");

    printf("count of other    (%%):");
    for (i = 0; i < fother * 100; ++i) {
        printf("|");
    }
    printf("\n");

}

int main() {
    int i, c, ndigit[10], nwhite, nother;

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++ndigit[c - '0'];
        } else if (c == ' ' || c == '\t' || c == '\n') {
            ++nwhite;
        } else {
            ++nother;
        }
    }
    print_count(ndigit, nwhite, nother);
}