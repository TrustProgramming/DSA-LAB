#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* right;
	Node* left;
};

Node* newNode(int val)
{
	Node* node = new Node();
	node->data = val;
	node->right = nullptr;
	node->left = nullptr;

	return node;
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

Node* minValueNode(Node* root)
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
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			return nullptr;
		}
		else if (root->left == nullptr)
		{
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == nullptr)
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
		else
		{
			Node* successor = minValueNode(root->right);
			root->data = successor->data;
			root->right = deleteNode(root->right, successor->data);
		}
	}
	return root;
}

class BST
{
	Node* root;

public:
	BST()
	{
		root = nullptr;
	}
	void createNode(int val)
	{
		root = insert(root, val);
	}
	void deletion(int val)
	{
		root = deleteNode(root, val);
	}
	void display()
	{
		inorder(root);
		cout << endl;
	}
};

int main()
{
	int val;
	BST b;

	b.createNode(100);
	b.createNode(70);
	b.createNode(150);
	b.createNode(30);
	b.createNode(170);
	b.createNode(90);
	b.createNode(10);

	b.display();

	cout << " Enter the Value to delete : ";
	cin >> val;

	b.deletion(val);
	b.display();

	return 0;
}