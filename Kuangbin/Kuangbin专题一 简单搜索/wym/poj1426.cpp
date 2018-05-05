#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
int flag;
void dfs(unsigned long long t,int n,int k){
    if(flag){
        return;
    }
    if(t%n==0){
        cout<<t<<endl;
        flag=1;
        return;
    }
    if(k==19){
        return;
    }
    dfs(t*10,n,k+1);
    dfs(t*10+1,n,k+1);
}
int main(){
    int n;
    while(~scanf("%d",&n) && n){
        flag = 0;
        dfs(1,n,0);
    }
    return 0;
}
