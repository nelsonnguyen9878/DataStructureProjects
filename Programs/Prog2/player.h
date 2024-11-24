// player.h
#include <string>
using std::string;
class player
{
	public:
		player(); // default constructor
		player(const string&, const int&, const int&, const int&); //  overloaded constructor
		player(const player& x); // copy constructor
        int SetName(const string);
		int DrawCard(); // current player draws their card
		int CheckStatus(); // checks their current health and damage
        
        // Getters
        int GetHealth();
        int GetDamage();
        int GetShield();

        // affect player stats
        int DealDamage(int);
        int Heal(int);
        int SetShield(int);       
        int SetDamage(int);

	private:
		string name;
		int health;
		int base_damage;
        int shield;
};











