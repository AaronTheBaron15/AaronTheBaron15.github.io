//Pair programmed by Aaron Borjas and Pukar Mahat
//1/8/2020
//CS371
//Dr. Bell
//using interfaces to continue the radio example as shown on the slides

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EX03
{
    public interface ISwitch
    {
        void toggle();
    }

    public interface ITunable
    {
        void tune(float s);
    }

    public class Radio : ISwitch, ITunable
    {
        private bool on;
        private float station;
        private int volume;

        public Radio()
        {
            @on = false;
            station = 91.7F;
            volume = 5;
        }

        public void toggle()
        {
            if (@on)
            {
                @on = false;
            }
            else
            {
                @on = true;
            }
        }

        public void tune(float s)
        {
            if (s > 88.5 && s < 107.9)
            {
                Station = s;
            }
        }

        public bool On
        {
            get { return @on; }
            set { @on = value; }
        }

        public float Station
        {
            get { return station; }
            set
            {
                if (value > 88.5 && value < 107.9)
                {
                    station = value;
                }
            }
        }

        public int Volume
        {
            get { return volume; }
            set
            {
                if (value >= 0 && value <= 12)
                {
                    volume = value;
                }
            }
        }

        public override string ToString()
        {
            if (On)
            {
                return "The radio is turned on at volume " + Volume + " and is set to station " + Station;
            }
            else
            {
                return "The radio is off.";

            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Radio r = new Radio();
            Console.WriteLine(r.ToString());

            bool on = false;


            Console.WriteLine("Would you like to turn the radio on? (true or false): ");
            on = Convert.ToBoolean(Console.ReadLine());
            if (on == false)
            {
                Console.WriteLine(r.ToString());
            }
            else
            {
                r.toggle();
                Console.Beep();
                Console.WriteLine(r.ToString());
            }

            while (on)
            {
                Console.WriteLine("Would you like to change the volume or station, or turn off the radio? (v, s, or off): ");
                string task = Console.ReadLine();
                if(task.Equals("v"))
                {
                    Console.WriteLine("What would you like to change the volume to? (any non-decimal number between 0 and 12): ");
                    int vol = Convert.ToInt32(Console.ReadLine());
                    r.Volume = vol;
                }
                else if (task.Equals("s"))
                {
                    Console.WriteLine("What would you like to change the volume to? (any decimal number from 88.5 to 107.9): ");
                    float stat = float.Parse(Console.ReadLine());
                    r.Station = stat;
                }
                else if (task.Equals("off"))
                {
                    on = false;
                    r.toggle();
                    Console.Beep();
                }
                Console.WriteLine(r.ToString());

            }

            Console.ReadLine();
        }
    }
}
