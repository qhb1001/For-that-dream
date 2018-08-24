#include <iostream>
#include <cstring>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
struct Mat{
    int row, col;
    ll N[25][25];
    Mat(int row = 0 , int col = 0){
        memset(N, 0, sizeof(N));
        this -> row = row;
        this -> col = col;
    }
    Mat operator * (const Mat B) const {
        Mat A(row, B.col);
        for(int i = 0 ;i < row; i ++)
            for(int k = 0 ; k < col; k ++)
                for(int j = 0 ; j < B.col; j++){
                    A.N[i][j] = (A.N[i][j] + N[i][k] * B.N[k][j] % mod + mod) % mod; 
                }
        return A;
    }
    Mat operator ^ (int x) const {
        Mat A(row,row) , temp = *this;
        for(int i = 0 ; i < row; i ++)  A.N[i][i] = 1;
        while(x){
            if(x & 1)   A = A * temp;
            temp = temp * temp;
            x>>= 1;
        }
        return A;
    }
};


ll A, B, C, D, p, n;
void input() {
    scanf("%lld%lld%lld%lld%lld%lld", &A, &B, &C, &D, &p, &n);
}

ll kpow(ll a,ll b){
    ll ans=1,base=a;
    while(b){
        if(b&1) ans*=base,ans%=mod;
        base=base*base%mod;
        b>>=1;
    }
    return ans;
}
ll fun(ll b,ll c,ll a1,ll cnt){
    if(b==1){
        return (a1+(cnt-1)*c%mod+mod)%mod;
    }else{
        ll tmp=kpow(b,cnt-1);
        return a1*tmp+c*(tmp-1)/(b-1);
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        input();
        Mat f1(2, 2), f2(2, 1);
        f1.N[0][0] = D; f1.N[0][1] = C; f1.N[1][0] = 1;
        f2.N[0][0] = B; f2.N[1][0] = A;

        Mat x1 = f1, x2(2, 1);
        x2.N[0][0] = p / 3;
        x2.N[1][0] = p / 2;

        if (n == 1) printf("%lld\n", A);
        else if (n == 2) printf("%lld\n", B);
        else if (n == 3) printf("%lld\n", (D * A + C * B + p / 3 + mod) % mod);
        else {
            long double y=(D+C)/2.0,x=(D-C)/2.0;
            int cnt;
            int l=3,b=floor(p/3.0),r=p/b;
            ll a1=A,a2=B; 
            while(r!=1){
                cnt=r-l+1;
                long double a11=a1-x*a2;
                ll b2=fun(Y,b,a11,cnt);
                a1=fun(x,b2,a1,cnt-1);
                a2=fun(x,b2,a1,cnt);

            }
        }
    }
}