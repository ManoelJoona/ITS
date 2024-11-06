/*
    C言語でCNNを作成
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int affeine(int a[],int w[][]) {
    int i, j;

    srand((unsigned)time(NULL));   /* 乱数の種をtime からとる（乱数の初期化） */

    for (i = 0; i < 2; i++) {      /* 重み（０～１） */
        for (j = 0; j < 3; j++) {
            double w[i][j] = {(rand() % 10) / 10};
        }
    }

    for (i = 0; i < 2; i++) {     /* 行列積 */
        for (j = 0; j < 3; j++) {
            a[j] = w[i][j] * a[j];
        }
    }

    return a[];
}