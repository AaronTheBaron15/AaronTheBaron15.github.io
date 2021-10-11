//Worked on by Caleb Grode and Aaron Borjas
//CS371
//1/13/2020
//Dr. Bell
//Extends the city tutorial class, adding delegates, events, anonymous functions, and a few more advanced c# items

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EX03
{
    class Program
    {
        static void Main(string[] args)
        {
            City metropolis = new City();
            Person fred = new Citizen("Fred Rogers");
            Person pete = new Citizen("Pete Tucker");
            Person anne = new Citizen("Anne Trefry");
            Person dexter = new Police("Dexter");
            Person david = new Vampire("David Boreanaz");

            metropolis.addResident(ref fred);
            metropolis.addResident(ref pete);
            metropolis.addResident(ref anne);
            metropolis.addResident(ref dexter);
            metropolis.addResident(ref david);

            string keepplaying = "y";
            while (keepplaying == "y")
            {
                metropolis.tourResidents();
                Console.WriteLine("Do you want to play again? (y/n): ");
                keepplaying = Console.ReadLine();
            }

        }
    }
}
