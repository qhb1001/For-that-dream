#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
const int maxn=2e5+10;
struct ty{
    int idx;
    int w;
}Node[maxn];
bool cmp(ty a,ty b){
    if(a.w==b.w) return a.idx<b.idx;
    else return a.w<b.w;
}
int n,m;
string s;
stack<int>st;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>Node[i].w;
        Node[i].idx=i;
    }
    sort(Node+1,Node+1+n,cmp);
    cin>>s;m=s.length();
    int l=1;
    for(int i=0;i<m;i++){
        if(s[i]=='0'){
            cout<<Node[l].idx<<" ";
            st.push(Node[l].idx);
            l++;
        }else{
            cout<<st.top()<<" ";
            st.pop();
        }
    }
    cout<<endl;
    return 0;
}
