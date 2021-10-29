#include <iostream>

using namespace std;

constexpr char kPlayerSymbol ='@';

int GetIndexFromCoordinates(int x,int y, int width);
void DrawLevel(char level[], int width, int height,int playerX, int playerY);
bool UpdatePlayerPosition(char level[],int& playerX,int& playerY, int width, bool& playerHasKey); 

int main()
{
    constexpr int kWidth = 25; 
    constexpr int kHeight = 15;

    // '+' is a corner of a wall, '-' is a horizontal wall, '|' is a vertical wall, '*' is a key,'D' is a door, ' X' is the goal 

    char levelArray[]{'+','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','+',
                      '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','*','|',
                      '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ','|',
                      '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ','|',
                      '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','+','-',' ','|',
                      '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
                      '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
                      '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
                      '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
                      '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
                      '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
                      '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','+','-','-','-','-','-','-','-','-','-','|',
                      '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
                      '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','D',' ',' ',' ',' ',' ',' ',' ',' ','X','|',
                      '+','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','+',};
    int playerX = 1;
    int playerY = 1;
    bool gameOver = false;

    bool playerHasKey = false;
    
    while (!gameOver)
    {
        system("clear"); //clears the screen apparently (use system("cls") when you go back to old cp)
        DrawLevel(levelArray, kWidth, kHeight, playerX, playerY);
        gameOver = UpdatePlayerPosition(levelArray, playerX, playerY,kWidth,playerHasKey);
    }
    system("clear");
    DrawLevel(levelArray, kWidth, kHeight, playerX, playerY);
    cout << "\nDING DING DING!! WINNER WINNER CHICKEN DINNER!!!" << endl;
                      
}
int GetIndexFromCoordinates(int x,int y, int width)
{
    return x + y * width;
}
void DrawLevel(char level[], int width, int height,int playerX, int playerY)
{
    for (int y = 0; y < height; y++)
    {

        for (int x = 0; x < width; x++)
        {
            if (playerX == x && playerY == y)
            {
                cout << kPlayerSymbol;
            }
            int index = GetIndexFromCoordinates(x,y,width);
            cout << level[index];
        }
        cout << endl;
    }
}
bool UpdatePlayerPosition(char level[],int& playerX,int& playerY, int width,bool& playerHasKey)
{
    char input = getchar(); // it's _getch() for windows 

    int newPlayerX = playerX;
    int newPlayerY = playerY;

    switch(input)
    {
        case 'w':
        case 'W':
        {
            newPlayerY--;
            break;
        }
        case 's':
        case 'S':
        {
            newPlayerY++;
            break;
        }
        case 'a':
        case 'A':
        {
            newPlayerX--;
            break;
        }
        case 'd':
        case 'D':
        {
            newPlayerX++;
            break;
        }
        default:

        break;
    }
    int index = GetIndexFromCoordinates(newPlayerX, newPlayerY, width);

    if (level[index] == ' ')
    {
        playerX = newPlayerX;
        playerY = newPlayerY;
    }
    else if (level[index] == '*')
    {
        playerHasKey = true;
        level[index] = ' ';

        playerX = newPlayerX;
        playerY = newPlayerY;
    }
    else if (level[index]=='D' && playerHasKey)
    {
        level[index] = ' ';
        playerHasKey = false;

        playerX = newPlayerX;
        playerY = newPlayerY;
    }
    else if (level[index] == 'X')
    {
        level[index] = ' ';

        playerX = newPlayerX;
        playerY = newPlayerY;

        return true; 
    }

    return false;
}