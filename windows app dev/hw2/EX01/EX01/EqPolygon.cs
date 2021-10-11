using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;

namespace EX01
{
    public class EqPolygon : Shape
    {
        private double sideLen;
        private int numSides;

        public int sides
        {
            get => numSides;
            set => numSides = value;
        }
        public double length
        {
            get => sideLen;
            set => sideLen = value;
        }

        public EqPolygon()
        {
            sideLen = 1;
            sides = 4;
            color = "white";
        }

        public EqPolygon(double l)
        {
            sideLen = l;
            color = "white";
        }

        public EqPolygon(double l, int s, string c = "white")
        {
            sideLen = l;
            sides = s;
            color = c;
        }

        public override double getPeri()
        {
            return sides * length;
        }

        public override string ToString()
        {
            return $"This shape is a {this.color} Equaliateral Polygon with a side length of {this.length} and {this.sides} number of sides";
        }

    }
}