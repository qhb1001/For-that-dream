#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn=20;//16
vector<int>one[17];
int two[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};
int ans;

int main(){
    int n;
    scanf("%d",&n);
    ll tmp=0;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        tmp=tmp|x;
        int j=16;
        while(two[j]>x&&j>=0)j--;
        for(;j>=0;j--){
            if(two[j]>x) continue;
            one[j].push_back(i);
            x-=two[j];
            if(!x) break;
        }
    }
    ans=0;
    for(int i=0;i<16;i++){

    }
}
