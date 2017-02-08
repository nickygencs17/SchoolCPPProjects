
//Nicholas Genco
//Maze Project


#include "Maze.h"
#include<iostream>


const std::string Maze::itemlist[] = { "Diamond", "Emerald", "Ruby", "Pearl", "Jade" };

Maze::Maze(const size_t& NumberofNodes)
{
	maxnodes = NumberofNodes;
	answered = false;
	itemctr = 0;
	MazeEntry = NULL;
	MazeExit = NULL;
	cursor = NULL;
	path = NULL;
	generate();
}

Maze::~Maze()
{
	delete[] MazeEntry;
	delete[] MazeExit;
	delete[] cursor;
	delete[] path;
}

void Maze::generate()
{
	unsigned int direction;
	size_t numofpaths = 0;
	size_t numofbranchnodes[4] = { 0 };
	assert(maxnodes > 0);
	MazeEntry = new MazeNode();
	cursor = MazeEntry;
	numofpaths = 4;

	if (numofpaths > (maxnodes - 1))
		numofpaths = maxnodes;

	for (unsigned int n = 0; n < numofpaths; ++n)
		numofbranchnodes[n] = static_cast<size_t>((maxnodes - 1) / numofpaths);

	for (unsigned int n = 0; n < numofpaths; ++n)
	{
		do
		{
			direction = std::rand() % 4;
		} while ((*cursor)[direction] != NULL);

		createbranch(numofbranchnodes[n], direction);
		cursor = MazeEntry;
	}

}

void Maze::createbranch(const size_t Branchlength, unsigned int Direction)
{
	size_t numofpaths;
	
	size_t numofbranchnodes[4] = { 0 };
	
	MazeNode* temp;

	if (Branchlength > 0)
	{
		temp = new MazeNode();
		(*cursor)[Direction] = temp;
		(*temp)[0] = cursor;
		cursor = temp;
		numofpaths = 1 + std::rand() % 3;

		if (rand() % 100 < 3)
		{
			setcurrentnodecontent(rand() % 5);
			++itemctr;
		}
        
		if (numofpaths > (Branchlength - 1))
			numofpaths = Branchlength;

		for (unsigned int n = 0; n <= 4; ++n)
			numofbranchnodes[n] = 0;

		for (unsigned int n = 1; n <= numofpaths; ++n)
		{
			do
			{
				Direction = std::rand() % 4;
				std::cout << Direction << std::endl;
			} while ((*cursor)[Direction] != NULL);

			numofbranchnodes[Direction] = (int)((Branchlength- 1) / numofpaths);
			createbranch(numofbranchnodes[Direction], Direction);

			if (MazeExit == NULL)
				MazeExit = cursor;

			cursor = temp;
		}
	}

	return;
}

bool Maze::back() const
{
	return (*cursor)[0] != NULL;
}

bool Maze::left() const
{
	return (*cursor)[1] != NULL;
}

bool Maze::ahead() const
{
	return (*cursor)[2] != NULL;
}

bool Maze::right() const
{
	return (*cursor)[3] != NULL;
}

bool Maze::goback()
{
	if ((*cursor)[0] != NULL)
		cursor = (*cursor)[0];
	return true;
}

bool Maze::goleft()
{
	if ((*cursor)[1] != NULL)
		cursor = (*cursor)[1];
	return true;
}

bool Maze::goahead()
{
	if ((*cursor)[2] != NULL)
		cursor = (*cursor)[2];
	return true;
}

bool Maze::goright()
{
	if ((*cursor)[3] != NULL)
		cursor = (*cursor)[3];
	return true;
}

std::string Maze::nodecontent()const
{
	if ((*cursor).getcontent() == -1)//always false?
		return std::string();
	else
		return itemlist[(*cursor).getcontent()];
}

void Maze::setcurrentnodecontent(const unsigned short& valin)
{
	(*cursor).setcontent(valin);
}

unsigned short Maze::getitemcount()const
{
	return itemctr;
}

