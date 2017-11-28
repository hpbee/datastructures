#include<iostream>
using namespace std;
template<typename T>
int bub_sort(T* arr)
{
	 int n=sizeof(arr)/sizeof(arr[0]);
	// if(n<2) return;
	// T tmp;
	for(int i=1;i<4;i++)
	{
		// if(arr[i-1]>arr[i]) {tmp=arr[i-1];arr[i-1]=arr[i];arr[i]=tmp;}
		arr[i]=0;
	}
	return 0;
}

int main()
{
	cout<<"enter no. of digits to be sorted : ";
	int n;
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	bub_sort(arr);
	for (int i=0;i<n;i++) cout<<arr[i]<<" ";
	return 0;
}