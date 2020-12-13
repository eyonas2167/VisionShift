#pragma once

#include "MyAgent.h"
#include "mathtool/Point.h"

namespace GMUCS425
{
    class MyPathPlanner; //define in MyPathPlanner.h

    class MyPlayerAgent : public MyAgent
    {
    public:
      MyPlayerAgent(bool movable=true, bool collision=true):MyAgent(movable,collision)
      { dx=dy=0;collide_with=NULL;has_goal=left=false;planner=NULL;}

      virtual void handle_event(SDL_Event & e);
      virtual void update(std::list<MyAgent*> list);
      virtual void draw_HUD();
      //render this agent
      virtual void display();
	  int getRed() { return redview; };
	  
	  int getBlue() { return blueview; };
	  void toggleRed() { redview *=-1; };
	  void toggleBlue() { blueview *= -1; }
    private:

      void move_to_next_waypoint();
      void pathing();

      //display goal and path if there is any
      void draw_goal_and_path();
      //path planning related data
      bool has_goal;
      mathtool::Point2d goal;
      std::list<mathtool::Point2d> path;
      MyPathPlanner * planner;

      //basic data
      int dx, dy;
      bool left;
	  int redview = 1;
	  int blueview = -1;
	  int score = 0;
	  
      MyAgent * collide_with;
    };

}//end namespace
