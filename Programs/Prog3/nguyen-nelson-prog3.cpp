// nguyen-nelson-prog3.cpp
// main file 

// libraries
#include <iostream>
#include "BST.h"
using namespace std;

// function prototypes
int Menu();
int FightingMenu();
int userInput();
int Play(BST&, BST&);

// beginning of main, switch case to call play the game
int main() {

    // LIST OF POKEMONS
    BST Player1;
    BST Player2;
    
    // inserting pokemons into player1's list
    try{
    cout << "\n\n";
    shared_ptr<pokemon> firePtr = make_shared<fire>(fire("Charizard", 78, 84, 78, true, 1, 1));
    Player1.insert(firePtr);

    shared_ptr<pokemon> waterPtr = make_shared<water>(water("Empoleon", 84, 1, 100, true, 1, 1));
    Player1.insert(waterPtr);
    
    shared_ptr<pokemon> grassPtr = make_shared<grass>(grass("Turtwig", 300, 1, 1, true, 1, 1));
    Player1.insert(grassPtr);

    // inserting pokemons into player2's list
    shared_ptr<pokemon> waterPtr2 = make_shared<water>(water("Gyarados", 95, 125, 79, true, 1, 1));
    Player2.insert(waterPtr2);
    
    shared_ptr<pokemon> firePtr2 = make_shared<fire>(fire("Infernape", 76, 104, 71, true, 1, 1));
    Player2.insert(firePtr2);


    shared_ptr<pokemon> grassPtr2 = make_shared<grass>(grass("Snivy", 170, 1, 1, true, 1, 1));
    Player2.insert(grassPtr2);

/* // UNDO THIS CODE TO TEST TRY AND EXCEPTION, THIS WILL THROW AN EXCEPTION
    shared_ptr<pokemon> grassPtr3 = make_shared<grass>(grass("Abdu", 5000, 1, 1, true, 1, 1));
    Player2.insert(grassPtr3);
    */
    }   catch (const std:: invalid_argument & error) {
        cerr << "Caught exception: " << error.what() << endl;
    }

    

    // do while loop
    do
    {
        Menu();
        switch(userInput())
        {
            // plays game 
            case 1: 
            {
                Play(Player1, Player2);
                break;
            }
            // displays all the pokemon for both players
            case 2:
            {
                cout << "Player 1's Pokemon: " << endl;
                Player1.display();

                cout << "\n Player 2's Pokemon: " << endl;
                Player2.display();
                break;
            }
            // quits game
            case 3:
            {
                return  1;
                break;
            }
            // try again
            default:
            {   
                cout << "That is not a choice, try again. " << endl;
                Menu();
                userInput();
                break;
            }
        }
    
    }while (userInput() != 3);

    
/*
    // calling player list of pokemon
    cout << "Player 1's Pokemons:" << endl;
    Player1.display();
    cout << "\n\n";
    cout << "Player 2's Pokemons" << endl;
    Player2.display();
    
    cout << "\n\n";


    // TESTING CURRENT POKEMONS FIGHTING 
    Player1.displayCurrPokemon();
    Player1.GetPokemon()->GetPokemonPtr()->UseAttack(Player2.GetPokemon()->GetPokemonPtr());       
    cout << "\n";
    cout << "This pokemon was attacked" << endl;
    Player2.displayCurrPokemon();
    
    // testing removePokemon()
    cout << "This pokemon was removed after being attacked: " << endl;
    Player2.removePokemon(Player2.GetPokemon()->GetPokemonPtr());
    cout << "\n\n";
    Player2.display();
    
    // TESTING REMOVEALL
    cout << "**********************************" << endl;
    Player2.removeAllPokemon();
    Player2.display();

    cout <<"\n\n";
*/

    return 0;

}

// FUNCTION DEFINITIONS


int Play(BST& Player1, BST& Player2) {

    // do while loop
    do
    {
        // displays player 1 first pokemon
        cout << "Player 1 Pokemon:  " << endl;
        Player1.displayCurrPokemon();
        
        cout << "\n";
        cout << "vs\n";

        // displays player 2 first pokemon
        cout << "Player 2 Pokemon: " << endl;
        Player2.displayCurrPokemon();

        cout << "\n\n";
        FightingMenu(); // calls fighting menu
    
        // switch case to choose a function 
        switch(userInput())
        {
            case 1: 
                Player1.GetPokemon()->GetPokemonPtr()->UseAttack(Player2.GetPokemon()->GetPokemonPtr());
                if(Player2.GetPokemon()->GetPokemonPtr()->GetHealth() <= 0)
                {
                    Player2.removePokemon(Player2.GetPokemon()->GetPokemonPtr());
                }
                break;
            case 2:
                cout << "Function not implemented yet..." << endl;
                break;       
            case 3:
                cout << "Function not implemented yet..." << endl;
                break;
        }
    } while(!Player2.isEmpty());

    return 1;
}


// Starting menu
int Menu()
{
    cout << "\tPokemon Battle" << endl;
    cout << "------------------------------" << endl;
    cout << "1) Start" << endl;
    cout << "2) Pokemon Status" << endl;
    cout << "3) Quit" << endl;
    cout << "Choose a number: ";
    return 1;
}

// returns a user input
int userInput()
{
    int input;
    cin >> input;
    return input;
}



int FightingMenu()
{
    cout << "1) Attack" << endl;
    cout << "2) Block" << endl;
    cout << "3) Use Berry" << endl;
    return 1;
}
