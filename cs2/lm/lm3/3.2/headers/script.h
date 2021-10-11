#include <iostream>
#include <string>
using namespace std;

#ifndef SCRIPT_H
#define SCRIPT_H

class Script {
    private:
        string workingName;
        string writer;
        string genre;
        string licenseIP;
    public:
        //empty class constructor
        Script();
        
        //class constructor for script
        //creates a script with a workingname, who wrote the script, what genre the script it, and the IP license of the script
        Script(string workName, string whoWrote, string whatGenre, string license);

        //function getWorkName, gets the working name of the script
        //no inputs
        //prints the working name of the script to the screen
        string getWorkName();

        //function getWriter, gets the name of the writer of the script
        //no inputs
        //prints the name of the writer to the screen
        string getWriter();

        //function getGenre, gets the genre of the script
        //no inputs
        //prints the genre of the script to the screen
        string getGenre();

        //function getLicense, gets the name of the IP license (the universe of the script)
        //no inputs
        //prints the name of the IP License holder to the screen
        string getLicense();

        //function print, prints all the information about the script to the screen
        //no inputs
        //prints all the information about the script to the screen
        void print();
};

#endif