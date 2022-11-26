#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include <bits/stdc++.h>
#include <inttypes.h>

class Node
{
	public:
		int md;
		Node* next;
	
		Node()
		{
			md = 0;
			next = NULL;
		}
		Node(int emd)
		{
			next = NULL;
			md = emd;
		}		
		void push_back(Node** n, int emd)
		{
			Node* newnode = new Node(emd);
			if (*n==NULL)
			{
				*n = newnode;
				return;
			}
			Node* last = *n;
			while(last->next !=NULL)
			{
				last = last->next;
			}
			last->next = newnode;
		}
		void printXOR(Node* n)
		{
			while(n != NULL)
			{
				std::cout << n->md << std::endl;
				n = n->next;
			}
		}
};

class XORNode
{
	public:
		int data;
		XORNode* npx;
		
};

XORNode* XOR(XORNode* a , XORNode* b)
{
    return (XORNode*)((uintptr_t)a ^ (uintptr_t)b);
}
XORNode* PREV = NULL; // store address of previous NODE form last NODE
XORNode* END  = NULL; // store address of last Node 
XORNode* NEXT = NULL; // store address of upcoming Node (isn't interesting :)
void add(XORNode** HEAD , int value)
{
  XORNode *new_node  = new XORNode();

  new_node -> data = value;

  if(*HEAD!=NULL)
	{
    END->npx = XOR(PREV , new_node);
    PREV = END;
    END = new_node;
    END->npx = XOR(PREV , NEXT);
	}
	else
	{
    new_node->npx = XOR(PREV , NEXT);
    *HEAD = new_node;
    END = new_node;
  }

  return ;
}
XORNode* get(int index ,XORNode *HEAD){
    XORNode* current  = HEAD;
    XORNode* Prev = NULL;
    XORNode* Next = NULL;
    int i=1;
    while(i<index)
		{
      i++;
      Next = XOR(current->npx , Prev);
      Prev = current;
        current = Next;
    }
    return current;
}
void print(XORNode* HEAD){
    XORNode* current  = HEAD;
    XORNode* Prev = NULL;
    XORNode* Next = NULL;
    while(current!=NULL){
        std::cout<<current->data<<' ';
        Next = XOR(current->npx , Prev);
        Prev = current;
        current = Next;
    }
    std::cout<< std::endl;
}


	
int main()
{
	Node* head2 = new Node(10);
	head2->push_back(&head2, 20);
	head2->push_back(&head2, 34);
	head2->printXOR(head2);
	
  // declare variables
  int a = 12, b = 25;
  std::cout << "a & b = " << (a & b) << std::endl;
	std::cout << "a | b = " << (a | b) << std::endl;
	std::cout << "a ^ b = " << (a ^ b) << std::endl;

    XORNode* head = NULL;		// you can make it global variable so that you don't have to pass it 
    
		add(&head , 10);
    add(&head , 20);
    add(&head , 30);
    add(&head , 40);
    add(&head , 50);
    add(&head , 60);
    print(head);
		
    std::cout << std::endl;
    // assumed that index will be valid 
    int index = 3;  
    XORNode *node = get(index,head); // we can make head a global variable that doesn't effect the solution
    assert(node->data==30);
    std::cout<<node->data<<std::endl; // 30 

	return 0;
}