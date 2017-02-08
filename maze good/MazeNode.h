




//Nicholas Genco
//Maze Project


#ifndef MAZE_NODE_H
#define MAZE_NODE_H
#include <cstdlib>

class MazeNode
{
public:
	MazeNode();
	MazeNode*& operator[](const unsigned int& way);
	MazeNode* operator*();
	unsigned short getcontent()const;
	void setcontent(const unsigned short&);
private:
	MazeNode* link[4];
	unsigned short content;
};
#endif