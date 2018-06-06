#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    int len=s.length();
    int len1=0,len2=0;
    for(int i=0;i<len;i++){
        if(s[i]=='-') len1++;
        else len2++;
    }
    if(!len2||len1%len2==0) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
