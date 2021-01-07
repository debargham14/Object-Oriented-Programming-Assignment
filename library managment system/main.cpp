//--------------------------------Library Management System------------------------------//
#include<iostream>
#include<fstream>
#include "member.h"
#include "book.h"
#include "transaction.h"

using namespace std;

//driver code to implement the above classes and their functionalities
int main() {
    //menu driven program to implement the same
    STUDENTFILE obj1;
    FACULTYFILE obj2;
    BOOKFILE obj3;
    TRANSACTIONFILE obj4;
    obj1.getData();
    obj2.getData();
    obj3.getData();
    obj4.getData();
    while (1) {
        //relevants objects to be declared
        int ch; //rproviding choice to the user
        cout << "1. add Student\n2. add faculty\n3. display student by id\n4. display all students\n5. display faculty by id\n6. display all faculties\n7. add a book\n";
        cout << "8. display book by id\n9. display all books\n10. issue a book\n11. return a book\n12. display all transaction\n13. exit\n";
        cin >> ch;
        switch (ch) { //implementing switch case based operation handler
        case 1: obj1.addStudent(obj2);
            break;
        case 2: obj2.addFaculty(obj1);
            break;
        case 3: obj1.displayStudentById();
            break;
        case 4: obj1.displayAllStudent();
            break;
        case 5: obj2.displayFacultyById();
            break;
        case 6: obj2.displayAllFaculties();
            break;
        case 7: obj3.addBook(obj4);
            break;
        case 8: obj3.displayBookById();
            break;
        case 9: obj3.displayAll();
            break;
        case 10: obj4.issueBook(obj1, obj2, obj3);
            break;
        case 11: obj4.returnBook(obj1, obj2, obj3);
                break;
        case 12: obj4.displayTransaction();
                break;
        default : exit(0);
        }
    }
    return 0;
}