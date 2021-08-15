#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "Input Number:\n";

    vector<int> multArray;

    int userNum;
    cin >> userNum;

    cout << "ur thingy: " << userNum;

    int one = 1;
    int two = 2;

    cout << "/nvalue is:" << one << "\n";
    cout << "value is:" << two << "\n";

    int curVal = 0;
    int curFib = two;

    int totalEven = 2;
    for(int curVal = 0; curVal < userNum; curVal++){

        curFib = one + two;

        one = two;
        two = curFib;
        if(curFib > userNum)
        {
            break;
        }

        cout << "value is:" << curFib << "\n";
        if(curFib % 2 == 0)
        {
            totalEven += curFib;
        }
    }


    cout << "total even is:" << totalEven << "\n";

    return 0;
}