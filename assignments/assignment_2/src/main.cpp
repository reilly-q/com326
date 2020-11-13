/*
* Main.cpp
*
* Version information
* Author: Dr. Shane Wilson
* Date:09/11/2017
* Description: Rule of Five
*
///**************************************************************************
// * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
// * Pearson Education, Inc. All Rights Reserved.                           *
// *                                                                        *
// * DISCLAIMER: The authors and publisher of this book have used their     *
// * best efforts in preparing the book. These efforts include the          *
// * development, research, and testing of the theories and programs        *
// * to determine their effectiveness. The authors and publisher make       *
// * no warranty of any kind, expressed or implied, with regard to these    *
// * programs or to the documentation contained in these books. The authors *
// * and publisher shall not be liable in any event for incidental or       *
// * consequential damages in connection with, or arising out of, the       *
// * furnishing, performance, or use of these programs.                     *
// **************************************************************************/


#include <iostream>
#include "Array.h"
using namespace std;

void outputArray(const Array &); // prototype
void outputArray(int); // prototype

int main() {
   Array integers1(7); // 7-element Array
   outputArray(integers1); // output Array integers1
   outputArray(3); // convert 3 to an Array and output Array's contents
   outputArray(Array(3)); // explicit single-argument constructor call

   //Add your code here to test each function of the Rule of Five


}  // end main

// print Array contents
void outputArray(const Array &arrayToOutput)
{
   cout << "The Array received has " << arrayToOutput.getSize()
      << " elements. The contents are:\n" << arrayToOutput << endl;
} // end outputArray

void outputArray(int) {

}






//Another example of the rule of three.


//#include <iostream>
//
//using namespace std;
//
//class Line {
//
//public:
//	int getLength(void);
//	Line(int len);             // simple constructor
//	Line(const Line &obj);  // copy constructor
//	~Line();                     // destructor
//
//private:
//	int *ptr;
//};
//
//// Member functions definitions including constructor
//Line::Line(int len) {
//	cout << "Normal constructor allocating ptr" << endl;
//
//	// allocate memory for the pointer;
//	ptr = new int;
//	*ptr = len;
//}
//
//Line::Line(const Line &obj) {
//	cout << "Copy constructor allocating ptr." << endl;
//	ptr = new int;
//	*ptr = *obj.ptr; // copy the value
//}
//
//Line::~Line(void) {
//	cout << "Freeing memory!" << endl;
//	delete ptr;
//}
//
//int Line::getLength(void) {
//	return *ptr;
//}
//
//void display(Line obj) {
//	cout << "Length of line : " << obj.getLength() << endl;
//}
//
//// Main function for the program
//int main() {
//	Line line(10);
//
//	display(line);
//
//	return 0;
//}
