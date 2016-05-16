//Problem Description
//FatMouse prepared M pounds of cat food, ready to trade with the cats guarding the warehouse containing his favorite food, JavaBean.
//The warehouse has N rooms. The i-th room contains J[i] pounds of JavaBeans and requires F[i] pounds of cat food. FatMouse does not have to trade for all the JavaBeans in the room, instead, he may get J[i]* a% pounds of JavaBeans if he pays F[i]* a% pounds of cat food. Here a is a real number. Now he is assigning this homework to you: tell him the maximum amount of JavaBeans he can obtain.
// 
//
//Input
//The input consists of multiple test cases. Each test case begins with a line containing two non-negative integers M and N. Then N lines follow, each contains two non-negative integers J[i] and F[i] respectively. The last test case is followed by two -1's. All integers are not greater than 1000.
// 
//
//Output
//For each test case, print in a single line a real number accurate up to 3 decimal places, which is the maximum amount of JavaBeans that FatMouse can obtain.
// 
//
//Sample Input
//5 3
//7 2
//4 3
//5 2
//20 3
//25 18
//24 15
//15 10
//-1 -1
// 
//
//Sample Output
//13.333
//31.500

#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
struct BestBuy{
	double x,y;
	double p;  //–‘º€±»
};
//“¿pΩµ–Ú≈≈–Ú
bool operator<(const BestBuy &a,const BestBuy &b)
{
	return a.p > b.p;
}
int main()
{
	double m,n,i,j,f;
	while(cin>>m>>n &&m!=-1&&n!=-1)
	{
		vector<BestBuy>v(n);
		for(i=0;i<n;i++)
		{
			cin>>j>>f;
			v[i].x = j;
			v[i].y = f;
			v[i].p = j/f;
		}
		sort(v.begin(),v.end());

		double sum=0,res=0;
		for(i=0;i<n;i++)
		{
			sum += v[i].y;
			res += v[i].x;
			if(sum>m)
			{
				int c = sum-m;
				res -= v[i].p*c;
				break;
			}
		}
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<res<<endl;
	}
	return 0;
}