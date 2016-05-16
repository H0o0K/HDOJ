//#include<iostream>  
//using namespace std;  
//#define Min -999999  
//int main()  
//{  
//	int data[100000],start,end;  
//	int m;  
//	int step=1;  
//	cin>>m;      
//	while(m--)  
//	{  
//		int n;  
//		cin>>n;  
//		for (int i=1; i<=n;i++)  
//			cin>>data[i];  
//		int max = Min;  
//		int k=1;  
//		int sum = 0;  
//		for (int i=1; i<=n; i++)  
//		{  
//			sum = sum + data[i];  
//			if (sum > max)  
//			{  
//				max = sum;  
//				start=k;  
//				end=i;  
//			}  
//			if(sum<0)  
//			{  
//				sum=0;  
//				k=i+1;  
//			}  
//		}  
//		if(step!=1)  
//			cout<<endl;  
//		cout<<"Case "<<step<<":"<<endl;  
//		cout<<max<<" "<<start<<" "<<end<<endl;  
//		step++;  
//	}  
//	return 0;  
//}  

#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> maxSum(vector<int> &arr ,int Size);

int main()
{
	int n,i;
	cin>>n;
	vector<vector<int> > p(n,vector<int>(3)); //保存全部case的结果
	for(i=0;i<n;i++){
		int num ,Size=0;
		vector<int>v;
		while(cin>>num){
			v.push_back(num);
			Size++;
		}
		vector<int>vec = maxSum(v,Size);
		p.push_back(vec);
	}
	for(i=0;i<n-1;i++){
		cout<<"Case "<<i+1<<":\n";
		cout<<p[i][0]<<" "<<p[i][1]<<" "<<p[i][2]<<"\n\n";
	}
	cout<<"Case "<<n<<":\n";
	cout<<p[n-1][0]<<" "<<p[n-1][1]<<" "<<p[n-1][2]<<endl;

	return 0;
}

vector<int> maxSum(vector<int> &arr,int Size)
{
	vector<int>vec;   //存 sum  start end
	if(Size==0)return vec;
	if(Size==1){
		vec.push_back(arr[0]);
		vec.push_back(1);
		vec.push_back(1);
		return vec;
	}
	int start=0,end=0;
	int max_curr = arr[0];
	int max_so_far = arr[0];
	for(int i=1;i<Size;i++){
		max_curr = max(arr[i], max_curr + arr[i]);
        max_so_far = max(max_so_far, max_curr);
		vec.push_back(max_so_far);
		vec.push_back(1);
		vec.push_back(3);
	}
	return vec;
}