#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int n, s;
const int maxn = 1e6 + 5;
int check(int a, int b){
    if(a&1){
        if(b&1){
            for(int i=1; i<=9; i+=2){
                int sum, count;
                sum = b - i;
                if(sum < 2 || sum > 9*(a-1)){
                    continue;
                }
                else{
                    return i;
                }
            }
        }
        else{
            for(int i=0; i<=8; i+=2){
                int sum, count;
                sum = b - i;
                if(sum < 2 || sum > 9*(a-1)){
                    continue;
                }
                else{
                    return i;
                }
            }
        }
    }
    else{
        if(b&1){
            return -1;
        }
        if(b<2 || b>9*a){
            return -1;
        }
        else{
            return -2;
        }
    }
    return -1;
}
int main(){
	freopen("input", "r", stdin);
	freopen("output.a", "w", stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&s);
        int flag = check(n,s);
        if(flag==-1){
            printf("-1\n");
        }
        else if(flag==-2){
            int mod, count;
            int sum = s / 2;
            count = sum / 9;
            mod = sum%9;
            for(int i=0; i<count; i++){
                printf("9");
            }
            printf("%d%d",mod,mod);
            for(int i=0; i<count; i++){
                printf("9");
            }
            printf("\n");
        }
        else{
            int mod, count;
            int sum = s - flag;
            sum /= 2;
            count = sum / 9;
            mod = sum%9;
            for(int i=0; i<count; i++){
                printf("9");
            }
            printf("%d%d%d",mod,flag,mod);
            for(int i=0; i<count; i++){
                printf("9");
            }
            printf("\n");
        }
    }
    return 0;
}
