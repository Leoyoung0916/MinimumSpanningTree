#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	ofstream out("input.txt");
	int n;
	cin >> n;
	out << n << '\n';
	for(int i = 0; i < n; i++) {
		int x = rand() % 400;//400
		int y = rand() % 400;
		out << x << ' ' << y << '\n';
	}
	return 0;
}