#include "MySandwichAgent.h"

namespace GMUCS425
{
  void MySandwichAgent::display()
  {
    if(!this->visible) return; //not visible...
    //setup positions and ask sprite to draw something
    this->sprite->display(x, y, scale, degree, NULL, this->ccw?SDL_FLIP_HORIZONTAL:SDL_FLIP_NONE);
    draw_bounding_box();
  }


  void MySandwichAgent::handle_event(SDL_Event & e)
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
          if(other!=this->collide_with)
          {
            //std::cout<<"changed to: "<<other<<" from " << collide_with<<std::endl;
            collide_with=other;
            ccw=!ccw;
          }
          this->collision_free_timer=10;
          this->collision=true;
        }//end if
      }//end if
    }//end if
  }

  void MySandwichAgent::update(std::list<MyAgent*> list)
  {
    if(!this->collision)
    {
		if (collision_free_timer >= 0)
		{
			this->collision_free_timer--;
		}
      else collide_with=NULL; //no collision
    }
    this->collision=false;

    if(radius==FLT_MAX)
    {
      radius=30;
      center_x=x; center_y=y-radius;
    }

	/**
    float angle=(ccw)?0.1:-0.1;
    float cos_t=cos(angle);
    float sin_t=sin(angle);

    float dx=x-center_x;
    float dy=y-center_y;
    float d=sqrt(dx*dx+dy*dy);
    dx=dx/d;
    dy=dy/d;

    x=(int)((cos_t*dx-sin_t*dy)*radius)+center_x;
    y=(int)((sin_t*dx+cos_t*dy)*radius)+center_y;
	**/
  }

}//end namespace
