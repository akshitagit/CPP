// Difference between a post-test and a pre-test loop.

#include <iostream>
using namespace std;

int main(){
    int myNum = 1;
    
    cout << "Pre-test loop (TRUE): \n";
    while (myNum <= 5){     // This block will be executed
        cout << myNum << endl;
        myNum++;    
    }

    cout << "\nPre-test loop (FALSE): \n";
    myNum = 1;
    while (myNum > 10){     // This loop will NOT be executed
        cout << "Larger than 10.";
        myNum--;
    }

    do {
        cout << "\n\nPost-test loop. Print this at least once no matter what.\n\n";
        myNum--;
    } while (myNum > 0);

    return 0;
}
