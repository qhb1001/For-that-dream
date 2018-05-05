#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
bool isprime[10000];
bool vis[10000];
string a, b;
struct number {
    string num;
    int step;
    number(string num, int step): num(num), step(step) {}
};
void shai() {
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    int n=9999;
    for(int i=2; i<n; ++i)
        if(isprime[i])
            for(int j=i*i; j<=n; j+=i) isprime[j] = false;
    return;
}
void solve() {
    int ans = 1<<29;
    memset(vis, false, sizeof(vis));
    queue<number> q;
    q.push(number(a, 0));
    while(!q.empty()) {
        number p = q.front(); q.pop();
        if(p.num == b) {
            ans = p.step;
            break;
        }
        for(int i=3; i>=0; --i) { 
            int jbegin = i==0?1:0;
            string c = p.num;
            for(int j=jbegin; j<=9; ++j) {
                c[i] = j+'0';
                int next = atoi(c.c_str());
                if(!vis[next] && isprime[next] && c!=p.num) {
                    vis[atoi(c.c_str())] = true;
                    q.push(number(c, p.step+1));
                }
            }
        }
    }
    cout << ans << endl;
}
int main(){
    shai();
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        solve();
    }
    return 0;
}
