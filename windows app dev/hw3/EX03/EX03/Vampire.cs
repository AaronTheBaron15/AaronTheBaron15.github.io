using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace EX03
{
    public class Vampire : Person
    {

        public Vampire()
        {
            nombre = "Dracula";
        }

        public Vampire(string n)
        {
            nombre = n;
        }
        public override Person speak()
        {
            Console.WriteLine("Ssss! <Bite!> <Bite!> <Bite!>");
            Console.WriteLine("You've been bitten by a vampire and are now a cursed undead");
            Console.WriteLine("What was your name in life, former mortal?");
            string name = Console.ReadLine();

            Vampire spawn = new Vampire(name);
            return spawn;
        }
    }
}