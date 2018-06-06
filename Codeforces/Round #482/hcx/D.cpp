#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,r,l) for(int i=r;i>=l;i--)
const int MAXN=1e5+10;
const int NM=200*MAXN;
const int inf=1e9;
using namespace std;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return f*x;
}
int d[NM][2],rt[MAXN],cnt;
int maxx[NM];
int str[21],mu[21];
int newnode(){
    cnt++;d[cnt][0]=d[cnt][1]=0;maxx[cnt]=inf;
    return cnt;
}
void zh(int x){
    for(int i=0;i<20;i++){
        if(x&(1<<(19-i))) str[i]=1;
        else str[i]=0;
    }
}
void insert(int root,int vul){
    int temp=root;
    for(int i=0;i<20;i++){
        int t=str[i];
        if(!d[temp][t]) d[temp][t]=newnode();
        temp=d[temp][t];
    }
    maxx[temp]=vul;temp=root;
    for(int i=0;i<20;i++){
        int t=str[i];
        temp=d[temp][t];
        maxx[temp]=min(maxx[temp],vul);
    }
    maxx[root]=min(vul,maxx[root]);
    //    cout<<maxx[root]<<" "<<root<<endl;
}
int ans1;
void querty(int x,int vul,int num){
    if(maxx[d[x][0]]==inf&&maxx[d[x][1]]==inf){ans1=maxx[x];return ;}
    if(maxx[d[x][0]]==inf&&maxx[d[x][1]]<=vul){querty(d[x][1],vul,num+1);}
    else if(maxx[d[x][1]]>vul){querty(d[x][0],vul,num+1);}
    else{
        if(str[num]) querty(d[x][0],vul,num+1);
        else querty(d[x][1],vul,num+1);}
}
void operator1(int x){
    zh(x);
    for(int i=1;i*i<=x;i++){
        if(x%i==0) insert(rt[i],x),insert(rt[x/i],x);
    }
}
int main(){
    int n;n=read();
    mu[0]=1;maxx[0]=inf;
    for(int i=1;i<20;i++) mu[i]=mu[i-1]<<1;
    for(int i=1;i<=100000;i++) rt[i]=newnode();
    int op,u,x,k,s;
    for(int i=1;i<=n;i++){
        op=read();
        if(op==1) u=read(),operator1(u);
        else{
            x=read();k=read();s=read();ans1=0;
            if(x%k!=0||s<=x||maxx[rt[k]]>(s-x)){
                puts("-1");continue;
            }
            zh(x);
            querty(rt[k],s-x,0);
            printf("%d\n",ans1);
        }
    }
    return 0;
}

