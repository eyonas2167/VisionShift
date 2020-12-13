#pragma once

#include "MyAgent.h"
#include "MyPlayerAgent.h"
#include "MySandwichAgent.h"
#include "MyBehaviorTree.h"
/**
 CS425 Final Project Elohe Yonas
**/


namespace GMUCS425
{
	class MyBlueAgent : public MyAgent
	{
	public:
		MyBlueAgent(bool movable = true, bool collision = true)
			:MyAgent(movable, collision)
		{
			collide_with = NULL;
			behavior = NULL;
		}

		virtual void update(std::list<MyAgent*> list);
		virtual void display();
		virtual void handle_event(SDL_Event& e);
		virtual void setDir(int newdir) { dir = newdir; };
		int getDir() { return dir; };
		int getRage() { return rage; };
		virtual void setRage(int newrage) { rage = newrage; };
	protected:

		//NEW
		void build_behavior_tree(std::list<MyAgent*> list, MyPlayerAgent* dragon, MySandwichAgent* Sandwich);

	private:

		int dir = 1;
		int rage = 1;

		MyAgent* collide_with;
		int collision_free_timer = 10;
		MyBehaviorTree* behavior; //NEW, build this!
		MyPlayerAgent* player = new MyPlayerAgent();
		MySandwichAgent* Sandwich = new MySandwichAgent();
		std::list<MyBehaviorTree*> behaviors;
	};

}//end namespace
