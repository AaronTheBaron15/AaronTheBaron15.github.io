#include <iostream>
using namespace std;

#ifndef BUDGET_H
#define BUDGET_H

class Budget {
    private:
        float talentBudget;
        float productionBudget;
        float marketBudget;
    public:
        //empty class constructor
        Budget();
        
        //Budget constructor, creates a budget with talent, production, and market as float values passed into it
        //these are representing talent budget, production budget, and marketing budget
        Budget(float talent, float production, float market);

        //function getTalent, which gets the budget dedicated to the talent
        //no inputs
        //returns the budget dedicated towards the talent in dollars
        float getTalent();

        //function getProduction, gets the dedicated production budget
        //no inputs
        //returns the budget dedicated towards the production of the movie
        float getProduction();

        //function getMarket, gets the dedicated marketing budget
        //no inputs
        //returns the budget dedicated to marketing
        float getMarket();

        //function getTotalBudget, which gets the total cost to make the movie
        //no inputs 
        //returns the total of talentBudget, productionBudget, and marketBudget
        float getTotalBudget();

        //function forcastReturn, which forcasts the amount of money needed to create a certain percent of profit. if the total cost was $100 and the percentReturn is 50%, the forcasted return should be $150
        //inputs - float percentReturn, the percent of profit expected to be made
        //returns the amount of money needed to create a certain percent of profit
        float forcastReturn(float percentReturn);

        //function print, which prints all the information about the budget
        //no inputs
        //prints the information about the budget to the screen
        void print();
};

#endif