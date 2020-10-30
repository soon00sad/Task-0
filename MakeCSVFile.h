#include <iostream>
#include <string>
#include <map>

using namespace std;

class MakeCSVFile {
	map <string, int> words_m;
	int amountOfWords = 0;
public:
	void FindWordsFromFile(string inFile);
	void MakeCSV(string outFile);
};
