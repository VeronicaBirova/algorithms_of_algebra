#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	char* filename = argv[1];
    setlocale(LC_ALL, "Russian");
	ifstream fin(filename);
	ofstream data;
	data.open("data.dzn");
	long N, W, vt, wt, i, j;
	fin >> N >> W;
	data << "N = " << N << ';' << endl;
	data << "W = " << W << ';' << endl;
	vector <long> values(N);
	vector <long> weights(N);
	for (i = 0; i < N; i++) {
		fin >> vt >> wt;
		values[i] = vt;
		weights[i] = wt;
	}
	data << "values = [";
	for (i = 0; i < N; i++) {
		data << values[i] << ", ";
	}
	data << "];";
	data << endl;
	data << "weights = [";
	for (i = 0; i < N; i++) {
		data << weights[i] << ", ";
	}
	data<<"];";
	data<<endl;
	data.close();
	fin.close();
	system("minizinc --solver Gecode knapsack.mzn data.dzn");
	return 0;
}
