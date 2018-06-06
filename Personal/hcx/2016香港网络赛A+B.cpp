#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
struct complex{
    double r,i;
    complex(double _r = 0,double _i = 0){
        r = _r; i = _i;
    }
    complex operator +(const complex &b){
        return complex(r+b.r,i+b.i);
    }
    complex operator -(const complex &b){
        return complex(r-b.r,i-b.i);
    }
    complex operator *(const complex &b){
        return complex(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};
void change(complex y[],int len){
    for(int i=1,j=len/2;i<len-1;i++){
        if(i<j) swap(y[i],y[j]);
        int k = len/2;
        while( j >= k){
            j -= k;
            k /= 2;
        }if(j < k) j += k;
    }
}
void fft(complex y[],int len,int on){
    change(y,len);
    for(int h = 2; h <= len;h <<= 1){
        complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j += h){
            complex w(1,0);
            for(int k = j;k < j+h/2;k++){
                complex u = y[k];
                complex t = w*y[k+h/2];
                y[k] = u + t;
                y[k + h/2] = u - t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
}
const int maxn = 400040;	//2倍长度
const int M =50000;          // a数组所有元素+M，使a[i]>=0
complex x1[maxn];
int a[maxn/2];
ll num[maxn];
ll sum[maxn];
ll tt[maxn];        //统计数组每个元素出现个数
int main(){
    int n=0,m;cin >> m;
    memset(num,0,sizeof(num));
    memset(tt,0,sizeof(tt));//
    int cnt0 = 0,aa;
    for(int i = 0;i < m;i++){
        cin >> aa;
        if(aa==0) {cnt0++;continue;}
        else a[i] = aa;
        num[a[n]+M]++;
        tt[a[n]+M]++;
        n++;
    }
    sort(a,a+n);
    int len1 = a[n-1]+M+1;
    int len = 1;
    while(len < 2 * len1) len <<= 1;
    for(int i = 0;i < len1;i++)
        x1[i] = complex(num[i],0);
    for(int i = len1;i < len;i++){
        x1[i] =complex(0,0);
    }
    fft(x1,len,1);
    for(int i = 0;i < len;i++){
        x1[i] = x1[i]*x1[i];
    }
    fft(x1,len,-1);
    for(int i = 0;i < len;i++)
        num[i] = (ll)(x1[i].r + 0.5);
    len = 2 * (a[n-1]+M);
    for(int i = 0;i < n;i++) num[a[i] + a[i]+2*M]--;////减掉取两个相同的组合
    
    long long ret= 0;
    int l=a[n-1]+M;
    for(int i = 0;i <=l; i++){   //ai,aj,ak都不为0的情况
        if(tt[i]) ret+=(long long)(num[i+M]*tt[i]);//无零的时候的可能性
    }
    
    ret+=(long long)(num[2*M]*cnt0);        // ai+aj=0的情况
    
    if(cnt0!=0){
        if(cnt0>=3) {                   //ai,aj,ak都为0的情况
            long long tmp=1;
            tmp*=(long long)(cnt0);
            tmp*=(long long)(cnt0-1);
            tmp*=(long long)(cnt0-2);
            ret+=tmp;
        }
        for(int i = 0;i <=l; i++){
            if(tt[i]>=2){             // x+0=x的情况
                long long tmp=(long long)cnt0;
                tmp*=(long long)(tt[i]);
                tmp*=(long long)(tt[i]-1);
                ret+=tmp*2;
            }
        }
    }
    cout<<ret<<endl;
    return 0;
}
