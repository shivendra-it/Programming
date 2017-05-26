/*
https://github.com/xisisu/CodeEval/blob/master/Hard/RobotMovements.cc

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

#define PROB_SIZE	4

int helper(vector<vector<int> > table, int i, int j) {
	if ( i < 0 || j < 0 || i >= 4 || j >= 4 ) return 0;
	if ( table[i][j] == 1 ) return 0;
	if ( i == 3 && j == 3 ) return 1;

	table[i][j] = 1;
	return helper(table, i, j+1) + helper(table, i+1, j) + helper(table, i, j-1) + helper(table, i-1, j);
}

int main(int argc, char *argv[]) {
	vector<vector<int> > table;
	vector<int> x(PROB_SIZE,0);
	for (int i = 0; i < PROB_SIZE; ++i)
		table.push_back(x);

	cout << helper(table, 0, 0) << endl;

    return 0;
}