//Aaron Borjas 
//cs371
//1/13/2020
//Dr. Bell
//Upgrading the geometry library from ex01 of hw3 to have two container classes, one of which holds any shape with a default constructor and the other which holds shapes that are comparable

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EX02
{
    class Program
    {
        static void Main(string[] args)
        {
            

            ComparableShapes<Shape> s = new ComparableShapes<Shape>();

            s.addShape(new Square(15));
            s.addShape(new Triangle(7));

            foreach (Shape shape in s)
            {
                Console.WriteLine("The area of shape " + shape.GetType() + " in ComparableShapes is: " + shape.getArea());
            }

            int compare = s.at(0).CompareTo(s.at(1));

            if (compare == -1)
            {
                Console.WriteLine(s.at(0).GetType() + " has a smaller area than " + s.at(1).GetType() + " (" + s.at(0).getArea() + " < " + s.at(1).getArea() + ")");
            }
            else if (compare == 1)
            {
                Console.WriteLine(s.at(0).GetType() + " has a larger area than " + s.at(1).GetType() + " (" + s.at(0).getArea() + " > " + s.at(1).getArea() + ")");
            }
            else
            {
                Console.WriteLine("The shapes have equal area");
            }

            Shapes<Shape> s2 = new Shapes<Shape>();
            s2.addShape(new Circle(3));
            s2.addShape(new EqPolygon(5,6));
            s2.addShape(new Square(17));
            s2.addShape(new Rhombus(33.6));
            s2.addShape(new Triangle(18.6));

            foreach(Shape shape in s2)
            {
                Console.WriteLine("The area of shape " + shape.GetType() + " in Shapes is: " + shape.getArea());
            }

            Console.ReadLine();
        }
    }
}
