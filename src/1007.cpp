// 分治法解决最小点对问题
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
struct Point
{
    float x, y;
};
// 根据X坐标排序
int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}
// 根据Y坐标排序
int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}
// 返回距离
float dist(Point p1, Point p2)
{
	float a = (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y);
    return sqrt(a); 
}

// 暴力方法找到最小的点对
float bruteForce(Point P[], int n)
{
    float mindist = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < mindist)
                mindist = dist(P[i], P[j]);
    return mindist;
}
// d就是min(dl,dr) 这个是上限。
//找出 strip[] 数组中的最小点对。看似复杂度O(n^2)
//实际上O(n)，因为内层循环最多执行6次。
float stripClosest(Point strip[], int size, float d)
{
    float mindist = d; 
    qsort(strip, size, sizeof(Point), compareY); 
    // 可以证明这个循环最多执行6次
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < mindist; ++j)
            if (dist(strip[i],strip[j]) < mindist)
                mindist = dist(strip[i], strip[j]);
    return mindist;
}
//递归的计算最小点对
float closestUtil(Point P[], int n)
{
    // 如果点较少，用暴力解决
    if (n <= 3)
        return bruteForce(P, n);

    // 找到中间点
    int mid = n/2;
    Point midPoint = P[mid];

    // 分成两个部分，分别计算
    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n-mid);
    float d = dl<=dr?dl:dr;

    //所有距离垂直线距离在d以内的点
	Point *strip = new Point[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;

    // 找出strip 数组中的最小点对
	float res =  min(d, stripClosest(strip, j, d) );
	delete []strip;
	return res;
}

float closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);
    return closestUtil(P, n);
}

int main()
{
	int N;
	float a,b;
	while(cin>>N)
	{
		float res;
		if(N==0)break;
		Point *P = new Point[N];
		if(N=1){
			cin>>a;
			cin>>b;
			P[0].x = a;
			P[0].y = b;
			res = 0.00;
			cout<<setiosflags(ios::fixed)<<setprecision(2)<<res<<endl;
			continue;
		}		
		for(int i=0;i<N;i++)
		{
			cin>>a;
			cin>>b;
			P[i].x = a;
			P[i].y = b;
		}
		res = closest(P,N)/2;
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<res<<endl;
		delete []P;
	}
    return 0;
}