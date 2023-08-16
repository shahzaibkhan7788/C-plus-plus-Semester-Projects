
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
void student_data();
void faculty_data();
void updated_Attendance();
void uploaded_marks();
void faculty_password();
void student_password();
void semester_fee();
using namespace std;
int k;
int m;
int l;
int fee;
class set_password
{
public:
string Name;
int password;
set_password *nptr;
};
set_password *nfptr=NULL;


class spassword:public set_password
{
public:
spassword *nptr;
};
spassword *stfptr=NULL;

class Faculty:public spassword
{
public:
string ID;
int Registration;
int  age ;
string course_name;
Faculty *nptr;
string phone_No;
int semester;
string Email_Address;
string date;
string CNIC;
string batch;
string log_in_ID;
int Attendance[];
float terminal_marks;
float project_marks[];
float quiz_marks[];
float sessional_marks[];
float Assignment_marks[];
float obtain_marks;
float total_marks;
float sum;
void set_data();
void Assigned_courses();
void check_Enrolled_courses();
};
Faculty *f_fptr=NULL;

class student:public Faculty
{
public:
void Updated_Attendence();
void Uploaded_marks();
student *nptr;
};
student *s_fptr=NULL;

class Admin:public student
{
public:
string professor;
string course_title;
int credit_hour;
int code;
Admin *nptr;
string season;
void Admin_data();
void Add_courses();
void Add_faculty();
void Add_student();
void Enroll_courses();
void set_data()
{
cout<<setw(15)<<"Enter log in ID:";
cin>>ID;
cout<<setw(15)<<"Enter Registration Number:";
cin>>Registration;
cout<<setw(15)<<"Enter age:";
cin>>age;
cout<<setw(15)<<"Enter Phone Number:";
cin>>phone_No;
cout<<setw(15)<<"Enter Identity card:";
cin>>CNIC;
cout<<setw(15)<<"Enter Email Address:";
cin>>Email_Address;
}
};
string A_password="1234";
string A_ID="bscs22";
Admin  *A_fptr=NULL;

class course:public Admin
{
public:
course *nptr;
void semester_Enrolment();
};
course *Ad_fptr=NULL;

class course_enrollment:public course
{
public:
string course_name;
course_enrollment *nptr;
};
 course_enrollment *Co_fptr=NULL;

class Attendance:public course_enrollment
{
public:
string name;
void mark_Attendance();
Attendance *nptr;
};
Attendance *Afptr=NULL;

class marks:public Attendance
{
public:
float sum1;
float sum2;
float sum3;
float sum4;
marks *nptr;
void upload_marks();
};
marks *ufptr=NULL;

int main()
{
  Admin A;
  int n;
cout<<"WELCOME TO SRA PORTAL OF PIEAS UNIVERSTY:\n\n";
while(1)
{
 cout<<setw(50)<<"Introduce yourself\n";
  cout<<"press 1 for Administration:\n";
  cout<<"press 2 for Faculty:\n";
  cout<<"press 3 for Student:\n\n";
  cin>>n;
switch(n)
{
case 1:
      A.Admin_data();
       break;
case 2:
      faculty_data();
	   break;
case 3:
       student_data();
        break;
default:
       cout<<setw(30)<<"Wrong input\n";
        break;
}
}
return 0;
}

void Admin::Admin_data()
{
  Admin A;
  course B;
string password;
string Log;
int count=3;
int option;
int flag=0;
while(count!=0)
{
cout<<"Enter password:";
cin>>password;
cout<<"Enter Log In ID:";
cin>>Log;
if(password==A_password && Log==A_ID)
{
cout<<endl;
cout<<setw(15)<<"WELCOME!HAVE A NICE DAY";
cout<<endl<<endl;
cout<<"press 1 to Add student:\n";
cout<<"press 2 to Add faculty member\n";
cout<<"press 3 to Add semester \n";
cout<<"press 4 to add courses:\n";
cout<<"press 5 to Allow student to enroll the courses\n";
cout<<"press 6 to return main menu\n";
cin>>option;
switch(option)
{
case 1:
        A.Add_student();
	break;
case 2:
        A.Add_faculty();
	break;
case 3:
        B.semester_Enrolment();
	break;
case 4:
        A.Add_courses();
	break;

case 5:
        A.Enroll_courses();
	break;
case 6:
        flag=1;
        break;
default:
        cout<<"Wrong input\n";
}
if(option>=1 && option<=5)
{
break;
}
if(flag==1)
{
flag=1;
break;
}
}

count--;
if(count>=1)
{
cout<<endl;
cout<<"you have left "<<count<<" chance.try again"<<endl;
}
else
{
cout<<endl;
cout<<"You have lost three chances\n\n";
}
}

}

void faculty_data()
{
set_password *ptr=nfptr;
int pass;
int flag=0;
int n;
marks A;

cout<<"Enter password:";
cin>>pass;
while(ptr!=NULL)
{
if(pass==ptr->password)
{
flag=1;
cout<<"You have successfully Enter the password:\n";
break;
}
ptr=ptr->nptr;
if(ptr==NULL)
{
cout<<"Wrong password...ntry again\n";
break;
}
cout<<"--------------------\\\\-----------------------"<<endl;
}

if(flag==1)
{
cout<<"WELCOME!HAVE A NICE DAY\n\n";
cout<<setw(15)<<"press 1 to to see the Add courses\n";
cout<<setw(15)<<"press 2 to see the student enrolled courses\n";
cout<<setw(15)<<"press 3 to to mark Attendence\n";
cout<<setw(15)<<"press 4 to mark quiz,Assignment and sessionals\n";
cin>>n;
switch(n)
{
case 1:
       A.Assigned_courses();
      break;
case 2:
       A.check_Enrolled_courses();
      break;
case 3:
       A.mark_Attendance();
      break;
case 4:
       A.upload_marks();
      break;
default:
       cout<<"Wrong input\n";

}
}
}

void student_data()
{
spassword *ptr=stfptr;
int n;
int flag=0;
student A;
int pass;
cout<<"Enter password:";
cin>>pass;
while(ptr!=NULL)
{
if(pass==ptr->password)
{
flag=1;
cout<<"You have successfully enter the password:\n";
break;
}
ptr=ptr->nptr;
if(ptr==NULL)
{
cout<<"Wrong password...ntry again\n";
break;
}
}
if(flag==1)
{
cout<<"WELCOME!HAVE A NICE DAY\n\n";
cout<<"press 1 to to see the updated attendence\n";
cout<<"press 2 to see the uploaded marks\n";
cout<<"press 3 to see the semester fee\n";
cin>>n;
switch(n)
{
case 1:
      updated_Attendance();
      break;
case 2:
       uploaded_marks();
      break;
case 3:
       semester_fee();
       break;
default:
       cout<<"Wrong input\n";

}
}
cout<<"------------------------\\\---------------------------"<<endl;
}

void Admin::Add_faculty()
{
Admin B;
faculty_password();
B.set_data();
cout<<"-----------------------\\\-----------------"<<endl;
}

void Admin::Add_student()
{
Admin A;
student_password();
A.set_data();
cout<<"-----------------------\\\---------------------"<<endl;
}

void course::semester_Enrolment()
{
course *ptr;
ptr=new course;
int count=3;
cout<<"Type one of the season:\nspring_2023\nfall_2023\n";

string B="spring_2023";
string C="fall_2023";

cout<<"Enter the season offering:";
	cin>>season;
	if(season==C)
	{

            cout<<"Offered semester in fall season 2023:\n\n";
            cout<<setw(30)<<"2 for second semester\n";
	   cout<<setw(30)<<"4 for fourth semester\n";
	   cout<<setw(30)<<"6 for sixth semester\n";
	   cout<<setw(30)<<"8 for eight semester\n";
	   cout<<"Enter the Semester:";
		cin>>ptr->semester;
			if(ptr->semester==2)
		{
		 cout<<setw(30)<<"SECOND FALL SEMESTER 2023\n";
		 cout<<"Semester Added successfully\n";
		}
	       if(ptr->semester==4)
              {
	        cout<<setw(30)<<"FOURTH FALL SEMESTER 2023\n";
	       	 cout<<"Semester Added successfully\n";
              }
	     if(ptr->semester==6)
              {
	         cout<<setw(30)<<"SIXTH FALL SEMESTER  2023\n";
	            cout<<"Semester Added successfully\n";
              }
	    if(ptr->semester==8)
             {
	         cout<<setw(30)<<"EIGHT FALL SEMESTER 2023\n";
	      	 cout<<"Semester Added successfully\n";
             }
	  if(Ad_fptr==NULL)
{
ptr->nptr=NULL;
Ad_fptr=ptr;
}
else
{
course *currentptr=Ad_fptr;
while(currentptr->nptr!=NULL)
{
currentptr=currentptr->nptr;
}
currentptr->nptr=ptr;
ptr->nptr=NULL;
}

	}
	 	else if(season==B)
         {

cout<<"Offered semester in spring season 2023:\n\n";
                  cout<<setw(30)<<"1 for First semester\n";
		cout<<setw(30)<<"3 for Third semester\n";
		cout<<setw(30)<<"5 for Fifth semester\n";
		cout<<setw(30)<<" 7 for Seventh semester\n";
		cout<<"Enter Semester:\n";
		cin>>ptr->semester;
cout<<endl;
		if(ptr->semester==1)
		{
                    cout<<setw(30)<<"FIRST SPRING SEMESTER 2023\n\n";
		 cout<<"Semester Added successfully\n";
		}

		if(ptr->semester==3)
                  {
		  cout<<"THIRD SPRING SEMESTER 2023\n";
	       	 cout<<"Semester Added successfully\n";
                  }
		 if(ptr->semester==5)
                  {
                  cout<<"FIFTH SPRING SEMESTER 2023\n";
	        	 cout<<"Semester Added successfully\n";
                  }
	        if(ptr->semester==7)
                 {
		   cout<<"SEVENTH  SPRING SEMESTER 2023\n";
	               	 cout<<"Semester Added successfully\n";
	        }

if(Ad_fptr==NULL)
{
ptr->nptr=NULL;
Ad_fptr=ptr;
}
else
{
course *currentptr=Ad_fptr;
while(currentptr->nptr!=NULL)
{
currentptr=currentptr->nptr;
}
currentptr->nptr=ptr;
ptr->nptr=NULL;
}

         }
cout<<"-------------------------------\\\\\------------------------------"<<endl;
}

void Admin::Add_courses()
{
int flag=0;
int n;
course *currentptr=Ad_fptr;
Admin *ptr;
cout<<"Enter the semester:";
cin>>n;
while(currentptr!=NULL)
{
if(n==currentptr->semester)
{
flag=1;
cout<<endl;
break;
}
currentptr=currentptr->nptr;
if(currentptr==NULL)
{
cout<<"This semester is not added yet\n";
break;
}
}
if(flag==1)
{
cout<<"Add the Number of courses\n";
cin>>k;
for(int i=0;i<k;i++)
{
ptr=new Admin;
ptr->semester=n;
cout<<"Enter course title:";
cin>>ptr->course_title;
cout<<"Assign Faculty member:";
cin>>ptr->professor;
cout<<"course Code:";
cin>>ptr->code;
cout<<" Course Credit hour:";
cin>>ptr->credit_hour;
if(A_fptr==NULL)
{
ptr->nptr=NULL;
A_fptr=ptr;
}
else
{
Admin *currentptr=A_fptr;
while(currentptr->nptr!=NULL)
{
currentptr=currentptr->nptr;
}
currentptr->nptr=ptr;
ptr->nptr=NULL;
}
cout<<endl;
}

cout<<endl<<endl;
cout<<"You have successfully enrolled courses in semester:"<<ptr->semester<<endl;
Admin *currentptr=A_fptr;
if(A_fptr==NULL)
{
cout<<"Link list is empty\n";
}
else
{
cout<<"Course Title:         professor:"<<endl;
for(int i=0;i<k;i++)
{
cout<<currentptr->course_title<<"               "<<currentptr->professor<<endl;
currentptr=currentptr->nptr;
}
}
}
if(flag==0)
{
cout<<"Semester is not Added yet\n";
}
cout<<"----------------------------\\\\---------------------------"<<endl;
}


void marks::upload_marks()
{
course_enrollment *newptr=Co_fptr;
marks *ptr;
ptr=new marks;
string course;
int flag=0;
int credit_hour;
int n,a,b,c,d;
int t_sessional=20;
int t_terminal=50;
int t_quiz=10;
int t_Assignment=10;
int t_project=10;
cout<<endl;
cout<<"Enter course Name:";
cin>>course;
cout<<"credit hour of the course:";
cin>>credit_hour;
while(newptr!=NULL)
{
if(course==newptr->course_name)
{
cout<<"You are now Allow to enter the marks of:"<<course;
flag=1;
break;
}
newptr=newptr->nptr;
if(newptr==NULL)
{
break;
}
}
if(flag==1)
{
cout<<endl<<endl;
cout<<"Enter number of quiz:";
cin>>a;
cout<<"Enter number of Assignment:";
cin>>b;
cout<<"Enter number of project:";
cin>>c;
cout<<"Enter number of sessionals:";//
cin>>d;

cout<<endl;
for(int j=0;j<c;j++)
{
cout<<"Enter project "<<j+1<<" marks out of 10:";
cin>>ptr->project_marks[j];
ptr->sum1=ptr->sum1+ptr->project_marks[j];
}
cout<<endl;
for(int j=0;j<b;j++)
{
cout<<"Enter Assignment "<<j+1<<" marks out of 10:";
cin>>ptr->Assignment_marks[j];
ptr->sum2=ptr->sum2+ptr->Assignment_marks[j];
}
cout<<endl;
for(int j=0;j<a;j++)
{
cout<<"Enter Quiz "<<j+1<<" marks out of 10:";
cin>>ptr->quiz_marks[j];
ptr->sum3=ptr->sum3+ptr->quiz_marks[j];
}
sessional_marks[0]=0;
for(int j=0;j<d;j++)
{
cout<<"Enter sessional:"<<j+1<<"marks out of 20:";
cin>>ptr->sessional_marks[j];
ptr->sum4=ptr->sum4+ptr->sessional_marks[j];
}
cout<<endl;
cout<<"Terminal marks out of 50:";
cin>>ptr->terminal_marks;

ptr->total_marks=a*t_quiz+b*t_Assignment+c*t_project+d*t_sessional+t_terminal;
ptr->sum=ptr->sum4+ptr->sum1+ptr->terminal_marks+ptr->sum2+ptr->sum3;//obtain marks...
if(credit_hour==3)
{
ptr->obtain_marks=((ptr->sum)/ptr->total_marks)*0.75;//  since it is three credit hour course so it has 12 points out of 64 points...so 0.75
}                                            //is the park of one subject....
if(credit_hour==2)
{
ptr->obtain_marks=((ptr->sum)/ptr->total_marks)*0.58;//  since it is three credit hour course so it has 12 points out of 64 points...so 0.75
}
if(ufptr==NULL)
{
ptr->nptr=NULL;
ufptr=ptr;
}
else
{
    marks *currentptr=ufptr;
while(currentptr!=NULL)
{
currentptr=currentptr->nptr;
}
currentptr->nptr=ptr;
ptr->nptr=NULL;
}
marks *secptr=ufptr;

while(secptr!=NULL)
{
cout<<setw(30)<<"WEIGHTAGE AND GPA OF COURSE:"<<course<<endl;
cout<<fixed;
cout<<endl<<endl;
if(credit_hour==3)
{
cout<<"TOTAL GPA OF TWO CREDIT HOUR COURSE IS 0.75"<<endl<<end;
secptr->sum2=(secptr->sum2/secptr->sum)*0.75;
secptr->sum2=secptr->sum2;
cout<<"Obtain Assignment weightage:"<<secptr->sum2<<endl;
secptr->sum3=(secptr->sum3/secptr->sum)*0.75;
secptr->sum3=secptr->sum3;
cout<<"Obtain Quiz weightage:"<<secptr->sum3<<endl;
secptr->sum1=(secptr->sum1/secptr->sum)*0.75;
secptr->sum1=secptr->sum1;
cout<<"Obtain project weightage:"<<secptr->sum1<<endl;
secptr->sum4=(secptr->sum4/secptr->sum)*0.75;
secptr->sum4=secptr->sum4;
cout<<"Obtain sessional weightage:"<<secptr->sum4<<endl;
secptr->terminal_marks=(secptr->terminal_marks/secptr->sum)*0.75;
secptr->terminal_marks=secptr->terminal_marks;
cout<<"Obtain terminal weightage:"<<secptr->terminal_marks<<endl;
cout<<"GPA obtain in one course:"<<secptr->obtain_marks;
secptr->obtain_marks=secptr->obtain_marks;
secptr=secptr->nptr;
}
if(credit_hour==2)
{
cout<<"TOTAL GPA OF TWO CREDIT HOUR COURSE IS 0.58"<<endl<<end;
secptr->sum2=(secptr->sum2/secptr->sum)*0.58;
secptr->sum2=secptr->sum2;
cout<<"Obtain Assignment weightage:"<<secptr->sum2<<endl;
secptr->sum3=(secptr->sum3/secptr->sum)*0.58;
secptr->sum3=secptr->sum3;
cout<<"Obtain Quiz weightage:"<<secptr->sum3<<endl;
secptr->sum1=(secptr->sum1/secptr->sum)*0.58;
secptr->sum1=secptr->sum1;
cout<<"Obtain project weightage:"<<secptr->sum1<<endl;
secptr->sum4=(secptr->sum4/secptr->sum)*0.58;
secptr->sum4=secptr->sum4;
cout<<"Obtain sessional weightage:"<<secptr->sum4<<endl;
secptr->terminal_marks=(secptr->terminal_marks/secptr->sum)*0.58;
secptr->terminal_marks=secptr->terminal_marks;
cout<<"Obtain terminal weightage:"<<secptr->terminal_marks<<endl;
cout<<"GPA obtain in one course:"<<secptr->obtain_marks;
secptr->obtain_marks=secptr->obtain_marks;
secptr=secptr->nptr;
}
}
}
else
{
cout<<"Sorry!This course is not enrolled ny the student:\n\n";
}
cout<<endl;
cout<<"------------------------------\\\\\\--------------------------"<<endl;
}


void Admin::Enroll_courses()
{
int flag=0;
int n;
fee=0;
course_enrollment *ptr;
Admin *currentptr=A_fptr;
cout<<"Enter the semester:";
cin>>n;
while(currentptr!=NULL)
{
if(n==currentptr->semester)
{
flag=1;
cout<<setw(30)<<"Please enroll courses courses in semester:"<<n<<endl<<endl;
break;
}
currentptr=currentptr->nptr;
if(currentptr==NULL)
{
cout<<"Sorry!No course is Added in this semester\n";
break;
}
}
if(flag==1)
{
cout<<"Course Title:     professor:"<<endl;
for(int i=0;i<k;i++)
{
cout<<currentptr->course_title<<"               "<<currentptr->professor<<endl;
currentptr=currentptr->nptr;
}
}
cout<<"Enroll the courses in semester:"<<n<<endl<<endl;
cout<<setw(30)<<"Enter Number of courses:";
cin>>m;
for(int i=0;i<m;i++)
{
fee=fee+8000;
ptr=new course_enrollment;
cout<<setw(30)<<"Name of course:";
cin>>ptr->course_name;
if(Co_fptr==NULL)
{
ptr->nptr=NULL;
Co_fptr=ptr;
}
else
{
 course_enrollment *travptr=Co_fptr;
while(travptr->nptr!=NULL)
{
travptr=travptr->nptr;
}
travptr->nptr=ptr;
ptr->nptr=NULL;
}
ptr->semester=n;
}
cout<<"-----------------------------\\\\---------------------"<<endl;
}

void semester_fee()
{
if(Co_fptr==NULL)
{
cout<<"You have not enrolled courses yet\n";
}
else
{
cout<<"Total semester fee of "<<m<< " subjects are:"<<fee<<endl<<endl;
}
}

void Faculty::Assigned_courses()
{
Admin *currentptr=A_fptr;
int n;
int flag=0;
cout<<"Enter semester:";
cin>>n;
while(currentptr!=NULL)
{
if(n==currentptr->semester)
{
flag=1;
break;
}
currentptr=currentptr->nptr;
if(currentptr==NULL)
{
cout<<"No course is Enrolled in semester:"<<n<<endl;
break;
}
}
if(flag==1)
{
cout<<"The following are the enrolled courses in semester:"<<n<<endl<<endl;
cout<<"Course Title:         professor:"<<endl;
for(int i=0;i<k;i++)
{
cout<<setw(30)<<currentptr->course_title<<"               "<<currentptr->professor<<endl;
currentptr=currentptr->nptr;
}
}
cout<<"------------------------\\\\------------------"<<endl;
}

void Faculty::check_Enrolled_courses()
{
course_enrollment *currentptr=Co_fptr;
int n;
int flag=0;
cout<<"Enter semester:";
cin>>n;
while(currentptr!=NULL)
{
if(n==currentptr->semester)
{
flag=1;
break;
}
currentptr=currentptr->nptr;
if(currentptr==NULL)
{
cout<<"No course is Enroll in semester:"<<n<<endl;
break;
}
}
if(flag==1)
{
cout<<"The following are the enrolled courses by the student\n\n";
for(int i=0;i<m;i++)
{
cout<<setw(30)<<"Course Name:"<<currentptr->course_name<<endl;
currentptr=currentptr->nptr;
}
}
cout<<"------------------------\\\\-----------------"<<endl;
}

void Attendance::mark_Attendance()
{
int flag=0;
int falg=0;
int n;

course_enrollment *currentptr=Co_fptr;
spassword *newptr=stfptr;
Attendance *ptr;
string sname;
cout<<"Enter semester:";
cin>>n;
while(currentptr!=NULL)
{
if(n==currentptr->semester)
{
flag=1;
break;
}
currentptr=currentptr->nptr;
if(currentptr==NULL)
{
cout<<"No course is enrolled by the student in semseter"<<n<<endl;
break;
}
}
if(flag==1)
{
cout<<"Enter the name of student:";
cin>>sname;
while(newptr!=NULL)
{
if(sname==newptr->Name)
{
falg=1;
cout<<"Now you can enter Attendance of student:"<<sname;
break;
}
newptr=newptr->nptr;
if(newptr==NULL)
{
cout<<ptr->name<<" is not Enrolled yet\n";
break;
}
}
if(falg==1)
{
cout<<endl<<endl;
cout<<"Enter the number of dates having marking attendance:";
cin>>l;
for(int i=0;i<l;i++)
{
ptr=new Attendance;
cout<<"Date:";
cin>>ptr->date;
if(Afptr==NULL)
{
ptr->nptr=NULL;
Afptr=ptr;
}
else
{
Attendance *currentptr=Afptr;
while(currentptr->nptr!=NULL)
{
currentptr=currentptr->nptr;
}
currentptr->nptr=ptr;
ptr->nptr=NULL;
}
ptr->name=sname;
}

cout<<"Attendance of:"<<ptr->name<<endl;
Attendance *secptr=Afptr;
cout<<setw(30)<<" Attendance Date:\n";
for(int i=0;i<l;i++)
{
cout<<"    "<<secptr->date<<endl;
secptr=secptr->nptr;
}
}
}
cout<<"---------------------\\\\----------------"<<endl;
}

void updated_Attendance()
{

cout<<"Updated Attendance:"<<endl<<endl;
Attendance *currentptr=Afptr;
cout<<"Date:\n";
for(int i=0;i<l;i++)
{
cout<<"    "<<currentptr->date<<endl;
currentptr=currentptr->nptr;
}
cout<<"---------------------\\\\\-----------------"<<endl;
}

void uploaded_marks()
{
spassword *currentptr=stfptr;
string name;
int flag=0;
cout<<setw(30)<<"Enter the name of student:";
cin>>name;
while(currentptr!=NULL)
{
if(name==currentptr->Name)
{
flag=1;
break;
}
currentptr=currentptr->nptr;
if(currentptr==NULL)
{
cout<<"You are not Enrolled in this course:";
break;
}
}
if(flag==1)
{
marks *ptr=ufptr;
while(ptr!=NULL)
{
cout<<"TOTAL GPA OF TWO CREDIT HOUR COURSE IS 0.58 AND GPA OF THREE CREDIT HOUR COURSE IS 0.75"<<endl<<end;
cout<<setw(30)<<"WEIGHTAGE AND GPA OF COURSE:"<<name<<endl;
cout<<fixed;
cout<<endl<<endl;
cout<<setw(30)<<"Obtain Assignment weightage:"<<ptr->sum2<<endl;
cout<<setw(30)<<"Obtain Quiz weightage:"<<ptr->sum3<<endl;
cout<<setw(30)<<"Obtain project weightage:"<<ptr->sum1<<endl;
cout<<setw(30)<<"Obtain sessional weightage:"<<ptr->sum4<<endl;
cout<<setw(30)<<"Obtain terminal weightage:"<<ptr->terminal_marks<<endl;
cout<<setw(30)<<"GPA obtain in one course:"<<ptr->obtain_marks;
ptr=ptr->nptr;

}
}
cout<<"---------------------\\\\----------------------"<<endl;
}

void faculty_password()
{
set_password *ptr;
ptr=new set_password;
cout<<"Enter Password:";
cin>>ptr->password;
cout<<"Enter Name:";
cin>>ptr->Name;
if(nfptr==NULL)
{
ptr->nptr=NULL;
nfptr=ptr;
}
else
{
set_password *currentptr=nfptr;
while(currentptr->nptr!=NULL)
{
currentptr=currentptr->nptr;
}
currentptr->nptr=ptr;
ptr->nptr=NULL;
}

}


void student_password()
{
spassword *ptr;
ptr=new spassword;
cout<<"Enter Password:";
cin>>ptr->password;
cout<<"Enter Name:";
cin>>ptr->Name;
if(stfptr==NULL)
{
ptr->nptr=NULL;
stfptr=ptr;
}
else
{
spassword *currentptr=stfptr;
while(currentptr->nptr!=NULL)
{
currentptr=currentptr->nptr;
}
currentptr->nptr=ptr;
ptr->nptr=NULL;
}

}

