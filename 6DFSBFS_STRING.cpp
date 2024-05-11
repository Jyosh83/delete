#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;
class Graph
{
	int ** adj;
	int * visited;
	int ver;

	public:
		bool type;
		Graph(int n)
		{
			ver = n;
			adj = new int*[n];
			for(int i =0;i<n;i++)
			{
				adj[i] = new int[n];
				for(int j = 0;j<ver;j++)
				{
					adj[i][j] = 0;
				}
								
			}
			visited = new int[n];
			for(int i =0;i<ver;i++)
			{
				visited[i] = false;
			}
			
		}
		void reset()
		{
			int i;
			for(i=0;i<ver;i++)
			{
				visited[i] = false;
			}
			return;
		}
		void addEdge(int vert1,int vert2)
		{
			adj[vert1][vert2] = 1;
			if(!type)
			{
				adj[vert2][vert1] = 1;
				
			}
			
		}
		void adj_disp(string arr[])
		{
			int i;
			for(i=0;i<ver;i++)
			{
				cout<<arr[i]<<" : ";
				for(int j=0;j<ver;j++)
				{
					if(adj[i][j]==1)
					{
						cout<<arr[j]<<" ";
					}
				}
				cout<<endl;
			}
		}
		void bfs_(int start,string arr[])
		{
			queue<int>q;
			q.push(start);
			visited[start] = true;
			while(!q.empty())
			{
				int front = q.front();
				q.pop();
				cout<<arr[front]<<" ";
				for(int i =0;i<ver;i++)
				{
					if(adj[front][i] == 1 && !visited[i])
					{
						q.push(i);
						visited[i] = true;
					}
				}
			}
		}
		void dfs(int start,string arr[])
		{
			cout<<" "<<arr[start];
			visited[start] = true;
			for(int i=0;i<ver;i++)
			{
					if(adj[start][i] == 1 && !visited[i])
					{
					dfs(i,arr);
						
					}
				
			}
		}
		void degree(string arr[])
		{
			int i;
			for(i=0;i<ver;i++)
			{
				int count = 0;
				cout<<" "<<arr[i]<<" : ";
				for(int j=0;j<ver;j++)
				{
					if(adj[i][j] == 1)
					{
						count++;
						
					}
				}
				cout<<count<<" "<<endl;
				
			}
		}
		//degree wala 
		
};

int main()
{
	int x;
	cout<<"Enter the Specification of Graph "<<endl;
	cout<<"Enter the No. of vertex of Graph: "<<endl;
	cin>>x;
	Graph gp(x);
	string * arr = new string[x];
	while(true)
	{
		
	int choice;
	cout<<"Enter choice \n1}Directed or Not \n2}Insert edge and location \n3}Degree \n4}BFS \n5]DFS \n6}Print adj_1 \n7}Exit"<<endl;
	cin>>choice;	
	int size,start;
	string loc;

	switch(choice)
	{
		case 1:
			cout<<"Is graph is directed : ";
			bool is;
			cin>>is;
			gp.type=is;
			break;
			
		case 2:
		
			cout<<"Enter number of edges you want in graph :";
			cin>>size;
			cin.ignore(1);
			for(int i=0;i<x;i++)
			{
				
				cout<<"Enter location : ";
				getline(cin,loc);
				arr[i]=loc;
			}
	
			while(size--)
			{
				cout<<"Enter edge : ";
				int a,b;
				cin>>a>>b;
				gp.addEdge(a,b);
			}
			break;
			
		case 3:
			
				gp.degree(arr);
				break;
				
		case 4:
				 cout<<"Enter starting point for BFS : ";
				
				cin>>start;
				gp.reset();
				gp.bfs_(start,arr);
				break;
		
		case 5:	
			cout<<"Enter starting point for DFS : ";
			
			cin>>start;
			gp.reset();
			gp.dfs(start,arr);
			break;
			
		case 6:
				gp. adj_disp(arr);
				break;
		case 7:		
			cout<<"Thank you ...... exiting"<<endl;
			exit(0);
		default:
				cout<<"Wrong Input Try Again "<<endl;
	}

	}	
}
