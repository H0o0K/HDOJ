#include<iostream>
#include<string>
using namespace std;

int sumOfDig(int n)
{
	if(n<10)return n;
	int sum = 0;
	while(n)
	{
		sum += n%10;
		n /=10;
	}
	return sum;
}
int summing(int n)
{
	int t = sumOfDig(n);
	while(t>9)
		t = sumOfDig(t);
	return t;	
}
int main()
{
	string s;
	while(cin>>s)
	{
		if(s=="0")break;
		int n=0;
		for(int i=0;i<s.length();++i)
		{
			n += s[i]-'0';
		}
		cout<<summing(n)<<endl;
	}
	return 0;
}