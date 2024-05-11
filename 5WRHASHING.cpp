#include<iostream>
#include<iomanip>
using namespace std;
class Client
{
	string name;
	long long int pno;
	public:
		Client()
		{
			name = '\0';
			pno = 0;
		}
		void scan()
		{
			cin.ignore(1);
			cout<<"Enter the Name of Client :" <<endl;
			getline(cin,name);
			
			cout<<"Enter the Phone Number of Client :"<<endl;
			cin>>pno;
			
		}
		friend class hash;
		
};
class hash
{
	Client * table_wr;
	Client * table_wor;
	int size;
	public:
			hash()
			{
				cout<<"Enter the Size of Your HashTable: "<<endl;
				cin>>size;
				table_wr = new Client[size];
				table_wor = new Client[size];
			}
		
			int comparison_wor(Client x)
			{
				int key =(x.pno) % size;
				int i;
				int count = 1;
				if(table_wor[key].pno  == x.pno && table_wor[key].name == x.name)
				{
					count = 1;
					return count;
				}
				else
				{
					i = key+1;
					while(table_wor[i].pno != x.pno && table_wor[key].name!=x.name)
					{
						if(key == i)
						{
							cout<<"NOT FOUND";
							return 0;
							
						}
						i = (i+1)%size;
						count++;
					}
					return count+1;
					
				}
			}
			int comparison_wr(Client x)
			{
				int key =x.pno % size;
				int i;
				int count = 1;
				if(table_wr[key].pno  == x.pno && table_wr[key].name == x.name)
				{
					count = 1;
					return count;
				}
				else
				{
					i = key+1;
					while(table_wr[i].pno != x.pno && table_wr[key].name!=x.name)
					{
						if(key == i)
						{
							cout<<"NOT FOUND";
							return 0 ;
							
						}
						i = (i+1)%size;
						count++;
					}
					return count+1;
					
				}
			}
			void lp_wor(Client x)
			{
			int key = (x.pno)%size;
			if(table_wor[key].pno == 0)
			{
				table_wor[key] = x;
			}
			else
			{
				int i = key+1;
				while(table_wor[i].pno != 0)
				{
					
					if(i == key)
					{
						cout<<"FULL";
						return;
					}
					i = (i+1)%size;
				}
				table_wor[i] = x;			
			}
			
			}
			void lp_wr(Client x)
			{
			int key = (x.pno)%size;
			if(table_wr[key].pno == 0)
			{
				table_wr[key] = x;
			}
			else
			{
				Client temp;
				if(table_wr[key].pno%size != key)
				{
					temp =table_wr[key];					
					table_wr[key] = x;
					x = temp;
					
				}
				int i = key+1;
				while(table_wr[i].pno != 0)
				{
					
					if(i == key)
					{
						cout<<"FULL";
						return;
					}
					i = (i+1)%size;
				}
				table_wr[i] = x;			
			}
			}
			void delete_wor(Client x)
			{
				int key = x.pno % size;
				int i;
				if(table_wor[key].pno == x.pno && table_wor[key].name == x.name)
				{
					table_wor[key].pno = 0;
					table_wor[key].name = " ";
				}
				else
				{
					i = key + 1;
					while(table_wor[i].pno != x.pno && table_wor[key].name!=x.name)
					{
						if(key == i)
						{
							cout<<"NOT FOUND";
							return;
							
						}
						i = (i+1)%size;
					}
					table_wor[i].pno = 0;
					table_wor[i].name = '\0';
				}
			}
			void delete_wr(Client x)
			{
				int key = x.pno % size;
				int i;
				if(table_wr[key].pno == x.pno && table_wr[key].name == x.name)
				{
					table_wr[key].pno = 0;
					table_wr[key].name = " ";
				}
				else
				{
					i = key + 1;
					while(table_wr[i].pno != x.pno && table_wr[key].name!=x.name)
					{
						if(key == i)
						{
							cout<<"NOT FOUND";
							return;
							
						}
						i = (i+1)%size;
					}
					table_wr[i].pno = 0;
					table_wr[i].name = " ";
				}
			}
		void show()
		{	
		cout<<"Linear Probing with Replacement"<<setw(40)<<"Linear Probing without Replacement";
		for(int i=0;i<size;i++)
		{
			cout<<"\n"<<i<<" : ("<<table_wr[i].name<<" , "<<table_wr[i].pno<<")"<<setw(20)<<i<<" : ("<<table_wor[i].name<<" , "<<table_wor[i].pno<<")";
		}
		}
		friend class Client;
		
		};
			
int main()
{
	hash h;
	Client c;
	long long int x;
	int choice;
	while(1)
	{
		cout<<"\n*********** MENU *************";
		cout<<"\n1.Insert";
		cout<<"\n2.Show";
		cout<<"\n3.Comparisons";
		cout<<"\n4.Delete";
		cout<<"\nEnter choice : ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			c.scan();
			h.lp_wor(c);  
			h.lp_wr(c);
			break;
		case 2:
			h.show();
			break;
		case 3:
			cout<<"\nEnter the client details to find : ";
			c.scan();
			cout<<"\nComparisons without replacement : "<<h.comparison_wor(c);
			cout<<"\nComparisons with replacement : "<<h.comparison_wr(c);  
			break;            //9149412561
		case 4:
			cout<<"\nEnter the client details to delete : ";
			c.scan();
			h.delete_wor(c);
			h.delete_wr(c);
			case 5:
				exit(0);
				
		}
	}
	return 0;
}

