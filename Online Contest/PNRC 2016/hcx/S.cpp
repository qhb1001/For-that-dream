#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
string s[55];
int a[55];
int n,m;
void deal(){
    for(int j=0;j<m;j++){
        for(int i=n-1;i>=1;i--){
            if(s[i][j]=='.'&&s[i-1][j]=='o'){
                swap(s[i][j],s[i-1][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=50;i++) deal();
    for(int i=0;i<n;i++){
        cout<<s[i]<<endl;
    }
    return 0;
}
