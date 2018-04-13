#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    ll ans=0;
    ll tmp=0;
    int bef=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='.'){
            if(bef==0){
                if(b>0){
                    b--;
                    ans++;
                    bef=1;
                }
                else{
                    bef=-1;
                }
            }
            else if(bef==1){
                if(a>0){
                    a--;
                    ans++;
                    bef=0;
                }
                else{
                    bef=-1;
                }
            }
            else{
                if(a<=b&&b){
                    b--;
                    ans++;
                    bef=1;
                }
                else if(b<a&&a){
                    a--;
                    ans++;
                    bef=0;
                }
                else{
                    break;
                }
            }
        }
        else
            bef=-1;
    }
    cout<<ans<<endl;
    return 0;
}
