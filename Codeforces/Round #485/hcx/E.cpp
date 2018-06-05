#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
ll a[maxn],tmp[maxn];
int n;
ll ans=0;
void Merge(int l,int m,int r){
    int i=l,j=m+1,k=l;
    while(i<=m&&j<=r){
        if(a[i]>a[j]){
            tmp[k++]=a[j++];
            ans+=m-i+1;
        }else{
            tmp[k++]=a[i++];
        }
    }
    while(i<=m) tmp[k++]=a[i++];
    while(j<=r) tmp[k++]=a[j++];

    for(int x=l;x<=r;x++)
        a[x]=tmp[x];
}

void Merge_sort(int l,int r){
    if(l<r){
        int m=1LL*(l+r)/2;
        Merge_sort(l, m);
        Merge_sort(m+1, r);
        Merge(l, m, r);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    Merge_sort(0,n-1);
    if(ans%2==(3*n%2)){
        cout<<"Petr"<<endl;
    }
    else{
        cout<<"Um_nik"<<endl;
    }
    return 0;
}
