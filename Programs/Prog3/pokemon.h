// file: pokemon.h
// summary of pokemon.h: Stores all the class information in this file
#include <iostream>
#include <string>
#include <memory>
using namespace std;

// base pokemon class
class pokemon {
    public:
        pokemon(); // default constructor
        pokemon(const string name, const int& health, const int& attack, const int& defense);
        ~pokemon();       

        int displayPokemon(void) const; // displays current pokemon
        virtual int UseBlock(); // function is not implemented, didn't have time to do this
        virtual int UseBerries(); // function is not implemented didn't have time to do this
        
        // Getters , returns the private variable
        int GetHealth(); 
        int GetAttack();
        int GetDefense();

        // Setters , sets the private variable to the variable passed in
        int SetHealth(int new_health);
        int SetAttack(int new_attack);
        int SetDefense(int new_defense);
    
        // Attack functions
        virtual int UseAttack(shared_ptr<pokemon>) = 0;
        virtual int TakeDamage(shared_ptr<pokemon>, int) = 0;
    private:
        string name;
        int health;
        int attack;
        int defense;
};

// derived classes
// fire class
class fire: public pokemon
{
    public:
        fire(); // default constructor
        fire(const string name, const int& health, const int& attack,const int& defense, 
        const bool& charcoal, const int& fighter, const int& special_atk);
        ~fire(); // destructor
        int displayPokemon() const;
        
        int UseAttack(shared_ptr<pokemon>);
        int TakeDamage(shared_ptr<pokemon>, int);


    private:
        bool charcoal; // item for fire enhancing, bonus fire damage
        int fighter; // subtype, bonus damage
        int special_atk;

};


// water class
class water: public pokemon
{
    public:
        water(); // default constructor
        water(const string name, const int& health, const int& attack, const int& defense, 
        const bool& mystic_water, const int& steel, const int& special_def);
        ~water(); // destructor
        int AquaRing(); // heals water pokemon x amount of health every turn
        int displayPokemon() const;
        int UseAttack(shared_ptr<pokemon>);
        int TakeDamage(shared_ptr<pokemon>, int);
    private:
        bool mystic_water; // item for water enhacning, bonus water damage
        int steel; // subtype, bonus defense
        int special_def;
};

// grass class
class grass: public pokemon
{
    public:
        grass(); // constructor
        grass(const string name, const int& health, const int& attack, const int& defense, 
        const bool& miracle_seed, const int& ground, const int& extra_health);
        ~grass(); // destructor
        int displayPokemon() const;
        int UseAttack(shared_ptr<pokemon>);
        int TakeDamage(shared_ptr<pokemon>, int);

    private:
        bool miracle_seed; // item for grass enhancing, bonus grass damage;
        int ground; // subtype, bonus health
        int extra_health;
};
