/*Aim : Store data of students using hashing function for telephone number and implement linear probing using chaining with replacement algorithm */
#include <iostream>

using namespace std;
#define size 13
#define h(x) x%size
class hash
{
	int data[size];
	int flag[size];
	int chain[size];

	public:
		hash()
		{
			for(int i=0;i<size;i++)
			{
				data[i]=11111;
				flag[i]=0;
				chain[i]=-1;
			}
		}
		void display();
		void insert(int x);
		void search();

};

void hash::insert(int x)
{
	int i=0,j,cnt=0,start;
	start=h(x);
	if(flag[start]==0)
	{
		data[start]=x;             //start of chain                    //1
		flag[start]=1;                  //inserting at start of chain
		return;
	}
	if(h(data[start])!=h(x))                  //if occupied by data with another key
	{
		cnt=0; j=start;
		while(flag[j] && cnt<size)
		{
			j=(j+1)%size;
			cnt++;
			            //finding empty location
		}                                               //2
		if(cnt==size)
		{
			cout<<"\nHash Table is full";
			return;
		}
		i=data[start]%size;    //hash of element present at home adr
		while(chain[i]!=start)
		 i=chain[i];                  //previous element of chain

		 chain[i]=chain[start];      //connecting next element directly to previous element
		 while(chain[i]!=-1)
		 i=chain[i]; //going to end of chain

		 chain[i]=j;
		 data[j]=data[start];   //replacement
		 chain[start]=-1;
		 flag[j]=1;
		 chain[j]=-1;

		 data[start]=x;       //inserting at original location
		 chain[start]=-1;

		return;
	}
	i=0;j=start;
	while(flag[j] && i<size)
	{
		j=(j+1)%size;           //finding next empty loc
		i++;                                 //3
	}
	if(i==size)
	{
		cout<<"\nTable is full";
		return;
	}
	data[j]=x;
	flag[j]=1;         //storing at next empty loc
	chain[j]=-1;
	i=start;
	while(chain[i]!=-1)
	{                         //going at end of chain
		i=chain[i];
	}
	chain[i]=j;      //connecting to the end of chain
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
		j=(j+1)%size;

	}
	if(flag[j]==0 || i==size)
	{
		cout<<"\nNot found";
	}
	while(j!= -1)
	{
		if(data[j]==x)
		{
			cout<<"\nData is stored at"<<j;
			break;
		}
		j=chain[j];
	}
	if(j == -1)
	{
		cout<<"\nssssNot found";
	}


}
void hash::display()
{
	cout<<"\nIndex    phnNO        Flag      chain\n";
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
		           cout<<"\nEnter phnNO to be inserted\n";
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
3- Search position2

Displaying Hash Table

Index    phnNO        Flag      chain
0       11111           0       -1
1       11111           0       -1
2       11111           0       -1
3       11111           0       -1
4       11111           0       -1
5       11111           0       -1
6       11111           0       -1
7       11111           0       -1
8       11111           0       -1
9       11111           0       -1
10      11111           0       -1
11      11111           0       -1
12      11111           0       -1

Do you want to continue 1/01

Enter
1-Insert data
 2 - Display hash table
3- Search position1

MAX Size of table is 13-prime no
Enter No of students13

Enter phnNO to be inserted
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

Index    phnNO        Flag      chain
0       57              1       4
1       58              1       3
2       41              1       -1
3       32              1       -1
4       44              1       -1
5       18              1       11
6       45              1       1
7       59              1       -1
8       73              1       -1
9       22              1       -1
10      23              1       -1
11      31              1       0
12      77              1       -1

Do you want to continue 1/01

Enter
1-Insert data
 2 - Display hash table
3- Search position3
Enter roll no to be searched5

ssssNot found
Do you want to continue 1/01

Enter
1-Insert data
 2 - Display hash table
3- Search position3
Enter roll no to be searched18

Data is stored at5
Do you want to continue 1/01

Enter
1-Insert data
 2 - Display hash table
3- Search position3
Enter roll no to be searched44

Data is stored at4
Do you want to continue 1/0
*/
