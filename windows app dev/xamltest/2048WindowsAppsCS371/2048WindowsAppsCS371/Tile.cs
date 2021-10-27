using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;

namespace _2048WindowsAppsCS371
{
    //a class for the individual tiles on the board. 
    //member variables include the number value of the tile, the color, the location on the board, and a status on if it is combined
    //member functions includean operator overload for addition and CompareTo, which compares two instances of the class.
    class Tile : IComparable<Tile>
    {
        public string value { get; set; }
        public Color color { get; set; }
        public int row { get; set; }
        public int col { get; set; }
        public bool combined { get; set; }

        
        //default constructor
        //sets color to dark gray, value is empty, and it is not combined
        public Tile()
        {
            color = Colors.DarkGray;
            value = "";
            combined = false;
        }

        //constructor by value
        //takes in a string with a number in it, which is assigned to value of the tile.
        //sets the color based on the value
        public Tile(string val)
        {
            value = val;
            switch (val) //choses color of tile based on what number it is
            {
                case "":
                    color = Colors.DarkGray;
                    break;
                case "2":
                    color = Colors.LightGray;
                    break;
                case "4":
                    color = Colors.Tan;
                    break;
                case "8":
                    color = Colors.Coral;
                    break;
                case "16":
                    color = Colors.DarkOrange;
                    break;
                case "32":
                    color = Colors.LightCoral;
                    break;
                case "64":
                    color = Colors.OrangeRed;
                    break;
                case "128":
                    color = Colors.GreenYellow;
                    break;
                case "256":
                    color = Colors.Chartreuse;
                    break;
                case "512":
                    color = Colors.Thistle;
                    break;
                case "1024":
                    color = Colors.Lime;
                    break;
                case "2048":
                    color = Colors.DarkTurquoise;
                    break;
                default:
                    color = Colors.MistyRose;
                    break;
            }

            combined = false;
        }

        //operator overload for +
        //input - takes in two tiles with set values
        //output - returns a tile that has a combination value of the two input tiles
        public static Tile operator +(Tile t, Tile other)
        {
            int ival = int.Parse(other.value) + int.Parse(t.value); //adds the value variable of each tile together.
            string sval = ival.ToString(); //converts the value of addition of two tiles to string

            return new Tile(sval); //returns a new Tile that has a value of sval 
        }


        //CompareTo 
        //inpput - takes in a tile with a set value
        //output - returns 0 if the two tiles are the same or if one tile is empty, returns -1 if *this* instance's value is less than other's value, and returns 1 otherwise
        public int CompareTo(Tile t)
        {
            //just in case it tries to parse an empty string
            try
            {

                if (Int32.Parse(this.value) == Int32.Parse(t.value)) //if the two tiles are equal to each other
                {
                    return 0;
                }
                else if (Int32.Parse(this.value) < Int32.Parse(t.value)) //if the current instance's value is less than the value of the second tile's value
                {
                    return -1; //return -1, which indicates this.value is less than t.value
                }
                else //otherwise, this.value is greater than t.value
                {
                    return 1; //return 1, indicates this.value is greater than t.value
                }
            }
            catch (Exception e) //catch the empty string exception
            {
                //Console.WriteLine("Tried to parse empty strings");
                return 0;
            }
        }
    }
}
