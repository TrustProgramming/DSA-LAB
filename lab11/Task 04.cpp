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

// BST class - pura Binary Search Tree is k andar hai

class BST
{
private:
    Node* root;

    // Recursive Insert helper
    // Choti value left, bari value right main jati hai

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
    // Minimum hamesha sabse LEFT node main hota hai BST mein
    // Is liye hum baar baar left mein jaaty hain
 
    int findMin(Node* node)
    {
        // Base case: agar left child nahi hai
        // toh yahi node minimum hai
        if (node->left == nullptr)
        {
            return node->data;
        }

        // Recursive call: aur left main jao
        return findMin(node->left);
    }

    // Recursive MAXIMUM finder
    // Maximum hamesha sabse RIGHT node main hota hai BST mein
    // Is liye hum baar baar right main jaate hain

    int findMax(Node* node)
    {
        // Base case: agar right child nhi hai
        // toh yahi node maximum hai
        if (node->right == nullptr)
        {
            return node->data;
        }
        // Recursive call: aur right main jao
        return findMax(node->right);
    }

    // Recursive Inorder Traversal (Left -> Root -> Right)
    // Sorted order main values print karta hai

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
        // Agar tree khali hai toh error
        if (root == nullptr)
        {
            cout << "Tree khali hai!" << endl;
            return -1;
        }
        return findMin(root);
    }

    // Public findMax: maximum value return karta hai

    int getMax() 
    {
        // Agar tree khali hai to error
        if (root == nullptr) 
        {
            cout << "Tree khali hai!" << endl;
            return -1;
        }
        return findMax(root);
    }

    // Public inorder display

    void display()
    {
        if (root == nullptr)
        {
            cout << "Tree khali hai!" << endl;
            return;
        }
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }
};

// ===================== MAIN FUNCTION =====================
int main() 
{
    BST tree;

    cout << "\n----- BST Min & Max Finder (Recursive) -----\n" << endl;

    // Values insert karna
    int values[] = { 50, 30, 70, 20, 40, 60, 80, 10, 90 };
    // Yeh tarika size nikalny ka hum na PF main parha tha Sir Shaukat Ali Chauhdry sa
    int n = sizeof(values) / sizeof(values[0]);

    cout << "\nInsert ho rahi hain values: ";
    for (int i = 0; i < n; i++)
    {
        cout << values[i] << " ";
        tree.insert(values[i]);
    }
    cout << endl;

    // Tree display karo
    cout << endl;
    tree.display();

    // Minimum aur Maximum print karo
    cout << "\nMinimum Value (Leftmost Node) : " << tree.getMin() << endl;
    cout << "Maximum Value (Rightmost Node): " << tree.getMax() << endl;

    return 0;
}