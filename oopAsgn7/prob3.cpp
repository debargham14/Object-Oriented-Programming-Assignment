#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

//designing the class student
class STUDENT{
    //basic attributes
    int roll;
    string name;
    int score;
public:
    STUDENT(int r = 0, string word = "", int s = 0){ //default constructor
        roll = r; name = word; score = s;
    }
    void getData() {//method to get the student related information
        cout << "Enter name of the student :- ";
        cin >> name;
        cout << "Enter Roll Number of the student :- ";
        cin >> roll;
        cout << "Enter the score of the student :- ";
        cin >> score;
    }
    void showData() { //method to display the stduent data
        cout << "Name of the student :- " << name << "\n";
        cout << "Roll Number :- " << roll << "\n";
        cout << "Score of the student :- " << score << "\n";
    }
    int retScore() { //method to return the score
        return score;
    }
    string getName() { //method to get the student name
        return name;
    }
    bool operator == (STUDENT& s1) const {
        return (s1.name == name && roll == s1.roll && score == s1.score);
    }
    int retRoll(){
        return roll;
    }
};
//designing the utility class required to compare by score 
class compByRoll {
    int r;
    public:
        compByRoll(int r1 = 0){
            r = r1;
        }
        bool operator () (STUDENT& s1) {
            return s1.retRoll() == r;
        }
};
//deisgning the class batch 3 to implment the functionality
class BATCH3{
    vector<STUDENT> v; 
    queue<int> q;
public:
    void operate() {
        STUDENT s; int n;
        cout << "Enter the number of students :- ";
        cin >> n;
        for(int i = 0; i < n; i++){
            s.getData();
            v.push_back(s);
        }
        while(1){
            int ch, r = 0;
            cout << "1. Add Student in a queue\n2. collect Marksheet\n";
            cout << "Enter choice :- ";
            cin >> ch;
            switch(ch) {
                case 1: cout << "Enter roll number :- ";
                        cin >> r;
                        q.push(r);
                        break;
                case 2: {
                            if(q.empty())
                                cout << "Empty queue !";
                            else {
                                int r1 = q.front();
                                vector<STUDENT>::iterator itr = find_if(v.begin(), v.end(), compByRoll(r1));
                                if(itr == v.end()){
                                    cout << "Entered roll is invalid !\n";
                                }
                                else{
                                    cout << "---------------********------------\n";
                                    v[itr - v.begin()].showData();
                                    cout << "------------collected from jdv office---------\n";
                                    q.pop();
                                }
                            }
                            break;
                }
                default: exit(0);
            }
        }
    }
};

int main() {
    BATCH3 obj;
    obj.operate();
    return 0;
}