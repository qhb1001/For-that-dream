#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
int alph[30];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--){
        string s,ss;
        cin>>s>>ss;
        memset(alph, 0, sizeof(alph));
        int n=ss.length();
        for(int i=0;i<n;i++){
            alph[ss[i]-'a']++;
        }

        n=s.length();
        int i;
        for(i=0;i<n;i++){
            if(alph[s[i]-'a']){
                alph[s[i]-'a']--;
            }
            else{
                break;
            }
        }
        cout<<i<<endl;
    }
    return 0;
}
