#include <iostream>
#include <array>
using namespace std;
int main() {
	//cout << "Input your coefficient matrix : " << endl;
	array<array<int, 7>, 7> row;
	int count = 0;

	for (auto& column : row) {
		
		for (auto& element : column) {
			element = count++;
			
			cout << element << " ";
		}
		cout << endl;
	}
	cout << row[0][0] << row[0][1] << endl;
}