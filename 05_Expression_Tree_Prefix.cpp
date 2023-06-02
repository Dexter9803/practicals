// Q. Construct an expression tree from the given prefix expression eg. +--abc/def
// and traverse it using post order traversal (non recursive) and then delete the entire tree.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    node *left;
    node *right;
};

class tree
{
    char prefix[20];

    public:
    node* top;
    void expression(char []);
    void non_rec_postorder(node*);
    void del(node*);
};

class stack1
{
    node* data[30];
    int top;

    public:

    stack1()
    {
        top = -1;
    }
    int empty()
    {
        if(top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void push(node *p)
    {
        data[++top] = p;
    }

    node* pop()
    {
        return (data[top--]);
    }
};

void tree::expression(char prefix[])
{
    stack1 s;
    node* t1,*t2;
    int len;
    len = strlen(prefix);

    for(int i = len - 1; i >= 0; i--)
    {
        top = new node;
        top->left = NULL;
        top->right = NULL;

        if(isalpha(prefix[i]))
        {
            top->data = prefix[i];
            s.push(top);
        }
        else if(prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/' )
        {
            t2 = s.pop();
            t1 = s.pop();

            top->data = prefix[i];
            top->left = t2;
            top->right = t1;
            s.push(top);
        }

    }
    top = s.pop();

}

void tree::non_rec_postorder(node* top)
{
    stack1 s1,s2;
    node* T = top;
    s1.push(T);

    while(!s1.empty())
    {
        T = s1.pop();
        s2.push(T);

        if(T->left != NULL)
        {
            s1.push(T->left);
        }
        if(T->right != NULL)
        {
            s1.push(T->right);
        }
    }

    while(!s2.empty())
    {
        top = s2.pop();
        cout<<top->data;
    }
}

void tree::del(node* node)
{
    if(node == NULL)
    {
        return;
    }

    del(node->left);
    del(node->right);

    cout<<"\nDeleting node: "<<node->data;
    free(node);
}

int main()
{
     char expr[20];
    tree t;
    
    cout<<"Enter prefix expression: ";
    cin>>expr;
    cout<<expr;

    t.expression(expr);

    cout<<"\nPostorder Traversal of prefix expression is: ";
    t.non_rec_postorder(t.top);
    t.del(t.top);
    return 0;  
    

    
}