#include <iostream>
#include <unordered_map>
#include <fstream>
using namespace std;

#include "json.hpp"

int main(int argc, char** argv){
	(void) argc;
	(void) argv;

	//unordered_map<int, int[5]> myMap;
	// read a JSON file
	ifstream i(argv[1]);
	nlohmann::json j;
	i >> j;

	// for(int i = 0; i < jsonFile[0].size(); i++){
	// 	myMap[id] = jsonFile[0]["childrens_id"];
	// }
	unordered_map<int, vector<int>> myMap;
	for(unsigned long i = 0; i < j.size(); i++){
		vector <int> newVector;
		for(unsigned long k = 0; k < j[i]["childrens_id"].size(); k++){
			newVector.push_back(j[i]["childrens_id"][k]);
		}
		myMap[j[i]["id"]] = newVector;
		for(unsigned int l = 0; l < newVector.size(); l++){
			cout << newVector[l] << endl;
		}
		
	}
	return 0;
}