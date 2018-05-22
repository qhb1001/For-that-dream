#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
string ma[2005];
int cnt[2005];
int n,m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>ma[i];

    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if(ma[i][j]=='1')cnt[j]++;
        }
    }

    bool flag=false,find=false;
    for(int i=0;i<n;i++){
        flag=false;
        for(int j=0;j<m;j++){
            if(ma[i][j]=='1'&&cnt[j]==1){
                flag=true;
                break;
            }
        }
        if(!flag){
            find=true;
            break;
        }
    }
    if(find) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
