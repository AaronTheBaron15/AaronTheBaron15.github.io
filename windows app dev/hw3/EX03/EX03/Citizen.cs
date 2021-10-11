using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace EX03
{
    public class Citizen : Person
    {
        public Citizen()
        {
            nombre = "John Smith";
        }

        public Citizen(string n)
        {
            nombre = n;
        }

        public override Person speak()
        {
            Console.WriteLine("What a beautiful day! Surely nothing could go wrong.");
            return this;
        }
    }
}