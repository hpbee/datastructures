#include<iostream>
using namespace std;

int bs(int arr[],int x)
{
	int lo=0;
	int hi=9;
	while(hi>lo)
	{
		int mid=(lo+hi)/2;
		if (arr[mid]==x) return mid;
		if (arr[mid]<=arr[hi]) 
		{
			if (arr[mid]>x) hi=mid-1;
			else if (arr[mid]<x)
			{
				if(arr[hi]==x) return hi;
				else if(arr[hi]>x) lo=mid+1;
				else hi=mid-1;
			}
			
 		}
		else
			{
				if (arr[mid]>x && arr[lo]<=x) hi=mid-1;
				else lo=mid+1;
			}
		
	}
	return -1;
}

int main()
{
	int arr[10]={7 ,8, 9, 10, 11, 12, 13, 14, 1, 4},t;
	cout<<"enter number to be searched: ";
	cin>>t;
	cout<<t<<" occurs at "<<bs(arr,t);
	return 0;
}