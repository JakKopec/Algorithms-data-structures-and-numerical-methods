#include<iostream>
#include<time.h>
#include<windows.h>
#include<fstream>
using namespace std;
#define N 100
struct data
	{
	string name;
	int swaps;
	int comparisions;
	data(){swaps=0;comparisions=0;};
	};

void save(data arg)
    {
	fstream file;
    file.open("Textfile.txt",ios::out | ios::app);
    if(file.good()==false)
    	{
       	cout<<"Error!\n";return;
		}
	file<<"\n"<<arg.name<<"\t\t"<<arg.swaps<<"\t"<<arg.comparisions<<"\n";
    }

void load(void)
    {
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
		cout<<temp;
		}
	file.close();
	}

void display_data(data temp)
    {
    cout<<"NAME:"<<temp.name<<endl;
	cout<<"SWAPS:"<<temp.swaps<<endl;
	cout<<"COMPARISIONS:"<<temp.comparisions<<endl;
    }

void display_array(int arr[])
	{
	cout<<"\n";
	for(int a=1;a<=N;a++)
        {
	    cout<<arr[a-1]<<"\t";
        if(a%10==0){cout<<endl;}
        }
	cout<<endl;
	return;
	}

void randomize_array(int arr[])
	{
	for(int a=0;a<N;a++)
		{
		arr[a]=-100+rand()%(200);
		Sleep(50);
		}
	//cout<<"RANDOMIZED:\n";display_array(arr);
	return;
	}

data coctail_sort(int arr[])//wahadlowe
	{
	bool if_swap=true;
	int start=0;
	int end=N-1;
	data temp;
	temp.name="coctail_sort:";
    //int s=start;
    //int e=end;
	while(if_swap)
		{
		if_swap=false;
		for(int a=start;a<end;++a)
			{
			temp.comparisions++;
			if(arr[a]>arr[a+1])
				{
				swap(arr[a],arr[a+1]);
				if_swap=true;
				temp.swaps++;
				}
			}

		if(!if_swap){break;}//tablica juz posortowana
		if_swap=false;

		//ostatni element we wlasciwym miejscu:
		end--;

		for(int b=end-1;b>=start;--b)
			{
			temp.comparisions++;
			if(arr[b]>arr[b+1])
				{
				swap(arr[b],arr[b+1]);
				if_swap=true;
				temp.swaps++;
				}
			}
		start++;//pierwszy element we wlasciwym miejscu
		}
	display_array(arr);
	display_data(temp);
	save(temp);
	return temp;
	}

int new_gap(int gap)
	{
	gap=(gap*10)/13;
	if(gap <1)gap =1;
	return gap;
	}

data comb_sort(int arr[])//grzebieniowe
	{
	int gap=N;
	data temp;
    temp.name="comb_sort:";
	while(true)
		{
		gap=new_gap(gap);
		if(gap==1){break;}
		for(int i=0;i<N-gap;++i)
			{
			temp.comparisions++;
			if(arr[i]>arr[i+gap])
				{
				swap(arr[i],arr[i+gap]);
				temp.swaps++;
				}
			}
		}
	//gap==1 zatem sortowanie babelkowe:
	data temp2=bubble_sort_v3(arr);

	temp.comparisions=temp2.comparisions+temp.comparisions;
	temp.swaps=temp2.swaps+temp.swaps;

    display_array(arr);
	display_data(temp);
	save(temp);
	return temp;
	}

data insertion_sort(int arr[])
    {
    data temp;
    temp.name="insertion_sort:";
    int j,temp2;
    for(int i=1;i<N;i++)
        {
        temp2=arr[i];//temp2-wstawiany element
        j=i-1;
        temp.comparisions++;
        while((j>=0)&&(arr[j]>temp2))
            {
            temp.swaps++;
            arr[j+1]=arr[j];
            j=j-1;
            }
        arr[j+1]=temp2;
        }
    display_array(arr);
    display_data(temp);
    save(temp);
    return temp;
    }

int find_min(int arr[],int index)//zwraca indeks
    {
    int min=index;
    for(int i=index;i<N;i++){if(arr[min]>arr[i]){min=i;}}
    return min;
    }

data select_sort(int arr[])
    {
    data temp;
    temp.name="select_sort:";
    int min;
    for(int i=0;i<N;i++)
        {
        min=find_min(arr,i);
        temp.comparisions++;
        if(arr[min]!=arr[i])
			{
			swap(arr[min],arr[i]);
			temp.swaps++;
			}
        }
    display_array(arr);
    display_data(temp);
    save(temp);
    return temp;
    }

//knuth     3*h+1 dopoki h<N potem h/9
data shell_sort(int arr[])
    {
    data temp;
    temp.name="shell_sort:";
    int a,j,h;
    //wyznaczenie pierwszego odstepu
    for(h=1;h<N;h=3*h+1);
    h=h/9;

    if(!h){h=1;}
    //wyznaczenie kolejnych odstepow
    for(;h>0;h=h/3)
        {
        //"przesuwanie" odstepu
        for(int i=h;i<N;++i)
            {
            a=arr[i];//arr[i]==ogon
            //sortowanie przez wstawianie
            temp.comparisions++;
            for(j=i-h;(j>=0)&&(a<arr[j]);j=j-h)
                {
                arr[j+h]=arr[j];//arr[j]=glowa
                temp.swaps++;
                }
            arr[j+h]=a;
            }
        }
    display_array(arr);
    display_data(temp);
    save(temp);
    return temp;
    }


void copied_bubble_sort(int arr[])
	{
	for(int j=0;j<N-1;j++)
    	{
		for(int i=0;i<N-1;i++)
      		{
			if(arr[i]>arr[i+1])
			  	{
			  	swap(arr[i],arr[i+1]);
			  	}
			}
		}
	}

data bubble_sort(int arr[])
	{
	data temp;
	temp.name="bubble_sort_v1:";
	cout<<endl<<"bubble_sort_v1:"<<endl;
	for(int j=0;j<N-1;j++)
    	{
		for(int i=0;i<N-1;i++)
      		{
      		temp.comparisions++;
			if(arr[i]>arr[i+1])
			  	{
			  	temp.swaps++;
			  	swap(arr[i],arr[i+1]);
			  	}
			}
		}
	display_array(arr);
    display_data(temp);
    save(temp);
	return temp;
	}

data bubble_sort_v2(int arr[])//babelkowe bez sprawdzania ulozonych
	{
	data temp;
	temp.name="bubble_sort_v2:";
	for(int j=0;j<N-1;j++)
    	{
		for(int i=0;i<N-j-1;i++)
      		{
      		temp.comparisions++;
			if(arr[i]>arr[i+1])
			  	{
			  	temp.swaps++;
			  	swap(arr[i],arr[i+1]);
			  	}
			}
		}
	display_array(arr);
	display_data(temp);
	save(temp);
	return temp;
	}

data bubble_sort_v3(int arr[])//babelkowe z kontrola monotonicznosci
	{
	data temp;
	temp.name="bubble_sort_v3:";
	cout<<endl<<"bubble_sort_v3:"<<endl;
	bool if_swap;


    for(int j=0;j<N-1;j++)
        {
        if_swap=false;
        for(int i=0;i<N-j-1;i++)
            {
            temp.comparisions++;
            if(arr[i]>arr[i+1])
                {
                temp.swaps++;
                swap(arr[i],arr[i+1]);
                if_swap=true;
                }
            }
            if(!if_swap){break;}
        }
	display_array(arr);
	display_data(temp);
	save(temp);
	return temp;
	}





int main()
	{


	int sortedarray[N];//posortowana                            a)
	int sortedarray2[N];//posortowana w odwrotnej kolejnosci    b)
    int randomizedarray[N];//sortowanie losowych wartosci       c)
	randomize_array(randomizedarray);

	randomize_array(sortedarray);
	copied_bubble_sort(sortedarray);
	int temp;
	for(int i=0,temp=N-1;i<N;i++,temp--)
        {
        sortedarray2[i]=sortedarray[temp];
        }

	//bubble_sort(randomizedarray);

	//bubble_sort_v2(randomizedarray);

	//bubble_sort_v3(randomizedarray);

	//coctail_sort(randomizedarray);

	//comb_sort(randomizedarray);

    //insertion_sort(randomizedarray);

    //select_sort(randomizedarray);

    //shell_sort(randomizedarray);

	return 0;
	}



