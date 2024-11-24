// filename:: BST.h
// Author: Nelson Nguyen
#include <memory>
#include "pokemon.h"


// Node class
class Node 
{
    public:
        Node(); // default constructor
        Node(shared_ptr<pokemon> n_pokeptr, Node* n_left, Node* n_right); // overloaded constructor
        shared_ptr<pokemon> GetPokemonPtr(); // grabs ptr for  pokemon
        Node* GetLeft(); // returns left
        Node* GetRight(); // returns right
        int SetLeft(Node*); // Sets the left node
        int SetRight(Node*); // sets the right node
    private:
        shared_ptr<pokemon> poke_ptr; // pointer to a pokemon
        Node* left; // left node
        Node* right; // right node
};


// BST Class
class BST
{
    public:
        BST(); // constructor
        int insert(const shared_ptr<pokemon>&); // inserts pokemon that is passed in
        int display(); // displays all pokemon
        int displayCurrPokemon(); // displays pokemon at root
        Node* GetPokemon(); // grabs a pokemon ptr
        bool isEmpty(); // checks if it is empty or not 
        Node* removePokemon(shared_ptr<pokemon>); // remove key pokemon
        int removeAllPokemon(); // removes all pokemon in the tree
        Node* inOrderSuccessor(Node*); // Sets the next succesor of the tree
    private:
        Node* root;
        Node* insertHelper(Node*, const shared_ptr<pokemon>&);
        int displayHelper(Node*);
        int displayCurrPokemonHelper(Node*);
        Node* removePokemonHelper(Node*, shared_ptr<pokemon>);
        int removeAllPokemonHelper(Node*);
};









