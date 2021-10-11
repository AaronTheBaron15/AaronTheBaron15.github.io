using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace EX01
{
    public class Triangle : EqPolygon
    {
        public Triangle()
        {
            length = 1;
            color = "white";
        }
        public Triangle(double l, string c = "white")
        {
            length = l;
            color = c;
        }

        public override double getPeri()
        {
            return this.length * 3;
        }
        public override string ToString()
        {
            return $"This shape is a {this.color} triangle with a side length of {this.length}.";
        }
    }
}