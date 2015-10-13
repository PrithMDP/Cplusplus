
/*WARNING:

 The code for this project has been emailed to Prof. Drew Deorio and EECS 280 Staff (at the University of Michigan). Do not attempt to use this code for your project. Doing so will result in an honor code violation
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <time.h>
//#define DEBUG
//#define SPEC    //for the spec comparison
using namespace std;

//FUNCTION DECLARATIONS
void printmap(vector<vector<char> > & map);	//to print the map

bool satisfied(vector<vector<char> > & map, int i, int j, double satisfaction_ratio);	//to check if map element is satisfied

bool find_first(vector<vector<char> > & map, double satisfaction_ratio, char agent,pair<int, int> start_pos);	//find first position that satisfies unsatisfied agent


//INT MAIN HERE
int main(int argc, char** argv)
{
	
	ifstream file_name(argv[1]);

	int size;
	double satisfaction_ratio;
	double x_percent;
	double y_percent; 

	//assigning istream to whatever input method is present
	istream &in = (argc ==2)?file_name:cin;
	
	string junk,junk1,junk2,junk3;
	in>>junk;
	in>>size;
	in>>junk1;
	in>>satisfaction_ratio;
	in>>junk2;
	in>>x_percent;
	in>>junk3;
	in>>y_percent;	//works
	

	//cout<<size<<" "<<satisfaction_ratio<<" "<<x_percent<<" "<<y_percent<<endl;
	//exit(1);

	vector<vector<char> > map;
	map.resize(size);
	for(int i=0;i<map.size();i++)
	{
		map[i].resize(size);
	}	//resizing the map

	for(int i=0;i<map.size();i++)	//initializing map here 
	{
		for(int j=0;j<map.size();j++)
		{
			//srand(time(NULL)%10);
			int r=rand()%10;
			if(r<=int(x_percent*6))
			{
				map[i][j]='X';
			}
			else if(r > int(x_percent*10) && r<= int(x_percent*10 + y_percent*10))
			{
				map[i][j]='O';
			}
			else
			{
				map[i][j]=' ';
			}
		}
	}

	#ifdef Spec//for spec comparisons 

		cout<<"Spec comparison is going on\n";
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
			{
				map[i][j]=' ';
			}
		map[2][0]='X';
		map[2][1]='O';
		map[2][2]='X';
		map[2][3]='X';
		map[2][4]='O';
		map[4][0]='X';
		map[4][1]='O';
		map[0][1]='X';
		map[0][4]='X';
		map[1][2]='X';
		map[1][3]='O';
		map[1][4]='X';
		
	#endif	
		//end spec debug

	printmap(map);
	

	bool all_satisfied=false;

	//iterate through map if find an unsatisfied element then move and start looking from the begining of map	
		for(int i=0;i<map.size();i++)
		{
			for(int j=0;j<map.size();j++)
			{
				char agent;
				bool found;
				if(map[i][j] != ' ' && !satisfied(map,i,j,satisfaction_ratio))	//if not satisfied put where satisfied
					{
						//cout<<i<<" "<<j<<endl;
						pair<int, int> start_pos(i,j);
						//find first empty place where they will be satisfied and put them there and then restart from starting of loop (old position is now ' ')
						agent = map[i][j];
						map[i][j]=' ';	//make spot empty and make function call
						found =find_first(map, satisfaction_ratio, agent,start_pos);
						j=0;
						i=0;
					}
			}
		}
	//exits loop when all are satisfied
		for(int i=0;i<map.size();i++)
		{
			for(int j=0;j<map.size();j++)
			{
				if(map[i][j]!=' '&&!satisfied(map,i,j,satisfaction_ratio))
				{
					cout<<"Not satisfied at "<<i<<" "<<j<<endl;
					all_satisfied = false;
				}
			}
		}

	if(!all_satisfied)
	{
		char agent=map[0][0];
		map[0][0]=' ';
		pair<int, int> start_pos(0,0);
		find_first(map, satisfaction_ratio, agent,start_pos);
	}


#ifdef DEBUG	//DEBUG OUTPUT

	cout<<"DEBUG IS ON\n";

	for(int i=0;i<map.size();i++)
		{
			for(int j=0;j<map.size();j++)
			{
				if(map[i][j]!=' '&&!satisfied(map,i,j,satisfaction_ratio))
				{
					cout<<"Not satisfied still at "<<i<<" "<<j<<endl;
					all_satisfied = false;
				}
			}
		}
#endif

	cout<<"\nAll agents are satisfied\n\n";
	printmap(map);
	cout<<endl;
	return 0;

}


///////////// FUNCTION DEFINITIONS HERE ////////////////////////////////////////////////////////////////////////////////////////////////

bool satisfied(vector<vector<char> > & map, int i, int j, double satisfaction_ratio)	//check up, down, left, right, and diagonals 
{
	double same_neighbors=1;	//counting itself of the potential 8 //
	double total_neighbors=1;
	//check down
	if(i+1 <map.size() && map[i+1][j]!=' ')
	{
		++total_neighbors;	//increase total neighbors
		if(map[i][j]==map[i+1][j])	//same 
		{
			++same_neighbors;	//similar neighbors increased
		}
	}
	//check up
	if(i-1 >=0 &&map[i-1][j]!=' ')
	{
		++total_neighbors;
		if(map[i-1][j]==map[i][j])
		{
			++same_neighbors;
		}
	}
	//check left
	if(j-1 >=0 && map[i][j-1]!=' ')
	{
		++total_neighbors;
		if(map[i][j-1]==map[i][j])
		{
			++same_neighbors;
		}
	}
	//check right
	if(j+1 <map.size() && map[i][j+1]!=' ')
	{
		++total_neighbors;
		if(map[i][j+1]==map[i][j])
		{
			++same_neighbors;
		}
	}
	//left up diagonal
	if(i-1>=0 && j-1>=0 && map[i-1][j-1]!=' ')
	{
		++total_neighbors;
		if(map[i-1][j-1]==map[i][j])
		{
			++same_neighbors;
		}
	}
	//left down diagonal
	if(i+1<map.size() && j-1>=0 && map[i+1][j-1]!=' ')
	{
		++total_neighbors;
		if(map[i+1][j-1] == map[i][j])
		{
			++same_neighbors;
		}
	}
	//right up
	if(i-1>=0 && j+1<map.size() && map[i-1][j+1]!=' ')
	{
		++total_neighbors;
		if(map[i-1][j+1]==map[i][j])
		{
			++same_neighbors;
		}
	}
	//right down diagonal
	if(i+1 <map.size() && j+1 < map.size() && map[i+1][j+1]!=' ')
	{
		++total_neighbors;
		if(map[i+1][j+1]==map[i][j])
		{
			++same_neighbors;
		}
	}
	double ratio = same_neighbors/total_neighbors;

	return (same_neighbors/total_neighbors >= satisfaction_ratio);

}

bool find_first(vector<vector<char> > & map, double satisfaction_ratio, char agent, pair<int, int> start_pos)
{
	for(int i=0;i<map.size();i++)
	{
		for(int j=0;j<map.size();j++)
		{
			pair<int,int> current_pos(i,j);
			if(current_pos!=start_pos && map[i][j]==' ' )	//empty spot, check if it will satisfy make sure pair isnt the same 
			{
				//cout<<get<0>(current_pos)<<" "<<get<1>(current_pos)<<endl;
				map[i][j]=agent;
				if(satisfied(map,i,j,satisfaction_ratio))
				{
					return true;
				}
				else
				{
					map[i][j]=' ';
				}	//if not satisfied then return to original state
			}
		}
	}
	return false;
}

void printmap(vector<vector<char> > & map)
{
	for(int i=0;i<map.size();i++)
	{
		for(int j=0;j<map.size();j++)
		{
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
}
