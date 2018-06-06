#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn=110;
struct ty{
    string s;
    int len;
}Node[maxn];
bool cmp(const ty a,const ty b){
    if(a.len!=b.len){
        return a.len<b.len;
    }
    else{
        return a.s<b.s;
    }
}
int n,m;
bool check(string a,string b){
    int lena=a.length(),lenb=b.length();
    for(int i=0;i<lenb;i++){
        if(b[i]==a[0]){
            int idx=i,j;
            for(j=0;j<lena&&i<lenb;){
                if(b[idx]!=a[j]) break;
                idx++;j++;
            }
            if(j==lena)return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>Node[i].s;
        Node[i].len=Node[i].s.length();
    }
    sort(Node,Node+n,cmp);
    bool flag=true;
    for(int i=1;i<n;i++){
        if(Node[i].len==Node[i-1].len){
            if(Node[i].s!=Node[i-1].s){
                flag=false;
                break;
            }
        }
        else{
            if(!check(Node[i-1].s, Node[i].s)){
                flag=false;
                break;
            }
        }
    }
    if(!flag) cout<<"NO"<<endl;
    else{
        cout<<"YES\n";
        for(int i=0;i<n;i++){
            cout<<Node[i].s<<endl;
        }
    }
    return 0;
}

