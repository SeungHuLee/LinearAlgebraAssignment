#include <iostream>
#include <array>

using namespace std;

int m = 0;
int n = 0;

void output();

int main() {
	
	int count = 0;

	cout << "How many rows and columns does the matrix have? (m * n) : "; // m�� n��
	cin >> m >> n;

	int **matrix = new int*[m];

	for (int i = 0; i < m; i++) {
		matrix[i] = new int[n];
		memset(matrix[i], 0, sizeof(int)*n);
	} // 2���� ���� �迭 �޸� �Ҵ�

	//output();
	int tempCount = 0; // for debugging

	for (int i = 0; i < m; i++) {                                            // mat[0][0] mat[0][1]
		for (int j = 0; j < n; j++) {                                        // mat[1][0] mat[1][1]
			matrix[i][j] = tempCount++;
			cout << matrix[i][j] << " "; // j�� ���̰�, i�� ���� ��Ÿ����. 

		}
		cout << endl;
	} // ���

	int sentry = 0;
	int option = 0;
	int *temp = new int[n];

	while (sentry != -1) {
		cout << "\nWhat operation do you want to perform with your matrix?" << endl;
		cout << "Choose your option : " << endl;
		cout << "(-1 - exit 1 - exchange row 2 - multiply coefficients 3 - addition of rows 4 - subtraction of rows) : ";

		cin >> option;

		switch (option)
		{
		case -1:
			sentry = -1;
			break;
		case 1:
			int chosenPlace;
			int chosenRowToExchange;
			
			

			cout << "You chose exchange." << endl;
			cout << "Choose row to exchange (0 ~ ): ";
			cin >> chosenRowToExchange;
			cout << "To where? : ";
			cin >> chosenPlace;

			for (int i = 0; i < n; i++) {
				temp[i] = matrix[chosenPlace][i]; // temp�� chosenPlace �� ��ҵ� ����
			}

			for (int i = 0; i < n; i++) {
				matrix[chosenPlace][i] = matrix[chosenRowToExchange][i]; // 
				matrix[chosenRowToExchange][i] = temp[i];
			}

			for (int i = 0; i < m; i++) {                                            // mat[0][0] mat[0][1]
				for (int j = 0; j < n; j++) {                                        // mat[1][0] mat[1][1]
					cout << matrix[i][j] << " "; // j�� ���̰�, i�� ���� ��Ÿ����. 
				}
				cout << endl;
			} // ���

			
			break;
		case 2: // (�� ����)
			cout << "2" << endl;
			break;
		case 3: // (�� ����)
			cout << "3" << endl;
			break;
		case 4: // (�� ����)
			cout << "4" << endl;
			break;
		default:
			break;
		}
	}

	for (int i = 0; i < m; i++) { // ����
		delete[] matrix[i]; 
	} 
	delete[] matrix;
	delete[] temp;
}

void output(int** arr) { // Reduced row echelon form ���ϱ� �� ��ȯ(�Ϸ�), �� ����, �� ���ϱ�, �� ����
	
	
}