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

bool checkFour(Card *inputHand){

    for(int i = 0; i < 2; i++){

        if(inputHand[i].Number == inputHand[i+1].Number &&
           inputHand[i+1].Number == inputHand[i+2].Number &&
           inputHand[i+2].Number == inputHand[i+3].Number 
           ){

               //change ordering so the 4 is at the end
            if(i == 0){
                Card tempCard = inputHand[4];
                inputHand[3] = inputHand[4];
                inputHand[2] = inputHand[3];
                inputHand[1] = inputHand[0];
                inputHand[4] = tempCard;
            }
            return true;
        }
    }
    return false;
}

bool checkHouse(Card *inputHand){

        if(inputHand[0].Number == inputHand[1].Number &&
           inputHand[1].Number == inputHand[2].Number &&
           inputHand[3].Number == inputHand[4].Number 
           ){

                Card cardOne = inputHand[0];
                Card cardTwo = inputHand[1];
                Card cardThree = inputHand[2];
                Card cardFour = inputHand[3];
                Card cardFive = inputHand[4];

                inputHand[0] = cardFour;
                inputHand[1] = cardFive;
                inputHand[2] = cardOne;
                inputHand[3] = cardTwo;
                inputHand[4] = cardThree;

            return true;
        }
        if(inputHand[0].Number == inputHand[1].Number &&
           inputHand[2].Number == inputHand[3].Number &&
           inputHand[3].Number == inputHand[4].Number 
           ){
        


            return true;
        }


    return false;
}
bool checkThree(Card *inputHand){

    for(int i = 0; i < 3; i++){

        if(inputHand[i].Number == inputHand[i+1].Number &&
           inputHand[i+1].Number == inputHand[i+2].Number 
           ){

            return true;
        }
    }
    return false;
}


bool checkOnePair(Card *inputHand){

    for(int i = 0; i < 4; i++){

        if(inputHand[i].Number == inputHand[i+1].Number){
            return true;
        }
    }
    return false;
}

bool checkTwoPair(Card *inputHand){

    int numDup = 0;
    for(int i = 0; i < 4; i++){
        if(i < 3){

            if(inputHand[i].Number == inputHand[i+1].Number && inputHand[i+1].Number != inputHand[i+2].Number){
                numDup += 1;
            }
        }
        else{

            if(inputHand[i].Number == inputHand[i+1].Number){
                numDup += 1;
            }
        }
    }
    if(numDup == 2){
        return true;
    }
    else{
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

int handVal(Card *hand){
        if(checkRoyalFlush(hand)){
            cout << "this be royal flush\n";
            return 9;
        }
        else if(checkStraightFlush(hand)){
            cout << "this be straight flush\n";
            return 8;
        }
        else if(checkFour(hand)){
            cout << "this be four\n";
            return 7;
        }
        else if(checkHouse(hand)){
            cout << "this be house\n";
            return 6;
        }
        else if(checkFlush(hand)){
            cout << "this be flush\n";
            return 5;
        }
        else if(checkStraight(hand)){
            cout << "this be straight \n";
            return 4;
        }
        else if(checkThree(hand)){
            cout << "this be three\n";
            return 3;
        }
        else if(checkTwoPair(hand)){
            cout << "this be twoPair\n";
            return 2;
        }
        else if(checkOnePair(hand)){
            cout << "this be Pair\n";
            return 1;
        }
        else{
            cout << "this be single\n";
            return 0;
        }
}


int checkHighest(Card *player1, Card *player2){
    for(int i = 4; i >= 0; i--){

        if(player1[i].Number > player2[i].Number){
            return 1;
        }
        else if(player1[i].Number < player2[i].Number){
            return 2;
        }
    }
    return 0;
}

int main() {

    string currentLine;
    ifstream PokeFile("poker.txt");

    int p1Wins = 0;
    
    while(getline(PokeFile, currentLine)){
        cout << "::::" << currentLine << "\n";
        string Player1 = currentLine.substr(0,14);
        string Player2 = currentLine.substr(15,29);
        cout << "Player1: ";
        Card player1Hand[5];
        processHand(Player1, player1Hand);
        printCard(player1Hand);
        int p1Value = handVal(player1Hand);

        cout << "Player2: ";
        Card player2Hand[5];
        processHand(Player2, player2Hand);
        printCard(player2Hand);
        int p2Value = handVal(player2Hand);
        if(p1Value > p2Value)
        {
            cout << "    P1 Wins\n";
            p1Wins += 1;
        }
        else if(p1Value < p2Value){
            cout << "    P2 Wins\n";
        }
        else{
            int Winner = checkHighest(player1Hand, player2Hand);
            if(Winner == 1)
            {
                cout << "    Tie P1 wins\n";
                p1Wins += 1;
            }
            else if(Winner == 2)
            {
                cout << "    Tie P2 wins\n";
            }
            else
            {
                cout << "     Equal\n";
            }


        }
    }

    cout << "P1 wins: " << p1Wins << "\n";

    return 0;
}