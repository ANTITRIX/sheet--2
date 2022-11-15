#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class LabelGenerator{
protected:
    string label;
    int count;
public:
    LabelGenerator(string l, int c);
    LabelGenerator(){}
    string nextLabel() ;
};
LabelGenerator::LabelGenerator(string l, int c){
    label = l;
    count = c;
}
string LabelGenerator::nextLabel(){
    string NL = label + to_string(count);
    count++;
    return NL;
}

class FileLabelGenerator:public LabelGenerator{
private:
    string FileName;
public:
    FileLabelGenerator(string l, int c, string name);
    string  nextLabel();
};
FileLabelGenerator::FileLabelGenerator(string l, int c, string name) {
    label= l;
    count=c;
    FileName=name;
}
string FileLabelGenerator::nextLabel(){
    ifstream mainFile;
    string line;
    mainFile.open(FileName);
    getline(mainFile, line);
    line = label + to_string(count)+ ' '+ line;
    count++;
    return line;

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

//_____________________________________________________
    FileLabelGenerator figureLabels ("Figure ", 1, "labels.txt");
    cout << "Figure labels: \n";
    for (int i = 0; i < 3; i++) {
        cout << figureLabels.nextLabel() << endl;
    }
    return 0;
}
