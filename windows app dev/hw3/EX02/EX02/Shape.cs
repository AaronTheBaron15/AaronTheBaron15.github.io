using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace EX02
{
    public class Shape : IComparable
    {
        private string shapeC;
        public string color
        {
            get => shapeC;
            set => shapeC = value;
        }

        public Shape()
        {
            color = "white";
        }

        public Shape(string c)
        {
            color = c;
        }

        public virtual double getPeri()
        {
            return 0.0;
        }

        public virtual double getArea()
        {
            return 0.0;
        }

        int IComparable.CompareTo(object obj)
        {
            Shape temp = obj as Shape;
            if (temp != null)
            {
                if (this.getArea() > temp.getArea())
                {
                    return 1;
                }

                if (this.getArea() < temp.getArea())
                {
                    return -1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                throw new ArgumentException("Parameter is not a Shape!");
            }
        }

    }
}