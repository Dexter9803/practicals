#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    char k[20];
    char m[20];
    class node* left;
    class node* right;
};

class dict
{
    public:
    node* root;
    void create();
    void insert(node* root, node* temp);
    void display(node* root);
    int search(node* root, char[]);
    int update(node* root, char[]);
    node* del(node* root, char[]);
    node* min(node* root);
};

void dict::create()
{
    class node* temp;
    char ch;
    do
    {
        temp = new node;
        cout<<"\nEnter Keyword: ";
        cin>>temp->k;
        cout<<"\nEnter Meaning: ";
        cin>>temp->m;
        
        temp->left = NULL;
        temp->right = NULL;

        if(root == NULL)
        {
            root = temp;
        }
        else
        {
            insert(root, temp);
        }

        cout<<"Do you want add more (y/n): ";
        cin>>ch;
    }while(ch == 'y');
}

void dict::insert(node* root, node* temp)
{
    if(strcmp(temp->k, root->k) < 0)
    {
        if(root->left == NULL)
        {
            root->left = temp;
        }
        else
        {
            insert(root->left, temp);
        }
    }
    else
    {
        if(root->right == NULL)
        {
            root->right = temp;
        }
        else
        {
            insert(root->right, temp);
        }
    }
}

void dict::display(node* root)
{
    if(root != NULL)
    {
        display(root->left);
        cout<<"\nKeyword: "<<root->k;
        cout<<"Meaning: "<<root->m;
        display(root->right);
    }
}

int dict:: search(node* root, char k[20])
{
    int c = 0;

    while(root != NULL)
    {
        c++;
        if(strcmp(k, root->k) == 0)
        {
            cout<<"\nNo of comparisions: "<<c;
            return 1;
        }
        if(strcmp(k, root->k) < 0)
        {
            root = root->left;
        }
        if(strcmp(k, root->k) > 0)
        {
            root = root->right;
        }
    }
    return -1;
}

int dict::update(node* root, char k[20])
{
    while(root != NULL)
    {
        if(strcmp(k, root->k) == 0)
        {
            cout<<"\nEnter new meaning of keyword: ";
            cin>>root->m;
            return 1;
        }
        if(strcmp(k, root->k) < 0)
        {
            root = root->left;
        }
        if(strcmp(k, root->k) > 0)
        {
            root = root->right;
        }
    }
    return -1;
}

node* dict::del(node* root, char k [20])
{
    node* temp;

    if(root == NULL)
    {
        cout<<"\nElement not found!!";
        return root;
    }
    if(strcmp(k, root->k) < 0)
    {
        root->left = del(root->left, k);
        return root;
    }
    if(strcmp(k, root->k) > 0)
    {
        root->right = del(root->right, k);
        return root;
    }
    if(root->left == NULL && root->right == NULL)
    {
        temp = root;
        delete temp;
        return NULL;
    }
    if(root->left == NULL)
    {
        temp = root;
        root = root->left;
        delete temp;
        return root;
    }
    if(root->right == NULL)
    {
        temp = root;
        root = root->right;
        delete temp;
        return root;
    }

    temp = min(root->right);
    strcpy(root->k, temp->k);
    root->right = del(root->right, root->k);    
    return root;    
}

node* dict::min(node* q)
{
    while(q->left != NULL)
    {
        q = q->left;
    }
    return q;
}


int main()
{
    int ch;
    dict d;
    d.root = NULL;
    do
    {
        cout << "\nMenu\n1.Create\n2.Disp\n3.Search\n4.Update\n5.Delete\nEnter your choice : ";
        cin >>ch;
        switch (ch)
        {
        case 1:
            d.create();
            break;
        case 2:
            if (d.root == NULL)
                cout << "\nNo any Keyword";
            else
                d.display(d.root);
            break;
        case 3:
            if (d.root == NULL)
                cout << "\nDictionary is Empty. First add keywords then try again ";
            else
            {
                cout << "\nEnter Keyword which you want to search:";
                char k[20];
                cin >> k;
                if (d.search(d.root, k) == 1)
                    cout << "\nKeyword Found";
                else
                    cout << "\nKeyword Not Found";
            }
            break;
        case 4:
            if (d.root == NULL)
                cout << "\nDictionary is Empty. First add keywords then try again ";
            else
            {
                cout << "\nEnter Keyword which meaning want to update:";
                char k[20];
                cin >> k;
                if (d.update(d.root, k) == 1)
                    cout << "\nMeaning Updated";
                else
                    cout << "\nMeaning Not Found";
            }
            break;
        case 5:
            if (d.root == NULL)
                cout << "\nDictionary is Empty. First add keywords then try again ";
            else
            {
                cout << "\nEnter Keyword which u want to delete:";
                char k[20];
                cin >> k;
                if (d.root == NULL)
                    cout << "\nNo any Keyword";
                else
                    d.root = d.del(d.root, k);
            }
        }
    } while (ch <= 5);


    
    return 0;  
    
}