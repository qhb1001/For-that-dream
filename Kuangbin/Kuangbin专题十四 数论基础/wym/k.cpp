#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 205;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char a[maxn];
        int b;
        scanf("%s%d",a,&b);
        int len = strlen(a);
        b = b < 0 ? -b : b;
        if(a[0] == '0'){
            printf("divisible\n");
            continue;
        }
        int ans = 0;
        for(int i = 0; i<len; i++){
            if(i == 0 && a[0] == '-')   continue;
            ans = (ans*10 + a[i]-'0')%b;
        }
        if(ans == 0){
            puts("divisible");
        }
        else{
            puts("not divisible");
        }
    }
    return 0;
}
