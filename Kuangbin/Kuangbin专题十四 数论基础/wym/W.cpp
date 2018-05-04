#include <cstdio>
#include <cstring>
int prime(int n){
    int i;
    for(i=2;i*i<=n;i++)
    {
        if((n%i)==0)
            return 0;
    }
    return 1;
}
int main()
{
    int num[10010];
    int i;
    int a,b;
    int sum;
    memset(num,0,sizeof(num));
    for(i=0;i<=10005;i++)
        num[i]=prime(i*i+i+41);
    while(~scanf("%d%d",&a,&b)){
        sum=0;
        for(i=a;i<=b;i++)
            sum+=num[i];
        printf("%.2f\n",sum*1.0/(b-a+1)*100+1e-6);
    }
    return 0;
}
