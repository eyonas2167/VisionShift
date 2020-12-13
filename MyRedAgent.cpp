#include "MyRedAgent.h"
#include "mathtool/Box.h"
#include "MyGame.h"
#include "MySandwichAgent.h"
#include "MyPlayerAgent.h"
/**
Elohe Yonas CS425 Final Project
**/
namespace GMUCS425
{
  //The base class of all Red behavior nodes
  //again, this is an abstract class because "run" is not implemented
  class MyRedTaskNode : public MyTaskNode
  {
  public:
    MyRedTaskNode(MyRedAgent * agent){ Red=agent; }
  protected:
    MyRedAgent * Red;
  };

  //TODO: Define more tasks here


  //TODO: Define more tasks here
  //LoS = Line of Sight
  class MyRedTaskCheckLoS : public MyRedTaskNode
  {
  public:
    MyRedTaskCheckLoS(MyRedAgent * agent):MyRedTaskNode(agent)
    {
		cur_agent = agent;
		
    }
    bool run(){
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
	  MyRedAgent* cur_agent;
	  float cx, cy;
  };



   class MyRedTaskCheckLoSC : public MyRedTaskNode
  {
  public:
    MyRedTaskCheckLoSC(MyRedAgent * agent):MyRedTaskNode(agent)
    {
		cur_agent = agent;
		
    }
    bool run(){
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
	  MyRedAgent* cur_agent;
	  float cx, cy;
  };




  class MyRedTaskCheckFoV : public MyRedTaskNode //field of vision between Red and player
  {
  public:
	  MyRedTaskCheckFoV(MyRedAgent* agent) :MyRedTaskNode(agent)
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
					if(((cx - cur_agent->getX())*(cx-cur_agent->getX())+(cy - cur_agent->getY())*(cy - cur_agent->getY()))<radius1*radius1)
				   {
					   cur_agent->tranlateTo(x, y);
					   return false;
				   }
				cur_agent->tranlateTo(x, y);
		//  }


		  return true;
	  }
  private:
	  MyRedAgent* cur_agent;
	  float cx, cy;
  };

  class MyRedTaskCheckFoVC : public MyRedTaskNode //field of vision between Sandwich and Red
  {
  public:
	  MyRedTaskCheckFoVC(MyRedAgent* agent) :MyRedTaskNode(agent)
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
	  MyRedAgent* cur_agent;
	  float cx, cy;
  };




  class MyRedTaskRageMode : public MyRedTaskNode //set the rage behavior of Red
  {
  public:
	  MyRedTaskRageMode(MyRedAgent* agent) :MyRedTaskNode(agent)
	  {
		  cur_agent = agent; //REMOVE this
	  }
	  bool run() {
		  //TODO: implement this
		  cur_agent->setRage(2);
		  return true;
	  }
  private:
	  MyRedAgent* cur_agent; //remove this
  };

  class MyRedTaskWander : public MyRedTaskNode //set the wandering behavior of Red
  {
  public:
	  MyRedTaskWander(MyRedAgent* agent) :MyRedTaskNode(agent)
	  {
		  cur_agent = agent; //REMOVE this
	  }
	  bool run() {
		  MySceneManager* scenemanager = getMyGame()->getSceneManager();
		  MyScene* scene = scenemanager->get_active_scene();
		  int rage = cur_agent->getRage();
		  if (scene->getRed() == -1)
		  {
			  rage = 0;
		  }

		  MyRedAgent name;
		  std::list<MyAgent*>agentlist = scene->get_agents();
		  if (0 >= cur_agent->getX())
		  {
			  cur_agent->setDir(cur_agent->getDir()*-1);
			 // Red->tranlate(2 * Red->getDir(), 0);
			  cur_agent->tranlate(1*cur_agent->getDir(),0);
		  }
		  else if(Red->getX() >= getMyGame()->getScreenWidth())
		  {
			  cur_agent->setDir(cur_agent->getDir() * -1);
			  //Red->tranlate(02 * Red->getDir(), 0);
			  cur_agent->tranlate(1*cur_agent->getDir(),0);
		  }
		  else
		  {
			  cur_agent->tranlate(1 * cur_agent->getDir()*rage, 0);
			  for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
			  {
				  if (cur_agent->collide(agent._Ptr->_Myval) && !(strcmp(typeid(**agent).name(), typeid(name).name()) == 0))
				  {
					  cur_agent->tranlate(-1*cur_agent->getDir()*rage,0);
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
	  MyRedAgent* cur_agent; //remove this
  };


  //hunt task
  class MyRedTaskHunt : public MyRedTaskNode
  {
  public:
	  MyRedTaskHunt(MyRedAgent* agent,MyPlayerAgent* player) :MyRedTaskNode(agent) //set the hunt behavior of Red
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
		  MyRedAgent Redname;
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
		  float smallest=99999;
		  int rage = cur_agent->getRage();
		  if (scene->getRed() == -1)
		  {
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
			  cur_agent->tranlate(-1*rage, -1*rage);
			  for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
			  {
				  if (cur_agent->collide(agent._Ptr->_Myval) && !(strcmp(typeid(**agent).name(), typeid(Redname).name()) == 0))
				  {
					 cur_agent->tranlate(1*rage, 1*rage);
					 
					 
				  }
			  }
		  }
		  else if (smallest == n)
		  {
			  cur_agent->tranlate(0, -1*rage);
			  for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
			  {
				  if (cur_agent->collide(agent._Ptr->_Myval) && !(strcmp(typeid(**agent).name(), typeid(Redname).name()) == 0))
				  {
					  cur_agent->tranlate(0, 1*rage);
					  
				  }
			  }
		  }
		  else if (smallest == ne)
		  {
			  cur_agent->tranlate(1*rage, -1*rage);
			  for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
			  {
				  if (cur_agent->collide(agent._Ptr->_Myval) && !(strcmp(typeid(**agent).name(), typeid(Redname).name()) == 0))
				  {
					  cur_agent->tranlate(-1 * rage, 1 * rage);
					  
				  }
			  }
		  }
		  else if (smallest == w)
		  {
			  cur_agent->tranlate(-1*rage, 0);
			  for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
			  {
				  if (cur_agent->collide(agent._Ptr->_Myval) && !(strcmp(typeid(**agent).name(), typeid(Redname).name()) == 0))
				  {
					  cur_agent->tranlate(1 * rage,0);
					  
				  }
			  }
		  }
		  else if (smallest == e)
		  {
			  cur_agent->tranlate(1,0);
			  for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
			  {
				  if (cur_agent->collide(agent._Ptr->_Myval) && !(strcmp(typeid(**agent).name(), typeid(Redname).name()) == 0))
				  {
					  cur_agent->tranlate(-1 * rage,0);
					  
				  }
			  }
		  }
		  else if (smallest == sw)
		  {
			  cur_agent->tranlate(-1*rage, 1*rage);
			  for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
			  {
				  if (cur_agent->collide(agent._Ptr->_Myval) && !(strcmp(typeid(**agent).name(), typeid(Redname).name()) == 0))
				  {
					  cur_agent->tranlate(1 * rage, -1 * rage);
					  
				  }
			  }
		  }
		  else if (smallest == s)
		  {
			  cur_agent->tranlate(0, 1*rage);
			  for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
			  {
				  if (cur_agent->collide(agent._Ptr->_Myval) && !(strcmp(typeid(**agent).name(), typeid(Redname).name()) == 0))
				  {
					  cur_agent->tranlate(0,- 1 * rage);
					  
				  }
			  }
		  }
		  else if (smallest == se)
		  {
			  cur_agent->tranlate(1*rage, 1*rage);
			  for (auto agent = agentlist.begin(); agent != agentlist.end(); agent++)
			  {
				  if (cur_agent->collide(agent._Ptr->_Myval) && !(strcmp(typeid(**agent).name(), typeid(Redname).name()) == 0))
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
	  MyRedAgent* cur_agent; //remove this
	  float cx,cy;
  };

  ///////////////////////////



  ///////////////////////////

  //TODO: make sure that you define more tasks here, ex: MyRedTask03~MyRedTask99

  //TODO: build your behavior tree here
  void MyRedAgent::build_behavior_tree(std::list<MyAgent*> list,MyPlayerAgent* player,MySandwichAgent* Sandwich)
  {
    MyTaskNode * root=NULL;

    //TODO:
    //Create a root
    //Create more nodes using MyRedTask1~MyRedTask100
    //use add_kid to build the rest of the tree!

	std::list<MyAgent*> obstacles;
	std::list<MyRedAgent*> Reds;
	//std::list<MyRedAgent*> Reds;
	MyRedAgent Red=NULL;
	MyPlayerAgent playername;
	MySandwichAgent Sandwichname;
	

	for (auto agent = list.begin(); agent !=list.end(); agent++) //some old code that does nothing now
	{
		//printf("%s\n",typeid(**agent).name());
		if (strcmp(typeid(**agent).name(), typeid(Sandwichname).name())==0)
		{
		}
		else if (strcmp(typeid(**agent).name(), typeid(playername).name()) == 0)
		{
		}
		else if (strcmp(typeid(**agent).name(),typeid(Red).name()) == 0)
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
	//MySelectorNode* ragewander = new MySelectorNode();
	//MySelectorNode* ragehunt = new MySelectorNode();
	base->add_kid(agro);
	base->add_kid(hunt);
	MyRedTaskCheckLoS* playerLoS = new MyRedTaskCheckLoS(this);
	MyRedTaskCheckFoV* playerFoV = new MyRedTaskCheckFoV(this);
	MyRedTaskWander* Redwander = new MyRedTaskWander(this);

	MyRedTaskHunt* Redhunt = new MyRedTaskHunt(this,player);
		agro->add_kid(playerLoS);
		agro->add_kid(playerFoV);
		agro->add_kid(Redwander);


		hunt->add_kid(Redhunt);

	root = base;
    //build the tree using the root
    this->behavior=new MyBehaviorTree(root);
	
  }

  void MyRedAgent::display()
  {
    if(!this->visible) return; //not visible...
    //setup positions and ask sprite to draw something
    this->sprite->display(x, y, scale, degree);
	if (player->getRed() == true)
	{
		this->sprite->display(x, y, scale, degree, NULL);
		draw_bounding_box();
		draw_HUD();
	}
  }

  void MyRedAgent::update(std::list<MyAgent*> list)
  {
    if(this->behavior==NULL)
    {
        this->build_behavior_tree(list,player,Sandwich);
        assert(this->behavior);
		
    }
	behavior->run();
    if(!this->collision)
    {
      if(collision_free_timer>=0) this->collision_free_timer--;
      else collide_with=NULL; //no collision
    }
	
    this->collision=false;
  }

  void MyRedAgent::handle_event(SDL_Event & e)
  {

    if(this->collision && collide_with!=NULL)
    {
      return;
    }

    if(e.type==SDL_USEREVENT)
    {
      if(e.user.code == 1)
      {
        if(e.user.data1==this || e.user.data2==this)
        {
          MyAgent * other = (MyAgent *)((e.user.data1!=this)?e.user.data1:e.user.data2);

          if(other!=collide_with)
          {
            collide_with=other;
          }
          this->collision_free_timer=10;
          this->collision=true;
        }
      }
    }
  }

}//end namespace
