/*
Aim : Store data of students using hashing function for roll number and implement linear probing using chaining without replacement algorithm
*/
#include <iostream>
using namespace std;
#define size 13
#define h(x) x%size;
class hash
{

	int data[size];
	int flag[size];
	int chain[size];
    public:
	void insert(int x);
	void display();
	void search();
	hash()
	{
		for(int i=0;i<size;i++)
		{
			data[i]=11111;
			flag[i]= 0;
			chain[i]= -1 ;
		}
	}

};
void hash::insert(int x)
{
	int i=0,j,start;
	start=h(x);
	while(flag[start] && i<size)
	{
		if(data[start]%size==x%size)  //finding start of chain
		break;
		i++;
		start=(start+1)%size;
	}
	if(i==13)
	{
		cout<<"\nHash table is full";
	}
	while(chain[start]!=-1)                           //following chain
	 start=chain[start];

	 j=start;
	 while(flag[j] && i<size)
     {
     	i=i+1;                                           //finding next space to store
     	j=(j+1)%size;
	 }

	data[j]=x;
	flag[j]=1;
	if(j!=start)
	{
		chain[start]=j;
	}

}
void hash::display()
{
	cout<<"\nIndex    RollNO        Flag      chain\n";
	for(int i=0;i<size;i++)
	{
		cout<<i;
	    cout<<"\t";
	    cout<<data[i];
		cout<<"\t\t";
		cout<<flag[i];
		cout<<"\t";
		cout<<chain[i];
		cout<<"\n";
	}
}
void hash::search()
{
	int i=0,j,x;
	cout<<"Enter roll no to be searched";
	cin>>x;
	j=h(x);
	while(i<size && flag[j] && data[j]%size != x%size)
	{
		i++;
		j=(j+1)%size;                                  //finding start of chain

	}
	if(flag[j]==0 || i==size)
	{
		cout<<"\nNot found";                    //data not found
	}
	while(j!= -1)
	{
		if(data[j]==x)
		{
			cout<<"\nData is stored at"<<j;                   //going through chain
			break;
		}
		j=chain[j];
	}
	if(j == -1)
	{
		cout<<"\nssssNot found";
	}

}


int main() {
	int  choice,t,p,s,i=0;
	class hash h;
	do{
		cout<<"\nEnter \n1-Insert data \n 2 - Display hash table \n3- Search position";
		cin>>choice;
		switch(choice)
		{
		  case 1 : cout<<"\nMAX Size of table is 13-prime no";
		           cout<<"\nEnter No of students";
		           cin>>s;
		           if(s>13)
		            {
				     	break;
				    }
		           cout<<"\nEnter RollNO to be inserted\n";
		           while(i<s)
		           {

				     cin>>p;
				     h.insert(p);
				     i++;
			       }
				   break;
		  case 2 : cout<<"\nDisplaying Hash Table\n";
		           h.display();
		           break;
		  case 3 : h.search();
		           break;
		  default : cout<<"\nWrong choice";
		}
		cout<<"\nDo you want to continue 1/0";
		cin>>t;
	}while(t==1);
	return 0;
}
/* OUTPUT


Enter
1-Insert data
 2 - Display hash table
3- Search position1

MAX Size of table is 13-prime no
Enter No of students13

Enter RollNO to be inserted
18
41
22
44
45
59
32
31
73
57
58
23
77

Do you want to continue 1/01

Enter
1-Insert data
 2 - Display hash table
3- Search position2

Displaying Hash Table

Index    RollNO        Flag      chain
0       57              1       -1
1       58              1       -1
2       41              1       -1
3       23              1       -1
4       77              1       -1
5       18              1       6
6       44              1       11
7       45              1       10
8       59              1       -1
9       22              1       -1
10      32              1       1
11      31              1       0
12      73              1       -1

Do you want to continue 1/01

Enter
1-Insert data
 2 - Display hash table
3- Search position3
Enter roll no to be searched31

Data is stored at11
Do you want to continue 1/01

Enter
1-Insert data
 2 - Display hash table
3- Search position3
Enter roll no to be searched44

Data is stored at6
Do you want to continue 1/0
*/
