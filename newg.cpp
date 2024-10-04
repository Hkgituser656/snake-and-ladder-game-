#include <bits/stdc++.h>
using namespace std;

int snakes[7][2] = {{91, 10}, {90, 2}, {76, 30}, {54, 8}, {40, 3}, {39, 5}, {27, 1}};
int ladders[7][2] = {{4, 25}, {13, 46}, {33, 49}, {42, 63}, {50, 69}, {62, 81}, {74, 92}};

void checksnakesladder(int &position)
{
    for (int i = 0; i < 7; i++)
    {
        if (position == snakes[i][0])
        {
            cout << "Oh no! You landed on a snake! Moving down from " << position << " to " << snakes[i][1] << endl;
            position = snakes[i][1];
        }
        else if (position == ladders[i][0])
        {
            cout << "Yay! You landed on a ladder! Moving up from " << position << " to " << ladders[i][1] << endl;
            position = ladders[i][1];
        }
    }
}

int diceroll()
{
    return rand() % 6 + 1;
}
int main()
{
    int position = 0;

    while (position < 100)
    {
        cout << "Press r to roll a dice" << endl;
        char roll;
        cin >> roll;
        if (roll == 'r')
        {
            int dice = diceroll();
            cout << "Your Roll is " << dice << endl;

            if (position + dice <= 100)
            {
                position += dice;
                cout << "Your new position is " << position << endl;
                checksnakesladder(position);
            }
            else
            {
                cout << "You need an exact roll to win. Stay at position " << position << endl;
            }

            if (position == 100)
            {
                cout << "Congratulations! You reached position 100 and won the game!" << endl;
                break;
            }
        }
        else
        {
            cout << "Wrong Press" << endl;
        }
    }
    return 0;
}