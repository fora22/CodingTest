#include <iostream>

using namespace std;

int main(void) 
{
	ifstream readFile("input.txt");
	cout << solve(&readFile) << endl;
	return 0;
}
