#include<iostream>
#define string int
using namespace std;
class binary_tree;
class bst_tree;

class node	
	{
		
  	public:
  	long int data;
	node* next;
	node* prev;
	node* parent;
	unsigned int level;
	node(){prev=NULL;next=NULL;level=0;};
	node(int dataa):data(dataa){level=0;};
	~node(){delete next,prev,parent;};
	friend class binary_tree;
	friend class bst_tree;
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


class bst_tree
	{
	node* parent;
	node* root;
	
	public:
	bst_tree(){root=NULL;}
	~bst_tree(){};
	
	node* insert(node* arg);

	node* max(void);
	node* min(void);
	
	node* search(int val);
	
	void inorder(void);
	void inorder(node* root);
	
	void preorder(void);
	void preorder(node* root);
	
	void postorder(void);
	void postorder(node* root);
	
	void deletenode(node* arg); 
	node* return_successor(node* arg);
	node* return_predecessor(node* arg);
	
	node* min(node* arg);
	node* max(node* arg);
	int height(node* arg);//wysoko�� drzewa
	int lenght(node* arg);//d�ugo�� najkr�tszej �cie�ki poddrzewa zaczepionego w root->parent
	void update(node* arg);
	
	};	
