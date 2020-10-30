#include "MakeCSVFile.h"

int main(int arg, char* argument[]) {
    MakeCSVFile CSV;
    if (arg > 2) {
        for (int i = 1; i < arg - 1; ++i) {
            CSV.FindWordsFromFile(argument[i]);
        }
        CSV.MakeCSV(argument[arg - 1]);
    }
    else {
        std::cout << "End" << endl;
    }
}
