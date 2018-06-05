#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string ans[105];
int n,k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    cout<<"YES\n";
    for(int i=1;i<=n;i++)
        cout<<".";
    cout<<endl;

    if(k%2){
        if(k>n-2){
            cout<<".";
            for(int i=1;i<n-1;i++)
                cout<<"#";
            cout<<".";
            cout<<endl;

            k-=n-2;
//            cout<<k<<endl;
            int from1=1,to1=k/2,from2=n-k/2-1,to2=n-2;
//            cout<<from1<<" "<<to1<<" "<<from2<<" "<<to2<<endl;
            for(int i=0;i<n;i++){
                if(i>=from1&&i<=to1){
                    cout<<"#";
                }else if(i>=from2&&i<=to2){
                    cout<<"#";
                }else cout<<".";
            }
            cout<<endl;
        }else{
            int from=n/2-k/2,to=n/2+k/2;
            for(int i=0;i<n;i++){
                if(i>=from&&i<=to)
                    cout<<"#";
                else cout<<".";
            }
            cout<<endl;
            for(int i=1;i<=n;i++)
                cout<<".";
            cout<<endl;
        }
    }else{
        int col=k/2;
        for(int i=0;i<n;i++){
            if(i>=1&&i<=col){
                cout<<"#";
            }else cout<<".";
        }
        cout<<endl;

        for(int i=0;i<n;i++){
            if(i>=1&&i<=col){
                cout<<"#";
            }else cout<<".";
        }
        cout<<endl;
    }

    for(int i=1;i<=n;i++)
        cout<<".";
    cout<<endl;
    return 0;
}
