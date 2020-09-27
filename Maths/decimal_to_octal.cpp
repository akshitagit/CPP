/*

CPP program to convert Decimal number 
to Octal number.

*/

#include <iostream>
using namespace std;

// Function
int decimalToOctal(int decimalNumber) {
   int octalNumber = 0, placeValue = 1;
   int dNo = decimalNumber;
   while (decimalNumber != 0) {
      octalNumber += (decimalNumber % 8) * placeValue;
      decimalNumber /= 8;
      placeValue *= 10;
   }

    return octalNumber;
}

// Main Function
int main() {
   cout<<decimalToOctal(70);
   return 0;
}
