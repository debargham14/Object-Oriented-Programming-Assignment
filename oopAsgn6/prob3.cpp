#include<iostream>
#include<climits>
using namespace std;

//class template for 1D array containing basic data types 
template<class T>
class ARRAY{
    static T M;
    T *arr;
    int size;
public:
    //deisgniing the relevant constructor
    ARRAY(int s = 0){
        if(s == 0)
            arr = NULL;
        else 
            arr = new T[s];
        size = s;
    }   
    //deisigning the mehtod to get the array elements
    void getData() {
        cout << "Enter " << size << " elements :- ";
        for(int i = 0; i < size; i++)   cin >> arr[i];
    }
    //designing the method to display the array elements 
    void showData() {
        cout << "The elements are :- ";
        for(int i = 0; i < size; i++)   cout << arr[i] << " "; 
    }
    //method to find the maximum element
    T retMax() {
        for(int i = 0; i < size; i++)
            M = max(M, arr[i]);
        return M;
    }
    //method to return the sum of elements 
    T retSum() {
        T s = 0;
        for(int i = 0; i < size; i++)   s += arr[i];
        return s;
    }
};
template<class T>
T ARRAY<T>::M = (T)INT_MIN;

int main() {
    ARRAY<float> a(5);
    a.getData();
    cout << "\n";
    a.showData();
    cout << "\n";
    cout << "Max and sum of all the elemets :- " << a.retMax() << " " << a.retSum() << "\n"; 
    return 0;
}
