#pragma once
class SparseMatrix
{

public:
	SparseMatrix();
	SparseMatrix(int mxRow,int mxCol);
	~SparseMatrix();

	SparseMatrix Transpose();
	SparseMatrix Add(SparseMatrix b);
	SparseMatrix Multiply(SparseMatrix b);
	void Trilogize();
	void PrintMatrix();
	void PrintTrilogy();

	void init();
	int num;
	int maxRow;
	int maxCol;
	int *value;
	int *column;
	int *row;
	int **matrix;
private:
	int Population();
};

