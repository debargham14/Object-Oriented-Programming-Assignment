#include<iostream>
using namespace std;

//designing the class CRIKETER
class CRIKETER{
protected:
    char name[31];
    char dateOfbirth[31];
    int matchesPlayed;
public:
    void getData() { //defining the method getData to take the details
        cout << "Enter the name :- ";
        scanf(" %[^\n]s", name);
        cout << "Enter Date of Birth :- ";
        scanf(" %[^\n]s", dateOfbirth);
        cout << "Enter the number Of matches Played :- ";
        cin >> matchesPlayed;
    }
    //show the basic player details
    void showData() {
        cout << "Name of the Player :- " << name << "\n";
        cout << "DATE OF BIRTH :- " << dateOfbirth << "\n";
        cout << "Number Of matches played :- " << matchesPlayed << "\n";
    }
};

//designing the class BATSMAN
class BATSMAN: virtual public CRIKETER{
protected:
    int totalRunsScored;
    double avgScore;
public:
    void getDataBatsman() { //defining the method getData for batsman
        cout << "Enter the total Run scored :- ";
        cin >> totalRunsScored;
    }
    //defining the method to calculate the average score out of everything
    void calAverage() {
        avgScore = (double (totalRunsScored)) / (double (matchesPlayed));
    }
    void showDataBatsman() { //defining the method showData to show the player details as a batsman
        calAverage(); //call to the function to calculate the average score
        cout << "Total Runs scored :- " << totalRunsScored << "\n";
        cout << "Average Score :- " << avgScore << "\n"; 
    }
};

//designing the class bOWLER
class BOWLER: virtual public CRIKETER{
protected:
    int wickets;
    double economy;
public:
    void getDataBowler() { //defining the method getData for the class BOWLER
        cout << "Enter the number of wickets taken :- ";
        cin >> wickets;
    }
    void calEconomy() { //defining the method cal economy to calculate the economy
        economy = (double(wickets)) / (double(matchesPlayed));
    } 
    void showDataBowler() { //defining the method show Data to show the bowler data
        calEconomy(); // call to method is made to calculate economy
        cout << "Number of wickets taken :- " << wickets << "\n";
        cout << "Economy :- " << economy << "\n";
    }
};

//designing the class allrounder (having both the qualities of batsman and bowler)
class ALLROUNDER: public BATSMAN, public BOWLER{
public:
    void getData() {    //call to all the three functions made to recieve the data
        CRIKETER::getData();    //to get the general details
        getDataBatsman();       //to get the batsman details
        getDataBowler();        //to get the bowler details
    }
    void showData(){ //call to both the functions made
        CRIKETER::showData();
        showDataBatsman();
        showDataBowler();
    }
};
//designing the class WICKETPAIR (batsman object and bowler object)
class WICKETPAIR{
    BATSMAN obj1;
    BOWLER obj2;
public:
    void getData() { //to accept the wicket pair details
        obj1.getData();
        obj1.getDataBatsman();
        obj2.getData();
        obj2.getDataBowler();
    }
    void showData() { //to show the wicket pair details
        cout << "\n";
        obj1.showData();
        obj1.showDataBatsman();
        cout << "\n";
        obj2.showData();
        obj2.showDataBowler();
    }
};
//driver funtion to implement the above classes
int main() {
    ALLROUNDER obj1;
    WICKETPAIR obj2;
    obj1.getData();
    obj1.showData();

    cout << "---------------------------------\n";

    obj2.getData();
    obj2.showData();
    return 0;
}