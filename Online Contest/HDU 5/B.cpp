#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 20;
int p[MAX], num[MAX], k, len, Max, Min;
char s[MAX];

void update() {
    if (num[p[1]] == 0) return ;

    int cnt = 0, ss = 0;
    int temp[MAX];
    memcpy(temp, p, sizeof(p));
    for (int i = 1; i <= len; ++i) {
        ss = ss * 10 + num[p[i]];
        if (temp[i] != i) {
            for (int j = i + 1; j <= len; ++j) {
                if (temp[j] == i) {
                    swap(temp[j], temp[i]);
                    ++cnt;
                    if (cnt > k)   return ;
                    break;
                }
            }
        }
    }

    if (cnt > k)    return ;
    Max = max(Max, ss);
    Min = min(Min, ss);
}

int main() {

    // freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s%d", s + 1, &k);

        len = strlen(s + 1);
        for (int i = 1; i <= len; ++i)  {
            num[i] = s[i] - '0';
        }
        if (k >= len - 1) {
            int times[11] = {0};
            for (int i = 1; i <= len; ++i) {
                times[num[i]]++;
            }

            //print the minimum value
            for (int i = 1; i <= 9; ++i) {
                if (times[i]) {
                    printf("%d", i);
                    times[i]--;
                    break;
                }
            }

            for (int i = 0; i <= 9; ++i) {
                while (times[i]--) {
                    printf("%d", i);
                }
            }
            printf(" ");

            //print the maximum value
            memset(times, 0, sizeof(times));
            for (int i = 1; i <= len; ++i) {
                times[num[i]]++;
            }
            for (int i = 9; i >= 0; --i) {
                while (times[i]--) {
                    printf("%d", i);
                }
            }

            printf("\n");
            continue;
        }

        for (int i = 1; i <= len; ++i)  p[i] = i;
        Max = -1;
        Min = 2e9;
        do {
            update();
        } while (next_permutation(p + 1, p + 1 + len));

        printf("%d %d\n", Min, Max);
    }
}