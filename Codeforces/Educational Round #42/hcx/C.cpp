#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
ll s_to_i(string s){
    ll tmp=0;
    int n=s.length();
    for(int i=0;i<n;i++){
        tmp*=10;
        tmp+=s[i]-'0';
    }
    return tmp;
}

bool check(string s){
    bool flag=false;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='1'||s[i]=='0'||s[i]=='4'||s[i]=='9'||s[i]=='5'||s[i]=='6'){
            flag=true;
            break;
        }
    }
    return flag;
}

int bfs(string s){
    ll ans=0;
    string tmp;
    queue<string>q;
    q.push(s);
    while(!q.empty()){
        tmp=q.front();
        q.pop();
        if(!check(tmp)) continue;
        ll now=s_to_i(tmp);
        if((int)sqrt(now)*(int)sqrt(now)==now){
            ans=tmp.length();
            break;
        }
        int n=tmp.length();
        if(n==1){
            continue;
        }
        string next="";
        for(int i=0;i<n;i++){
            next="";
            for(int j=0;j<n;j++){
                if(i==j)continue;
                next+=tmp[j];
            }
//            cout<<next<<endl;
            if(next[0]=='0') continue;
            q.push(next);
        }
    }
//    cout<<tmp<<endl;
    return ans;
}

int main(){
    string s;cin>>s;
    ll n=s_to_i(s);
    if(check(s)){
        int x=bfs(s);
        if(!x) cout<<"-1"<<endl;
        else cout<<s.length()-x<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }
    return 0;
}
