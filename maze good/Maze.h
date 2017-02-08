
//Nicholas Genco
//Maze Project



#ifndef MAZE_H
#define MAZE_H

#include <stack>
#include <deque>
#include <string>
#include <ctime>
#include <cassert>
#include "MazeNode.h"
using namespace std;

class Maze
{
public:
	static const std::string itemlist[5];
	Maze(const size_t& NumberofNodes = 1000);
	~Maze();
	bool back() const;
	bool left() const;
	bool ahead() const;
	bool right() const;
	bool goback();
	bool goleft();
	bool goahead();
	bool goright();
	bool solve1(struct Direction pos, char dir);
	bool solve2(struct Direction pos, char dir);
private:
	void generate();
	void createbranch(const size_t NumberofNodes, unsigned int direction);
	void preorder(const char direction);
	std::string nodecontent()const;
	void setcurrentnodecontent(const unsigned short& valin);
	unsigned short getitemcount()const;
	size_t counter = 0;
	struct Direction
	{
		size_t steps = 0;// Keeps track of the amount of steps taken to solve he maze

		char dir;// char object that will hold the current direction
		
		//Pre:
		//Post:Return the steps data member
		size_t getsteps()const { return steps; }// 

		//Pre:
		//Post:Increments the size_t object called steps by 1
		void stepup(){ ++steps; }

		//Pre:The function needs a char object which will be used to set the direction
		//Post:Assigning the char object that was passed to the char data member called "dir".
		//which will later be used to set the direction of the Mazenode
		void setDir(char Dir){ dir = Dir; }

		//Pre:
		//Post:Returns the char object that contains the character that represents the direction 
		//you take a step in 
		char getDir()const { return dir; }
	};

	bool solve1(Direction pos, char dir)
	{
		// Base case for recursive function
		if (cursor == MazeExit)
			return true;

		// Not counting entering the binary search tree maze a step but keep track of every step after
		if (counter > 0)
			pos.stepup();

		// Increment the counter
		++counter;

		// Setting the direction that will be push onto stack
		pos.setDir(dir);

		// Print out every step to keep track of what steps where taken. Used for debugging purposes 
        std::cout << "\n Step: " << pos.getDir() ;

		ss.push(pos.getDir());

	
		if (left() && goleft() && solve1(pos, 'L'))
		{
			return true;
		}

		
		if (right() && goright() && solve1(pos, 'R'))
		{
			return true;
		}

		if (ahead() && goahead() && solve1(pos, 'A'))
		{
			return true;
		}

		if (back() && goback() && solve1(pos, 'B'))
		{
			return true;
		}

		ss.pop();

		return false;

	}


	bool solve2(Direction pos, char dir)
	{
		// Base case for recursive function
		if (cursor == MazeExit)
			return true;

		// Not counting entering the binary search tree maze a step but keep track of every step after
		if (counter > 0)
			pos.stepup();

		// Increment the counter
		++counter;

		// Setting the direction that will be push onto stack
		pos.setDir(dir);

		// Print out every step to keep track of what steps where taken. Used for debugging purposes 
		std::cout << "Step: " << pos.getDir() << std::endl;

		// Push a char object to the stack for backtracking purposes
		ss2.push(pos.getDir());

		//If the cursor is not null then go right in the tree
		if (right() && goright() && solve2(pos, 'R'))
		{
			return true;
		}

		// If the cursor can't go right and is not null the go left in the tree
		if (left() && goleft() && solve2(pos, 'L'))
		{
			return true;
		}

		// If I can't go left or right and the cursor is not null then move ahead
		if (ahead() && goahead() && solve2(pos, 'A'))
		{
			return true;
		}


		// If I can't go left or right or ahead and the cursor is not null the move back
		if (back() && goback() && solve2(pos, 'B'))
		{
			return true;
		}

		ss.pop();

		return false;

	}


	MazeNode* MazeEntry;
	MazeNode* MazeExit;
	MazeNode* cursor;
	MazeNode* path; 
	size_t maxnodes;
	bool answered;
	std::stack<char, std::deque<char> > ss;
	std::stack<char, std::deque<char> > ss2;
	unsigned short itemctr;
};
#endif