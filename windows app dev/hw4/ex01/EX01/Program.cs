//Aaron Borjas
//CS371
//1/14/2020
//Dr. Bell
//This part of hw4 works on using linq to interact with xml stuff. creates a ship with a list of crew members, who have first and last names, positions, ages, etc. That stuff is able to be messed around with.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Xml.Linq;

namespace linqTest
{
    class Program
    {
        static void Main(string[] args)
        {
            // We will need implictly typed variables for the return values
            // We need to know the type ahead of time!
            // The compiler cannot, however
            // var myLinqInt = 0;

            CrewMember mal = new CrewMember(
                    "Malcolm",
                    "Reynolds",
                    "Captain",
                    34
                );

            CrewMember zoe = new CrewMember(
                    "Zoe",
                    "Washburne",
                    "First Mate",
                    23
                );

            CrewMember jayne = new CrewMember(
                    "Jayne",
                    "Cobb",
                    "Public Relations",
                    26
                );

            CrewMember wash = new CrewMember(
                    "Hoban",
                    "Washburne",
                    "Pilot"
                );

            CrewMember inara = new CrewMember(
                    "Inara",
                    "Serra",
                    "Ambassador",
                    43
                );

            CrewMember book = new CrewMember(
                    "Derrial",
                    "Book",
                    "Shepherd",
                    57
                );

            CrewMember kaylee = new CrewMember(
                    "Kaywinnit",
                    "Frye",
                    "Engineer",
                    23
                );

            CrewMember simon = new CrewMember(
                    "Simon",
                    "Tam",
                    "Doctor",
                    41
                );

            CrewMember river = new CrewMember(
                    "River",
                    "Tam",
                    "Psyker",
                    36
                );

            List<CrewMember> roster = new List<CrewMember> {
                mal, zoe, jayne, wash, inara, book, kaylee, simon, river
            };

            XmlRoster xmlRoster = new XmlRoster(roster);

            CrewMember yoSaffBridge = new CrewMember(
                "Yolanda Saffron Bridget",
                "Unknown",
                "Hazard"
                );

            xmlRoster.AddCrew(yoSaffBridge);
            xmlRoster.Print();

            XElement serenity = xmlRoster.GetXmlRoster();
            Console.WriteLine(serenity);

            //finding tams
            //IEnumerable<XElement> tams = from crew in serenity.Descendants("crewMember")
            //                             where (string)crew.Attribute("Lname") == "Tam"
            //                             select crew;
            IEnumerable<XElement> tams = serenity.Descendants("crewMember").Where(t => (string)t.Attribute("Lname") == "Tam").Select(t => t);
            Console.WriteLine("Found {0} Tams. Two by two, hands of blue...", tams.Count());
            foreach (XElement tam in tams) {
                Console.WriteLine(tam);
            }

            Console.WriteLine();

            //find washburnes
            IEnumerable<XElement> washburnes = from crew in serenity.Descendants("crewMember")
                                         where (string)crew.Attribute("Lname") == "Washburne"
                                         select crew;
            foreach (XElement washburne in washburnes)
            {
                Console.WriteLine(washburne);
                Console.WriteLine(washburne.GetType());
            }

            //sorting by first name and if the person's last name starts with a letter befor M
            IEnumerable<XElement> firstHalf = from crew in serenity.Descendants("crewMember")
                                         where (String.Compare(((string) crew.Attribute("Lname")), "A") == 1) 
                                            && (String.Compare(((string) crew.Attribute("Lname")), "M") == -1)
                                         orderby (string) crew.Attribute("Fname") descending
                                         select crew;
            foreach (XElement n in firstHalf)
            {
                Console.WriteLine(n);
            }


            //AVG AGE OF ALL CREW MEMBERS
            IEnumerable<XElement> ages = from crew in serenity.Descendants("crewMember")
                       select crew;
            double runningAge = 0;
            int numAges = 0;
            foreach(XElement c in ages)
            {

                Console.WriteLine("The total age of the crew members is: " + (runningAge));
                runningAge += (int)c.Attribute("Age");
                numAges++;
            }
            Console.WriteLine("The average age of the crew members is: " + (runningAge/numAges));
            

            //SHIP OPERATORS
            IEnumerable<XElement> operators = from crew in serenity.Descendants("crewMember")
                                              where ((string)crew.Attribute("Position") == "Captain"
                                                || (string)crew.Attribute("Position") == "First Mate"
                                                || (string)crew.Attribute("Position") == "Pilot")
                                              select crew;

            foreach (XElement op in operators) 
            {
                Console.WriteLine(op);
            }

            Console.WriteLine();

            //NOT ship operatores
            IEnumerable<XElement> Noperators = from crew in serenity.Descendants("crewMember")
                                              where (!((string)crew.Attribute("Position") == "Captain"
                                                || (string)crew.Attribute("Position") == "First Mate"
                                                || (string)crew.Attribute("Position") == "Pilot"))
                                              select crew;
            foreach(XElement op in Noperators)
            {
                Console.WriteLine(op);
            }
            Console.ReadLine();
        }
    }
}
