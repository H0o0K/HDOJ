// ���η������С�������
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
// ����X��������
int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}
// ����Y��������
int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}
// ���ؾ���
float dist(Point p1, Point p2)
{
	float a = (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y);
    return sqrt(a); 
}

// ���������ҵ���С�ĵ��
float bruteForce(Point P[], int n)
{
    float mindist = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < mindist)
                mindist = dist(P[i], P[j]);
    return mindist;
}
// d����min(dl,dr) ��������ޡ�
//�ҳ� strip[] �����е���С��ԡ����Ƹ��Ӷ�O(n^2)
//ʵ����O(n)����Ϊ�ڲ�ѭ�����ִ��6�Ρ�
float stripClosest(Point strip[], int size, float d)
{
    float mindist = d; 
    qsort(strip, size, sizeof(Point), compareY); 
    // ����֤�����ѭ�����ִ��6��
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < mindist; ++j)
            if (dist(strip[i],strip[j]) < mindist)
                mindist = dist(strip[i], strip[j]);
    return mindist;
}
//�ݹ�ļ�����С���
float closestUtil(Point P[], int n)
{
    // �������٣��ñ������
    if (n <= 3)
        return bruteForce(P, n);

    // �ҵ��м��
    int mid = n/2;
    Point midPoint = P[mid];

    // �ֳ��������֣��ֱ����
    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n-mid);
    float d = dl<=dr?dl:dr;

    //���о��봹ֱ�߾�����d���ڵĵ�
	Point *strip = new Point[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;

    // �ҳ�strip �����е���С���
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