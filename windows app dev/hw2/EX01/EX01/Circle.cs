using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace EX01
{
    public class Circle : Shape
    {
        private double radius;

        public double rad
        {
            get { return radius; }
            set
            {
                radius = value;
            }
        }

        public Circle()
        {
            radius = 5;
        }

        public Circle(double r)
        {
            radius = r;
        }
        public Circle(double r, string c = "white")
        {
            radius = r;
            color = c;
        }

        public override double getPeri()
        {
            return 2 * Math.PI * radius;
        }

        public override string ToString()
        {
            return color + " circle with radius of " + rad;
        }
    }
}