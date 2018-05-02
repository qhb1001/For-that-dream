#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,h;
int lh=0,lm=0;
int nh,nm;
bool judge(){
    int res=nm-lm+(nh-lh)*60;
    if(res>=2*h+2){
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>h;
    bool flag=false;
    cin>>lh>>lm;
    if(lm+lh*60>=h+1){
        flag=true;
        cout<<0<<" "<<0<<endl;
        return 0;
    }
    for(int i=1;i<n;i++){
        cin>>nh>>nm;
        if(judge()){
            flag=true;
            break;
        }
        lh=nh;lm=nm;
    }
    nm=lm+h+1;
    nh=nm/60+lh;
    nm%=60;
    cout<<nh<<" "<<nm<<endl;
    return 0;
}
