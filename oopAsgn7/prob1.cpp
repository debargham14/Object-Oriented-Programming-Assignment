#include<iostream>
#include<string>
#include<vector>
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
class compByScore {
    public:
        bool operator () (STUDENT& s1, STUDENT& s2) {
            return (s1.retScore() < s2.retScore());
        }
};

//designing the utility class to find a student whose name contains a substring
class checkSubstringPresent {
    string name1;
    public:
        checkSubstringPresent(string dummy = ""){
            name1 = dummy;
        }
        void operator () (STUDENT& s1) const{
            string name = s1.getName();
            for(int i = 0; i <= (int)name.size(); i++) {
                for(int j = i + 1; j <= (int)name.size(); j++) {
                    if(name.substr(i, j) == name1)
                    {
                        s1.showData();
                        cout << "\n";
                        return;
                    }
                }
            }
        }
};

class checkByScore {
    int score;
    public:
        checkByScore(int s = 0) {
            score = s;
        }
        void operator () (STUDENT& s1) const {
            if (s1.retScore() == score){
                s1.showData(); 
                cout << "--------------------------\n";
            }
        }
};
//desinging the batch class
class BATCH{
    vector<STUDENT> v;
public:
    void operate() {
        while(1) { //menu driven program to implement all the functionalities 
            int ch;
            cout << "1. Add Student\n2. Display Number of students\n3. Show Student with highest score\n4. Find student with substring\n";
            cout << "Enter choice :- ";
            cin >> ch;
            STUDENT s; string subString;
            switch(ch) {
                case 1: s.getData();
                        v.push_back(s);
                        cout << "Student Data entry sucessful !";
                        break;
                case 2: cout << "Number students :- " << v.size() << "\n";
                        break; 
                case 3: {
                            vector<STUDENT>::iterator itr = max_element(v.begin(), v.end(), compByScore());
                            int sc = v[itr - v.begin()].retScore();
                            for_each(v.begin(), v.end(), checkByScore(sc));
                            break;
                }   
                case 4: {
                            cout << "Enter the substring :- ";
                            cin >> subString;
                            for_each(v.begin(), v.end(), checkSubstringPresent(subString));
                            break;
                }
                default: exit(0);
                        break;
            }
            cout << "\n";
        }
    }
};
//driver function to use the above functionalities
int main() {
    BATCH obj;
    obj.operate();
    return 0;
}
