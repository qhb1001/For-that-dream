#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
struct ty{
    bool is_boy;
    int idx;
}b[maxn];
int ans[maxn];
string s;
ll sum;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        cin>>s;
        sum=0;
        sum=1LL*(1+n)*n/2;
        if(sum&1){
            cout<<"-1"<<endl;
            continue;
        }

        for(int i=1;i<=n;i++){
            if(s[i-1]=='0'){
                b[i].is_boy=false;
            }
            else b[i].is_boy=true;
            b[i].idx=i;
//            cout<<i<<" "<<b[i].is_boy<<endl;
        }

        sum/=2;
        for(int i=n;i>=0;i--){
            if(sum>=b[i].idx){
                sum-=b[i].idx;
                if(b[i].is_boy){
                    ans[i]=4;
                }
                else{
                    ans[i]=2;
                }
            }
            else{
                if(b[i].is_boy) ans[i]=3;
                else ans[i]=1;
            }
        }
        for(int i=1;i<=n;i++){
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}
