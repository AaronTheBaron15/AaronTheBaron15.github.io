using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EX02
{
	public class ComparableShapes<T> where T : Shape, IComparable
	{
		private List<Shape> shapes;

		public ComparableShapes()
		{
			shapes = new List<Shape>();
		}

		public void addShape<T>(T t) where T : EqPolygon
		{
			shapes.Add(t);
		}

        public EqPolygon at(int index)
        {
            return (EqPolygon)shapes[index];
        }

		public IEnumerator GetEnumerator()
		{
			return shapes.GetEnumerator();
		}
	}
}
