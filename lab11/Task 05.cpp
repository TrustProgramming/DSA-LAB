#include <iostream>
using namespace std;

// BST Node class - aik node ko represent karta hai
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

// Binary Search Tree class
class BST
{
private:
    Node* root;

    // Private helper: naya node recursive insert krta ha
    Node* insert(Node* node, int val) 
    {
        // Agar tree khali hai ya leaf tak pohnch jaye
        if (node == nullptr)
        {
            return new Node(val);
        }

        // Choti value left mein jati hai
        if (val < node->data)
        {
            node->left = insert(node->left, val);
        }
        // Bari value right mein jati hai
        else if (val > node->data)
        {
            node->right = insert(node->right, val);
        }

        return node;
    }

    // Private helper: subtree mein sab se chota node dhundna
    // (right subtree ka minimum = inorder successor)
    Node* findMin(Node* node) 
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    // Private helper: recursive deletion function
    Node* deleteNode(Node* node, int val)
    {
        // Base case: agar node nahi mila
        if (node == nullptr) 
        {
            cout << "Value " << val << " not found in tree !" << endl;
            return nullptr;
        }

        // Value choti hai: left subtree mein jao
        if (val < node->data) 
        {
            node->left = deleteNode(node->left, val);
        }
        // Value bari hai: right subtree mein jao
        else if (val > node->data) 
        {
            node->right = deleteNode(node->right, val);
        }
        // Value mil gayi: ab delete karo
        else 
        {
            // Case 1: Node ka koi child nahi (leaf node)
            if (node->left == nullptr && node->right == nullptr) 
            {
                delete node;
                return nullptr;
            }

            // Case 2: Sirf ek child hai
            // Sirf right child hai
            if (node->left == nullptr)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            // Sirf left child hai
            if (node->right == nullptr)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Dono children hain
            // Inorder successor dhundo (right subtree ka minimum)
            Node* successor = findMin(node->right);

            // Successor ka data current node mein copy karo
            node->data = successor->data;

            // Phir successor ko right subtree se delete karo
            node->right = deleteNode(node->right, successor->data);
        }

        return node;
    }

    // Private helper: inorder traversal (Left -> Root -> Right)
    // Yeh sorted order mein values print karta hai
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
    // Constructor - khali tree banata hai
    BST() 
    {
        root = nullptr;
    }

    // Public: value insert karta hai
    void insert(int val)
    {
        root = insert(root, val);
    }

    // Public: value delete karta hai
    void deleteValue(int val) 
    {
        root = deleteNode(root, val);
    }

    // Public: inorder traversal print karta hai
    void displayInorder()
    {
        if (root == nullptr)
        {
            cout << " Tree is Empty !" << endl;
            return;
        }
        cout << " Inorder Traversal : ";
        inorder(root);
        cout << endl;
    }
};

// ===================== MAIN FUNCTION =====================
int main()
{
    BST tree;

    // Pehle se kuch values insert kar rahe hain tree mein
    int initialValues[] = { 50, 30, 70, 20, 40 };
    // Yeh tarika size nikalny ka hum na PF main parha tha Sir Shaukat Ali Chauhdry sa
    int n = sizeof(initialValues) / sizeof(initialValues[0]);

    cout << " Binary Search Tree - Deletion " << endl;

    // Values insert karna
    cout << "\nValues are inserting : ";
    for (int i = 0; i < n; i++)
    {
        cout << initialValues[i] << " ";
        tree.insert(initialValues[i]);
    }
    cout << endl;

    // Deletion se pehle traversal dikhao
    cout << "\nBefore deletion :" << endl;
    tree.displayInorder();

    // User se value lo jo delete karni hai
    int val;
    cout << "\nEnter the value to delete : ";
    cin >> val;

    // Delete karo
    cout << "\nDeleting " << val << "..." << endl;
    tree.deleteValue(val);

    // Deletion ke baad traversal dikhao
    cout << "\nAfter deletion :" << endl;
    tree.displayInorder();

    return 0;
}