using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace EX03
{
    public class Person
    {
        private string name;

        public string nombre
        {
            get => name;
            set => name = value;
        }
        public City City
        {
            get => default;
            set
            {
            }
        }

        public Person()
        {
            nombre = "John Doe";
        }

        public Person(string n)
        {
            nombre = n;
        }

        public string getName()
        {
            return this.nombre;
        }

        public virtual Person speak()
        {
            return this;
        }
    }
}