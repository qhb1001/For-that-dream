#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
string s;
int d[105][105];
int T,n;
bool Match(char a,char b){
    if(a=='['&&b==']')return true;
    if(a=='('&&b==')')return true;
    return false;
}
void dp(){
    for(int i=0;i<n;i++){
        d[i+1][i]=0;
        d[i][i]=1;
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            d[i][j]=n;
            if(Match(s[i], s[j])) {
                d[i][j]=min(d[i][j],d[i+1][j-1]);
            }
            for(int k=i;k<j;k++){
                d[i][j]=min(d[i][j],d[i][k]+d[k+1][j]);
            }
        }
    }
}

void print(int i,int j){
    if(i>j)return ;
    if(i==j){
        if(s[i]=='('||s[i]==')') cout<<"()";
        else cout<<"[]";
        return ;
    }
    int ans=d[i][j];
    if(Match(s[i], s[j])&&ans==d[i+1][j-1]){
        cout<<s[i];
        print(i+1,j-1);
        cout<<s[j];
        return ;
    }
    for(int k=i;k<j;k++){
        if(ans==d[i][k]+d[k+1][j]){
            print(i,k);
            print(k+1,j);
            return ;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>T;
    cin.get();
    while(T--){
        getline(cin, s);
        getline(cin,s);
        n=s.length();
        dp();
        print(0,n-1);
        cout<<endl;
        if(T) cout<<endl;
    }
    return 0;
}
