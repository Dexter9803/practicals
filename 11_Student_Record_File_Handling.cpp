#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Student
{
    string name, add, rn;
    char div;
    fstream f;

    public:
    void addStudent()
    {
        fstream f("stud.txt", ios::app);

        cout<<"Enter Roll no of Student: ";
        cin>>rn;
        cout<<"Enter name of student: ";
        cin>>name;
        cout<<"Enter division of student: ";
        cin>>div;
        cout<<"Enter address of student: ";
        cin>>add;

        f<<rn<<setw(20)<<name<<setw(20)<<div<<setw(20)<<add<<endl;
        cout<<"RECOIRD ADDED SUCCESSFULLY"<<endl;
        f.close();
    }

    void deleteStudent()
    {
        cout<<"Enter roll no of student to delete: ";
        cin>>rn;
        string line;
        string data;
        ifstream f("stud.txt");

        while(getline(f,line))
        {   
            if(line.find(rn) == string :: npos)
            {
                data += line;
                data += "\n";
            }

        }

        ofstream f1("stud.txt", ios::out);
        f1<<data;
        f1.close();
        cout<<"RECOIRD DELETED SUCCESSFULLY"<<endl;
    }

    void searchStudent()
    {
        cout<<"Enter roll no of student to search: ";
        cin>>rn;
        string line;
        bool found = false;

        ifstream f("stud.txt");

        while(getline(f, line))
        {
            if(line.find(rn) != string :: npos)
            {
                found = true;
                cout<<"Student Details: "<<line<<endl;
                break;
            }
        }
        if(!found)
        {
            cout<<"Student Does not exist";
        }
        f.close();
    }

    void printStudent()
    {
        ifstream f("stud.txt");
        string line;

        cout<<"PRINTING DATA: "<<endl;

        while(getline(f, line))
        {
            cout<<line<<endl;
        }

        cout<<"RECORD DISPLAYED SUCCESSFULLY";

    }
};

int main()
{
ofstream f("stud.txt", ios::out);
	f<<"ROLL NO."<<setw(20)<<"NAME"<<setw(20)<<"DIVISION"<<setw(20)<<"ADDRESS"<<endl;
	f.close();
	
	Student s;
	int ch;
	while(1)
	{
		cout<<"\n\n1.ADD STUDENT\n2.DELETE STUDENT\n3.SEARCH STUDENT\n4.PRINT DATA\n5.EXIT"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				s.addStudent();
				break;
			case 2: 
				s.deleteStudent();
				break;
			case 3:
				s.searchStudent();
				break;
			case 4: 
				s.printStudent();
				break;
			case 5:
				exit(1);
			default:
				cout<<"Incorrect choice. Please enter a valid choice."<<endl;
				break;
		}
	}
}
