// attendees.cpp
// edited: 10/21/24

#include <iostream>
#include "attendees.h"
#include <cstring>
using namespace std;

// definition for attendees class
// default constructor
attendees::attendees() : name(""), age(0), status(nullptr)
{
}

// constructor
attendees::attendees(const string &name, int age, const char* new_status) 
{
	this->name = name;
	this->age = age;

	status = new char[strlen(new_status)+1];
	strcpy(this->status, new_status);
}

// deconstructor
attendees::~attendees() { delete[] status; }

// attendees copy constructor
attendees::attendees(const attendees& x)
{
	name = x.name;
	age = x.age;
	
	status = new char[strlen(x.status)+1];
	strcpy(status, x.status);
}

// beginning of display()
int attendees::display() const
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Status: " << string((const char*)status) << endl;
       return 1;	
}// end of display()



// beginning of compare_name
bool attendees::compare_name(const string &name_comp) const 
{
	// returns true if name is equal to compared name
	// else it is returning false
	return name == name_comp;
} // end of compare_name


// beginning of copy_name
bool attendees::copy_name(string & copy)
{
	name = copy;
	return true;
} // end of copy_name

// assignment operator
attendees& attendees::operator=(const attendees& other)
{
	if(this == &other) return *this;

	if(status)
		delete[] status;
	
	status = new char[strlen(other.status) + 1];
	strcpy(status, other.status);

	return *this;	
}




// definition for derived class kid *********
// default constructor
kid::kid() : candies_collected(0)
{
}

//overloaded constructor
kid::kid(const string & name, int age): attendees(name, age, nullptr), candies_collected(0)
{}

// copy constructor
kid::kid(const kid& other) {
	this->candies_collected = other.candies_collected;
}

// allows the kid to pick up a pumpkin in the maze, was not able to implement this
// begining of pickPumpkin()
bool kid::pickPumpkin()
{
	return false;
}// end of pickPumpkin()


// beginning of scream(), purpose is to go through the maze and can choose to scream or not
// as a kid.
bool kid::scream()
{
	return false;
} // end of hayRide()
 

// beginning of pickCandy() allows the user to pick up the candy in the CLL that is presented
// in the room, was not able to implement this
int kid::pickCandy()
{
	return 1;
} // end of pickCandy()


// DEFINITION FOR DERIVED CLASS ADULT
// adult default constructor
adult::adult() : lost(false), fear(nullptr)
{
}

// adult overloaded constructor
adult::adult(const string & name, int age, const char* status) : attendees(name, age, status), lost(false), fear(nullptr)
{}

// deconstructor
adult::~adult() { delete[] fear; }

// copy constructor
adult::adult(const adult& x)
{
	lost = x.lost;

	fear = new char[strlen(x.fear) + 1];
	strcpy(status, x.fear);
}

// assignment operator
adult& adult::operator=(const adult& other)
{
	if(this == &other) return *this;

	if(status)
		delete[] status;

	fear = new char[strlen(other.fear) + 1];
	strcpy(fear, other.fear);

	return *this;


}

// The plan with these functions for forward, backward, left, and right is to traverse the 
// Array of LLL. Had a lot of difficulty trying to implement these in the list. 
// beginning of forward()
int adult::forward()
{
	return 1;
} // end of forward()

// beginning of backward()
int adult::backward()
{
	return -1;
} // end of backward()

// beginning of left()
int adult::left()
{
	return 0;
} // end of left()


// beginning of right()
int adult::right()
{	
	return 0;
} // end of right()



// DEFINITION FOR DERIVED CLASS ZOMBIE
zombie::zombie() : people_scared(0)
{
}


// ADULT CLASS NODE
adultNode::adultNode() : next(nullptr), room(0) // default constructor
{}

// overloaded constructor
adultNode::adultNode(int room)
{
	this->room = room;
	this->next = nullptr;
}

//copy constructor
adultNode::adultNode(const adultNode & new_next) : adult(new_next), next(nullptr)
{
}


// returns next pointer
adultNode *& adultNode::get_next()
{
	return next;
}

// returns the room number which is either a 0 or 1
int adultNode::get_room()
{
	return room;
}

// sets current next to the new next so that way we can grab the new node
int adultNode::set_next(adultNode* new_next)
{
	next = new_next;
	return 1;
}



// LLLHAUNTEDHOUSE CLASS DEF ********
// default constructor
ALLHauntedHouse::ALLHauntedHouse() : array_head(nullptr) {}

//overload constructor to dynamically allocate the memory for our array
ALLHauntedHouse::ALLHauntedHouse(int num_row) : array_head(nullptr)
{
	array_head = new adultNode*[num_row];
}


// deconstructor
// uses a for loop to iterate through the all the array of headpointers and removes each list
// and deleting the array and setting it the double pointer to nullptr
ALLHauntedHouse::~ALLHauntedHouse() {
	for(int i = 0; i < 5; ++i) 
	{
		RemoveAll(i);
	}
	delete [] array_head;
	array_head = nullptr;
	
}

// RemoveAll wrapper, passes in index to let us know which index of the LLL to start removing
int ALLHauntedHouse::RemoveAll(int index)
{
	if(array_head[index] != nullptr) {
		return RemoveAllHelper(array_head[index]);
	}
	return 1;
}

// RemoveAllHelper passes in adultNode*& head as a pointer and reference so that way we can
// modify the LLL. It recursively calls next on head to get the next node and remove it until 
// there isnt anything left in the list of that current index.
int  ALLHauntedHouse::RemoveAllHelper(adultNode*& head) 
{
	
	if(head  == nullptr)
	{
		delete head;
		return 1;
	}
	
	adultNode* tail = head->get_next();
	delete head;
	head = tail;
	return  RemoveAllHelper(head);
}


// ALLHauntedHouse will insert a LLL of rooms to create a maze
// Insert() will allocate new memory to create a room filled with the data 0's and 1's
// to determine which room is available to enter or not. 
// Insert() Wrapper, passes in roomNumber which is either a 0 or 1. Index will let us know
// which index we're in to point to that head pointer in the index.
int ALLHauntedHouse::Insert(int roomNumber, int index) 
{
	if(array_head[index] == nullptr) { // if headpointer is empty we'll insert a node at the head
		array_head[index] = new adultNode(roomNumber); // allocating memory to set head to value
		return 1;
	}
	return InsertHelper(array_head[index], roomNumber);
}


// InsertHelper() passes in head pointer and roomNumber. The array_head pointer is pointed to a
// head pointer that we passed in and we're inserting nodes in that index
// the nodes are insert roomNumber and recursively calls next.
int ALLHauntedHouse::InsertHelper(adultNode* head, int roomNumber)
{
	if(head->get_next() == nullptr) // checks if we're at last node to insert
	{	
		adultNode* newRoom = new adultNode(roomNumber); // dynamically allocating memory
		head->set_next(newRoom); // setting the room data
		return 1;
	}
	return InsertHelper(head->get_next(), roomNumber); // recursively goes next until we reach last node
}






// Display() wrapper passes in index to initialize the index we want to be at in the array
// to print out the LLL
int ALLHauntedHouse::Display(int index) const
{
	if(!array_head[index]) return 0; // if headpointer is empty, return 0
	cout << endl;
	return DisplayHelper(array_head[index]); // calls recursive function
}



// DisplayHelper() runs through the whole linear linked list of the index
// by using head[index] to print current room and recursively gets the next node to print
int ALLHauntedHouse::DisplayHelper(adultNode* head) const
{	
	if(head == nullptr) // base case
		return 0;

	cout << head->get_room() << " "; // prints out the room data
	return DisplayHelper(head->get_next()); // recursively gets next
}







// KID NODE *****************
// defualt constructor
kidNode::kidNode() : next(nullptr)
{
}

// copy constructor
kidNode::kidNode(const kidNode& to_copy)
{
	next = to_copy.next;
}


// initializing current next to new_next being added
int kidNode::set_next(kidNode* new_next)
{
	this->next = new_next;
	return 1;
}

// returns next pointer
kidNode*& kidNode::get_next() 
{
	return next;
}

// returns the amount of candy , which is the private variable
int kidNode::get_candy_amount()
{
	return amount_of_candy;
}

// overload constructor, that sets the current node to the candy being passed in
kidNode::kidNode(int amount_of_candy) : next(nullptr)
{
	this->amount_of_candy = amount_of_candy;
}


// CLLKidMaze ********************

//default constructor
CLLKidMaze::CLLKidMaze(): rear(nullptr)
{
}


// Insert wrapper, amount of candy is passed in and passed into the head if there is no
// existing nodes or it'll be passed into the recursive helper function. 
int CLLKidMaze::Insert(int amount_of_candy)
{
	if(rear == nullptr)
	{
		rear = new kidNode(amount_of_candy);
		rear->set_next(rear);
	}
	//kidNode* current = rear;
	return InsertHelper(rear, amount_of_candy);

}


// Helper Function for Insert() that passes in a current and amount of candy. Current is a
// pointer that allows us to traverse the list. Amount_of_candy will go into the constructor of
// kidNode to initialize the amount for that node.
int CLLKidMaze::InsertHelper(kidNode* current, int amount_of_candy)
{
	if(current->get_next() == rear)
	{
		kidNode* temp = new kidNode(amount_of_candy);
		current->set_next(temp);
		temp->set_next(rear);
		return 1;
	}
	return InsertHelper(current->get_next(), amount_of_candy);

}

// Display() wrapper, calls our recursive helper function to print out the candies available
int CLLKidMaze::Display() const
{
	if(!rear) return 0;
	
	return DisplayHelper(rear);
}


// Helper function for Display(), passes in kidNode* current pointer to allow us to
// traverse through the list and print out the amount of candies that are available in the 
// room for the kid to grab.
int CLLKidMaze::DisplayHelper(kidNode* current) const
{
	if(current->get_next() == rear) 
	{
		cout << current->get_candy_amount() << endl;
		return 0;
	}

	cout << current->get_candy_amount() << " ";
		
	return DisplayHelper(current->get_next());
}


// destructor that calls RemoveAll() function
CLLKidMaze::~CLLKidMaze()
{
	RemoveAll();
	rear = nullptr;
}

// Wrapper function for RemoveAll, destructor will call this function to
// remove all nodes in the list and free memory
int CLLKidMaze::RemoveAll()
{
	if(!rear)
		return 0;

	return RemoveAllHelper(rear);
}


// Remove All Helper function that recursively removes all nodes
// takes in a current pointer to traverse through so we can compare it to rear
// we don't set it as rear because that is the name of the beginning node, it would make
// it confusing if we set it as rear.
int CLLKidMaze::RemoveAllHelper(kidNode*& current)
{
	if(current->get_next() == rear)
	{
		delete current;
		return 1;
	}
	
	kidNode* temp = current;
	delete current;
	current = temp;
	
	return RemoveAllHelper(current->get_next());

}
