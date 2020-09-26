/*
    Given an integer, A, implement a C++ 
    program to convert A into a string 
    that represents its Roman numeral.
*/
#include <bits/stdc++.h>
using namespace std;

map<string, int> romanNumeralsMap = {
    {"I",  1},
    {"IV", 4},
    {"V",  5},
    {"IX", 9},
    {"X",  10},
    {"XL", 40},
    {"L",  50},
    {"XC", 90},
    {"C",  100},
    {"CD", 400},
    {"D", 500},
    {"CM", 900},
    {"M",  1000}
};

string greatestDivisor(int num) {
    string divisor;

    if (num%romanNumeralsMap["M"] != num) {
            divisor = "M";
    } else if (num%romanNumeralsMap["CM"] != num) {
            divisor = "CM";
    } else if (num%romanNumeralsMap["D"] != num) {
            divisor = "D";
    } else if (num%romanNumeralsMap["CD"] != num) {
            divisor = "CD";
    } else if (num%romanNumeralsMap["C"] != num) {
            divisor = "C";
    } else if (num%romanNumeralsMap["XC"] != num) {
            divisor = "XC";
    } else if (num%romanNumeralsMap["L"] != num) {
            divisor = "L";
    } else if (num%romanNumeralsMap["XL"] != num) {
            divisor = "XL";
    } else if (num%romanNumeralsMap["X"] != num) {
            divisor = "X";
    } else if (num%romanNumeralsMap["IX"] != num) {
            divisor = "IX";
    } else if (num%romanNumeralsMap["V"] != num) {
            divisor = "V";
    } else if (num%romanNumeralsMap["IV"] != num) {
            divisor = "IV";
    } else if (num%romanNumeralsMap["I"] != num) {
            divisor = "I";
    }        
    
    return divisor;
}

string toRomanNumeral(int arabic) {
    string roman = "";

    if (arabic <= 0 || arabic > 3000) {
            return "";
    }

    while (arabic != 0) {
            string divisor = "M";

            if (arabic < 1000) {
                    divisor = greatestDivisor(arabic);
            }

            int times = arabic / romanNumeralsMap[divisor];

            for(int i = 0; i < times; i++) {
                roman += divisor;
            }

            arabic = arabic % romanNumeralsMap[divisor];
    }

    return roman;
}


int main() {
    int integer;
    cin >> integer;

    string romanNumeral = toRomanNumeral(integer);
    cout << romanNumeral << endl;

    return 0;
}
