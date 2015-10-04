//
//  main.cpp
//  Searching-Sorted-Matrix
//
//  Created by Lionel Messi on 7/4/15.
//  Copyright (c) 2015 Lionel Messi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
/*
 Search in a sorted matrix
 
 1   2   3
 4   5   6
 7   8   9
 */
void printmatrix(vector<vector<int>> matrix);
//function to find;
void matrixsearch(vector<vector<int>> matrix, int find);
int main(int argc, const char * argv[])
{
    vector<vector<int>> matrix(3);
    //resizing
    for (int i=0; i<3; i++)
    {
        matrix[i].resize(3);
    }
    
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            matrix[i][j]=3*i+1+j;
        }
    }
    printmatrix(matrix);
    matrixsearch(matrix, 1);
    return 0;
}

void printmatrix(vector<vector<int>> matrix)
{
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
// function to find
void matrixsearch(vector<vector<int>> matrix, int find)
{
    int i=0;
    int j=int(matrix.size())-1;
    
    while (i<matrix.size() &&  j>=0)
    {
        if (matrix[i][j]==find)
        {
            cout<<"found, the number is at row "<<i+1<<" and column "<<j+1<<endl;
            
            break;
        }
        else if(matrix[i][j]>find)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    cout<<"not found!"<<endl;
}