#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int m = 0;
int n = 0;

void printMatrix(float** matrix);
void RowReduce(float** matrix);

int main()
{
	cout << "How many rows and columns does the matrix have? (m * n) : "; // m행 n열
	cin >> m >> n;

	float **matrix = new float*[m];
	float *temp = new float[n];

	for (int i = 0; i < m; i++) {
		matrix[i] = new float[n];
		memset(matrix[i], 0, sizeof(float)*n);
	} // 2차원 동적 배열 메모리 할당

	for (int i = 0; i < m; i++) {
		cout << i << "번째 행의 요소들을 입력하세요 : ";
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
		
		cout << endl;
	}


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	//output();
	/*int tempCount = 0; // for debugging

	for (int i = 0; i < m; i++) {                                            // mat[0][0] mat[0][1]
		for (int j = 0; j < n; j++) {                                        // mat[1][0] mat[1][1]
			matrix[i][j] = tempCount++;
			cout << matrix[i][j] << " "; // j가 열이고, i가 행을 나타낸다. 

		}
		cout << endl;
	} // 출력*/

	
	
	/*float A[3][4] = { {5, -6, -7,   7},
					 {3, -2,  5, -17},
					 {2,  4, -3,  29} }; //answer should be {2, 4, -3}  주어진 행렬이다.*/



	printMatrix(matrix);
	RowReduce(matrix);

	for (int i = 0; i < m; i++) { // 해제
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] temp;
}

void printMatrix(float** matrix) // Outputs the matrix
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(7) << setprecision(4) << matrix[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
}

void RowReduce(float** matrix)
{
	//const int nrows = 3; // number of rows
	//const int ncols = 4; // number of columns

	int lead = 0;

	while (lead < m) {
		float divisor, multiplier;

		for (int r = 0; r < m; r++) { // for each row ...
			/* calculate divisor and multiplier */
			divisor = matrix[lead][lead];
			multiplier = matrix[r][lead] / matrix[lead][lead];

			for (int c = 0; c < n; c++) { // for each column ...
				if (r == lead)
					matrix[r][c] /= divisor;               // make pivot = 1
				else
					matrix[r][c] -= matrix[lead][c] * multiplier;  // make other = 0
			}
		}

		lead++;
		printMatrix(matrix);
	}
}