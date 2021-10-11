using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;

namespace EX03
{
    public class City
    {

        public delegate void sketchHandler(Vampire v);

        public delegate void spookHandler();

        private sketchHandler listOfHandlers;

        public void RegisterWithSketch(sketchHandler methodToCall)
        {
            listOfHandlers = methodToCall;
        }

        public event spookHandler avoidVamp;


        public City()
        {
            residents = new List<Person>();
        }

        private static List<Person> residents;
        

        public void addResident(ref Person p)
        {
            residents.Add(p);
        }

        public static void OnBiteEvent(Vampire v)
        {
            Console.WriteLine("**** Message from Vampire object ****");
            residents.Add(v.speak());
            Console.WriteLine("*************************************");
        }

        public static void avoidBite()
        {
            Console.WriteLine("Good call! That guy gave me the heebie jeebies.");
        }

        public void tourResidents()
        {
            avoidVamp = new spookHandler(avoidBite);

            sketchHandler sketch = (vamp) => { residents.Add(vamp.speak()); };

            Console.WriteLine("Welcome to our city! Let our citizens introduce themselves!");

            for (int i = 0; i < residents.Count(); i++)
            {
                Vampire temp = new Vampire();
                if (residents[i].GetType() != temp.GetType())
                {
                    residents[i].speak();
                }
                else 
                {
                    //this.RegisterWithSketch(OnBiteEvent);
                    Console.WriteLine("Something feels evil about the approaching citizen. Do you still approach? (y/n): ");
                    string input = Console.ReadLine();
                    if (input != "y")
                    { 
                        avoidVamp();
                    }
                    else
                    {
                        sketch((Vampire)residents[i]);
                        
                        break;
                    }
                }
            }
        }
    }
}