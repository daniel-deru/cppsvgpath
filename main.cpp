#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;
string getPath(string svg);
int main() {
    string filename = "name.svg";
    string svg;
    string line;
    fstream file;

//    cout << "Enter the filename" << endl;
//    cin >> filename;

    file.open(filename, ios::in);

    if(file.is_open()){
        while(getline(file,line)){
             svg += line;
        }
    } else {
        cout << "file is not open";
    }
    file.close();

    string paths = getPath(svg);
    cout << paths << endl;
    return 0;
}

string getPath(string svg){
    regex reg("(d=)");

    smatch matches;
    string paths;

    while(regex_search(svg, matches, reg)){
//        cout << "inside the while loop" << endl;
//        paths += matches.str(1);
        cout << matches.str(1) << endl;
        svg = matches.suffix().str();
    }
    return paths;
}
