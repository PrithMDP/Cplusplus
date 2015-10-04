// Example program
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct point
{
  int x;
  int y;
  char sym;
  bool visited;
};
void printmap(vector<vector<point> > map, int size);
void pointadder( point a, stack<point> & route, vector<vector<point> > map);

int main()
{
  unsigned size;
  cout<<"Enter the size of the matrix: ";
    cin>>size;
  cout<<endl;
  vector<vector<point> > map;
  map.resize(size);
  for( int i=0;i<size;i++)
  {
    map[i].resize(size);
  }
  //map will have # as walls and . as ground
  for(int i=0; i<size;i++){  //initializing map 
      for(int j=0;j<size;j++)
        {
            int a=rand()%8;
            if(a%5==0)
            {
              map[i][j].sym='#';
            }
            else
            {
              map[i][j].sym='.';
            }
            map[i][j].visited=false;
	      }
    }
    int s1,s2;  //starting point
    int e1,e2;  //ending point
    s1=rand()%size;
    s2=rand()%size;
    e1=rand()%size;
    e2=rand()%size;

    map[s1][s2].sym='S';
    map[e1][e2].sym='E';

    stack<point> route;
    route.push(map[s1][s2]); //push starting point

       printmap(map,size);

    while(!route.empty())
    {
      //pop the point
      point here=route.top();
      route.pop();

      //add the surrounding points (left right up down)
      cout<<"adding\n";
      pointadder(here,route,map);
      if(route.empty())
      {
        cout<<"no path exists!";
      }
      cout<<"added \n";
    }

   printmap(map,size);
}
void printmap(vector<vector<point> > map, int size)
{
  for(int i=0; i<size;i++)
  {  //initializing map 
      for(int j=0;j<size;j++)
        {
          cout<<map[i][j].sym<<" ";
        }
        cout<<endl;
  }
}

void pointadder(point a, stack<point> & route, vector<vector<point> > map)
{
  // left is [x][y-1] // right is [x][y+1] // up is [x-1][y] // down is [x+1][y]
  if( a.y -1 > 0 && map[a.x][a.y-1].sym!='#' && a.visited==false) //left is fine
  {
    if(map[a.x][a.y-1].sym=='E')
    {
      cout<<"found at "<<a.x<<" "<<a.y-1<<endl;
      exit(1);
    }
    route.push(map[a.x][a.y-1] );
    a.visited=true;
  }
  if(a.y + 1 < map.size() && map[a.x][a.y+1].sym!='#' && a.visited==false)  //right is fine
  {
    if(map[a.x][a.y+1].sym == 'E')
    {
      cout<<"found at "<<a.x<<" "<<a.y+1<<endl;
      exit(1);
    }
    route.push(map[a.x][a.y+1]);
    a.visited=true;
  }
  if(a.x -1 >0 && map[a.x-1][a.y].sym!='#' && a.visited==false)//up is fine
  {
    if(map[a.x-1][a.y].sym == 'E')
    {
      cout<<"found at "<<a.x-1<<" "<<a.y<<endl;
      exit(1);
    }
    route.push(map[a.x-1][a.y]);
    a.visited=true;
  }
  if(a.x + 1 <map.size() && map[a.x+1][a.y].sym!='#' && a.visited==false)  //down is fine
  {
    if(map[a.x +1][a.y].sym == 'E')
    {
      cout<<"found at "<<a.x+1<<" "<<a.y<<endl;
      exit(1);
    }
    route.push(map[a.x+1][a.y]);
    a.visited=true;
  }
}