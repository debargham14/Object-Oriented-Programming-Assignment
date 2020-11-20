#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
typedef long long ll;

// //function to multiply two numbers
// ll mult(ll a, ll b) {
// 	ll c = a * b;
// 	return c;
// }

//inline function to multiply the two numbers
inline ll multiply(ll a, ll b) {
	ll c = a * b;
	return c;
}

int main() {

	//to check the time taken by the online function
	// auto start = high_resolution_clock::now();
	// for (int i = 0; i < 100000; i++) {
	// 	int c = mult(i , i + 1);
	// }
	// auto stop = high_resolution_clock::now();
	// //end of the execution of first funtion -------------------------------------


	auto start1 = high_resolution_clock::now();
	for (int i = 0; i < 100000; i++) {
		int c = multiply(i , i + 1);
	}
	auto stop1 = high_resolution_clock::now();
	// //end of the execution of first funtion -------------------------------------

	//calculation of time
	//auto duration = duration_cast<nanoseconds>(stop - start);
	auto duration1 = duration_cast<nanoseconds>(stop1 - start1);

	//cout << "Time required for the execution of the first function 1e5 times : " << duration.count() << "\n";
	cout << "Time required for the execution of the second function 1e5 times : " << duration1.count() << "\n";

	// const char *c = (duration.count() > duration1.count()) ? "first" : "second";
	// cout << c << " function takes more time";
	return 0;
}