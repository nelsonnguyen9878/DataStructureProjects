// nguyen-nelson-prog1.cpp
//
// Libraries
#include <iostream> // cin cout
#include "attendees.h" // attendees .h uses all the datastructures such as CLL and ALLL
#include <vector> // lets us use vector functions, .size(), .push_back(), .empty()
#include <string> // string to let us use string member functions
using namespace std; // init variables and objects 

// ***** TEST CASES *******
// Entering in an age of 17 or less will let us be a kid attendee and displays information on the nodes and 
// the attendee.
//
// Entering in 18 or above and less tha 100, will let us access the maze , also gathering information on the
// attendee.
//
// Entering in above 100 will result in a zombine class, displays information and the event the zombies are suppose
// to go through.

// PROTOTYPES
int GrabUserInfo(string&, int&); // passes in a string and int by reference to modify the variables
int BuildMaze(ALLHauntedHouse); // builds the maze using our ALLHauntedHouse class
int VectorEvents(vector<string> & events); // creating the events in our vector list
int VectorDisplay(vector<string>); // Displays the vector list
int VectorRemoveAll(vector<string>); // removes all the data in the list

// beginning of main()
int main()
{
	//variables
	string name;
	int age;
	
	
	// grabs user information
	GrabUserInfo(name, age);
	
	// adult
	if(age > 18 && age < 100)
	{
		adult adult1(name, age, "Normal");
		adult1.display();
		ALLHauntedHouse Maze(5);
		BuildMaze(Maze);
		cout << endl;
	}
	
	// kid
	if(age < 18 && age > 0)
	{
		//kid kid1(name, age);
		//kid1.display();

		CLLKidMaze KidMaze;
		KidMaze.Insert(5);
		KidMaze.Insert(6);
		KidMaze.Insert(7);
		KidMaze.Insert(9);
		KidMaze.Display();
	}
	// Zombie
	if(age > 100) 
	{
		vector<string> events;
		VectorEvents(events);
		VectorDisplay(events);
		VectorRemoveAll(events);
	}
	cout << endl;

	return  0;
}


// Adds the events to the vector
int VectorEvents(vector<string>& events)
{
	if(!events.empty()) return 1;

	for(int i = 0; i < 3; i++)
	{
		events.push_back("Hello");// "events" will be replaced with a function that is an event
				    // for the zombie to be accessible with, didnt have
				    // the time to compelete that, so I inserted i. 
				    // This will allow us to see if we were able to insert
				    // it into the vector array. 
	}
	return 1;
}


// VectorDisplays all the data in the vector array by using a forloop to loop through and print out the data
int VectorDisplay(vector<string> events)
{
	for(int i = 0; i < 3; i++)
	{
		cout << events[i] << endl;
	}
	return 1;
}

// VectorRemoveAll(), passes in the vector to erase through each iteartion using the forloop
int VectorRemoveAll(vector<string> events)
{
	for(int i = events.size(); i > 0; i--)
	{
		events.erase(events.begin());
	}
	return 1;
}


// GrabsUserInfo, passes in name and age to be able to set the attendee() name and age
// considering the age range, it'll print out kid, adult, or zombie
int GrabUserInfo(string& name, int& age) {
	cout << "How old are you?: ";
	cin >> age;

	if(age > 18 && age <= 100) {
		cout << endl;
		cout << "What is your name?: ";
		cin >> name;
		cout << endl << "You are an Adult!" << endl;
	}

	if(age < 18 && age > 0) {
		cout << endl;
		cout << "What is your name?: ";
		cin >> name;
		cout << endl << "You are a kid" << endl;
	}	

	if(age > 100)
		cout << "You are a zombie!" << endl;
	return 1;
	
}





// function definitions
// uses function from the ALL huanted house maze, to create our rooms to traverse through. Uses the insert function
// by entering in which index of the array we want to be in, also known as our row number. Then the second number 
// would be the data of the room.
int BuildMaze(ALLHauntedHouse Maze)
{	
	// inserting (data , row)
	Maze.Insert(1, 0);
	Maze.Insert(1, 0);
	Maze.Insert(0, 0);
	Maze.Insert(0, 0);
	Maze.Insert(0, 0);

	Maze.Insert(0, 1);
	Maze.Insert(1, 1);
	Maze.Insert(0, 1);
	Maze.Insert(1, 1);
	Maze.Insert(1, 1);
	Maze.Insert(5, 1);

	Maze.Insert(0, 2);
	Maze.Insert(1, 2);
	Maze.Insert(1, 2);
	Maze.Insert(1, 2);
	Maze.Insert(0, 2);

	Maze.Insert(0, 3);
	Maze.Insert(0, 3);
	Maze.Insert(1, 3);
	Maze.Insert(0, 3);
	Maze.Insert(0, 3);

	Maze.Insert(0, 4);
	Maze.Insert(1, 4);
	Maze.Insert(1, 4);
	Maze.Insert(1, 4);
	Maze.Insert(1, 4);

	cout << "-------HAUNTED MAZE--------" << endl;
	Maze.Display(0);
	Maze.Display(1);
	Maze.Display(2);
	Maze.Display(3);
	Maze.Display(4);
	
	return 1;
}
