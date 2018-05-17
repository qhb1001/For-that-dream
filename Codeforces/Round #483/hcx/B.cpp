#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string s[105];
int cnt[105][105];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='*'){
                if(i!=0) cnt[i-1][j]++;
                if(j!=0) cnt[i][j-1]++;
                if(i!=(n-1)) cnt[i+1][j]++;
                if(j!=(m-1)) cnt[i][j+1]++;
                if(i!=0&&j!=0) cnt[i-1][j-1]++;
                if(i!=0&&j!=(m-1)) cnt[i-1][j+1]++;
                if(i!=(n-1)&&j!=(m-1)) cnt[i+1][j+1]++;
                if(i!=(n-1)&&j!=0) cnt[i+1][j-1]++;
            }
        }
    }
    bool flag=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='.'&&cnt[i][j]!=0){
                flag=true;
                break;
            }
            if('1'<=s[i][j]&&s[i][j]<='8'){
                if(cnt[i][j]!=(s[i][j]-'1'+1)){
                    flag=true;
                    break;
                }
            }
        }
        if(flag) break;
    }
    if(flag) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}
