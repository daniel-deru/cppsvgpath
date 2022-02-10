#include <iostream>
#include <fstream>
#include <string>
#include <regex>


using namespace std;
string * getPath(string svg);
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

    string *paths = getPath(svg);

    ofstream outfile;

    outfile.open("test.txt", ios::out);
    if(outfile.is_open()){
        outfile << "[" << endl;
        for(int i = 0; i < 13; i++){
            outfile << "\"";
            outfile << paths[i];
            outfile << "\"";
            outfile << "," << endl;
        }
        outfile << "]" << endl;
        outfile.close();
    }
    cout << sizeof(&paths);
    return 0;
}

string* getPath(string svg){
    regex reg("d=\"(.*?)\"");

    smatch matches;
    static string paths[20];

//    static string test[3] {"hello", "what", "why"};
    int counter = 0;
    while(regex_search(svg, matches, reg)){

        paths[counter] = matches.str(1);
        svg = matches.suffix().str();
        counter ++;
    }
    return paths;
}
