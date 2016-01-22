#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

struct point
{
	double x_cord;
	double y_cord;
};

int main(int argc, char* argv[])
{

	vector<point> points;

	string line;
	double x,y;
	char junk;
	while(getline(cin,line))
	{
		stringstream ss(line);
		ss >> x >> junk >> y;
		point temp;
		temp.x_cord = x;
		temp.y_cord = y;
		points.push_back(temp);	//can be optimized if no of points given
	}
	/*
	for(auto x:points)
	{
		cout << x.x_cord <<" "<< x.y_cord <<endl;
	}
	*/

	//find point with lowest y coordinate
	double min_y = points[0].y_cord;
	int count = 0; 
	for(auto i = points.begin(); i != points.end(); i++)
	{
		if(i->y_cord < min_y)
		{
			iter_swap(points.begin(), points.begin()+count);	// not as efficient as finding min and replacing with points[0] but wanted to try iter_swap
		}
		count++;
	}

	//cout << points[0].x_cord <<" "<< points[0].y_cord << endl;
	//and then sort by polar angle aka sort by x coordinate 

	sort(points.begin()+1,points.end(),[](point a, point b){return a.x_cord > b.x_cord;});	//sort by polar angle

	for(auto x:points)
	{
		cout << x.x_cord <<" "<< x.y_cord <<endl;
	}

	points.push_back(points[0]);	//pushing back first point into again to compare

	//points[0] always part of convex hull (by definition)
	//find convex hull
	//iterate starting from points[2] and find all points by using determinant
	cout << "Convex Hull:\n";
	for( auto i = points.begin()+1; i != points.end(); i++)
	{
		double det_area = ((i->x_cord - (i-1)->x_cord) * ((i+1)->y_cord - (i-1)->y_cord)) - ((i->y_cord - (i-1)->y_cord) * ((i+1)->x_cord - (i-1)->x_cord)); //determinant area
		if(det_area >=0) //ccw or coolinear
		{
			cout << i->x_cord << "," <<i->y_cord << endl; 
		}
	}


	return 0;

}
