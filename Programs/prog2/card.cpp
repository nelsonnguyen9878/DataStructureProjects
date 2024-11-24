// card.cpp
//
//
//
// 

#include "card.h" // header file, grabbing class  
#include <iostream> // cin, cout
#include <cstring>
using namespace std; // naming variables




// *******BASE CARD**********
// default constructor
card::card(): name(""), rarity(nullptr)
{}

// overloaded constructora
card::card(const string& new_name, const char* new_rarity)
{
	name = new_name;
	
	rarity = new char[strlen(new_rarity) + 1];
	strcpy(rarity, new_rarity);
}

// deconstructor, deletes the memory allocated for char* rarity
card::~card()
{
	delete[] rarity;
}


// copy constructor, passes in another card called other to copy the private
// variables to the current card
card::card(const card& other)
{
	name = other.name;
	
	rarity = new char[strlen(other.rarity) + 1];
	strcpy(rarity, other.rarity);
}

// assignment operator, will passs in another card to allow assignment
// operator to copy the char*
card& card::operator=(const card& other)
{
    if(this == &other) return *this;

    if(rarity)
        throw(other);
	    delete[] rarity;

    rarity = new char[strlen(other.rarity) + 1];
   	strcpy(rarity, other.rarity);

    return *this;
}

// less than operator , compares this->rarity to other cards rarity and returns a bool
bool card::operator<(const card& other)
{
	if(((strcmp(this->rarity, "rare") == 0)) && ((strcmp(other.rarity, "uncommon") == 0)))
		return false;

	if(((strcmp(this->rarity, "rare") == 0)) && ((strcmp(other.rarity, "common") == 0)))
		return false;

	if(((strcmp(this->rarity, "rare") == 0)) && ((strcmp(other.rarity, "rare") == 0)))
		return false;


	
	if(((strcmp(this->rarity, "uncommon") == 0)) && ((strcmp(other.rarity, "uncommon") == 0)))
		return false;


	if(((strcmp(this->rarity, "uncommon") == 0)) && ((strcmp(other.rarity, "common") == 0)))
		return false;

	if(((strcmp(this->rarity, "uncommon") == 0)) && ((strcmp(other.rarity, "rare") == 0)))
		return true;


	
	if(((strcmp(this->rarity, "common") == 0)) && ((strcmp(other.rarity, "uncommon") == 0)))
		return true;
	
	
	if(((strcmp(this->rarity, "common") == 0)) && ((strcmp(other.rarity, "common") == 0)))
		return false;

	if(((strcmp(this->rarity, "common") == 0)) && ((strcmp(other.rarity, "rare") == 0)))
		return true;

    return false;
}

// less than or equal to operator, compares this->rarity to other cards rarity and returns a bool
bool card::operator<=(const card& other)
{

	if(((strcmp(this->rarity, "rare") == 0)) && ((strcmp(other.rarity, "uncommon") == 0)))
		return false;

	if(((strcmp(this->rarity, "rare") == 0)) && ((strcmp(other.rarity, "common") == 0)))
		return false;

	if(((strcmp(this->rarity, "rare") == 0)) && ((strcmp(other.rarity, "rare") == 0)))
		return true;


	
	if(((strcmp(this->rarity, "uncommon") == 0)) && ((strcmp(other.rarity, "uncommon") == 0)))
		return true;


	if(((strcmp(this->rarity, "uncommon") == 0)) && ((strcmp(other.rarity, "common") == 0)))
		return false;

	if(((strcmp(this->rarity, "uncommon") == 0)) && ((strcmp(other.rarity, "rare") == 0)))
		return true;


	
	if(((strcmp(this->rarity, "common") == 0)) && ((strcmp(other.rarity, "uncommon") == 0)))
		return true;
	
	
	if(((strcmp(this->rarity, "common") == 0)) && ((strcmp(other.rarity, "common") == 0)))
		return true;

	if(((strcmp(this->rarity, "common") == 0)) && ((strcmp(other.rarity, "rare") == 0)))
		return true;

    return false;
}


// greater than operator , compares this-. rarity to other cards rarity and returns a bool
bool card::operator>(const card& other)
{

	if(((strcmp(this->rarity, "rare") == 0)) && ((strcmp(other.rarity, "uncommon") == 0)))
		return true;

	if(((strcmp(this->rarity, "rare") == 0)) && ((strcmp(other.rarity, "common") == 0)))
		return true;

	if(((strcmp(this->rarity, "rare") == 0)) && ((strcmp(other.rarity, "rare") == 0)))
		return false;


	
	if(((strcmp(this->rarity, "uncommon") == 0)) && ((strcmp(other.rarity, "uncommon") == 0)))
		return false;



	if(((strcmp(this->rarity, "uncommon") == 0)) && ((strcmp(other.rarity, "common") == 0)))
		return true;

	if(((strcmp(this->rarity, "uncommon") == 0)) && ((strcmp(other.rarity, "rare") == 0)))
		return false;


	
	if(((strcmp(this->rarity, "common") == 0)) && ((strcmp(other.rarity, "uncommon") == 0)))
		return false;
	
	
	if(((strcmp(this->rarity, "common") == 0)) && ((strcmp(other.rarity, "common") == 0)))
		return false;

	if(((strcmp(this->rarity, "common") == 0)) && ((strcmp(other.rarity, "rare") == 0)))
		return false;

    return false;
}



// greater than or equal to operator, compares this->rarity to other->rarity and returns a bool
bool card::operator>=(const card& other)
{
	if(((strcmp(this->rarity, "rare") == 0)) && ((strcmp(other.rarity, "uncommon") == 0)))
		return true;

	if(((strcmp(this->rarity, "rare") == 0)) && ((strcmp(other.rarity, "common") == 0)))
		return true;

	if(((strcmp(this->rarity, "rare") == 0)) && ((strcmp(other.rarity, "rare") == 0)))
		return true;


	
	if(((strcmp(this->rarity, "uncommon") == 0)) && ((strcmp(other.rarity, "uncommon") == 0)))
		return true;


	if(((strcmp(this->rarity, "uncommon") == 0)) && ((strcmp(other.rarity, "common") == 0)))
		return true;

	if(((strcmp(this->rarity, "uncommon") == 0)) && ((strcmp(other.rarity, "rare") == 0)))
		return false;


	
	if(((strcmp(this->rarity, "common") == 0)) && ((strcmp(other.rarity, "uncommon") == 0)))
		return false;
	
	
	if(((strcmp(this->rarity, "common") == 0)) && ((strcmp(other.rarity, "common") == 0)))
		return false;

	if(((strcmp(this->rarity, "common") == 0)) && ((strcmp(other.rarity, "common") == 0)))
		return true;

    return false;
}

// assignment operator, checks if current card rarity is equal to other card's rarity or not and return a bool
bool card::operator==(const card& other)
{
	if(((strcmp(this->rarity, "rare") == 0)) && ((strcmp(other.rarity, "uncommon") == 0)))
		return false;

	if(((strcmp(this->rarity, "rare") == 0)) && ((strcmp(other.rarity, "common") == 0)))
		return false;

	if(((strcmp(this->rarity, "rare") == 0)) && ((strcmp(other.rarity, "rare") == 0)))
		return true;


	
	if(((strcmp(this->rarity, "uncommon") == 0)) && ((strcmp(other.rarity, "uncommon") == 0)))
		return true;


	if(((strcmp(this->rarity, "uncommon") == 0)) && ((strcmp(other.rarity, "common") == 0)))
		return false;

	if(((strcmp(this->rarity, "uncommon") == 0)) && ((strcmp(other.rarity, "rare") == 0)))
		return false;


	
	if(((strcmp(this->rarity, "common") == 0)) && ((strcmp(other.rarity, "uncommon") == 0)))
		return false;
	
	
	if(((strcmp(this->rarity, "common") == 0)) && ((strcmp(other.rarity, "common") == 0)))
		return true;

	if(((strcmp(this->rarity, "common") == 0)) && ((strcmp(other.rarity, "uncommon") == 0)))
		return false;

    return false;
}


// not equal operator, checks if the current card is not equal to the other card and returns a bool
bool card::operator!=(const card& other)
{

	if(((strcmp(this->rarity, "rare") == 0)) && ((strcmp(other.rarity, "uncommon") == 0)))
		return true;

	if(((strcmp(this->rarity, "rare") == 0)) && ((strcmp(other.rarity, "common") == 0)))
		return true;

	if(((strcmp(this->rarity, "rare") == 0)) && ((strcmp(other.rarity, "rare") == 0)))
		return false;


	
	if(((strcmp(this->rarity, "uncommon") == 0)) && ((strcmp(other.rarity, "uncommon") == 0)))
		return false;


	if(((strcmp(this->rarity, "uncommon") == 0)) && ((strcmp(other.rarity, "common") == 0)))
		return true;

	if(((strcmp(this->rarity, "uncommon") == 0)) && ((strcmp(other.rarity, "rare") == 0)))
		return true;


	
	if(((strcmp(this->rarity, "common") == 0)) && ((strcmp(other.rarity, "uncommon") == 0)))
		return true;
	
	
	if(((strcmp(this->rarity, "common") == 0)) && ((strcmp(other.rarity, "common") == 0)))
		return false;

	if(((strcmp(this->rarity, "common") == 0)) && ((strcmp(other.rarity, "uncommon") == 0)))
		return true;

    return false;
}


// ostream operator that gives the ability to cout << card to display the card's information
ostream& operator<<(ostream& out, const card& my_card)
{
	out << "----------------------" << endl;
	out << "-\tCard: " << my_card.name << "   -" << endl;
	out << "----------------------" << endl;
	out << "-\tRarity: " << (const char*) my_card.rarity << " -"<< endl;
    return out;
}

// displays card info as a const since we're not modifying anything. 
// grabs the private variables and displays them.
int card::DisplayCard() const
{
	cout << "----------------------" << endl;
	cout << "-\tCard: " << name << "   -" << endl;
	cout << "----------------------" << endl;
	cout << "-\tRarity: " << (const char*) rarity << " -"<< endl;
	return 1;
}


// allows us to modify the current card by setting it to a new name, passes in a string new_name
// which is the name for the card
int card::SetCardName(string new_name)
{   
    name = new_name;
	return 0;
}

// *******SKILL CARD*********
// default constructor, initalizes private members to 0 or nullptr
skill::skill(): damage(0), heal(0)
{}

// overloaded constructor
skill::skill(const string & new_name, const char* new_rarity,const int& new_damage, const int& new_heal): card(new_name, new_rarity), damage(new_damage), heal(new_heal)
{}

// copy constructor
skill::skill(const skill& other): card(other)
{
	damage = other.damage;
	heal = other.heal;
}
// Deal Damage function, passes in two players in the case where we get a heal card or damage card. Damage
// card will affect the opposing player and healing with effect the current player
int skill::DealDamage(player& player1, player& player2) // player
{
    // pass in player object
    // player
	// function that will show how much damage will be done for
	// this card
    
	return 0;
}

// Heal Player function, when called, takes current player health and add the current card healing to the player
int skill::HealPlayer(player& self)
{
    // this will take in the player and the amount healed from the card
	return 0;
}

// display current skill card by calling base class display card
// to grab display name and rarity while this function will add on 
// damage or healing
int skill::DisplaySkillCard() 
{
    DisplayCard();
    cout << "-\t Damage: " << damage << endl;
    cout << "-\t heal: " << heal << endl;
    cout << "--------------------------" << endl;
    return 0;
}

// ostream operator to display the statistics of the card, passing in my_card
ostream& operator<<(ostream& out, const skill& my_card)
{
    out << static_cast<const card&>(my_card);
	out << "-\tDamage: " << my_card.damage << "   -" << endl;
	out << "-\tHeal: " << my_card.heal << " -"<< endl;
    cout << "--------------------------" << endl;
    return out;
}

// PlayCard passes in two players that way the current player is healed if the card 
// is a healing card and the opponent will take damage if it is a damage card
int skill::PlayCard(player& player1, player& player2)
{
    player2.DealDamage(damage);
    player1.Heal(heal);
    return 1;
}


// ******EQUIPMENT CARD*********
// default constructor
equipment::equipment(): additional_damage(0), shield(0)
{}

// overloaded constructor
equipment::equipment(const string & new_name, const char* new_rarity, const int&  new_additional_damage, const int& new_shield): card(new_name, new_rarity), additional_damage(new_additional_damage), shield(new_shield)
{}

// copy constructor
equipment::equipment(const equipment& other): card(other)
{
    additional_damage = other.additional_damage;
    shield = other.shield;
}

// ostream operator to dispay infromation on my_card that is passed in
ostream& operator<<(ostream& out, const equipment& my_card)
{
    out << static_cast<const card&>(my_card);
	out << "-\tWeapon Damage: " << my_card.additional_damage << "   -" << endl;
	out << "-\tShield: " << my_card.shield << " -"<< endl;
    cout << "--------------------------" << endl;
    return out;
}

// displays the unique stats of the card
int equipment::DisplayEquipCard()
{
    DisplayCard();
    cout << "-\t Bonus Attack: " << additional_damage << endl;
    cout << "-\t Shield: " << shield << endl;
    cout << "--------------------------" << endl;
    return 1;

}

// GetDamage function , returns damage from the card
int equipment::GetDamage()
{ return additional_damage; }

// AddWeaponDamage function, passes in self to apply the bonus_damage to the player
int equipment::AddWeaponDamage(player& self, const equipment& curr_card)
{
	// card will have a random weapon with a bonus damage
	// and it will be applied to the players damage
    self.SetDamage(self.GetDamage() + curr_card.additional_damage);
	return 0;
}

// Add Shield Function, passes in self to apply the bonus shield from the card to the player
int equipment::AddShield(player& self, const equipment& curr_card)
{
	// will have a random shield with a random bonus shield
	// that will protect the player a certain amount of damage;
    self.SetShield(self.GetShield() + curr_card.shield);
	return 0;
}

// Playcard passes in self, that way when the card is called, it will apply the stats of the
// curr_card to the player
int equipment::PlayCard(player& self, const equipment& curr_card)
{
    AddWeaponDamage(self, curr_card);  
    AddShield(self, curr_card);

    return 1;
}

// ********** TRAP CARD**********

// default constructor
trap::trap(): trap_name(nullptr)
{
}

//  overloaded constructor
trap::trap(const string & new_name, const char* new_rarity, const char* new_trap_name): card(new_name, new_rarity), trap_name(nullptr) 
{
 this->trap_name = new char[strlen(new_trap_name) + 1];
 strcpy(this->trap_name, new_trap_name);
}

// copy constructor
trap::trap(const trap& x)
{
	// implement copy function here
    this->trap_name = new char[strlen(x.trap_name) + 1];
    strcpy(this->trap_name, x.trap_name);
}

ostream& operator<<(ostream& out, const trap& my_card)
{
    out << static_cast<const card&>(my_card);
	out << "-\tTrap: " << (const char*)my_card.trap_name << "   -" << endl;
    return out;
}



// deconstructor
trap::~trap()
{
    delete[] trap_name;
}





