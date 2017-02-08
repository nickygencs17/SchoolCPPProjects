
//Nicholas Genco
//Maze Project



#include "MazeNode.h"

MazeNode::MazeNode()
{
	for (int n = 0; n < 4; ++n)
		link[n] = NULL;
	content = -1;
}

MazeNode*& MazeNode::operator[](const unsigned int& way)
{
	return link[way];
}

MazeNode* MazeNode::operator*()
{
	return this;
}

unsigned short MazeNode::getcontent()const
{
	return content;
}

void MazeNode::setcontent(const unsigned short& valin)
{
	content = valin;
}