//--------------------------------Library Management System------------------------------//
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
    int retLast(){
        ++last;
        return last; 
    }
};
int MEMBER::last = 0;

//designing the class STUDENT which will inherit from the MEMBER class
class STUDENT:public MEMBER{
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
class STUDENTFILE{
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
    void displayStudentById(){
        int id;
        cout << "Enter the student id :- ";
        cin >>  id;

        int flag = 0; //counter to trace the presence
        //opening the file to read the content
        fstream f; 
        f.open(fname, ios::binary | ios::out | ios::in | ios::app);
        
        //search till end of file is reached
        STUDENT s;
        while(f.read((char*)&s, sizeof(STUDENT))){
            if(s.getStudentId() == id){
                s.showData();
                flag = 1;
            }
        }
        if(flag == 0){
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
        while( f.read((char*)&s, sizeof(STUDENT))) {
            s.showData();
            cout << "------------------------------\n";
            count++;
        }
        if(count == 0){
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
        while( f.read((char*)&s, sizeof(STUDENT))) {
            k++;
            if(s.getStudentId() == id)
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
        while(f.read((char*)&s, sizeof(STUDENT))) {
            ans = max(ans, s.getStudentId());
        }
        return ans;
    }
};

//designing the class FACULTY which will also inherit from the MEMBER class
class FACULTY:public MEMBER{
public:
    void getData(){ //defining the method getData to accpet details of a faculty
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
class FACULTYFILE{
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
    void displayFacultyById(){
        int id;
        cout << "Enter the faculty id :- ";
        cin >>  id;

        int flag = 0; //counter to trace the presence
        //opening the file to read the content
        fstream f; 
        f.open(fname, ios::binary | ios::app | ios::in | ios::out);
        
        //search till end of file is reached
        FACULTY s;
        while(f.read((char*)&s, sizeof(FACULTY))){
            if(s.getFacultyId() == id){
                s.showData();
                flag = 1;
            }
        }
        if(flag == 0){
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
        while(f.read((char*)&s, sizeof(FACULTY))) {
            s.showData();
            cout << "------------------------------\n";
            count++;
        }
        if(count == 0){
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
        while(f.read((char*)&s, sizeof(FACULTY))) {
            k++;
            if(s.getFacultyId() == id)
            {
                f.close();
                return k;
            }
        }
        //closing the file 

        if(f.eof()) return 0; //not found condition
        f.close();
        return 0;
    }

    //mehtod to return the last id
    int retLastId() {
        int ans = -1;
        fstream f;
        f.open(fname, ios::binary | ios::app | ios::in | ios::out);
        FACULTY s;
        while(f.read((char*)&s, sizeof(FACULTY))) {
            ans = max(ans, s.getFacultyId());
        }
        return ans;
    }
};

void MEMBER::setLast(STUDENTFILE& obj1, FACULTYFILE& obj2) {
    int val = -1;
    val = max(val, max(obj1.retLastId(), obj2.retLastId()));
    if(val == -1)
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
class TRANSACTIONFILE;

//designing the class BOOK to hold the relevant information on books
class BOOK{
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
class BOOKCOPY:public BOOK{
protected:
    static int lastEntry;
    int count = -1;
    int serialNos[31];
public:
    int retLast() { //to return the last serial number of a book
        if(count == -1)
            return 999;
        else
            return serialNos[count];
    }
    void getCopy(BOOKFILE&, TRANSACTIONFILE&); //method to get the copy of the book
    void showCopy() { //to show the existing copies of the book
        if(count == -1){
            cout << "No Copy Of this Book Exists !\n";
            return;
        }
        cout << "Current serial Numbers existing are :- ";
        for(int i = 0; i <= count; i++) cout << serialNos[i] << " ";
        cout << "\n";
    }
    //method to search the presence of a copy on the basis of serial Numbers
    bool searchCopy(int s) {
        for(int i = 0; i <= count; i++){
            if(serialNos[i] == s)
                return true;
        }
        return false;
    }
    int getCount(){ //method to return the total number of books
        return count + 1;
    }
    int getId(){
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
class BOOKFILE{
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

        while(f.read((char*)&b, sizeof(BOOKCOPY))) {
           
            if(b.getId() == id){
                flag = 1;
                b.showData();
                char ch;
                cout << "Would you like to see the existing serial numbers of this book (y / n):- ";
                cin >> ch;
                if(ch == 'y' || ch == 'Y')
                    b.showCopy();
                break;
            }
        }
        if(flag == 0) {
            cout << "The book doesn't exist !";
        }
        f.close();
    }

    void displayAll(){ //method to display all available books
        fstream f;
        f.open(fname, ios::binary | ios::app | ios::in | ios::out);
        int count = 0;
        BOOKCOPY b;
        int ch;
        cout << "1. display all books\n2. display all available books\nEnter the choice :- ";
        cin >> ch;
        while( f.read((char*)&b, sizeof(BOOKCOPY))) {
           
            count++;
            if(ch == 1){
                b.showData();
                b.showCopy();
            }
            else if(ch == 2){
                b.showData();
            }
            else{
                cout << "Invalid Choice !";
                return;
            }
            cout << "------------------------------\n";
        }
        if(count == 0 && (ch == 1 || ch == 2))
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
        while( f.read((char*)&b, sizeof(BOOKCOPY))) {
            k++;
            if(b.getId() == id) {
                if(b.getCount() > 0)
                    return k;
            }
        }
        if(f.eof()) return 0;
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
        while( f.read((char*)&b, sizeof(BOOKCOPY))) {
            k++;
            if(b.getId() == bid) {
                break;
            }
        }
        if(k == 0){
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
        while( f.read((char*)&b, sizeof(BOOKCOPY))) {
            k++;
            if(b.getId() == bid) {
                break;
            }
        }
        if(k == 0){
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

//designing the class transaction to handle all different types of transaction
class TRANSACTION{ //exsitence of the triplet is mandatory 
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
    int getMemId(){ //method to get the member id
        return memId;
    }
    int getBookId(){//method to return member id
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
class TRANSACTIONFILE{
    char fname[31];
public:
    void getData() { //to get the binary file where transaction is stored
        cout << "Enter the transaction file name :- ";
        cin >> fname;
    }
    
    void makeTransaction(STUDENTFILE& obj1, FACULTYFILE& obj2, BOOKFILE& obj3) { //method to make transaction
        fstream f;
       f.open(fname, ios::binary | ios::ate | ios::in | ios::out);
        
        int ch;
        cout << "Enter the type of transaction you like to make\n1. issue a book\n2. return a book\n";
        cin >> ch;
        if(ch == 1){    //issue a book
            char memType = '\0';
            int id;
            cout << "Enter the id :- ";
            cin >> id;
            if(obj1.searchStudentById(id)){
                cout << "Member Type : Student\n";
                memType = 's';
            }
            else if(obj2.searchFacultyById(id)) {
                cout << "Member Type : Faculty\n";
                memType = 'f';
            }
            if(memType == '\0'){
                cout << "Sorry member with the same id doesn't exist !";
                return;
            }
            else { //proceed with other checkings
                int cntBooks = 0;
                TRANSACTION t;
                f.seekg(0);
                f.seekp(0);
                while(f.read((char*)&t, sizeof(TRANSACTION))) {       
                    if(t.getMemId() == id && t.getTransactionType() == 'i')  {
                        cntBooks++;                  
                    }
                }
                f.clear();
                cout << "Number of books issued so far :- "<< cntBooks << "\n";
                if(memType == 's'){ //setting conditions for students to issue a book
                    if(cntBooks < 2){ //book issue possible for student provided book is available
                        int bid;
                        cout << "Enter the book id :- ";
                        cin >> bid;
                        if(obj3.searchBookById(bid) > 0){
                            cout << "Book can be issued by the student !\n";
                            //take the last serial number from the list of books
                            char c;
                            cout << "Do you want to proceed (y/n) :- ";
                            cin >> c;
                            if(c == 'y' || c == 'Y'){ //book exists and is available for issue
                                int sno = obj3.updateBookStockIssue(bid);
                                TRANSACTION t1;
                                t1.getData(id, bid, sno, 'i');
                                if(sno != -1){
                                    f.write((char*)&t1, sizeof(TRANSACTION));
                                    cout << "Book issued successfully serial number :- " << sno << "\n";
                                }
                                else
                                    cout << "Transaction failed ! Book Not available \n";
                            }
                        }
                        //book doesn't exist      
                        else{
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
                else{ //setting conditions for book issue by faculty
                    if(cntBooks < 10){ //book issue possible for faculty provided book is available
                        int bid;
                        cout << "Enter the book id :- ";
                        cin >> bid;
                        if(obj3.searchBookById(id) == 2){
                            cout << "Book can be issued by the faculty !\n";
                            //take the last serial number from the list of books
                            char c;
                            cout << "Do you want to proceed (y/n) :- ";
                            cin >> c;
                            if(c == 'y' || c == 'Y'){
                                int sno = obj3.updateBookStockIssue(bid);
                                TRANSACTION t1;
                                t1.getData(id, bid, sno, 'i');
                                if(sno != -1){
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
        else if(ch == 2){ //return a book
            int sno, bid, mid;
            cout << "Enter the member id :- ";
            cin >> mid;
            cout << "Enter the book id :- ";
            cin >> bid;
            cout << "Enter the sno :- ";
            cin >> sno;
            int flag = 0, k = 0, nullcount = 0;
            //check if the triplet is present in the transaction list or not
            TRANSACTION t;
            f.seekg(0);
            f.seekp(0);
            while(f.read((char*)&t, sizeof(TRANSACTION))){
                k++;
                
                if(t.getBookId() == bid && t.getMemId() == mid && t.getSno() == sno && t.getTransactionType() == 'i'){
                    flag = 1;
                    break;
                }
                else if(t.getBookId() == bid && t.getMemId() == mid && t.getSno() == sno && t.getTransactionType() == '\0'){
                    nullcount++;
                } 
            }
            if(f.eof()) {
                if(nullcount > 0){
                    cout << "Book already returned ! \n";
                }
                else {
                    cout << "detail mismatch alert !\n";
                }
            }
            else{ //bring the get and the put pointer to proper location and then modify the record and finally add a new record 
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
        //incase if any other number is selected
       else{
            cout << "Invalid choice !\n";
            return;
        }
    }
    void displayTransaction() {
        fstream f;
        f.open(fname, ios::binary | ios::app | ios::in | ios::out);
        TRANSACTION t;
        cout << "bid mid sno trtype-----------\n";
        while(f.read((char*)&t, sizeof(TRANSACTION))) {
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
        while(f.read((char*)&t, sizeof(TRANSACTION))){
            if(t.getTransactionType() == 'i'){
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
    while(f.read((char*)&b, sizeof(BOOKCOPY))) {
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
        while(f.read((char*)&b, sizeof(BOOKCOPY))) {
            k++;
            if(b.getId() == id) {
                flag = 1;
                cout << "First Copy of the book already exists ! Would you like add a copy (y/n) :- ";
                cin >> ch;
                if(ch == 'y' || ch == 'Y'){ //record modfication is required
                    b.getCopy(*this, obj1); 
                    f.seekp(-1 * sizeof(BOOKCOPY), ios::cur);
                    f.write((char*)&b, sizeof(BOOKCOPY));
                    cout << "Book added sucessfully !\n";
                    f.close();
                    return;         
                }
            }
        }
        if(flag == 0){
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
    while(1) {
        //relevants objects to be declared   
        int ch; //rproviding choice to the user
        cout << "1. add Student\n2. add faculty\n3. display student by id\n4. display all students\n5. display faculty by id\n6. display all faculties\n7. add a book\n";
        cout << "8. display book by id\n9. display all books\n10. make a transaction\n11. display Transaction\n12. exit\n";
        cin >> ch;
        switch(ch) { //implementing switch case based operation handler
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
            case 10: obj4.makeTransaction(obj1, obj2, obj3);
                    break;
            case 11: obj4.displayTransaction();
                    break;
            default : exit(0);
        }
    }
    return 0;
}