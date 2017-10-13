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
		matrix = new int*[maxRow];
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
	//for (int i = 0; i < maxRow; i++) {
	//		delete[] matrix[i];
	//}
	//delete[] matrix;
	//matrix = NULL;
}


SparseMatrix SparseMatrix::Transpose() {
	SparseMatrix sm(maxRow, maxCol);
	for (int i = 0; i < maxRow; i++) {
		for (int j = 0; j < maxCol; j++) {
			sm.matrix[i][j] = matrix[j][i];
		}
	}
	sm.Population();
	sm.Trilogize();
	return sm;
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
		exit(0);
	}
	
}


SparseMatrix SparseMatrix::Multiply(SparseMatrix b) {
	if (maxCol != b.maxRow) {
		cerr << "Unmultipliable Matrices";
		exit(0);
	}
	else {
		SparseMatrix result(maxRow, b.maxCol);
		for (int i = 0; i < maxRow; ++i)
			for (int j = 0; j < b.maxCol; ++j)
				for (int k = 0; k < maxCol; ++k)
				{
					result.matrix[i][j] += matrix[i][k] * b.matrix[k][j];
				}
		return result;
	}
}


void SparseMatrix::init() {
	for (int i = 0; i < maxRow; i++) {
		for (int j = 0; j < maxCol; j++) {
			cout << "\n enter the value for " << i << " " << j << " :  ";
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
	num = 0;
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

//prints matrix
void SparseMatrix::PrintMatrix() {
	for (int i = 0; i < maxRow; i++) {
		for (int j = 0; j < maxCol; j++) {
			cout << matrix[i][j] << "   ";
		}
		cout << "\n";
	}
}

//prints Arrays value , row and column
void SparseMatrix::PrintTrilogy() {
	cout << "\n Values: [";
	for (int i = 0; i < num; i++) {
		if (i == (num - 1)) {
			cout << value[i] << "]";
		}
		else {
			cout << value[i] << " ,";
		}
	}
	cout << "\n Rows: [";
	for (int i = 0; i < num; i++) {
		if (i == (num - 1)) {
			cout << row[i] << "]";
		}
		else {
			cout << row[i] << " ,";
		}
	}
	cout << "\n Columns: [";
	for (int i = 0; i < num; i++) {
		if (i == (num - 1)) {
			cout << column[i] << "]";
		}
		else {
			cout << column[i] << " ,";
		}
	}
}