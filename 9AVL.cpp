#include<iostream>
using namespace std;
class Node
{
	Node * left;
	Node * right;
	string keyword;
	string meaning;
	public: 
			Node()
			{
				left = NULL;
				right = NULL;
				keyword = " ";
				meaning = " ";
			}
			Node(string k,string m)
			{
				keyword = k;
				meaning = m;
				left = NULL;
				right = NULL;
			}
			friend class AVL;
};
class AVL
{
			Node * root;
	public:
		AVL()
		{
			root = NULL;	
		}
		void create()
		{
			string x,m;
			cout<<"KEEP ENTERING THE Word and Meaning/ENTER stop to STOP: "<<endl;
			while(1)
			{
				cout<<"Enter the Keyword: "<<endl;
				getline(cin,x);
				cout<<"Enter the Meaning of Your Keyword: "<<endl;
				getline(cin,m);
				if(x == "stop")
				{
					break;
				}
				root = insert(root,x,m);
			}
		}
		Node * insert(Node * t,string x,string m)
		{
			if(t == NULL)
			{
				t = new Node(x,m);
				return t;
			}
			else if(t->keyword > x)
			{
				t->left = insert(t->left,x,m);
				
				if(balancedfactor(t)>=2)
				{
					if(t->left->keyword<x)
					{
						t = leftright(t);
					}
					else
					{
						t = rotateright(t);
					}
				}
				return t;
			}
			else if(t->keyword < x)
			{
				t->right = insert(t->right,x,m);
				if((balancedfactor(t))<= -2)
				{
					if(t->right->keyword < x)
					{
						t = rotateleft(t);
					}
					else
					{
						t = rightleft(t);
					}
				}
			}
			cout<<"Duplicate Entry "<<endl;
			return t;
		}
		
		Node * rotateright(Node * t)
		{
			Node * p = t->left;
			t->left = p->left;
			return p;	
		}
		Node * rotateleft(Node * t)
		{
			Node * p = t->right;
			t->right = p->right;
			return p;
			
		}
		
		Node * leftright(Node * t)
		{
			t->left = rotateleft(t->left);
			t = rotateright(t);
			return t;
		}
		
		Node * rightleft(Node * t)
		{
			t->right = rotateright(t->right);
			t = rotateleft(t);
			return t;
		}
		Node * inorder(Node * t)
		{
			if(t == NULL)
			{
				return NULL;
			}
			inorder(t->left);
			cout<<"  "<<t->keyword<<" : "<<t->meaning<<"  "<<endl;
			inorder(t->right);
		}
		int balancedfactor(Node * t)
		{
			if(t == NULL)
			{
				return 0;
			}
			else
			{
				int lh = height(t->left);
				int lr = height(t->right);
				return lh-lr;
			}
		}
		int height(Node * t)
		{
			if(t == NULL)
			{
				return 0;
			}
			return max(height(t->left),height((t->right))+1);
			
		}
		Node * getroot()
		{
			return root;
		}
};



int main()
{
	AVL obj;
	Node *t;
	obj.create();
	t = obj.getroot();
	obj.inorder(t);



return 0;
}

