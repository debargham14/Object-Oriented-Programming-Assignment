#pragma once 
#include<iostream>
#include<fstream>
using namespace std;

class TRANSACTIONFILE;

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
class BOOKFILE;
//designing the class BOOKCOPY to keep a track of the number of books with a same id
class BOOKCOPY: public BOOK {
protected:
    static int lastEntry;
    int count = -1;
    int serialNos[31];
public:
    int retLast() { //to return the last serial number of a book
        if (count == -1)
            return 999;
        else
            return serialNos[count];
    }
    void getCopy(BOOKFILE&, TRANSACTIONFILE&); //method to get the copy of the book
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
    void setLast(BOOKFILE&);
};
int BOOKCOPY::lastEntry = 999;

//designing the class bookList to contain the list Of books
class BOOKFILE {
    char fname[31];
public:
    //addiing the method get data to do the same
    void getData() {
        cout << "Enter the book file name :- ";
        cin >> fname;
    }
    void addBook(TRANSACTIONFILE&);

    void displayBookById() { //method to display the book by their id
        int id, flag = 0;
        fstream f;
        f.open(fname, ios::binary | ios::app | ios::in | ios::out);

        BOOKCOPY b;
        cout << "Enter book id :- ";
        cin >> id;

        while (f.read((char*)&b, sizeof(BOOKCOPY))) {

            if (b.getId() == id) {
                flag = 1;
                b.showData();
                char ch;
                cout << "Would you like to see the existing serial numbers of this book (y / n):- ";
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                    b.showCopy();
                break;
            }
        }
        if (flag == 0) {
            cout << "The book doesn't exist !";
        }
        f.close();
    }

    void displayAll() { //method to display all available books
        fstream f;
        f.open(fname, ios::binary | ios::app | ios::in | ios::out);
        int count = 0;
        BOOKCOPY b;
        int ch;
        cout << "1. display all books\n2. display all available books\nEnter the choice :- ";
        cin >> ch;
        while ( f.read((char*)&b, sizeof(BOOKCOPY))) {

            count++;
            if (ch == 1) {
                b.showData();
                b.showCopy();
            }
            else if (ch == 2) {
                b.showData();
            }
            else {
                cout << "Invalid Choice !";
                return;
            }
            cout << "------------------------------\n";
        }
        if (count == 0 && (ch == 1 || ch == 2))
        {
            cout << "No Books existing !";
        }
        f.close();
    }

    //designing the method to search the existence of the book
    int searchBookById(int id) {
        int k = 0;
        fstream f;
        f.open(fname, ios::binary | ios::app | ios::in | ios::out);
        BOOKCOPY b;
        while ( f.read((char*)&b, sizeof(BOOKCOPY))) {
            k++;
            if (b.getId() == id) {
                if (b.getCount() > 0)
                    return k;
            }
        }
        if (f.eof()) return 0;
        f.close();
        return 0;
    }

    //method to update the book record based on id
    int updateBookStockIssue(int bid) {
        int sno = -1, k = 0;
        fstream f;
        f.open(fname, ios::binary | ios::ate | ios::in | ios::out);
        BOOKCOPY b;
        f.seekg(0);
        f.seekp(0);
        while ( f.read((char*)&b, sizeof(BOOKCOPY))) {
            k++;
            if (b.getId() == bid) {
                break;
            }
        }
        if (k == 0) {
            cout << "Unexpected Error !\n";
            return -1;
        }
        else {
            f.clear();
            f.seekg((k - 1) * sizeof(BOOKCOPY), ios::beg);
            f.read((char*)&b, sizeof(BOOKCOPY));

            sno = b.updateBookIssue(); //modification done

            f.seekp((k - 1) * sizeof(BOOKCOPY), ios::beg);
            f.write((char*)&b, sizeof(BOOKCOPY));
        }
        return sno;
    }

    //method to return the book based on id and serial number
    void updateBookStockReturn(int bid, int sno) {
        fstream f;
        f.open(fname, ios::binary | ios::ate | ios::in | ios::out);
        BOOKCOPY b;
        int k = 0;
        f.seekg(0);
        f.seekp(0);
        while ( f.read((char*)&b, sizeof(BOOKCOPY))) {
            k++;
            if (b.getId() == bid) {
                break;
            }
        }
        if (k == 0) {
            cout << "Unexpected Error !\n";
            return;
        }
        else {
            f.clear();
            f.seekg((k - 1) * sizeof(BOOKCOPY), ios::beg);
            f.read((char*)&b, sizeof(BOOKCOPY));

            b.updateBookReturn(sno); //modification done

            f.seekp((k - 1) * sizeof(BOOKCOPY), ios::beg);
            f.write((char*)&b, sizeof(BOOKCOPY));
        }
    }
    //method to return the last serial number of any book
    int retLast(TRANSACTIONFILE&);
};