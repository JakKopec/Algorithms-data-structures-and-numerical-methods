#include"structuresLib.h"
#define string int
#define N 20 //rozmiar kolejki
#define M 20 //rozmiar stosu
void list::create_node(string arg)
    {    
    node* temp=new node;
    temp->data=arg;
    temp->next=NULL;
    if(head==NULL)
      	{
        head=temp;
        tail=temp;
      	}
    else
    	{			
    	tail->next=temp;
    	temp->prev=tail;
    	tail=temp;
    	}
	}
	
void list::insert_start(string arg)
	{

	node* temp=new node;
    temp->data=arg;
    temp->prev=NULL;
    temp->next=this->head;
    this->head=temp;
    if(temp->next)
    	{
    	temp->next->prev=temp;
		}
	else
		{
		this->tail=temp;	
		}		
	}
		
void list::delete_last_node()
	{
	node* temp=tail;
	if(tail->prev!=NULL)
		{	
		this->tail=this->tail->prev;
		tail->next=NULL;
		delete temp;
		return;	
		}
	else{tail=head=NULL;delete temp;}	
	}
	
void list::delete_first_node(void)
	{
  	node* temp=head;
	if(this->head==NULL){cout<<"The list is empty!\n";delete temp;return;}
	this->head=temp->next;
	delete temp;
	}
	
void list::delete_node(node* arg)
	{
	node* temp=this->head;
	while(temp!=arg)
		{
		temp=temp->next;
		}
	if(temp==head){this->delete_first_node();}
	else if(temp==tail){this->delete_last_node();}
	else
		{
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		delete temp;
		}	
	}

void list::display_list(void)	
	{    
	node* temp=head;
	cout<<"List:\n";
	while(temp!=NULL)
		{
		cout<<temp->data<<" ";	
		temp=temp->next;
		}
		cout<<endl;
	}
	
bool list::is_empty(void)
	{
	if(this->head==NULL)
		{
		cout<<"The queue is empty!\n";return true;
		}
	else
		{
		cout<<"The queue isnt empty!\n";return false;
		}
	}

void list::randomize_list(int temp)
	{
	int temp2=0;
	srand(time(NULL));
	while(temp2<2*temp)
		{
		string random='A'+rand()%(4);
		this->create_node(random);
		temp2++;
		}	
	}
	
//arg-usuwana z listy litera	
string list::check_list(string arg)
	{
	node* temp=this->head;
	while(temp)
		{
		if(temp->data==arg)
			{
			char tempchar=temp->data;
			this->delete_node(temp);
			return tempchar;
			}
		temp=temp->next;
		}	
	delete temp;
	return 0;	
	}	

//STACK______________________________________________________________________________________________________________________________________________________
//___________________________________________________________________________________________________________________________________________________________

void stack::push(char value)
	{
	if(this->isfull()==false)
		{
		//if(value==' '){return;}	
		//cout<<"Pushing a value:\t"<<value<<endl;	
		this->array[++top]=value;
		}
	}
char stack::pop(void)
	{	
	if(this->isempty()==false)
		{		
		//cout<<"Fetching down a value:\t"<<this->array[top]<<endl;
		char temp='-';
		temp=this->array[top];
		this->array[top]='0';
		top--;
		return temp;
		}	
	}		
	
bool stack::isempty()
	{
	if(top==-1){cout<<"stack is empty!\n";return true;}
	else{return false;}	
	}

bool stack::isfull()
	{
	if(top==(size-1)) {//cout<<"stack is full!\n";
	return true;}
	else{return false;}	
	}

	
void stack::randomize_stack(int temp)
	{
	int temp2=0;
	srand(time(NULL));
	while(temp2<2*temp)
		{
		string random='A'+rand()%(4);
		push(random);
		temp2++;
		}
	}
//niepotrzebne	
void stack::show_stack()
	{
	cout<<"Stack:\n";	
	for(int b=0;b<this->size;b++)
		{
			cout<<this->array[b]<<" ";
		}
	cout<<"\n";		
	}
	
char stack::pop(char val,int size)
	{
	if(this->isempty()==false)
		{		
		int index=0;
		while(index!=(size))
			{
			if(this->array[index]==val)
				{
				cout<<"Fetching down a value from the stack:\t"
				<<this->array[index]<<endl;	
				val=this->array[index];
				array[index]='0';
				for(int a=index;a<size;a++)
					{
					array[a]=array[a+1];
					}					
				return val;	
				}
			index++;		
			}
		return '0';
		}		
	}

//QUEUE_______________________________________________________________________________________________________________________________________________________
//____________________________________________________________________________________________________________________________________________________________

void queue::push(char value)
	{
	if(capacity>size)
		{
		cout<<"error-the queue is full\n";return;
		}
	else
		{
		//cout<<"Pushing a value:\t"<<value<<"\n";
		rear=(rear+1)%size;
		array[rear]=value;
		capacity ++;	
		}	
	}
	
void queue::pop()
	{
	if(capacity==0)
		{
		cout<<"erroe-the queue is empty\n";return;	
		}
	else
		{
		//cout<<"Fetching down a value:\t"<<array[front]<<"\n";
		front=(front+1)%size;
		capacity--;
		
		}		
	}
	
bool queue::isfull()
	{
	if(this->capacity==this->size)
		{
		cout<<"The queue is full\n";//return true;
		}
	else
		{
		cout<<"The queue isnt full\n";//return false;	
		}	
	}	
	
bool queue::isempty()
	{
	if(this->capacity<=0)
		{
		cout<<"The queue is empty\n";
		return true;
		}
	else
		{
		//cout<<"The queue isnt empty\n";
		return false;	
		}	
	}	

void queue::randomize_queue(int temp)
	{
	int temp2=0;
	srand(time(NULL));
	while(temp2<=(this->size))
		{
		string random='A'+rand()%(4);
		push(random);
		temp2++;
		}
	}
//niepotrzebne 
void queue::show_queue()
	{
	cout<<"Queue:\n";	
	for(int b=0;b<this->size;b++)
		{
			cout<<this->array[b]<<" ";
		}
	cout<<"\n";		
	}
	
char queue::pop(char val,int size)
	{
	if(this->isempty()==false)
		{		
		int index=0;
		while(index!=(size))
			{
			if(this->array[index]==val)
				{
				cout<<"Fetching down a value from the queue:\t"<<this->array[index]<<endl;	
				val=this->array[index];
				array[index]='0';
				for(int a=index;a<size;a++)
					{
					array[a]=array[a+1];
					}					
				return val;	
				}
			index++;		
			}
		return '0';
		}		
	}	
	
	
//BINARY TREE________________________________________________________________________________________________________


//prev - lewo ,next-prawo-wykorzystanie klasy node(lab1)

void binary_tree::insert(int val)
	{
	if(root!=NULL){insert(val,root);}
	else
		{
		root =new node;
		root->data=val;
		root->next=NULL;root->prev=NULL;	
		}	
	}

void binary_tree::insert(int val,node* leaf)
	{
	if(val<(leaf->data))
		{
		if(leaf->prev!=NULL){insert(val,leaf->prev);}	
		else
			{
			leaf->prev=new node;
			leaf->prev->data=val;
			//leaf->prev->level++;
			leaf->prev->prev=NULL;
			leaf->prev->next=NULL;		
			}
		}
	else if(val>=(leaf->data))
		{
		if(leaf->next!=NULL){this->insert(val,leaf->next);}	
		else
			{
			leaf->next=new node;
			leaf->next->data=val;
			//leaf->next->level++;
			leaf->next->prev=NULL;
			leaf->next->next=NULL;		
			}
		}		
	}

void binary_tree::destroy_tree()
	{
 	destroy_tree(root);
	}
	
void binary_tree::destroy_tree(node *leaf)
	{
 	if(leaf!=NULL)
  		{
    	destroy_tree(leaf->prev);
    	destroy_tree(leaf->next);
    	delete leaf;
  		}
	}
	
void binary_tree::preorder()
	{
	cout<<"\nPreorder:\n";	
	this->preorder(this->root);	
	}
	
void binary_tree::preorder(node* root)
	{
	node* ptr=root;	
	if(this->root!=NULL)
		{
		cout<<ptr->data<<"\t";
		if(root->prev)	this->preorder(root->prev);
		if(root->next)	this->preorder(root->next);
		}
	else return;	
	}
	
void binary_tree::inorder()
	{
	cout<<"\nInorder:\n";	
	this->inorder(this->root);	
	}

void binary_tree::inorder(node* root)
	{
	node* ptr=root;
	if(this->root!=NULL)
		{
		if(root->prev)	this->inorder(root->prev);
		cout<<ptr->data<<"\t";
		if(root->next)	this->inorder(root->next);
		}
	else return;		
	}
	
void binary_tree::postorder()
	{
	cout<<"\nPostorder:\n";	
	this->postorder(this->root);	
	}

void binary_tree::postorder(node* root)
	{
	node* ptr=root;
	if(this->root!=NULL)
		{
		if(root->prev)	this->postorder(root->prev);
		if(root->next)	this->postorder(root->next);
		cout<<ptr->data<<"\t";
		}
	else return;		
	}
	
/*void binary_tree::inorder_s()
	{
	node tab[20];
	int counter=0;
	node* ptr=this->root;
	while(1)
		{
		while(ptr!=NULL)
			{
			tab[couter]=	
			}
		}
	}*/
		
		
bool bst_tree::insert(node* arg)
	{
	if(this->root)
	{	
		node* par=NULL;
		node* temp=this->root;
		
		arg->prev=NULL;arg->next=NULL;
		while(temp)
			{
			if(arg->data==temp->data){return false;}
			par=temp;
			if(arg->data < temp->data){temp=temp->prev;}
			else{temp=temp->next;}	
			//temp=(arg->value < temp->value) ? temp->prev : temp->next
			arg->parent=par;	
			}
		if(!par){root=arg;}
		else if(arg->data < par->data){par->prev=arg;}
		else{par->next=arg;}
		return true;
	}
	else this->root=arg;return 0;
	}		

		
		
node* bst_tree::max(void)
	{
	if(!root){cout<<"The are no elements!\n";return NULL;}
	node* temp=root;	
	while(this->root->next)
		{
		temp=temp->next;
		}
	cout<<"Maximum:"<<temp->data;return temp;	
	}
	
node* bst_tree::min(void)
	{
	if(!root){cout<<"The are no element!\n";return NULL;}
	node* temp=root;	
	while(this->root->prev)
		{
		temp=temp->prev;
		}
	cout<<"Maximum:"<<temp->data;return temp;	
	}
	
node* bst_tree::search(int val)
	{
	if(!root){cout<<"The are no elements!\n";return 0;}
	node* temp=root;
	//brak sprawdzenia czy element istnieje !
	//inline bool check(bst_tree a,node b)}
	if(temp->data<val){temp=temp->prev;}
	else if(temp->data>val){temp=temp->next;}
	//else if
	else{cout<<"A value has been found"<<temp->data<<"\n";}
	 
	
	}
