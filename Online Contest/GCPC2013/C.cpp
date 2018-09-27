#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <vector>
using namespace std;
int x1, y_, x2, y2;
char s[2];
pair<int, int> now, last;
pair<int, int> get(pair<int, int> a, bool type) {
    int t = (a.first + a.second) / 2;
    if (type) return make_pair(t, t);
    else return make_pair((9 + a.first - a.second) / 2, (9 + a.second - a.first) / 2);
}
vector<pair<int, int> >ans;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
        scanf("%s", s);
		x1 = s[0] - 'A' + 1;
		scanf("%s", s);
		y_ = s[0] - '1' + 1;
		scanf("%s", s);
		x2 = s[0] - 'A' + 1;
		scanf("%s", s);
		y2 = s[0] - '1' + 1;

        if (x1 == x2 && y_ == y2) {printf("0 %c %c\n", x1 + 'A' - 1, y_ + '1' - 1); continue;}
        ans.clear();
		if((x1+y_)%2 == 0 && (x2+y2)%2 == 0){
            now = last = make_pair(x1, y_);
            ans.push_back(now);

            now = get(now, 1);
            if (now != last)   {
                ans.push_back(now);
                last = now;
            }

            now = get(make_pair(x2, y2), 1);
            if (now != last) {
                ans.push_back(now);
                last = now;
            }

            now = make_pair(x2, y2);
            if (now != last) {
                ans.push_back(now);
                last = now;
            }

		}
		else if((x1+y_)%2 == 1 && (x2+y2)%2 == 1){
            now = last = make_pair(x1, y_);
            ans.push_back(now);

            now = get(now, 0);
            if (now != last)   {
                ans.push_back(now);
                last = now;
            }

            now = get(make_pair(x2, y2), 0);
            if (now != last) {
                ans.push_back(now);
                last = now;
            }

            now = make_pair(x2, y2);
            if (now != last) {
                ans.push_back(now);
                last = now;
            }
		}
		else{
			puts("Impossible");
            continue;
		}

        int len = ans.size();
        printf("%d", len);
        for (int i = 0; i < len; ++i) printf(" %c %c", ans[i].first + 'A' - 1, ans[i].second + '1' - 1);
        printf("\n");
	}
	return 0;
}