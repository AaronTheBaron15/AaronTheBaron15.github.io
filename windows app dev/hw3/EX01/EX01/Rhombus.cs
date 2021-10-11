using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace EX01
{
    public class Rhombus : EqPolygon
    {
        public Rhombus()
        {
            length = 1;
            color = "white";
        }

        public Rhombus(double l, string c = "white")
        {
            length = l;
            color = c;
        }

        public override double getPeri()
        {
            return 4 * length;
        }

        public override string ToString()
        {
            return $"This shape is a {this.color} rhombus with a side length of {this.length}.";
        }

        public override double getArea()
        {
            return length * length;
        }
    }
}