#include<cstdio>  
#include<algorithm>
#include<cmath>
#include<iostream>
int a[16005];  
int main()  {  
    for(int i=2; i<=800 ;i++){  
        if(a[i]==1)continue;  
        for(int j=i+i; j<=16000; j=j+i)  
            a[j]=1;  
    }  
    a[1]=a[2]=1;  
    int kase = 0;
    int t;
    while(scanf("%d",&t),t>0)  {  
        if(a[t]==0)  
            printf("%d: yes\n",++kase);  
        else printf("%d: no\n",++kase);  
    }  
    return 0;  
} 
