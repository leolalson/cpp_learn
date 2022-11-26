#include<iostream>


class Node
{
	public:
	  int data;
		Node* left;
		Node* right;
		
		Node()
		{
			data = 0;
			left = NULL;
			right = NULL;
		}
		
		Node(int val)
		{
			data = val;
			left = NULL;
			right = NULL;
		}
};

class BST
{
	public:
		int data;
		BST* left;
		BST* right;
		
		BST()
		{
			data = 0;
			left = NULL;
			right = NULL;
		}
		BST(int val)
		{
			data = val;
			left = NULL;
			right = NULL;
		}
		BST* Insert(BST* root, int val)
		{
			if (!root)
			{
				return new BST(val);
			}
			else if(val > root->data)
			{
				root->right = Insert(root->right, val);
			}
			else if(val < root->data)
			{
				root->left = Insert(root->left, val);
			}
			return root;
		}
		void Inorder(BST* root)
		{
			if (!root) 
			{
				return;
			}
			Inorder(root->left);
			std::cout << root->data << std::endl;

			Inorder(root->right);
		}
};

int main()
{
  BST b, *root = NULL;
	root = b.Insert(root, 50);
  b.Insert(root, 30);
  b.Insert(root, 20);
  b.Insert(root, 40);
  b.Insert(root, 70);
  b.Insert(root, 60);
  b.Insert(root, 80);
 
  b.Inorder(root);
	
	BST c(1);
	BST* d = new BST(1);
	d.Insert(d->data, 10);
	//b.insert(c, 20);

	//BST* root = new BST
  return 0;
}
