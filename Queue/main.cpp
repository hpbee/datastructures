#include<iostream>
#include<algorithm>
using namespace std;

long long arr[100001];
bool fun(long long d,long long n,long long c)
{

	long long pos=0;
	long long cn=1;
	for (long long i=1;i<n;i++)
	{
		if (arr[i]-arr[pos]>=d)
		{
			pos=i;cn++;
		}
		if (cn==c) return true;
	}
	return false;
}

int main()
{
	int t;
	long long n,c,lo,hi,mid;
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		for(int  i=0;i<n;i++) {cin>>arr[i];}
		sort(arr,arr+n);
		lo=1;
		hi=arr[n-1]-arr[0];
		if (c==2)
		{
			cout<<hi<<endl;
			continue;
		}
		while (hi>lo)
		{
			mid=(hi+lo)/2;
			(fun(mid,n,c))?lo=mid:hi=mid;
		}
		cout<<lo<<endl;
	}
	return 0;
}
