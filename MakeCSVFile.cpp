#include "MakeCSVFile.h"
#include <fstream>
#include <iterator>
#include <locale>

using namespace std;

string DeletePunctuationMarks(string word) {
	int size = word.length();
	while (!isalpha(word[size - 1])) {
		word.erase(size - 1, 1);
		--size;
	}
	return word;
}

void MakeCSVFile::FindWordsFromFile(string inputFile) {
	ifstream inFile(inputFile);
	if (!inFile.is_open()) {
		cout << "File isn't open" << endl;
	}
	while (!inFile.eof()) {
		string word;
		getline(inFile, word, ' ');
		word = DeletePunctuationMarks(word);
		++words_m[word];
		word.clear();
		++amountOfWords;
	}
	inFile.close();
}

void MakeCSVFile::MakeCSV(string outputFile) {
	ofstream outFile(outputFile);
	multimap <int, string, greater<int>> CSVFile;
	for (auto it = words_m.begin(); it != words_m.end(); ++it) {
		CSVFile.insert(pair<int, string>(it->second, it->first));
	}
	words_m.clear();
	if (!outFile.is_open()) {
		cout << "File isn't open" << endl;
	}
	for (auto it = CSVFile.begin(); it != CSVFile.end(); ++it) {
		outFile << it->second << ", " << it->first << ", " << (int)((double)it->first / (double)amountOfWords * 100) << "%\n" << endl;
	}
}
