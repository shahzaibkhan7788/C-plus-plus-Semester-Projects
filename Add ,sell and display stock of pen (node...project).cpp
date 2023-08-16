#include<iostream>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;
struct node
{
int data;
node *nptr;
};
node *fptr=NULL;
int main()
{
node *ptr;
int n,option,i,j,k,g,h,index=1,value,count=1,flag=0,total;
for(;;)
{
cout<<"Enter the option of the given list\n";
cout<<"1)Add Data\n2)Find data\n3)Display Data\n4)Press 4 to Exit\n";
cin>>option;
if(option==1)
{
/*
cout<<"Enter the number of nodes\n";
cin>>n;*/
ptr=new node;
cout<<"Enter the data of the node#"<<":";
cin>>ptr->data;
if(fptr==NULL)
{
ptr->nptr=NULL;
fptr=ptr;
}
else
{
node *currentptr=fptr;
while(currentptr->nptr!=NULL)
{
currentptr=currentptr->nptr;
}
ptr->nptr=fptr;
fptr=ptr;
}
}

if(option==2)
{
node *newptr=fptr;
cout<<"Enter the searching value\n";
cin>>value;
while(newptr!=NULL)
{
if(newptr->data==value)
{
flag=1;
break;
}
newptr=newptr->nptr;
count++;
if(flag==1)
{
total=count;
}
}
if(flag==1)
{
cout<<"value found at node#"<<total<<" and its value is:"<<newptr->data<<endl;
}
else
{
cout<<"Value is not founded\n";
}
}
if(option==3)
{
cout<<"This will display all data of the students\n";
node *currentptr=fptr;
if(fptr==NULL)
{
cout<<"Link list is empty\n";
}
else
{
while(currentptr!=NULL)
{
cout<<"value at node#"<<index<<" is#:"<<currentptr->data<<endl;
currentptr=currentptr->nptr;
index++;
}
}
if(option==4)
{
break;
}
}


}

return 0;
}

