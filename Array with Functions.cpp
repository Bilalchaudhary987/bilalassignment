// Array with Functions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int const MaxSize = 20;
int i, x;

void Add(int List[], int &CSize, int MaxSize, int x)
{
	if(CSize < MaxSize)
	{
	    List[CSize] = x;
	    CSize++;
	}
	else
	{
		cout<<"Array is full" << endl;
	}
}

void Modify( int List[], int &CSize, int q, int Val, int Replace, int i)
{
	for(int i=0; i<CSize-1; i++)
		{
			cout<<List[i]<<"  ";
			
		}
   for(i=0; i<CSize; i++)
		{
			if( List[i] == Val)
			{
				q= 0;
				List[i]=Replace;
			}

       }
   if(q==-1)
		{
			cout<<"Value is modified"<<endl;
		}
		else
		{
			for(i=0; i<CSize; i++)
			{
				cout<<List[i]<<" ";
			}
		}
   for(int i=0; i<CSize-1; i++)
		{
			cout<<List[i]<<"  ";
			
		}
}
void Delete(int n, int num, int p, int List[], int i)
{
	
	for (i = 0; i < n; i++)
	{
        if (List[i] == num)
		{
            List[i] = List[i + 1];
            p = 1;
        } 

		else if (p > 0)
		{
            List[i] = List[i + 1];
        }
	}
    
	 for (i = 0; i < n-p ; i++) 
	{
        cout << List[i] << " ";
    }
	  for (i = 0; i < n-p ; i++) 
	{
        cout << List[i] << " ";
    }
	 cout<<endl;
}
void Insert(int a, int Index, int &CSize, int List[], int MaxSize, int i)
{
	if(CSize < MaxSize)
	{ 
		for(i=CSize; i>Index; i--)
	  {
		  List[i] = List[i-1];
	  }
	  List[Index] = a;
	  CSize++;
		
	}
	else
	{
		cout<<"Array is full" << endl;
	}

}
void Display(int List[], int &CSize, int i)
{
	for(int i=0; i<CSize; i++)
		{
			cout<<List[i]<<"  ";
			
		}
}
void Search(int key, int loc, int List[], int &CSize, int i)
{
	for(int i=0; i<CSize; i++)
	{
		if(List[i] == key)
			loc = i;
	}
	cout<<"Location of the Key is: "<<i<< endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int List[MaxSize] ={0};
	int CSize = 0;
	int i;
	char Choice='\0';
	do
{
	cout<<"Enter 'A' for Add: "<< endl;
	cout<<"Enter 'I' for Insert: "<< endl;
	cout<<"Enter 'E' for Exit: "<< endl;
	cout<<"Enter 'Q' for Display All: "<<endl;
	cout<<"Enter 'S' for Search: "<<endl;
	cout<<"Enter 'D' for Delete: "<<endl;
	cout<<"Enter 'M' for Modify: "<<endl;
	cout<<"Enter Choice: "<< endl;
	cin>> Choice;
	cout<<endl;

	switch(Choice)
{   // Add Operation
	case 'A':
	{
		int x;
	    cout<<"Enter a Number you want to Add: "<< endl;
	    cin>>x;
		Add(List, CSize, MaxSize, x);
	    
	}
	break;
	case 'M':
	{

		int Val, Replace,q=, i;
		cout<<"All Elements of Array are: ";
		Modify(List,  CSize,  q,  Val,  Replace,  i);
		cout<<endl;


		cout<<"Enter an Element you want to Modify: "<<endl;
		cin>>Val;
		Modify(List,  CSize,  q,  Val,  Replace,  i);

		cout<<"Enter Value to Replace: "<<endl;
		cin>>Replace;
		Modify(List,  CSize,  q,  Val,  Replace,  i);

		cout<<"Values After Replace: "<<endl;
		Modify( List, CSize,  q, Val,  Replace,  i);
	
		cout<<"New Array is: ";
		Modify( List,  CSize,  q,  Val,  Replace,  i);
	}
	break;

	// Delete Operation
	case 'D':
	{
		int n, num, p, i;
		cout << "Enter size of an array:";
		cin>>n;
		cout << "Enter element for delete:";
		cin>>num;
		Delete( n,  num,  p,  List, i);
		cout << "New array list is: "<<List[i];
		Delete( n,  num,  p,  List, i);
		cout<<endl;
	}
	break;

	// Insert Operation
	case 'I':
	{
	  int a, Index, i=0;
	  cout<<"Enter a Number You want to insert: "<< endl;
	  cin>>a;
	  cout<<"Enter the Index Number Where the Number is needed to be Insert(0<= 0< Current Size-1): "<< endl;
	  cin>> Index;
	  Insert( a,  Index, CSize,  List,  MaxSize, i);
	}
	break;
	case 'Q':
	{
		int i=0;
		cout<<"All Elements of Array are: ";
		Display(List, CSize, i);
		cout<<endl;
	}
	break;
	case 'S':
	{
		int key, loc, i=0;
		loc = -1;
		cout<<"Enter the Key: "<< endl;
		cin>> key;
		Search( key,  loc,  List,  CSize,  i);
		break;
	}
	case 'E':
	break;
	default:
     cout<< endl<<"Invalid Choice"<< endl;
	}
}
  while(Choice != 'E');



	return 0;
}

