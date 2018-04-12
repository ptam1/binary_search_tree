#include <string>
#include <iostream>
#include "bst.h"
#include "node.h"
#include "bintree.h"
using namespace std;


/*Postcondition: Produces a linked list with the smallest entries at the front
of the list, and largest entries at the back.
*/
/*
template <class Item>
void sorted_linkedList(binary_tree_node<Item> *root);
*/
template<class Process, class Item>
void sorted_linkedList(Process f, binary_tree_node<Item> *root);

/*Postcondition: Produces a balanced binary search tree from a sorted linked 
list as the input. 
*/
template <class Item>
binary_tree_node<Item>* make_BST(node* head, Item a, Item b);



template <class T>
void printItem(T item)
{
    cout<<item<<" ";
}

template <class T>
void addItem(binary_tree_node<T>* root)
{
	node* head = new node;
    list_insert(head, root->data());
		  //Prints Linked List
	  for(node* i = head->link(); i != NULL; i = i->link())
	  {
		  cout <<  i->data() << " ";
	  }  	
}
int main() 
{
    int data[] = {15, 10, 20, 19, 8, 11, 23};
    int size = 7;  
	//int data[] = {31, 23, 19, 11, 5, 2, 1};
    binary_search_tree<int> bst1;

    for(int i = 0; i < size; i++) 
		{
        bst1.insert(data[i]);
        }

		cout << "The BST is: " << endl;
		print(bst1.get_root(), 0);
		cout << bst1 << endl;
		binary_tree_node<int>* root = bst1.get_root();
		cout << "Making a BST into a Linked List." << endl;
		
		cout << "The Linked List is: " << " ";	
		node* n = new node; 

		sorted_linkedList(addItem<int>, root);

		cout << endl;
		
		node* tail = new node(7);
		node* six = new node(6, tail);
		node* five = new node(5, six);
		node* four = new node(4, five);
		node* three = new node(3, four);
		node* two = new node(2, three);
		node* one = new node(1, two);
		
		
		cout << "Testing Linked List to BST. " << endl;
		cout << "The Linked List is: ";
		  for(node* i = one; i != NULL; i = i->link())
	  {
		  cout<<  i->data() << " ";
	  }  
	  cout << endl;	  
	  int list_size = list_length(one);
	  cout << "The BST is: "; 
	  cout << endl;
	  binary_tree_node<int>* rootTwo =  make_BST(one,0,list_size-1);
	  print(rootTwo, 0);
	  cout <<  rootTwo << endl;
	 
}

/*Postcondition: Produces a linked list with the smallest entries at the front
of the list, and largest entries at the back.
*/
template<class Process, class Item>
void sorted_linkedList(Process f, binary_tree_node<Item> *root)
{
	   //Create new first node for a linked list
       node* head = new node;	
	  	     
	   //Inserts numbers from the BST into the Linked List 
      if(root != NULL)
	   {
		   sorted_linkedList(f, root->left());
		   f(root);
		   sorted_linkedList(f, root->right());	
	   }	    
}


/*Postcondition: Produces a balanced binary search tree from a sorted linked 
list, and list size as the input. 
*/
template <class Item>
binary_tree_node<Item>* make_BST(node* head, Item a, Item b)
{
	  //Base Case
	  if(a  > b)
	  {
		 return NULL;
	  }
	  else
	  {
	  int i = 0; 
	  node* current = head; 
	  int middle= a+(b-a)/2;
	  while((i < middle_num) && (current->link() != NULL))
	  {
		  current = current->link();
		  i++;
	  }
	  binary_tree_node<Item>* root = new binary_tree_node<Item>;
	  //Linked list data is entered into the root data
	  root->data() = current->data();
	  //Construct left subtree 
	  root->left() = make_BST(head, a, middle_num-1);
	  //Construct right subtree
	  root->right() = make_BST(head, middle_num+1, b);
	  return root;
	  }  
} 
