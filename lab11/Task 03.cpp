#include <iostream>
using namespace std;

// Node class - BST ka aik node represent karta hai

class Node 
{
public:
    int data;
    Node* left;
    Node* right;

    // Constructor - naya node banata hai
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// BST class - poora Binary Search Tree is k andar hai

class BST
{
private:
    Node* root;

    // Recursive Insert helper
    // Chhoti value left, bari value right main jati hai

    Node* insert(Node* node, int val) 
    {
        // Base case: khali jagah mil gayi
        if (node == nullptr)
        {
            return new Node(val);
        }
        if (val < node->data)
        {
            node->left = insert(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = insert(node->right, val);
        }

        return node;
    }

    // Recursive MINIMUM finder
    // Minimum hamesha sabse LEFT node main hota hai

    int findMin(Node* node)
    {
        // Base case: left child nahi hai to yahi minimum hai
        if (node->left == nullptr)
        {
            return node->data;
        }

        // Aur left main jao
        return findMin(node->left);
    }

    // Recursive MAXIMUM finder
    // Maximum hamesha sabse RIGHT node main hota hai

    int findMax(Node* node) 
    {
        // Base case: right child nahi hai toh yahi maximum hai
        if (node->right == nullptr)
        {
            return node->data;
        }

        // Aur right main jao
        return findMax(node->right);
    }

    // Recursive SEARCH function
    // BST property use karke value dhundta hai:
    //   - target < current  → left main jao
    //   - target > current  → right main jao
    //   - target == current → mil gaya!

    bool search(Node* node, int target)
    {
        // Base case 1: node null hai - value nahi mili
        if (node == nullptr)
        {
            return false;
        }

        // Base case 2: value mil gayi!
        if (node->data == target)
        {
            return true;
        }

        // Agar target cahota hai toh left main dhundo
        if (target < node->data)
        {
            return search(node->left, target);
        }

        // Agar target bada hai toh right main dhundo
        return search(node->right, target);
    }

    // Recursive Inorder Traversal (Left -> Root -> Right)
    // Sorted order mein values print karta hai

    void inorder(Node* node) 
    {
        if (node == nullptr)
        {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    // Constructor: khali tree banata hai
    BST() 
    {
        root = nullptr;
    }

    // Public insert

    void insert(int val)
    {
        root = insert(root, val);
    }

    // Public findMin: minimum value return karta hai
 
    int getMin()
    {
        if (root == nullptr) 
        {
            cout << " Tree is Empty ! " << endl;
            return -1;
        }
        return findMin(root);
    }

    // Public findMax: maximum value return karta hai

    int getMax()
    {
        if (root == nullptr)
        {
            cout << " Tree is Empty ! " << endl;
            return -1;
        }
        return findMax(root);
    }

    // Public search: value dhundta hai aur result print karta hai

    void searchValue(int target) 
    {
        // Pehle check karo tree khali to nahi
        if (root == nullptr)
        {
            cout << " Tree is Empty ! " << endl;
            return;
        }

        cout << "\nSearching for " << target << " in BST..." << endl;

        // Recursive search call
        bool found = search(root, target);

        // Result print karo
        if (found)
        {
            cout << ">> Value " << target << " found in the BST! <<" << endl;
        }
        else
        {
            cout << ">> Value " << target << " not found in the BST! <<" << endl;
        }
    }

    // Public inorder display

    void display() 
    {
        if (root == nullptr)
        {
            cout << " Tree is Empty ! " << endl;
            return;
        }
        cout << " Inorder Traversal : ";
        inorder(root);
        cout << endl;
    }
};

// ===================== MAIN FUNCTION =====================
int main() {
    BST tree;

    cout << "\n----- BST Min, Max& Search(Recursive) -----\n" << endl;

    // Values insert karna
    int values[] = { 50, 30, 70, 20, 40, 60, 80, 10, 90 };
    int n = sizeof(values) / sizeof(values[0]);

    cout << "\nInserting the values : ";
    for (int i = 0; i < n; i++) 
    {
        cout << values[i] << " ";
        tree.insert(values[i]);
    }
    cout << "\n" << endl;

    // Tree display karo
    tree.display();

    // Min aur Max print karo
    cout << "\nMinimum Value (Leftmost Node) : " << tree.getMin() << endl;
    cout << "Maximum Value (Rightmost Node): " << tree.getMax() << endl;

    // User se search value lo

    int searchVal;
    cout << " Enter the value to search : ";
    cin >> searchVal;

    // Search karo aur result dikhao
    tree.searchValue(searchVal);

    // Multiple searches ka option
    char choice;
    cout << " Search for another value (y/n) : ";
    cin >> choice;

    while (choice == 'y' || choice == 'Y')
    {
        cout << " Enter the value : ";
        cin >> searchVal;
        tree.searchValue(searchVal);

        cout << "\n Search for another value (y/n) : ";
        cin >> choice;
    }

    cout << "        Exiting Program !              " << endl;

    return 0;
}