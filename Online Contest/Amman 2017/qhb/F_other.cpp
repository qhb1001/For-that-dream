#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef pair<int,int> P;
priority_queue<P,vector<P> >Q;
const int N=500010;
int T,n,k,a[N],nxt[N],lst[N];
bool inq[N];
int main(){
	//freopen("input", "r", stdin);
	//freopen("output.a", "w", stdout);
    scanf("%d",&T);
    while(T--){
        int cnt=0,ans=0;
        scanf("%d%d",&n,&k);
        map<int,int> M;
        for(int i=1;i<=n;i++)lst[i]=n+1;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(!M.count(a[i]))M[a[i]]=++cnt;
            inq[M[a[i]]]=0;
        }
        for(int i=1;i<=n;i++)a[i]=M[a[i]];
        while(!Q.empty())Q.pop();
        for(int i=n;i;i--)nxt[i]=lst[a[i]],lst[a[i]]=i;
        for(int i=1;i<=n;i++){
            if(inq[a[i]]){Q.push(make_pair(nxt[i],a[i]));continue;}
            if(k){ans++;Q.push(make_pair(nxt[i],a[i]));inq[a[i]]=1;k--;}
            else{
                while(!inq[Q.top().second])Q.pop();
                inq[Q.top().second]=0; Q.pop();
                ans++; Q.push(make_pair(nxt[i],a[i]));
                inq[a[i]]=1;
            }
        }printf("%d\n",ans);
    }return 0;
}
