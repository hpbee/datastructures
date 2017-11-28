#include<iostream>
//#include<vector>
using namespace std;
typedef long long LL;
int main()
{
	int n;
	cin>>n;
	int a[n];
	LL f[n+3];
	f[0]=f[1]=f[2]=0;
	scanf("%d",&a[0]);
	f[3]=a[0];
	for(int i=1,k=4;i<n;i++,k++)
	{
		scanf("%d",&a[i]);
		f[k]=a[i]+max(max(a[i-1]+f[k-3],f[k-2]),;
	}
	cout<<max(f[n+1],f[n+2]);
	return 0;
}