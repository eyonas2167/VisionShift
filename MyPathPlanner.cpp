#include "MyPathPlanner.h"
#include "MyGame.h"

using namespace mathtool;

namespace GMUCS425
{

MyPathPlanner::MyPathPlanner(MyScene * scene, MyAgent * agent)
{
  m_scene=scene;
  m_agent=agent;
}

//
//TODO: (10 pts)
//about 15~20 lines of code
//
//return true if m_agent collide with a non-movable object
//at a given location
//
bool MyPathPlanner::collision_detection(const Point2d& pos)
{
  //brute force collision detection

  //Hint:
  //methods to use: collide(), getX(), getY(), tranlateTo() in MyAgent
  //get_agents() in MyScene

  return false;
}

//TODO: (10 pts)
//estimate the cost of traveling from pos1 to pos2
//distance between pos1 and pos2 scaled using the values generated by Perlin noise
float MyPathPlanner::cost(const Point2d& pos1, const Point2d& pos2)
{
  const Uint32 * terrain = m_scene->get_terrain();
  int terrain_width = getMyGame()->getScreenWidth();
  int terrain_height = getMyGame()->getScreenHeight();

  //terrain is a (terrain_width X terrain_height) array

  float scale=1; //Note: the scale must be larger than 1
  
  //TODO:
  //estimate the scale here, if the terrain value is 0, the scale should be 1
  //if the terrain value is high, the scale should be larger, therefore the cost
  //of going from pos1 to pos2 is higher

  //Hint: there are many correct implementations, use your imagination
  

  return scale * (pos1-pos2).norm(); //scale this by the value in terrain
}

//------------
//TODO: (20 pts)
bool MyGridPathPlanner::build() //build a grid
{
  if(!m_grid.empty()) return false; //build only if the grid is empty

  m_grid=std::vector< std::vector<Node> >( m_height, std::vector<Node>(m_width,Node()) );
  float cell_w=getMyGame()->getScreenWidth()*1.0f/m_width;
  float cell_h=getMyGame()->getScreenHeight()*1.0f/m_height;

  //TODO: go through the nodes (cells) in the grid, and initial the data for each node
  for(int i=0;i<m_height;i++)
  {
    for(int j=0;j<m_width;j++)
    {
      Node & n=m_grid[i][j];

      //determine the values of n.pos, n.free and n.neighbors

      //Note: 
      // We consider 8-connection neighbors here. (N, W, E, S, NE, NW, SE, SW)
      // A node n has a neighobor node m iff both m and n are free (i.e. not occupied)
      // Thus, if a node is not free (i.e. occupied), it should not have any neighbors
      

    }//end j
  }//end i

  return true;
}

//finding a path using A*
bool MyGridPathPlanner::find_path( const Point2d& start, const Point2d& goal, std::list<Point2d>& path )
{
  //check if the start and goal are valid (i.e., inside the screen)
  if(start[0]<0 || start[1]>=getMyGame()->getScreenWidth()) return false;
  if(goal[0]<0 || goal[1]>=getMyGame()->getScreenWidth()) return false;

  float cell_w=getMyGame()->getScreenWidth()*1.0f/m_width;
  float cell_h=getMyGame()->getScreenHeight()*1.0f/m_height;

  vector<Node *> open, close;
  Node * S=&m_grid[(int)(start[1]/cell_h)][(int)(start[0]/cell_w)];
  Node * G=&m_grid[(int)(goal[1]/cell_h)][(int)(goal[0]/cell_w)];
  if(!S->free) cerr<<"! Error: Start point makes the agent collide with something"<<endl;
  if(!G->free) cerr<<"! Error: Goal point makes the agent collide with something"<<endl;
  bool found = true;

  //dummy path planning, replace the following two lines with A*
  path.push_front(goal);  //replace this
  path.push_front(start); //replace this

  return found;
}



//TODO: shorten and smooth the path (20 pts, 10 pts each)
//To smooth, use Quadratic Bezier curves
void MyPathPlanner::shorten_and_smooth(std::list<Point2d>& path)
{
  
  //We assume that the agent can travel along the path without colliding with
  //any static obstacles/objects
  //
  //
  //Note: "path" is both input and output
  //
  //Hints: 
  //  shorten: Pick a pair of points on the path
  //           make sure the line connecting the points are collision free
  //           replace all points in between with the line
  //           
  //  smooth: Pick 3 points on the path
  //          Compute the Quadratic Bezier curve from these 3 points
  //          Replace all points in between with the curve 
  //
  //  combined: Pick 3 points and smooth the path. 
  //            If failed, use 1st and 3rd point to shorten the path.

}

}//end namespace GMUCS425
