#include "MakeCSVFile.h"
#include <fstream>
#include <iterator>
#include <locale>

using namespace std;

void MakeCSVFile::FindWordsFromFile(const string &inputFile) {
	ifstream inFile(inputFile);
	if (!inFile.is_open()) {
		throw std::invalid_argument("File isn't open");
	}
	while (!inFile.eof()) {
		string word, symbol;
		getline(inFile, symbol);
		for (int i = 0; i < symbol.length(); ++i) {
			if (isalnum(symbol[i]) && symbol[i] != '\0') {
				word += symbol[i];
			}
			else {
				if (word.length() > 0) {
					++words_m[word];
					word.clear();
					++amountOfWords;
				}
			}
		}
	}
	inFile.close();
}

void MakeCSVFile::MakeCSV(const string &outputFile) {
	ofstream outFile(outputFile);
	multimap <int, string, greater<int>> CSVFile;
	for (auto it = words_m.begin(); it != words_m.end(); ++it) {
		CSVFile.insert(pair<int, string>(it->second, it->first));
	}
	words_m.clear();
	if (!outFile.is_open()) {
		throw std::invalid_argument("File isn't open");
	}
	for (auto it = CSVFile.begin(); it != CSVFile.end(); ++it) {
		outFile << it->second << ", " << it->first << ", " << (int)((double)it->first / (double)amountOfWords * 100) << "%\n" << endl;
	}
}
