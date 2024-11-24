// file: pokemon.cpp
// Author: Nelson Nguyen
// summary of pokemon.cpp: defines all the member function for each class in this file.
#include "pokemon.h"

// base pokemon class
// default constructor
pokemon::pokemon(): name(""), health(100), attack(1), defense(1)
{}

// overloaded constuctor
pokemon::pokemon(const string new_name, const int& new_health, const int& new_atk, const int& new_def):
name(new_name), health(new_health), attack(new_atk), defense(new_def)
{}

// destructor
pokemon::~pokemon()
{ 
    name = "";
    health = 0;
    attack = 0;
    defense = 0;
}

// displays pokemon stats
int pokemon::displayPokemon() const
{
    cout << "Name: " << name << endl;
    cout << "HP: " << health << endl;
    cout << "Atk: " << attack << endl;
    cout << "Def: " << defense << endl;
    return 1;
}



// not implemented yet, but if this function is used, it will block the next incoming attack
int pokemon::UseBlock()
{ return 1; }

// not implemented yet: functionality is to use a berry during a turn to heal current pokemon
int pokemon::UseBerries()
{ return 1; }


// GETTERS , grabs private member variables
int pokemon::GetHealth()
{ return health; }

int pokemon::GetAttack()
{ return attack; }

int pokemon::GetDefense()
{ return defense; }



// Setters, sets the private member variables to the variable passed in
int pokemon::SetHealth(int new_health)
{
    health = new_health;
    return 1; 
}

int pokemon::SetAttack(int new_attack)
{
    attack = new_attack; 
    return 1;
}

int pokemon::SetDefense(int new_defense)
{
    defense = new_defense;
    return 1;
}



// Derived class: fire
// default constructor
fire::fire(): charcoal(false), fighter(0), special_atk(0)
{}

// overloaded constructor
fire::fire(const string new_name, const int& new_health, const int& new_attack, const int& new_defense,
const bool& new_charcoal, const int& new_fighter, const int& new_specialatk): pokemon(new_name, new_health,
new_attack, new_defense), charcoal(new_charcoal), fighter(new_fighter), special_atk(new_specialatk)
{   
    if(new_charcoal == true)
    {
        int new_attack_value = GetAttack();
        SetAttack(new_attack_value += (new_attack * 0.1));
    }
}

// destructor, resets stats to 0
fire::~fire()
{
    charcoal = false;
    fighter = 0;
    special_atk = 0;
}


// unique display, to display their unique characteristics
int fire::displayPokemon() const
{
    pokemon::displayPokemon();
    if(charcoal) 
    { 
        cout << "Item: charcoal" << endl; 
    } 
    
    else { cout << "Item: " << endl; }

    cout << "Sub-type: fighter, bonus " << fighter << "%" << " damage" << endl;
    cout << "Sp.Atk: " << special_atk << endl;
    return 1;
}


// virtual UseAttack, that passes in a opposing pokemon to have them take damage from the attack
int fire::UseAttack(shared_ptr<pokemon> opp_pokemon)
{
    int incoming_damage = this->GetAttack();
    TakeDamage(opp_pokemon, incoming_damage);
    cout << "Damage done: " << ((incoming_damage * 0.08) - (opp_pokemon->GetDefense() * 0.05)) << endl;
    return 1;
}

// TakeDamage takes in a opposing pokemon and takes the users pokemon damage. The opposing pokemon
// will take damage from users pokemon that is calculated by their attack
int fire::TakeDamage(shared_ptr<pokemon> opp_pokemon, int incoming_damage)
{
    opp_pokemon->SetHealth(opp_pokemon->GetHealth() - ((incoming_damage * 0.08) - (opp_pokemon->GetDefense() * 0.05)));
    return 1;
}


// Derived class: water
// default constructor
water::water(): pokemon(), mystic_water(false), steel(0), special_def(0)
{}

// overloaded constructor
water::water(const string new_name, const int& new_health, const int& new_attack, const int& new_defense, 
const bool& new_mystic, const int& new_steel, const int& new_specialdef): pokemon(new_name, new_health,
new_attack, new_defense), mystic_water(new_mystic), steel(new_steel), special_def(new_specialdef)
{
    if(mystic_water)
    {
        int curr_defense = GetDefense();
        SetDefense(curr_defense += (new_defense * 0.1));
    }
}

// virtual UseAttack, that passes in a opposing pokemon to have them take damage from the attack
int water::UseAttack(shared_ptr<pokemon> opp_pokemon)
{
    int incoming_damage = this->GetAttack();
    TakeDamage(opp_pokemon, incoming_damage);
    cout << "Damage done: " << ((incoming_damage * 0.08) - (opp_pokemon->GetDefense() * 0.05)) << endl;
    return 1;
}

// TakeDamage takes in a opposing pokemon and takes the users pokemon damage. The opposing pokemon
// will take damage from users pokemon that is calculated by their attack
int water::TakeDamage(shared_ptr<pokemon> opp_pokemon, int incoming_damage)
{
    opp_pokemon->SetHealth(opp_pokemon->GetHealth() - ((incoming_damage * 0.08) - (opp_pokemon->GetDefense() * 0.05)));
    return 1;
}

// destructor
water::~water()
{
    mystic_water = false;
    steel = 0;
    special_def = 0;
}


// display water pokemon stats
int water::displayPokemon() const
{
    pokemon::displayPokemon();
    if(mystic_water)
    { cout << "Item: mystic water" << endl; }
    else {cout << "Item: " << endl; }
    cout << "Sub-type: steel, bonus " << steel << "%" << " defense" << endl;
    cout << "Sp.Def: " << special_def << endl;
    return 1;
}




// derived class: grass
// default constructor
grass::grass(): pokemon(), miracle_seed(false), ground(0), extra_health(0)
{}

// overloaded constructor
grass::grass(const string n_name, const int& n_health, const int& n_attack, const int& n_defense, 
const bool& new_miracle, const int& new_ground, const int& new_extrahp): pokemon(n_name, n_health, n_attack,
n_defense), miracle_seed(new_miracle), ground(new_ground), extra_health(new_extrahp)
{
    if(miracle_seed)
    {      
        int curr_health = GetHealth();
        SetHealth(curr_health += (n_health * 0.1));

    }
}

// virtual UseAttack, that passes in a opposing pokemon to have them take damage from the attack
int grass::UseAttack(shared_ptr<pokemon> opp_pokemon)
{
    int incoming_damage = this->GetAttack();
    TakeDamage(opp_pokemon, incoming_damage);
    cout << "Damage done: " << ((incoming_damage * 0.08) - (opp_pokemon->GetDefense() * 0.05)) << endl;
    return 1;
}

// TakeDamage takes in a opposing pokemon and takes the users pokemon damage. The opposing pokemon
// will take damage from users pokemon that is calculated by their attack
int grass::TakeDamage(shared_ptr<pokemon> opp_pokemon, int incoming_damage)
{
    opp_pokemon->SetHealth(opp_pokemon->GetHealth() - ((incoming_damage * 0.08) - (opp_pokemon->GetDefense() * 0.05)));
    return 1;
}

// destructor
grass::~grass()
{
    miracle_seed = false;
    ground = 0;
    extra_health = 0;
}

// display grass pokemon stats
int grass::displayPokemon() const
{
    pokemon::displayPokemon();
    if(miracle_seed)
    { cout << "Item: miracle seed" << endl; }
    else { cout << "Item: " << endl; }
    cout << "Sub-type: ground, bonus " << ground << "%" << " health" << endl;
    return 1;
}






