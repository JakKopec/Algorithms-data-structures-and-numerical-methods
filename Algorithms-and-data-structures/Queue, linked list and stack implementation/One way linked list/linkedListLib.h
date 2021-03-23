#include<string>
#include<iostream>
#include<fstream>

using namespace std;
//#define string int
class list;
class node	{

	string data;
	node* ptr;    	
  	public:
	
	node(){};
	node(string dataa):data(dataa){ptr=NULL;};
	~node(){};
	string getdata(){return this->data;}
	friend class list;
			};

class list{
	
	node *head,*tail;
	public:
	list(){head=NULL;tail=NULL;};
	~list(){};
	
	node* createnode(string arg);
	node* createnode(node* node);
	
	void insert_start(string arg);
	void insert_start(node* arg);
	
	node* searchfor(string arg);
	
	node* getprevptr(node *arg);
	void deletenode(node* arg);
	void deletenode(string arg);
	void deletefirstnode(void);
	void deletelastnode(void);
	
	void displaylist(void);
	void importlist(void);
	
	//queue
	bool isempty(void);
	};
