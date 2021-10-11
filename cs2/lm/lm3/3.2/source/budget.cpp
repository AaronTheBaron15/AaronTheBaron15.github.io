#include "../headers/budget.h"
using namespace std;

Budget::Budget() {
    
}

Budget::Budget(float talent, float production, float market) {
    talentBudget = talent;
    productionBudget = production;
    marketBudget = market;
}

float Budget::getTalent() {
    return talentBudget;
}

float Budget::getProduction() {
    return productionBudget;
}

float Budget::getMarket() {
    return marketBudget;
}

float Budget::getTotalBudget() {
    return talentBudget+productionBudget+marketBudget;
}

float Budget::forcastReturn(float percentReturn) {
    float costToProduce = talentBudget + productionBudget + marketBudget;
    return costToProduce*(percentReturn/100);
}

void Budget::print() {
    cout << "The talent budget is: " << talentBudget << endl;
    cout << "The production budget is: " << productionBudget << endl;
    cout << "The marketing budget is: " << marketBudget << endl;
    cout << "The total budget is: " << talentBudget + productionBudget + marketBudget << endl;
}