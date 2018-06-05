#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>

using namespace std;
typedef    long long ll;
int base=100000000,width=8;
struct Bign{
    int len;
    ll N[500];
    Bign (){len=0;memset(N,0,sizeof(N));}
    Bign (ll t){*this =t;}
    Bign (char *t){*this =t;}

    int trans(char *a,int begin,int end){
        int sum=0;
        for(int i=begin;i<end;i++)
            sum=sum*10+a[i]-'0';
        return sum;
    }
    ll trans(Bign A){
        ll now = 0;
        int idx = 10;
        while(A.N[idx] == 0)    idx--;
        while(idx != -1)    now = 1LL * now * base + A.N[idx--];
        return now;
    }
    int get_num(ll x) const {
        int ans=0;
        while(x){
            ans++;x/=10;
        }
        return ans;
    }
    Bign operator =( ll x){
        len=0;
        memset(N,0,sizeof(N));
        while(x){
            N[len++]=x%base;
            x/=base;
        }
        return *this;
    }

    Bign operator =(char *a){
        int flag=0;
        if(a[0]=='-')  { a=a+1;flag=1;}
        int L=strlen(a);
        len=(L-1)/width+1;
        memset(N,0,sizeof(N));
        for(int i=0;i<len;i++){
            int end=L-width*i;
            int start=max(0,end-width);
            N[i]=trans(a,start,end);
        }
        if(flag){N[len-1]*=-1;}
        return *this;
    }

    void clear(){
        while(len>1&&N[len-1]==0)  len--;
        for(int i=0;i<len-1;i++)
            if(N[i]<0)  N[i]=-N[i];
    }

    Bign operator + (const Bign B)const {
        Bign C;
        C.len=max(len,B.len)+10;
        for(int i=0;i<C.len;i++)
            C.N[i]+=N[i]+B.N[i],C.N[i+1]+=C.N[i]/base,C.N[i]%=base;

        C.clear();
        return C;
    }

    Bign operator - (const Bign B) const {
        Bign C;
        int flag=0;
        if(len>=B.len){
            C=*this;
            C.len=len;
            for(int i=0;i<C.len;i++){
                if(C.N[i]<B.N[i]&&i<len-1){C.N[i]+=base;C.N[i+1]--;}
                C.N[i]-=B.N[i];
            }}
        else {
            C=B;
            C.len=B.len;
            flag=1;
            for(int i=0;i<C.len;i++){
                if(C.N[i]<N[i]){C.N[i]+=base;C.N[i+1]--;}
                C.N[i]-=N[i];
            }
        }
        C.clear();
        if(flag)    C.N[C.len-1]=-C.N[C.len-1];
        return C;
    }

    Bign operator * (const Bign B) const {
        Bign C;

        C.len=len+B.len;
        for(int i=0;i<len;i++)
            for(int j=0;j<B.len;j++)
                C.N[i+j]+=N[i]*B.N[j];

        for(int i=0;i<C.len;i++)
            C.N[i+1]+=C.N[i]/base,C.N[i]%=base;
        C.clear();
        return C;
    }

    Bign operator / ( ll b) const {
        Bign F=*this,C;

        for(int i=len-1;i>=0;i--){

            for(int j=C.len-1;j>=0;j--) C.N[j+1]=C.N[j],C.N[j]=0;
            C.len++;

            ll t=F.N[i]/b;
            Bign T=t;
            if(i!=0)    F.N[i-1]+=(F.N[i]-t*b)*base;
            C=C+T;
        }
        C.clear();
        return C;
    }
    Bign operator % ( ll &b)const {
        Bign r=*this/b,C=*this-r*b;
        return C;
    }

}num[305];
void Print(Bign A){
    printf("%lld",A.N[A.len-1]);
    for(int i=A.len-2;i>=0;i--)
        printf("%08lld",A.N[i]);
}
int n;
void Init(){
    num[1]=2;num[2]=9;
    Bign deta=97;
    Bign d=16;
    for(int i=3;i<=103;i++){
        if(i%2==1){
            num[i]=num[i-1]*4+2;
//            Print(num[i]);
//            printf("i \n");
        }
        else{
            num[i]=num[i-1]+deta;
            deta=d*deta-15;
//            Print(num[i]);
//            printf("i \n");
        }
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    scanf("%d",&n);
    n/=3;
    Print(num[n]);
    printf("\n");
}
