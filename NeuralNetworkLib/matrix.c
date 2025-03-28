#include "NeuralNetworkLib.h"

Matrix* createMatrix(size_t row, size_t col) {

	Matrix* setToReturn = (Matrix*)malloc(sizeof(Matrix));

	setToReturn->row = row;
	setToReturn->col = col;

	setToReturn->values = (double**)malloc(row * sizeof(double*));

	for (int i = 0;i < row;i++)
	{
		setToReturn->values[i] = (double*)malloc(col * sizeof(double));
	}

	return setToReturn;

}

void printMatrix(Matrix* m) {

	for (int i = 0;i < m->row;i++) {
		for (int j = 0;j < m->col;j++) {
			printf("%lf ", m->values[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}

void freeMatrix(Matrix* matrix) {
	if (!matrix) return; 

	for (size_t i = 0; i < matrix->row; i++) {
		free(matrix->values[i]);
	}

	free(matrix->values);
	
	free(matrix);
}


Matrix* addMatrices(Matrix* a, Matrix* b) {

	if (a->row != b->row || a->col != b->row) return NULL;

	Matrix* setToReturn = createMatrix(a->row, a->col);

	for (int i = 0;i < a->row;i++) {
		for (int j = 0;j < a->col;j++) {
			setToReturn->values[i][j] = a->values[i][j] + b->values[i][j];
		}
	}

	return setToReturn;
}

Matrix* subtractMatrices(Matrix* a, Matrix* b) {

	if (a->row != b->row || a->col != b->row) return NULL;

	Matrix* setToReturn = createMatrix(a->row, a->col);

	for (int i = 0;i < a->row;i++) {
		for (int j = 0;j < a->col;j++) {
			setToReturn->values[i][j] = a->values[i][j] - b->values[i][j];
		}
	}

	return setToReturn;
}

Matrix* scalarMultiplyMatrices(double scalar, Matrix* a) {

	Matrix* setToReturn = createMatrix(a->row, a->col);

	for (int i = 0;i < a->row;i++) {
		for (int j = 0;j < a->col;j++) {
			setToReturn->values[i][j] = scalar * a->values[i][j];
		}
	}

	return setToReturn;
}
