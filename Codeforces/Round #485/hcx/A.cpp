#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string a[]={"Power","Time","Space","Soul","Reality","Mind"};
string b[]={"purple","green", "blue", "orange", "red", "yellow"};
bool c[10];
int m;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    memset(c,0,sizeof(c));

    cin>>m;
    while(m--){
        cin>>s;
        for(int i=0;i<6;i++){
            if(s==b[i]){
                c[i]=true;
                break;
            }
        }
    }

    int cnt=0;
    for(int i=0;i<6;i++){
        if(!c[i]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<6;i++){
        if(!c[i]){
            cout<<a[i]<<endl;
        }
    }
    return 0;
}
