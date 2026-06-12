#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* right;
	Node* left;
	int height = 1;
};

Node* newNode(int val)
{
	Node* node = new Node();
	node->data = val;
	node->right = nullptr;
	node->left = nullptr;

	return node;
}

int height(Node* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	return root->height;
}

int maxHeight(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

int getBalance(Node* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	return height(root->left) - height(root->right);
}

Node* rightRotate(Node* root)
{
	Node* y = root->left;
	Node* temp = y->right;

	y->right = root;
	root->left = temp;

	root->height = 1 + maxHeight(height(root->left), height(root->right));
	y->height = 1 + maxHeight(height(y->left), height(y->right));

	return y;
}

Node* leftRotate(Node* root)
{
	Node* y = root->right;
	Node* temp = y->left;

	y->left = root;
	root->right = temp;

	root->height = 1 + maxHeight(height(root->left), height(root->right));
	y->height = 1 + maxHeight(height(y->left), height(y->right));

	return y;
}

Node* insert(Node* root, int val)
{
	if (root == nullptr)
	{
		return newNode(val);
	}

	if (val < root->data)
	{
		root->left = insert(root->left, val);
	}
	else if (val > root->data)
	{
		root->right = insert(root->right, val);
	}
	else
	{
		return root;
	}

	root->height = 1 + maxHeight(height(root->left), height(root->right));

	int balance = getBalance(root);

	if (balance > 1 && val < root->left->data)
	{
		return rightRotate(root);;
	}
	if (balance < -1 && val > root->right->data)
	{
		return leftRotate(root);
	}
	if (balance > 1 && val > root->left->data)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if (balance < -1 && val < root->right->data)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

Node* minValue(Node* root)
{
	Node* curr = root;

	while (curr->left != nullptr)
	{
		curr = curr->left;
	}

	return curr;
}

Node* deleteNode(Node* root, int val)
{
	if (root == nullptr)
	{
		return root;
	}

	if (val < root->data)
	{
		root->left = deleteNode(root->left, val);
	}
	else if (val > root->data)
	{
		root->right = deleteNode(root->right, val);
	}
	else
	{
		if (root->left == nullptr || root->right == nullptr)
		{
			Node* temp = nullptr;

			if (root->left == nullptr)
			{
				temp = root->right;
			}
			else
			{
				temp = root->left;
			}

			if (temp == nullptr)
			{
				temp = root;
				root = nullptr;
			}
			else
			{
				*root = *temp;
			}

			delete temp;
		}
		else
		{
			Node* successor = minValue(root->right);
			root->data = successor->data;
			root->right = deleteNode(root->right, successor->data);
		}
	}

	if (root == nullptr)
	{
		return root;
	}

	root->height = 1 + maxHeight(height(root->left), height(root->right));

	int balance = getBalance(root);

	if (balance > 1 && getBalance(root->left) >= 0)
	{
		return rightRotate(root);
	}
	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if (balance < -1 && getBalance(root->right) <= 0)
	{
		return leftRotate(root);
	}
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void inorder(Node* root)
{
	if (root == nullptr)
	{
		return;
	}

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main()
{
	Node* root = nullptr;

	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);

	cout << "Inorder traversal after insertion: ";
	inorder(root);
	cout << endl;

	root = deleteNode(root, 40);

	cout << "Inorder traversal after deleting 40: ";
	inorder(root);
	cout << endl;

	return 0;
}