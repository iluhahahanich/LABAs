#include "Class.h"
int main() {
	Fraction f1(1 , -2) , f2(6 , 8), f3(6, -3), f4(10 ,-3), f5(0, -12)  ; 
	f1.getFraction();    
	f2.getFraction();	
	f3.getFraction();	
	f4.getFraction();
	f5.getFraction();
	cout << "\n";
	cout << "the Sum of f1 and f2: ";  (f1 + f2).getFraction();
	cout << "the Product of f1 and f4: "; (f1 * f4).getFraction();
	cout << "the Ratio of f2 and f4: "; (f2 / f4).getFraction();
	cout << '\n';
	Fraction o(1, 0);
}