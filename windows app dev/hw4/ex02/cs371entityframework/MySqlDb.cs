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
    public class MySqlDb
    {
        private MySqlConnection conn;

        public MySqlDb(string server, string user, string pw, string db) {
            var connStringBuilder = new MySqlConnectionStringBuilder
            {
                Server = server,
                UserID = user,
                Password = pw,
                Database = db,
                OldGuids = true
            };

            string connstr = connStringBuilder.ConnectionString;
            conn = new MySqlConnection(connstr);
        }

        public void OpenConnection() {
            conn.Open();
        }

        public void CloseConnection() {
            conn.Close();
        }

        public List<Ship> GetAllShips() {
            List<Ship> ships = new List<Ship>();
            string sql = "SELECT * FROM ships";
            using (MySqlCommand cmd = new MySqlCommand()) {
                cmd.CommandText = sql;
                cmd.Connection = conn;
                MySqlDataReader reader = cmd.ExecuteReader(System.Data.CommandBehavior.CloseConnection);
                while (reader.Read()) {
                    ships.Add(new Ship { 
                        Id = (int)reader["id"],
                        Name = (string)reader["Name"],
                        Registration = (string)reader["registration"]
                    });
                }
                reader.Close();
            }
            return ships;
        }

        // In class - Add method to get a single ship

        // Homework four: models and method to print out a complete roster
        //      Crew member's full name, age and the role they fill, the ship's name and registration number
        public Ship getShip(int shipId)
        {
            Ship ship = new Ship();
            string sql = "SELECT * FROM ships WHERE id = " + shipId.ToString();
            using (MySqlCommand cmd = new MySqlCommand())
            {
                cmd.CommandText = sql;
                cmd.Connection = conn;
                MySqlDataReader reader = cmd.ExecuteReader(System.Data.CommandBehavior.CloseConnection);
                while (reader.Read())
                {
                    ship = new Ship
                    {
                        Id = (int)reader["id"],
                        Name = (string)reader["Name"],
                        Registration = (string)reader["registration"]
                    };
                }
                reader.Close();
            }

            return ship;
        }

        public void FullRoster()
        {
            List<Crew> roster = new List<Crew>();
            List<Ship> ships = new List<Ship>();
            List<Roles> roles = new List<Roles>();

            string sql = "SELECT * FROM roster JOIN (crew, ships, roles) ON (crew.id = roster.crewid AND roster.shipid = ships.id AND crew.roleid = roles.id)";
                
            using (MySqlCommand cmd = new MySqlCommand())
            {
                cmd.CommandText = sql;
                cmd.Connection = conn;
                MySqlDataReader reader = cmd.ExecuteReader(System.Data.CommandBehavior.CloseConnection);
                int i = 0;
                while (reader.Read())
                {
                    //Console.WriteLine("Added new ship");
                    //Console.WriteLine("Added new crew");
                    ships.Add(new Ship
                    {
                        Id = (int)reader["id"],
                        Name = (string)reader["name"],
                        Registration = (string)reader["registration"]
                    });
                    roster.Add(new Crew
                    {
                        Id = (int)reader["id"],
                        Fname = (string)reader["fname"],
                        Lname = (string)reader["lname"],
                        Age = (int)reader["age"],
                        RoleId = (int)reader["roleid"]
                    });
                    roles.Add(new Roles
                    {
                        Id = (int)reader["id"],
                        Role = (string)reader["role"],
                        PilotQualified = (bool)reader["pilotQualified"]
                    });

                    
                    Console.WriteLine("{0} ({1}): {2} {3} {4}, {5}", ships[i].Name, ships[i].Registration, roles[i].Role, roster[i].Fname, roster[i].Lname, roster[i].Age);
                    i = i + 1;
                    //Console.WriteLine(i);
                }
                reader.Close();
            }

            
        }

        public void PilotRoster()
        {
            List<Crew> roster = new List<Crew>();
            List<Ship> ships = new List<Ship>();
            List<Roles> roles = new List<Roles>();

            string sql = "SELECT * FROM roster JOIN (crew, ships, roles) ON (crew.id = roster.crewid AND roster.shipid = ships.id AND crew.roleid = roles.id)";

            using (MySqlCommand cmd = new MySqlCommand())
            {
                cmd.CommandText = sql;
                cmd.Connection = conn;
                MySqlDataReader reader = cmd.ExecuteReader(System.Data.CommandBehavior.CloseConnection);
                int i = 0;
                while (reader.Read())
                {
                    //Console.WriteLine("Added new ship");
                    //Console.WriteLine("Added new crew");
                    ships.Add(new Ship
                    {
                        Id = (int)reader["id"],
                        Name = (string)reader["name"],
                        Registration = (string)reader["registration"]
                    });
                    roster.Add(new Crew
                    {
                        Id = (int)reader["id"],
                        Fname = (string)reader["fname"],
                        Lname = (string)reader["lname"],
                        Age = (int)reader["age"],
                        RoleId = (int)reader["roleid"]
                    });
                    roles.Add(new Roles
                    {
                        Id = (int)reader["id"],
                        Role = (string)reader["role"],
                        PilotQualified = (bool)reader["PilotQualified"]
                    });

                    if(roles[i].PilotQualified)
                    {
                        Console.WriteLine("{0} ({1}): {2} {3} {4}, {5}", ships[i].Name, ships[i].Registration, roles[i].Role, roster[i].Fname, roster[i].Lname, roster[i].Age);
                    }
                    i = i + 1;
                    //Console.WriteLine(i);
                }
                reader.Close();
            }
        }
    }  


}
            
            
            

