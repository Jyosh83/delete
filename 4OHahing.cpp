#include<iostream>
using namespace std;

class Dict
{
	string key;
	string value;
	public:
		Dict()
		{
			key = '\0';
			value = '\0';
			
		}
		void scan()
		{
			cin.ignore(1);
			cout<<"Enter the Key: "<<endl;
			getline(cin,key);
			cout<<"Enter the Value: "<<endl;
			getline(cin,value);
			
		}
		friend class Node;
		friend class hash;
		friend int main();
};
class Node
{
	Dict data;
	Node * next;
	public:
		friend class hash;
		Node()
		{
			next = NULL;
			
		}
		Node(Dict d)
		{
			data = d;
			next = NULL;
		}
	
	friend class Dict;
};
class hash
{
	Node * hash_table[26];
	public:
		friend class Node;
		friend class Dict;
		friend int main();
		hash()
		{
			for(int i=0;i<26;i++)
			{
				hash_table[i] = new Node();
				hash_table[i]->data.key = 'a' + i;
			}
		}
		int find_ind(string k)
		{
			char c = k[0];
			int ind = c - 'a';
			return ind;
			//return (3*ind+5)%10 for another question
		}
		void insert(Dict temp)
		{
			int ind = find_ind(temp.key);
			Node * q = hash_table[ind];
			Node * p = hash_table[ind]->next;
			while(p!=NULL)
			{
				if(p->data.key>temp.key)
				{
					break;

				}
				q = p;
				p = p->next;
				
			}
			Node * s = new Node(temp);
			s->next = p;
			q->next = s;
		}
		int find(string key)
		{
			int ind = find_ind(key); 
			Node * p = hash_table[ind]->next;
			while(p!=NULL)
			{
				if(p->data.key == key)
				{
					return 1;
				}
				p = p->next;
			}
			return 0;
			
		}
		void delete_(string key)
		{
			int ind = find_ind(key);
			Node * q= hash_table[ind];
			Node  * p = q->next;
			while(p!=NULL)
			{
				if(p->data.key == key)
				{
					break;
				}
				q = p;
				p = p->next;
			}
			q->next = p->next;
			delete p;
		}
		void show()
		{
			for(int i=0;i<26;i++)
			{
			cout<<"\n"<<hash_table[i]->data.key<<" : ";
			Node * p = hash_table[i]->next;
			while(p!= NULL)
			{
				cout<<" ("<<p->data.key<<" , "<<p->data.value<<" )"<<" -> ";
				p = p->next;
				
			}
				
			}
		}
	
};
int main()
{
	hash h;
	Dict d;
	int choice;
	string key;
	while(1)
	{
	cout<<"\n***** MENU ******";
		cout<<"\n1.Insert";
		cout<<"\n2.Show";
		cout<<"\n3.Find";
		cout<<"\n4.Delete";
		cout<<"\nEnter your choice : ";
		cin>>choice;	
		switch (choice)
		{
			case 1:
				d.scan();
				h.insert(d);
				break;
			case 2:
		    	h.show();
			    break;
			case 3:
				cin.ignore(1);
				cout<<"\nEnter key to find : ";
				getline(cin,key);
				if(h.find(key))
				{
					cout<<"\n"<<key<<" found !";
				}
				else
				{
					cout<<"\n"<<key<<" not found !";
				}
				break;
			case 4:
				cin.ignore(1);
				cout<<"\nEnter key to delete : ";
				getline(cin,key);
				h.delete_(key);
				break;
		}
	}
	return 0;
}

