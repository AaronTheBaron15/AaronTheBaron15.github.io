//Aaron Borjas 
//cs371
//1/13/2020
//Dr. Bell
//updating the geometry classes from hw2 to contain a getArea function
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EX01
{
    class Program
    {
        static void Main(string[] args)
        {
            Shape[] shapes = { new Circle(3.7, "pink"), new Square(3, "maroon"), new Rhombus(8.3, "black"), new EqPolygon(4,  5, "brown"), new Triangle(15.4, "red")};

            for(int i = 0; i < shapes.Length; i++)
            {
                Console.WriteLine(shapes[i].ToString());
                Console.WriteLine("The perimeter of shape is: " + shapes[i].getPeri());
            }

            Console.ReadLine();
        }
    }
}
