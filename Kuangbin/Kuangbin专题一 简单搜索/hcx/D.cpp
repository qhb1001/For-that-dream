//POJ 3279
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=20;
const int INF=0x3f3f3f3f;
int a[maxn][maxn],b[maxn][maxn];
int t[maxn][maxn],ans[maxn][maxn];
int tnum,anum;
int m,n;
void change(int x,int y){
    tnum++;
    t[x][y]=1;
    b[x][y]=1-b[x][y];
    b[x-1][y]=1-b[x-1][y];
    b[x+1][y]=1-b[x+1][y];
    b[x][y-1]=1-b[x][y-1];
    b[x][y+1]=1-b[x][y+1];
}

void check(){
    if(tnum>=anum) return ;
    int j;
    for(j=1;j<=n;j++){
        if(b[m][j]) break;
    }
    if(j<=n) return ;

    anum=tnum;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            ans[i][j]=t[i][j];
        }
    }
}

int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }

    anum=INF;
    int times=1<<n;
    for(int k=0;k<times;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                b[i][j]=a[i][j];
            }
        }

        tnum=0;
        memset(t, 0, sizeof(t));

        int tmp=k;
        for(int j=1;j<=n;j++){
            if(tmp&1) change(1, j);
            tmp=tmp>>1;
        }

        for(int i=2;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(b[i-1][j]) change(i,j);
            }
        }

        check();
    }
    if(anum==INF){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(j==1) cout<<ans[i][j];
                else cout<<" "<<ans[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
