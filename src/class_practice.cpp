#include <iostream>
using namespace std;

class Character
{
private:
    int health;

public:
    // This is more efficient than assigning inside the body because it avoids default-initializing health first.
    Character(int newValue) : health(newValue)
    {
        // cout << "Take care of yourself:" << endl;
        // cout << "Your health is: " << health << endl;
    }
    // Getter
    int GetHealth()
    {
        return health;
    };
    // setter with validation
    void setHealth(int newVale)
    {
        if (newVale < 0)
        {
            health = 0;
        }
        else
        {
            health = newVale;
        }
    }
    Character(const Character &newCharacter)
    {
        health = newCharacter.health;
    }
};

int main()
{
    cout << "Understanding Class: " << endl;

    Character Asad{10};
    // newCharacter other{20};
    // Character newConstructore;
    // Not allowed - Health is private
    // Asad.health = 10;
    Asad.setHealth(10);
    cout << "Your health: " << Asad.GetHealth() << endl;
}