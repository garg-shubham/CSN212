// Gift wrapping algorithm for finding the convex hull points
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define mp make_pair
#define pb push_back
#define x first
#define y second
 
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int orientation(pii a, pii b, pii c){
	int temp = a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
	if(temp>0) return 1;		// counterclockwise
	if(temp<0) return -1;		// Clockwise
	return 0;					// Colinear
}


int main()
{
	int n;
	cin>>n;
	if(n<3)		// n>=3 for closed polygon
		return 0;

	vector <pii> hull;
	pii point[n];

	clock_t t;		// Starting clock
	t=clock();
	
	for(int i=0;i<n;i++)
	{
		// input of n points
		cin>>point[i].x>>point[i].y;
	}

	// find the left-most point
	int l=0;
	for(int i=1;i<n;i++)
	{
		if(point[i].x<point[l].x)
			l=i;
	}

	//start from the leftmost point, keep moving clockwise
	//until we reach the start point again.
	int p=l,q;
	do
	{
		//find a point q which is most clockwise than all others
		//assume some point q and replace a more clockwise point found
		hull.pb(point[p]);
		q= (p+1)%n;
		for(int i=0;i<n;i++)
		{
			if( orientation(point[p],point[q],point[i]) == 1 )
				q=i;
		}

		p=q;

	}while(p!=l)	//while we don't reach back to the first point

	t=clock()-t;

	// Print Result
	for(int i=0;i<hull.size();i++)
	{
		cout<<"("<<hull[i].x<<<" , "<<hull[i].y<<")\n";
	}

	printf ("It took %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
	return 0;
}