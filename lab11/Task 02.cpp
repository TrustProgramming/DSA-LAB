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
    // BST property:
    //   - Chhoti value → left main jati hai
    //   - Bari  value → right main jati hai

    Node* insert(Node* node, int val) 
    {
        // Base case: khali jagah mil gayi, naya node banao
        if (node == nullptr)
        {
            return new Node(val);
        }

        // Value chhoti hai toh left main jao
        if (val < node->data)
        {
            node->left = insert(node->left, val);
        }

        // Value bari hai toh right main jao
        else if (val > node->data)
        {
            node->right = insert(node->right, val);
        }

        // Duplicate values ignore kar rahe hain
        return node;
    }

    // Recursive Inorder Traversal
    // Order: Left → Root → Right
    // Yeh hamesha sorted/ascending order main print karta hai

    void inorder(Node* node)
    {
        // Base case: node null hai toh wapas jao
        if (node == nullptr)
        {
            return;
        }

        // Pehle left subtree visit karo
        inorder(node->left);

        // Phir current node print karo
        cout << node->data << " ";

        // Phir right subtree visit karo
        inorder(node->right);
    }

public:
    // Constructor: khali tree banata hai
    BST()
    {
        root = nullptr;
    }

    // Public insert: user se value lekar tree main dalta hai

    void insert(int val)
    {
        root = insert(root, val);
        cout << val << " Value is inserted ! " << endl;
    }

    // Public display: inorder traversal print karta hai

    void display() 
    {
        if (root == nullptr)
        {
            cout << " Tree is Empty ! " << endl;
            return;
        }
        cout << " Inorder Traversal (Ascending) : ";
        inorder(root);
        cout << endl;
    }
};

// ===================== MAIN FUNCTION =====================
int main() {
    BST tree;

    cout << "\n----- BST Insertion & Inorder Traversal -----\n" << endl;

    // User se values lo aur insert karo
    int n, val;
    cout << "\nEnter number of Values to search : ";
    cin >> n;

    cout << "\nEnter the values : " << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << "Value " << i + 1 << ": ";
        cin >> val;
        tree.insert(val);
    }

    // Inorder traversal display karo
    cout << endl;
    tree.display();

    return 0;
}