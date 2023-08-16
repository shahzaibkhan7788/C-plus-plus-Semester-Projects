#include<iostream>
#include<string.h>
void Add_inventory(int a);
void Sell_inventory();
void Remove_inventory_item();
void Display_inventory();
void Display_stock_in_ruppess();
using namespace std;
struct inventry_item
{
string item_name;
int id;
int qty;
float price_per_item;
inventry_item *nptr;
};
inventry_item *fptr=NULL;
int main()
{
int option,sum=0;
while(1)
{
cout<<"Enter the option\n";
cout<<"1)Add inventory item\n2)Sell inventory item\n3)Remove inventory item\n4)Display all inventory\n";
cout<<"4)total stock display in ruppess\n";
cin>>option;
if(option==1)
{
Add_inventory(sum);
}
if(option==2)
{
Sell_inventory();
}
if(option==3)
{
Remove_inventory_item();
}
if(option==4)
{
 Display_inventory();
}
if(option==5)
{
Display_stock_in_ruppess();
}
}


return 0;
}
void Add_inventory(int sum)
{
cout<<"----------//-----------"<<endl;
cout<<"-------//-------------"<<endl;
inventry_item *ptr;
ptr=new inventry_item;
cout<<"Enter the name of the inventory item:";
cin>>ptr->item_name;
cout<<"Enter the id of the inventory item:";
cin>>ptr->id;
cout<<"Enter the quantity of the item:";
cin>>ptr->qty;
cout<<"Enter the price per item:";
cin>>ptr->price_per_item;
if(fptr==NULL)
{
ptr->nptr=NULL;
fptr=ptr;
}
else
{
inventry_item *currentptr=fptr;
while(currentptr->nptr!=NULL)
{
currentptr=currentptr->nptr;
}
ptr->nptr=NULL;
ptr->nptr=fptr;
fptr=ptr;
}
}
void Sell_inventory()
{
int ID,quantity,Cost,price,flag=1;
inventry_item *ptr=fptr;
cout<<"-------//-------------"<<endl;
cout<<"Enter the id of the inventory item:";
cin>>ID;
while(1)
{
if(ID==ptr->id)
{
cout<<"Enter the quantity of the inventory item to be sell:";
cin>>quantity;
if(quantity>ptr->qty)
{
cout<<"Your typed quantity is more than the available\n";
break;
}
cout<<"Enter the price per item:";
cin>>Cost;
if(Cost>ptr->price_per_item)
{
cout<<"TYour typed price is more than the original price\n";
}
else if(Cost<ptr->price_per_item)
{
cout<<"Your type price is less than the original price\n";
}
else
{
break;
}
break;
}
else
{
ptr=ptr->nptr;
if(ptr==NULL)
{
cout<<"Your type ID is invalid\n";
flag=0;
}
}
if(flag==0)
{
break;
}
}
}
void Remove_inventory_item()
{
char c[100];
int fix=0;
inventry_item* currentptr;
currentptr = fptr;
while (currentptr != NULL)
{
cout << "Enter Name OF Inventory Item You Want To Remove: ";
cin >> c;
cin.ignore();
if (strcmp(currentptr->item_name, c) == 0)
{
currentptr->qty = 0;
fix = 1;
}
if (fix == 0)
cout << "Inventory Not Found.\n";
fix=0;
}

}
void Display_inventory()
{
cout<<"----------//-----------"<<endl;
int ID1,flag=1;
inventry_item *ptr=fptr;
cout<<"This will display all the inventory items\n";
cout<<"Enter the id of the inventory item:";
cin>>ID1;
if(ptr==NULL)
{
cout<<"The list of items is empty\n";
}
else
{
while(1)
{
if(ID1==ptr->id)
{
cout<<"ID of the item is:"<<ptr->id<<endl;
cout<<"Name of the item is:"<<ptr->item_name<<endl;
cout<<"Price per item is:"<<ptr->price_per_item<<endl;
break;
}
else
{
ptr=ptr->nptr;
if(ptr==NULL)
{
flag==0;
}
}
if(flag==0)
{
break;
}
}
}
}
void Display_stock_in_ruppess()
{
cout<<"----------//-----------"<<endl;
inventry_item *newptr=fptr;
int sum=0,total_cost,newID,flag=1;
cout<<"This will display the total stock value of different items\n";
cout<<"Enter the ID of the item:";
cin>>newID;
if(newptr==NULL)
{
cout<<"The list of items is empty\n";
}
else
{
while(1)
{
if(newID==newptr->id)
{
total_cost=(newptr->price_per_item)*newptr->qty;
cout<<"Total price of "<<newptr->qty<<" "<<newptr->item_name<<" are:"<<total_cost<<endl;
break;
}
else
{
newptr=newptr->nptr;
if(newptr==NULL)
{
cout<<"The given ID is invalid\n";
flag==0;
}
}
if(flag==0)
{
cout<<"Invalid ID\n";
break;
}
}
}
}

