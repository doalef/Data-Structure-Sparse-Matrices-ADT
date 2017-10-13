// SparceMatrices.cpp : Defines the entry point for the console application.
//Amirali Ahmadi

#include "stdafx.h"
#include <iostream>
#include "SparseMatrix.h"
using namespace std;


int main()
{
	SparseMatrix sm(3, 3);
	sm.init();
	sm.PrintMatrix();
	sm.Trilogize();
	sm.PrintTrilogy();
	sm.Transpose();
	system("pause");
    return 0;
}

