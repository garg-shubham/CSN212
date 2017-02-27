#include <bits/stdc++.h>
#define ll long long

using namespace std;
int sequence[51];

int longestZigZag(int* a,int count)
{
	int last_inc[count],last_dec[count];
	
	last_inc[0]=last_dec[0]=1;
	
	for(int i=1;i<count;i++)
	{
		if(a[i]>a[i-1])
		{
			last_inc[i] = max(last_inc[i-1],last_dec[i-1] +1);
			last_dec[i] = last_dec[i-1];
		}
		else if(a[i]<a[i-1])
		{
			last_dec[i] = max(last_dec[i-1], last_inc[i-1] + 1);
			last_inc[i]= last_inc[i-1];
		}
		else
		{
			last_inc[i] = last_inc[i-1];
			last_dec[i] = last_dec[i-1];
		}
	}

	return max(last_dec[count-1],last_inc[count-1]);
}

int main()
{
	int j=0,count=0;
	string s;
	getline(cin,s);
	int x=0;
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

	cout<<longestZigZag(sequence,count)<<"\n";
}