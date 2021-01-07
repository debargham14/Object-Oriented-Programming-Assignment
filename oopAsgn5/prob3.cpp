#include<iostream>
using namespace std;

//designing the  class employee
class EMPLOYEE {
protected:
    static int last;
    int empId;
    char name[31];
    char designation[31];
    double basePay;
public:
    void getData() { //designing the method getData to accept the employee details
        empId = last++;
        cout << "Enter the Employee Name :- ";
        scanf(" %[^\n]s", name);
        cout << "Enter the designation :- ";
        scanf(" %[^\n]s", designation);
        cout << "Enter the Basic Pay :- ";
        cin >> basePay;
    }
    //method to calculatee the salary
    virtual void calSalary() = 0;
    //designing the method to show Data
    virtual void showData() = 0;
};
int EMPLOYEE::last = 0;

//designing the class permanent employee to do the same
class PERMANENT: public EMPLOYEE {
protected:
    double salary;
public:
    void calSalary() {  //defining the method calculate salary
        salary = basePay + (0.3 * basePay) + (0.8 * basePay);
    }
    void showData() { //defining the method calculate data
        calSalary();   //call made to the function calsalary before displaying it
        cout << "Name Of the employee :- " << name << "\n";
        cout << "Employee Id :- " << empId << "\n";
        cout << "Designation :- " << designation << "\n";
        cout << "Total Salary :- " << salary << "\n";
    }
};

class CONTRACTUAL: public EMPLOYEE {
protected:
    double salary;
    double allowance;
public:
    void calSalary() { //defining method calculate salary for the contractual emloyee
        cout << "Enter the allowance amount :- ";
        cin >> allowance;
        salary = basePay + allowance;
    }
    void showData() {
        calSalary();    //call made to the function calsalary before displaying it
        cout << "Name Of the employee :- " << name << "\n";
        cout << "Employee Id :- " << empId << "\n";
        cout << "Designation :- " << designation << "\n";
        cout << "Total Salary :- " << salary << "\n";
    }
};

int main() {
    EMPLOYEE *ptr;
    PERMANENT obj1;
    CONTRACTUAL obj2;
    ptr = &obj1;    //enabling dynamic linking or runtime polymorphism
    ptr->getData();
    ptr->showData();

    ptr = &obj2;    //enabling dynamic linking
    ptr->getData();
    ptr->showData();
    return 0;
}