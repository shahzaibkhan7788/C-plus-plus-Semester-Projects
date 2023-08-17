#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include<conio.h>
void student_data();
void faculty_data();
void updated_Attendance();
void uploaded_marks();
void faculty_password();
void student_password();
void semester_fee();
void Exit_function();
using namespace std;
int k;
int m;
int l;
int n;
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
void Enroll_courses();
void set_data()
{
fstream myfile;
cout<<"Log in ID:";
cin>>ID;
cout<<"Registration No.:";
cin>>Registration;
cout<<"Enter age:";
cin>>age;
cout<<"Phone Number:";
cin>>phone_No;
cout<<"Identity card:";
cin>>CNIC;
cout<<"Email Address:";
cin>>Email_Address;
if(n==1)
{
fstream myfile("student",ios::out);
myfile<<"ID:"<<ID<<endl;
myfile<<"Registration:"<<Registration<<endl;
myfile<<"Age:"<<age<<endl;
myfile<<"Phone No."<<phone_No<<endl;
myfile<<"CNIC:"<<CNIC<<endl;
myfile<<"Email:"<<Email_Address<<endl;
}
if(n==2)
{
fstream faculty("faculty",ios::out);
faculty<<"ID:"<<ID<<endl;
faculty<<"Registration:"<<Registration<<endl;
faculty<<"Age:"<<age<<endl;
faculty<<"Phone No."<<phone_No<<endl;
faculty<<"CNIC:"<<CNIC<<endl;
faculty<<"Email:"<<Email_Address<<endl;
}

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
string mark;
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
char ch;
   cout<<"Press any key to start a program...";
  cin>>ch;
getchar();
cout<<endl;
cout<<"WELCOME TO SRA PORTAL OF PIEAS UNIVERSTY:\n\n";
while(1)
{
 cout<<setw(50)<<"INTORDUCE YOUR SELF\n";
  cout<<"1 for Administration:\n";
  cout<<"2 for Faculty:\n";
  cout<<"3 for Student:\n";
  cout<<"4 to exit the function\n\n";
  cin>>n;
    system("CLS");
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
case 4:
       Exit_function();
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
cout<<setw(15)<<"WELCOME! HAVE A NICE DAY";
cout<<endl<<endl;
cout<<"1 to Add student\n";
cout<<"2 to Add faculty member\n";
cout<<"3 to Add semester\n";
cout<<"4 to return main menu\n";
cin>>n;
switch(n)
{
case 1:
        student_password();
	break;
case 2:
       faculty_password();
	break;
case 3:
         B.semester_Enrolment();
	break;
case 4:
        flag=1;
        break;
default:
        cout<<"Wrong input\n";
}
if(n>=1 && n<=5)
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
cout<<"You have successfully enter the password:\n";
break;
}
ptr=ptr->nptr;
if(ptr==NULL)
{
cout<<"Wrong password...ntry again\n";
break;
}
cout<<"---------------------------------------"<<endl;
}

if(flag==1)
{
cout<<"WELCOME! HAVE A NICE DAY\n\n";
cout<<"1 to see Add courses\n";
cout<<"2 to see student enrolled courses\n";
cout<<"3 to  mark Attendence\n";
cout<<"4 for marks\n";
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
int flag=0;
Admin A;
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
cout<<"WELCOME! HAVE A NICE DAY\n\n";
cout<<"1 to enroll the courses\n";
cout<<"2 to to see the updated attendence\n";
cout<<"3 to see the uploaded marks\n";
cout<<"4 to see the semester fee\n";
cin>>n;
switch(n)
{
case 1:
        A.Enroll_courses();
	break;
case 2:
      updated_Attendance();
      break;
case 3:
       uploaded_marks();
      break;
case 4:
       semester_fee();
       break;
default:
       cout<<"Wrong input\n";

}
}
cout<<"---------------------------------------"<<endl;
}





void course::semester_Enrolment()
{
course *ptr;
Admin A;
ptr=new course;
int count=3;
cout<<"Type the season:\n\n"<<setw(15)<<"spring_2023\nfall_2023\n\n";

string B="spring_2023";
string C="fall_2023";

cout<<"Enter the season offering:";
	cin>>season;
	if(season==C)
	{
            cout<<"OFFERED SEMESETER IN FALL SEASON 2023:\n\n";
            cout<<"2 for second semester\n";
	   cout<<"4 for fourth semester\n";
	   cout<<"6 for sixth semester\n";
	   cout<<"8 for eight semester\n";
	   cout<<"Enter the Semester:";
		cin>>ptr->semester;
			if(ptr->semester==2)
		{
		 cout<<"SECOND FALL SEMESTER 2023\n";
		 cout<<"Semester Added successfully\n\n";
		}
	       if(ptr->semester==4)
              {
	        cout<<"FOURTH FALL SEMESTER 2023\n";
	       	 cout<<"Semester Added successfully\n\n";
              }
	     if(ptr->semester==6)
              {
	         cout<<"SIXTH FALL SEMESTER  2023\n";
	            cout<<"Semester Added successfully\n\n";
              }
	    if(ptr->semester==8)
             {
	         cout<<"EIGHT FALL SEMESTER 2023\n";
	      	 cout<<"Semester Added successfully\n\n";
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

cout<<"OFFERED SEMESETER IN SPRING SEASON 2023 semester :\n\n";
                  cout<<"1 for First semester\n";
		cout<<"3 for Third semester\n";
		cout<<"5 for Fifth semester\n";
		cout<<"7 for Seventh semester\n";
		cout<<"Enter Semester:\n";
		cin>>ptr->semester;
cout<<endl;
		if(ptr->semester==1)
		{
                    cout<<"FIRST SPRING SEMESTER 2023\n\n";
		 cout<<"Semester Added successfully\n\n";
		}

		if(ptr->semester==3)
                  {
		  cout<<"THIRD SPRING SEMESTER 2023\n";
	       	  cout<<"Semester Added successfully\n\n";
                  }
		 if(ptr->semester==5)
                  {
                    cout<<"FIFTH SPRING SEMESTER 2023\n";
	        	  cout<<"Semester Added successfully\n\n";
                  }
	        if(ptr->semester==7)
                 {
		   cout<<"SEVENTH  SPRING SEMESTER 2023\n";
	            cout<<"Semester Added successfully\n\n";
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
 A.Add_courses();
}


void Admin::Add_courses()
{
fstream myfile("Admin",ios::out);
if(!myfile)
{
cout<<"No Admin file is created yet\n";
}
else
{
int n;
Admin *ptr;
course *newptr=Ad_fptr;
cout<<"Add the Number of courses\n";
cin>>k;
for(int i=0;i<k;i++)
{
ptr=new Admin;
ptr->semester=n;
cout<<"Enter course title:";
cin>>ptr->course_title;
myfile<<"Course title:"<<ptr->course_title<<endl;
cout<<"Faculty member:";
cin>>ptr->professor;
myfile<<"Professor:"<<ptr->professor<<endl;
cout<<"course Code:";
cin>>ptr->code;
myfile<<"Course Code:"<<ptr->code<<endl;
cout<<" Credit hour:";
cin>>ptr->credit_hour;
myfile<<"Credit Hour:"<<ptr->credit_hour<<endl;
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
cout<<"Successfully  Courses Added in Semester:"<<newptr->semester<<" Semester"<<endl;
Admin *currentptr=A_fptr;
if(A_fptr==NULL)
{
cout<<"Link list is empty\n";
}
else
{
cout<<"|----------------|--------------------|"<<endl;
cout<<"|Course Title    |     professor -----|"<<endl;
cout<<"|----------------|--------------------|"<<endl;
for(int i=0;i<k;i++)
{
cout<<"|----------------|--------------------|"<<endl;
cout<<"|"<<currentptr->course_title<<"                   "<<currentptr->professor<<"                "<<endl;
cout<<"|----------------|--------------------|"<<endl;
currentptr=currentptr->nptr;
}
}
}
myfile.close();
cout<<endl;
}





void marks::upload_marks()
{
fstream myfile("faculty",ios::out);
myfile<<"Marks of student:"<<endl;
if(!myfile)
{
cout<<"No faculty file is created yet\n";
}
else
{
course_enrollment *newptr=Co_fptr;
marks *ptr;
ptr=new marks;
string course;
int flag=0;
int n,a,b,c,d;
int t_sessional=20;
int t_terminal=50;
int t_quiz=10;
int t_Assignment=10;
int t_project=10;
cout<<endl;
cout<<"Enter course Name:";
cin>>course;
while(newptr!=NULL)
{
if(course==newptr->course_name)
{
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
cout<<"Assignments:";
cin>>b;
cout<<"Projects:";
cin>>c;
cout<<"Sessionals or Mid-Term:";//
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
{
ptr->obtain_marks=((ptr->sum)/ptr->total_marks)*4;
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
cout<<setw(30)<<"WEIGHTAGE OF :"<<course<<endl<<endl;
cout<<fixed;
cout<"|----OBTAIN WEIGHTAGE----|";
cout<<endl;
{
secptr->sum2=(secptr->sum2/secptr->sum)*4;
secptr->sum2=secptr->sum2;
cout<<"|  Assignment    "<<secptr->sum2<<" |"<<endl;
myfile<<"Assignment:"<<secptr->sum2<<endl;
secptr->sum3=(secptr->sum3/secptr->sum)*4;
secptr->sum3=secptr->sum3;
cout<<"|  Quiz         "<<secptr->sum3<<" |"<<endl;
myfile<<"Quiz:"<<secptr->sum3<<endl;
secptr->sum1=(secptr->sum1/secptr->sum)*4;
secptr->sum1=secptr->sum1;
cout<<"|  Project      "<<secptr->sum1<<" |"<<endl;
myfile<<"project:"<<secptr->sum1<<endl;
secptr->sum4=(secptr->sum4/secptr->sum)*4;
secptr->sum4=secptr->sum4;
cout<<"|  Sessional    "<<secptr->sum4<<" |"<<endl;
myfile<<"Sessional:"<<secptr->sum4<<endl;
secptr->terminal_marks=(secptr->terminal_marks/secptr->sum)*4;
secptr->terminal_marks=secptr->terminal_marks;
cout<<"|  Terminal     "<<secptr->terminal_marks<<" |"<<endl;
myfile<<"Terminal marks:"<<secptr->terminal_marks<<endl;
cout<<"GPA             "<<secptr->obtain_marks<<" |"<<endl;
myfile<<"GPA:"<<secptr->obtain_marks<<endl;
secptr->obtain_marks=secptr->obtain_marks;
secptr=secptr->nptr;
}
}
}
else
{
cout<<"Sorry!This course is not enrolled ny the student:\n\n";
}
}
myfile.close();
cout<<endl;
cout<<"-----------------------------------"<<endl;
}




void Admin::Enroll_courses()
{
int flag=0;
int n;
fee=0;
fstream myfile("student",ios::out);
myfile<<"Enrolled Courses:"<<endl;
if(!myfile)
{
cout<<"Student file is not created yet\n";
}
else
{
course_enrollment *ptr;
Admin *currentptr=A_fptr;
course *newptr=Ad_fptr;
cout<<"Enter Semester:";
cin>>n;
while(newptr!=NULL)
{
if(n==newptr->semester)
{
flag=1;
cout<<endl<<endl;
cout<<setw(30)<<"Enroll the Above Courses"<<endl<<endl;
break;
}
if(newptr==NULL)
{
break;
}
newptr=newptr->nptr;
}
if(flag==1)
{
cout<<endl;
cout<<"Following are Added courses by Admin in semester:"<<n<<endl<<endl;
cout<<" |   Course Title    |"<<endl;
cout<<" |-------------------|"<<endl;
for(int i=0;i<k;i++)
{
cout<<" |"<<currentptr->course_title<<"            |"<<endl;
cout<<" |-------------------|"<<endl;
currentptr=currentptr->nptr;
}
}
cout<<"Please Enroll courses in semester:"<<n<<endl<<endl;
cout<<setw(30)<<"Enter Number of courses:";
cin>>m;
cout<<endl;
cout<<"|------Course Name------|"<<endl;
for(int i=0;i<m;i++)
{
fee=fee+5000;
ptr=new course_enrollment;
cin>>ptr->course_name;
myfile<<"Courses Name:"<<ptr->course_name<<endl;
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
}
myfile.close();
cout<<"----------------------------------"<<endl;
}




void semester_fee()
{
if(Co_fptr==NULL)
{
cout<<"You have not enrolled any course courses yet\n";
}
else
{
cout<<"|------------------|--------------|"<<endl;
cout<<"|Semester Fee      | "<<fee<<"    |"<<endl;
cout<<"|------------------|--------------|"<<endl;
cout<<"|Library Charges   |   3000       |"<<endl;
cout<<"|------------------|--------------|"<<endl;
cout<<"|Hostel Charges    |   30000      |"<<endl;
cout<<"|------------------|--------------|"<<endl;
cout<<"|Transport Charges |   5000       |"<<endl;
cout<<"|------------------|--------------|"<<endl;
cout<<"|Internet Charges  |   2000       |"<<endl;
cout<<"|------------------|--------------|"<<endl;
cout<<"|Total Fee         |   "<<fee+40000<<endl;
cout<<"|------------------|--------------|"<<endl;
cout<<endl;
}
cout<<"-------------------------------------"<<endl;
}






void Faculty::Assigned_courses()
{
fstream myfile("faculty",ios::out);
myfile<<"Added Courses:"<<endl;
if(!myfile)
{
cout<<"No file is created for faculty\n";
}
else
{
course *currentptr=Ad_fptr;
Admin *ptr=A_fptr;
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
cout<<"Course Title:     |    professor     |"<<endl;
cout<<"|-----------------|------------------|"<<endl;
for(int i=0;i<k;i++)
{
cout<<"|"<<ptr->course_title<<"               "<<ptr->professor<<"               "<<endl;
cout<<"|-----------------|------------------|"<<endl;
myfile<<"Course title:"<<ptr->course_title<<endl;
ptr=ptr->nptr;
}
}
}
myfile.close();
cout<<"------------------------------------------"<<endl;
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
else
{
cout<<"No course is enrolled by student in semester:"<<n<<endl;
}

cout<<"-----------------------------------------"<<endl;
}




void Attendance::mark_Attendance()
{
fstream myfile("faculty",ios::out);
myfile<<"Attendance of student:"<<endl;
if(!myfile)
{
cout<<"No faculty file is created yet\n";
}
else
{
int flag=0;
int falg=0;
int n;
Admin *currentptr=A_fptr;
spassword *newptr=stfptr;
Attendance *ptr;
string sname;
cout<<"Enter course code:";
cin>>n;
while(currentptr!=NULL)
{
if(n==currentptr->code)
{
flag=1;
break;
}
currentptr=currentptr->nptr;
if(currentptr==NULL)
{
break;
}
}
if(flag==1)
{
cout<<"Enter  name of student:";
cin>>sname;
while(newptr!=NULL)
{
if(sname==newptr->Name)
{
falg=1;
break;
}
newptr=newptr->nptr;
if(newptr==NULL)
{
cout<<ptr->name<<" is not Enrolled yet\n";
break;
}
}
}
if(flag==0)
{
cout<<"No course is enrolled by the student in semseter"<<n<<endl;
}
if(falg==1)
{
cout<<endl<<endl;
cout<<"Enter the number of dates having marking attendance:";
cin>>l;
cout<<"|-------Date-------|---Attendance---|"<<endl;
for(int i=0;i<l;i++)
{
ptr=new Attendance;
cout<<"|";
cin>>ptr->date;
cout<<"                   |    ";
cin>>ptr->mark;
myfile<<"Date "<<ptr->date;
myfile<<"   "<<ptr->mark<<endl;
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
cout<<setw(30)<<"|----Date-------|-----Attendance------|"<<endl;
for(int i=0;i<l;i++)
{
cout<<"|"<<secptr->date<<"         "<<ptr->mark<<"       "<<endl;
secptr=secptr->nptr;
}
}
}
myfile.close();
cout<<"----------------------------------"<<endl;
}





void updated_Attendance()
{
fstream myfile("student",ios::out);
myfile<<"Updated Attendance:"<<endl;
if(!myfile)
{
cout<<"No student file is created yet\n";
}
else
{
cout<<"Updated Attendance:"<<endl<<endl;
Attendance *currentptr=Afptr;
cout<<"Date:\n";
cout<<"|    Date    |    Attendance    |"<<endl;
for(int i=0;i<l;i++)
{
cout<<"|"<<currentptr->date;
cout<<"           ";
myfile<<"Date:   "<<currentptr->date;
cout<<currentptr->mark<<"           "<<endl;
myfile<<"   "<<currentptr->mark<<endl;
currentptr=currentptr->nptr;
}
}
myfile.close();
cout<<"-----------------------------------------"<<endl;
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
cout<<setw(30)<<"WEIGHTAGE OF :"<<ptr->course_name<<endl;
cout<<fixed;
while(ptr!=NULL)
{

cout<"|----OBTAIN WEIGHTAGE----|";
cout<<endl;
{
cout<<"|  Assignment    "<<ptr->sum2<<"  |"<<endl;
cout<<"|  Quiz         "<<ptr->sum3<<"   |"<<endl;
cout<<"|  Project      "<<ptr->sum1<<"   |"<<endl;
cout<<"|  Sessional    "<<ptr->sum4<<"   |"<<endl;
cout<<"|  Terminal     "<<ptr->terminal_marks<<"   |"<<endl;
cout<<"|GPA             "<<ptr->obtain_marks<<"   |"<<endl;
ptr=ptr->nptr;
}
}
}
cout<<"--------------------------------------"<<endl;
}






void faculty_password()
{
Admin A;
fstream myfile("faculty",ios::out);
myfile<<"Faculty Bio data:"<<endl;
if(!myfile)
{
cout<<"No file is created for faculty\n";
}
else
{
set_password *ptr;
ptr=new set_password;
cout<<endl;
cout<<"Enter Password:";
cin>>ptr->password;
myfile<<"password:"<<ptr->password<<endl;
cout<<"Enter Name:";
cin>>ptr->Name;
myfile<<"Name:"<<ptr->Name<<endl;
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
A.set_data();
}
myfile.close();
}





void student_password()
{
Admin A;
fstream  myfile("student",ios::out);
myfile<<"Student Bio Data:"<<endl;
if(!myfile)
{
cout<<"No file for student is created yet\n";
}
else
{
spassword *ptr;
ptr=new spassword;
cout<<endl;
cout<<"Enter Password:";
cin>>ptr->password;
myfile<<"password:"<<ptr->password<<endl;
cout<<"Enter Name:";
cin>>ptr->Name;
myfile<<"Name:"<<ptr->Name<<endl;
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
A.set_data();
myfile.close();
}
}



void Exit_function()
{
cout<<endl;
string ch;
{
fstream myfile("student",ios::in);
if(!myfile)
{
cout<<"No student file is created yet\n";
}
else
{
myfile<<"Student Data"<<endl;
while(!myfile.eof())
{
myfile>>ch;
cout<<ch<<endl;
}
}
myfile.close();
}

cout<<endl;
fstream myfile("faculty",ios::in);
{
if(!myfile)
{
cout<<"No faculty file is created yet\n";
}
else
{
myfile<<"Faculty Data"<<endl;
while(!myfile.eof())
{
myfile>>ch;
cout<<ch<<endl;
}
}
myfile.close();
}

cout<<endl;
fstream Admin("Admin",ios::in);
{
if(!Admin)
{
cout<<"No faculty file is created yet\n";
}
else
{
myfile<<"Admin Data"<<endl;
while(!myfile.eof())
{
myfile>>ch;
cout<<ch<<endl;
}
}
myfile.close();
}
exit(0);
}


 
 
 
 
 
 
 

