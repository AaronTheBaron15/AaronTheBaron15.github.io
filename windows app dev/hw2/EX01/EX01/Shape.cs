using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace EX01
{
    public class Shape
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

        
    }
}