#include <iostream>

class Node
{
	public:
	  int data;
		Node* next;
	Node()
	{
		data = 0;
		next = NULL;
	}
	Node(int md, Node* n)
	{
		data = md;
		next = n;
	}
	void push_front(Node** n, int md)
	{
		
		Node* new_node = new Node();
		new_node->data = md;
		new_node->next = *n;
		*n = new_node;
	}
	void push_back(Node** n, int md)
	{
		Node* new_node = new Node();
		new_node->data = md;
		if(*n ==NULL)
		{
			*n = new_node;
			return;
		}
		Node* last = *n;
		while(last->next!=NULL)
		{
			last = last->next;
		}
		last->next = new_node;
	}
	
	
	static void print_LL(Node* n)
	{
		while(n !=NULL)
		{
			std::cout << n->data << std::endl;
			n = n->next;
		}
	}
};

int main()
{
	Node* head = new Node(10, NULL);
	head->next = new Node(12, NULL);
	head->next->next = new Node(13, NULL);
	std::cout << "head: " << std::endl;
	Node::print_LL(head);
	
	
	Node* new_head = new Node(5, NULL);
	new_head->push_front(&new_head, 10);
	new_head->push_back(&new_head, 20);
	std::cout << "new_head: " << std::endl;
	Node::print_LL(new_head);
	
	Node* new_head2 = NULL;
	new_head2->push_back(&new_head2, 20);
	new_head2->push_back(&new_head2, 21);
	
	std::cout << "new_head2: " << std::endl;
	Node::print_LL(new_head2);
		
	return 0;
	
}
