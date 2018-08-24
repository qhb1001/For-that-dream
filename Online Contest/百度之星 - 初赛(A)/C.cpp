#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1e4 + 5;
char s[MAX];
int len, k;
struct Node {
    int len, cost;
    Node(int a = 0, int b = 0): len(a), cost(b) {}
    bool operator < (const Node b) const {
        if (len != b.len)   return len > b.len;
        return cost < b.cost;      
    }
};
vector<Node>ans;
void deal(int L, int R, int idx) {
    ans.clear();
    int l = L, r;
    while (s[l] != '1' && l <= R) ++l;

    //代表这一段根本没有1
    if (l > R)  return ;

    //双指针扫描
    r = l;
    while (true) {
        while (s[r] != '0' && r <= R) ++r;

        //进行插入
        if (l == 1 || r == R || l == idx)   ans.push_back(Node(r - l, 1));
        else    ans.push_back(Node(r - l, 2));


        if (r > R) {//代表这一段全都是1
            return ;
        }
        
        l = r;
        while (s[l] != '1' && l <= R) ++l;
        //代表后面不再有1了
        if (l > R) {
            return ;
        }

        r = l;//重新设置，继续搜索
    }

}

bool check() {
    for (int i = 1; i <= len; ++i) 
    if (s[i] == '0')    return false;
}
int main() {
    while (scanf("%d%d", &len, &k) != EOF) {
        scanf("%s", s + 1);

        if (check()) {
            printf("%d\n", len);
            continue;
        }


        //特殊处理第一段1
        if (s[1] == '1') {
            
        }
        //寻找最长的那段1
        int idx, l = 1, r = 1, Max = 0;
        while (true) {
            
        }
    }
}