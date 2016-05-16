/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int i=0,N;
	string str;
	while(cin>>N){
		getchar();           //从控制台读取字符并立即回显
		if(N==0)return 0;
		vector<string>vec;
		vector<int>num(N,0); //统计各颜色次数
		int n_color=0;       //颜色种类
		while(N--){
			getline(cin,str);			
			vec.push_back(str);
			for(i=0;i<n_color;i++){
				if(str == vec[i])
					num[i]++;
			}
			if(i==n_color){
				num[n_color]++;
				n_color++;
			}
		}
		int maxval=-1,j;
		for(i=0;i<n_color;i++){
			if(num[i]>maxval){
				maxval = num[i];
				j = i;
			}
		}
		cout<<vec[j]<<endl;
	}
	return 0;
}
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    map<string,int> balloon;
    int n;
    string a;
    while(cin >> n&& n!=0)
    {
        balloon.clear();
        while(n--)
        {
            cin >> a;
            balloon[a]++;
        }
        map<string,int>::iterator it;
        int max=-100;string maxcolor;
        for (it=balloon.begin();it!=balloon.end();it++)
        {
            if((*it).second>max)
            {
                max=(*it).second;
                maxcolor=(*it).first;
            }
        }
        cout<<maxcolor<<endl;
    }
    return 0;
}