#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <map>
using namespace std;
int n;
string Right;
string a,b;
int main(){
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        int ans=1;
        cin>>n;
        cin>>a>>b;
        cin>>Right;

        string g="";
        for(int i=0;i<n;i++){
            g+=b[i];
            g+=a[i];
        }
        string f=g;
        while(f!=Right){
//            cout<<f<<endl;
            ans++;
            a="";b="";
            for(int i=0;i<n;i++){
                a+=f[i];
                b+=f[n+i];
            }
            f="";
            for(int i=0;i<n;i++){
                f+=b[i];
                f+=a[i];
            }
            if(f==g){
                ans=-1;
                break;
            }
        }
        cout<<i<<" "<<ans<<endl;
    }
    return 0;
}