//f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.
//ime Limit: 2000/1000 MS (Java/Others)   
//Memory Limit: 65536/32768 K (Java/Others)

/*超时  由于mod7  所以一定个数后就会有重复，可不必再计算
#include<iostream>
using namespace std;
int fun(int A,int B,int n)
{	
	A %= 7;	B %= 7;
	int a,b,c,i;
	a=b=c=1;
	if(n==1||n==2)return c;
	for(i=3;i<=n;i++){
		a %= 7;	b %= 7;
		c = A*b + B*a;
		c %= 7;
		a = b;
		b = c;
	}
	return c;
}
int main()
{
	int A,B,n,f1=1,f2=1;
	while(cin>>A){
		cin>>B>>n;
		if(A==0&&B==0&&n==0)
			return 0;
		int fn = fun(A,B,n);
		cout<<fn<<endl;
	}
	return 0;
}
*/ 
#include<iostream>
int f[1000];
using namespace std;
int main()
{
    int a, b,n, i;
    while(cin>>a)
    {
        memset(f, 0, sizeof(f));
        cin>>b>>n;
        if(a==0 && b==0 && n == 0) break;
        f[0] = f[1] = 1;
        if(n == 1 || n ==2 )
        {
            cout<<f[0]<<endl;
            continue;
        }
        for(i = 2; i<1000; i++)
        {
            f[i] = (a * f[i-1] + b * f[i-2])% 7;
            if(f[i-1] == 1 && f[i-2] == 1 && i != 2  )  break;    
        }
        cout<<f[(n-1)%(i-2)]<<endl;
    }
    return 0;
}