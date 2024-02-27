#include <iostream>
#include <ctime>
#include <time.h>
#include <vector>
#include <string.h>
using namespace std;
vector<string> choiceOfComputer = {"rock", "paper", "scissor"};
string computersChoice(vector<string> &choiceOfComputer)
{
    srand(time(0));
    int randomChoice = rand() % choiceOfComputer.size();
    return choiceOfComputer[randomChoice];
}
int main()
{
    bool mark = true,flag=true;
    int numberCount, computerWins = 0, userWins = 0, tie = 0;
    cout << "Enter the number of times you want to play: ";
    cin>>numberCount;
    while(numberCount>0)
    {
        string computersChoiceFinal = computersChoice(choiceOfComputer);
        // cout << computersChoiceFinal << endl;
        string playersChoice;
        cout << "Enter Your Choice:-  ";
        cin >> playersChoice;
        if (playersChoice == "rock" || playersChoice == "paper" || playersChoice == "scissor")
        {
            if(playersChoice==computersChoiceFinal)
                cout<<"It is a Tie, Try again!\n";
            else if((playersChoice=="rock" && computersChoiceFinal=="paper") || (playersChoice=="paper" && computersChoiceFinal=="scissor") || (playersChoice=="scissor" && computersChoiceFinal=="rock"))
            {    
                computerWins++;
                cout<<"The User's Choice is "<<playersChoice<<" Computer's Choice is "<<computersChoiceFinal<<"\nComputer Wins This Round"<<endl;
            }
            else
            {
                cout<<"The User's Choice is "<<playersChoice<<" Computer's Choice is "<<computersChoiceFinal<<"\nUser Wins This Round"<<endl;
                userWins++;
            }  
            numberCount--;
        }
        else
        {
            cout<<"INVALID CHOICE"<<endl;
            mark=false;
        }
    }
    if (computerWins > userWins)
        cout << "Computer Wins the Game!\n";
    else if (userWins > computerWins)
        cout << "You Win the Computer, You Supreme Being!\n";
    else
        cout << "It's a Tie!\n";
    return 0;
}
