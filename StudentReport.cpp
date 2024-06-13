#include <iostream>
#include <conio.h>
#include <fstream>
#include<string.h>
//#include <Windows.h>

using namespace std;

class student
{
    string name; string roll; string grade; float Cpp, DAA, Mathematics, ECE, Python, Economics, ISES, ISCP, avg;
    public:
        void menu();
        void add();
        void display_all();
        void display_one();
        void modify();
        void Delete();
        string Grade(float avg);
};

void student::menu()
{
    char x;
    int choice,ch;
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout << "\t\t\t\t\t\t\t\t\t\t **************" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t * SRM Student Report Management System *" <<endl;
    cout << "\t\t\t\t\t\t\t\t\t\t **************\n"<< endl;
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t Press any key to continue ";
    getch();
    do
    {
        system("cls");
        system("color E1");
        cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t\t\t 1. Enter New Record" << endl<<endl;
        cout << "\t\t\t\t\t\t\t\t\t\t 2. Display All Records" << endl<< endl;
        cout << "\t\t\t\t\t\t\t\t\t\t 3. Display Particular Record" <<endl<< endl;
        cout << "\t\t\t\t\t\t\t\t\t\t 4. Modify Record" << endl<< endl;
        cout << "\t\t\t\t\t\t\t\t\t\t 5. Delete Record" << endl<< endl;
        cout << "\t\t\t\t\t\t\t\t\t\t 6. Exit" << endl<< endl;
        cout << "\t\t\t\t\t\t\t\t\t\t Choose any one of the options : ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                add();
                cout<<"\n\n\t\t\t\t\t\t\t\t\t\t Record added successfully!"<<endl;
                cout<<"\n\t\t\t\t\t\t\t\t\t\tPress any key to continue";
                getch();
                break;
            case 2:
                display_all();
                break;
            case 3:
                display_one();
                break;
            case 4:
                modify();
                break;
            case 5:
                Delete();
                break;
            case 6:
                break;
                default:
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\tINVALID CHOICE!" << endl;
                cout<<"\t\t\t\t\t\t\t\t\t\tPress any key to continue!";
                getch();
                break;
        }
    } while(choice!=6);
}

void student::add()
{
    ofstream file;
    system("cls");
    system("color 5F");
    cout << "\t\t\t\t\t\t**************************"<<endl;
    cout << "\t\t\t\t\t\t* *"<<endl;
    cout << "\t\t\t\t\t\t* Add Student Record *"<<endl;
    cout << "\t\t\t\t\t\t* *"<<endl;
    cout << "\t\t\t\t\t\t**************************"<<endl<<endl<<endl;
    cout << "\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
    cout << "\t\t\t\t\t\tEnter name of the Student : ";
    getline(cin,name);
    getline(cin,name);
    cout << "\n\t\t\t\t\t\tEnter Roll number of the Student : ";
    getline(cin,roll);
    cout << "\n\t\t\t\t\t\tEnter the marks of C++ out of 100: ";
    cin >> Cpp;
    if(Cpp<0 || Cpp>100)
    {
        cout<<"\n\t\t\t\t\t\tPlease enter the correct marks!"<<endl;
        cin>>Cpp;
    }
    cout << "\n\t\t\t\t\t\tEnter the marks of DAA out of 100: ";
    cin >> DAA;
    if(DAA<0 || DAA>100)
    {
        cout<<"\n\t\t\t\t\t\tPlease enter the correct marks!"<<endl;
        cin>>DAA;
    }
    cout << "\n\t\t\t\t\t\tEnter the marks of Mathematics out of 100: ";
    cin >> Mathematics;
    if(Mathematics<0 && Mathematics>100)
    {
        cout<<"\n\t\t\t\t\t\tPlease enter the correct marks!"<<endl;
        cin>>Mathematics;
    }
    cout << "\n\t\t\t\t\t\tEnter the marks of ECE out of 100: ";
    cin >> ECE;
    if(ECE<0 || ECE>100)
    {
        cout<<"\n\t\t\t\t\t\tPlease enter the correct marks!"<<endl;
        cin>>ECE;
    }
    cout << "\n\t\t\t\t\t\tEnter the marks of Python out of 100: ";
    cin >> Python;
    if(Python<0 || Python>100)
    {
        cout<<"\n\t\t\t\t\t\tPlease enter the correct marks!"<<endl;
        cin>>Python;
    }
    cout << "\n\t\t\t\t\t\tEnter the marks of Economics out of 100: ";
    cin >> Economics;
    if(Economics<0 || Economics>100)
    {
        cout<<"\n\t\t\t\t\t\tPlease enter the correct marks!"<<endl;
        cin>>Economics;
    }
    cout << "\n\t\t\t\t\t\tEnter the marks of ISES out of 100: ";
    cin >> ISES;
    if(ISES<0 || ISES>100)
    {
        cout<<"\n\t\t\t\t\t\tPlease enter the correct marks!"<<endl;
        cin>>ISES;
    }
    cout << "\n\t\t\t\t\t\tEnter the marks of ISCP out of 100: ";
    cin >> ISCP;
    if(ISCP<0 || ISCP>100)
    {
        cout<<"\n\t\t\t\t\t\tPlease enter the correct marks!"<<endl;
        cin>>ISCP;
    }
    avg = (Cpp + DAA + Mathematics + ECE + Python + Economics + ISES + ISCP ) / 8;
    cout << "\n\t\t\t\t\t\tAverage of the marks is : " << avg << endl;
    grade=Grade(avg);
    cout<<"\n\t\t\t\t\t\tGrade is : "<<grade<<endl;
    file.open("Student.txt", ios::app | ios::out);
    file << name << " " << roll << " " << Cpp << " " << DAA << " " << Mathematics << " " << ECE << " " << Python << " " << Economics << " " << ISES << " " << ISCP << " " <<avg << " "<< grade<<endl;
    file.close();
}

void student::display_all()
{
    fstream file;
    string name,roll,Cpp,DAA,Mathematics,ECE,Python,Economics,ISES,ISCP,avg,grade;
    system("cls");
    system("color 1E");
    file.open("Student.txt", ios::in);
    if (!file)
    {
        cout << "\t\t\t\t\t\t\t\t\tNo Data Is Present...";
        file.close();
    }
    else
    {
        //system("cls");
        cout << "\t\t\t\t\t\t**************************"<<endl;
        cout << "\t\t\t\t\t\t* *"<<endl;
        cout << "\t\t\t\t\t\t* Student Record Display*"<<endl;
        cout << "\t\t\t\t\t\t* *"<<endl;
        cout << "\t\t\t\t\t\t**************************"<<endl<<endl<<endl;
        file >> name >> roll >> Cpp >> DAA >> Mathematics >> ECE >> Python >> Economics >> ISES >> ISCP>>avg>>grade;
        while (!file.eof())
        {
            cout<<"\n\n";
            cout << "\t\t\t\t\t\tName : " << name <<endl;
            cout << "\n\t\t\t\t\t\tRoll number : " << roll<<endl;
            cout << "\n\t\t\t\t\t\tC++ : " << Cpp <<endl;
            cout << "\n\t\t\t\t\t\tDAA : " << DAA <<endl;
            cout << "\n\t\t\t\t\t\tMATHEMATICS : " << Mathematics<<endl ;
            cout << "\n\t\t\t\t\t\tECE : " << ECE <<endl;
            cout << "\n\t\t\t\t\t\tPYTHON : " << Python<<endl;
            cout << "\n\t\t\t\t\t\tECONOMICS : " << Economics <<endl;
            cout << "\n\t\t\t\t\t\tISES : " << ISES <<endl;
            cout << "\n\t\t\t\t\t\tISCP : " << ISCP <<endl;
            cout << "\n\t\t\t\t\t\tAverage is : " << avg <<endl;
            cout << "\n\t\t\t\t\t\tGrade is : " << grade <<endl<<endl<<endl;
            cout << "\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
            file >> name >> roll >> Cpp >> DAA >> Mathematics >> ECE >> Python >> Economics >> ISES >> ISCP>>avg>>grade;
        }
    }
    cout<<"\t\t\t\t\t\tPress any key to continue";
    getch();
    file.close();
}

void student::modify()
{
    fstream file, file1;
    string rollno, n_name, n_rollno,n_grade;
    int edit,edit1, n_Cpp, n_DAA, n_Mathematics, n_ECE, n_Python, n_Economics,
    n_ISES, n_ISCP,n_avg,found=0;
    system("cls");
    system("color 2F");
    cout << "\t\t\t\t\t\t\t\t\t**************************"<<endl;
    cout << "\t\t\t\t\t\t\t\t\t* *"<<endl;
    cout << "\t\t\t\t\t\t\t\t\t* Edit Student Record*"<<endl;
    cout << "\t\t\t\t\t\t\t\t\t* *"<<endl;
    cout << "\t\t\t\t\t\t\t\t\t**************************"<<endl<<endl<<endl;
    file.open("Student.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t\t\t\t\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\n\n\n\n\t\t\t\t\t\t\t\t\tEnter Roll Number of the Student which you want to Modify: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll >> Cpp >> DAA >> Mathematics >> ECE >> Python >>
        Economics >> ISES >> ISCP >> avg>>grade;
        while (!file.eof())
        {
            if(rollno==roll)
            {
                found=1;
                do
                {
                    cout << "\n\t\t\t\t\t\t\t\t\t1. Name"<<endl;
                    cout << "\n\t\t\t\t\t\t\t\t\t2. Roll number" <<endl;
                    cout << "\n\t\t\t\t\t\t\t\t\t3. Cpp"<<endl;
                    cout << "\n\t\t\t\t\t\t\t\t\t4. DAA"<<endl;
                    cout << "\n\t\t\t\t\t\t\t\t\t5. Mathematics"<<endl;
                    cout << "\n\t\t\t\t\t\t\t\t\t6. ECE"<<endl;
                    cout << "\n\t\t\t\t\t\t\t\t\t7. Python"<<endl;
                    cout << "\n\t\t\t\t\t\t\t\t\t8. Economics"<<endl;
                    cout << "\n\t\t\t\t\t\t\t\t\t9. ISES"<<endl;
                    cout << "\n\t\t\t\t\t\t\t\t\t10. ISCP"<<endl;
                    cout << "\n\n\t\t\t\t\t\t\t\t\tEnter which of these you want to edit: ";
                    cin >> edit;
                    if(edit>0 && edit<11)
                    {
                        switch (edit)
                        {
                            case 1:
                                cout << "\n\t\t\t\t\t\t\t\t\tEnter the new name : ";
                                getline(cin, n_name);
                                getline(cin, n_name);
                                name = n_name;
                                cout << "\n\t\t\t\t\t\t\t\t\tName changed successfully" <<endl;
                                break;
                            case 2:
                                cout << "\n\t\t\t\t\t\t\t\t\tEnter the new Roll number of the student : ";
                                cin >> n_rollno;
                                rollno = n_rollno;
                                cout << "\n\t\t\t\t\t\t\t\t\tRoll number changed successfully" << endl;
                                break;
                            case 3:
                                cout << "\n\t\t\t\t\t\t\t\t\tEnter the new marks of cpp : ";
                                cin >> n_Cpp;
                                Cpp = n_Cpp;
                                cout << "\n\t\t\t\t\t\t\t\t\tMarks of CPP changed successfully" << endl;
                                break;
                            case 4:
                                cout << "\n\t\t\t\t\t\t\t\t\tEnter the new marks of DAA : " ;
                                cin >> n_DAA;
                                DAA = n_DAA;
                                cout << "\n\t\t\t\t\t\t\t\t\tMarks of DAA changed successfully" << endl;
                                break;
                            case 5:
                                cout << "\n\t\t\t\t\t\t\t\t\tEnter the new marks of Mathematics : ";
                                cin >> n_Mathematics;
                                Mathematics = n_Mathematics;
                                cout << "\n\t\t\t\t\t\t\t\t\tMarks of Mathematics changed successfully" << endl;
                                break;
                            case 6:
                                cout << "\n\t\t\t\t\t\t\t\t\tEnter the new marks of ECE : ";
                                cin >> n_ECE;
                                ECE = n_ECE;
                                cout << "\n\t\t\t\t\t\t\t\t\tMarks of ECE changed successfully" << endl;
                                break;
                            case 7:
                                cout << "\n\t\t\t\t\t\t\t\t\tEnter the new marks of Python : ";
                                cin >> n_Python;
                                Cpp = n_Python;
                                cout << "\n\t\t\t\t\t\t\t\t\tMarks of Python changed successfully" << endl;
                                break;
                            case 8:
                                cout << "\n\t\t\t\t\t\t\t\t\tEnter the new marks of Economics : ";
                                cin >> n_Economics;
                                Economics = n_Economics;
                                cout << "\n\t\t\t\t\t\t\t\t\tMarks of Economics changed successfully" << endl;
                                break;
                            case 9:
                                cout << "\n\t\t\t\t\t\t\t\t\tEnter the new marks of ISES : ";
                                cin >> n_ISES;
                                ISES = n_ISES;
                                cout << "\n\t\t\t\t\t\t\t\t\tMarks of ISES changed successfully" << endl;
                                break;
                            case 10:
                                cout << "\n\t\t\t\t\t\t\t\t\tEnter the new marks of ISCP : ";
                                cin >> n_ISCP;
                                ISCP = n_ISCP;
                                cout << "\n\t\t\t\t\t\t\t\t\tMarks of ISCP changed successfully" << endl;
                                break;
                            default:
                                break;
                        }
                    }
                    avg=(Cpp + DAA + Mathematics + ECE + Python + Economics + ISES + ISCP)/8;
                    cout<<"\n\t\t\t\t\t\t\t\t\tNew Average is : " <<avg<<endl;
                    grade=Grade(avg);
                    cout<<"\n\t\t\t\t\t\t\t\t\t0. Exit from edit\n\n\t\t\t\t\t\t\t\t\t1. Edit again\n\n\n\t\t\t\t\t\t\t\t\tSelect any one: ";
                    cin>>edit1;
                    if(edit==1)
                    {
                        system("cls");
                        file1 << name << " " << roll << " " << Cpp << " " << DAA << " " << Mathematics << " " << ECE << " " << Python << " " << Economics << " " << ISES << " " << ISCP<<" "<<avg<<" "<<grade<<endl;
                    }
                } while (edit1!=0);
            }
            file >> name >> roll >> Cpp >> DAA >> Mathematics >> ECE >> Python >>
            Economics >> ISES >> ISCP>>avg>>grade;
        }
        if(found==0)
        {
            cout<<"\n\n\t\t\t\t\t\t\t\t\tRecord not found!"<<endl;
            cout<<"\n\n\t\t\t\t\t\t\t\t\tPress any key to continue";
            getch();
        }
        file1.close();
        file.close();
        remove("Student.txt");
        rename("record.txt", "Student.txt");
    }
}

void student::Delete()
{
    fstream file, file1;
    int found = 0;
    string s_roll;
    system("cls");
    system("color F8");
    cout << "\t\t\t\t\t\t\t\t\t**************************"<<endl;
    cout << "\t\t\t\t\t\t\t\t\t**"<<endl;
    cout << "\t\t\t\t\t\t\t\t\t* Delete Student Record*"<<endl;
    cout << "\t\t\t\t\t\t\t\t\t**"<<endl;
    cout << "\t\t\t\t\t\t\t\t\t**************************"<<endl<<endl<<endl;
    file.open("Student.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t\t\t\t\t\t\tNo Data is Present..";
        cout<<"Press any key to continue!"<<endl;
        getch();
        file.close();
    }
    else
    {
        cout << "\n\t\t\t\t\t\t\t\t\tEnter Roll No. of Student which you want Delete Data: ";
        cin >> s_roll;
        file1.open("record.txt", ios::out);
        file >> name >> roll >> Cpp >> DAA >> Mathematics >> ECE >> Python >> Economics >> ISES >> ISCP>>avg>>grade;
        while (!file.eof())
        {
            if (s_roll != roll)
            {
                file1 << name << " " << roll << " " << Cpp << " " << DAA << " " << Mathematics << " " << ECE << " " << Python << " " << Economics << " " << ISES << " " << ISCP << " " << avg <<" "<<grade<< endl;
            }
            else
            {
                found++;
                cout << "\n\t\t\t\t\t\t\t\t\tData successfully deleted";
            }
            file >> name >> roll >> Cpp >> DAA >> Mathematics >> ECE >> Python >> Economics >> ISES >> ISCP>>avg>>grade;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\tStudent Roll Number Not Found....";
            cout << "\n\n\t\t\t\t\t\t\t\t\tPress any key to continue";
            getch();
        }
        file1.close();
        file.close();
        remove("Student.txt");
        rename("record.txt", "Student.txt");
    }
}

void student :: display_one()
{
    fstream file;
    int found=0;
    file.open("Student.txt",ios::in);
    if(!file)
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tThe file is empty!"<<endl;
    }
    else
    {
        string o_rollno;
        system("cls");
        system("color 1E");
        cout << "\t\t\t\t\t\t\t\t\t**************************"<<endl;
        cout << "\t\t\t\t\t\t\t\t\t**"<<endl;
        cout << "\t\t\t\t\t\t\t\t\t* Student Record Display*"<<endl;
        cout << "\t\t\t\t\t\t\t\t\t**"<<endl;
        cout << "\t\t\t\t\t\t\t\t\t**************************"<<endl<<endl<<endl;
        cout << "\n\n\n\n\t\t\t\t\t\t\t\t\tEnter Roll No. of Student Which You Want to Search: ";
        cin >> o_rollno;
        file >> name >> roll >> Cpp >> DAA >> Mathematics >> ECE >> Python >> Economics >> ISES >> ISCP>>avg>>grade;
        while (!file.eof())
        {
            if (o_rollno == roll)
            {
                cout << "\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~"<<endl<<endl;
                cout << "\n\t\t\t\t\t\t\t\t\tName : " << name << endl;
                cout << "\n\t\t\t\t\t\t\t\t\tRoll : " << roll << endl;
                cout << "\n\t\t\t\t\t\t\t\t\tC++ : " << Cpp << endl;
                cout << "\n\t\t\t\t\t\t\t\t\tDAA : " << DAA << endl;
                cout << "\n\t\t\t\t\t\t\t\t\tMATHEMATICS : " << Mathematics << endl;
                cout << "\n\t\t\t\t\t\t\t\t\tECE : " << ECE << endl;
                cout << "\n\t\t\t\t\t\t\t\t\tPYTHON : " << Python << endl;
                cout << "\n\t\t\t\t\t\t\t\t\tECONOMICS : " << Economics << endl;
                cout << "\n\t\t\t\t\t\t\t\t\tISES : " << ISES << endl;
                cout << "\n\t\t\t\t\t\t\t\t\tISCP : " << ISCP << endl;
                cout << "\n\t\t\t\t\t\t\t\t\tAverage is : " << avg << endl;
                cout << "\n\t\t\t\t\t\t\t\t\tGrade is : "<<grade<<endl<<endl<<endl<<endl;
                cout << "\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~"<<endl<<endl;
                found++;
                cout<<"\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue!"<<endl;
                getch();
                break;
            }
            file >> name >> roll >> Cpp >> DAA >> Mathematics >> ECE >> Python >> Economics >> ISES >> ISCP >>avg>>grade;
        }
        if(found==0)
        {
            cout<<"\n\n\t\t\t\t\t\t\t\t\tNo record found!\n";
            cout<<"\n\t\t\t\t\t\t\t\t\tPress any key to continue";
            getch();
        }
    }
}

string student :: Grade(float avg)
{
    if(avg>=90)
    {
        grade="O";
    }
    else if(avg>=80&&avg<90)
    {
        grade="A";
    }
    else if(avg>=70&&avg<80)
    {
        grade="B";
    }
    else if(avg>=60&&avg<70)
    {
        grade="C";
    }
    else
    {
        grade="Fail";
    }
    return grade;
}

int main()
{
    //loadingBar();
    student project;
    project.menu();
    return 0;
}