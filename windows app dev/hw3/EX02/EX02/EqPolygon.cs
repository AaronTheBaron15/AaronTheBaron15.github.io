using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;

namespace EX02
{
    public class EqPolygon : Shape, IComparable<EqPolygon>
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

        public override double getArea()
        {
            double top = Math.Pow(length,2) * sides;
            double bottom = 4 * (Math.Tan(180 / sides));
            return top / bottom;
        }

        public int CompareTo(EqPolygon p)
        {
            if (this.getArea() < p.getArea())
            {
                return -1;
            }
            else if (this.getArea() > p.getArea())
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

    }
}