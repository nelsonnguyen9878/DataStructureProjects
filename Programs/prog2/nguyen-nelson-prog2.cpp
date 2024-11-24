// nguyen-nelson-prog2
//

// libraries
#include <iostream>
#include "card.h"
//#include "player.h"
#include "dll.h"
#include <cstdlib>
#include <array>
using namespace std;

// prototypes
int menu(); // displays menu
int play(); //starts the game
int GetInput(); // grabs user input
int cardMenu(); // displays card menu
Deck<skill> buildSkillDeck(Deck<skill>&); // fills the deck with different cards
Deck<equipment> buildEquipDeck(Deck<equipment>&); // fills the deck with different cards





// int main that has a switch case to let the user choose from the menu
// play() will call the play function and start the game
int main()
{

    // Setting up Game
    menu();
    switch (GetInput()) {
        case 1:
            play();
            break;
        case 2:
            return 0;
            break;
        default:
            return 0;
    }
/*

    // TESTING CREATION OF CARDS and INSERTIONS
    // creating test cards
	card testcard1("Test", "common");
    card testcard2("Test", "uncommon");
    skill skillcard1("Fireball", "common", 2, 0);
    skill skillcard2("Fireball", "rare", 2, 0);
    skill skillcard3("Air bomb", "common", 2, 0);
    skill skillcard4("Earthquake", "uncommon", 2, 0);
    // inserting them into the deck
    SpellDeck.insertAtHead(skillcard1);
    SpellDeck.insertAtHead(skillcard2);
    SpellDeck.insertAtHead(skillcard3);
    SpellDeck.insertAtHead(skillcard4);
    SpellDeck.displayAll();

    SpellDeck.popAtTail();
    //SpellDeck.popAtHead();

    SpellDeck.displayAll();
    //skillcard1.DisplaySkillCard();
    //skillcard2.DisplaySkillCard();
    //skillcard3.DisplaySkillCard();
    //skillcard4.DisplaySkillCard();
	//testcard1.DisplayCard();
    //player1.CheckStatus();

    
    // TESTING ASSIGNMENT OPERATORS
    if(testcard1 != testcard2)
    {
        cout << "They're not the same" << endl;
    }

    if(testcard1 == testcard2)_
    {
        cout << "The same!" << endl;
    }

    if(testcard < testcard2)
    {
        cout << "Less than card2" << endl;
    }

*/
    


	return 0;
}	


// play function, switch cases that lets user choose which option to do
// creation of decks and players.
int play()
{  
    // variables
    string firstPlayer;
    string secondPlayer;
    bool player_turn = true;
    std::array<player, 2> players;
    // Declaring Decks
    // Skill Deck
    Deck<skill> SpellDeck;
    buildSkillDeck(SpellDeck);

    // Equipment Deck
    Deck<equipment> EquipDeck;
    buildEquipDeck(EquipDeck);

    Deck<trap> TrapDeck;


    cout << "\n\n";
    // setting player1 name
    cout << "Player 1, please enter your name: ";
    cin >> firstPlayer;
    players.at(0).SetName(firstPlayer);
   // player player1(firstPlayer, 100, 1, 0);
    players.at(0).CheckStatus();
    cout << endl;
    
    // setting player2 name
    cout << "Player 2, please enter your name: ";
    cin >> secondPlayer;
    players.at(1).SetName(secondPlayer);
   // player player2(secondPlayer, 100, 1, 0);
    players.at(1).CheckStatus();
    cout << endl;


    // starting game
    if(player_turn) 
    {
        // do while to keep the game going until either player's health hits 0
        do {
            player_turn = !player_turn;
            cardMenu();        
            // allows first player to choose from a deck
            switch (GetInput())
            {
                // SKILL Deck chosen
                case 1: 
                {
                    SpellDeck.grabAtHead().PlayCard(players.at(0), players.at(1)); // plays card
                    SpellDeck.grabAtHead().DisplaySkillCard(); // display the card chosen
                    //SpellDeck.displayAll(); // TEST: this will display all the cards in the current deck, uncomment to test the use of DLL
                    skill temp = SpellDeck.grabAtHead(); // setting it to temp, so we can insert to the end of the list
                    SpellDeck.popAtHead(); // this will pop the head of the list in the DLL
                    SpellDeck.insertAtTail(temp); // inserts card to the end of the list
                    //SpellDeck.displayAll(); // TEST: uncomment if you want to see the head node be transfered to the end of the list
                    break;
                }
                // EQUIPMENT Deck chosen, does the same functions as the skill option above
                case 2:
                {
                    EquipDeck.grabAtHead().PlayCard(players.at(0), EquipDeck.grabAtHead());
                    EquipDeck.grabAtHead().DisplayEquipCard();
                    equipment temp = EquipDeck.grabAtHead();
                    EquipDeck.insertAtTail(temp);
                    EquipDeck.popAtHead();
                    
                    break;
                }
                case 3: // this is where the trap deck options would display
                {
                    cout << "Not finished... ";
                    break;
                }
                case 4: // exit in infinite loop
                    return 0;
                // default
                default:
                    cout << "Try again, " << endl;
                    GetInput();
            }

        } while(players.at(0).GetHealth() <= 0 || players.at(1).GetHealth() <= 0); 

    }
 
    // frees up all the memory that we've allocated by  building the decks
    SpellDeck.removeAll();
    EquipDeck.removeAll();

    return 1;
}

// menu display that displays the description and a menu to select from
int menu()
{
    cout << "\tARCANE ARSENAL" << endl << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "How to play: This is a one on one player card battle," << endl;
    cout << "once in the game, you will have three decks to select" << endl;
    cout << "from and will use to attack your opponent or help " << endl;
    cout << "yourself. Strategically use these cards to your" << endl;
    cout << "advantage to bring your opponents health zero, to    " << endl;
    cout << "secure the victory." << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "1) Play" << endl;
    cout << "2) Quit" << endl;
    cout << "Select a choice: ";
return 0;
};


// function grabs user input, creating a local variable to return 
// the user input of an integer.
int GetInput()
{
    int userInput;
    cin >> userInput;
    return userInput;
}



// DECK BUILD******************************
// SKILL DECK BUILD
// function has hard coded a DLL list of cards inserted at head
// new_deck is passed in by reference to be modified so it can be returned
// to the game
Deck<skill> buildSkillDeck(Deck<skill>& new_deck)
{
    // creating test cards
    skill skillcard1("Fireball", "common", 2, 0);
    skill skillcard2("Fireball", "rare", 2, 0);
    skill skillcard3("Air bomb", "common", 2, 0);
    skill skillcard4("Earthquake", "uncommon", 2, 0);
    // inserting them into the deck
    new_deck.insertAtHead(skillcard1);
    new_deck.insertAtHead(skillcard2);
    new_deck.insertAtHead(skillcard3);
    new_deck.insertAtHead(skillcard4);
    return new_deck;
}


// EQUIPMENT DECK BUILD
// function creates equipment cards and is inserted into the new_deck
// by modifying the deck. 
Deck<equipment> buildEquipDeck(Deck<equipment>& new_deck)
{
    // creating  equipment cards
    equipment equipcard1("Stone Sword", "common", 2, 0);
    equipment equipcard2("Exaclibur", "rare", 10, 0);
    equipment equipcard3("Wooden Shield", "common", 0, 1);
    equipment equipcard4("THE WALL", "rare", 0, 10);

    // inserting into equipment deck
    new_deck.insertAtHead(equipcard1);
    new_deck.insertAtHead(equipcard2);
    new_deck.insertAtHead(equipcard3);
    new_deck.insertAtHead(equipcard4);
    return new_deck;
}

/* need to fix and implement on how it will work
Deck<trap> buildTrapDeck(Deck<trap>& new_deck)
{
    trap trapcard1("Skip", "common" 


    return new_deck;
}
*/

// displays a menu of deck choices
int cardMenu()
{  
    cout << "1) Skill" << endl;
    cout << "2) Equipment" << endl;
    cout << "3) Trap" << endl;
    cout << "4) Quit. Leave in the case of an infinite loop" << endl;
    cout << "Choose a deck to select a card from: ";
    return 1;
}
