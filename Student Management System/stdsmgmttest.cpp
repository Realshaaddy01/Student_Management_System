#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<stdlib.h>
#include<ctime>
#include<iomanip>

using namespace std;


class fee 
{
        public:
        int sid;
        string fee_id ;
        string year;
        string month;
        string fee_paid;
        string balance;
        string paid_date;        

        void feemenu();
        void makepayment();
        void checkpayment();
        void showallpayments();
};

class exam : virtual public fee
{ 
        public:
        int sid;
        string eid;
        string examdate;
        string months;
        string year;
        string subject;
        string marksobtained;
        string passmarks;
        string resultstatus;  

        void exammenu();
        void examrecord();
        void searchstds();
        void showallexam();   
};

class student : virtual public fee, virtual public exam 
{
    public:
        int sid;
        string name;
        string address;
        string contact;
        string email;
        string dob;
        string course;
		
        void menu();
      	void stdsmenu();
        void insert();
        void display();
        void search();
};


void student :: menu()
{
menustart:
    int choice;
    char x;
    system("cls");
    cout<<"\t\t\t ------------------------------------- "<<endl; 
    cout<<"\t\t\t|------Student Management System-----|"<<endl;
    cout<<"\t\t\t ------------------------------------- "<<endl;
    cout<<"\t\t\t| 1. Student Registration            |"<<endl;
    cout<<"\t\t\t| 2. Student Fee Payment             |"<<endl;
    cout<<"\t\t\t| 3. Student Exam Result             |"<<endl;
    cout<<"\t\t\t| 4. Exit                            |"<<endl;
    cout<<"\t\t\t-------------------------------------- "<<endl;
    cout<<"\t\t\t Choose option [1,2,3,4] "<<endl;
    cout<<"\t\t\t-------------------------------------- "<<endl<<endl;
    cout<<"\t\t\t Enter your choice : ";
    cin>>choice;

    switch(choice){
        case 1:
            do{
                stdsmenu();
                cout<<"\t\t\t Do you want to Continue Stds Registration  (y/n) : ";
                cin>>x;
            }
                while(x =='y'|| x=='Y');
                if(x == 'n' || x == 'N'){
					return menu();
				};
                break;
       case 2:
       		do{
               feemenu();
               cout<<"\t\t\t Do you want to Continue Fee Payment  (y/n) : ";
               cin>>x;
            }
               while(x =='y'| x =='Y');
               if(x == 'n' || x == 'N'){
					return menu();
				};
               break;
       case 3:
       		do{
               exammenu();
               cout<<"\t\t\t Do you want to Continue Exam Records  (y/n) : ";
               cin>>x;
            }
               while(x=='y'| x=='Y');
               if(x == 'n' || x == 'N'){
					return menu();
				};
               break;
        case 4:
        	exit(0);
        	break;
        default:
        cout<<"\t\t\t Invalid Choice... Please input the correct number ";
            }
            return ;
            goto menustart;
}

void student :: stdsmenu()
{
    menustart1:
    int choice;
    char x;
    system("cls");
    cout<<"\t\t\t---------------------------------------"<<endl; 
    cout<<"\t\t\t|------Student Management System------|"<<endl;
    cout<<"\t\t\t---------------------------------------"<<endl;
    cout<<"\t\t\t| 1. Register Student Record          |"<<endl;
    cout<<"\t\t\t| 2. Display Student Record           |"<<endl;
    cout<<"\t\t\t| 3. Search Student Record            |"<<endl;
    cout<<"\t\t\t| 4. Exit                             |"<<endl;
    cout<<"\t\t\t---------------------------------------"<<endl;
    cout<<"\t\t\t Choose option [1,2,3,4] "<<endl;
    cout<<"\t\t\t---------------------------------------"<<endl<<endl;
    cout<<"\t\t\t Enter your choice : ";
    cin>>choice;

    switch(choice){
        case 1:
        	do{
            insert();
                cout << "\t\t\t Add Another Student Record (Y,N): ";
                cin>>x;
                }
                while(x =='Y'|| x =='y');
				
                break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
        	do{
               
               cout<<"\t\t\t Do you want to Continue to exit   (y/n) : ";
               cin>>x;
            }
               while(x=='n'| x=='N');{
               	return menu();
			   };

            exit(0);
            break;
        default:
        cout<<"\t\t\t Invalid Choice... Please input the correct number ";
    }
    	return;
    	goto menustart1;
}
void student :: insert()
{
    system("cls");
    fstream infile;
    
    cout<<"\t\t\t ------------------------------------- "<<endl; 
    cout<<"\t\t\t|------Student Management System------|"<<endl;
    cout<<"\t\t\t ------------------------------------- "<<endl;
    cout<<"\t\t\t|      Register a Student Record      |"<<endl;
            
            cout<<"\t\t\t Enter Student ID : ";
            cin>>sid;
            cout<<"\t\t\t Enter Student Name : ";
           	cin>>name;
            cout<<"\t\t\t Enter Student Address : ";
            cin>>address;
            cout<<"\t\t\t Enter Student Contact : ";
            cin>>contact;
            cout<<"\t\t\t Enter Student Email : ";
            cin>>email;
            cout<<"\t\t\t Enter Student DOB : ";
            cin>>dob;
            cout<<"\t\t\t Enter Student Course : ";
            cin>>course;
            cout<<endl;

            infile.open("student.txt", ios::app | ios::out);
            infile<<sid<<" "<<name<<" "<<address<<" "<<contact<<" "<<email<<" "<<dob<<" "<<course<<endl;
            infile.close();
}

void student :: display()
{
    system("cls");
    fstream infile;
    int total = 1;
    
    cout<<"\t\t\t ------------------------------------- "<<endl; 
    cout<<"\t\t\t|------Student Management System------|"<<endl;
    cout<<"\t\t\t ------------------------------------- "<<endl;
    cout<<"\t\t\t|      Display Student Record         |"<<endl;
    cout<<"\t\t\t ------------------------------------- "<<endl;
    cout<<endl;
    infile.open("student.txt", ios::in);

    if(!infile){
        cout<<"\t\t\t ...No Data is Present... "<<endl;	
        infile.close();
    }
    else {
        infile>>sid>>name>>address>>contact>>email>>dob>>course;
        while(!infile.eof()){
            cout<<"\t\t\t ------------------------------------- "<<endl;
            cout<<"\t\t\t Student serial Number : "<<total++ <<endl;  
            cout<<"\t\t\t Student Identity No : "<< sid << endl;
            cout<<"\t\t\t Student Name : "<< name << endl;
            cout<<"\t\t\t Student Address : "<< address << endl;
            cout<<"\t\t\t Student Contact : "<< contact << endl;
            cout<<"\t\t\t Student Email id : "<< email << endl;
            cout<<"\t\t\t Student Date of birth : "<< dob << endl;
            cout<<"\t\t\t Student Course : "<< course << endl;
            cout<<"\t\t\t ------------------------------------- "<<endl;
          	infile>>sid>>name>>address>>contact>>email>>dob>>course;
          	cout<<endl<<endl;
        }
        if(total == 0){
            cout<<"\t\t\t ...No Data is Present... "<<endl;
        }
    }
    infile.close();
}
void student :: search()
{
    system("cls");
    fstream infile;
    int found = 0;
    
    cout<<"\t\t\t ------------------------------------- "<<endl; 
    cout<<"\t\t\t|------Student Management System------|"<<endl;
    cout<<"\t\t\t ------------------------------------- "<<endl;
    cout<<"\t\t\t|      Search Student Record          |"<<endl;
    cout<<"\t\t\t ------------------------------------- "<<endl;
    
    infile.open("student.txt", ios::in);
    if(!infile){
        cout << "\t\t-------------------------------------------------------------------" << endl;
        cout << "\t\t--------------- Student Search Data ---------------------------------" << endl<<endl;
        cout<<"\t\t\t .........No Data is Present........... "<<endl;
    }
    else {
        int stds_id;
         cout << "\t\t-------------------------------------------------------" << endl;
         cout << "\t\t--------------- Student Search Data -------------------" << endl;
         cout << " \t\t Enter The Student ID : ";
         cin>>stds_id;
        infile>>sid>>name>>address>>contact>>email>>dob>>course;
        while(!infile.eof()){
            if(stds_id == sid)
			{ 
                cout<<"\t\t\t ------------------------------------- "<<endl;
                cout<<"\t\t\t Student Identity No : "<< sid << endl;
                cout<<"\t\t\t Student Name : "<< name << endl;
                cout<<"\t\t\t Student Address : "<< address << endl;
                cout<<"\t\t\t Student Contact : "<< contact << endl;
                cout<<"\t\t\t Student Email id : "<< email << endl;
                cout<<"\t\t\t Student Date of birth : "<< dob << endl;
                cout<<"\t\t\t Student Course : "<< course << endl;
                cout<<"\t\t\t ------------------------------------- "<<endl;
                cout<<endl<<endl;
				found++;
            }
            infile>>sid>>name>>address>>contact>>email>>dob>>course;
        }
        if(found == 0){
            cout<<"\t\t\t Student id is not found "<<endl;
        }
        infile.close();
    }
}
void fee :: feemenu(){
    menustart2:
    int choice;
    char x;
    system("cls");
    cout<<"\t\t\t---------------------------------------"<<endl;
    cout<<"\t\t\t|----------Fee Payment System---------|"<<endl;
    cout<<"\t\t\t---------------------------------------"<<endl;

    cout<<"\n\t\t\t ---------1. Make Payment  ----------";
    cout<<"\n\t\t\t ---------2. Check Payment ----------";
    cout<<"\n\t\t\t ---------3. Show all Payments ------";
    cout<<"\n\t\t\t ---------4. Exit -------------------"<<endl;
    
    cout<<"\t\t\t-----------------------------------------"<<endl;
    cout<<"\t\t\t Choose option [1,2,3,4] "<<endl;
    cout<<"\t\t\t-----------------------------------------"<<endl;
    cout<<"\t\t\t Enter your choice : ";
    cin>>choice;
    
    switch(choice){
        case 1:
            do {
            makepayment();
            cout<<"\t\t\t Do you want to make another payment (Y/N) : ";
            cin>>x;
            } while(x == 'Y' || x == 'y');
            break;
        case 2:
            checkpayment();
            break;
        case 3:
            showallpayments();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout<<"\t\t\t Invalid Choice"<<endl;
            break;
    }
    return;
    goto menustart2;
}
void fee :: makepayment()
{
    startmenu2:
    fstream infile2;
    system("cls");
    cout<<"\t\t\t ---------------------------------------"<<endl;
    cout<<"\t\t\t|----------Fee Payment System-----------|"<<endl;
    cout<<"\t\t\t ---------------------------------------"<<endl;
    cout<<"\t\t\t|-----------Making Fee Payment----------|"<<endl;
    cout<<"\t\t\t ----------------------------------------"<<endl;


    cout<<"\t\t Enter the Student id : ";
    cin>>sid;
    cout<<"\t\t Enter the Fee id : ";
    cin>>fee_id;
    cout<<"\t\t Enter the Payment Year : ";
    cin>>year;	
    cout<<"\t\t Enter the Payment Month : ";
    cin>>month;
    cout<<"\t\t Enter the Paid amount : ";
    cin>>fee_paid;
    cout<<"\t\t Enter the Payment Balanace : ";
    cin>>balance;
    cout<<"\t\t Enter the Payment Date : ";
    cin>>paid_date;

    infile2.open("fee.txt", ios::app | ios::out);
    if(!infile2){
        cout<<"\t\t\t Error in opening file"<<endl;
    }
    else{
        infile2<<sid<<" "<<fee_id<<" "<<year<<" "<<month<<" "<<fee_paid<<" "<<balance<<" "<<paid_date<<endl;
        cout<<"\t\t-----------Payment is made successfully---------------"<<endl;
    }
    
    infile2.close();
    return;
    goto startmenu2;
}

void fee :: checkpayment()
{
    system("cls");
    fstream infile2;
    int found = 0;
    
    cout<<"\t\t\t ---------------------------------------"<<endl;
    cout<<"\t\t\t|----------Fee Payment System-----------|"<<endl;
    cout<<"\t\t\t ---------------------------------------"<<endl;
    cout<<"\t\t\t|         Check Payment Record          |"<<endl;
    cout<<"\t\t\t ---------------------------------------"<<endl;
    
    infile2.open("fee.txt", ios::in);
    if(!infile2){
        cout << "\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t------------------------ Fee Payment Data ------------------------" << endl<<endl;
        cout<<"\t\t\t.........................No Data is Present......................."<<endl;
    }
    else {
        int stud_id;
         cout << "\t\t-------------------------------------------------------" << endl;
         cout << "\t\t--------------- Fee Payment Data -------------------" << endl;
         cout << " \t\t Enter The Student ID : ";
         cin>>stud_id;
        infile2>>sid>>fee_id>>year>>month>>fee_paid>>balance>>paid_date;
        while(!infile2.eof()){
            if(stud_id == sid)
            { 
                cout<<"\t\t\t ------------------------------------- "<<endl;
                cout<<"\t\t\t Student id : "<< sid << endl;
                cout<<"\t\t\t Fee id : "<< fee_id << endl;
                cout<<"\t\t\t Payment Year : "<< year << endl;
                cout<<"\t\t\t Payment Month : "<< month << endl;
                cout<<"\t\t\t Paid amount : "<< fee_paid << endl;
                cout<<"\t\t\t Payment Balanace : "<< balance << endl;
                cout<<"\t\t\t Payment Date : "<< paid_date << endl;
                cout<<"\t\t\t ------------------------------------- "<<endl;
                found++;
            }
            infile2>>sid>>fee_id>>year>>month>>fee_paid>>balance>>paid_date;
        }
        if(found == 0){
            cout<<"\t\t\t Student id is not found "<<endl;
        }
        infile2.close();
    }
}

void fee :: showallpayments()
{
    system("cls");
    fstream infile2;
    int total = 1;
    infile2.open("fee.txt", ios::in);
    if(!infile2){
        cout << "\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t------------------------ Fee Payment Data ------------------------" << endl<<endl;
        cout<<"\t\t\t.........................No Data is Present......................."<<endl;
        infile2.close();
    }
    else {
        cout << "\t\t-------------------------------------------------------" << endl;
        cout << "\t\t--------------- Fee Payment Data -------------------" << endl;
        infile2>>sid>>fee_id>>year>>month>>fee_paid>>balance>>paid_date;
        while(!infile2.eof()){
        	cout<<"\t\t\t ---------------------------------------"<<endl;
        	cout<<"\t\t\t Total fee payments : "<< total++ << endl;
            cout<<"\t\t\t Student id : "<< sid << endl;
            cout<<"\t\t\t Fee id : "<< fee_id << endl;
            cout<<"\t\t\t Payment Year : "<< year << endl;
            cout<<"\t\t\t Payment Month : "<< month << endl;
            cout<<"\t\t\t Paid amount : "<< fee_paid << endl;
            cout<<"\t\t\t Payment Balanace : "<< balance << endl;
            cout<<"\t\t\t Payment Date : "<< paid_date << endl;
            cout<<"\t\t\t ---------------------------------------"<<endl;
            infile2>>sid>>fee_id>>year>>month>>fee_paid>>balance>>paid_date;
        }
        if(total == 0){
        	cout<<"---NO DATA FOUND---";
		}
        infile2.close();
    }
}

void exam :: exammenu()
{
	system("cls");
    menustart3:
    int choice;
    char x;
    cout<<"\t\t\t ---------------------------------------"<<endl;
    cout<<"\t\t\t|----------Exam Record System-----------|"<<endl;
    cout<<"\t\t\t ---------------------------------------"<<endl;
    cout<<"\t\t\t|-----------Exam Record Menu------------|"<<endl;
    cout<<"\t\t\t ---------------------------------------"<<endl;
    cout<<"\t\t\t| 1. Add Exam Record                    |"<<endl;
    cout<<"\t\t\t| 2. Check Exam Record                  |"<<endl;
    cout<<"\t\t\t| 3. Show All Exam Record               |"<<endl;
    cout<<"\t\t\t| 4. Exit                               |"<<endl;
    cout<<"\t\t\t ---------------------------------------"<<endl;
    cout<<"\t\t\t Choose option [1,2,3,4] "<<endl;
    cout<<"\t\t\t---------------------------------------"<<endl;
    cout<<"\t\t\t Enter your choice : ";
    cin>>choice;
    switch(choice){
        case 1:
            do {
            examrecord();
            cout<<"\t\t\t Do you want to add another Record (Y/N) : ";
            cin>>x;
            } while(x == 'Y' || x == 'y');
            break;
        case 2:
            searchstds();
            break;
        case 3:
            showallexam();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout<<"\t\t\t Invalid Choice"<<endl;
            break;
    }
        return;
        goto menustart3;
}

void exam :: examrecord()
{
    system("cls");
    fstream infile3;
    infile3.open("exam.txt", ios::app);
    if(!infile3){
        cout<<"\t\t\t File is not found"<<endl;
    }
    else {
    cout<<"\t\t\t ---------------------------------------"<<endl;
    cout<<"\t\t\t|----------Exam Record System-----------|"<<endl;
    cout<<"\t\t\t ---------------------------------------"<<endl;
    cout<<"\t\t\t|----------Enter Exam Records-----------|"<<endl;
    cout<<"\t\t\t ---------------------------------------"<<endl;

    cout<<"\t\t\t Enter the Student ID : ";
    cin>>sid;
    cout<<"\t\t\t Enter the Exam ID : ";
    cin>>eid;
    cout<<"\t\t\t Enter the Exam Date : ";
    cin>>examdate;
    cout<<"\t\t\t Enter the Months : ";
    cin>>months;
    cout<<"\t\t\t Enter the Year : ";
    cin>>year;
    cout<<"\t\t\t Enter the Subjects : ";
    cin>>subject;
    cout<<"\t\t\t Enter the Marks obtained : ";
    cin>>marksobtained;
    cout<<"\t\t\t Enter the Pass Marks : ";
    cin>>passmarks;
    cout<<"\t\t\t Enter the Result Status : ";
    cin>>resultstatus;

    infile3.open("fee.txt", ios::app | ios::out);
        if(!infile3){
            cout<<"\t\t\t Error in opening file"<<endl;
        }
        else{
            infile3<<sid<<" "<<eid<<" "<<examdate<<" "<<months<<" "<<year<<" "<<subject<<" "<<marksobtained<<" "<<passmarks<<" "<<resultstatus<<endl;
            cout<<"\t\t-----------Record is Saved Successfully---------------"<<endl;
        }
        infile3.close();
    }
}

void exam:: searchstds()
{
    system("cls");
    fstream infile3;
    infile3.open("exam.txt", ios::in);
    if(!infile3){
        cout<<"\t\t\t Data is not found"<<endl;
        infile3.close();
    }
    else {
        int found = 0;
        int stud_id;
        cout<<"\t\t\t ---------------------------------------"<<endl;
        cout<<"\t\t\t|----------Exam Record System-----------|"<<endl;
        cout<<"\t\t\t ---------------------------------------"<<endl;
        cout<<"\t\t\t|----------Search Exam Record-----------|"<<endl;
        cout<<"\t\t\t ---------------------------------------"<<endl;
        cout<<"\t\t\t Enter the Student ID : ";
        cin>>stud_id;
        while(!infile3.eof()){
            infile3>>sid>>eid>>examdate>>months>>year>>subject>>marksobtained>>passmarks>>resultstatus;
            if(stud_id == sid){
                found = 1;
                cout<<"\t\t\t ---------------------------------------"<<endl;
                cout<<"\t\t\t Student id : "<< sid << endl;
                cout<<"\t\t\t Exam id : "<< eid << endl;
                cout<<"\t\t\t Exam Date : "<< examdate << endl;
                cout<<"\t\t\t Months : "<< months << endl;
                cout<<"\t\t\t Year : "<< year << endl;
                cout<<"\t\t\t Subjects : "<< subject << endl;
                cout<<"\t\t\t Marks obtained : "<< marksobtained << endl;
                cout<<"\t\t\t Pass Marks : "<< passmarks << endl;
                cout<<"\t\t\t Result Status : "<< resultstatus << endl;
                 cout<<"\t\t\t ---------------------------------------"<<endl;
            }
        }
        if(found == 0){
            cout<<"\t\t\t Student id is not found "<<endl;
        }
        infile3.close();
    }
}

void exam:: showallexam()
{
    system("cls");
    fstream infile3;
    int totalexam = 1;

    infile3.open("exam.txt", ios::in);
    if(!infile3){
        cout<<"\t\t\t Data is not found"<<endl;
        infile3.close();
    }
    else {
        cout<<"\t\t\t ---------------------------------------"<<endl;
        cout<<"\t\t\t|----------Exam Record System-----------|"<<endl;
        cout<<"\t\t\t ---------------------------------------"<<endl;
        cout<<"\t\t\t|----------Show All Exam Record-----------|"<<endl;
        cout<<"\t\t\t ---------------------------------------"<<endl;
        infile3>>sid>>eid>>examdate>>months>>year>>subject>>marksobtained>>passmarks>>resultstatus;
        while(!infile3.eof()){
            cout<<"\t\t\t ---------------------------------------"<<endl;
            cout<<"\t\t\t Total exams : "<< totalexam++ << endl; 
            cout<<"\t\t\t Student id : "<< sid << endl;
            cout<<"\t\t\t Exam id : "<< eid << endl;
            cout<<"\t\t\t Exam Date : "<< examdate << endl;
            cout<<"\t\t\t Months : "<< months << endl;
            cout<<"\t\t\t Year : "<< year << endl;
            cout<<"\t\t\t Subjects : "<< subject << endl;
            cout<<"\t\t\t Marks obtained : "<< marksobtained << endl;
            cout<<"\t\t\t Pass Marks : "<< passmarks << endl;
            cout<<"\t\t\t Result Status : "<< resultstatus << endl;
             cout<<"\t\t\t ---------------------------------------"<<endl;
            infile3>>sid>>eid>>examdate>>months>>year>>subject>>marksobtained>>passmarks>>resultstatus;
        }
        if(totalexam = 0){
        	cout<<"---NO data Present---";
		}
        infile3.close();
    }
}

main()
{
	student stdsinfo;
	stdsinfo.menu();
   
}