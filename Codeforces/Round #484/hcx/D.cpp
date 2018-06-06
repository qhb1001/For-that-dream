#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
set<pair<int, int> >s;//day,distance
set<pair<int,int> >::reverse_iterator it;
set<int>ts; //divided
map<int,int>mmap;//map[i]=j  the number of (the length is i) is j
int n,x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;s.insert(make_pair(x, i));
    }
    ts.insert(0);
    ts.insert(n+1);
    mmap[n]=1;
    int ans=s.rbegin()->first+1;//rbegin 反向迭代器
    int cnt=1;
    for(int i=0;i<n-1;i++){
        it=s.rbegin();
        int pos=it->second;
//        cout<<"pos: "<<pos<<endl;
        s.erase((*it));
        int head,tail;
        head=*(--ts.lower_bound(pos));
        tail=*(ts.upper_bound(pos));
//        cout<<"head: "<<head<<endl;
//        cout<<"tail: "<<tail<<endl;
        ts.insert(pos);                     //divide
        mmap[tail - head - 1]--;
        if (mmap[tail - head - 1] == 0){
            mmap.erase(tail - head - 1);
        }

        mmap[pos - head - 1]++;
        mmap[tail - pos - 1]++;
        mmap.erase(0);
        if (mmap.size() == 1){               //all the length are same
            int now = mmap.begin()->second;
//            cout<<"now: "<<now<<endl;
            if (now >= cnt){
                cnt = now;
                ans = s.rbegin()->first + 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

