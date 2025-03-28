
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

Matrix* scalarMultiplyMatrices(double scalar, Matrix* a);

void printMatrix(Matrix* a);
