#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void registration();
void login();
void A_details();
void d_details();
void s_details();
int main()  //start
{
	int c;
	cout<<"\n\t\t\t*****************************************************\n\n\n";
	cout<<"\t\t\t\tWelcome to Employee Atendance page\n\n\n";
	cout<<"\t\t\t\t\t******	 Menu   ******\n\n\n";
	cout<<"                                                      \n\n";
	cout<<"\t* Press 0 to quit the program"<<endl;
	cout<<"\t* Press 1 For Admin Registration "<<endl;
	cout<<"\t* Press 2 to Login & Authenticate"<<endl;
	cout<<"\t* Press 3 to add attendence details to a file"<<endl;
	cout<<"\t* Press 4 to display attendence information from a file"<<endl;
	cout<<"\t* Press 5 to search for attendence record by employee ID"<<endl;
	cout<<"\n\t\t Please enter your choice : ";		cin>>c;
	cout<<endl;
	switch(c)
	{
	case 0:
		 system("cls");
		 cout<<"\n\n\n\n\n\t\t\t\t---Exiting---\n\t\t\t\t**Thank you**"<<endl;
		  exit(0);	break;
	case 1:
		 registration();	break;
 	case 2:
  		 login();		break;
	case 3:
		 A_details();	break;
	case 4:
		 d_details();	break;
   case 5:
         s_details(); break;
	default:
	system ("cls");
	cout<<"\t\t\t Please select from the options given below \n"<<endl;
	main();
	}

} //end of 1st function (main)
void registration()  //start
{
	string rusername,rpassword;
	cout<<"\t\t\t Enter the Username : ";
	cin.ignore();
	getline(cin,rusername);
	cout<<"\t\t\t Enter the Password : ";
	cin.ignore();
	getline(cin,rpassword);
	ofstream write1("registrationrecords.txt",ios::app);
	write1<<rusername<<" "<<rpassword<<endl;
	system("cls");
	cout<<"\n\t\t Registration Successful ! \n";
	main();
}  // end of 2nd function (registration)
void login()  //start
{
	int count;
	string userId,password,pass,id;
	system("cls");
	cout<<"\t\t\t Please enter the Username and Password : "<<endl;
	cout<<"\t\t\t USERNAME : ";
		cin.ignore();
	getline(cin,userId);
	cout<<"\t\t\t PASSWORD : ";
		cin.ignore();
	getline(cin,password);
	ifstream read1("registrationrecords.txt",ios::in);
	while(read1>>id>>pass)
	{
		if(id==userId && pass==password)
		{
			count=1;
			system("cls");
		}
	}
	read1.close();
	if(count==1)
	{
		cout<<userId<<"\n Your LOGIN is successful \n Thanks for logging \
in ! \n\t\t\t\tYou are Authenticated/Verified\n";
		main();
	}
	else{
		cout<<"\n LOGIN ERROR \n You are not Verified \n Please check \
your username and password \n\n";
		main();
	}
}  // end of 3rd function (login)
void A_details()  //start
{
	string status , name , ID;
	cout<<"Enter employee name : ";
	cin.ignore();
	cin>>name;
	cout<<"Enter employee ID : ";
	cin.ignore();
	cin>>ID;
	cout<<"Enter status : " ;
	cin.ignore();
	cin>>status;
		ofstream write2("attendencerecords.txt",ios::app);
	write2<<name<<"\t"<<ID<<"\t"<<status<<endl;
	system("cls");
	cout<<"\n\t\t\t\t**Attendence Record updated successfullY**\n\n"<<endl;
	main();
}
void d_details()
{

	string ename , ename2,  id , sta; int count;
	cout<<"Enter name : ";
	cin.ignore();
	getline(cin, ename);
	ifstream read2("attendencerecords.txt",ios::in);
	while(read2>>ename2>>id>>sta)
	{
		if(ename2==ename )
		{
			 count=1;
			system("cls");
		} // if condition closing
	} // infile closing
	read2.close();
	if(count==1)
	{
		cout<<"Employee "<<ename<<" of ID "<<id<<" is "<<sta<<endl;
	} // if condition 2 closing
	else
	cout<<"No such employee found"<<endl;
	main();
}  // end of 4th function (attendence details)
void s_details()
{
	string ID , ID2 , name , status;int count;
	cout<<"enter the ID number you are searching for : ";
	cin.ignore();
	cin>>ID;
	ifstream read3("attendencerecords.txt",ios::in);
	while(read3>>name>>ID2>>status)
	{
		if(ID==ID2){
			count=1;
			system("cls");
		}
	}
	read3.close();
	if(count==1)
	{
		cout<<"employee name is "<<name<<endl;
		cout<<"employee ID is "<<ID<<endl;
		cout<<"employee status is "<<status<<endl;
	}
	else
	cout<<"No such employee ID found\nplease check your ID number"<<endl;
	main();
}
