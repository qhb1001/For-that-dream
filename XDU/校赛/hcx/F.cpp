#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn=5e4+10;
int a[maxn],lst[maxn],nxt[maxn],inque[maxn];
int n,m,q;
priority_queue<pair<int,int>,vector<pair<int,int> > >p;
int main(){
    while(scanf("%d%d%d",&n,&m,&q)!=EOF){
        while(!p.empty()) p.pop();
        memset(inque,0,sizeof(inque));
        for(int i=0;i<q;i++){
            scanf("%d",&a[i]);
            lst[i]=q;
            nxt[i]=0;
        }
        for(int i=q-1;i>=0;i--){
            nxt[i]=lst[a[i]];
            lst[a[i]]=i;
        }
        int ans=0;
        for(int i=0;i<q;i++){
            if(inque[a[i]]){
                p.push(make_pair(nxt[i], a[i]));
                continue;
            }

            if(n){
                n--;
                ans++;
                inque[a[i]]=1;
                p.push(make_pair(nxt[i], a[i]));
            }
            else{
                ans++;
                while(!inque[p.top().second]) p.pop();
                inque[p.top().second]=0;
                p.pop();
                inque[a[i]]=1;
                p.push(make_pair(nxt[i], a[i]));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
