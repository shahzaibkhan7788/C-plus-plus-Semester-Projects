#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<ctime>
void Vehicle_Entry();
void Vehicle_Fee();
void Vehicle_exit();
void Vehicl_Statistic();
void exit_function();
void reading_file();
using namespace std;
struct parking_management
{
int vehicle_reg;
string driver_name;
string vehicle_model;
string vehicle_make;
string vehicle_color;
int vehicle_entry_time;
 parking_management *nptr;
};
 parking_management *fptr=NULL;
float total=0.0;
time_t entrance,ex;

fstream myfile;

int main()
{
int option;
while(1)
{
cout<<"Enter the option\n";
cout<<"1)Vehicle_Entry\n2)Vehicle_Exit\n3)Vehicle_Fee\n4)Vehicl_Statistic\n5)press 5 to write content inside the file\n";
cout<<"6)press 6 to read from the file\n\n";
cin>>option;
if(option==1)
{
Vehicle_Entry();
}
if(option==2)
{
Vehicle_exit();
}
if(option==3)
{
Vehicle_Fee();
}

if(option==4)
{
Vehicl_Statistic();
}
if(option==5)
{
exit_function();
}
if(option==6)
{
reading_file();
}
}


}
void Vehicle_Entry()
{
 parking_management *ptr=fptr;
ptr=new parking_management;
cout<<"Enter the vehicle registration:";
cin>>ptr->vehicle_reg;
cout<<"name of the driver:";
cin>>ptr->driver_name;
cout<<"vehicle make:";
cin>>ptr->vehicle_make;
cout<<"vehicle model:";
cin>>ptr->vehicle_model;
cout<<"Enter color:";
cin>>ptr->vehicle_color;
time(&entrance);
char *ch=ctime(&entrance);
cout<<"Enter proper time of the vehicle with data:"<<ch<<endl;
if(fptr==NULL)
{
ptr->nptr=NULL;
fptr=ptr;
}
else
{
parking_management *currentptr=fptr;
while(currentptr->nptr!=NULL)
{
currentptr=currentptr->nptr;
}
ptr->nptr=NULL;
currentptr->nptr=ptr;
}
total=total+70;
}

void Vehicle_exit()
{
int rgrt,flag=0,difference;
parking_management *deleptr, *currentptr=fptr;
cout<<"enter the registration of the car:";
cin>>rgrt;
if(rgrt==currentptr->vehicle_reg)
{
time(&ex);
char *ch=ctime(&ex);
cout<<"exit time of the car with fixed data:"<<ch<<endl;
difference=difftime(entrance,ex);
}
if(difference<60)
{
total=total+50.0;
cout<<"parking charges are 50 ruppess from registration number:"<<rgrt<<endl;
deleptr=fptr;
fptr=currentptr->nptr;
flag=1;
delete deleptr;
}
else
{
total=total+70.0;
cout<<"parking charges are 70 ruppess from registration number:"<<rgrt<<endl;
deleptr=fptr;
fptr=currentptr->nptr;
flag=1;
delete deleptr;
}
if(flag==0)
{
cout<<"No car founded in the park\n";
}
cout<<endl;
}

void Vehicle_Fee()
{
cout<<"Total fee collected:"<<total<<endl;
cout<<endl;
}
void Vehicl_Statistic()
{
cout<<"-----------///--------"<<endl;
int index=1;
 parking_management *ptr=fptr;

if(ptr==NULL)
{
cout<<"List is empty\n\n";

}
else
{
while(ptr!=NULL)
{
cout<<"Registration number of the car is:"<<ptr->vehicle_reg<<endl;
cout<<"Name of the driver:"<<ptr->driver_name<<endl;
cout<<"Vehicle make:"<<ptr->vehicle_make<<endl;
cout<<"Vehicle model:"<<ptr->vehicle_model<<endl;
cout<<"Vehicle color:"<<ptr->vehicle_color<<endl;
index++;
ptr=ptr->nptr;
cout<<endl;
}
}

}

void exit_function()
{
myfile.open("parking_data1.txt",ios::out|ios::app);

parking_management *ptr=fptr;

if(!myfile)
{
cout<<setw(30)<<"File is not created yet\n";
}
else
{
cout<<"WRITING INSIDE THE FILE\n\n";
while(ptr!=NULL)
{
myfile<<ptr->vehicle_reg<<endl;
myfile<<ptr->driver_name<<endl;
myfile<<ptr->vehicle_make<<endl;
myfile<<ptr->vehicle_model<<endl;
myfile<<ptr->vehicle_color<<endl<<endl;
ptr=ptr->nptr;
}
}
myfile.close();
}
void reading_file()
{
parking_management *ptr=fptr;
string ch;
myfile.open("parking_data1.txt",ios::in);
if(!myfile)
{
cout<<"File is not created yet\n\n";
}
else
{
cout<<endl<<endl;
cout<<setw(30)<<"READING FROM THE FILE\n\n";
while(!myfile.eof())
{
getline(myfile,ch);
cout<<ch<<endl;
}
}
myfile.close();
}




 
 
 

