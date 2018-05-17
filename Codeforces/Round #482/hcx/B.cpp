#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
string ans[]={"Kuro","Shiro","Katie","Draw"};
int xa[30],xb[30],xc[30];
int da[30],db[30],dc[30];
int maxa[4];
int m,n;
const int maxn=1e5;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a,b,c;
    cin>>n>>a>>b>>c;
    m=a.length();
    for(int i=0;i<m;i++){
        if(a[i]>='a') xa[a[i]-'a']++;
        else da[a[i]-'A']++;

        if(b[i]>='a') xb[b[i]-'a']++;
        else db[b[i]-'A']++;

        if(c[i]>='a') xc[c[i]-'a']++;
        else dc[c[i]-'A']++;
    }

    for(int i=0;i<26;i++){
        maxa[0]=max(maxa[0],xa[i]);
        maxa[0]=max(maxa[0],da[i]);

        maxa[1]=max(maxa[1],xb[i]);
        maxa[1]=max(maxa[1],db[i]);

        maxa[2]=max(maxa[2],xc[i]);
        maxa[2]=max(maxa[2],dc[i]);
    }

    for(int i=0;i<3;i++){
        if(maxa[i]==m&&n==1){
            maxa[i]--;
        }
        else{
            maxa[i]+=n;
            if(maxa[i]>m) maxa[i]=m;
        }
    }
    if(maxa[0]>maxa[1]&&maxa[0]>maxa[2]) cout<<ans[0]<<endl;
    else if(maxa[1]>maxa[2]&&maxa[1]>maxa[0]) cout<<ans[1]<<endl;
    else if(maxa[2]>maxa[0]&&maxa[2]>maxa[1]) cout<<ans[2]<<endl;
    else cout<<ans[3]<<endl;
    return 0;
}
