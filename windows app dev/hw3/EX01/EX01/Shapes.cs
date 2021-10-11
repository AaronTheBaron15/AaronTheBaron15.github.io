using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace EX01
{
    class Shapes
    {
        public Shapes()
        {
            Shape r = new Rhombus(15.7, "yellow");
            Shape s = new Square(3.2, "red");
            Shape t = new Triangle(8.5, "Blue");
            shapes.Add(r);
            shapes.Add(s);
            shapes.Add(t);
        }

        private static List<Shape> shapes;
    }
}
