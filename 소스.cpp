#include <iostream>
#include <array>

using namespace std;

int m = 0;
int n = 0;

void output();

int main() {
	
	int count = 0;

	cout << "How many rows and columns does the matrix have? (m * n) : "; // m행 n열
	cin >> m >> n;

	int **matrix = new int*[m];

	for (int i = 0; i < m; i++) {
		matrix[i] = new int[n];
		memset(matrix[i], 0, sizeof(int)*n);
	} // 2차원 동적 배열 메모리 할당

	//output();
	int tempCount = 0; // for debugging

	for (int i = 0; i < m; i++) {                                            // mat[0][0] mat[0][1]
		for (int j = 0; j < n; j++) {                                        // mat[1][0] mat[1][1]
			matrix[i][j] = tempCount++;
			cout << matrix[i][j] << " "; // j가 열이고, i가 행을 나타낸다. 

		}
		cout << endl;
	} // 출력

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
				temp[i] = matrix[chosenPlace][i]; // temp에 chosenPlace 행 요소들 복사
			}

			for (int i = 0; i < n; i++) {
				matrix[chosenPlace][i] = matrix[chosenRowToExchange][i]; // 
				matrix[chosenRowToExchange][i] = temp[i];
			}

			for (int i = 0; i < m; i++) {                                            // mat[0][0] mat[0][1]
				for (int j = 0; j < n; j++) {                                        // mat[1][0] mat[1][1]
					cout << matrix[i][j] << " "; // j가 열이고, i가 행을 나타낸다. 
				}
				cout << endl;
			} // 출력

			
			break;
		case 2: // (행 곱셈)
			cout << "2" << endl;
			break;
		case 3: // (행 덧셈)
			cout << "3" << endl;
			break;
		case 4: // (행 뺄셈)
			cout << "4" << endl;
			break;
		default:
			break;
		}
	}

	for (int i = 0; i < m; i++) { // 해제
		delete[] matrix[i]; 
	} 
	delete[] matrix;
	delete[] temp;
}

void output(int** arr) { // Reduced row echelon form 구하기 행 교환(완료), 행 곱셈, 행 더하기, 행 빼기
	
	
}