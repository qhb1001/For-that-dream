#include <iostream>
#include <string>
using namespace std;
string s;
int n,cnt=0;
bool flag=false;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>s;
    if(n==1){
        if(s[0]=='0')
            flag=true;
    }
    if(s[0]==s[1]&&s[0]=='0')
        flag=true;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            if(i<n-1&&s[i+1]=='1'){
                flag=true;
                break;
            }
            cnt=0;
        }
        else if(s[i]=='0'){
            cnt++;
            if(cnt==3){
                flag=true;
                break;
            }
        }
    }
    if(cnt==2) flag=true;
    if(flag) cout<<"No\n";
    else cout<<"Yes\n";
    return 0;
}
