using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MySql.Data;
using MySql.Data.MySqlClient;
using cs371entityframework.Models;

namespace cs371entityframework
{
    class Program
    {
        static void Main(string[] args)
        {
            MySqlDb fleet = new MySqlDb("cs1", "cs371student", "whitworth", "cs371ado");
            fleet.OpenConnection();
            List<Ship> ships = fleet.GetAllShips();
            foreach (Ship s in ships) {
                Console.WriteLine("{0} has registration number {1}", s.Name, s.Registration);
            }

            fleet.OpenConnection();
            Ship sh = fleet.getShip(1);
            Console.WriteLine("getting ship by id... \n{0} has registration number {1}", sh.Name, sh.Registration);

            fleet.OpenConnection();
            fleet.FullRoster();

            Console.WriteLine();

            fleet.OpenConnection();
            fleet.PilotRoster();
        }
    }
}
