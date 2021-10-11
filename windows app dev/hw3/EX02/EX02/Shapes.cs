using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace EX02
{
    class Shapes<T> where T : Shape, new()
    {
        private List<Shape> shapes;

        public Shapes()
        {
            shapes = new List<Shape>();
            //shapes.Add(new Rhombus(5.1, "yellow"));
        }

        public void addShape(Shape s)
        {
            shapes.Add(s);
        }

        public IEnumerator GetEnumerator()
        {
            return shapes.GetEnumerator();
        }
    }
}
