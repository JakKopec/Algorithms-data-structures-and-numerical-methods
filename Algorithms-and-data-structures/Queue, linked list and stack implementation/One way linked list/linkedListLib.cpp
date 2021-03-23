#include "linkedListLib.h"	
node* list::createnode(string arg)
    {    
    node* temp=new node;
    temp->data=arg;
    temp->ptr=NULL;
    if(head==NULL)
      	{
        head=temp;
        tail=temp;
        temp=NULL;
      	}
    else
    	{			
    	tail->ptr=temp;
    	tail=temp;
    	}
    //cout<<"new node!"<<endl;	
    }	
    
node* list::createnode(node* node)
    {    
    node* temp=new node;
    temp->data=node->data;
    temp->ptr=NULL;
    if(head==NULL)
      	{
        head=temp;
        tail=temp;
        temp=NULL;
      	}
    else
    	{			
    	tail->ptr=temp;
    	tail=temp;
    	}
    //cout<<"new node!"<<endl;	
    }
    	
		
void list::insert_start(string arg)
	{
	
	fstream file;
    file.open("Textfile.txt",ios::out | ios::app);
    if(file.good()==false)
    	{
       	cout<<"Error!\n";return;
		}	
	node* temp=new node;
    temp->data=arg;
    temp->ptr=head;
    head=temp;
	}
	
void list::insert_start(node* arg)
	{
	
	fstream file;
    file.open("Textfile.txt",ios::out | ios::app);
    if(file.good()==false)
    	{
       	cout<<"Error!\n";return;
		}
		
	node* temp=new node;
    temp->data=arg->data;
    temp->ptr=head;
    head=temp;
	}	
	
node* list::searchfor(string arg)
	{
	node* guard=this->createnode(arg);
	node* temp=this->head;
	node* lastvalue=NULL;
	//cout<<temp<<"\t\t"<<guard;
	while(temp)
		{
		cout<<temp<<"\t";	
  	    if((temp->data)==(guard->data))
			{
			cout<<"A value has been found!\n";lastvalue->data=temp->data;return lastvalue;
			if(guard==temp)
				{
				cout<<"A temporary pointer has reached the end of a list!\n";
				cout<<"LAST VALUE"<<lastvalue;
				}
			}
		temp=temp->ptr;
        }
	}		
	
node* list::getprevptr(node* arg)
	{
    node* temp = this->head;
    while(temp)
		{
  	    if(temp->ptr == arg){return temp->ptr;}
  	    //cout<<temp<<"\t\t";
		temp= temp->ptr;
        }
    return NULL;
    }		
		
void list::deletenode(node* arg)
	{
	//node* next=new node;
	//next->ptr=arg->ptr;
    node* previous;
	previous->ptr=this->getprevptr(arg);
    previous->ptr=arg->ptr;
    delete arg;
	}

void list::deletenode(string arg)
	{
	node* temp=this->head;
	node* previous=new node;
	while(temp)
		{
  	    if(temp->data == arg)
		  	{
			previous->ptr=this->getprevptr(temp);
			return;
			}
		temp= temp->ptr;
        }
	previous->ptr=temp;
	//jak tu siê dobraæ do usuwanego elemntu?	
	}
	
void list::deletefirstnode(void)
	{
	node* temp=new node;
	temp=this->head;
	if(this->head==NULL){cout<<"The list is empty!\n";return;}
	this->head=temp->ptr;	
	delete temp;		
	}
	

	
void list::displaylist(void)	
	{
	fstream file;
    file.open("Textfile.txt",ios::out );//| ios::app)
    if(file.good()==false)
    	{
       	cout<<"Error!\n";
		return;
		}
        
	node* temp=new node;
	temp=head;
	while(temp!=NULL)
		{
		cout<<temp->data<<"\n";
		file<<temp->data<<endl;	
		temp=temp->ptr;
		}
	cout<<endl<<endl;
	file.close();
	}
		
void list::importlist(void)
	{
	cout<<"\nIMPORT";
	fstream file;
    file.open("Textfile.txt",ios::in);
    if(file.good()==false)
    	{
       	cout<<"Error!\n";return;
        }
	string temp;	
	while(!file.eof())
		{
		getline(file,temp);
		this->createnode(temp);
		}
	cout<<"\n\n";
	cout<<"Display after import:\n";	
	this->displaylist();	
	file.close();		
	}	
	
bool list::isempty(void)
{
	if(this->head==NULL)
		{
		cout<<"A queue is empty!\n";return true;
		}
	else
		{
		cout<<"A queue isnt empty!\n";return false;
		}
}	

void list::deletelastnode(void)
	{
	fstream file;
    file.open("Stack.txt",ios::out | ios::app);
    if(file.good()==false)
    	{
       	cout<<"Error!\n";
		return;
		}
	cout<<"Fetching down:\t"<<tail->data<<endl;	
	file<<tail->data<<endl;
		
	node* temp=new node;
	temp=this->head;
	node* temp2=new node;
	temp2=this->head;
	while(this)
	{
		temp=temp->ptr;
		//counter++;
		if(temp->ptr==NULL)
		{
		//	delete temp;	
			temp2->ptr=NULL;delete temp;
			this->tail=NULL;
			break;
		}
		temp2=temp2->ptr;
	}	
	//sprawdzenie
	//node* temp3=new node;
	//temp3=head;
	file.close();
}
/*	//alternatywa:
		node* temp3=new node;
		temp3=head;
		while(this)
			{
			if(temp3->ptr->ptr=NULL)
				{
				node* temp4= new node;
				temp4=temp3->ptr->ptr;
				delete temp3;
				this->tail=temp4;
				}
		temp3=temp3->ptr;
		//while(this)
		//{cout<<temp3<<endl;
		//temp3=temp3->ptr;}
			}
	*/
