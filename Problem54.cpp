#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <typeinfo>
#include <stdlib.h>

using namespace std;

struct Card {
    int Number;
    string Suit;
};


void printCard(Card *inputHand)
{
    cout << "CPRINT: ";
    for(int ii = 0; ii < 5; ii++){
        cout << "" << inputHand[ii].Number << "" << inputHand[ii].Suit << " ";
    }
    cout << "\n";
}


bool checkStraight(Card *inputHand){

    if(inputHand[0].Number == (inputHand[1].Number - 1) &&
       inputHand[1].Number == (inputHand[2].Number - 1) &&
       inputHand[2].Number == (inputHand[3].Number - 1) &&
       inputHand[3].Number == (inputHand[4].Number - 1) 
       )
       {
           return true;
       }
       else
       {
           return false;
       }
}

bool checkFlush(Card *inputHand){
    if(inputHand[0].Suit == inputHand[1].Suit &&
       inputHand[1].Suit == inputHand[2].Suit &&
       inputHand[2].Suit == inputHand[3].Suit &&
       inputHand[3].Suit == inputHand[4].Suit)
       {
           return true;
       }
       else{
           return false;
       }
}

bool checkStraightFlush(Card *inputHand){
    if(checkFlush(inputHand) && checkStraight(inputHand))
    {
        return true;
    }
    else{
        return false;
    }
}

bool checkRoyalFlush(Card *inputHand){
    if(inputHand[0].Number == 10 && checkFlush(inputHand) && checkStraight(inputHand))
    {
        return true;
    }
    else{
        return false;
    }
}

bool checkOnePair(Card *inputHand){
    if(inputHand[0].Number == inputHand[1].Number ||
       inputHand[1].Number == inputHand[2].Number ||
       inputHand[2].Number == inputHand[3].Number ||
       inputHand[3].Number == inputHand[4].Number) {
           return true;
       }
       else {
           return false;
       }
}

//sorts and processes string into card array
void processHand(string input, Card *outPutHand){

    int curCardIndex = 0;

    string onlyNum = "";
    for(int i = 0; i < input.length(); i+=3)
    {
        Card curCard;
        int num;
        if(input[i] == 'T'){
            num = 10;
        }
        else if(input[i] == 'J'){
            num = 11;
        }
        else if(input[i] == 'Q'){
            num = 12;
        }
        else if(input[i] == 'K'){
            num = 13;
        }
        else if(input[i] == 'A'){
            num = 14;
        }
        else
        {
            num = (int)input[i] - 48;
        }

        curCard.Number = num; 
        curCard.Suit = input[i+1]; 
        outPutHand[curCardIndex] = curCard;
        curCardIndex += 1;
    }

    //Perform bubble sort of the hand array
    for(int j = 0; j < 5; j++)
    {
        for(int k = 0; k < 4; k++){

            if(outPutHand[k+1].Number < outPutHand[k].Number){
                Card temp = outPutHand[k];
                outPutHand[k] = outPutHand[k+1];
                outPutHand[k+1] = temp;
            }
        }
    }

}

int main() {

    string currentLine;
    ifstream PokeFile("poker.txt");
    
    while(getline(PokeFile, currentLine)){
        //cout << currentLine << "\n";
        string Player1 = currentLine.substr(0,14);
        string Player2 = currentLine.substr(15,29);
        cout << "Player1: " << Player1 << "\n";
        Card player1Hand[5];
        processHand(Player1, player1Hand);

        printCard(player1Hand);
        if(checkRoyalFlush(player1Hand)){
            cout << "this be royal flush\n";
        }
        else if(checkStraightFlush(player1Hand)){
            cout << "this be straight flush\n";
        }
        else if(checkFlush(player1Hand)){
            cout << "this be flush\n";
        }
        else if(checkStraight(player1Hand)){
            cout << "this be straight \n";
        }
        Card player2Hand[5];
        processHand(Player2, player2Hand);
    }

 

    return 0;
}