#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <time.h>
using namespace std;
int guessCount = 0;
bool ifNotGuessed = true;
vector<string> wordsToPlay = {
    "Abacus", "Abrupt", "Abroad", "Absorb", "Abused", "Accept", "Access", "Accuse", "Admire", "Adored", "Advise",
    "Beyond", "Bishop", "Border", "Bottom", "Bought", "Branch", "Bamboo", "Budget", "Bureau", "Ballot", "Behind",
    "Camera", "Carbon", "Change", "Church", "Center", "Casual", "Circle", "Copper", "County", "Credit", "Couple",
    "Decade", "Defeat", "Depend", "Device", "Deputy", "Debate", "Doctor", "Differ", "Driver", "Depend", "During",
    "Apple", "Banana", "Cat", "Dog", "Elephant", "Fish", "Giraffe", "House",
       "Ice Cream", "Jacket", "Kite", "Lion", "Monkey", "Nest", "Octopus", "Piano",
       "Apricot", "Backpack", "Blanket", "Bracelet", "Bubble", "Butterfly",
       "Rainbow", "Rocket", "Ruby", "Sandwich", "Scar", "Scissors",
       "Scooter", "Sculpture", "Seagull", "Seashell", "Seedling", "Seesaw", "Sequoia",
       "Shadow", "Shampoo", "Shipwreck", "Shoemaker", "Shower",
       "Sidewalk", "Silkworm", "Silverware", "Skates", "Skyscraper",
       "Slingshot", "Snail", "Snowflake", "Soda",
       "Spaceship", "Sparkler", "Sparrow", "Sphinx", "Spice rack", "Squirrel",
       "Stadium", "Staircase", "Starfruit", "Starship", "Statue", "Steamboat",
       "Stethoscope", "Stingray", "Stork", "Storytelling", "Stovetop", "Submarine",
       "Sunflower", "Sunset", "Surfboard", "Swan",
       "Symphony", "Telescope", "Tent", "Thermometer",
       "Thread", "Thunderstorm", "Tightrope", "Tiger", "Toolbox", "Toothbrush",
       "Tornado", "Train","Station", "Trampoline", "Treasure chest", "Treehouse",
       "Tricycle", "Trombone", "Tunnel", "Turtle", "Twister", "Umbrella", "Unicycle"

    };
vector<string> drawHangMan = {
    "-----------------\n+",
    "-----------------\n+\t|\t\n",
    "-----------------\n+\t|\t\n\t|\t\n",
    "-----------------\n+\t|\t\n\t|\t\n\tO\t\n",
    "-----------------\n+\t|\t\n\t|\t\n\tO\t\n\t|\n",
    "-----------------\n+\t|\t\n\t|\t\n\tO\t\n\t|\n       / \\\n",
    "-----------------\n+\t|\t\n\t|\t\n\tO\t\n\t|\n       / \\\n\t|\n"
    "-----------------\n+\t|\t\n\t|\t\n\tO\t\n\t|\n       / \\\n\t|\n       / \\\n_____________"};
string stringFunctionReturn(vector<string> &wordsToPlay)
{
    srand(time(0));
    int index = rand() % wordsToPlay.size();
    return wordsToPlay[index];
}
int main()
{
    cout<<"The first Letter is Captial!\n"<<endl;
    string randomWord = stringFunctionReturn(wordsToPlay);
    string guessWord = randomWord;
    int numberOfGuesses = 7;
    string finalAnswer = "";
    for (int i = 0; i < guessWord.length(); i++)
        finalAnswer = finalAnswer + "_";
    cout << "\n " << finalAnswer << endl;
    bool mark = true;
    cout << drawHangMan[0] << endl;
    while (true)
    {
        char guessCharecter;
        cout << "Enter your Guess Alphabet:-  ";
        cin >> guessCharecter;
        int pos = 0;
        if (guessWord.find(guessCharecter) != string::npos)
        {
            for (int i = 0; i < guessWord.length(); i++)
            {
                if (guessWord[i] == guessCharecter)
                    finalAnswer[i] = guessCharecter;
                //guessCount--;
            }
            cout<<"CORRECT!,Safe!\n";
            cout << drawHangMan[guessCount] << endl;
            cout << finalAnswer;
            cout << "\n\n"<< endl;
        }
        else
        {
            cout << "Wrong guess, try again\n";
            guessCount++;
            cout << drawHangMan[guessCount] << endl;
            if (guessCount == numberOfGuesses)
            {
                cout << "YOU ARE DEAD!\n";
                cout << guessWord << endl;
                break;
            }
        }
        if (finalAnswer == guessWord)
        {
            cout << "The answer is found!" << endl;
            break;
        }
    }
    return 0;
}
