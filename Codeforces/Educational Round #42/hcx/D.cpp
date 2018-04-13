#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long  ll;
const int maxn=1e5+5e4+10;
struct ty{
    ll v;
    int idx;
    bool operator<(const ty& a)const{
        if(v==a.v)
            return idx>a.idx;
        return v>a.v;
    }
};

struct node{
    ll v;
    int idx;
    bool operator<(const node& a)const{
        return idx>a.idx;
    }
};

priority_queue<ty>q;
priority_queue<node>p;

int main(){
    ll n;cin>>n;
    for(int i=1;i<=n;i++){
        ty tmp;cin>>tmp.v;
        tmp.idx=i;
        q.push(tmp);
    }

    node ins;
    while(!q.empty()){
        ty bef=q.top();q.pop();
        if(q.empty()){
            ins.v=bef.v;ins.idx=bef.idx;
            p.push(ins);
            break;
        }
        ty now=q.top();q.pop();
//        cout<<bef.v<<" "<<now.v<<endl;
        if(now.v==bef.v){
            now.v*=2;
//             cout<<"now"<<now.v<<" "<<now.idx<<endl;
            q.push(now);
        }
        else{
            ins.v=bef.v;ins.idx=bef.idx;
//            cout<<"ins"<<ins.v<<" "<<ins.idx<<endl;
            p.push(ins);
            q.push(now);
        }
    }

    cout<<p.size()<<endl;
    node tmp=p.top();
    cout<<tmp.v;
    p.pop();
    while(!p.empty()){
        tmp=p.top();p.pop();
        cout<<" "<<tmp.v;
    }
    cout<<endl;
    return 0;
}
