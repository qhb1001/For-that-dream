#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
set<string>ans[100];
bool check(char a,char b,char c){
    if(a==b&&b==c) return false;
    if(b=='C'&&a!=b&&c!=a&&c!=b) return false;
    if(a=='C'&&a==c&&b!=a) return false;
    return true;
}
void dfs(string now){
    int len=now.length();
    ans[len].insert(now);
    if(now.length()>=15) return ;
    char a=now[len-2];char b=now[len-1];
    char c='A';
    if(check(a,b,c)){
        dfs(now+c);
    }
    c='B';
    if(check(a,b,c)){
        dfs(now+c);
    }
    c='C';
    if(check(a,b,c)){
        dfs(now+c);
    }
}

int main(){
    // freopen("output","w",stdout);
    dfs("AA");
    dfs("AB");
    dfs("AC");
    dfs("BA");
    dfs("BB");
    dfs("BC");
    dfs("CA");
    dfs("CB");
    dfs("CC");
// AA=BA+CA
// AB=AA+BA+CA
// AC=AA+BA

// BA=AB+BB+CB
// BB=AB+CB
// BC=AB+BB

// CA=AC+CC
// CB=BC+CC
// CC=AC+BC
//

//AAB +16
//AAC +9
//ABA +16
//ABB +11
//ABC +9

//ACA +12
    for(int i=3;i<=15;i++){
        set<string>::iterator it;
        cout<<"len: "<<i<<" "<<ans[i].size()<<" "<<3*ans[i-1].size()<<" "<<3*ans[i-1].size()-ans[i].size()<<endl;
        
        // for(it=ans[i].begin();it!=ans[i].end();it++){
        //     cout<<(*it)<<endl;
        // }
    }
}