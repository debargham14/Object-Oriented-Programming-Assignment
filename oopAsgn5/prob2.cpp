#include<iostream>
using namespace std;

//designing the class member as an abstract base class
class MEMBER {
protected: //placing the commonalities in the member class
    static int last;
    int memberId;
    char name[31];
    char email[31];
    int bookId[31];
public:
    virtual void getData() = 0; //deaclaring a pure virtual function to make the MEMBER class abstarct
    void showData() {
        cout << "Name :- " << name << "\n";
        cout << "Member Id :- " << memberId << "\n";
        cout << "email id :- " << email << "\n";
    }
};
int MEMBER::last = 0;
//designing the class STUDENT which will inherit from the MEMBER class
class STUDENT: public MEMBER {
public:
    void getData() { //defining the method getData()
        memberId = last++;
        cout << "Enter the Name :- ";
        scanf(" %[^\n]s", name);
        cout << "Enter the email id :- ";
        scanf(" %[^\n]s", email);
    }
    int getStudentId() { //method to get student id
        return memberId;
    }
};

//designing the class student to hold the list of  students
class STUDENTLIST: public STUDENT {
    int totalstd = -1;
    STUDENT arr[31];
public:
    void addStudent() { //designing a method to add student
        arr[++totalstd].getData();
        cout << "Student Entry Successfull ! member id :- " << arr[totalstd].getStudentId();
        // cout << totalstd;
        cout << "\n";
    }
    void displayStudentById() { //method to display the details of student on the basis of id
        int id;
        cout << "Enter the id of the student :- ";
        cin >> id;
        int flag = 0;
        for (int i = 0; i <= totalstd; i++) {
            if (arr[i].getStudentId() == id) {
                arr[i].showData();
                flag = 1;
            }
        }
        if (flag == 0) {
            cout << "Student Not enrolled yet !\n";
        }
    }
    //method to display all the students
    void displayAllStudent() {
        //     cout << totalstd << "\n";
        if (totalstd == -1) {
            cout << "No students to display !\n";
            return;
        }
        for (int i = 0; i <= totalstd; i++) {
            arr[i].showData();
            cout << "------------------------------\n";
        }
    }
    //method to search for a student with a given id
    bool searchStudentById(int id) {
        for (int i = 0; i <= totalstd; i++) {
            if (arr[i].getStudentId() == id)
                return true;
        }
        return false;
    }
};


//designing the class FACULTY which will also inherit from the MEMBER class
class FACULTY: public MEMBER {
public:
    void getData() { //defining the method getData to accpet details of a faculty
        memberId = last++;
        cout << "Enter the Name :- ";
        scanf(" %[^\n]s", name);
        cout << "Enter the email id :- ";
        scanf(" %[^\n]s", email);
    }
    int getFacultyId() { //to get the faculty id
        return memberId;
    }
};

//designing the class faculty list to hold the list of faculties
class FACULTYLIST: public FACULTY {
    int totalfac = -1;
    FACULTY arr[31];
public:
    void addFaculty() { //designing a method to add faculty
        arr[++totalfac].getData();
        cout << "Faculty Entry Successful ! member id :- " << arr[totalfac].getFacultyId() << "\n";
    }
    void displayFacultyById() { //method to display the details of faculty on the basis of id
        int id;
        cout << "Enter the id of the faculty :- ";
        cin >> id;
        int flag = 0;
        for (int i = 0; i <= totalfac; i++) {
            if (arr[i].getFacultyId() == id) {
                arr[i].showData();
                flag = 1;
            }
        }
        if (flag == 0) {
            cout << "Faculty Not enrolled yet !\n";
        }
    }
    //method to display all the students
    void displayAllFaculties() {
        if (totalfac == -1) {
            cout << "No faculties to display !\n";
            return;
        }
        for (int i = 0; i <= totalfac; i++) {
            arr[i].showData();
            cout << "------------------------------\n";
        }
    }
    //method to search for a student with a given id
    bool searchFacultyById(int id) {
        for (int i = 0; i <= totalfac; i++) {
            if (arr[i].getFacultyId() == id)
                return true;
        }
        return false;
    }
};

//designing the class BOOK to hold the relevant information on books
class BOOK {
protected:
    int bookId;
    char bookName[31];
    char author[31];
    char publisher[31];
public:
    void getData(int id) { //designing the class getData() to accept book details
        bookId = id;
        cout << "Enter the book Name :- ";
        scanf(" %[^\n]s", bookName);
        cout << "Enter the author's Name :- ";
        scanf(" %[^\n]s", author);
        cout << "Enter the publisher's name :- ";
        scanf(" %[^\n]s", publisher);
    }
    void showData() { //designing the method  showData to show the book details
        cout << "Name of the Book :- " << bookName << "\n";
        cout << "Book Id :- " << bookId << "\n";
        cout << "Author's Name :- " << author << "\n";
        cout << "Publisher's Name :- " << publisher << "\n";
    }
};

//designing the class BOOKCOPY to keep a track of the number of books with a same id
class BOOKCOPY: public BOOK {
protected:
    static int lastEntry;
    int count = -1;
    int serialNos[31];
public:
    void getCopy() { //to get a copy of the book
        serialNos[++count] = lastEntry;
        lastEntry++;
    }
    void showCopy() { //to show the existing copies of the book
        if (count == -1) {
            cout << "No Copy Of this Book Exists !\n";
            return;
        }
        cout << "Current serial Numbers existing are :- ";
        for (int i = 0; i <= count; i++) cout << serialNos[i] << " ";
        cout << "\n";
    }
    //method to search the presence of a copy on the basis of serial Numbers
    bool searchCopy(int s) {
        for (int i = 0; i <= count; i++) {
            if (serialNos[i] == s)
                return true;
        }
        return false;
    }
    int getCount() { //method to return the total number of books
        return count + 1;
    }
    int getId() {
        return bookId;
    }

    //method to update the book and the recent serial number
    int updateBookIssue() {
        int sno = serialNos[count];
        count--;
        return sno;
    }
    //method to accept the return of the book
    void updateBookReturn(int sno) {
        serialNos[++count] = sno;
    }
};
int BOOKCOPY::lastEntry = 1000; //initialising the static data member of the class so that problem of repition and need for recheck is abolished

//designing the class bookList to contain the list Of books
class BOOKLIST: public BOOKCOPY {
    int total = -1;
    BOOKCOPY arr[31];
public:
    void addBook() { //method to add a book in the list
        int flag = 0;
        int id;
        cout << "Enter book id :- ";
        cin >> id;
        for (int i = 0; i <= total; i++) {
            if (arr[i].getId() == id) {
                flag = 1;
                char ch;
                cout << "First of the Book Already exsits ! Would you like to add a copy (y/n) :- ";
                cin >> ch;
                if (ch == 'y' || ch == 'Y') { //enter a copy
                    arr[i].getCopy();
                    cout << "Book entry sucessful !\n";
                }
                else {
                    return;
                }
            }
        }
        if (flag == 0) {
            cout << "Adding First Copy of the book\n";
            arr[++total].getData(id); //get the book details
            arr[total].getCopy(); //increment the copy of the book by 1 by assigning a serial number
            cout << "Book Entry Sucessful !\n";
        }
    }

    void displayBookById() { //method to display the book by their id
        int id, flag = 0;
        cout << "Enter the book id :- ";
        cin >> id;
        for (int i = 0; i <= total; i++) {
            if (arr[i].getId() == id) {
                flag = 1;
                arr[i].showData();
                char ch;
                cout << "Would you like to see the existing serial numbers of this book (y / n):- ";
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                    arr[i].showCopy();
            }
        }
        if (flag == 0)  //book doesn't exist
        {
            cout << "Sorry The Book doesn't exist ! ";
            return;
        }
    }
    void displayAll() { //method to display all available books
        int ch;
        cout << "1. display all books\n2. display all available books\nEnter the choice :- ";
        cin >> ch;
        if (ch == 1) {
            if (total == -1)
                cout << "No Books To Display !\n";
            else {
                for (int i = 0; i <= total; i++) {
                    arr[i].showData();
                    cout << "------------------------------\n";
                }
            }
        }
        else if (ch == 2) {
            if (total == -1) {
                cout << "No Books To Display !\n";
            }
            else {
                for (int i = 0; i <= total; i++) {
                    if (arr[i].getCount() > 0) {
                        arr[i].showData();
                        cout << "------------------------------\n";
                    }
                }
            }
        }
        else
            cout << "Invalid Choice !";
    }
    //designing the method to search the existence of the book
    int searchBookById(int id) {
        for (int i = 0; i <= total; i++) {
            if (arr[i].getId() == id && arr[i].getCount() > 0)
            {
                cout << "Found !!";
                return 2;
            }
            else if (arr[i].getId() == id && arr[i].getCount() == 0)
                return 1;
        }
        return 0;
    }
    //method to update the book record based on id
    int updateBookStockIssue(int bid) {
        int sno = -1;
        for (int i = 0; i <= total; i++) {
            if (arr[i].getId() == bid) {
                sno = arr[i].updateBookIssue();
            }
        }
        return sno;
    }
    //method to return the book based on id and serial number
    void updateBookStockReturn(int bid, int sno) {
        for (int i = 0; i <= total; i++) {
            if (arr[i].getId() == bid)
                arr[i].updateBookReturn(sno);
        }
    }
};

//designing the class transaction to handle all different types of transaction
class TRANSACTION { //exsitence of the triplet is mandatory
protected:
    int bookId;
    int memId;
    int serialNum;
    char trType;
public:
    void getData(int mid, int bid, int sno, char c) { //function to get the transaction details
        bookId = bid;
        memId = mid;
        serialNum = sno;
        trType = c;
    }
    int getMemId() { //method to get the member id
        return memId;
    }
    int getBookId() { //method to return member id
        return bookId;
    }
    int getSno() {  //method to return serial number
        return serialNum;
    }
    char getTransactionType() { //method to return the transaction type
        return trType;
    }
    //function to set the transactiontype to null so that a kind of
    //logical deletion fo the previous issue transaction takes place
    void setTransactionNull() { //defining the method
        trType = '\0';
    }
};

//designing the class TRNSACTIONLIST to support the transactions
class TRANSACTIONLIST: public TRANSACTION {
    int tcount = -1;
    TRANSACTION arr[31];
public:
    void makeTransaction(STUDENTLIST& obj1, FACULTYLIST& obj2, BOOKLIST& obj3) { //method to make transaction
        int ch;
        cout << "Enter the type of transaction you like to make\n1. issue a book\n2. return a book\n";
        cin >> ch;
        if (ch == 1) {  //issue a book
            char memType = '\0';
            int id;
            cout << "Enter the id :- ";
            cin >> id;
            if (obj1.searchStudentById(id)) {
                cout << "Member Type : Student\n";
                memType = 's';
            }
            else if (obj2.searchFacultyById(id)) {
                cout << "Member Type : Faculty\n";
                memType = 'f';
            }
            if (memType == '\0') {
                cout << "Sorry member with the same id doesn't exist !";
                return;
            }
            else { //proceed with other checkings
                int cntBooks = 0;
                for (int i = 0; i <= tcount; i++) {
                    if (arr[i].getMemId() == id && arr[i].getTransactionType() == 'i')
                        cntBooks++;
                }
                if (memType == 's') { //setting conditions for students to issue a book
                    if (cntBooks < 2) { //book issue possible for student provided book is available
                        int bid;
                        cout << "Enter the book id :- ";
                        cin >> bid;
                        if (obj3.searchBookById(bid) == 2) {
                            cout << "Book existing and can be issued by the student !\n";
                            //take the last serial number from the list of books
                            char c;
                            cout << "Do you want to proceed (y/n) :- ";
                            cin >> c;
                            if (c == 'y' || c == 'Y') { //book exists and is available for issue
                                int sno = obj3.updateBookStockIssue(bid);
                                arr[++tcount].getData(id, bid, sno, 'i');
                                cout << "Book issued successfully !\n";
                            }
                        }
                        else if (obj3.searchBookById(bid) == 1) { //book can be issued later
                            cout << "Book exsiting but OUT OF STOCK !\n";
                            return;
                        }
                        //book doesn't exist
                        else {
                            cout << "Book not existing !\n";
                            return;
                        }
                    }
                    //maximum limit exceeded for the student
                    else {
                        cout << "Sorry book issue not possible for student !";
                        return;
                    }
                }
                else { //setting conditions for book issue by faculty
                    if (cntBooks < 10) { //book issue possible for faculty provided book is available
                        int bid;
                        cout << "Enter the book id :- ";
                        cin >> bid;
                        if (obj3.searchBookById(id) == 2) {
                            cout << "Book existing and can be issued by the faculty !\n";
                            //take the last serial number from the list of books
                            char c;
                            cout << "Do you want to proceed (y/n) :- ";
                            cin >> c;
                            if (c == 'y' || c == 'Y') {
                                int sno = obj3.updateBookStockIssue(bid);
                                arr[++tcount].getData(id, bid, sno, 'i');
                                cout << "Book issued successfully !\n";
                            }
                        }
                        //same check is made for the faculty while issueing
                        else if (obj3.searchBookById(id) == 1) {
                            cout << "Book exsiting but OUT OF STOCK !\n";
                            return;
                        }
                        else {
                            cout << "Book not existing !\n";
                            return;
                        }
                    }
                    //maximum limit exceeded for the faculty
                    else {
                        cout << "Sorry book issue not possible for faculty !";
                        return;
                    }
                }
            }
        }
        else if (ch == 2) { //return a book
            int sno, bid, mid;
            cout << "Enter the member id :- ";
            cin >> mid;
            cout << "Enter the book id :- ";
            cin >> bid;
            cout << "Enter the sno :- ";
            cin >> sno;
            //check if the triplet is present in the transaction list or not
            int issueCount = 0, nullCount = 0, lastIdx = -1;
            for (int i = 0; i <= tcount; i++) {
                // cout << arr[i].getBookId() << " " << arr[i].getMemId() << " " << arr[i].getSno() << " " << "\n";
                if (arr[i].getBookId() == bid && arr[i].getMemId() == mid && arr[i].getSno() == sno && arr[i].getTransactionType() == 'i')
                {
                    //if there is an issue the issue count needs to be incremented and the lastIdx needs to recorded
                    issueCount++;
                    lastIdx = i;
                }
                else if (arr[i].getBookId() == bid && arr[i].getMemId() == mid && arr[i].getSno() == sno && arr[i].getTransactionType() == '\0') {
                    //null count refers to the number of times a students has taken a book and returned it
                    nullCount++;
                }
            }
            //issue count > 0, ensures that there is a single issue that
            //has not been returned yet
            if (issueCount > 0) {
                arr[lastIdx].setTransactionNull();
                obj3.updateBookStockReturn(bid, sno);
                arr[++tcount].getData(mid, bid, sno, 'r');
                cout << "Return Successful !\n";
                return;
            }
            //issuecount == 0 ensures that there is no possible return
            else if (issueCount == 0) {
                if (nullCount == 0) { //raise a detail mismatch alert
                    cout << "Return Not possible ! detail mismatch alert !\n";
                    return;
                }
                else {  //book already returned
                    cout << "Book Already Returned !\n";
                }
            }

        }
        //incase if any other number is selected
        else {
            cout << "Invalid choice !\n";
            return;
        }
    }
};

//driver code to implement the above classes and their functionalities
int main() {
    //menu driven program to implement the same
    STUDENTLIST obj1;
    FACULTYLIST obj2;
    BOOKLIST obj3;
    TRANSACTIONLIST obj4;
    while (1) {
        //relevants objects to be declared

        int ch; //rproviding choice to the user
        cout << "1. add Student\n2. add faculty\n3. display student by id\n4. display all students\n5. display faculty by id\n6. display all faculties\n7. add a book\n";
        cout << "8. display book by id\n9. display all books\n10. make a transaction\n11. exit\n";
        cin >> ch;
        switch (ch) { //implementing switch case based operation handler
        case 1: obj1.addStudent();
            break;
        case 2: obj2.addFaculty();
            break;
        case 3: obj1.displayStudentById();
            break;
        case 4: obj1.displayAllStudent();
            break;
        case 5: obj2.displayFacultyById();
            break;
        case 6: obj2.displayAllFaculties();
            break;
        case 7: obj3.addBook();
            break;
        case 8: obj3.displayBookById();
            break;
        case 9: obj3.displayAll();
            break;
        case 10: obj4.makeTransaction(obj1, obj2, obj3);
            break;
        default : exit(0);
        }
    }
    return 0;
}