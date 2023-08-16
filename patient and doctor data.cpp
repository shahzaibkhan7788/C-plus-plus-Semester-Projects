#include<iostream>
#include<ctime>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
class Doctor
{
public:
string Name;
int Room_No;
string specialization;
int date;
int month;
int year;
char Assigned_duty[50];
string ID;
};


class patient_data
{
public:
string F_Name;
string L_Name;
string id;
string Date_of_birth[50];
string checkup_date[60];
char purpose_of_checkup[50];
string appointment_date[50];
string doctor[50];
int date;
string month;
int year;

};

int main()
{

Doctor obj[3];
for(int i=0;i<3;i++)
{
cout<<setw(50)<<"DATA of DOCTOR:"<<endl<<endl;
cout<<"Enter the Name of the doctor:";
cin>>obj[i].Name;
cout<<"Enter specialization of the doctor:";
cin>>obj[i].specialization;
cout<<"Enter the duty:";
cin>>obj[i].Assigned_duty;
cout<<"Enter the Room number:";
cin>>obj[i].Room_No;
cout<<"Enter ID of doctor:";
cin>>obj[i].ID;
cout<<"Enter Assigned duty:";
cin>>obj[i].Assigned_duty;
cout<<"enter date of joining:";
cin>>obj[i].date;
cout<<"Enter the month:";
cin>>obj[i].month;
cout<<"Enter the year:";
cin>>obj[i].year;
cout<<"Date of joining:"<<obj[i].date<<"-"<<obj[i].month<<"-"<<obj[i].year<<endl;
cout<<setw(30)<<"`````````````````````````````````";
cout<<endl<<endl;

}
patient_data obj1;
{

cout<<"Enter First name of the patient:";
cin>>obj1.F_Name;
cout<<"Last Name of patient:";
cin>>obj1.L_Name;
cout<<"Enter ID:";
cin>>obj1.id;
cout<<setw(20)<<"Enter date of birth of patient:";
cout<<"Enter date:";
cin>>obj1.date;
cout<<"Enter month:";
cin>>obj1.month;
cout<<"Enter year:";
cin>>obj1.year;
cout<<"Date of birth of patient:"<<obj1.date<<"-"<<obj1.month<<"-"<<obj1.year<<endl;
cout<<setw(20)<<"Enter checkup date of patient:"<<endl;
cout<<"Enter date:";
cin>>obj1.date;
cout<<"Enter month:";
cin>>obj1.month;
cout<<"Enter year:";
cin>>obj1.year;
cout<<"checkup date of patient:"<<obj1.date<<"-"<<obj1.month<<"-"<<obj1.year<<endl;
cout<<"Enter purpose of checkup:";
cin>>obj1.purpose_of_checkup;

}
bool flag=false;
for(int i=0;i<3;i++)
{
if(strcmp(obj[i].Assigned_duty,obj1.purpose_of_checkup)==0)
{
if(i==0)
{
obj1.date+=4;
obj1.month+=3;
obj1.year+=0;
cout<<"Name of the patient"<<obj1.F_Name<<" "<<obj1.L_Name<<endl;
cout<<"ID of the patient:"<<obj1.id<<endl;
cout<<"Date of Birth:"<<obj1.date<<"-"<<obj1.month<<"-"<<obj1.year<<endl;
cout<<"Purpose of checkup:"<<obj[i].Assigned_duty<<endl;
cout<<"Doctor Assigned:"<<obj[i].Name<<endl;
cout<<"Room No of doctor:"<<obj[i].Room_No<<endl;
cout<<"Next expected appointment date:"<<obj1.date<<"-"<<obj1.month<<"-"<<obj1.year<<endl;
}
else if(i==1)
{

obj1.date+=5;
obj1.month+=1;
obj1.year+=0;
cout<<"Name of the patient"<<obj1.F_Name<<" "<<obj1.L_Name<<endl;
cout<<"ID of the patient:"<<obj1.id<<endl;
cout<<"Date of Birth:"<<obj1.date<<"-"<<obj1.month<<"-"<<obj1.year<<endl;
cout<<"Purpose of checkup:"<<obj[i].Assigned_duty<<endl;
cout<<"Doctor Assigned:"<<obj[i].Name<<endl;
cout<<"Room No of doctor:"<<obj[i].Room_No<<endl;
cout<<"Next expected appointment date:"<<obj1.date<<"-"<<obj1.month<<"-"<<obj1.year<<endl;
}
else
{
obj1.date+=2;
obj1.month+=1;
obj1.year+=0;
cout<<"Name of the patient"<<obj1.F_Name<<" "<<obj1.L_Name<<endl;
cout<<"ID of the patient:"<<obj1.id<<endl;
cout<<"Date of Birth:"<<obj1.date<<"-"<<obj1.month<<"-"<<obj1.year<<endl;
cout<<"Purpose of checkup:"<<obj[i].Assigned_duty<<endl;
cout<<"Doctor Assigned:"<<obj[i].Name<<endl;
cout<<"Room No of doctor:"<<obj[i].Room_No<<endl;
cout<<"Next expected appointment date:"<<obj1.date<<"-"<<obj1.month<<"-"<<obj1.year<<endl;
}

}

}


return 0;
}


