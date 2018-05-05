#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std;

string str1,str2,str3,str;
map<string,int> res;
int num;

void solve(){
    int cnt=0;
    res.clear();
    while(1){
        cnt++;
        str.clear();
        for(int i=0;i<num;i++){
            str+=str2[i];
            str+=str1[i];
        }
        if(!res[str]){
            res[str]++;
        }
        else{
            cout<<"-1"<<endl;
            break;
        }
        if(str==str3){
            cout<<cnt<<endl;
            break;
        }
        str1.clear();
        str2.clear();
        for(int i=0;i<num;i++){
            str1+=str[i];
        }
        for(int i=num;i<num*2;i++){
            str2+=str[i];
        }
    }
}

int main(){
    int cnt=0,n;
    cin>>n;
    while(n--){
        cin>>num>>str1>>str2>>str3;
        cout<<++cnt<<" ";
        solve();
    }
    return 0;
}
