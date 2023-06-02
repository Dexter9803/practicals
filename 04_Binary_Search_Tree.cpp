/*
Beginning with an empty binary search tree, construct binary search tree by inserting the values in the order given. 
After constructing a binary tree- 
i. Insert new node, ii. Find number of nodes in longest path from root, 
iii. Minimum data value found in the tree, iv. Change a tree so that the roles of the left and right pointers are swapped at every node. 
v. Search a value
*/


#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertInBST(Node *root, int data)
{
    // base case
    if (root == NULL)
    {
        Node *root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        // right part
        root->right = insertInBST(root->right, data);
    }
    else
    {
        // left part
        root->left = insertInBST(root->left, data);
    }

    return root;
}

void takeInput(Node *&root)
{
    int n;
    cout << "Enter no of elements to insert: ";
    cin >> n;

    int value;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value of Node: ";
        cin >> value;
        root = insertInBST(root, value);
    }
}

bool searchInBST(Node *root, int key)
{
    if (root == NULL)
    {
        // not found
        return false;
    }
    if (root->data == key)
    {
        // found
        return true;
    }
    if (key > root->data)
    {
        // search in right part
        searchInBST(root->right, key);
    }
    else
    {
        // search in left part
        searchInBST(root->left, key);
    }
}

void minValue(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    cout << "Minimum Value in BST is: " << temp->data;
}

void mirror(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        Node *ptr;
        mirror(root->left);
        mirror(root->right);
        ptr = root->left;
        root->left = root->right;
        root->right = ptr;
    }
}

void inorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void display(Node *root)
{
    cout << "\n-------- BST in Inorder format---------\n";
    inorder(root);
    cout << endl;
}

int main()
{
    Node *root = NULL;

    int ch, key;
    cout << "Enter data to create BST: ";

    while (1)
    {
        cout << "\n1.Insert new node \n2.Minimum data value node \n3.mirror image \n4.search value \nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            takeInput(root);
            display(root);
            break;
        case 2:
            minValue(root);
            break;
        case 3:
            mirror(root);
            display(root);
            break;
        case 4:
            cout << "\nEnter key to be search: ";
            cin >> key;

            if (searchInBST(root, key))
            {
                cout << "\nElement found";
            }
            else
            {
                cout << "Element not found";
            }
            break;
        }
    }

    return 0;
}