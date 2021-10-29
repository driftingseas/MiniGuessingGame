#include <iostream>
#include <time.h>

using namespace std;

//constant values for Main Menu
constexpr int g_kPlayMenu = 1;
constexpr int g_kQuitMenu = 2;

constexpr int g_kMaxGuesses = 5;

//constant values for Gender Menu
constexpr int g_kMaleGender = 1;
constexpr int g_kFemaleGender = 2;
constexpr int g_kOtherGender = 3;

int DisplayWelcomeMessage();
void DisplayMessage(string message);
void PlayGame();
string GetUserName();
int AskForGender();
int GetAge();
string GenerateNickname(int gender, int age);
int GetGuess(int turn, string nickname);
bool ReviewGuess(int guess, int randomNumber);
void DisplayGameOver(int randomNumber, string nickname);

int main()
{
    srand((unsigned)time(0));

    bool keepPlaying = true;

    do
    {
        int input = DisplayWelcomeMessage();

        switch (input)
        {
        case g_kPlayMenu:
        {
            PlayGame();

            break;
        }
        case g_kQuitMenu:
        {
            DisplayMessage(" Quit? Aw shucks. Welp. See you later! Bye bye!");

            keepPlaying = false;

            break;
        }
        default:
        {
            system("cls");
            DisplayMessage("Invalid input. Try again!");
        }
        }

    } while (keepPlaying);
}

int DisplayWelcomeMessage()
{
    int input;

    do
    {
        //Display welcome message
        cout << "-----------------Welcome to the Super Amazing Guessing Game--------------------" << endl;
        cout << "          You have " << g_kMaxGuesses << " guesses to correctly guess the correct number between 1 and 20. " << endl;
        cout << "          \n1)Play Now" << endl;
        cout << "          2} Quit" << endl;
        cout << "          \n Press 1 or 2: ";

        cin >> input;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            system("cls");
            cout << "Invalid entry! Try again!" << endl;
        }
        else
        {
            break;
        }

    } while (true);

    return input;
}

void DisplayMessage(string message)
{
    cout << message << endl;
}
void PlayGame()
{
    system("cls");
    string name = GetUserName();
    system("cls");

    cout << "\nOh cool! Welcome " << name << "!" << endl;

    bool isGameOver = false;

    do
    {
        int gender = AskForGender();

        if ((gender >= g_kMaleGender) && (gender <= g_kOtherGender))
        {
            system("cls");
            int age = GetAge();
            system("cls");

            string nickname = GenerateNickname(gender, age);

            int randomNumber = 1 + rand() % 20;

            cout << endl
                 << randomNumber << endl;

            bool guessCorrect = false;
            for (int i = 0; i < g_kMaxGuesses; i++)
            {
                int guess = GetGuess(i + 1, nickname);
                bool guessCorrect = ReviewGuess(guess, randomNumber);

                if (guessCorrect)
                {
                    break;
                }
            }
            //test for commit 
            if (guessCorrect == false)
            {
                DisplayGameOver(randomNumber, nickname);
            }
            isGameOver = true;
        }
        else
        {
            system("cls");
            DisplayMessage("Oops. invalid input. Try again! ");
        }
    } while (!isGameOver);
}
string GetUserName()
{

    cout << "Hey! What's your name, buddy-o-pally-o?" << endl;

    string name;
    cin >> name;

    return name;
}
int AskForGender()
{
    int gender;

    do
    {
        //Ask for gender
        cout << "\n     What's your gender? If you don't mind me asking.. : " << endl;
        cout << "       \n1) Female" << endl;
        cout << "       2) Male" << endl;
        cout << "       3) Other" << endl;
        cout << "Press 1, 2 or 3: ";

        cin >> gender;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            system("cls");
            cout << "Invalid entry! Try again!" << endl;
        }
        else
        {
            break;
        }

    } while (true);

    return gender;
}
int GetAge()
{
    int age;

    do
    {
        cout << "\nHow old are ya? ";

        cin >> age;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            system("cls");
            cout << "Invalid entry! Try again!" << endl;
        }
        else
        {
            break;
        }
    } while (true);

    return age;
}
string GenerateNickname(int gender, int age)
{
    //Generate nickname
    string nickname;

    if (gender == g_kMaleGender)
    {
        if (age > 60)
        {
            nickname = "old man";
        }
        else if (age < 10)
        {
            nickname = "little man";
        }
        else
        {
            nickname = "bud";
        }
    }
    else if (gender == g_kFemaleGender)
    {
        if (age > 60)
        {
            nickname = "old lady";
        }
        else if (age < 10)
        {
            nickname = "little lady";
        }
        else
        {
            nickname = "ma'am";
        }
    }
    else
    {
        nickname = "friend";
    }
    return nickname;
}
int GetGuess(int turn, string nickname)
{
    int guess;

    do
    {
        cout << "Guess " << turn << ":"
             << "Alright " << nickname << "please guess the number: ";

        cin >> guess;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            system("cls");
            cout << "Invalid entry! Try again!" << endl;
        }
        else
        {
            break;
        }
    } while (true);

    return guess;
}
bool ReviewGuess(int guess, int randomNumber)
{
    if (guess == randomNumber)
    {
        DisplayMessage(" Ding ding ding!! You are correct!!!");

        return true;
    }
    else
    {
        if (guess > randomNumber)
        {
            DisplayMessage("Aw man! Your guess is too high! Try again! ");
        }
        else
        {
            DisplayMessage("Aw man! Your guess is too low! Try again! ");
        }

        return false;
    }
}
void DisplayGameOver(int randomNumber, string nickname)
{
    cout << "Too bad " << nickname << ", you're all out of luck! The correct number was: " << randomNumber << endl;
    DisplayMessage("Better luck next time!");
}