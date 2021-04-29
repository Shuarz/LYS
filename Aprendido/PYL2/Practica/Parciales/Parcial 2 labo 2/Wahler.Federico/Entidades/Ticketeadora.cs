using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Entidades
{
    public static class Ticketeadora<T> where T : Utiles
    {
        public static bool ImprimirTicket(Cartuchera<T> car)
        {
            bool rta = true;

            string path = Environment.GetFolderPath(System.Environment.SpecialFolder.MyDocuments) + @"\tickets.log";

            if (!File.Exists(path))
            {
                try
                {
                    using (StreamWriter f = new StreamWriter(path, false))
                    {
                        f.Write("Fecha: ");
                        f.WriteLine(System.DateTime.Now);
                        f.Write("Precio Total: ");
                        f.WriteLine(car.PrecioTotal);
                        f.WriteLine("---------------------------------");
                    }
                }
                catch
                {
                    rta = false;
                }
            }
            else
            {
                try
                {
                    using (StreamWriter f = new StreamWriter(path, true))
                    {
                        f.Write("Fecha: ");
                        f.WriteLine(System.DateTime.Now);
                        f.Write("Precio Total: ");
                        f.WriteLine(car.PrecioTotal);
                        f.WriteLine("---------------------------------");
                    }
                }
                catch
                {
                    rta = false;
                }

            }


            return rta;
        }
    }
}
