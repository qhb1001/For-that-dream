#include <iostream>
#include <cmath>
using namespace std;
int n;
int a[]={0,
    8,
    72,
    648,
    5832,
    52488,
    472392,
    4251528,
    38263752,
    344373768};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>n;
    if(n<10){
        cout<<a[n]<<endl;
    }
    else{
        cout<<a[9];
        for(int i=10;i<=n;i++)
            cout<<"0";
        cout<<endl;
    }
    return 0;
}
