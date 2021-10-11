using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EX_01
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("I see you're known to the system as " + Environment.UserName + ". What do you prefer to be called? ");
            string userName = Console.ReadLine();
            Console.WriteLine("OK " + userName + ", how old are you?");
            int userAge = Convert.ToInt32(Console.ReadLine());
            if(userAge < 18) {
                Console.BackgroundColor = ConsoleColor.Red;
                Console.WriteLine("Hello, {0}", userName);

                Console.Beep();
                MessageBox.Show("DANGER, " + userName + " Robinson! DANGER!");
            }
            else if(userAge >= 18) {
                Console.BackgroundColor = ConsoleColor.Yellow;
                Console.ForegroundColor = ConsoleColor.Black;
                Console.WriteLine("Hello, {0}", userName);
            }

            Console.ReadLine();
        }
    }
}
