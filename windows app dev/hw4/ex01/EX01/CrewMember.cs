using System;

namespace linqTest
{
    class CrewMember : IDisposable
    {
        public string Fname {
            get;
            set;
        }
        public string Lname {
            get;
            set;
        }
        public int Age
        {
            get;
            set;
        }
        public string Position {
            get;
            set;
        }
        public string Rank {
            get;
            set;
        }

        public CrewMember(string fname = "none", string lname = "none", string position = "none", int age = 0, string rank= "none") {
            Fname = fname;
            Lname = lname;
            Position = position;
            Rank = rank;
            Age = age;
        }

        ~CrewMember()
        {
            cleanUp();
        }

        public void Dispose()
        {
            cleanUp();
            GC.SuppressFinalize(this);
        }

        public void cleanUp()
        {
            Console.WriteLine("Cleaned up crew member!");
        }

    }
}
