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
	} // 동적할당

	//output();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	} // 출력

	for (int i = 0; i < m; i++) { 
		delete[] matrix[i]; 
	} 
	delete[] matrix;

}

void output(int** arr) { // Reduced row echelon form 구하기
	
	
}