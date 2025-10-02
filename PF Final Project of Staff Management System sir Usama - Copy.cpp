#include<iostream>
#include<string>
using namespace std;
struct Employee {
    int ID;
    string name;
    string position;
    float salary;

    string attendance;
    string P;
    string A;
    void printEmployee();
    void addEmployee();
    void markAttendance(int ID);
};
string attendance[1] = {};
struct Leave {
    int ID;
    string name;
    string reason;
    void Request();
    void showRequest();
};

Leave leave[1] = {};
int Count = 0;
void deleteEmployee();
Employee employees[4] = { {1, "Ali", "developer",50000}, {2, "Ahmed", "manager",78999} };
int Counter = 2;
void deleteByID(int ID);
void profileByID(int ID);
int main() {
    int AdminPassword = 0;
    int UserPassword = 0;
    int choice = 0;
    int choice2 = 0;

    do {
        cout << "*** Welcome to Staff Management System ***" << endl;
        cout << "1- Administrator" << endl;
        cout << "2- End User" << endl;
        cout << "3- Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        int choice3 = 0;
        switch (choice) {
        case 1: {
            cout << "Enter Your Password: ";
            cin >> AdminPassword;
            if (AdminPassword == 123) {
                cout << "Congratulations, you are successfully logged in" << endl;
                do {
                    cout << "1- Add Employee" << endl;
                    cout << "2- Delete Employee" << endl;
                    cout << "3- View All Employees" << endl;
                    cout << "4- Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice2;
                    switch (choice2) {
                    case 1:
                        employees[0].addEmployee();
                        cout << "New Employee successfully added" << endl;
                        break;
                    case 2:
                        int ID;
                        cout << "Enter his id: ";
                        cin >> ID;
                        deleteByID(ID);
                        cout << "Employee successfully deleted" << endl;
                        break;
                    case 3:

                        cout << "All Employees are:" << endl;

                        employees[0].printEmployee();
                        break;
                    case 4:
                        cout << "Exit" << endl;
                        break;
                    default:
                        cout << "Wrong choice" << endl;
                        break;
                    }
                    cout << "Enter 4 for logout anything else for continue:";
                    cin >> choice3;
                } while (choice3 != 4);


            }
            else {
                cout << "Incorrect password" << endl;
            }
            break;
        }
        case 2: {
            cout << "Enter Your Password: ";
            cin >> UserPassword;
            if (UserPassword == 1234) {
                cout << "Congratulations, you are successfully logged in" << endl;
                do {
                    cout << "\nUser Menu:" << endl;
                    cout << "1 - View Profile" << endl;
                    cout << "2 - Request Leave" << endl;
                    cout << "3 - Mark Attendance" << endl;
                    cout << "4 - Logout" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                    case 1:
                      
                        int ID;
                        cout << "Enter your id: ";
                        cin >> ID;
                        cout << "Your profile:" << endl;
                        profileByID(ID);
                        break;
                    case 2:
                       leave[0].Request();
                          cout << "Your leave request has been submitted!" << endl;
                        break;
                    case 3:
                     
                        cout << "Enter your id: ";
                        cin >> ID;
                        employees[0].markAttendance(ID);
                        cout << "You are present"<<endl;
                        cout << "Your attendance has been marked successfully!" << endl;
                        break;
                    case 4:
                        cout << "logout";
                    }
                    cout << "Enter 4 for logout anything else for continue";
                    cin >> choice;

                } while (choice != 4);
            }
            else {
                cout << "Incorrect password" << endl;
            }
            break;
        }
        case 3:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice, please try again" << endl;
            break;
        }
        {
            cout << "Enter 3 for exit anything else for continue" << endl;

        }
    } while (choice != 3);

    return 0;


}
void Employee::addEmployee() {
    cout << "Enter id of employee: ";
    cin >> employees[Counter].ID;
    cout << "Enter name of employee: ";
    cin.ignore();
    getline(cin,employees[Counter].name);
    cout << "Enter position of employee: ";
    cin.ignore();
   getline(cin,employees[Counter].position);
    cout << "Enter salary of employee: ";
    cin >> employees[Counter].salary;
    Counter = Counter + 1;

};
void Employee::printEmployee()
{
    for (int i = 0; i <Counter; i++) {
        cout << "id:" << employees[i].ID << endl;
        cout << "name:" << employees[i].name << endl;
        cout << "position:" << employees[i].position << endl;
        cout << "salary:" << employees[i].salary << endl;
    }
};
void deleteByID(int ID)
{
    for (int i = 0;i < Counter;i++)
    {
        if (employees[i].ID == ID) {

            employees[i].ID = 0;
            employees[i].name = "";
            employees[i].position = "";
            employees[i].salary = 0;
        }
    }
};
void profileByID(int ID)
{
    for (int i = 0;i < Counter;i++)
    {
        if (employees[i].ID == ID) {
          

            cout << employees[i].ID << endl;
            cout << employees[i].name << endl;
            cout << employees[i].position << endl;
            cout << employees[i].salary << endl;
        }

    }
};

void Leave::Request()
{

    cout << "My ID is:";
    cin >> leave[Count].ID;
    cout << "My name is:";
    cin.ignore();
    getline(cin,leave[Count].name);
    cout << "Reason of leave is:";
    getline(cin, leave[Count].reason);
    cin.ignore();
    showRequest();
};
void Leave::showRequest()
{
    for (int i = 0;i < Counter;i++)
    {
        cout << leave[Count].ID<<endl;
        cout << leave[Count].name << endl;
        cout << leave[Count].reason << endl;
    }
}; 
void Employee::markAttendance(int ID)
{
    for (int i = 0;i < Counter;i++)
    {
        if (employees[i].ID == ID) {

            cout << employees[i].ID << endl;
            cout << employees[i].name << endl;
            cout << employees[i].position << endl;
            cout << employees[i].salary << endl;

        }
          }
    cout << "Enter P for present and A for absent:"<<endl;
    cin >> attendance;
    if (attendance == P) {
        cout << "You are Present" << endl;
    }
 
};