#pragma once
class SparseMatrix
{
	friend int Population(SparseMatrix sm);
public:
	SparseMatrix();
	SparseMatrix(int mxRow,int mxCol);
	~SparseMatrix();

	SparseMatrix Transpose();
	SparseMatrix Add(SparseMatrix b);
	SparseMatrix Multiply(SparseMatrix b);
	void Trilogize();

	void init();

	int maxRow;
	int maxCol;
	int *value;
	int *column;
	int *row;
	int **matrix;
};

