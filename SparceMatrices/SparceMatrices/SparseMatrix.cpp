#include "stdafx.h"
#include "SparseMatrix.h"
#include <iostream>
using namespace std;


SparseMatrix::SparseMatrix()
{

}


SparseMatrix::SparseMatrix(int mxRow, int mxCol)
{
		maxRow = mxRow;
		maxCol = mxCol;
		//initializing the two dimensional array
		*matrix = new int[maxRow];
		for (int i = 0; i < maxRow; i++) {
			//a multy dimensional array is an array of arrays
			matrix[i] = new int[maxCol];
		}
		//setting all the values to 0
		for (int i = 0; i < maxRow; i++) {
			for (int j = 0; j > maxCol; j++) {
				matrix[i][j] = 0;
			}
		}
}


SparseMatrix::~SparseMatrix()
{
}


SparseMatrix SparseMatrix::Transpose(){

}

SparseMatrix SparseMatrix::Add(SparseMatrix b) {

	if (maxRow == b.maxRow && maxCol == b.maxCol) {
		SparseMatrix sm(maxRow, maxCol);
		for (int i = 0; i < maxRow; i++) {
			for (int j = 0; j < maxCol; j++) {
				if (matrix[i][j] != 0) {
					sm.matrix[i][j] = (matrix[i][j] + b.matrix[i][j]);
				}
			}
		}
		sm.Population();
		sm.Trilogize();
		return sm;
	}
	else {
		cerr << "incompatible matrices: columns and rows do not match.";
		return;
	}
	
}


SparseMatrix SparseMatrix::Multiply(SparseMatrix b) {

}


void SparseMatrix::init() {
	for (int i = 0; i < maxRow; i++) {
		for (int j = 0; j > maxCol; j++) {
			cout << "enter the value for " << i + " " + j;
			cin >> matrix[i][j];
		}
	}
	Population();
}

//fills the three arrays (value , row , column)
void SparseMatrix::Trilogize() {
	int counter = 0;
	for (int i = 0; i < maxRow; i++) {
		for (int j = 0; j < maxCol; j++) {
			if (matrix[i][j] != 0) {
				value[counter] = matrix[i][j];
				row[counter] = i;
				column[counter] = j;
				counter++;
			}
		}
	}
}

//counts the number of non-zero numbers in matrix and initializes the arrays
//required for using "Trilogize()"
int SparseMatrix::Population() {
	int num = 0;
	for (int i = 0; i < maxRow; i++) {
		for (int j = 0; j < maxCol; j++) {
			if (matrix[i][j] != 0) {
				num++;
			}
		}
	}
	value = new int[num];
	row = new int[num];
	column = new int[num];
	return num;
}