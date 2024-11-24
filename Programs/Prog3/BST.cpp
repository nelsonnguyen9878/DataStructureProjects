// filename: BST.cpp
// Author: Nelson Nguyen
// Summary: BST.cpp defines all the functions for the Node and BST class in BST.h
#include "BST.h"
#include <iostream> // cout
#include <stdexcept> // throwing and catching
using namespace std; // names



// NODE CLASS DEF************
// default constructor
Node::Node(): poke_ptr(nullptr), left(nullptr), right(nullptr)
{}

// overloaded constructor
Node::Node(shared_ptr<pokemon> n_pokeptr, Node* n_left, Node* n_right): poke_ptr(n_pokeptr), left(n_left), right(n_right)
{}

// GETTERS
// returns the current pokemon
shared_ptr<pokemon> Node::GetPokemonPtr()
{ return poke_ptr; }


// returns private member 'left'
Node* Node::GetLeft()
{ return left; }

// returns private member 'right'
Node* Node::GetRight()
{ return right; }

// SETTERS
// passes in a node to set to the left of the tree node
int Node::SetLeft(Node* incoming_node)
{ 
    left = incoming_node; 
    return 1;
}

// passes in a node to set to the right of the tree node
int Node::SetRight(Node* incoming_node)
{ 
    right = incoming_node; 
    return 1;
}


// BST CLASS DEF**************
// constructor
BST::BST(): root(nullptr)
{}


// insert wrapper function that calls the recursive helper function 
int BST::insert(const shared_ptr<pokemon>& new_pokemon)
{
    if(new_pokemon->GetHealth() > 500)
    {
        throw std::invalid_argument("Pokemon is not valid with that much health");
    }
    root = insertHelper(root, new_pokemon);
    return 1;
}


// insert helper function to add to the tree, passes in a root of the tree and a pokemon
// to determine if it is inserting left or right of the tree with the amount of health they have
Node* BST::insertHelper(Node* root, const shared_ptr<pokemon>& new_pokemon) 
{
    if(!root) 
        return new Node(new_pokemon, nullptr, nullptr);

    if(new_pokemon->GetHealth() < root->GetPokemonPtr()->GetHealth()) {
        root->SetLeft(insertHelper(root->GetLeft(), new_pokemon));
    }
    
    else if(new_pokemon->GetHealth() > root->GetPokemonPtr()->GetHealth()) {
        root->SetRight(insertHelper(root->GetRight(),new_pokemon));
    }

    return root;
}


// display wrapper that calls the recursive helper function
int BST::display() 
{
    if(!root)
    {
        cout << "There is no pokemons" << endl;
        return 1;
    }

    return displayHelper(root);
}

// display helper takes in a node root and determines the type of the pokemon
// to display their unqiue display function to display their stats
// recursively travels until the end of the tree and display all the pokemon stats
int BST::displayHelper(Node* root) 
{
    
    if(root == nullptr)
    {   return 0; }
    
    displayHelper(root->GetLeft()); // calls left

    shared_ptr<pokemon> base_ptr = root->GetPokemonPtr();


    fire* f_ptr = dynamic_cast<fire*>(base_ptr.get());
    if(f_ptr)
    { f_ptr->displayPokemon(); }

    water* w_ptr = dynamic_cast<water*>(base_ptr.get());
    if(w_ptr)
    { w_ptr->displayPokemon(); }

    grass* g_ptr = dynamic_cast<grass*>(base_ptr.get());
    if(g_ptr)
    { g_ptr->displayPokemon(); }
    
    cout << endl;
    displayHelper(root->GetRight());

/*
    if(root == nullptr)
    {   return 0; }

    displayHelper(root->GetLeft());

    
    root->GetPokemonPtr()->displayPokemon();
    displayHelper(root->GetRight());
*/
    return 1;
}

// wrapper function for display current pokemon 
// calls helper function to display the stats of the pokemon of their respected type
int BST::displayCurrPokemon()
{
    return displayCurrPokemonHelper(root);
}


// helper function to display the current pokemon at the root of the tree
// passes in root and determines the type of the pokemon to call their display type
int BST::displayCurrPokemonHelper(Node* root)
{
    
    shared_ptr<pokemon> base_ptr = root->GetPokemonPtr();


    fire* f_ptr = dynamic_cast<fire*>(base_ptr.get());
    if(f_ptr)
    { f_ptr->displayPokemon(); }

    water* w_ptr = dynamic_cast<water*>(base_ptr.get());
    if(w_ptr)
    { w_ptr->displayPokemon(); }

    grass* g_ptr = dynamic_cast<grass*>(base_ptr.get());
    if(g_ptr)
    { g_ptr->displayPokemon(); }

    return 1;
}

// returns the pokemon at the top of the tree
Node* BST::GetPokemon()
{
    return root;
}

// wrapper function for removePokemon, passes in a pokemon we want to remove from the
// tree
Node* BST::removePokemon(shared_ptr<pokemon> this_pokemon)
{
    if(root == nullptr)
        return 0;
    
    return removePokemonHelper(root, this_pokemon);
}


// removePokemonHelper takes in a root of the tree and a pokemon we're searching for.
// this will search the tree until we find that key pokemon and delete and use a 
// inOrderSuccessor function to set in place of the missing node
Node* BST::removePokemonHelper(Node* root, shared_ptr<pokemon> this_pokemon)
{
    if(root == nullptr)
        return root;

    if(this_pokemon->GetHealth() < root->GetPokemonPtr()->GetHealth())
    {
        root->SetLeft(removePokemonHelper(root->GetLeft(), this_pokemon));
    }

    if(this_pokemon->GetHealth() > root->GetPokemonPtr()->GetHealth())
    {
        root->SetRight(removePokemonHelper(root->GetRight(), this_pokemon));
    }

    else {
        if(root->GetLeft() == nullptr)
        {
            Node* temp = root->GetRight();
            delete root;
            return temp;
        }
        else if(root->GetRight() == nullptr)
        {
            Node* temp = root->GetLeft();
            delete root;
            return temp;
        }

        Node* successor = inOrderSuccessor(root->GetRight());

        root->GetPokemonPtr() = successor->GetPokemonPtr();

        root->SetRight(removePokemonHelper(root->GetRight(), this_pokemon));
    }
    return root;
}

// this will find the successor for the root of the tree, 
// takes in incoming_node which is the root of the tree and traverse left
// until we find the end.
Node* BST::inOrderSuccessor(Node* incoming_node)
{
    Node* current = incoming_node;
    if(current && current->GetLeft() != nullptr)
    {
        return inOrderSuccessor(current->GetLeft());
    }
    return current;
}



// this will pass in the root node to the removeAllPokemonHelper to initiate
// the recursive function to remove all the nodes in the tree
int BST::removeAllPokemon()
{
    if(!root)
        return 0;

    return removeAllPokemonHelper(root);
    root = nullptr;
}

// function that takes in the root ptr of the tree and delete all the 
// components of the tree 
int BST::removeAllPokemonHelper(Node* root)
{
    if(root == nullptr)
        return 0;

    removeAllPokemonHelper(root->GetLeft());
    removeAllPokemonHelper(root->GetRight());

    delete root;
    return 1;
}

bool BST::isEmpty()
{
    if(!root)
        return true;

    else
        return false;
}








