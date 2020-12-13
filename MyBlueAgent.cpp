#include "MyBlueAgent.h"
#include "mathtool/Box.h"
#include "MyGame.h"
#include "MySandwichAgent.h"
#include "MyPlayerAgent.h"
/**
Elohe Yonas CS425 Final Project
**/
namespace GMUCS425
{
	//The base class of all Blue behavior nodes
	//again, this is an abstract class because "run" is not implemented
	class MyBlueTaskNode : public MyTaskNode
	{
	public:
		MyBlueTaskNode(MyBlueAgent* agent) { Blue = agent; }
	protected:
		MyBlueAgent* Blue;
	};

	//TODO: Define more tasks here


	//TODO: Define more tasks here
	//LoS = Line of Sight
	class MyBlueTaskCheckLoS : public MyBlueTaskNode
	{
	public:
		MyBlueTaskCheckLoS(MyBlueAgent* agent) :MyBlueTaskNode(agent)
		{
			cur_agent = agent;

		}
		bool run() {
			//TODO: implement this
			  //if there is nothing in sight return true else return false
			MySceneManager* scenemanager = getMyGame()->getSceneManager();
			MyScene* scene = scenemanager->get_active_scene();
			std::list<MyAgent*>agentlist = scene->get_agents();
			MyPlayerAgent name;
			for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
			{
				//printf("%s\n",typeid(**agent).name());
				if (strcmp(typeid(**agent).name(), typeid(name).name()) == 0)
				{
					cx = agent._Ptr->_Myval->getX();
					cy = agent._Ptr->_Myval->getY();
					//printf("values of x,y %f,%f\n", cx, cy);
					break;

				}
			}


			if ((cur_agent->getX() <= cx && cx <= cur_agent->getX()) || (cur_agent->getY() <= cy && cy <= cur_agent->getY()))
			{
				return false;
			}
			return true;
		}
	private:
		MyBlueAgent* cur_agent;
		float cx, cy;
	};



	class MyBlueTaskCheckLoSC : public MyBlueTaskNode
	{
	public:
		MyBlueTaskCheckLoSC(MyBlueAgent* agent) :MyBlueTaskNode(agent)
		{
			cur_agent = agent;

		}
		bool run() {
			//TODO: implement this
			  //if there is nothing in sight return true else return false
			MySceneManager* scenemanager = getMyGame()->getSceneManager();
			MyScene* scene = scenemanager->get_active_scene();
			std::list<MyAgent*>agentlist = scene->get_agents();
			MySandwichAgent name;
			for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
			{
				//printf("%s\n",typeid(**agent).name());
				if (strcmp(typeid(**agent).name(), typeid(name).name()) == 0)
				{
					cx = agent._Ptr->_Myval->getX();
					cy = agent._Ptr->_Myval->getY();
					//printf("values of x,y %f,%f\n", cx, cy);
					break;

				}
			}


			if ((cur_agent->getX() <= cx && cx <= cur_agent->getX()) || (cur_agent->getY() <= cy && cy <= cur_agent->getY()))
			{
				return true;
			}
			return false;
		}
	private:
		MyBlueAgent* cur_agent;
		float cx, cy;
	};




	class MyBlueTaskCheckFoV : public MyBlueTaskNode //field of vision between Blue and player
	{
	public:
		MyBlueTaskCheckFoV(MyBlueAgent* agent) :MyBlueTaskNode(agent)
		{
			cur_agent = agent;
		}
		bool run() {
			//TODO: implement this
			  //if there is nothing in field of awareness return true else return false
			MySceneManager* scenemanager = getMyGame()->getSceneManager();
			MyScene* scene = scenemanager->get_active_scene();
			std::list<MyAgent*>agentlist = scene->get_agents();
			MyPlayerAgent name;
			for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
			{
				//printf("%s\n",typeid(**agent).name());
				if (strcmp(typeid(**agent).name(), typeid(name).name()) == 0)
				{
					cx = agent._Ptr->_Myval->getX();
					cy = agent._Ptr->_Myval->getY();
					// printf("values of x,y %f,%f\n", cx, cy);
					break;

				}
			}

			////////////////////////////////////////
			int degree;
			float radius1 = 100;
			float x = cur_agent->getX();
			float y = cur_agent->getY();
			//  for(degree = 0;degree<360;degree++) //check the radial view of radius 1
			 //{
			   //   float rx = cur_agent->getX() + radius1 * cos((float)degree * PI / 180);
				//  float ry = cur_agent->getY() + radius1 * cos((float)degree * PI / 180);
				  //cur_agent->tranlateTo(cur_agent->getX()+radius1*cos((float)degree*PI/180), cur_agent->getY()+radius1*cos((float)degree*PI/180));
					  //if (((cur_agent->getX() >= cx && cx >=rx) || (cur_agent->getY()>=cy && cy >= ry)))
			if (((cx - cur_agent->getX()) * (cx - cur_agent->getX()) + (cy - cur_agent->getY()) * (cy - cur_agent->getY())) < radius1 * radius1)
			{
				cur_agent->tranlateTo(x, y);
				return false;
			}
			cur_agent->tranlateTo(x, y);
			//  }


			return true;
		}
	private:
		MyBlueAgent* cur_agent;
		float cx, cy;
	};

	class MyBlueTaskCheckFoVC : public MyBlueTaskNode //field of vision between Sandwich and Blue
	{
	public:
		MyBlueTaskCheckFoVC(MyBlueAgent* agent) :MyBlueTaskNode(agent)
		{
			cur_agent = agent;
		}
		bool run() {
			//TODO: implement this
			  //if there is nothing in field of awareness return true else return false
			MySceneManager* scenemanager = getMyGame()->getSceneManager();
			MyScene* scene = scenemanager->get_active_scene();
			std::list<MyAgent*>agentlist = scene->get_agents();
			MySandwichAgent name;
			for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
			{
				//printf("%s\n",typeid(**agent).name());
				if (strcmp(typeid(**agent).name(), typeid(name).name()) == 0)
				{
					cx = agent._Ptr->_Myval->getX();
					cy = agent._Ptr->_Myval->getY();
					// printf("values of x,y %f,%f\n", cx, cy);
					break;

				}
			}

			////////////////////////////////////////
			int degree;
			float radius1 = 100;
			float x = cur_agent->getX();
			float y = cur_agent->getY();
			//  for(degree = 0;degree<360;degree++) //check the radial view of radius 1
			 //{
			   //   float rx = cur_agent->getX() + radius1 * cos((float)degree * PI / 180);
				//  float ry = cur_agent->getY() + radius1 * cos((float)degree * PI / 180);
				  //cur_agent->tranlateTo(cur_agent->getX()+radius1*cos((float)degree*PI/180), cur_agent->getY()+radius1*cos((float)degree*PI/180));
					  //if (((cur_agent->getX() >= cx && cx >=rx) || (cur_agent->getY()>=cy && cy >= ry)))
			if (((cx - cur_agent->getX()) * (cx - cur_agent->getX()) + (cy - cur_agent->getY()) * (cy - cur_agent->getY())) < radius1 * radius1)
			{
				cur_agent->tranlateTo(x, y);
				return false;
			}
			cur_agent->tranlateTo(x, y);
			//  }


			return true;
		}
	private:
		MyBlueAgent* cur_agent;
		float cx, cy;
	};




	class MyBlueTaskWander : public MyBlueTaskNode //set the wandering behavior of Blue
	{
	public:
		MyBlueTaskWander(MyBlueAgent* agent,MyPlayerAgent* player) :MyBlueTaskNode(agent)
		{
			cur_agent = agent; //REMOVE this
			p_agent = player;
		}
		bool run() {
			int rage = cur_agent->getRage();
			MySceneManager* scenemanager = getMyGame()->getSceneManager();
			MyScene* scene = scenemanager->get_active_scene();
			//printf("%d\n", cur_player->getBlue());
			//printf("%d\n", -1 * -1);
			if (scene->getBlue()==-1)//checks if you are in the same plane of existence
			{
				//printf("%d\n",cur_player->getBlue());
				rage = 0;
			}
		
			MyBlueAgent name;
			std::list<MyAgent*>agentlist = scene->get_agents();
			if (0 >= cur_agent->getX())
			{
				cur_agent->setDir(cur_agent->getDir() * -1);
				// Blue->tranlate(2 * Blue->getDir(), 0);
				cur_agent->tranlate(1 * cur_agent->getDir(), 0);
			}
			else if (Blue->getX() >= getMyGame()->getScreenWidth())
			{
				cur_agent->setDir(cur_agent->getDir() * -1);
				//Blue->tranlate(02 * Blue->getDir(), 0);
				cur_agent->tranlate(1 * cur_agent->getDir(), 0);
			}
			else
			{
				cur_agent->tranlate(1 * cur_agent->getDir() * rage, 0);
				for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
				{
					if (cur_agent->collide(agent._Ptr->_Myval) && !(strcmp(typeid(**agent).name(), typeid(name).name()) == 0))
					{
						cur_agent->tranlate(-1 * cur_agent->getDir() * rage, 0);
						cur_agent->setDir(cur_agent->getDir() * -1);

						cur_agent->tranlate(1 * cur_agent->getDir() * rage, 0);
						cur_agent->setRage(1);
						return true;
					}
				}
			}

			//TODO: implement this
		   // printf("did it\n");
			cur_agent->setRage(1);
			return true;
		}
	private:
		MyBlueAgent* cur_agent; //remove this
		MyPlayerAgent* p_agent;
	};


	//hunt task
	class MyBlueTaskHunt : public MyBlueTaskNode
	{
	public:
		MyBlueTaskHunt(MyBlueAgent* agent, MyPlayerAgent* player) :MyBlueTaskNode(agent) //set the hunt behavior of Blue
		{
			cur_agent = agent; //REMOVE this
			p_agent = player;
			cx = 0;
			cy = 0;
		}
		bool run() {


			MySceneManager* scenemanager = getMyGame()->getSceneManager();
			MyScene* scene = scenemanager->get_active_scene();


			std::list<MyAgent*>agentlist = scene->get_agents();
			MyPlayerAgent name;
			MyBlueAgent Bluename;
			for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
			{
				//printf("%s\n",typeid(**agent).name());
				if (strcmp(typeid(**agent).name(), typeid(name).name()) == 0)
				{
					cx = agent._Ptr->_Myval->getX();
					cy = agent._Ptr->_Myval->getY();
					//printf("values of x,y %f,%f\n", cx, cy);
					break;

				}
			}

			/////////////////////////
			float smallest = 99999;
			int rage = cur_agent->getRage();
			if (scene->getBlue() == -1)//checks if you are in the same plane of existence
			{
				//printf("%d\n",cur_player->getBlue());
				rage = 0;
			}
			std::list<float> list;
			//printf("%f\n", cur_agent->getX());
			//printf("%f\n", cur_agent->getY());
			float nw = fabsf((cur_agent->getX() - 1) - (cx)) + fabsf((cur_agent->getY() - 1) - (cy));
			list.push_front(nw);
			float n = fabsf((cur_agent->getX()) - (cx)) + fabsf((cur_agent->getY() - 1) - (cy));
			list.push_front(n);
			float ne = fabsf((cur_agent->getX() + 1) - (cx)) + fabsf((cur_agent->getY() - 1) - (cy));
			list.push_front(ne);
			float w = fabsf((cur_agent->getX() - 1) - (cx)) + fabsf((cur_agent->getY()) - (cy));
			list.push_front(w);
			float e = fabsf((cur_agent->getX() + 1) - (cx)) + fabsf((cur_agent->getY()) - (cy));
			list.push_front(e);
			float sw = fabsf((cur_agent->getX() - 1) - (cx)) + fabsf((cur_agent->getY() + 1) - (cy));
			list.push_front(sw);
			float s = fabsf((cur_agent->getX()) - (cx)) + fabsf((cur_agent->getY() + 1) - (cy));
			list.push_front(s);
			float se = fabsf((cur_agent->getX() + 1) - (cx)) + fabsf((cur_agent->getY() + 1) - (cy));
			list.push_front(se);

			for (int i = 0; i < 8; i++)
			{
				float test = list.back();
				if (smallest >= test)
				{
					smallest = test;
				}
				list.pop_back();
			}

			if (smallest == nw)
			{
				cur_agent->tranlate(-1 * rage, -1 * rage);
				for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
				{
					if (cur_agent->collide(agent._Ptr->_Myval) && !(strcmp(typeid(**agent).name(), typeid(Bluename).name()) == 0))
					{
						cur_agent->tranlate(1 * rage, 1 * rage);


					}
				}
			}
			else if (smallest == n)
			{
				cur_agent->tranlate(0, -1 * rage);
				for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
				{
					if (cur_agent->collide(agent._Ptr->_Myval) && !(strcmp(typeid(**agent).name(), typeid(Bluename).name()) == 0))
					{
						cur_agent->tranlate(0, 1 * rage);

					}
				}
			}
			else if (smallest == ne)
			{
				cur_agent->tranlate(1 * rage, -1 * rage);
				for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
				{
					if (cur_agent->collide(agent._Ptr->_Myval) && !(strcmp(typeid(**agent).name(), typeid(Bluename).name()) == 0))
					{
						cur_agent->tranlate(-1 * rage, 1 * rage);

					}
				}
			}
			else if (smallest == w)
			{
				cur_agent->tranlate(-1 * rage, 0);
				for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
				{
					if (cur_agent->collide(agent._Ptr->_Myval) && !(strcmp(typeid(**agent).name(), typeid(Bluename).name()) == 0))
					{
						cur_agent->tranlate(1 * rage, 0);

					}
				}
			}
			else if (smallest == e)
			{
				cur_agent->tranlate(1, 0);
				for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
				{
					if (cur_agent->collide(agent._Ptr->_Myval) && !(strcmp(typeid(**agent).name(), typeid(Bluename).name()) == 0))
					{
						cur_agent->tranlate(-1 * rage, 0);

					}
				}
			}
			else if (smallest == sw)
			{
				cur_agent->tranlate(-1 * rage, 1 * rage);
				for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
				{
					if (cur_agent->collide(agent._Ptr->_Myval) && !(strcmp(typeid(**agent).name(), typeid(Bluename).name()) == 0))
					{
						cur_agent->tranlate(1 * rage, -1 * rage);

					}
				}
			}
			else if (smallest == s)
			{
				cur_agent->tranlate(0, 1 * rage);
				for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
				{
					if (cur_agent->collide(agent._Ptr->_Myval) && !(strcmp(typeid(**agent).name(), typeid(Bluename).name()) == 0))
					{
						cur_agent->tranlate(0, -1 * rage);

					}
				}
			}
			else if (smallest == se)
			{
				cur_agent->tranlate(1 * rage, 1 * rage);
				for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
				{
					if (cur_agent->collide(agent._Ptr->_Myval) && !(strcmp(typeid(**agent).name(), typeid(Bluename).name()) == 0))
					{
						cur_agent->tranlate(-1 * rage, -1 * rage);

					}
				}
			}
			//TODO: implement this
		   // printf("hunt\n");
			cur_agent->setRage(1);
			return true;
		}
	private:
		MyPlayerAgent* p_agent;
		MyBlueAgent* cur_agent; //remove this
		float cx, cy;
	};

	///////////////////////////



	///////////////////////////

	//TODO: make sure that you define more tasks here, ex: MyBlueTask03~MyBlueTask99

	//TODO: build your behavior tree here
	void MyBlueAgent::build_behavior_tree(std::list<MyAgent*> list, MyPlayerAgent* player, MySandwichAgent* Sandwich)
	{
		MyTaskNode* root = NULL;

		//TODO:
		//Create a root
		//Create more nodes using MyBlueTask1~MyBlueTask100
		//use add_kid to build the rest of the tree!

		std::list<MyAgent*> obstacles;
		std::list<MyBlueAgent*> Blues;
		//std::list<MyBlueAgent*> Blues;
		MyBlueAgent Blue = NULL;
		MyPlayerAgent playername;
		MySandwichAgent Sandwichname;


		for (auto agent = list.begin(); agent != list.end(); agent++) //some old code that does nothing now
		{
			//printf("%s\n",typeid(**agent).name());
			if (strcmp(typeid(**agent).name(), typeid(Sandwichname).name()) == 0)
			{
			}
			else if (strcmp(typeid(**agent).name(), typeid(playername).name()) == 0)
			{
			}
			else if (strcmp(typeid(**agent).name(), typeid(Blue).name()) == 0)
			{
			}
			else
			{
				obstacles.push_back(*agent);
			}

		}
		/**
		tree building below
		**/
		MySelectorNode* base = new MySelectorNode();
		MySequenceNode* agro = new MySequenceNode();
		MySequenceNode* hunt = new MySequenceNode();
		
		base->add_kid(agro);
		base->add_kid(hunt);
		MyBlueTaskCheckLoS* playerLoS = new MyBlueTaskCheckLoS(this);
		MyBlueTaskCheckFoV* playerFoV = new MyBlueTaskCheckFoV(this);
		MyBlueTaskCheckFoVC* SandwichFoVwander = new MyBlueTaskCheckFoVC(this);
		MyBlueTaskCheckFoVC* SandwichFoVhunt = new MyBlueTaskCheckFoVC(this);
		MyBlueTaskWander* Bluewander = new MyBlueTaskWander(this,player);

		MyBlueTaskHunt* Bluehunt = new MyBlueTaskHunt(this, player);
		
		agro->add_kid(playerLoS);
		agro->add_kid(playerFoV);
		agro->add_kid(Bluewander);
		hunt->add_kid(Bluehunt);

		root = base;
		//build the tree using the root
		this->behavior = new MyBehaviorTree(root);

	}

	void MyBlueAgent::display()
	{
		if (!this->visible) return; //not visible...
		//setup positions and ask sprite to draw something
		this->sprite->display(x, y, scale, degree);
		draw_bounding_box();
	}

	void MyBlueAgent::update(std::list<MyAgent*> list)
	{
		if (this->behavior == NULL)
		{
			this->build_behavior_tree(list, player, Sandwich);
			assert(this->behavior);

		}
		behavior->run();
		if (!this->collision)
		{
			if (collision_free_timer >= 0) this->collision_free_timer--;
			else collide_with = NULL; //no collision
		}

		this->collision = false;
	}

	void MyBlueAgent::handle_event(SDL_Event& e)
	{

		if (this->collision && collide_with != NULL)
		{
			return;
		}

		if (e.type == SDL_USEREVENT)
		{
			if (e.user.code == 1)
			{
				if (e.user.data1 == this || e.user.data2 == this)
				{
					MyAgent* other = (MyAgent*)((e.user.data1 != this) ? e.user.data1 : e.user.data2);

					if (other != collide_with)
					{
						collide_with = other;
					}
					this->collision_free_timer = 10;
					this->collision = true;
				}
			}
		}
	}

}//end namespace