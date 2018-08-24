#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
char ans[222][222];
int main() {
    freopen("input.txt", "r", stdin);
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
            if (col <= row) {
                for (int i = 1; i <= row/2; ++i) {
                    ans[i][1] = '('; ans[i][col] = ')';
                    int cnt = 2;
                    for (int j = 1; j <= col/2-1; ++j) {
                        ans[i][cnt++] = '('; 
                        ans[i][cnt++] = ')';
                    }
                }

                for (int i = row/2+1; i <= row; ++i) {
                    int cnt = 1;
                    for (int j = 1; j <= col/2; ++j) {
                        ans[i][cnt++] = '(';
                        ans[i][cnt++] = ')';
                    }
                }

                for (int i = 1; i <= row; ++i) {
                    for (int j = 1; j <= col; ++j) printf("%c", ans[i][j]);
                    printf("\n");
                }

            } else {
                for (int j = 1; j <= col/2; ++j) {
                    ans[1][j] = '('; ans[row][j] = ')';
                    int cnt = 2;
                    
                    for (int i = 1; i <= row/2 - 1; ++i) {
                        ans[cnt++][j] = '(';
                        ans[cnt++][j] = ')';
                    }
                }

                for (int j = col/2+1; j <= col; ++j) {
                    int cnt = 1;
                    for (int i = 1; i <= row/2; ++i) {
                        ans[cnt++][j] = '(';
                        ans[cnt++][j] = ')';
                    }
                }

                for (int i = 1; i <= row; ++i) {
                    for (int j = 1; j <= col; ++j) printf("%c", ans[i][j]);
                    printf("\n");
                }
            }
        }
    }
}