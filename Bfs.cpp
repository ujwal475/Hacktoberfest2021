//BFS
#include<iostream>
using namespace std;
class BFS
{
	int n,a[10][10],s[10],source;
	public:void bfs();
	void read_data();
	void print_data();
};
void BFS::read_data() 
{
	int i,j;
	cout<<"enter the number of node:"<<endl;
	cin>>n;
	cout<<"enter the adjacency matrix:"<<endl;
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
	     cin>>a[i][j];
	cout<<"enter the source: "<<endl;
	cin>>source;     
}
void BFS::print_data() 
{
	for(int i=0;i<n;i++)
	{
		if(s[i]==0)
		cout<<"vertex "<<i<<" is not reachable"<<endl;
		else
		cout<<"vertex "<<i<<" is reachable"<<endl;
	}
}
void BFS::bfs() 
{
	int i,u,v,f,r,q[10];
	for(i=0;i<n;i++)
	  s[i]=0;
	f=r=0;
	q[r]=source;
	s[source]=1;
	while(f<=r)
	{
		u=q[f++];
		for(v=0;v<n;v++)
		{
			if(a[u][v]==1 && s[v]==0)
			{
				s[v]=-1;
				q[++r]=v;
			}
		}
	}  
}
int main()
{
	BFS b;
	b.read_data();
	b.bfs();
	b.print_data();
	return 0; 
}
