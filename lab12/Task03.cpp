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
	bool isIdentical(node* root1, node* root2)
	{
		if (root1 == NULL && root2 == NULL)
		{
			return true;
		}

		if (root1 == NULL || root2 == NULL)
		{
			return false;
		}

		if (root1->data == root2->data)
		{
			return isIdentical(root1->left, root2->left) &&
				isIdentical(root1->right, root2->right);
		}

		return false;
	}
};

int main()
{
	bst b1, b2;

	int n;
	cout << "Enter number of nodes for Tree 1: ";
	cin >> n;
	b1.addNode(n);

	cout << "\nEnter number of nodes for Tree 2: ";
	cin >> n;
	b2.addNode(n);

	cout << "\nInorder Traversal of Tree 1:\n";
	b1.inorder(b1.root);

	cout << "\nInorder Traversal of Tree 2:\n";
	b2.inorder(b2.root);

	if (b1.isIdentical(b1.root, b2.root))
	{
		cout << "\nBSTs are IDENTICAL";
	}
	else
	{
		cout << "\nBSTs are NOT IDENTICAL";
	}
}
