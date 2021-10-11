#include "../headers/script.h"
using namespace std;

Script::Script() {
    
}

Script::Script(string workName, string whoWrote, string whatGenre, string license) {
    workingName = workName;
    writer = whoWrote;
    genre = whatGenre;
    licenseIP = license;
}

string Script::getWorkName() {
    return workingName;
}

string Script::getWriter() {
    return writer;
}

string Script::getGenre() {
    return genre;
}

string Script::getLicense() {
    return licenseIP;
}

void Script::print() {
    cout << "The script's working name is: " << workingName << endl;
    cout << "The script's writer is: " << writer << endl;
    cout << "The script's genre is: " << genre << endl;
    cout << "The script's IP license is: " << licenseIP << endl;
}