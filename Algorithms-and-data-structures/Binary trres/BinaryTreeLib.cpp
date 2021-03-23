#include"BinaryTreeLib.h"

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
		
node* bst_tree::insert(node* arg)
	{
	arg->next=arg->prev=arg->parent=NULL;
	node* temp=this->root;
	
	if(!temp){this->root=arg;cout<<"\nInsert: val:"<<arg->data<<"\t level:"<<arg->level<<endl;return arg;}
	int lvl=1;
	while(true)
		{
		if(arg->data < temp->data)
			{
			if(!temp->prev)
				{
				temp->prev=arg;
				arg->level=lvl;
				break;
				}
			else {temp=temp->prev;lvl++;}
			}
		else
			{
			if(!temp->next)
				{
				temp->next=arg;
				arg->level=lvl;
				break;
				}
			else {temp=temp->next;lvl++;}
			}
			arg->parent=temp;
		}
	cout<<"\nInsert: val:"<<arg->data<<"\t level:"<<arg->level<<endl;	
	return arg;		
	}

node* bst_tree::max(void)
	{
	if(!root){cout<<"\nThe are no elements!\n";return NULL;}
	node* temp=root;	
	while(temp->next!=NULL)		{temp=temp->next;}
	cout<<"\nMaximum:"<<temp->data;cout<<endl;
	return temp;	
	}
	
node* bst_tree::min(void)
	{
	if(!root){cout<<"\nThe are no elements!\n";return NULL;}
	node* temp=root;	
	while(temp->prev!=NULL)		{temp=temp->prev;}
	cout<<"\nMinimum:"<<temp->data;cout<<endl;
	return temp;	
	}
	
node* bst_tree::search(int val)
	{
	if(!root){cout<<"\nThe are no elements!\n";return NULL;}
	node* temp=this->root;
	while(temp)
		{		
		if(val<temp->data)
			{
			if(temp->prev!=NULL)	{temp=temp->prev;}
			else	{cout<<"\n\nA value hasnt been found!\n";return NULL;}
			}
		if(val>temp->data)
			{
			if(temp->next!=NULL)	{temp=temp->next;}
			else	{cout<<"\n\nA value hasnt been found!\n";return NULL;}
			}
		if(val==temp->data)
			{cout<<"\n\nA value has been found!\n"<<temp->data<<endl;return temp;}	
		}
	}	

void bst_tree::inorder()
	{
	cout<<"\nBST Inorder:\n";	
	this->inorder(this->root);	
	}
	
void bst_tree::inorder(node* root)
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
	
void bst_tree::postorder()
	{
	cout<<"\nBST Postorder:\n";	
	this->postorder(this->root);	
	}

void bst_tree::postorder(node* root)
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

void bst_tree::preorder()
	{
	cout<<"\nBST Preorder:\n";	
	this->preorder(this->root);	
	}
	
void bst_tree::preorder(node* root)
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
	
void bst_tree::deletenode(node* arg)
	{
	//gdy drzewo jest puste	:
	if(!(this->root)){cout<<"\nThe are no elements!\n";return;}
	//gdy nie ma w drzewie w�z�a o tym samym adresie co argument:
	//if(this->search(arg->data)==NULL){cout<<"The node hasnt been found\n";return;}
	
	
	
	//gdy arg nie ma potomk�w albo ma jednego :
	node* temp1=NULL;
	node* temp2=NULL;
	if((!arg->next)||(!arg->prev))
		{temp1=arg;}
		else{temp1=this->return_successor(arg);}
	
	if(temp1->prev)		
		{temp2=temp1->prev;}
		else{temp2=temp1->next;}	
	//je�li nie ma potomk�w :  
	if(temp2){temp2->parent=temp1->parent;}
	
	//je�li temp 1 to korze�
	if(!temp1->parent){this->root=temp2;}
	
	//je�li temp1 jest lewym li�ciem
	else if(temp1==temp1->parent->prev){temp1->parent->prev=temp2;}
	else{temp1->parent->next=temp2;}
	
	//skopiowanie danych 
	if(temp1!=arg){arg->data=temp1->data;}
	
	delete temp1;
	
	/*
	node* temp1=NULL;
	if(arg->next||arg->prev)	temp1=this->return_successor(arg);
	else temp1=arg;
	node* temp2=NULL;
	if(temp1->prev) temp2=temp1->prev;
	else temp2=temp1->next;
	if(temp2) temp2->parent=temp1->parent;
	if(temp2->parent)
	{
	if(temp1=temp1->parent->prev)	temp1->parent->prev=temp2;
	else temp1->parent->next=temp2;			
	}
	else root=temp2;
	if(temp2!=arg)	arg->data=temp1->data;
	delete temp1;*/
	
	}
	
node* bst_tree::return_successor(node* arg)
	{
	if(arg->next)
		{return this->min(arg->next);}
		else
			{
			node* temp=arg->parent;
			while(temp&&(arg==temp->next))
				{
				arg=temp;
				temp=temp->parent;	
				}
			return temp;		
			}
	return arg;	
	}
	
node* bst_tree::return_predecessor(node* arg)
	{
	if(arg->prev)
		{return this->max(arg->prev);}
		else
			{
			node* temp=arg->parent;
			while(temp&&(arg==temp->prev))
				{
				arg=temp;
				temp=temp->parent;	
				}
			//cout<<"\nPredecessor"<<temp->data<<endl;	
			return temp;		
			}
	//cout<<"\nPredecessor:"<<arg->data<<endl;			
	return arg;		
	}	
	
node* bst_tree::min(node* arg)
	{
	while(arg->prev){arg=arg->prev;}
	return arg;	
	}
	
node* bst_tree::max(node* arg)
	{
	while(arg->next){arg=arg->next;}
	return arg;	
	}	
	
int bst_tree::height(node* arg)
	{  
    if(arg == NULL)		return 0;  
    else
    	{  
        int lDepth=this->height(arg->prev);  
        int rDepth=this->height(arg->next);  
      
        if(lDepth > rDepth)  	return(lDepth + 1);  
        else 					return(rDepth + 1);  
    	}  	
	}
		
	
int bst_tree::lenght(node* arg)
	{
		if(arg == NULL)		return 0; 
		else
		{ 
		
		node* temp=this->return_predecessor(arg);
		cout<<"Argument:"<<arg->data<<endl;	
		cout<<"Predecessor:"<<temp->data<<endl;
		
		//int max=this->height(temp);
		int prev_short=this->height(temp->prev);
		int next_short=this->height(temp->next);
		if(prev_short>next_short)	return(prev_short);
		else return(next_short);
		}
	}
	
void bst_tree::update(node* arg)
	{
	cout<<"Tree before update:";
	this->postorder();
	
	node* temp=this->return_predecessor(arg);
	temp->data=temp->data+this->root->data;
	node* temp2;temp2->data=temp->data;
	this->deletenode(temp);
	this->insert(temp2);
	
	cout<<"\nTree after update:";
	this->postorder();cout<<endl<<endl;	
	}		
