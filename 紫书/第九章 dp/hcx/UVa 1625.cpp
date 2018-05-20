#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=5005;
const int INF=0x3f3f3f3f;
int d[maxn][maxn];
string a,b;
int bea[30],enda[30];
int beb[30],endb[30];
int cnt[maxn][maxn];
int num,T,n,m,idx;
bool Begin,End;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>a>>b;
        n=a.length();
        m=b.length();

        memset(bea,-1,sizeof(bea));
        memset(beb,-1,sizeof(beb));
        memset(enda,-1,sizeof(enda));
        memset(endb,-1,sizeof(endb));

        for(int i=0;i<n;i++){
            idx=a[i]-'A';
            if(bea[idx]==-1){
                bea[idx]=enda[idx]=i+1;
            }
            else{
                enda[idx]=i+1;
            }
        }
        for(int i=0;i<m;i++){
            idx=b[i]-'A';
            if(beb[idx]==-1){
                beb[idx]=endb[idx]=i+1;
            }
            else{
                endb[idx]=i+1;
            }
        }

        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                num=0;
                for(int k=0;k<26;k++){
                    Begin=false;
                    if((bea[k]!=-1&&bea[k]<=i)||(beb[k]!=-1&&beb[k]<=j)){
                        Begin=true;
                        num++;
//                        cout<<(char)(k+'A')<<" "<<bea[k]<<" "<<i<<" "<<beb[k]<<" "<<j<<" "<<num<<endl;
                    }
                    if(Begin){
                        if(enda[k]<=i&&endb[k]<=j){
                            num--;
//                            cout<<" "<<enda[k]<<" "<<i<<" "<<endb[k]<<" "<<j<<" "<<num<<endl;
                        }
                    }
                }
                cnt[i][j]=num;
//                cout<<i<<" "<<j<<" "<<cnt[i][j]<<endl;
            }
        }

        d[0][0]=0;
        for(int j=1;j<=m;j++){
            idx=b[j-1]-'A';
            d[0][j]=d[0][j-1]+cnt[0][j];
        }

        for(int i=1;i<=n;i++){
            idx=a[i-1]-'A';
            d[i][0]=d[i-1][0]+cnt[i][0];
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                d[i][j]=min(d[i-1][j]+cnt[i][j],d[i][j-1]+cnt[i][j]);
            }
        }
        cout<<d[n][m]<<endl;
    }
    return 0;
}