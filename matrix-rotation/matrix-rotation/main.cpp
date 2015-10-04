//
//  main.cpp
//  matrix-rotation
//
//  Created by Lionel Messi on 7/2/15.
//  Copyright (c) 2015 Lionel Messi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void transpose(vector<vector<int>>&matrix);
int main(int argc, const char * argv[])
{
    vector<vector<int>> matrix(3);
    for (int i=0; i<3; i++) {
        matrix[i].resize(3);
    }
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            matrix[i][j]=rand()%100;
        }
    }
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    transpose(matrix);
    
    cout<<"Transpose is \n";
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}

void transpose(vector<vector<int>>&matrix)
{
    for (int i=1; i<3; i++) {
        for (int j=0; j<i; j++)
        {
            int temp;
            //cout<<matrix[i][j]<<endl;
            temp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }
}