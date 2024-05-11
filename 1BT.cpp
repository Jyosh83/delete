#include<iostream>
#include<queue>
#define MAX 100
using namespace std;
class Node
{
    int data;
    Node* lchild;
    Node* rchild;
public:
    Node()
    {
        data=0;
        lchild=NULL;
        rchild=NULL;
    }
    Node(int x)
    {
        data=x;
        lchild=NULL;
        rchild=NULL;
    }
    
    friend class Tree;
};
class Queue
{
	int front,rear;
	Node * data[MAX];
	public:
		Queue()
		{
			front = -1;
			rear = -1;
		}
		int empty()
		{
			if(front == -1)
			{
				return 1;
				
			}
			return 0;
		}
		int full()
		{
			if(rear == MAX -1 )
			{
				return 1;
			}
			return 0;
		}
		void enqueue(Node * x)
		{
		 	if(!full())
		 	{
		 		
		 		if(empty())
				{
				 	front++;
				}
				else
				{
					rear++;
					data[rear] = x;
				 } 
		 		
			}
			else
			{
				cout<<"\n\nQueue is fULL"<<endl;
			}
		}
		Node * dequeue( )
		{
			if(!empty())
			{
				Node * t = data[front];
				if(front == rear)
				{
					front = rear = -1;
				}
				else
				{
					front++;
				}
				return t;
			}
			else
			{
				cout<<"Queue Empty "<<endl;
				return 0;
			}
		}
};
class Stack
{
    Node* data[MAX];
    int top;
public:
    Stack()
    {
        top= -1;
        
    }
    int full()
    {
        if(top==MAX-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int empty()
    {
        if(top==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void push(Node* x)
    {
        if(full())
        {
            cout<<"\nstack is full cannot push";
            return;
        }
        else
        {
            top++;
            data[top]=x;
        }
    }
    Node* pop()
    {
        Node* t;
        if(empty())
        {
            cout<<"\nstack is already empty cannot pop";
            return 0;
        }
        else
        {
            t=data[top];
            top--;
            
        }
        return t;
    }
   
};
class Tree
{
    Node* root;
    Node* maketree();
public:
    Tree()
    {
        root=NULL;
    }
    void create()
    {
        root=maketree();
    }
    void recursive_traversal();
    void recursive_preorder(Node*);
    void recursive_inorder(Node*);
    void recursive_postorder(Node*);
    void iterative_traversal();
    void iterative_preorder(Node*);
    void iterative_inorder(Node*);
    void iterative_postorder(Node*);
    Node* getroot()
    {
        return root;
    }
    void swap(Node*);
    int height(Node*);
    void level_node(Node * root);
    Tree& operator=(Tree& T);
    Node* copy(Node* t);
    int leafcount(Node*);
    int internalnodes(Node*);
    void deletenode(Node*);
};
void Tree::level_node(Node* root) 
{
    Queue q;
    if (root == NULL)
	{
        return;
    }
    q.enqueue(root);
    q.enqueue(NULL);

    while (!q.empty())
	  {
        Node* t = q.dequeue();

        if (t == NULL) 
		  {
            cout << endl; 
            if (q.empty())
				{
                break;
                
            }
				else 
				{
                q.enqueue(NULL);
            }
        } 
		  else 
		  {
            cout << t->data << " "; 
            if (t->lchild != NULL)
				 {
                q.enqueue(t->lchild);
            }
            if (t->rchild != NULL)
				 {
                q.enqueue(t->rchild);
            }
        }
    }
};

Node* Tree::maketree()
{
    Node* temp;
    char ch;
    temp=new Node();
    cout<<"\nEnter data of root node: ";
    cin>>temp->data;
    cout<<"\nEnter right child (y/n)?"<<temp->data<<endl;
    cin>>ch;
    if(ch=='y')
    {
        temp->rchild=maketree();
        
    }
    cout<<"\nEnter left child(y/n)?: "<<temp->data<<endl;
    cin>>ch;
    if(ch=='y')
    {
        temp->lchild=maketree();
    }
    return temp;
}
void Tree::recursive_inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        recursive_inorder(root->lchild);
        cout<<root->data<<" ";
        recursive_inorder(root->rchild);
    }
}
void Tree::recursive_preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        cout<<root->data<<" ";
        recursive_preorder(root->lchild);
        recursive_preorder(root->rchild);
    }
}
void Tree::recursive_postorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        recursive_postorder(root->lchild);
        recursive_postorder(root->rchild);
        cout<<root->data<<" ";
    }
    
}
void Tree:: recursive_traversal()
{
    Node* temp=root;
    
    int n;
    cout<<"\nENTER YOUR CHOICE---WHICH RECURSIVE TRAVERSAL YOU WANT TO PERFORM:\n1:preorder\n2:inorder\n3:postorder\n4:exit";
    cin>>n;
    switch(n)
    {
        case 1:recursive_preorder(temp);
            break;
        case 2:
            recursive_inorder(temp);
            break;
        case 3:
            recursive_postorder(temp);
            break;
        case 4:exit(0);
    }
    
    
}
void Tree:: iterative_traversal()
{
    Node* temp=root;
    int n;
    cout<<"\nENTER YOUR CHOICE---WHICH ITERATIVE TRAVERSAL YOU WANT TO PERFORM:\n1:preorder\n2:inorder\n3:postorder\n4:exit";
    cin>>n;
    switch(n)
    {
        case 1:iterative_preorder(temp);
            break;
        case 2:
            iterative_inorder(temp);
            break;
        case 3:
            iterative_postorder(temp);
            level_node(temp);
              
            break;
        case 4:exit(0);
    }
    
}
void Tree::iterative_preorder(Node *root)
{
    Node* t=root;
    Stack s;
    while(t!=NULL)
    {
        cout<<t->data;
        s.push(t);
        t=t->lchild;
    }
    while(!s.empty())
    {
        t=s.pop();
        t=t->rchild;
        while(t!=NULL)
        {
            cout<<t->data<<" ";
            s.push(t);
            t=t->lchild;
        }
    }
}
void Tree::iterative_inorder(Node *root)
{
    Node* t=root;
    Stack  s;
    while(t!=NULL)
    {
        s.push(t);
        t=t->lchild;
    }
    while(!s.empty())
    {
        t=s.pop();
        cout<<t->data<<" ";
        t=t->rchild;
        while(t!=NULL)
        {
            s.push(t);
            t=t->lchild;
        }
    }
}
void Tree::iterative_postorder(Node *root)
{
    Node* t=root;
    Stack s1,s2;
    s1.push(t);
    while(!s1.empty())
    {
        t=s1.pop();
        s2.push(t);
        if(t->lchild!=NULL)
        {
            s1.push(t->lchild);
        }
        if(t->rchild!=NULL)
        {
            s1.push(t->rchild);
        }
    }
    while(!s2.empty())
    {
        t=s2.pop();
        cout<<t->data<<" ";
    }
}
void Tree::swap(Node* t)
{
    
    if(t==NULL)
    {
        return;
    }
    else
    {
        swap(t->lchild);
        swap(t->rchild);
        Node* temp=t->lchild;
        t->lchild=t->rchild;
        t->rchild=temp;
        
    }
    
}
int Tree::height(Node* t)
{
    if(t==NULL)
    {
        return 0;
    }
    else
    {
        int ldepth=height(t->lchild);
        int rdepth=height(t->rchild);
        if(ldepth>rdepth)
        {
            return ldepth+1;
        }
        else
        {
            return rdepth+1;
        }
    }
}
Tree& Tree:: operator=(Tree& T)
{
    Tree cpy;
    cpy.root=T.root;
    return cpy;
}
Node* Tree::copy(Node* t)
{
    if(t==NULL)
    {
        return NULL;
    }
    else
    {
        Node* T=new Node();
        T->data=t->data;
        if(t->lchild==NULL)
        {
            T->lchild=NULL;
        }
        else
        {
            T->lchild=copy(t->lchild);
        }
        if(t->rchild==NULL)
        {
            T->rchild=NULL;
        }
        else
        {
            T->rchild=copy(t->rchild);
        }
        return T;
        
    }
    
}
int Tree::leafcount(Node* p)
{
    if(p==NULL)
    {
        return 0;
    }
    else if(p->rchild==NULL && p->lchild==NULL)
    {
        return 1;
    }
    else
    {
        return leafcount(p->lchild)+leafcount(p->rchild);
    }
    
}
int Tree::internalnodes(Node* p)
{
    if(p==NULL || (p->rchild==NULL && p->lchild==NULL))
    {
        return 0;
    }
    else
    {
        return (1+internalnodes(p->rchild)+internalnodes(p->lchild));
    }
    
}
void Tree::deletenode(Node* t)
{
    if(t==NULL)
    {
        return;
    }
    else
    {
        if(t->lchild)
        {
            deletenode(t->lchild);
        }
        if(t->rchild)
        {
            deletenode(t->rchild);
        }
    }
    delete t;
}
int main()
{
//	Tree t,cpy;
     Tree t;
    t.create();
    Node * temp = t.getroot();
    t.level_node(temp);
//    t.recursive_traversal();
//    t.level_node(t.getroot());
//	 //t.iterative_traversal();
//    t.swap(t.getroot());
//    cout<<"\nswapped!!!!";
//    t.recursive_traversal();
//    
//    
//    int h=t.height(t.getroot());
//    cout<<"\nHeight of tree is:"<<h;
//    
//    cpy=t;
//    cout<<"\nTree is copied";
//    cpy.recursive_traversal();
//    
//    int l=t.leafcount(t.getroot());
//    cout<<"\nleaf nodes="<<l;
//    
//    int i=t.internalnodes(t.getroot());
//    cout<<"\ninternal nodes="<<i;
//    t.deletenode(t.getroot());
//    t.recursive_traversal();
    
  
    
}