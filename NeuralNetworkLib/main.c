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
	Matrix* multiply = multiplyMatrices(a, b);
	Matrix* transposed = transposeMatrix(a);
	double determinant = matrixDeterminant(a);
	Matrix* inverse = inverseMatrix(a);

	printMatrix(add);
	printMatrix(subtract);
	printMatrix(scalarMultiply);
	printMatrix(multiply);
	printMatrix(transposed);
	printf("%lf\n\n", determinant);
	printMatrix(inverse);


	Matrix* A = createMatrix(3, 3);
	Matrix* c = createMatrix(3, 1);

	c->values[0][0] = 3;
	c->values[1][0] = 7;
	c->values[2][0] = 8;

	// Example: System of Equations
	A->values[0][0] = 2;  A->values[0][1] = 1;  A->values[0][2] = -1;
	A->values[1][0] = -3; A->values[1][1] = -1; A->values[1][2] = 2;
	A->values[2][0] = -2; A->values[2][1] = 1;  A->values[2][2] = 2;

	Matrix* sol = solveSystemOfLinearEquations(A, c);

	printMatrix(sol);

	free(sol);

	freeMatrix(a);
	freeMatrix(b);
	freeMatrix(add);
	freeMatrix(subtract);
	freeMatrix(scalarMultiply);
	freeMatrix(multiply);
	freeMatrix(transposed);
	free(inverse);

	freeMatrix(A);
	freeMatrix(c);



	return 0;
}
