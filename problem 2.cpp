#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class LabelGenerator {
protected:
    string label;
    int count = 0;
public:
    LabelGenerator(string l, int c);
    LabelGenerator() {}
    string nextLabel();
};
LabelGenerator::LabelGenerator(string l, int c) {
    label = l;
    count = c;
}
string LabelGenerator::nextLabel() {
    string temp = label + to_string(count);
    count++;
    return temp;
}

class FileLabelGenerator :public LabelGenerator {
protected:
    string FileName;
    int j = 0;
public:
    FileLabelGenerator(string l, int c, string name);
    string  nextLabel();
};
FileLabelGenerator::FileLabelGenerator(string l, int c, string name) {
    label = l;
    count = c;
    FileName = name;
}
string FileLabelGenerator::nextLabel() {
    ifstream myfile;
    string l;
    vector<string> lines;
    myfile.open(FileName);
    while (myfile) {
        string temp;
        getline(myfile, temp);
        lines.push_back(temp);
    }
    myfile.close();
    l = label + ' ' + to_string(count) + ' ' + lines[j];
    j++;
    count++;

    return l;

}

int main() {
    //    LabelGenerator figureNumbers("Figure ", 1);
//    LabelGenerator pointNumbers("P", 0);
//    cout << "Figure numbers: ";
//    for (int i = 0; i < 3; i++) {
//        cout << figureNumbers.nextLabel() << ", ";
//    }
//    cout << endl << "Point numbers: ";
//    for (int i = 0; i < 5; i++) {
//        cout << pointNumbers.nextLabel() << ", ";
//    }
//    cout << endl << "More figures: ";
//    for (int i = 0; i < 3; i++) {
//        cout << figureNumbers.nextLabel() << ", ";
//    }
//    cout << endl;

    FileLabelGenerator figureLabels("Figure ", 1, "test1.txt");
    cout << "Figure labels: \n";
    for (int i = 0; i < 3; i++) {
        cout << figureLabels.nextLabel() << endl;


    }

}
