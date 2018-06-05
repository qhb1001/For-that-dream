// 可以看出题目其实就是让你求有多少对哑铃片，每一片哑铃只能用一次且这一对重量相同。
// 最多只可能有14个哑铃片，因此我们可以用二进制进行枚举，假设二进制是 101011(高->低)，那么表示1,2,4,6号哑铃片被选中了；
// 这样的话最多 2^14种重量，接下来我们只需要判断一下相同重量的方案是不是满足每种哑铃片只用了一次。
// eg: 假设 1001和1100构成的重量是相同的，但是它们都选择了4号哑铃片，所以这种情况是不满足题意的，只有 1001和 0110这种情况满足；
// 可见判断标准就是看两个方案的二进制数的按位与操作的结果是不是0，是的话表示满足，不是的话表示有重复使用，则不满足。
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a;i <= b;++ i)
#define per(i,a,b) for(int i = a;i >= b;-- i)
#define mem(a,b) memset((a),(b),sizeof((a)))
#define FIN freopen("in.txt","r",stdin)
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define pb push_back
typedef long long LL;
typedef pair<int, LL> PIR;
const int N = (1<<16);

int n, m;
LL a[20], b[20];
vector <LL> ans, ANS;
map <LL, bool> vis, VIS;
struct Node{
    int bt;
    LL val;
    bool operator < (const Node &r) const   { return val < r.val; }
}node[N];

bool judge(int i, int j){
    int a = node[i].bt, b = node[j].bt;
    if(a&b) return false;
    return true;
}
int main()
{IO;
    //FIN;
    cin >> n >> m;
    rep(i, 1, n)    cin >> a[i];
    rep(i, 1, m)    cin >> b[i];

    rep(i, 0, ((1<<m)-1)){
        int bit = i, p = 1;
        LL res = 0;
        while(bit){
            if(bit&1)   res += b[p];
            p++; bit >>= 1;
        }
        node[i].val = res;
        node[i].bt = i;
    }
    sort(node, node+(1<<m));
    int i = 0;
    while(i < (1<<m)){
        int j = i+1;
        if(vis[node[i].val])    { i++; continue; }
        while(j < (1<<m)){
            if(node[i].val != node[j].val)  break;
            if(judge(i, j)){
                if(!vis[node[i].val]) ans.pb(node[i].val);
                vis[node[i].val] = true;
            }
            j++;
        }
        i++;
    }
    //rep(i, 0, (int)ans.size()-1)    cout << ans[i] << " ";
    rep(i, 1, n){
        if(!VIS[a[i]])  ANS.pb(a[i]);
        VIS[a[i]] = true;
        rep(j, 0, (int)ans.size()-1){
            LL res = a[i]+ans[j]*2;
            if(!VIS[res]) ANS.pb(res);
            VIS[res] = true;
        }
    }
    sort(ANS.begin(), ANS.end());
    rep(i, 0, (int)ANS.size()-1)    cout << ANS[i] << endl;
    return 0;
}
