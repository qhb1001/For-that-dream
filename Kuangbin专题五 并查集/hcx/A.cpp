#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=1e3+10;
int f[maxn],dx[maxn],dy[maxn];
int rep[maxn];
int n;
void Init(){
    for(int i=0;i<=n;i++){
        f[i]=i;
    }
}
int Find(int x){
    if(f[x]!=x)
        f[x]=Find(f[x]);
    return f[x];
}
void Union(int x,int y){
    f[x]=y;
}

double dist(int a,int b){
    return sqrt(1.0*(dx[a]-dx[b])*(dx[a]-dx[b])+1.0*(dy[a]-dy[b])*(dy[a]-dy[b]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int d;
    cin>>n>>d;
    Init();
    
    for(int i=1;i<=n;i++){
        cin>>dx[i]>>dy[i];
    }
    char c;int idx;
    cin.get();
    int len=0;
    while(cin>>c>>idx){
        if(c=='O'){
            rep[len++]=idx;
            for(int i=0;i<len-1;i++){
                if(rep[i]!=idx&&dist(rep[i], idx)<=1.0*d){
                    Union(rep[i], idx);
                }
            }
        }
        else{
            int y;cin>>y;
            if(Find(idx)==Find(y)){
                cout<<"SUCCESS"<<endl;
            }
            else{
                cout<<"FAIL"<<endl;
            }
        }
        cin.get();
    }
    return 0;
}
