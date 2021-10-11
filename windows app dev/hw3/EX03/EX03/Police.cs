using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace EX03
{
    public class Police : Person
    {
        public Police()
        {
            nombre = "Sarge";
        }

        public Police(string n)
        {
            nombre = n;
        }
        public override Person speak()
        {
            Console.WriteLine("PUT YOUR HANDS IN THE AIR!");
            return this;
        }
    }
}