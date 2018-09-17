#include <iostream>
#include <array>
using namespace std;
array<array<int, 7>, 7> row;

void input() {
	array<int, 7> temp;
	cout << "Input your coefficient matrix : " << endl;
	cin >> temp[0] >> temp[1] >> temp[2] >> temp[3] >> temp[4] >> temp[5] >> temp[6];

	// 일단 첫째 row부터 입력받은 값으로 채워넣어 보자. 7x7 행렬이다.
	for (int i = 0; i < 1; i++) {
		row[i] = temp;
	}

}

int main() {
	input();
	int count = 0;

	for (auto& column : row) {
		
		for (auto& element : column) {
			
			
			cout << element << " ";
		}
		cout << endl;
	}
	//cout << row[0][0] << row[0][1] << endl;
}