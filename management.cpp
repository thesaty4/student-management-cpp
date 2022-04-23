#include<bits/stdc++.h>
using namespace std;
static int total_stu=0;
void _print_design();
class Student{
    int roll;
    string name,fname, dob,mobile,address;

    public:
        static int option();
        static int add_student(Student rec[]);
        static void show_record(Student rec[]);
        static void search_record(Student rec[]);
        static Student* edit_record(Student rec[]);
        static Student* delete_record(Student rec[]);
};
Student* Student::delete_record(Student rec[]){
    while(true){
        system("CLS");
        cout<<" ENTER ROLL NO. OF STUDENT for deletion : ";
        int n,flag=-1,i;cin>>n;
        for(i=0;i<total_stu;i++){
            if(rec[i].roll == n){
                flag=0;
                break;
            }
        }

        if(flag==-1){
            cout<<endl<<"+------------- Opps ! Record is not found -----------------+"<<endl;
            system("pause");
            continue;
        }else{
            for(int j=0,i=0;i<total_stu;i++,j++){
                if(rec[i].roll == n) continue;

                else{
                    rec[j]=rec[i];
                }
            }
            --total_stu;
            cout<<"+-------- Record Deleted Successfully --------+"<<endl;
        }
        break;
    }
    
    return rec;
}

Student* Student::edit_record(Student rec[]){
    while(true){
        system("CLS");
        cout<<" ENTER ROLL NO. OF STUDENT : ";
        int n,flag=-1,i;cin>>n;
        for(i=0;i<total_stu;i++){
            if(rec[i].roll == n){
                flag=0;
                break;
            }
        }

        if(flag==0){ //record found
            _print_design();
            cout<<i-1<<"    ";
            cout<<rec[i].roll<<"   ";
            cout<<rec[i].name<<"     ";
            cout<<rec[i].fname<<"\t";
            cout<<rec[i].mobile<<"   ";
            cout<<rec[i].dob<<"   ";
            cout<<rec[i].address<<"\n\n";
            cout<<"+----------------------| END |----------------------+"<<endl;

            // Lets Edit
            cout<<endl;
            cout<<" +----------------------------------------------+"<<endl;
            cout<<" |      ENTER "<<n<<" STUDENT UPDATE RECORD     | "<<endl;
            cout<<" +----------------------------------------------+"<<endl;
            cout<<"Enter student roll number in  format(1XXX): ";
            cin>>rec[i].roll;
            cout<<"Enter student name: ";
            cin>>rec[i].name;
            cout<<"Enter student's Father name: ";
            cin>>rec[i].fname;
            cout<<"Enter student's Mobile phone number: ";
            cin>>rec[i].mobile;
            cout<<"Enter student's Date of Birth(dd/mm/yyyy): ";
            cin>>rec[i].dob;
            cout<<"Enter student's Address: ";
            cin>>rec[i].address;
            cout<<endl;

            cout<<"+--------| Record Updated Successfully |--------+"<<endl;

            return rec;
        }else{
            cout<<"+-------- Oops ! Invalid ROLL No. --------+"<<endl;
            system("pause");
            continue;
        }
        break;
    }
    return rec;
}

int main(){
    int opt,status;
    Student* record = new Student[50];

    while(true){
        system("CLS");
        cout<<endl<<"+-------------------------------------------------------+"<<endl;
        cout<<"| \t STUDENT MANAGEMENT SYSTEM \t\t\t|"<<endl;
        cout<<"+-------------------------------------------------------+"<<endl;
        opt = Student::option();
        switch(opt){
            case 1: // add student
                status=Student::add_student(record);
                if(status==0){
                    cout<<"+-------- Record Added Successfully --------+"<<endl;
                    system("pause");
                    continue;
                } else{
                    cout<<"+-------- Oops ! Somthing went wrong --------+"<<endl;
                    system("pause");
                    continue;
                }
            break;

            case 2: // show record
                Student::show_record(record);
                system("pause");
                continue;
            break;

            case 3: //edit student
                record=Student::edit_record(record);
                system("pause");
                continue;
            break;

            case 4: //search program
                record=Student::delete_record(record);
                system("pause");
                continue;
            break;

            case 5: //search program
                Student::search_record(record);
                system("pause");
                continue;
            break;

            case 6: //quit program
                system("pause");
                exit(1);
            break;

            default:
            system("CLS");
            cout<<endl<<"Invalid Input..."<<endl;
            continue;
        }

        break;
    }

    free(record);
    return 0;
}

void _print_design(){
            cout<<"--------------------------------------------------------------------------------"<<endl;
            cout<<"---------------------------Student record Table---------------------------------"<<endl;
            cout<<"--------------------------------------------------------------------------------"<<endl; 
            cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tCell no.      "<<"DOB          "<<"Address\n\n";
            cout<<"--------------------------------------------------------------------------------"<<endl; 
}

void Student::search_record(Student rec[]){
    system("CLS");
    int key,flag=-1;
    cout<<" Enter the Roll no. of student : ";cin>>key;
    for(int i=0;i<total_stu;i++){
        if(rec[i].roll==key){
            flag=0;
            cout<<endl;
            _print_design();
            cout<<i<<"    ";
            cout<<rec[i].roll<<"   ";
            cout<<rec[i].name<<"     ";
            cout<<rec[i].fname<<"\t";
            cout<<rec[i].mobile<<"   ";
            cout<<rec[i].dob<<"   ";
            cout<<rec[i].address<<"\n\n";
            break;
        }
    }

    if(flag==-1){
        cout<<"                         ________________________"<<endl;
        cout<<"+-----------------------| Opps ! No Record Found |-----------------------+"<<endl;
    }
}


void Student::show_record(Student rec[]){
    system("CLS");
    cout<<endl;
    cout<<"+--------------------------------------------------------------------------------+"<<endl;
    cout<<"|--------------------------| Student record Table |------------------------------|"<<endl;
    cout<<"+--------------------------------------------------------------------------------+"<<endl;
    cout<<" ID   "<<"Roll   "<<"Name      "<<"Father\tMobile no.      "<<"DOB          "<<"Address\n\n";
    cout<<"+--------------------------------------------------------------------------------+"<<endl;
    for(int i=0;i<total_stu;i++){        //Loop was processed for 5 times to show obtained records.
        cout<<i<<"    ";
        cout<<rec[i].roll<<"   ";
        cout<<rec[i].name<<"     ";
        cout<<rec[i].fname<<"\t";
        cout<<rec[i].mobile<<"   ";
        cout<<rec[i].dob<<"   \t";
        cout<<rec[i].address<<"\n\n";
    }
    cout<<"+------------------------------------END-----------------------------------------+"<<endl;
}



/* ADD FUNCTION RETURN THE SOME VALUE WHICH IS THE
-1 : Not enough Space
 0  : Successfull

*/
int Student::add_student(Student rec[]){
    int n;
    while(true){
        system("CLS");
        cout<<" Enter the total student want add [MAX 50] : ";cin>>n;
        if(n+total_stu>50){
            cout<<" You have only "<<50-total_stu<<" Space Available "<<endl;
            system("pause");
            continue;
        }else{

            int k=1;
            for(int i=total_stu;i<total_stu+n;i++){
                system("CLS");
                cout<<endl<<" +----------------------------------------+"<<endl;
                cout<<" |         ENTER "<<k++<<" STUDENT RECORD         | "<<endl;
                cout<<" +----------------------------------------+"<<endl;
                cout<<"Enter student roll number in  format(1XXX): ";
                cin>>rec[i].roll;
                cout<<"Enter student name: ";
                cin>>rec[i].name;
                cout<<"Enter student's Father name: ";
                cin>>rec[i].fname;
                cout<<"Enter student's Mobile phone number: ";
                cin>>rec[i].mobile;
                cout<<"Enter student's Date of Birth(dd/mm/yyyy): ";
                cin>>rec[i].dob;
                cout<<"Enter student's Address: ";
                cin>>rec[i].address;
                cout<<endl;
            }
            total_stu+=n;
            return 0;
        }

        break;
    }
}


int Student::option(){
    cout<<"\n\t\tWhat do you want to do?"<<endl;
    cout<<"\t\t----------------------"<<endl;
    cout<<"\t\t1-Add student"<<endl;
    cout<<"\t\t2-Show Record"<<endl;
    cout<<"\t\t3-Edit student"<<endl;
    cout<<"\t\t4-Delete student"<<endl;
    cout<<"\t\t5-Search student"<<endl;
    cout<<"\t\t6-Quit Program"<<endl;
    cout<<"\t\t----------------------"<<endl;
    cout<<"Enter your choice: ";
    
    int c;cin>>c;
    return c;
}

