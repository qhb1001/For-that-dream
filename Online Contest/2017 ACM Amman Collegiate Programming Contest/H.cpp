#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e6+5;
char ans[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n,s;
        scanf("%d%d",&n,&s);
        if(n==1){
            if(s<=9){
                printf("%d\n",s);
            }
            else printf("-1\n");
            continue;
        }

        if(s<2||n*9<s){
            printf("-1\n");
            continue;
        }
        if(2==s){
            printf("1");
            for(int i=2;i<n;i++){
                printf("0");
            }
            printf("1\n");
            continue;
        }
        if(n*9==s){
            for(int i=1;i<=n;i++){
                printf("9");
            }
            printf("\n");
            continue;
        }
        int numNine=s/18;
        int res=s%18;
        if(res%2){
            if(n%2==0){
                printf("-1\n");
                continue;
            }

            if(numNine*2+1==n){
                for(int i=1;i<=numNine;i++)
                    printf("9");
                printf("%d",res);
                for(int i=1;i<=numNine;i++)
                    printf("9");
                printf("\n");
                continue;
            }

            for(int i=1;i<=numNine;i++)
                printf("9");
            printf("%d",(res-1)/2);
            for(int i=numNine+2;i<=n/2;i++)
                printf("0");
            printf("1");
            for(int i=0;i<=n/2-numNine-2;i++)
                printf("0");
            printf("%d",(res-1)/2);
            for(int i=1;i<=numNine;i++)
                printf("9");
        }
        else{
            if(numNine*2+1==n){
                for(int i=1;i<=numNine;i++)
                    printf("9");
                printf("%d",res);
                for(int i=1;i<=numNine;i++)
                    printf("9");
                printf("\n");
                continue;
            }

            for(int i=1;i<=numNine;i++)
                printf("9");
            printf("%d",res/2);
            for(int i=0;i<n-2*(numNine+1);i++)
                printf("0");
            printf("%d",res/2);
            for(int i=1;i<=numNine;i++)
                printf("9");
        }
        printf("\n");
    }
    return 0;
}
