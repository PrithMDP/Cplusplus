//
//  main.cpp
//  spiral-matrix-print
//
//  Created by Lionel Messi on 6/14/15.
//  Copyright (c) 2015 Lionel Messi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
/*
 spiral print matrix
 1   2   3   4
 5   6   7   8
 9   10  11  12
 13  14  15  16
 
 OUTPUT-> 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
 */
void printspiral(vector<vector<int>> nums,int height, int width);

//helper function to print vector
void printvector(vector<vector<int>> nums);

int main(int argc, const char * argv[])
{
    vector<vector<int>> nums (4);
    for (int i=0; i<4; i++) {
        nums[i].resize(4);
    }
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            nums[i][j]=4*i+1 + 1*j;
        }
    }
    printvector(nums);
    cout<<endl<<endl;
    printspiral(nums, 4, 4);
    cout<<endl;
    return 0;
}

void printspiral(vector<vector<int>> nums,int height, int width)
{
    //4 "pointers" and 4 directions dir 0= right, 1 = bottom ,2 = left, 3 = top
    int top,bottom,left,right;
    top=0;
    bottom=height-1;
    left=0;
    right=width-1;
    int dir=0;
    while (top<=bottom && left<=right)
    {
        
        if (dir==0) {
            for (int i=left; i<=right; i++) {
                cout<<nums[top][i]<<" , ";
            }
                dir=1;
                top++;
        
        }
        else if(dir==1)
        {
            for (int i=top; i<=bottom; i++) {
                cout<<nums[i][right]<<" , ";
            }
                dir=2;
                right--;
        
            
        }
        else if(dir==2)
        {
            for (int i=right; i>=left; i--) {
                cout<<nums[bottom][i]<<" , ";
                
            }   dir=3;
                bottom--;
        
            
        }
        else//dir = 3
        {
            for (int i=bottom; i>=top; i--) {
                cout<<nums[i][left]<<" , ";
            }
                dir=0;
                left++;
            
        }
        
    }
}

void printvector(vector<vector<int>> nums)
{
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
}