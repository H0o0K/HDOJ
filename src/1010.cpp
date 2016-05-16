//// http://blog.csdn.net/chyshnu/article/details/6171758
//����ʱҪ�õ��ļ�֦��
//1.�����ǰʱ�伴����(step) >= T ���һ�û���ҵ�D�㣬�������
//2.�赱ǰλ��(x, y)��D��(dx, dy)����̾���Ϊs�����ﵱǰλ��(x, y)�Ѿ�����ʱ��(����)step����ô�������ĿҪ���ʱ��T - step < s���������
//3. ���ڵ�ǰλ��(x, y)�������(T-step-s)�������������(��ż��֦)��
//4.�����ͼ�У����ߵĵ����Ŀ(xnum) < Ҫ���ʱ��T�������(·����֦)��

#include<iostream>
using namespace std;
const int MAX = 6;
char maze[MAX][MAX];
int N, M, T, sx, sy, ex, ey;
bool solved = false,map[MAX][MAX];
const int dir[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

int Distance ( int x, int y ) 
{
	return abs ( (double)x - ex ) + abs ( (double)y - ey ); // ��ǰ��(x,y)���յ�(ex,ey)����̾���
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
		int i,j,xnum=0;   //X���Ÿ���
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