#include<iostream>
using namespace std;
typedef long long LL;
string s="";
//naive pattern search
bool match (LL i,string p)
{
	for(LL j=0;j<p.size();j++)
	{
		if (p[j]!=s[i+j]) return false;
	}
	return 1;
}
int main()
{
	LL k;
	string p;
	int m;
	while (cin>>m)
	{
		if (!m) return 0;
		cin>>p>>s;
		k=s.size()-m;
		for(int i=0;i<k;i++)  
		{
			
			if (match(i,p)) cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}