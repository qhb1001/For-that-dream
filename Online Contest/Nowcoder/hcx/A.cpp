#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
vector<int>alp[30];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    int n=s.length();
    for(int i=0;i<n;i++){
        alp[s[i]-'a'].push_back(i);
    }
    int now=-1;
    string ans="";
    for(int i='z'-'a';i>=0;i--){
        int m=alp[i].size();
        int j=0;
        while(j<m&&alp[i][j]<=now) j++;
        if(j==m) continue;
        j=m-j;
        now=alp[i][m-1];
        while(j--) ans+=(char)(i+'a');
    }
    cout<<ans<<endl;
    return 0;
}
