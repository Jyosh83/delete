#include<iostream>
#include<iomanip>
#define INF 99999
using namespace std;
class Tree
{
	int v,e,wt;
	int * visit,* from,* dist;
	int ** adj;
	string * office;
	int mindist;
	public:
		Tree()
		{
			v = e = 0;
			adj = NULL;
			office = NULL;
		}
		void read()
		{
			cout<<"\nEnter the No. of Offices = ";
			cin>>v;
			cout<<"\nEnter the No. of Connections = ";
			cin>>e;
			cin.ignore(1);
			adj = new int*[v];
			office = new string[v];
			int i,j;
			for(i=0;i<v;i++)
			{
				adj[i] = new int[v];
				for(j=0;j<v;j++)
				{
					
					adj[i][j] = 0;
					
				}
			}
				string s,d;
				int sis,did;
			for(i=0;i<e;i++)
			{
				cout<<"Enter the Source: "<<endl;
				getline(cin,s);
				cout<<"Enter the Destination: "<<endl;
				getline(cin,d);	
				cout<<endl;
				cout<<"Enter the Source id: "<<endl;
				cin>>sis;
				cout<<"Enter the Destination id: "<<endl;
				cin>>did;
				
				cout<<"Enter the Cost from "<<s<<" -> "<<d<<" = "<<endl;
				cin>>wt;
				cin.ignore(1);
				
				add(s,d,sis,did,wt);
			}
			for(i=0;i<v;i++)
			{
				for(j=0;j<v;j++)
				{
					if(adj[i][j] == 0)
					{
						adj[i][j] = INF;
					}	
				}
			}
			visit = new int[v];
			dist = new int[v];
			from = new int[v];
			int source = 0;
			for(i=0;i<v;i++)
			{
				visit[i] = 0;
				dist[i] = adj[source][i];
				from[i] = source;
			}
			visit[source] = 1;
			dist[source] = 0;
			
		}
		void add(string s,string d,int sis,int did,int cost)
		{
			office[sis] = s;
			office[did] = d;
			
			adj[sis][did] = cost;
			adj[did][sis] = cost;
		}
		void prims()
		{
			int V,U;
			int sum = 0;
			int e = v-1;
		//	mindist = INF;
			while(e>0)
			{
				mindist = INF;
				for(int i=0;i<v;i++)
				{
					if(visit[i]==0 && mindist>dist[i])
					{
						mindist = dist[i];
						V = i;
					}		
				}
				visit[V] = 1;
				U = from[V];
				//sum wala bhul gya tha
				sum = sum + adj[V][U];
				for(int i=0;i<v;i++)
				{
					if(visit[i]==0 && dist[i]>adj[V][i])
					{
						//yaha pr dist of i is greater than apne matrix wale condn yaad rakhna
						dist[i] = adj[V][i];
						from[i] = V;
					}	
				}
				e--;
			}
			cout<<"\nMinimum Cost = "<<sum<<endl;
			
		}
		void display()
		{
			cout<<"\n Adjacency Matrix: "<<endl;
			int k;
			for(k=0;k<v;k++)
			{
				cout<<setw(8);
				cout<<office[k]<<" : ";
			}
			cout<<endl;
			for(int i=0;i<v;i++)
			{
				cout<<left<<office[i]<<left<<" :";
				for(int j=0;j<v;j++)
				{

					if(adj[i][j]<10)
					{
						cout<<"   "<<0<<adj[i][j]<<"    ";
						
					}
					else
					{
						cout<<"   "<<adj[i][j]<<"    ";
					}
				
				}
				cout<<endl;
			}
		}
};
int main()
{
	Tree T;
	T.read();
	T.prims();
	T.display();
	return 0;
	
}
