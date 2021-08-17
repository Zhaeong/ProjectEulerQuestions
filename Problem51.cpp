#include <iostream>
#include <vector>
#include <string>
#include "PrimeTest.h"

using namespace std;

int main() {
    cout << "Input Number:\n";

    vector<int> multArray;

    int userNum;
    cin >> userNum;

    cout << "ur thingy: " << userNum;

 
    bool isIT = isPrime(userNum);

    cout << "value is:" << isIT << "\n";
    return 0;
}