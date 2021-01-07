#pragma once 
#include<iostream>
#include<fstream>
using namespace std;

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
class TRANSACTIONFILE {
    char fname[31];
public:
    void getData() { //to get the binary file where transaction is stored
        cout << "Enter the transaction file name :- ";
        cin >> fname;
    }
    //definging the method to issue a book
    void issueBook(STUDENTFILE& obj1, FACULTYFILE& obj2, BOOKFILE& obj3) {
        fstream f;
        f.open(fname, ios::binary | ios::ate | ios::in | ios::out);
         char memType = '\0';
            int id;
            cout << "Enter the id :- ";
            cin >> id;
            memType = obj1.searchStudentById(id) ? 's' : (obj2.searchFacultyById(id) ? 'f' : '\0'); //receiving the member type 
            
            if (memType == '\0') {
                cout << "Sorry member with the same id doesn't exist !";
                return;
            }
            else { //proceed with other checkings
                int cntBooks = 0;
                TRANSACTION t;
                f.seekg(0);
                f.seekp(0);
                while (f.read((char*)&t, sizeof(TRANSACTION))) {
                    if (t.getMemId() == id && t.getTransactionType() == 'i')  {
                        cntBooks++;
                    }
                }
                f.clear();
                cout << "Number of books issued so far :- " << cntBooks << "\n";
                if (memType == 's') { //setting conditions for students to issue a book
                    cout << "Mmber Tyoe :- " << "student" << "\n";
                    if (cntBooks < 2) { //book issue possible for student provided book is available
                        int bid;
                        cout << "Enter the book id :- ";
                        cin >> bid;
                        if (obj3.searchBookById(bid) > 0) {
                            cout << "Book can be issued by the student !\n";
                            //take the last serial number from the list of books
                            char c;
                            cout << "Do you want to proceed (y/n) :- ";
                            cin >> c;
                            if (c == 'y' || c == 'Y') { //book exists and is available for issue
                                int sno = obj3.updateBookStockIssue(bid);
                                TRANSACTION t1;
                                t1.getData(id, bid, sno, 'i');
                                if (sno != -1) {
                                    f.write((char*)&t1, sizeof(TRANSACTION));
                                    cout << "Book issued successfully serial number :- " << sno << "\n";
                                }
                                else
                                    cout << "Transaction failed ! Book Not available \n";
                            }
                        }
                        //book doesn't exist
                        else {
                            cout << "Book not existing at this moment!\n";
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
                    cout << "Member Type :- " << "faculty" << "\n";
                    if (cntBooks < 10) { //book issue possible for faculty provided book is available
                        int bid;
                        cout << "Enter the book id :- ";
                        cin >> bid;
                        if (obj3.searchBookById(id) == 2) {
                            cout << "Book can be issued by the faculty !\n";
                            //take the last serial number from the list of books
                            char c;
                            cout << "Do you want to proceed (y/n) :- ";
                            cin >> c;
                            if (c == 'y' || c == 'Y') {
                                int sno = obj3.updateBookStockIssue(bid);
                                TRANSACTION t1;
                                t1.getData(id, bid, sno, 'i');
                                if (sno != -1) {
                                    f.write((char*)&t1, sizeof(TRANSACTION));
                                    cout << "Book issued successfully ! serial number :- " << sno << "\n";
                                }
                                else
                                    cout << "Transaction failed ! sorry book not available\n";
                            }
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
    void returnBook(STUDENTFILE& obj1, FACULTYFILE& obj2, BOOKFILE& obj3) { //method to make transaction
        fstream f;
        f.open(fname, ios::binary | ios::ate | ios::in | ios::out);
            int sno, bid, mid;
            cout << "Enter the member id :- ";
            cin >> mid;
            cout << "Enter the book id :- ";
            cin >> bid;
            cout << "Enter the sno :- ";
            cin >> sno;
            int k = 0, nullcount = 0;
            //check if the triplet is present in the transaction list or not
            TRANSACTION t;
            f.seekg(0);
            f.seekp(0);
            while (f.read((char*)&t, sizeof(TRANSACTION))) {
                k++;
                if (t.getBookId() == bid && t.getMemId() == mid && t.getSno() == sno && t.getTransactionType() == 'i') {
                    break;
                }
                else if (t.getBookId() == bid && t.getMemId() == mid && t.getSno() == sno && t.getTransactionType() == '\0') {
                    nullcount++;
                }
            }
            if (f.eof()) {
                if (nullcount > 0) {
                    cout << "Book already returned ! \n";
                }
                else {
                    cout << "detail mismatch alert !\n";
                }
            }
            else { //bring the get and the put pointer to proper location and then modify the record and finally add a new record
                f.clear();
                f.seekg((k - 1) * sizeof(TRANSACTION), ios::beg);
                f.read((char*)&t, sizeof(TRANSACTION));

                t.setTransactionNull();

                f.seekp((k - 1) * sizeof(TRANSACTION), ios::beg);
                f.write((char*)&t, sizeof(TRANSACTION));

                f.seekp(0, ios::end);
                obj3.updateBookStockReturn(t.getBookId(), t.getSno());

                t.getData(mid, bid, sno, 'r');
                f.write((char*)&t, sizeof(TRANSACTION));
                cout << "Return Successful !\n";
            }
            f.close();
    }
    void displayTransaction() {
        fstream f;
        f.open(fname, ios::binary | ios::app | ios::in | ios::out);
        TRANSACTION t;
        cout << "bid mid sno trtype-----------\n";
        while (f.read((char*)&t, sizeof(TRANSACTION))) {
            cout << t.getBookId() << " " << t.getMemId() << " " << t.getSno() << " " << t.getTransactionType() << "\n";
        }
        f.close();
    }
    //method to get the last serial number issued
    int lastSerialIssued() {
        TRANSACTION t;
        fstream f;
        int ans = 999;
        f.open(fname, ios::binary | ios::app | ios::in | ios::out);
        while (f.read((char*)&t, sizeof(TRANSACTION))) {
            if (t.getTransactionType() == 'i') {
                ans = max(ans, t.getSno());
            }
        }
        return ans;
    }
};
//method uses transaction file object to get hold of the lasts serial number issued for a particular book
int BOOKFILE::retLast(TRANSACTIONFILE& obj1) {
    int ans = 999;
    fstream f;
    f.open(fname, ios::binary | ios::app | ios::in | ios::out);
    BOOKCOPY b;
    while (f.read((char*)&b, sizeof(BOOKCOPY))) {
        ans = max(ans, b.retLast());
    }
    ans = max(ans, obj1.lastSerialIssued());

    return ans;
}
//defining the method get data
void BOOKCOPY::getCopy(BOOKFILE& obj, TRANSACTIONFILE& obj1) {
    int val = obj.retLast(obj1);
    lastEntry = ++val;
    serialNos[++count] = lastEntry;
    cout << "Serial Number generated :- " << serialNos[count] << "\n";
}
//defining the method to get a new book or copy of another book
void BOOKFILE::addBook(TRANSACTIONFILE& obj1) {
    fstream f;
    f.open(fname, ios::binary | ios::ate | ios::in | ios::out);
    int flag = 0, k = 0;
    char ch;
    int id;
    cout << "Enter book id :- ";
    cin >> id;
    //if id already exists wee need to go for record modification else
    //we need to add the book record into the file
    BOOKCOPY b;
    f.seekg(0, ios::beg);
    f.seekp(0, ios::beg);
    while (f.read((char*)&b, sizeof(BOOKCOPY))) {
        k++;
        if (b.getId() == id) {
            flag = 1;
            cout << "First Copy of the book already exists ! Would you like add a copy (y/n) :- ";
            cin >> ch;
            if (ch == 'y' || ch == 'Y') { //record modfication is required
                b.getCopy(*this, obj1);
                f.seekp(-1 * sizeof(BOOKCOPY), ios::cur);
                f.write((char*)&b, sizeof(BOOKCOPY));
                cout << "Book added sucessfully !\n";
                f.close();
                return;
            }
        }
    }
    if (flag == 0) {
        f.clear();
        f.seekp(0, ios::end);
        BOOKCOPY b1;
        b1.getData(id);
        b1.getCopy(*this, obj1);
        //write the record into the file
        f.write((char*)&b1, sizeof(BOOKCOPY));
        cout << "Book inserted successfully !\n";
    }
    f.close();
}