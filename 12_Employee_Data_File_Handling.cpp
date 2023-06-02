/*
Company maintains employee information as employee ID, name, designation and salary.
Allow user to add, delete information of employee. Display information of particular employee.
If employee does not exist an appropriate message is displayed.
If it is, then the system displays the employee details. Use index sequential file to maintain the data.
*/

#include <bits/stdc++.h>
using namespace std;
class Employee
{

    private:
        int code;
        char name[20];
        float salary;

    public:
        void read();
        void display();

};

void Employee::read()
{
    cout << "Enter employee code: ";
    cin >> code;
    cout << "Enter name: ";
    cin.ignore(1);
    cin.getline(name, 20);
    cout << "Enter salary: ";
    cin >> salary;
}

void Employee::display()
{
    cout << code << " " << name << "\t" << salary << endl;
}

fstream file;
void deleteExistingFile()
{
    remove("EMPLOYEE.DAT");
}

void appendToFille()
{
    Employee x;
    x.read();
    file.open("EMPLOYEE.DAT", ios::binary | ios::app);
    if (!file)
    {
        cout << "ERROR IN CREATING FILE\n";
        return;
    }
    file.write((char *)&x, sizeof(x));
    file.close();
    cout << "Record added sucessfully.\n";
}

void displayAll()
{
    Employee x;
    file.open("EMPLOYEE.DAT", ios::binary | ios::in);
    if (!file)
    {
        cout << "ERROR IN OPENING FILE \n";
        return;
    }
    while (file)
    {
        if (file.read((char *)&x, sizeof(x)))
            if (x.getSalary() >= 10000 && x.getSalary() <= 200000)
                x.display();
    }
    file.close();
}

void searchForRecord()
{
    Employee x;
    int c;
    int isFound = 0;
    cout << "Enter employee code: ";
    cin >> c;
    file.open("EMPLOYEE.DAT", ios::binary | ios::in);
    if (!file)
    {
        cout << "ERROR IN OPENING FILE \n";
        return;
    }
    while (file)
    {
        if (file.read((char *)&x, sizeof(x)))
        {
            if (x.getEmpCode() == c)
            {
                cout << "RECORD FOUND\n";
                x.display();
                isFound = 1;
                break;
            }
        }
    }
    if (isFound == 0)
    {
        cout << "Record not found!!!\n";
    }
    file.close();
}

int main()
{
    char ch;
    deleteExistingFile();
    do
    {
        int n;
        cout << "\n1.ADD AN EMPLOYEE\n2.DISPLAY\n3.SEARCH\nENTER YOUR CHOICE: ";
        cin >> n;
        switch (n)
        {
        case 1:
            appendToFille();
            break;
        case 2:
            displayAll();
            break;
        case 3:
            searchForRecord();
            break;
        default:
            cout << "Invalid Choice\n";
        }
        cout << "Do you want to continue?(y/n) : ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}