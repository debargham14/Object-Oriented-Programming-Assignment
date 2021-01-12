#include<iostream>
#include<map>
using namespace std;

class BATCH5{
    map<int, int> m; //map to implement the given functionality
public:
    void operate () {
        while(1) {
            cout << "1. add student data\n2. show score against a roll\n";
            cout << "Enter choice :- ";
            int ch, roll, score;  cin >> ch;
            switch(ch) {
                case 1:{ 
                    cout << "Enter student roll :- ";
                    cin >> roll;
                    cout << "Enter score of the student :- ";
                    cin >> score;
                    //insertion chech needs to be performed 
                    pair<map<int, int>::iterator, bool> p = m.insert(map<int, int>::value_type(roll, score));
                    if(p.second) //insertion done !
                        cout << "Insertion sucessful !\n";
                    else
                        cout << "Insertion unsucessful :(\n";
                    break;
                }
                case 2:{ //to check the presence of a roll number 
                    cout << "Enter roll number :- ";
                    cin >> roll;
                    if(m.find(roll) != m.end()) { // check if roll exists or not
                        cout << "score of the student :- " << m[roll] << "\n";
                    }
                    else 
                        cout << "Invalid roll number !\n";
                    break;
                } // else we can exit out 
                default : exit(0);
            }
            cout << "\n";
        }
    }
};
//driver function to implement the functionality
int main() {
    BATCH5 obj;
    obj.operate();
    return 0;
}