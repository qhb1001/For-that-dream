#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    freopen("input", "r", stdin);
    freopen("output.b", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n,s;
        cin>>n>>s;
        if(n==1){
            if(s<=9){
                cout<<s<<endl;
            }
            else cout<<-1<<endl;
            continue;
        }

        if(s<2||n*9<s){
            cout<<"-1"<<endl;
            continue;
        }
        if(2==s){
            cout<<"1";
            for(int i=2;i<n;i++){
                cout<<"0";
            }
            cout<<"1";
            cout<<endl;
            continue;
        }
        if(n*9==s){
            for(int i=1;i<=n;i++){
                cout<<"9";
            }
            cout<<endl;
            continue;
        }

        int numNine=s/18;
        int res=s%18;
        if(res%2){
            if(n%2==0){
                cout<<-1<<endl;
                continue;
            }

            for(int i=1;i<=numNine;i++)
                cout<<9;
            cout<<(res-1)/2;
            for(int i=numNine+2;i<=n/2;i++)
                cout<<0;
            cout<<1;
            for(int i=0;i<=n/2-numNine-2;i++)
                cout<<0;
            cout<<(res-1)/2;
            for(int i=1;i<=numNine;i++)
                cout<<9;
        }
        else{
            for(int i=1;i<=numNine;i++)
                cout<<9;
            cout<<res/2;
            for(int i=0;i<n-2*(numNine+1);i++)
                cout<<0;
            cout<<res/2;
            for(int i=1;i<=numNine;i++)
                cout<<9;
        }
        cout<<endl;
    }
    return 0;
}
