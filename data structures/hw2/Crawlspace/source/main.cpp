//This is the cpp file that compiles and runs all the headers and cpp files
//Aaron Borjas
//CS273-1
//10/11/2019
//This file compiles everything for this project and executes it as one "game"
#include <iostream>
#include <string>
#include "../headers/Crawlspace.h"
#include "../headers/Exit.h"
#include "../headers/Explorer.h"
#include "../headers/Location.h"
#include "../headers/Object.h"
#include "../headers/Treasure.h"

void playRound(Crawlspace& c, Explorer& e) {
    e.getLoc().describe();

    bool endBool = false;
    while(!endBool) {
        string move;
        cout << "Do you want to move (m), take (t), or examine (e): ";
        cin >> move;
    

        if(move == static_cast<string>("m")) {
            cout << "Where do you want to move to?" << endl;
            e.getLoc().listExits();
            
        }
        else if(move == static_cast<string>("t")) {
            cout << "What do you want to take?" << endl;
            e.getLoc().listTreasures();
        }
        else if(move == static_cast<string>("e")) {
            cout << "What do you want to examine?" << endl;
            string input;
            do {
                cout << "Enter object or location: ";
                cin >> input;
            } while(input != "object" || input != "location");

            if(input == "location") {
                e.getLoc().describe();
            }
            else if(input == "object") {
                e.getInventory();
                
            }
        }

        string end;
        cout << "Do you want to continue playing? (y for yes, n for no):";
        cin >> end;

        if(end == "true") {
            endBool = true;
        }
    }
}

int main() {

    //creating locations for the crawlspace
    Location forest(static_cast<string>("forest"), static_cast<string>("You are in a forest that is teaming with wildlife. Birds sing and deer prance around."));
    Location beach(static_cast<string>("beach"), static_cast<string>("The waves lap against the sand on a warm beach. Shells are scattered throughout and seagulls caw in the distance."));
    Location swamp(static_cast<string>("swamp"), static_cast<string>("Bugs buzz around the mossy trees in the humid and dense swamp. A wild hog is snorting around."));
    Location savannah(static_cast<string>("savannah"), static_cast<string>("Hyenas cackle in the distance as the bushes russle around you. Giraffes are grazing nearby."));
    Location mountains(static_cast<string>("mountains"), static_cast<string>("Snow capped mountains with a myriad of trees surround you. You hear the cry of elk nearby."));

    //creating the crawlspace and adding the locations to it
    Crawlspace mySpace;
    mySpace.addLocation(forest);
    mySpace.addLocation(beach);
    mySpace.addLocation(swamp);
    mySpace.addLocation(savannah);
    mySpace.addLocation(mountains);

    //creating an explorer who starts at the forest
    Explorer dora(forest);

    //creating the exits 

    //exit from mountain to savannah
    Exit mTs(4, static_cast<string>("Mountain Path"), static_cast<string>("A secret path down to a savannah"));
    mySpace.updateLoc(mTs, 3);

    //exit from savannah to swamp
    Exit sTs(3, static_cast<string>("Random Sewer"), static_cast<string>("What's a sewer doing here? It must lead to a swamp."));
    mySpace.updateLoc(sTs, 2);

    //exit from swamp to forest
    Exit sTf(2, static_cast<string>("Flower Door"), static_cast<string>("A door that opens to a lush forest."));
    mySpace.updateLoc(mTs, 0);

    //exit from forest to beach
    Exit fTb(0, static_cast<string>("Worn Path"), static_cast<string>("A path that goes to the ocean."));
    mySpace.updateLoc(mTs, 1);

    //creating one treasure per location
    Treasure flowerCrown("Flower Crown", "A crown made of flowers. Those wearing it are more in tune with nature.", 20);
    Treasure pearl("Pearl", "A pearl from a clam. This can be sold for a lot of money.", 150);
    Treasure oldPants("Old Pants", "A pair of old khakis. They're covered in muck.", 2);
    Treasure water("Canteen of Water", "And its full!", 200);
    Treasure antlers("Broken Antlers", "Antlers broken off of an elk. Great wall decorations!", 40);

    mySpace.setStart(0);

    string startGame;
    do {
        cout << "Type \"start\" to start: ";
        cin >> startGame;
    } while (startGame != "start");

    playRound(mySpace, dora);

}