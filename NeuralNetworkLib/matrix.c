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

	if (a->row != b->row || a->col != b->col) return NULL;

	Matrix* setToReturn = createMatrix(a->row, a->col);

	for (int i = 0;i < a->row;i++) {
		for (int j = 0;j < a->col;j++) {
			setToReturn->values[i][j] = a->values[i][j] + b->values[i][j];
		}
	}

	return setToReturn;
}

Matrix* subtractMatrices(Matrix* a, Matrix* b) {

	if (a->row != b->row || a->col != b->col) return NULL;

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

Matrix* multiplyMatrices(Matrix* a, Matrix* b) {
	if (!a || !b || a->col != b->row) return NULL; 

	Matrix* result = createMatrix(a->row, b->col);
	if (!result) return NULL; 

	for (size_t i = 0; i < a->row; i++) {
		for (size_t j = 0; j < b->col; j++) {
			result->values[i][j] = 0.0; 
			for (size_t k = 0; k < a->col; k++) {
				result->values[i][j] += a->values[i][k] * b->values[k][j];
			}
		}
	}

	return result;
}

Matrix* transposeMatrix(Matrix* a) {
	if (!a) return NULL; 

	Matrix* transposed = createMatrix(a->col, a->row); 
	if (!transposed) return NULL; 

	for (size_t i = 0; i < a->row; i++) {
		for (size_t j = 0; j < a->col; j++) {
			transposed->values[j][i] = a->values[i][j]; 
		}
	}

	return transposed;
}

Matrix* getMinor(Matrix* a, size_t row, size_t col) {
	Matrix* minor = createMatrix(a->row - 1, a->col - 1);
	if (!minor) return NULL;

	for (size_t i = 0, minor_i = 0; i < a->row; i++) {
		if (i == row) continue; 

		for (size_t j = 0, minor_j = 0; j < a->col; j++) {
			if (j == col) continue; 

			minor->values[minor_i][minor_j] = a->values[i][j];
			minor_j++;
		}
		minor_i++;
	}

	return minor;
}

double matrixDeterminant(Matrix* a) {
	if (!a || a->row != a->col) return 0.0; 

	size_t n = a->row;

	if (n == 1) return a->values[0][0];

	if (n == 2) {
		return (a->values[0][0] * a->values[1][1]) -
			(a->values[0][1] * a->values[1][0]);
	}

	double det = 0.0;
	for (size_t j = 0; j < n; j++) {
		Matrix* minor = getMinor(a, 0, j);
		if (!minor) return 0.0;

		double cofactor = ((j % 2 == 0) ? 1 : -1) * a->values[0][j] * matrixDeterminant(minor);
		det += cofactor;

		freeMatrix(minor);
	}

	return det;
}

Matrix* matrixCofactor(Matrix* mat, size_t row, size_t col) {
	return getMinor(mat, row, col); 
}

Matrix* adjugateMatrix(Matrix* mat) {
	if (!mat || mat->row != mat->col) return NULL;

	size_t n = mat->row;
	Matrix* adj = createMatrix(n, n);
	if (!adj) return NULL;

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			Matrix* cofactorMat = matrixCofactor(mat, i, j);
			if (!cofactorMat) {
				freeMatrix(adj);
				return NULL;
			}

			double cofactor = ((i + j) % 2 == 0 ? 1 : -1) * matrixDeterminant(cofactorMat);
			adj->values[j][i] = cofactor; 

			freeMatrix(cofactorMat);
		}
	}

	return adj;
}

Matrix* inverseMatrix(Matrix* mat) {
	if (!mat || mat->row != mat->col) return NULL; 

	double det = matrixDeterminant(mat);
	if (det == 0.0) return NULL; 

	Matrix* adj = adjugateMatrix(mat);
	if (!adj) return NULL;

	Matrix* inverse = scalarMultiplyMatrices(1.0 / det, adj);
	freeMatrix(adj);

	return inverse;
}

Matrix* solveSystemOfLinearEquations(Matrix* A, Matrix* b) {

	Matrix* inv_A = inverseMatrix(A);
	printMatrix(inv_A);
	Matrix* x = multiplyMatrices(inv_A, b);

	freeMatrix(inv_A);

	return x;
}



