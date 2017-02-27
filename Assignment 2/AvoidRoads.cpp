#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ans[101][101]={0};
int lr[101][101]={0};
int td[101][101]={0};
int main()
{
	int width,height;
	cin>>width>>height;

	string s;
	getline(cin,s);
	getline(cin,s);
	int x=0;
	int input[4];
	for(int i=1;i<s.size();i++)
	{
		if(s[i]=='"')
		{

			for(int j=0;j<4;j++)
			{
				x=0;
				while(s[i]!=' '||s[i]!='"')
				{
					x = 10*x + s[i] -'0';
					i++;
				}
				input[j]=x;
			}
			if(input[0]==input[2])
			{
				if(input[1]>input[3])
					lr[input[0]][input[1]]=-1;
				else
					lr[input[2]][input[3]]=-1;
			}
			else
			{
				if(input[0]>input[2])
					td[input[0]][input[1]]=-1;
				else
					td[input[2]][input[3]]=-1;
			}
			while(s[i]!=',' || s[i]!='}')
				i++;
		}
		else
		{}
	}
	for(int i=0;i<width;i++)
	{
		for(int j=0;j<height;j++)
		{
			if(i==0 && j==0)
				ans[i][j]=1;
			else if(j==0)
			{
				ans[i][j] = 1;
				if(lr[i][j]=-1)
					ans[i][j]=0;
			}
			else if(i==0)
			{
				ans[i][j]=1;
				if(td[i][j]==-1)
					ans[i][j]=0;
			}
			else
			{
				ans[i][j]=0;
				if(lr[i][j]!=-1)
					ans[i][j]+=ans[i-1][j];
				if(td[i][j]!=-1)
					ans[i][j] += ans[i][j-1];
			}
		}
	}
	cout<<ans[width-1][height-1]<<"\n";
}