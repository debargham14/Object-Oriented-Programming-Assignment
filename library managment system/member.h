#pragma once 
#include<iostream>
#include<fstream>
using namespace std;
//fwd declaration of the classes whose object reference is required
class STUDENTFILE;
class FACULTY;
class FACULTYFILE;

class MEMBER {
    static int last;
protected: //placing the commonalities in the member class
    int memberId;
    char name[31];
    char email[31];
    int bookId[31];
public:
    //deaclaring a pure virtual function to make the MEMBER class abstarct
    void showData() {
        cout << "Name :- " << name << "\n";
        cout << "Member Id :- " << memberId << "\n";
        cout << "email id :- " << email << "\n";
    }
    static void setLast(STUDENTFILE&, FACULTYFILE&); //setting the last value of the  id
    int retLast() {
        ++last;
        return last;
    }
};
int MEMBER::last = 0;

//designing the class STUDENT which will inherit from the MEMBER class
class STUDENT: public MEMBER {
public:
    void getData() { //defining the method getData()
        memberId = MEMBER::retLast();
        cout << "Enter the Name :- ";
        cin >> name;
        cout << "Enter the email id :- ";
        cin >> email;
        cout << "Student Registration sucessful ! member id :- " << memberId << "\n";
    }
    int getStudentId() { //method to get student id
        return memberId;
    }
};

//designing the class studentfile to keep the records into the file
class STUDENTFILE {
    char fname[31];
public:
//defining the method to get Data into the file
    void getData() {
        cout << "Enter the student filename :- ";
        cin >> fname;
    }
//defining the method to add student into the file
    void addStudent(FACULTYFILE&);

    //to display student data on the basis of id
    void displayStudentById() {
        int id;
        cout << "Enter the student id :- ";
        cin >>  id;

        int flag = 0; //counter to trace the presence
        //opening the file to read the content
        fstream f;
        f.open(fname, ios::binary | ios::out | ios::in | ios::app);

        //search till end of file is reached
        STUDENT s;
        while (f.read((char*)&s, sizeof(STUDENT))) {
            if (s.getStudentId() == id) {
                s.showData();
                flag = 1;
            }
        }
        if (flag == 0) {
            cout << "Record not found !";
        }
        f.close();
    }

    //method to display all students
    void displayAllStudent() {
        int count = 0;
        fstream f;
        f.open(fname, ios::binary | ios::in | ios::out | ios::app);

        //declaring a student type object
        STUDENT s;
        while ( f.read((char*)&s, sizeof(STUDENT))) {
            s.showData();
            cout << "------------------------------\n";
            count++;
        }
        if (count == 0) {
            cout << "No students to display !\n";
        }
        f.close();
    }

    //method to search student by id
    int searchStudentById(int id) {
        int k = 0, flag = 0;
        //opening the file
        fstream f;
        f.open(fname, ios::binary | ios::app | ios::out | ios::in);

        //search operation begins
        STUDENT s;
        while ( f.read((char*)&s, sizeof(STUDENT))) {
            k++;
            if (s.getStudentId() == id)
            {
                flag = 1;
                f.close();
                return k;
            }
        }
        //closing the file
        f.close();
        return 0;
    }
    //method to return the last id
    int retLastId() {
        int ans = -1;

        fstream f(fname, ios::binary | ios::app | ios::in | ios::out);
        STUDENT s;
        while (f.read((char*)&s, sizeof(STUDENT))) {
            ans = max(ans, s.getStudentId());
        }
        return ans;
    }
};

//designing the class FACULTY which will also inherit from the MEMBER class
class FACULTY: public MEMBER {
public:
    void getData() { //defining the method getData to accpet details of a faculty
        memberId = MEMBER::retLast();
        cout << "Enter the Name :- ";
        cin >>  name;
        cout << "Enter the email id :- ";
        cin >> email;
        cout << "Student Registration sucessful ! member id :- " << memberId << "\n";
    }
    int getFacultyId() { //to get the faculty id
        return memberId;
    }
};

//designing the class facultyfile to keep the records into the file
class FACULTYFILE {
    char fname[31];
public:
//defining the method to get Data into the file
    void getData() {
        cout << "Enter the faculty filename :- ";
        cin >> fname;
    }
//defining the method addfaculty to add a faculty
    void addFaculty(STUDENTFILE&);

    //to display faculty data on the basis of id
    void displayFacultyById() {
        int id;
        cout << "Enter the faculty id :- ";
        cin >>  id;

        int flag = 0; //counter to trace the presence
        //opening the file to read the content
        fstream f;
        f.open(fname, ios::binary | ios::app | ios::in | ios::out);

        //search till end of file is reached
        FACULTY s;
        while (f.read((char*)&s, sizeof(FACULTY))) {
            if (s.getFacultyId() == id) {
                s.showData();
                flag = 1;
            }
        }
        if (flag == 0) {
            cout << "Record not found !";
            return;
        }
        f.close();
    }

    //method to display all students
    void displayAllFaculties() {
        int count = 0;
        fstream f;
        f.open(fname, ios::binary | ios::app | ios::in | ios::out);

        //declaring a student type object
        FACULTY s;
        while (f.read((char*)&s, sizeof(FACULTY))) {
            s.showData();
            cout << "------------------------------\n";
            count++;
        }
        if (count == 0) {
            cout << "No faculties to display !\n";
        }
        f.close();
    }

    //method to search student by id
    int searchFacultyById(int id) {
        int k = 0;
        //opening the file
        fstream f;
        f.open(fname, ios::binary | ios::app | ios::in | ios::out);
        //search operation begins
        FACULTY s;
        while (f.read((char*)&s, sizeof(FACULTY))) {
            k++;
            if (s.getFacultyId() == id)
            {
                f.close();
                return k;
            }
        }
        //closing the file

        if (f.eof()) return 0; //not found condition
        f.close();
        return 0;
    }

    //mehtod to return the last id
    int retLastId() {
        int ans = -1;
        fstream f;
        f.open(fname, ios::binary | ios::app | ios::in | ios::out);
        FACULTY s;
        while (f.read((char*)&s, sizeof(FACULTY))) {
            ans = max(ans, s.getFacultyId());
        }
        return ans;
    }
};

void MEMBER::setLast(STUDENTFILE& obj1, FACULTYFILE& obj2) {
    int val = -1;
    val = max(val, max(obj1.retLastId(), obj2.retLastId()));
    if (val == -1)
        last = 0;
    else
        last = val;
}
//defining the method fro adding a student
void STUDENTFILE::addStudent(FACULTYFILE& obj1) {
    MEMBER::setLast(*this, obj1);
    STUDENT obj;
    obj.getData();
    fstream f; //declaring the file

    //file has to be opened in binary mode and ate mode
    f.open(fname, ios::binary | ios::ate | ios::in | ios::out);
    f.write((char*)&obj, sizeof(STUDENT));
    f.close();
}
//defining a method for adding a faculty
void FACULTYFILE::addFaculty(STUDENTFILE& obj1) {
    MEMBER::setLast(obj1, *this);
    FACULTY obj;
    obj.getData();
    fstream f; //declaring the file

    //file has to be opened in binary mode and ate mode
    f.open(fname, ios::binary | ios::ate | ios::in | ios::out);
    f.write((char*)&obj, sizeof(FACULTY));
    f.close();
}