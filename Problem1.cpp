#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "Input Number:\n";

    vector<int> multArray;

    int userNum;
    cin >> userNum;

    cout << "ur thingy: " << userNum;

    for(int i = 0; i < userNum; i++){
        if(i % 5 == 0 || i % 3 == 0){
            multArray.push_back(i); 
        } 
    }

    int total = 0;
    for(int j = 0; j < multArray.size(); j++){
        total += multArray[j];
        cout << "in arry:" << multArray[j] << "\n";
    }

    cout << "value is:" << total << "\n";
    return 0;
}