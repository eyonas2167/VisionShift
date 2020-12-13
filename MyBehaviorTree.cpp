#include "MyBehaviorTree.h"


bool MySelectorNode::run()
{
  //TODO: implement this

	for(auto node = children.begin(); node != children.end(); node++)
	{
		if (node._Ptr->_Myval->run()==true)
		{
			return true;
		}
		
	}
  return false;
}

bool MySequenceNode::run()
{
  //TODO: implement this
	for (auto node = children.begin(); node != children.end(); node++)
	{
		if (node._Ptr->_Myval->run()==false)
		{
			return false;
		}
		
	}
  return true;
}

//Note: You are free to create more types of nodes if needed