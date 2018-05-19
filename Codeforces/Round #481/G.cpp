#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=105;
int n,m;
struct ty{
    int s,d,c,idx;
}Node[maxn];
bool cmp(ty a,ty b){
    return a.d<b.d;
}
int ans[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>Node[i].s>>Node[i].d>>Node[i].c;
        Node[i].idx=i;
        ans[Node[i].d]=m+1;
    }
    sort(Node+1,Node+1+m,cmp);
    bool flag=false;
    for(int i=1;i<=m;i++){
        int now=Node[i].s;
        int cnt=0;
        while(cnt<Node[i].c&&now<Node[i].d){
            if(ans[now]==0){
                ans[now]=Node[i].idx;
                cnt++;
            }
            now++;
        }
        if(cnt<Node[i].c){
            flag=true;
            break;
        }
    }
    if(flag) cout<<-1<<endl;
    else{
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

