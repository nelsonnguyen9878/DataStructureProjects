// attendees.h
#pragma once
#include <string>
using std::string;

// Base class
// will pass down constructor, display(), compare_name, and copy_name to allow
// derived classes to inherit these public functions
class attendees
{
	public:
		attendees(); // default constructor
		attendees(const string&, int, const char*); // overloaded constructor
		~attendees(); // deconstructor
		attendees(const attendees& x);
		int display() const;
		bool compare_name(const string & name_comp) const;
		bool copy_name(string & copy);
		attendees& operator=(const attendees& other);
	protected:
		string name;
		int age;
		char* status;
};

// derived class from base class attendees
// kid will inherit name and age
class kid: public attendees
{
	public:
		kid(); // default constructor
		kid(const string & name, int age); // overloaded constructor
		kid(const kid& kid2); // copy constructor
		bool pickPumpkin();
		bool scream();
		int pickCandy();
		
	protected:
		int candies_collected;
};

// adult class derived from attendees, will be using CLL to traverse through the
// maze using forward, left, right functions
// private char* status to consider the status of the adult in the maze and update
// lost if they're lose in the maze
class adult: public attendees
{
	public:
		adult(); // constructor
		adult(const string & name, int age, const char*);
		adult(const adult& x); // copy constructor
		~adult();
		adult& operator=(const adult& other);
		int forward();
		int backward();
		int left();
		int right();

	protected:
		bool lost;
		char* fear;

};


// zombie class that ahs three public functions to chase, scare, or check brain
// private variable that keeps track of people were scared.
class zombie: public attendees
{
	public:
		zombie();
		void chase();
		void scare();
		void attack();

	protected:
		int people_scared;
};

// adult class node derived from adult
class adultNode: public adult
{
        public:
                adultNode();
                adultNode(const adultNode & to_copy);
               // adultNode(const string & name, int age); // overload constructor
		adultNode(int room);
                int set_next(adultNode * new_next);
                adultNode *& get_next();
                int get_room();
                bool has_next();
                bool jumpScare();
        private:
                adultNode* next;
                int room;
};


// Array of Linear linked list
class ALLHauntedHouse
{
        public:
               	ALLHauntedHouse(); // default constructor
		ALLHauntedHouse(int);
                ~ALLHauntedHouse(); // deconstructor
                int RemoveAll(int);
                int Insert(int, int);
                int Display(int index) const;

        private:
                adultNode** array_head;	// pointer

                int RemoveAllHelper(adultNode*&);
                int DisplayHelper(adultNode*) const;
                int InsertHelper(adultNode*, int roomNumber); // room is considered as a room in the maze


};



// kid class node derived from kid
class kidNode: public kid
{
        public:
                kidNode(); // default constructor
                kidNode(const kidNode & to_copy); // copy constructor
                kidNode(int); // overload constructor
                int set_next(kidNode * new_next); // set next to a new next
                kidNode *& get_next(); // returns next
		int get_candy_amount();
                bool has_next(); // checks if it has next

        protected:
                kidNode * next;
		int amount_of_candy;
};


// Circular linked list for the kid maze
class CLLKidMaze
{
	public:
		CLLKidMaze(); // default constructor
		//CLLKidMaze(int); // ovverload constructor
		~CLLKidMaze(); // deconstructor
		int RemoveAll();
		int Insert(int);
		int Display() const;

	private:
		kidNode* rear;
		int InsertHelper(kidNode*, int);
		int DisplayHelper(kidNode*) const;
		int RemoveAllHelper(kidNode*&);
};


// init the ZombieVector class so the HauntedHouse could have a list of people to challenge or scare
// 
/*
class ZomebieVector
{
	public:
		vector<zombie> zombie_vec;
		int BuildList(zombie_vec);
			


	private:
};
*/
