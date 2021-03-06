#include <iostream>

#include <fstream>

#include <algorithm>

#include <vector>

#include <set>
using namespace std;


set <int> closeto(vector<vector<int>> &graph, int vet);
void plantGrass(int vet, int grass, vector <int> &GrassTypes, vector <int> &Farm);
void insertkey(set<int> &nearfields, vector <int> &GrassTypes, vector <int> &Farm, int vet, int UsedGrass);
void testKeyNU(set<int> &nearfields, vector <int> &GrassTypes, vector <int> &Farm, bool &NotUsed, int &UsedGrass, int l);
void repeatKey(vector <int> &Farm, int vet, int l);

int main(void)
{
	int Size;
	ifstream fin("planting.in");
	fin >> Size;

	vector<vector <int>> Graph(Size+1); 
	vector <int> GrassTypes, Farm(Size+1); 

	for (int connections = 0; connections < Size-1; connections++) {
		int point1, point2;
		fin >> point1 >> point2;
		Graph[point1].push_back(point2);
		Graph[point2].push_back(point1);
	}

	plantGrass(1, 1, GrassTypes, Farm);

	for (int vet = 2; vet <= Size; vet++) {
		set <int> nearfields = closeto(Graph, vet);
		int UsedGrass = 0;
		insertkey(nearfields, GrassTypes, Farm, vet, UsedGrass);
	}
	
	ofstream fout("planting.out");
	fout << GrassTypes.size() << endl;

	return 0;
}


void plantGrass(int vet, int Grass, vector <int> &GrassTypes, vector <int> &Farm) {
	GrassTypes.push_back(Grass);
	Farm[vet] = Grass;
	return;
}

set <int> closeto(vector<vector<int>> &Graph, int vet)
{
	set <int> nearfields;
	for (auto adjacent : Graph[vet])
		nearfields.insert(adjacent);
	set <int> tnearfields = nearfields;
	for (auto adjacent : tnearfields) {
		for (auto adjacent2 : Graph[adjacent])
			nearfields.insert(adjacent2);
	}
	nearfields.erase(vet);
	return nearfields;
}

void testKeyNU(set<int> &nearfields, vector <int> &GrassTypes, vector <int> &Farm, bool &NotUsed, int &UsedGrass, int l) {
	for (auto j = nearfields.begin(); j != nearfields.end(); j++) {
		if (Farm[*j] == GrassTypes[l]) {
			NotUsed = 0;
			UsedGrass++;
			break;
		}
	}
	return;
}


void insertkey(set<int> &nearfields, vector <int> &GrassTypes, vector <int> &Farm, int vet, int UsedGrass) {
	for (int l = 0; l < GrassTypes.size(); l++) {
		bool NotUsed;
		NotUsed = 1;
		if (NotUsed) testKeyNU(nearfields, GrassTypes, Farm, NotUsed, UsedGrass, l);
		if (NotUsed) { Farm[vet] = GrassTypes[l];  break; }
	}
	if (UsedGrass == GrassTypes.size()) {
		plantGrass(vet, GrassTypes.size() + 1, GrassTypes, Farm);
	}
}