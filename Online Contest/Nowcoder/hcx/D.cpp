#include <iostream>
#include <cstdio>
using namespace std;
int get_length(int k){
    int ans=0;
    while(k){
        ans++;
        k/=10;
    }
    return ans;
}
int main(){
    int k,n,d;
    scanf("%d%d%d",&k,&n,&d);
    int k_l=get_length(k);
    if(k_l<=n){
        int ans=1;
        for(int i=0;i<n;i++){
            int x;scanf("%d",&x);
            ans*=x;
        }
        if(ans%k==d){
            printf("1\n");
        }
        else printf("0\n");
        return 0;
    }


}
