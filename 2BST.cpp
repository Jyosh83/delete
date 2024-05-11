#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int cnt=0;
class Node
{
    int data;
    Node*left;
    Node*right;
    public:
        Node(int d)
        {
            data=d;
            left=right=NULL;
        }
        friend class BST;
};

class BST
{
    Node* root;
    public:
        BST()
        {
            root=NULL;
        }
        Node*& getRoot()
        {
            Node *&p=root;
            return p;
        }
        void takeInput(Node*&root);
        Node* create(Node*&,int);
        void ascending();
        int search(Node* temp,int x);
        void levelOrder();
        void descending();
        Node* delete_node(Node*&,int);
        Node* inorderSucces(Node*);
};
void BST::takeInput(Node*&root)
{
    int d;
    cout<<"\nEnter data = ";
    cin>>d;
    while(d!=-1)
    {
        root=create(root,d);
        cout<<"\nEnter data = ";
        cin>>d;
    }
}
Node* BST::create(Node*&root,int x)
{
   if(root==NULL)
   {
        root=new Node(x);
        return root;
   }
   if(x <root->data)
   {
        root->left=create(root->left,x);
   }
   if(x > root->data)
   {
    root->right=create(root->right,x);
   }
   return root;
    
}
void BST::ascending()
{
    stack<Node*>s;
    Node*temp=root;
    while(temp!=NULL)
    {
        s.push(temp);
        temp=temp->left;
    }
    while(!s.empty())
    {
        temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        temp=temp->right;
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
    }
}
int BST::search(Node*temp,int x)
{
    int res;
    if(temp==NULL)
    {
        return 0;
    }
    if(temp->data==x)
    {
        cnt++;
        return 1;
    }
    if(x <temp->data)
    {
        cnt++;
        res=search(temp->left,x);
    }
    else
    {
        cnt++;
        res=search(temp->right,x);
    }
    return res;
}
void BST::levelOrder()
{
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node*temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(q.empty())
            {
                break;
            }
            else
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void BST::descending()
{
    stack<Node*>s;
    Node*temp=root;
    while(temp!=NULL)
    {
        s.push(temp);
        temp=temp->right;
    }
    while(!s.empty())
    {
        temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        temp=temp->left;
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->right;
        }
    }
}
Node* BST::delete_node(Node*&root,int x)
{
    if(root==NULL)
    {
        return root;
    }
    if(x<root->data)
    {
        root->left=delete_node(root->left,x);
        return root;
    }
    else if(x>root->data)
    {
        root->right=delete_node(root->right,x);
        return root;
    }
    else
    {

        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        else if(root->left==NULL)
        {
            Node*temp=root->right;
            delete root;
            return temp;
        }
        else if (root->right==NULL)
        {
            Node*temp=root->left;
            delete root;
            return temp;
        }
       else if(root->right!=NULL && root->left!=NULL)
        {
             Node*IS=inorderSucces(root->right);
            root->data=IS->data;
            root->right=delete_node(root->right,IS->data);
            return root;
        }
       
    }
    
}
Node* BST::inorderSucces(Node*temp)
{
    Node*t=temp;
    while(t->left!=NULL)
    {
        t=t->left;
    }
    return t;


}
Node *findmin()
{
	Node * t = root;
	if(t == null)
	{
		return n;
	}
	while(t->left !=NULL)
	{
		t =t->left;		
	}
	return  t;
}
int main()
{
    BST T1;
    T1.takeInput(T1.getRoot());
    T1.ascending();
    cout<<endl;
    // int x;
    // cout<<"\nenter data to search = ";
    // cin>>x;
    // if(T1.search(T1.getRoot(),x))
    // {
    //     cout<<"\nFound";
    // }
    // else
    // {
    //     cout<<"\nnot Found";
    // }
    // cout<<"\nnumber of comparison to search "<<x<<" is "<<cnt;
    // cout<<endl;
    // T1.levelOrder();
    T1.descending();

    int y;
    cout<<"\nenter data to delete = ";
    cin>>y;
    T1.delete_node(T1.getRoot(),y);
    T1.ascending();
    return 0;
    /*int BST:: no_of_nodes_in_longest_path(Node* t)
{
    if(t==NULL)
    {
      return 0;
    }
    else if(t->lchild==NULL && t->rchild==NULL)
    {
       return 1;
    }
    else
    {

        int lheight=no_of_nodes_in_longest_path(t->lchild);

        int rheight=no_of_nodes_in_longest_path(t->rchild);

        if(lheight>rheight)
        {
            return lheight+1;
        }
        else
        {
            return rheight+1;
        }
 	}
	}
	void BST::swap(Node* t)
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
        t->rchild=NULL;
    }
}
*/
