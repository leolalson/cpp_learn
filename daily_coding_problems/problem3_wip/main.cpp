#include<iostream>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;

class Node
{
	public:
	  char data;
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
		Node* deserialize_string(Node* root, std::vector<char> char_vec)
		{
			int mid = char_vec.size()/2;
			char val = char_vec[mid];
			if (!root)
			{
				return new Node(val);
			}
			
			std::cout << "mid: " << mid << std::endl;
			std::cout << "data: " << data << std::endl;
			std::cout << "Full String: ";
			for(int i=0;i<char_vec.size();++i)
			{
				std::cout << char_vec[i] << ", ";
			}
			std::cout << std::endl;
			
			std::vector<char> left_array(char_vec.begin(), char_vec.begin() + mid);
			std::vector<char> right_array(char_vec.begin() + mid + 1, char_vec.end());
			
			std::cout << "left String: ";
			for(int i=0;i<left_array.size();++i)
			{
				std::cout << left_array[i] << ", ";
			}
			std::cout << std::endl;
			//std::cout << "right String: ";
			//for(int i=0;i<right_array.size();++i)
			//{
			//	std::cout << right_array[i] << ", ";
			//}
			//std::cout << std::endl;
			
			if(mid > 0)
			{	
				root->left = deserialize_string(root, left_array);
			}
			
			//if(mid + 1 < char_vec.size())
			//{
			//	root->right = root->deserialize_string(right_array);
			//}
			
			return new Node(val);
			
		}
		void Inorder(Node* root)
		{
			if(!root)
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
	std::string my_string = "lalson1";
	int n  = my_string.length();
	std::vector<char> char_vec(my_string.begin(), my_string.end());
	
	Node* a = new Node(' ');
	Node b, *root = NULL;
	root = b.deserialize_string(root, char_vec);
	b.Inorder(root);
	return 0;
}