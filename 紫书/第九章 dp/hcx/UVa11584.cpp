#include <iostream>
#include <cstdio>
#include <string>
#include <cstdio>
using namespace std;
const int maxn=1005;
int T,n;
string s;
bool pa[maxn][maxn];
int d[maxn];
void Init(){
    memset(pa,0,sizeof(pa));
    int l,r;
    for(int i=0;i<n;i++){
        pa[i][i]=1;
        
        l=i-1;r=i+1;
        while(l>=0&&r<n&&s[l]==s[r]){
            pa[l][r]=1;
            l--;r++;
        }
        
        l=i-1;r=i;
        while(l>=0&&r<n&&s[l]==s[r]){
            pa[l][r]=1;
            l--;r++;
        }
        
        l=i;r=i+1;
        while(l>=0&&r<n&&s[l]==s[r]){
            pa[l][r]=1;
            l--;r++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>s;
        n=s.length();
        memset(d,0x3f3f3f,sizeof(d));
        Init();
        
        for(int i=0;i<n;i++){
            if(pa[0][i]) d[i]=1;
            else{
                for(int j=0;j<i;j++){
                    if(pa[j+1][i]) d[i]=min(d[i],d[j]+1);
                }
            }
        }
        cout<<d[n-1]<<endl;
    }
    return 0;
}

