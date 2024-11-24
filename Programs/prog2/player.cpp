// player.cpp
#include "player.h"
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
// default constructor
player::player() : name(""), health(0), base_damage(1), shield(0)
{
}


// overloaded constructor
player::player(const string& player_name, const int& player_health, const int& new_damage, const int& new_shield)
{
	name = player_name;
	health = player_health;
	base_damage = new_damage;
    shield = new_shield;
}

// copy constructor
player::player(const player& x)
{
    name = x.name;
    health = x.health;
    base_damage = x.base_damage;
    shield = x.shield;

	// implement copy function
}

// player will draw card. Not sure if this should be under the player class or
// if it should be under the game class
int player::DrawCard()
{
	// need to figure out how pulling a card will work for the player
	return 0;

}

// Wil display health, current damage, and if there is any traps activated
// on the player
int player::CheckStatus()
{
	// create a menu to display the current stats of the player
    cout << "Health: " << health << endl;
    cout << "Current damage: " << base_damage << endl;
	return 0;
}


// GETTERS, returns the private variable of the class
int player::GetHealth()
{ return health; }

int player::GetDamage()
{ return base_damage; }

int player::GetShield()
{ return shield; }

 // deal damage will subtract the current health from the incoming damage   
int player::DealDamage(int incoming_damage)
{
    return health -= incoming_damage;
}

// heal will pass in incoming_heal and add it to the current health
int player::Heal(int incoming_heal)
{
    if(health != 100)
        return health += incoming_heal;

    else
        return health = 100;
}


// SETTERS
// setting the players damage to the new damage added by equipment class
int player::SetDamage(int new_damage)
{
    base_damage = new_damage;
    return 1;
}

// updates the player shield by setting it to the new shield, calculated in the equipment class
int player::SetShield(int new_shield)
{
    shield = new_shield;
    return 1;
}

// sets current player name
int player::SetName(const string new_name)
{ 
    name = new_name; 
    return 1;
}
