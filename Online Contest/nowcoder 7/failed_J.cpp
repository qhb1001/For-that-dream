#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;
typedef long long ll;
const int MAX = 1e3 + 5;
ll letter[130];
char G[MAX][MAX];
struct Node {
    int l, r;
    ll now;
}t[MAX][MAX<<2];
void build(Node* t, int i, int j, int l, int r) {
    t[i].l = l; t[i].r = r;
    if (l == r) {
        t[i].now = letter[G[l][j]];
        return ;
    }
    int mid = l + r >> 1;
    
    
}
 

void pretreatment() {
    ll now = 1;
    for (char c = 'a'; c <= 'z'; ++c) {
        letter[c] = 1LL<<now;
        ++now;
    }
    
    for (char c = 'A'; c <= 'Z'; ++c) {
        letter[c] = 1LL<<now;
        ++now;
    }
}
int row, col, up[MAX][MAX], vis[130], finalUp[MAX][MAX];
void input() {
    scanf("%d%d", &row, &col);
    for (int i = 0; i < row; ++i) {
        scanf("%s", G[i]);
    }
    
    // //deal with row
    // for (int i = 0; i < row; ++i) {
    //     for (int j = 0; j < col; ++j) {
    //         sumOfRow[i + 1][j + 1] = sumOfRow[i + 1][j] | letter[G[i][j]];
    //     }
    // }
    
    // //deal with column
    // for (int j = 0; j < col; ++j) {
    //     for (int i = 0; i < row; ++i) {
    //         sumOfCol[i + 1][j + 1] = sumOfCol[i][j + 1] | letter[G[i][j]];
    //     }
    // }
    
    //deal with 'up'
    for (int j = 0; j < col; ++j) {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < row; ++i) {
            if (!vis[G[i][j]]) {
                vis[G[i][j]] = i + 1;
            } else {
                up[i + 1][j + 1] = vis[G[i][j]];
                vis[G[i][j]] = i + 1;
            }
        }
    }
    
    //deal with 'finalUp'
    char c;
    for (int j = 0; j < col; ++j) {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < row; ++i) {
            c = G[i][j];
            if (!vis[c]) {
                vis[c] = 1;
                finalUp[i + 1][j + 1] = finalUp[i][j + 1] + 1;
            } else {
                finalUp[i + 1][j + 1] = min(finalUp[i][j + 1]+1,i+1-up[i+1][j+1]);
            }
        }
    }
}

long long ans = 0;
void solve() {
    ll status;
    for (int i = 1;i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
            //枚举竖直边长度
            memset(vis, 0, sizeof(vis));
            for (int len = 1; len <= 52 && i + len - 1 <= row; ++len) {
                status = 0;
                
                //首先得到第一条边的数值
                if (vis[G[i - 1 + len - 1][j - 1]]) break;
                vis[G[i - 1 + len - 1][j - 1]] = 1;
                
                // status = (sumOfCol[i + len - 1][j] ^ sumOfCol[i - 1][j])|letter[G[i+len-2][j-1]];

                ++ans;
                
                //开始向右扩展
                for (int k = 1; k <= 52 && j + k <= col; ++k) {
                    if(finalUp[i+len-1][j+k]<len) break;
                    // if((status & (sumOfCol[i+len-1][j+k] ^ sumOfCol[i-1][j+k]))!=0) break;
                    // status|=((sumOfCol[i+len-1][j+k] ^ sumOfCol[i-1][j+k])|letter[G[i+len-2][j+k-1]]);
                    ++ans;
                }
            }
        }
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.a", "w", stdout);
    pretreatment();
    input();
    solve();
    printf("%lld\n",ans);
    return 0;
}

