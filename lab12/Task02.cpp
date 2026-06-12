#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;
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

		while (n > 0)
		{
			if (root == NULL)
			{
				root = new node;
				cout << "Enter value of root: ";
				cin >> root->data;
				root->left = NULL;
				root->right = NULL;
				cout << "Root (" << root->data << ") added!" << endl;
				n--;
			}
			else
			{
				p = root;
				cout << "Enter next node: ";
				cin >> val;

				while (true)
				{
					if (val < p->data)
					{
						if (p->left == NULL)
						{
							p->left = new node;
							p = p->left;
							p->data = val;
							p->left = NULL;
							p->right = NULL;
							cout << "Value entered at left!" << endl;
							break;
						}
						else
						{
							p = p->left;
						}
					}

					else if (val >= p->data)
					{
						if (p->right == NULL)
						{
							p->right = new node;
							p = p->right;
							p->data = val;
							p->left = NULL;
							p->right = NULL;
							cout << "Value entered at right!" << endl;
							break;
						}
						else
						{
							p = p->right;
						}
					}

					else
					{
						cout << "Error!" << endl;
					}
				}
				n--;
			}
		}
	}

	void inorder(node * root)
	{
		if (root != NULL)
		{
			inorder(root->left);
			cout << root->data << " ";
			inorder(root->right);
		}
	}
	void preorder(node * root)
	{
		if (root != NULL)
		{
			cout << root->data << " ";
			preorder(root->left);
			preorder(root->right);
		}
	}
	void postorder(node * root)
	{
		if (root != NULL)
		{
			postorder(root->left);
			postorder(root->right);
			cout << root->data << " ";
		}
	}
	bool search(node* root, int key)
	{
		if (root == NULL)
		{
			return false;
		}
		if (root->data == key)
		{
			return true;
		}
		else if (key < root->data)
		{
			return search(root->left, key);
		}
		else
		{
			return search(root->right, key);
		}
	}
	node* findMin(node* root)
	{
		while (root->left != NULL)
		{
			root = root->left;
		}
		return root;
	}
	node* deleteNode(node* root, int key)
	{
		if (root == NULL)
		{
			return NULL;
		}

		if (key < root->data)
		{
			root->left = deleteNode(root->left, key);
		}
		else if (key > root->data)
		{
			root->right = deleteNode(root->right, key);
		}
		else
		{
			// Case 1: Leaf node
			if (root->left == NULL && root->right == NULL)
			{
				delete root;
				return NULL;
			}

			// Case 2: One child
			else if (root->left == NULL)
			{
				node* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == NULL)
			{
				node* temp = root->left;
				delete root;
				return temp;
			}

			// Case 3: Two children
			else
			{
				node* temp = findMin(root->right); // inorder successor
				root->data = temp->data;
				root->right = deleteNode(root->right, temp->data);
			}
		}
		return root;
	}
};

int main()
{
	bst b;

	int num;
	cout << "Enter number of nodes: ";
	cin >> num;

	b.addNode(num);

	cout << "\nInorder Traversal:\n";
	b.inorder(b.root);

	cout << "\nPreorder Traversal:\n";
	b.preorder(b.root);

	cout << "\nPostorder Traversal:\n";
	b.postorder(b.root);

	int valueToFind;
	
	cout << "\n\nEnter value to search for in BST: ";
	cin >> valueToFind;

	if (b.search(b.root, valueToFind))
	{
		cout << "Key found successfully!" << endl;
	}
	else
	{
		cout << "Key not found!" << endl;
	}

	int valueToDelete;
	cout << "Enter value to delete: ";
	cin >> valueToDelete;

	b.root = b.deleteNode(b.root, valueToDelete);

	cout << "\nInorder after deletion:\n";
	b.inorder(b.root);
	cout << "\nPreorder after deletion:\n";
	b.preorder(b.root);
	cout << "\nPostorder after deletion:\n";
	b.postorder(b.root);

	return 0;
}