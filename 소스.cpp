#include <iostream>
#include <array>

using namespace std;

int m = 0;
int n = 0;

void output();

int main() {
	
	int count = 0;

	cout << "How many rows and columns does the matrix have? (m * n) : ";
	cin >> m >> n;

	int **matrix = new int*[n];

	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m];
		memset(matrix[i], 0, sizeof(int)*m);
	} // 2차원 동적 배열 메모리 할당

	//output();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	} // 출력

	int sentry = 0;
	int option = 0;

	while (sentry != -1) {
		cout << "What operation do you want to perform with your matrix?" << endl;
		cout << "Choose your option : " << endl;
		cout << "(-1 - exit 1 - exchange row 2 - multiply coefficients 3 - addition of rows 4 - subtraction of rows) : ";

		cin >> option;

		switch (option)
		{
		case -1:
			sentry = -1;
			break;
		case 1:
			cout << "1" << endl;
			break;
		case 2:
			cout << "2" << endl;
			break;
		case 3:
			cout << "3" << endl;
			break;
		case 4:
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

}

void output(int** arr) { // Reduced row echelon form 구하기 행 교환, 행 곱셈, 행 더하기, 행 빼기
	
	
}