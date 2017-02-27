#include <bits/stdc++.h>
#define ll long long

using namespace std;
int sequence[51];

// Solving Method
int longestZigZag(int* a,int count)
{
	int last_inc[count],last_dec[count];		
	// last_inc[i] stores the length of subsequence in subarray[0:i] which ends with positive last difference and ending at i
	// last_dec[i] stores the length of subsequence in subarray[0:i] which ends with negative last difference and ending at i
	

	last_inc[0]=last_dec[0]=1;	// Base Case
	
	for(int i=1;i<count;i++)
	{
		if(a[i]>a[i-1])		
		{
			// If two continous no.s have positive difference then
			// length of subsequence in subarray[0:i] which ends with positive last difference
			// will increment because a[i] will get added to subsequence of last_dec[i-1]
			last_inc[i] = last_dec[i-1] + 1;

			// However a[i] will replace the last element of subsequence of last_dec[i-1]
			// to make valid subsequence for last_dec[i] thus keeping the length same
			last_dec[i] = last_dec[i-1];
		}

		else if(a[i]<a[i-1])
		{
			// Vice versa of what explained in above condition
			last_dec[i] = last_inc[i-1] + 1;
			last_inc[i]= last_inc[i-1];
		}
		else
		{
			// If a[i]==a[i-1] , so no change in any of the subsequence is observed
			last_inc[i] = last_inc[i-1];
			last_dec[i] = last_dec[i-1];
		}
	}

	// Final answer is max of given two
	return max(last_dec[count-1],last_inc[count-1]);
}

int main()
{
	int j=0,count=0;
	string s;
	getline(cin,s);
	int x=0;

	// Changing string input to integers
	for(int i=2;i<s.size()-1;i++)
	{
		if(s[i]=='}')
			break;	
		if(s[i]==' ')
		{
			sequence[j]=x;
			j++;
			count++;
			x=0;
		}
		else if(s[i]==',')
		{}
		else
		{
			x= 10*x + s[i]-'0';
		}
	}
	//

	// Calling Solving Method to find answer
	cout<<longestZigZag(sequence,count)<<"\n";
}