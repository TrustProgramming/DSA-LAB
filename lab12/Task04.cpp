#include<iostream>
using namespace std;

class node
{
public:
    int data; // ISBN
    string title;
    node* left;
    node* right;
};

class listNode
{
public:
    int isbn;
    string title;
    listNode* next;
};

class bst
{
public:
    node* root;

    bst()
    {
        root = NULL;
    }

    void addNode(int n)
    {
        node* p;
        int val;
        string t;

        while (n > 0)
        {
            if (root == NULL)
            {
                root = new node;
                cout << "Enter ISBN: ";
                cin >> root->data;
                cout << "Enter Title: ";
                cin >> root->title;

                root->left = NULL;
                root->right = NULL;
                n--;
            }
            else
            {
                p = root;

                cout << "Enter ISBN: ";
                cin >> val;
                cout << "Enter Title: ";
                cin >> t;

                while (true)
                {
                    if (val < p->data)
                    {
                        if (p->left == NULL)
                        {
                            p->left = new node;
                            p = p->left;
                            p->data = val;
                            p->title = t;
                            p->left = NULL;
                            p->right = NULL;
                            break;
                        }
                        else
                        {
                            p = p->left;
                        }
                    }
                    else
                    {
                        if (p->right == NULL)
                        {
                            p->right = new node;
                            p = p->right;
                            p->data = val;
                            p->title = t;
                            p->left = NULL;
                            p->right = NULL;
                            break;
                        }
                        else
                        {
                            p = p->right;
                        }
                    }
                }
                n--;
            }
        }
    }

    void inorder(node* root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->data << " - " << root->title << endl;
            inorder(root->right);
        }
    }

    void convertToList(node* root, listNode*& head, listNode*& tail)
    {
        if (root == NULL)
        {
            return;
        }

        convertToList(root->left, head, tail);

        listNode* newNode = new listNode;
        newNode->isbn = root->data;
        newNode->title = root->title;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        convertToList(root->right, head, tail);
    }

    void printList(listNode* head)
    {
        listNode* temp = head;

        while (temp != NULL)
        {
            cout << temp->isbn << " - " << temp->title << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    bst b;

    int n;
    cout << "Enter number of books: ";
    cin >> n;

    b.addNode(n);

    cout << "\nBST Inorder (Sorted):\n";
    b.inorder(b.root);

    listNode* head = NULL;
    listNode* tail = NULL;

    b.convertToList(b.root, head, tail);

    cout << "\nSorted Linked List (Catalog):\n";
    b.printList(head);
}