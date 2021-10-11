using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace EX01
{
    public class Square : EqPolygon
    {
        public Square()
        {
            length = 1;
            color = "white";
        }
        public Square(double l, string c = "white")
        {
            length = l;
            color = c;
        }

        public override double getPeri()
        {
            return this.length * 4;
        }

        public override string ToString()
        {
            return $"This shape is a {this.color} square with a side length of {this.length}.";
        }

        public override double getArea()
        {
            return length * length;
        }
    }
}