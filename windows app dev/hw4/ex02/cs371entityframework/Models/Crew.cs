using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs371entityframework.Models
{
    public class Crew
    {
        public int Id { get; set; }
        public string Fname { get; set; }
        public string Lname { get; set; }
        public string Name { get; set; }
        public int Age { get; set; }
        public int RoleId { get; set; }
    }
}
