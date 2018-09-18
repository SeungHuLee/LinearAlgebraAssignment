#include <iostream>

using namespace std;

int m = 0;
int n = 0;

void PrintMatrix(float** matrix);
void RowReduce(float** matrix);

int main()
{
	cout << "��� ���� �����ϼ��� (m * n) : "; // m�� n��
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
	
	PrintMatrix(matrix);
	RowReduce(matrix);

	for (int i = 0; i < m; i++) { // ����
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] temp;
}

void PrintMatrix(float** matrix) // ��� ����Ʈ
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
}

void RowReduce(float** matrix)
{
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
		} // while end

		lead++;
		PrintMatrix(matrix);
	}
}