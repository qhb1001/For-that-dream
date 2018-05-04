//POJ 3126
#include <iostream>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
const int maxn=1e4+10;
int step[maxn];
bool flag[maxn];
set<int>ss;
bool check(int n){
    if(!(n%2)) return false;
    for(int i=3;i*i<=n;i+=2){
        if(!(n%i)) return false;
    }
    return true;
}
void bfs(int x,int y){
    queue<int>q;
    q.push(x);
    step[x]=0;
    while(!q.empty()){
        int tmp=q.front();
        q.pop();

        int next;
        for(int i=0;i<=9;i++){
            next=tmp/10*10+i;
//            cout<<next<<endl;
            if(next==tmp||!flag[next]||step[next]) continue;
            q.push(next);
            step[next]=step[tmp]+1;
            if(next==y){
                cout<<step[next]<<endl;
                return ;
            }
        }

        for(int i=0;i<=9;i++){
            next=(tmp/100*10+i)*10+tmp%10;
            if(next==tmp||!flag[next]||step[next]) continue;
//            cout<<next<<endl;
            q.push(next);
            step[next]=step[tmp]+1;
            if(next==y){
                cout<<step[next]<<endl;
                return ;
            }
        }

        for(int i=0;i<=9;i++){
            next=(tmp/1000*10+i)*100+tmp%100;
            if(next==tmp||!flag[next]||step[next]) continue;
//            cout<<next<<endl;
            q.push(next);
            step[next]=step[tmp]+1;
            if(next==y){
                cout<<step[next]<<endl;
                return ;
            }
        }

        for(int i=1;i<=9;i++){
            next=i*1000+tmp%1000;
            if(next==tmp||!flag[next]||step[next]) continue;
//            cout<<next<<endl;
            q.push(next);
            step[next]=step[tmp]+1;
            if(next==y){
                cout<<step[next]<<endl;
                return ;
            }
        }
    }
}

int main(){
    for(int i=1000;i<10000;i++){
        if(check(i)){
            flag[i]=1;
        }
    }
    int n;cin>>n;
    while(n--){
        int x,y;cin>>x>>y;
        memset(step, 0, sizeof(step));
        if(x<y) bfs(x, y);
        else if(x==y) cout<<0<<endl;
        else bfs(y,x);
    }
    return 0;
}

