#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>
#include <bits/stdc++.h>

using namespace std;

bool isPossible(int mat[9][9],int row,int col,int n,int num){

	for(int i=0;i<n;i++){
		if(mat[row][i]==num or mat[i][col]==num){
			return false;
		}
	}

	int starting_x = (row/3)*3;
	int starting_y = (col/3)*3;

	for(int i = starting_x;i<starting_x+3;i++){
		for(int j=starting_y;j<starting_y+3;j++){
			if(mat[i][j]==num){
				return false;
			}
		}
	}

	return true;
}

bool sudokuSolver(int mat[9][9],int row,int col,int n){
	if(row==n){

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}

		return true;
	}

	if(col==n){
		return sudokuSolver(mat,row+1,0,n);
	}

	if(mat[row][col]!=0){
		return sudokuSolver(mat,row,col+1,n);
	}

	for(int num=1;num<=9;num++){
		if(isPossible(mat,row,col,n,num)){

			mat[row][col] = num;

			bool restOfTheSudoku = sudokuSolver(mat,row,col+1,n);

			if(restOfTheSudoku){
				return true;
			}
		}
	}

	mat[row][col] = 0;
	return false;
}
int main(){

	int mat[9][9] = {
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
    };

    int n = 9;
    cout<<sudokuSolver(mat,0,0,n)<<endl;

	return 0;
}