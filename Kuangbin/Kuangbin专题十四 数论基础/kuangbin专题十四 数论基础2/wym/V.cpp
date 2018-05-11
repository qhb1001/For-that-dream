#include<cstdio>  
#include<iostream>  
#include<sstream>  
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;  
int num[100], n;  
string s;  
int gcd(int a, int b){  
    return b ? gcd(b, a % b) : a;  
}  
  
int cal(){  
    int i, j, maxn = 0;  
    for (i = 0; i < n - 1; i++)  
        for (j = i + 1; j < n; j++)  
            maxn = max(maxn, gcd(num[i], num[j]));  
    return maxn;  
}  
  
int main()  {  
    int t;  
    scanf("%d\n", &t);  
    while (t--)  {  
        getline(cin, s);  
        stringstream ss(s);  
        n = 0;  
        while (ss >> num[n])  
            n++;  
        printf("%d\n", cal());  
    }  
    return 0;  
}
