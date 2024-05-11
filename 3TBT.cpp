#include <iostream>
using namespace std;
class node

{
    int data;
    node* left;
    node* right;
    bool lthread;
    bool rthread;
public:
    node()
    {
        data = 0;
        left = NULL;
        right = NULL;
        lthread = 1;
        rthread = 1;
    }
    friend class tbt;
};
class tbt
{
    node* root;
    node* head;
public:
    tbt()
    {
        root = NULL;
        head = new node;
    }
    void create()
    {
        int x;
        cout << "\nKeep entering data = ";
        while (1)
        {
            cin >> x;
            if (x == 0)
            {
                return;
            }
            insert(x);
        }
    }
    void insert(int x);
    void inorder(node* c);
    node* inordersucc(node* c);
    node* get_root();
    node* preorder(node* c);
    void remove(int x);
};
void tbt::insert(int x)
{
    node* new1 = new node();
    new1->data = x;
    node* c = root;
    node* p = root;
    int flag = 0;
    if (root == NULL)
    {
        root = new1;
        head->right = root;
        new1->left = head;
        new1->right = head;
    }
    else
    {
        while (flag != 1)
        {
            if (c->data == x)
            {
            	cout<<"Duplication not permitted!"<<endl;
                return;
            }
            if (x > c->data)
            {
                if (c->rthread == 1)
                {
                    new1->right = c->right;
                    new1->left = c;
                    c->right = new1;
                    c->rthread = 0;
                    flag = 1;
                }
                //p = c;
                c = c->right;
            }
            else if (c->data > x)
            {
                if (c->lthread == 1)
                {
                    new1->left = c->left;
                    new1->right = c;
                    c->left = new1;
                    c->lthread = 0;
                    flag = 1;
                }
                //p = c;
                c = c->left;
            }
        }
    }
}
void tbt::inorder(node* c)
{
    while (c->left != head) 
    {
        c = c->left;
    }
    while (c->right != head) 
    {
        cout << c->data << " ";
        c = inordersucc(c);
    }
    cout << c->data << " ";
}
node* tbt::inordersucc(node* c)
{

    if (c->rthread == 1)

    {

        return c->right;

    }

    else

    {

        c = c->right;

        while (c->lthread != 1)

        {

            c = c->left;

        }

        return c;



    }

}
node* tbt::preorder(node* c)
{
    while (c->left != head)
    {
        cout << c->data << " ";
        c = c->left;
    }
    cout << c->data << " ";
    while (c->right != head)
    {
        if (c->rthread == 1)
        {
            c = c->right;
        }
        else
        {
            c = c->right;
            while (c->lthread != 1)
            {
                cout << c->data << " ";
                c = c->left;
            }
            cout << c->data << " ";
        }
    }
    return c;
}
void tbt::remove(int x)
{
    node* c = root;
    node* p = root;
    int flag = 0;
    while (flag != 1)
    {
        if (c->data == x)
        {
           flag = 1;
        }
        if (x > c->data)
        {
            if (c->rthread == 1)
            {
                cout << "\nData not found";
                return;
            }
            p = c;
            c = c->right;
        }
        else if (x < c->data)
        {
            if (c->lthread == 1)
            {
                cout << "\nData not found";
                return;
            }
            p = c;
            c = c->left;
        }
    }
    //leaf node
    if (c->lthread == 1 && c->rthread == 1)
    {
        if (p->left == c)
        {
            p->left = c->left;
            p->lthread = 1;
            delete(c);
        }
        else if (p->right == c)
        {
            p->right = c->right;
            p->rthread = 1;
            delete(c);
        }
    }
    //===========================================
    //Node with one child
    else if (c->lthread == 1 || c->rthread == 1)
    {
        node* q;
        //node to be deleted is right child of its parent
        if (p->right == c) 
        {
            if (c->lthread == 1)
            {
                q = c->right;
                while (q->lthread != 1)//6
                {
                    q = q->left;
                }
                q->left = c->left;
                p->right = c->right;
                delete(c);
            }
            else if (c->rthread == 1)//7
            {
                q = c->left;
                while (q->rthread != 1)
                {
                    q = q->right;
                }
                q->right = c->right;
                p->right = c->left;
                delete(c);
            }
        }
        //node to be deleted is left child of its parent
        else if (p->left == c)
        {
            if (c->lthread == 1)//8
            {
                q = c->right;
                while (q->lthread != 1)
                {
                    q = q->left;
                }
                q->left = c->left;
                p->left = c->right;
                delete(c);
            }
            else if (c->rthread == 1)//9
            {
                q = c->left;
                while (q->rthread != 1)
                {
                    q = q->right;
                }
                q->right = c->right;
                p->left = c->left;
                delete(c);
            }
        }
    }
    else if(c->lthread != 1 && c->rthread != 1)
    {
        node* p = c;
        node* q = inordersucc(c);
        c = c->right;
        while (c->left != q && c != q)
        {
            c = c->left;
        }
        int temp = p->data;
        p->data = q->data;
        q->data = temp;
        if (c->left == q)
        {
            if (q->rthread != 1)//11
            {
                // c->left=q->right;
                node* r = q;
                q = q->right;
                while (q->lthread != 1)
                {
                    q = q->left;
                }
                q->left = r->left;
                c->left = r->right;
                delete(r);
            }
            else if (q->rthread == 1)//10
            {
                c->left = q->left;
                c->lthread = 1;
                delete(q);
            }
        }
        else if (c == q)//12
        {
            if (q->rthread == 1)
            {
                p->right = q->right;
                p->rthread = 1;
                delete(q);
            }
            else if (q->rthread != 1)
            {
                c = q->right;
                while (c->lthread != 1)
                {
                    c = c->left;
                }
                p->right = q->right;
                c->left = q->left;
                delete(q);
            }
        }
    }
}
node* tbt::get_root()
{
    return root;
}

int main()
{
    tbt t;
    t.create();
    t.inorder(t.get_root());
    int c;
    cout << "\nEnter data to remove = ";
    cin >> c;
    t.remove(c);
    t.inorder(t.get_root());
    return 0;
}

