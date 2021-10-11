//This project was collaborated on by Aaron Borjas and Pukar Mahat
//CS371 HW2
//1/9/2020
//Dr. Bell
//exceptions incorporated in converting from one temperature unit to another temperature unit

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EX04
{
    [Serializable]
    class cException : ApplicationException
    {
        public cException() { }
        public cException(string message) : base(message) { }
        public cException(string message, System.Exception inner) : base(message, inner) { }
        protected cException(System.Runtime.Serialization.SerializationInfo info, System.Runtime.Serialization.StreamingContext context) : base(info, context) { }


    }

    class Converter : cException
    {
        public Converter()
        {

        }
        public static double ftok(double f)
        {
            double k = ((f - 32) * (5/9.0)) + 273.15;
            try
            {
                if(k < 0)
                {
                    throw new cException("Kelvin cannot be below 0!");
                }
                else
                {
                    return k;
                }
            }
            catch (cException e)
            {
                Console.Write(e.Message + " Exiting with error code ");
                return -1;
            }
            
        }

        public static double ftoc(double f)
        {
            double c = (f - 32) * (5.0 / 9);

            try
            {
                if(c < -273.15)
                {
                    throw new cException("Celsius cannot be below -273.15 degrees!");
                }
                else
                {
                    return c;
                }
            }
            catch(cException e)
            {
                Console.Write(e.Message + " Exiting with error code ");
                return -1;
            }
        }

        public static double ktof(double k)
        {
            double f = (k - 273.15) * (9 / 5.0) + 32;

            try
            {
                if(f < -459.67)
                {
                    throw new cException("Fahrenheit cannot be below -459.67 degrees!");
                }
                else
                {
                    return f;
                }
            }
            catch(cException e)
            {
                Console.Write(e.Message + " Exiting with error code ");
                return -1;
            }
        }

        public static double ktoc(double k)
        {
            double c = k - 273.15;

            try
            {
                if (c < -273.15)
                {
                    throw new cException("Celsius cannot be below -273.15 degrees!");
                }
                else
                {
                    return c;
                }
            }
            catch (cException e)
            {
                Console.Write(e.Message + " Exiting with error code ");
                return -1;
            }
        }

        public static double ctok(double c)
        {
            double k = c + 273.15;
            try
            {
                if (k < 0)
                {
                    throw new cException("Kelvin cannot be below 0 degrees!");
                }
                else
                {
                    return k;
                }
            }
            catch (cException e)
            {
                Console.Write(e.Message + " Exiting with error code ");
                return -1;
            }
        }

        public static double ctof(double c)
        {
            double f = (c * (9 / 5.0)) + 32;
            try
            {
                if (f < -459.67)
                {
                    throw new cException("Fahrenheit cannot be below - 459.67 degrees!");
                }
                else
                {
                    return f;
                }
            }
            catch (cException e)
            {
                Console.Write(e.Message + " Exiting with error code ");
                return -1;
            }
        }

    }

    class Program
    {
        public static double convertFromUnits(string unit1, string unit2, double temp)
        {
            switch(unit1)
            {
                case "f":
                    if(unit2 == "c")
                    {
                        return Converter.ftoc(temp);
                    }
                    else
                    {
                        return Converter.ftok(temp);
                    }
                case "c":
                    if (unit2 == "f")
                    {
                        return Converter.ctof(temp);
                    }
                    else
                    {
                        return Converter.ctok(temp);
                    }
                case "k":
                    if (unit2 == "f")
                    {
                        return Converter.ktof(temp);
                    }
                    else
                    {
                        return Converter.ktoc(temp);
                    }
                default:
                    break;
            }

            return -1;
        }
        public static double tempConvert(double temp)
        {

            Console.WriteLine("Enter a unit you'd like to convert from (f for fahrenheit, c for celsius, and k for kelvin): ");
            string unit1 = Console.ReadLine();
            Console.WriteLine("Ok, now enter a unit you'd like to convert to (f for fahrenheit, c for celsius, and k for kelvin): ");
            string unit2 = Console.ReadLine();

            return convertFromUnits(unit1, unit2, temp);
        }
        static void Main(string[] args)
        {
            Console.WriteLine("***** Welcome to temperature converter! *****");
            bool input = true;

            while(input)
            {
                Console.WriteLine("Enter a number to convert from one temperature unit to another temperature unit:" );
                double temp = Double.Parse(Console.ReadLine());

                Console.WriteLine(tempConvert(temp));

                Console.WriteLine("Would you like to continue? (true or false): ");
                if(Console.ReadLine() == "false")
                {
                    break;
                }
            }
        }
    }
}
