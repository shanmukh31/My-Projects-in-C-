#include <iostream>
#include<vector>
#include<string>
using namespace std;
vector<vector<string>> positionArray;//(3, vector<char>(3));
string player="X";
bool tieBoolean = true;
int count = 0;
void drawBoard()
{
    cout << "\n\n"<< endl;
    cout << "\t\t|---------------|---------------|---------------|" << endl;
    cout << "\n\t\t|\t"<< positionArray[0][0] << "\t|\t" << positionArray[0][1] << "\t|\t" << positionArray[0][2] << "\t|\t\n"<< endl;
    cout << "\t\t|---------------|---------------|---------------|" << endl;
    cout << "\n\t\t|\t"<< positionArray[1][0] << "\t|\t" << positionArray[1][1] << "\t|\t" << positionArray[1][2] << "\t|\t\n"<< endl;
    cout << "\t\t|---------------|---------------|---------------|" << endl;
    cout << "\n\t\t|\t"<< positionArray[2][0] << "\t|\t" << positionArray[2][1] << "\t|\t" << positionArray[2][2] << "\t|\t\n"<< endl;
    cout << "\t\t|---------------|---------------|---------------|" << endl;
    cout << "\n\n"<< endl;
}
bool checkWinner()
{
    for (int i = 0; i < 3; i++) {
        if (positionArray[i][0] == player && positionArray[i][1] == player && positionArray[i][2] == player)
            return true;
    }
    for (int i = 0; i < 3; i++){
        if (positionArray[0][i] == player && positionArray[1][i] == player && positionArray[2][i] == player)
            return true;
    }
    if (positionArray[0][0] == player && positionArray[1][1] == player && positionArray[2][2] == player)
        return true;
    if (positionArray[0][2] == player && positionArray[1][1] == player && positionArray[2][0] == player)
        return true;
    return false;
}
void move()
{
    int choice;
    cout<<player<<"-->"<<"Enter the postion where you want to enter : ";
    cin>>choice;
    if(choice>9 || choice<1)
    {
        cout<<"\nInvalid Input ,Run the program again\n";
        move();
    }
    else
    {
        switch(choice)
        {
            case 1:
                    if(positionArray[0][0]=="1")
                        positionArray[0][0]=player;
                    else
                    {
                        cout<<"Position Already Taken, ReEnter a different position\n";
                        move();
                    }
                    break;
            case 2:
                    if(positionArray[0][1]=="2")
                        positionArray[0][1]=player;
                    else
                    {
                        cout<<"Position Already Taken, ReEnter a different position\n";
                        move();
                    }
                    break;
            case 3:
                    if(positionArray[0][2]=="3")
                        positionArray[0][2]=player;
                    else
                    {
                        cout<<"Position Already Taken, ReEnter a different position\n";
                        move();
                    }
                    break;
            case 4:
                    if(positionArray[1][0]=="4")
                        positionArray[1][0]=player;
                    else
                    {
                        cout<<"Position Already Taken, ReEnter a different position\n";
                        move();
                    }
                    break;
            case 5:
                    if(positionArray[1][1]=="5")
                        positionArray[1][1]=player;
                    else
                    {
                        cout<<"Position Already Taken, ReEnter a different position\n";
                        move();
                    }
                    break;
            case 6:
                    if(positionArray[1][2]=="6")
                        positionArray[1][2]=player;
                    else
                    {
                        cout<<"Position Already Taken, ReEnter a different position\n";
                        move();
                    }
                    break;
            case 7:
                    if(positionArray[2][0]=="7")
                        positionArray[2][0]=player;
                    else
                    {
                        cout<<"Position Already Taken, ReEnter a different position\n";
                        move();
                    }
                    break;
            case 8:
                    if(positionArray[2][1]=="8")
                        positionArray[2][1]=player;
                    else
                    {
                        cout<<"Position Already Taken, ReEnter a different position\n";
                        move();
                    }
                    break;
            case 9:
                    if(positionArray[2][2]=="9")
                        positionArray[2][2]=player;
                    else
                    {
                        cout<<"Position Already Taken, ReEnter a different position\n";
                        move();
                    }
                    break;
        }
        count++;
    }
}
int main()
{
    positionArray={{"1", "2", "3"},{"4", "5", "6"},{"7", "8", "9"}};
    while(true)
    {
        drawBoard();
        move();
        if(checkWinner())
        {
            drawBoard();
            cout<<player<<" Wins!!\n"<<endl;
            tieBoolean=false;
            if(count==9)
                break;
            break;
        }
        player=(player=="X") ? "O" : "X";
    }
    if(count==9 && tieBoolean==true)
        cout<<"The Game is a TIE\n"<<endl;
    return 0;
}
