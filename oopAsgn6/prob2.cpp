#include<iostream>
#define MAX_SIZE 2
using namespace std;

//designing the class student 
class STUDENT{
protected:
    int roll;
    char name[31];
    int score;
public:
    //defining the method to get the data
    void getData() {
        cout << "Enter roll of the student :- ";
        cin >> roll;
        cout << "Enter Name of the student :- ";
        cin >> name;
        cout << "Enter Score :- ";
        cin >> score;
    }
    //defining the method ot show the data
    void showData() {
        cout << "Name of the student :- " << name << "\n";
        cout << "Roll Number :- " << roll << "\n";
        cout << "Score Achieved :- " << score << "\n";
    }
};
//designing the class array of students so that one can work with array of students with proper exception for index going out of bounds
class STUDENTLIST:public STUDENT{
    int count = -1;
    STUDENT arr[MAX_SIZE];
public:
    //method to add all students 
    void addStudent(){
        ++count;
        if(count > MAX_SIZE - 1)
            throw "max student limit exceeded !\n";
        else
            arr[count].getData();
    }
    //method to diplay all records
    void displayAl(){
        if(count == -1)
            throw "Student underflow condition \n";
        else{
            for(int i = 0; i <= min(count, MAX_SIZE - 1); i++){
                arr[i].showData();
            }
        }
    }
};

int main() {
    //menu driven program to implement the same
    STUDENTLIST obj1;
    while(1) {
        cout << "1. add student\n2. display all students\n3. exit\n";
        int ch;
        cin >> ch;
        switch(ch) {
            case 1: try{
                obj1.addStudent();
            }
            catch(const char* c){
                cout << c;
            }
            break;
            case 2:try{
                obj1.displayAl();
            }catch(const char* c){
                cout << c;
            }
            break;
            default:
                exit(0);
        }
    }
    return 0;    
}