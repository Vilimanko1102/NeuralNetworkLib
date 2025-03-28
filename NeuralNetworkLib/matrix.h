
typedef struct matrix_st {
	size_t row;
	size_t col;
	double** values;
}Matrix;

Matrix* createMatrix(size_t row, size_t col);
Matrix* scanMatrix();
void freeMatrix(Matrix* a);

Matrix* addMatrices(Matrix* a, Matrix* b);
Matrix* subtractMatrices(Matrix* a, Matrix* b);
Matrix* multiplyMatrices(Matrix* a, Matrix* b);

Matrix* transposeMatrix(Matrix* a);

Matrix* getMinor(Matrix* a, size_t row, size_t col);
double matrixDeterminant(Matrix* a);
Matrix* matrixCofactor(Matrix* mat, size_t row, size_t col);
Matrix* adjugateMatrix(Matrix* mat);
Matrix* inverseMatrix(Matrix* mat);

Matrix* solveSystemOfLinearEquations(Matrix* A, Matrix* b);

Matrix* scalarMultiplyMatrices(double scalar, Matrix* a);

void printMatrix(Matrix* a);
