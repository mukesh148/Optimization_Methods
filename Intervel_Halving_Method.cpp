#include <iostream>
#include <cmath>
using namespace std;


// Function to be Minimized//
float function(float x){
	return ( x*x + 54/x );
}

// float function(float x){
// 	return ( 2*exp(x) - x*x*x - 10*x );
// }

// float function(float x){
// 	return ( x*x - 10*exp(0.1*x) );
// }

int main(){

	// Initial parameters to be provided by user//
	float start, end, eps;
	cout << "Lower Intervel Bound - ";
	cin >> start;
	cout << endl;
	cout << "Upper Intervel Bound - ";
	cin >> end;
	cout << endl;
	cout << "Accuracy level - ";
	cin >> eps;
	cout << endl;
	
	// L - Intervel diffrence// 
	float L = end - start;
	// mid - middle value between Intervel Range//
	float mid = start + (end - start) / 2.0;
	float x1 = start + L / 4.0;
	float x2 = end - L / 4.0;
	
	// Count number of iterations//
	int count = 0;
	
	// Keep iterating till Intervel diffrence is grater than accuracy level//
	while(L > eps){

		// compare F(x1) and F(x2) with F(mid)//
		// if F(x1) > F(mid) then minimum value can't in the left of x1 so eliminate left region of x1//
		// if F(x2) > F(mid) then minimum value can't in the right of x2 so eliminate right region of x2//
		float midVal = function(mid);
		if( function(x1) <  midVal){
			end = mid;
		}
		else if( function(x2) < midVal ){
			start = mid;
		}
		else{
			start = x1;
			end = x2;
		}

		L = end - start;
		mid = start + (end - start) / 2.0;
		x1 = start + L / 4.0;
		x2 = end - L / 4.0;

		cout << ++count << " Iteration is over. Intervel found till now - (" << start << ", " << end << ")" << endl;

	}
	cout << endl;
	cout << "Found Optimal Intervel After - " << count << " Iteration " << endl;
	cout << "Optimal Intervel - (" << start << ", " << end << ")" << endl;
	return 0;
}