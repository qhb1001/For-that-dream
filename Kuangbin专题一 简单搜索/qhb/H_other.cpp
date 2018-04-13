#include <iostream>
#include <algorithm>
using namespace std;
#include <cstring>
#include <queue>
#include <stack>
struct cup
{
	int x, y;
	int step;
	int flag;//标记操作
	cup *pre;//记录路径
};
queue<cup>Q;
stack<int>R;
int a, b, e;
int vis[117][117]={0};//标记当前状态是否到达过
int ans;
void BFS(int x, int y)
{
	cup c;
	cup t[317];//目前瓶子里剩余的水量
	c.x = 0, c.y = 0;
	c.flag = 0;
	c.pre = NULL;
	c.step = 0;
	Q.push(c);
	vis[x][y] = 1;
	int count = -1;
	while(!Q.empty())
	{
		count++;
		t[count] = Q.front();
		Q.pop();
		for(int i = 1; i <= 6; i++)
		{
			switch(i)
			{
				case 1:						//fill a
					c.x = a;
					c.y = t[count].y;
					c.flag = 1;
					break;
				case 2:						//fill b
					c.x = t[count].x;
					c.y = b;
					c.flag = 2;
					break;
				case 3:						//drop a
					c.x = 0;
					c.y = t[count].y;
					c.flag = 3;
					break;
				case 4:						//drop b
					c.x = t[count].x;
					c.y = 0;
					c.flag = 4;
					break;
				case 5:						//pour a to b
					if(t[count].x > b-t[count].y)
					{
						c.x = t[count].x-(b-t[count].y);
						c.y = b;
					}
					else
					{
						c.x = 0;
						c.y = t[count].y+t[count].x;
					}
					c.flag = 5;
					break;
				case 6:						//pour b to a
					if(t[count].y > a-t[count].x)
					{
						c.y = t[count].y - (a-t[count].x);
						c.x = a;
					}
					else
					{
						c.x = t[count].x+t[count].y;
						c.y = 0;
					}
					c.flag = 6;
					break;
			}
			if(vis[c.x][c.y])
				continue;
			vis[c.x][c.y] = 1;
			c.step = t[count].step+1;
			c.pre = &t[count];
			if(c.x == e || c.y == e)
			{
				ans = c.step;
				while(c.pre)
				{
					R.push(c.flag);
					c = *c.pre;
				}
				return;
			}
			Q.push(c);
		}
	}
}
void print()
{
	while(!R.empty())
	{
		int i = R.top();
		R.pop();
		switch(i)
		{
			case 1:cout<<"FILL(1)"<<endl;break;
			case 2:cout<<"FILL(2)"<<endl;break;
			case 3:cout<<"DROP(1)"<<endl;break;
			case 4:cout<<"DROP(2)"<<endl;break;
			case 5:cout<<"POUR(1,2)"<<endl;break;
			case 6:cout<<"POUR(2,1)"<<endl;break;
		}
	}
}
int main()
{
	freopen("input", "r", stdin);
	freopen("output.b", "w", stdout);
	cin >>a>>b>>e;
	BFS(0,0);
	if(ans == 0)
		cout<<"impossible"<<endl;
	else
	{
		cout<<ans<<endl;
		print();
	}
	return 0;
}
