using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    class Prestamo
    {
        public void setVencimiento(int datetime)
        {
            if(setVencimiento > datetime.CompareTo)
            {
                Console.WriteLine("error, no puede poner esa fecha");
            }
        }
    }
}
