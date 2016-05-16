#include<iostream>
#include<string>
using namespace std;
string intAdd(string s1,string s2);
string invert(string src);

int main()
{
	int n;
	cin>>n;
	string **arr = new string*[n];
	for(int i=0;i<n;i++)
		arr[i] = new string[2];
	string a,b,sum;
	for(int i=0;i<n;i++){
	    cin>>a;arr[i][0]=a;
		cin>>b;arr[i][1]=b;
	}
	for(int i=0;i<n-1;i++){
		cout<<"Case "<<i+1<<":\n";
		sum = intAdd(arr[i][0],arr[i][1]);
		cout<<arr[i][0]<<" + "<<arr[i][1]<<" = "<<sum<<"\n\n";
	}
	sum = intAdd(arr[n-1][0],arr[n-1][1]);
	cout<<"Case "<<n<<":\n";
	cout<<arr[n-1][0]<<" + "<<arr[n-1][1]<<" = "<<sum<<endl;

	for(int i=0;i<n;i++)
		delete[] arr[i];
	delete[] arr;
	return 0;
}
string intAdd(string s1,string s2)
{
    string str1=invert(s1);
    string str2=invert(s2);
 
    if(str1.length()<str2.length())
        str1.swap(str2);
 
    for(size_t i=0; i!=str2.length(); ++i)
    {
        char c1=str1[i];
        char c2=str2[i];
        int t=((int)c1-48)+((int)c2-48);
        if(t>=10)
        {     //½øÎ»
            int x=t/10;
            t%=10;
            size_t n=i+1;
            do{    
				int t1=(int)str1[n]-48+x;
                if(t1>=10) {
                    str1[n]=(char)(t1%10+48);
                    ++n;
                }
                else   
                    str1[n]=(char)(t1+48);
 
                if(n==str1.length()){
                    str1+="1";
                    break;
                }
                x=t1/10;
            }
            while(x!=0); 
            str1[i]=(char)(t+48);
        }
        else
            str1[i]=(char)(t+48);
    }
    string rstrResult=str1;
    string strOut=invert(rstrResult);
    return strOut;
}
 
string invert(string src)
{
    string newStr=src;
    for(int i=src.length()-1,j=0; i>=0; --i,++j)
        newStr[j]=src[i];
 
    return newStr;
}
