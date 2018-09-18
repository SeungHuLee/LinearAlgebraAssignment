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
	cout << "How many rows and columns does the matrix have? (m * n) : "; // m�� n��
	cin >> m >> n;

	float **matrix = new float*[m];
	float *temp = new float[n];

	for (int i = 0; i < m; i++) {
		matrix[i] = new float[n];
		memset(matrix[i], 0, sizeof(float)*n);
	} // 2���� ���� �迭 �޸� �Ҵ�

	for (int i = 0; i < m; i++) {
		cout << i << "��° ���� ��ҵ��� �Է��ϼ��� : ";
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
			cout << matrix[i][j] << " "; // j�� ���̰�, i�� ���� ��Ÿ����. 

		}
		cout << endl;
	} // ���*/

	
	
	/*float A[3][4] = { {5, -6, -7,   7},
					 {3, -2,  5, -17},
					 {2,  4, -3,  29} }; //answer should be {2, 4, -3}  �־��� ����̴�.*/



	printMatrix(matrix);
	RowReduce(matrix);

	for (int i = 0; i < m; i++) { // ����
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