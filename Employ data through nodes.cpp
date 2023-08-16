#include<string>
void employee_data1();
void database();
void Netpay_of_employer();
void showentire_database();
using namespace std;
struct employee_data
{
int employee_id;
string employe_name;
string phone_No;
int Basic_Salary;
employee_data *nptr;
};
 employee_data *fptr=NULL;
int main()
{
int option;
for(;;)
{
cout<<"Select one of the option\n";
cout<<"1)Enter the employee data\n";
cout<<"2)Check the existance of employee in a database\n";
cout<<"3)Compute the allowance and net pay of the employer\n";
cout<<"4)Show entire database\n";
cin>>option;
if(option==1)
{
employee_data1();
}
if(option==2)
{
database();
}
if(option==3)
{
Netpay_of_employer();
}
if(option==4)
{
showentire_database();
}


}//end of the while loop;

return 0;
}
void employee_data1()
{
cout<<"--------//-------"<<endl;
employee_data *ptr;
ptr=new employee_data;
cout<<"Enter the id of the employer\n";
cin>>ptr->employee_id;
cout<<"Enter the name of the employer\n";
cin>>ptr->employe_name;
cout<<"Enter the phone number of the employer\n";
cin>>ptr->phone_No;
cout<<"Enter the basic pay of the employer\n";
cin>>ptr->Basic_Salary;
if(fptr==NULL)
{
ptr->nptr=NULL;
fptr=ptr;
}
else
{
employee_data *currentptr=fptr;
while(currentptr->nptr!=NULL)
{
currentptr=currentptr->nptr;
}
ptr->nptr=NULL;

}

}

void database()
{
cout<<"--------//-------"<<endl;
int ID;
employee_data *newptr=fptr;
cout<<"This will check the existance of the employer in database\n";
cout<<"Enter the id of the employer\n";
cin>>ID;
if(ID==newptr->employee_id)
{
cout<<"Yes the data of the given id is stored in database\n";
}
else
{
cout<<"Your ID is not mention in the database\n";
}
}


void Netpay_of_employer()
{
cout<<"--------//-------"<<endl;
employee_data *anptr=fptr;
int newID;
float sum;
float rent_house,medical_allowance,conveyance_allowance,Net_pay;
cout<<"This will calculate the net pay of the employer\n";
cout<<"Enter the id of the employer\n";
cin>>newID;
if(newID==anptr->employee_id)
{
rent_house=0.45*(anptr->Basic_Salary);
medical_allowance=0.05*(anptr->Basic_Salary);
conveyance_allowance=0.1*(anptr->Basic_Salary);
sum=(rent_house)+(medical_allowance)+(medical_allowance);
Net_pay=(anptr->Basic_Salary)*2;
cout<<"Basic pay of the employer is:"<<anptr->Basic_Salary<<endl;
cout<<"House rent:"<<rent_house<<endl;
cout<<"Medical allownace:"<<medical_allowance<<endl;
cout<<"Coneyance allowance:"<<conveyance_allowance<<endl;
cout<<"Net pay:"<<Net_pay<<endl;
}

}

void showentire_database()
{
cout<<"--------//-------"<<endl;
employee_data *canptr=fptr;
int ID1;
int newID;
float sum;
float rent_house,medical_allowance,conveyance_allowance,Net_pay;
cout<<"Enter the ID of the employer:";
cin>>ID1;
if(ID1==canptr->employee_id)
{
rent_house=0.45* canptr->Basic_Salary;
medical_allowance=0.05* canptr->Basic_Salary;
conveyance_allowance=0.1* canptr->Basic_Salary;
sum=rent_house+medical_allowance+medical_allowance;
Net_pay=(canptr->Basic_Salary)-sum;
cout<<"Name of the employer:"<<canptr-> employe_name<<endl;
cout<<"Phone number of the employer:"<<canptr->phone_No<<endl;
cout<<"Basic pay of the employer is:"<<canptr->Basic_Salary<<endl;
cout<<"House rent:"<<rent_house<<endl;
cout<<"Medical allownace:"<<medical_allowance<<endl;
cout<<"Coneyance allowance:"<<conveyance_allowance<<endl;
cout<<"Net pay:"<<Net_pay<<endl;
}


}


