#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[105][105]={0};		// To store the answers of subproblems
int lr[105][105]={0};		// To store which edges are blocking left-to-right traversal
int dt[105][105]={0};		// To store which edges are blocking down-to-top traversal
int input[4];				

int main()
{
	int width,height;
	cin>>width>>height;

	string s;
	getline(cin,s);
	if(s=="")				// Because getline makes error of
		getline(cin,s);		// taking an empty line as input sometimes
	//cout<<s<<"\n";		// if there is some other input taken before it
	int x=0;
	
	for(int i=1;i<s.size();i++)			
	{
		if(s[i]=='\"')		//Because one set of input is provided within inverted commas
		{
			i++;
			for(int j=0;j<4;j++)
			{
				x=0;
				while(s[i]!=' ' && s[i]!='\"')		// Any two no.s are differentiated using space and set of no.s ends with ".
				{
					x = 10*x + s[i] -'0';
					i++;
				}
				input[j]=x;
				i++;
				//cout<<input[j]<<" ";
			}
			//cout<<"\n";
			if(input[0]==input[2])		// To determine whether it stops the left-right traversal or top-dow traversal
			{
				if(input[1]>input[3])
					dt[input[0]][input[1]]=1;
				else
					dt[input[2]][input[3]]=1;
			}
			else
			{
				if(input[0]>input[2])
					lr[input[0]][input[1]]=1;
				else
					lr[input[2]][input[3]]=1;
			}
			while(s[i]!=',' && s[i]!='}')		// To deal with any extra characters i.e. spaces that might be provided
				i++;
		}
	}

	//Debugging
	/*
	for(int j=0;j<=height;j++)
	{
		for(int i=0;i<=width;i++)
			cout<<lr[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
	for(int j=0;j<=height;j++)
	{
		for(int i=0;i<=width;i++)
			cout<<dt[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
	*/

	// Calculating No. of Paths

	for(int j=0;j<=height;j++)
	{
		for(int i=0;i<=width;i++)
		{
			// Base Case
			if(i==0 && j==0)		
				dp[i][j]=1;
	
			// if still on height 0, only path is left-to-right.
			else if(j==0)
			{
				dp[i][j] = dp[i-1][j];
				if(lr[i][j]==1)
				{
					//cout<<"dt";
					dp[i][j]=0;
				}
			}

			// If still on width 0, only path is down to up.
			else if(i==0)
			{
				dp[i][j]=dp[i][j-1];
				if(dt[i][j]==1)
				{
					//cout<<"lr";
					dp[i][j]=0;
				}
			}

			// Main case
			else
			{
				dp[i][j]=0;
				if(lr[i][j]!=1)
					dp[i][j] += dp[i-1][j];
				if(dt[i][j]!=1)
					dp[i][j] += dp[i][j-1];
			}
			//cout<<dp[i][j]<<" ";
		}
		//cout<<"\n";
	}
	
	cout<<dp[width][height]<<"\n";
}