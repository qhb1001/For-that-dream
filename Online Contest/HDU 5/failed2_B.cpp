#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
char s[15], a[15], b[15];
int k, len;
void input() {
    scanf("%s%d", s, &k);
    len = strlen(s);
    memcpy(a, s, sizeof(s));
    memcpy(b, s, sizeof(s));
}
vector<char>q;
int letter[15];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        input();
        memset(letter, 0, sizeof(letter));
        for (int i = 0; i < len; ++i) {
            letter[a[i] - '0']++;
        }
        
        if (k == 1) {
            char c = '9' + 1;
            int idx = -1;
            for (int i = 1; i < len; ++i) {
                if (a[i] <= a[0] && c >= a[i] && a[i] != '0') {
                    idx = i;
                    c = a[i];
                }
            }   
            if (idx != -1) {
                swap(a[idx], a[0]);
            }

            c = '0';
            idx = -1;
            for (int i = 1; i < len; ++i) {
                if (b[i] >= b[0] && b[i] >= c) {
                    idx = i;
                    c = b[i];
                }
            }
            if (idx != -1) {
                swap(b[idx], b[0]);
            }

            printf("%s %s\n", a, b);
            continue;
        }

        
        //deal with zero
        

    }
}