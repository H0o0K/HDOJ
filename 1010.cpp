//// http://blog.csdn.net/chyshnu/article/details/6171758
//搜索时要用到的剪枝：
//1.如果当前时间即步数(step) >= T 而且还没有找到D点，则剪掉。
//2.设当前位置(x, y)到D点(dx, dy)的最短距离为s，到达当前位置(x, y)已经花费时间(步数)step，那么，如果题目要求的时间T - step < s，则剪掉。
//3. 对于当前位置(x, y)，如果，(T-step-s)是奇数，则剪掉(奇偶剪枝)。
//4.如果地图中，可走的点的数目(xnum) < 要求的时间T，则剪掉(路径剪枝)。

#include<iostream>
using namespace std;
const int MAX = 6;
char maze[MAX][MAX];
int N, M, T, sx, sy, ex, ey;
bool solved = false,map[MAX][MAX];
const int dir[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

int Distance ( int x, int y ) 
{
	return abs ( (double)x - ex ) + abs ( (double)y - ey ); // 当前点(x,y)到终点(ex,ey)的最短距离
}
void DFS(int x, int y, int step)
{
	if(solved)return;
	if(maze[x][y]=='D'&& step==T)
	{
		solved = true;
		return;
	}
	if(step>=T)return;
	int dis = T-step-Distance(x,y);
	if(dis<0 || dis%2)return;
	for(int i=0;i<4;i++)
	{
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		int tstep = step + 1;
		if ( tx >= 0 && tx < N && ty >= 0 && ty < M && maze[tx][ty] != 'X' && !map[tx][ty]) {
			map[tx][ty] = true;
			DFS ( tx, ty, tstep );
			map[tx][ty] = false;
		}
	}
}

int main()
{
	while(cin>>N>>M>>T,N+M+T)
	{
		solved = false;
		int i,j,xnum=0;   //X符号个数
		for(i=0;i<N;++i)
		{
			cin.get();
			for(j=0;j<M;++j)
			{
				cin>>maze[i][j];
				map[i][j] = false;
				if(maze[i][j]=='S')
				{
					sx = i;
					sy = j;
					map[i][j] = true;
				}
				else if(maze[i][j]=='D')
				{
					ex = i;
					ey = j;
				}
				else if(maze[i][j]=='X')
					xnum++;
			}
		}
		if ( N * M - xnum > T ) { 
			DFS ( sx, sy, 0 );
		}
		if ( solved )
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	return 0;
}