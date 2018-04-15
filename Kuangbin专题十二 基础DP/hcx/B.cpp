#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>v;
int main() {
    int n;
    while(scanf("%d",&n)!=EOF){
        v.clear();
        for(int i=0;i<n;i++){
            int x;scanf("%d",&x);
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        cout<<v[n/2]<<endl;
    }
    return 0;
}

// //internet
// //o(n)
// #include<iostream>
// #include<cstring>
// #include<cmath>
// #include<cstdio>
// #include<algorithm>
// #include<stack>
// #include<queue>
// using namespace std;

// const int N = 1000009;
// int a[N];

// int main()
// {
//     int n;
//     while(~scanf("%d", &n))
//     {
//         int num = 0;
//         int ans = -1;
//         for(int i=0; i<n; i++)
//         {
//             scanf("%d", &a[i]);
//             if(num == 0)
//             {
//                 ++num;
//                 ans = a[i];
//             }
//             else
//             {
//                 if(ans != a[i])
//                     num--;
//                 else
//                     num++;
//             }
//         }
//         printf("%d\n", ans);
//     }
//     return 0;
// }