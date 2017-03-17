#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int start, dest, cost;
};

int main(){
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);

	clock_t clk;

	int T;
	cin>>T;
	while(T--)
	{
		clk=clock();
		int v,e,source;
		bool negative = false;
		cin>>v>>e;
		cin>>source;
		Edge *edge;
		edge = new Edge[e];
		for(int i=0;i<e;i++){
			cin>>edge[i].start>>edge[i].dest>>edge[i].cost;
		}

		

		int *dist;
		dist = new int[v];
		for(int i=0;i<v;i++){
			dist[i]=INT_MAX;
		}
		dist[source]=0;
		int a,b,c;
		int check;
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<e;j++)
			{
				a=edge[j].start; b=edge[j].dest; c=edge[j].cost;
				if(dist[a] != INT_MAX)
				{
					if(dist[b] > (dist[a]+c))
					{
							dist[b] = dist[a]+c;
					}
					if(dist[b] > (dist[a]+c))
					{
						cout<<"Graph contains negative weight cycle\n";
						negative = true;
						//break;
					}
				}
			}
		}
		
		for(int j=0;j<e;j++)
		{
			a=edge[j].start; b=edge[j].dest; c=edge[j].cost;
			if(dist[a] != INT_MAX)
			{
				if(dist[b] > (dist[a]+c))
				{
					cout<<"Graph contains negative weight cycle\n";
					negative = true;
					break;
				}
			}
		}
		
		if(!negative)
		{
			cout<<"\nDistance of all vertices from the source vertex:\n";
			cout<<"Output Format :\nVertex:  Distance from source\n";
			for(int i=0;i<v;i++)
			{
				cout<<i<<":  ";
				if(dist[i]==INT_MAX)
					cout<<"INF"<<endl;
				
				else
					cout<<dist[i]<<endl;
			}
			cout<<endl;
		}

		clk = clock() - clk;

		printf("Time Taken: %.6lf seconds\n", ((double)clk)/CLOCKS_PER_SEC);

		// cout<<"Time Taken:  ";
		// cout<<fixed<<setprecision(6)<<(((double)clk)/CLOCKS_PER_SEC)<<"\n";	
	}
	return 0;
}