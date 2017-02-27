#include <bits/stdc++.h>


using namespace std;

int dp[100005];

int binary_search(int arr[], int right,int key)
{
	int left =0;
	while(right - left>1)
	{
		int mid = (left + right)/2;
		if(arr[mid] > key)
			right = mid;
		else
			left = mid;
	}
	return right;
}

int find_lis(int* a,int offset,int n)
{
	for(int i=0;i<n;i++)
		dp[i]=-1;
	// dp[i] stores last element of incresing subsequence of length i+1
	// Base Case
	dp[0] = a[offset];

	// Length of longest increasing subsequece so far
	int res = 1;

	// Updating dp[x] if a[i]<dp[x] so that
	// last element of incresing subsequence of length x+1 is smallest as possible 
	for(int i = offset+1;i<n+offset;i++)
	{
		if(a[i] < dp[0])	// If a[i]<dp[0] then a[i]<all dp[i]
			dp[0]=a[i];

		else if(a[i] > dp[res-1])	// i.e. increasing subsequence can be extended
		{
			dp[res]=a[i];
			res++;
		}
		else	// find x such that dp[j]<a[i] for j<x and dp[j]>x for j>x and then update dp[x]
		{
			int x = binary_search(dp,res-1,a[i]);
			dp[x] = a[i];
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0);	// For fast i/o
	cin.tie(0);		// To Output answer for all the test cases in the end

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[2*n];		
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			a[i+n]=a[i];	// With this circular array can be implemented easily
		}
		int ans=0,temp;
		for(int i=0;i<n;i++)
		{
			// Finding Longest increasing subsequence for array starting at a[i] to a[i + n-1]
			temp = find_lis(a,i,n);
			
			// Updating ans
			ans = max(ans,temp);
		}
		cout<<ans<<"\n";
	}
}