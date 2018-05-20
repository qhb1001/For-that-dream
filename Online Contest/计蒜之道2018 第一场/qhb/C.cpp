#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
int n, cnt = 0;
typedef long long ll;
ll cost[MAX], dp[MAX];
struct Node {
	int idx;
	ll val;
}now[MAX];

vector<int>G[MAX];//邻接表,存原图
vector<int>scc[MAX];//缩点后的图
stack<int>s;
int dfn[MAX],low[MAX],tot,ins[MAX];
//dfn是否为0可以判断点是否访问过，ins数组用来判断点是否在栈中
//dfn数组表示顶点dfs的时间戳，low[]为u能够追溯到的最早的栈中顶点的次序号
int scc_cnt;//强联通分量的个数
int sccnum[MAX];//缩点数组，表示某个点对应的缩点值
ll costNow[MAX];

bool vis[MAX];
ll dfs(int now) {
	if (dp[now] != -1) {
		return dp[now];
	}
	int len = scc[now].size();
	ll sum = 0;
    dp[now] = costNow[now];
	for (int i = 0; i < len; ++i) {
		vis[G[now][i]] = 1;
		dp[now] += dfs(G[now][i]);
	}
    return dp[now];
}

void tarjan(int x)
{
    low[x]=dfn[x]=++tot;//
    s.push(x);ins[x]=1;
    for(int i=0;i<G[x].size();i++){
        int p=G[x][i];
        if(!dfn[p]){//判断点是否被访问过
            tarjan(p);
            low[x]=min(low[x],low[p]);
        }
        else if(ins[p]) low[x]=min(low[x],dfn[p]);//判断点是否在栈中
    }

    if(low[x]==dfn[x]){//dfs到叶子节点，开始判断，如果==就到达了某个强联通分量的根节点,dfs回溯到了这个点
        scc_cnt++;
        scc[scc_cnt].clear();
        while(1){//得出某个强联通分量的集合
            int now=s.top();
            s.pop();
            ins[x]=0;//出栈ins置0
            if(sccnum[now]!=scc_cnt) scc[scc_cnt].push_back(x), costNow[scc_cnt] += cost[now];
            sccnum[now]=scc_cnt;//将该连通分量中的每个点都赋予相同的值
            if(now==x) break;//通过栈找到那个点
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> cost[i];
	}

	cnt = n;

	for (int i = 1; i <= n; ++i) {
		now[i].idx = i;
		now[i].val = cost[i];
	}
	int k, type, nowIdx;
	ll  nowVal, l, r;
	cin >> k;

	while (k--) {
		cin >> type;
		if (type == 0) {
			cin >> nowIdx >> nowVal;
			now[nowIdx].idx = ++cnt;
		//	cout << "here " << nowIdx << " " << cnt << endl;
			now[nowIdx].val = nowVal;
			cost[cnt] = nowVal;
		} else {
			cin >> nowIdx >> l >> r;
			//cout << "here " << nowIdx << " " << now[nowIdx].idx << endl;
			for (int i = l; i <= r; ++i) {
				G[now[nowIdx].idx].push_back(now[i].idx);
		//		cout << now[i].idx << " ";
			}
		//	cout << endl;
		}
	}

	ll ans = 1e18;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= cnt; ++i) {
		if (!dfn[i])	tarjan(i);
	}

	for (int i = 1; i <= scc_cnt; ++i) {
		memset(vis, 0, sizeof(vis));
		vis[i] = 1;
		ans = min(ans, dfs(i));
	}
//	for (int i = 1; i <= cnt; ++i)	cout << cost[i] << " " ;
//	cout << endl;
	cout << ans << endl;
}
