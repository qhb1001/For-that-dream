#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int maxn=1e6+5;
int Next[maxn];
int getNext(string &a){
    int i=0,j=-1,len=a.size();
    Next[0]=-1;
    while(i<len){
        if(j==-1||a[i]==a[j]){
            Next[++i]=++j;
        }
        else{
            j=Next[j];
        }
    }

//    for(int i=0;i<=len;i++){
//        cout<<i<<" "<<Next[i]<<endl;
//    }
//
    int ans=Next[len];
    while(ans>0){
//        cout<<ans<<" "<<len-ans<<endl;
        for(int i=1;i<len;i++){
//            cout<<Next[i]<<endl;
            if(Next[i]==ans) return ans;
        }
        ans=Next[ans];
    }
    return -1;
}
int main() {
    string s;
    while(cin>>s){
        int ans=getNext(s);
//        cout<<ans<<endl;
        if(ans==-1) cout<<"Just a legend"<<endl;
        else{
            for(int i=0;i<ans;i++){
                cout<<s[i];
            }
            cout<<endl;
        }
    }
    return 0;
}

