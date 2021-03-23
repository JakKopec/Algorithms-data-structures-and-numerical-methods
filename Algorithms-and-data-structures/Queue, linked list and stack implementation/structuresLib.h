//#include<string>
#include<iostream>
#include <cstdlib>
#include<time.h> 
#include <windows.h>

using namespace std;
#define string int 
#define node node
class list;
class stack;
class queue;
class binary_tree;
class bts_tree;

class node	{
   	string data;
	node* next;
	node* prev;
	node* parent; 
  	public:
	
	node(){};
	node(string dataa):data(dataa){};
	~node(){};
	friend class list;
	friend class binary_tree;
	friend class bst_tree;
			};




class list{
	node *head,*tail;
	public:
	list(){head=NULL;tail=NULL;};
	~list(){};
	
	void create_node(string arg);
	void insert_start(string arg);
	void delete_first_node(void);
	void delete_last_node(void);
	void delete_node(node* arg);
	void display_list(void);
	//queue
	bool is_empty(void);
	void randomize_list(int temp);
	string check_list(string arg);
	friend void zad2(list a,list b,stack c);
	friend void zad3(queue a,stack b,list c);
	};



	
class stack
	{
	char* array;
	int size;
	int top;
	public:
	friend void zad2(list a,list b,stack c);
	
	stack(int sizee=0):size(sizee)
		{
		array=new char[size];
		top=-1;
		}		
	~stack(){delete array;}	
	
	void push(char value);
	char pop(void);
	bool isempty();
	bool isfull();
	void randomize_stack(int temp);	
	friend void zad3(queue a,stack b,list c);
	void show_stack();
	char pop(char val,int size);
	};
	
	
	
	
class queue	{
	char* array;	
	int front;
	int rear;
	int size;
	int capacity;
	
	public:
	queue(int sizee=0):size(sizee)
	{
		array=new char[size];
		front=0;rear=-1;
		capacity=0;
	}
	~queue(){delete array;}	
	
	void push(char value);
	void pop();
	bool isfull();
	bool isempty();
	void randomize_queue(int temp);
	friend void zad3(queue a,stack b,list c);
	void show_queue();
	char pop(char val,int size);
			};		
	
	
class binary_tree
{
    node *root;
    void insert(int key,node* leaf);
    node *search(int key,node* leaf);
	void destroy_tree(node* leaf);
	void preorder(node* root);   
    void inorder(node* root);
    void postorder(node* root);
	
	public:
		
    binary_tree(){root=NULL;};
    ~binary_tree(){destroy_tree();};
 
    void destroy_tree();
    void insert(int key);
   // node* search(int key);
    
    void preorder(); 
    void inorder();
    void postorder();
    
    void inorder_s();
    void preorder_s();
    void postorder_s();
};


class bst_tree{
	node* parent;
	node* root;
	int value;
	
	public:
	bst_tree(){root=NULL;}
	//bst_tree(int value):val(value){};
	~bst_tree(){};
	
	void insert(int val);
	bool insert(node* arg);
	void destroy_tree(void);

	node* max(void);
	node* min(void);
	node* search(int val);
	
	
//3 przypadki - gdy element jest li�ciem , ma potomk�w,kiedy ma dw�ch potomk�w
	void delete_element(node* del);
	void display_tree(void);
		
};	
	
