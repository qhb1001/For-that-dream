#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char ans[222][222];
int main() {
    // freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        int row, col;
        scanf("%d%d", &row, &col);
        if (row&1 && col&1) {
            for (int i = 1; i <= row; ++i) {
                for (int j = 1; j <= col; ++j) {
                    printf("(");
                }
                printf("\n");
            }
        } else if (row&1) {
            int cnt = col / 2;
            for (int i = 1; i <= row; ++i) {
                for (int k = 1; k <= cnt; ++k) printf("()");
                printf("\n");
            }
        } else if (col&1) {
            int cnt = row/2;
            for (int i = 1; i <= cnt; ++i) {
                for (int j = 1; j <= col; ++j)  printf("(");
                printf("\n");
            }
            for (int i = cnt + 1; i <= row; ++i) {
                for (int j = 1; j <= col; ++j)  printf(")");
                printf("\n");
            }
        } else {
            if (min(row, col) == 2) {
                if (row > col) {
                    for (int i = 1; i <= row; ++i) printf("()\n");
                } else {
                    for (int i = 1; i <= col; ++i)  printf("(");
                    printf("\n");
                    for (int i = 1; i <= col; ++i)  printf(")");
                    printf("\n");
                }
                continue;
            }
            if (min(row, col) == 4) {
                int r = row, c = col;
                if (row > col)  swap(r, c);
                for (int i = 1; i <= c; ++i) ans[1][i] = '(';
                for (int i = 1; i <= c; ++i) ans[2][i] = i <= c/2? ')':'(';
                for (int i = 1; i <= c; ++i) ans[3][i] = i <= c/2? '(':')';
                for (int i = 1; i <= c; ++i) ans[4][i] = ')';

                if (row <= col) {
                for (int i = 1; i <= row; ++i) {
                    for (int j = 1; j <= col; ++j)  printf("%c", ans[i][j]);
                    printf("\n");
                }
            } else {
                for (int j = 1; j <= row; ++j) {
                    for (int i = 1; i <= col; ++i) printf("%c", ans[i][j]);
                    printf("\n");
                }
            }
            continue;
            }

            int r = row, c = col;
            if (r > c)  swap(r, c);
            for (int i = 1; i <= c; ++i) {
                    ans[1][i] = '(';
                    ans[r][i] = ')';
                }

            bool flag = 1;
            for (int i = 2; i < r; ++i) {
                if (flag) {
                    int cnt = 1;
                    for (int j = 1; j <= c/2; ++j) {
                        ans[i][cnt++] = '('; ans[i][cnt++] = ')';
                    }
                } else {
                    int cnt = 2;
                    ans[i][1] = '('; ans[i][c] = ')';
                    for (int j = 1; j < c/2; ++j) {
                        ans[i][cnt++] = '('; ans[i][cnt++] = ')';
                    }
                }
                flag = !flag;
            }

            if (row <= col) {
                for (int i = 1; i <= row; ++i) {
                    for (int j = 1; j <= col; ++j)  printf("%c", ans[i][j]);
                    printf("\n");
                }
            } else {
                for (int j = 1; j <= row; ++j) {
                    for (int i = 1; i <= col; ++i) printf("%c", ans[i][j]);
                    printf("\n");
                }
            }
        }
    }
}