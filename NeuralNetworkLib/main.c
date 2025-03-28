// NeuralNetworkLib.cpp : Defines the entry point for the application.
//

#include "NeuralNetworkLib.h"


int main()
{
	Matrix* a = createMatrix(2, 2);
	Matrix* b = createMatrix(2, 2);
	double scalar = 7;

	a->values[0][0] = 1;
	a->values[0][1] = 2;
	a->values[1][0] = 3;
	a->values[1][1] = 4;

	b->values[0][0] = 5;
	b->values[0][1] = 6;
	b->values[1][0] = 7;
	b->values[1][1] = 8;

	Matrix* add = addMatrices(a, b);
	Matrix* subtract = subtractMatrices(a, b);
	Matrix* scalarMultiply = scalarMultiplyMatrices(scalar, a);

	printMatrix(add);
	printMatrix(subtract);
	printMatrix(scalarMultiply);

	freeMatrix(a);
	freeMatrix(b);
	freeMatrix(add);
	freeMatrix(subtract);
	freeMatrix(scalarMultiply);

	return 0;
}
