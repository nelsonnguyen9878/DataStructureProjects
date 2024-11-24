#pragma once
// card.h
// where to implement operators once small set betwen 3-5 that is in
// each card. DO NOT implement operators in data structure class
// operators are inherited because they're member functions
#include <iostream>
#include <string>
#include "player.h"
using std::string;
using std::ostream;

//class player;
// base class
class card
{
	public:
		card(); // default constructor
		card(const string & name, const char*); // overloaded constructor
		~card(); // deconstructor
		card(const card& x);		// copy constructor
		card& operator=(const card& other);
		bool operator<(const card& other);
		bool operator<=(const card& other);
		bool operator>(const card& other);
		bool operator>=(const card& other);
		bool operator==(const card& other);
		bool operator!=(const card& other);
        friend ostream& operator<<(ostream& out, const card& my_card);

		int SetCardName(string );
		int DisplayCard() const;
		int PlayCard();
	protected:
		string name;
		char* rarity;
};

// derived clases
class skill: public card
{
	public:
		skill(); // default constructor
		skill(const string & name, const char* rarity, const int& damage, const int& heal);// overloaded constructor
		skill(const skill& x); // copy constructor
        friend ostream& operator<<(ostream& out, const skill& my_card);

		int DealDamage(player&, player&);
		int HealPlayer(player&);
        int DisplaySkillCard(); 
        int PlayCard(player&, player&);
	private:
		int damage;
		int heal;
};


class equipment: public card
{
	public:
		equipment(); // default constructor
		equipment(const string & name, const char* rarity, const int& additonal_damage,const int& shield); // overloaded constructor
		equipment(const equipment& x); // copy constructor
        friend ostream& operator<<(ostream& out, const equipment& my_card);
        int DisplayEquipCard();

        // Getter
        int GetDamage(); 
    

        // stat modifiers and play
		int AddWeaponDamage(player&, const equipment&); 
		int AddShield(player&, const equipment&);
        int PlayCard(player&, const equipment&);
        
	private:
		int additional_damage;
		int shield;
};


class trap: public card
{
	public:
		trap(); // default constructor
		trap(const string & name, const char* rarity, const char* trap_name); // overloaded constructor
		trap(const trap& x);
        friend ostream& operator<<(ostream& out, const trap& my_card);

		~trap(); // deconstructor
		int SkipTurn();
		int DamageSelf();

	private:
		char* trap_name;
        //string description;
};
















