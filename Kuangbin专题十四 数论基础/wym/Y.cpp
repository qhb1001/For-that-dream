#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int phi[1000005];
void solve(){
    memset(phi,0,sizeof(phi));
    for(int i=2;i<=1000000;i++){
        if (!phi[i]){
            for (int j=i; j<=1000000; j+=i){
                if (phi[j]==0)
                    phi[j]=j;
                phi[j]=phi[j]-phi[j]/i;
            }
        }
    }
}
int main()
{
    int n;
    solve();
    while (cin>>n)
    {
        if(n==0) break;
        ll sum = 0 ;
        for (int i=2;i<=n;i++)
            sum+=phi[i];
        cout<<sum<<endl;
    }
    return 0;
}
