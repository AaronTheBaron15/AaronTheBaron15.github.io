using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EX_02
{
    class Program
    {
        public static int Add(int a, int b)
        {
            return a+b;
        }
        public static int Subtract(int a, int b)
        {
            return a-b;
        }
        public static int Multiply(int a, int b)
        {
            return a*b;
        }
        public static int Divide(int a, int b)
        {
            return a/b;
        }
        public static int Operate(string sign, int operand1, int operand2)
        {
            switch(sign)
            {
                case "+":
                    return Add(operand1, operand2);
                case "-":
                    return Subtract(operand1, operand2);
                case "*":
                    return Multiply(operand1, operand2);
                case "/":
                    return Divide(operand1, operand2);
                default:
                    Console.WriteLine("A valid operator was not provided. Please use +, -, *, or /");
                    break;
            }
            return -1;
        }

        static void Main(string[] args)
        {
            string input;
            Console.WriteLine("Would you like to perform a calculation? (y/n): ");
            input = Console.ReadLine();
            while (input == "y")
            {
                Console.WriteLine("Enter an operator (+, -, *, /): ");
                string operation = Console.ReadLine();
                Console.WriteLine("Sweet! Ok, now enter an operand (any non-decimal number): ");
                int operand1 = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Thanks! Now enter a second operand (again, any non-decimal number): ");
                int operand2 = Convert.ToInt32(Console.ReadLine());

                Console.WriteLine("Computing {1} {0} {2} ...", operation, operand1, operand2);
                int ans = Operate(operation, operand1, operand2);
                MessageBox.Show("The answer is: " + ans);

                Console.WriteLine("Would you like to perform a calculation? (y/n): ");
                input = Console.ReadLine();
            }
        }
    }
}
