using Entidades;
using System;
using System.Data;
using System.Data.SqlClient;
using System.Threading;
using System.Xml;
using System.Xml.Serialization;
using System.Runtime.Serialization;
using System.IO;

namespace TestConsola
{
    class Program
    {
        static void Main(string[] args)
        {
            Vendedora celulares = new Vendedora();
            Vendedora pantallas = new Vendedora();
            DataTable tabla = new DataTable("historialVentas");
            SqlDataAdapter dA = new SqlDataAdapter();
            SqlConnection conexion = new SqlConnection(Properties.Settings.Default.conexionBD);
            SmartPhone s= new SmartPhone(1, "Galaxy Core", 240, "Apple", ESistemaOperativo.iOS, EMemoria.GB32);
            Pantalla p1 = new Pantalla(1,"Monitor",450,"Samsung",EPulgadas.P32,EResolucion.P1080);
            Pantalla p2 = new Pantalla(2, "Monitor", 450, "Samsung", EPulgadas.P32, EResolucion.P1080);
            SmartPhone s2 = new SmartPhone(1, "Galaxy Plus", 220, "Samsung", ESistemaOperativo.Android, EMemoria.GB16);
            Pantalla p3 = new Pantalla(1, "Television", 500, "LG", EPulgadas.P32, EResolucion.K4);

            celulares += s;
            celulares += s2;

            pantallas += p1;
            pantallas += p2;
            pantallas += p3;
            
            
            try
            {
                conexion.Open();

                if(conexion.State == System.Data.ConnectionState.Open)
                {
                    conexion.Close();
                    Console.WriteLine("CONEXION REALIZADA CON EXITO");
                }
            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
            }
            
            try
            {
                tabla.Columns.Add("idVenta", typeof(int));

                tabla.PrimaryKey = new DataColumn[] { tabla.Columns[0] };

                tabla.Columns[0].AutoIncrement = true;
                tabla.Columns[0].AutoIncrementSeed = 1;
                tabla.Columns[0].AutoIncrementStep = 1;

                Console.WriteLine("DATA TABLE CONFIGURADO CON EXITO");
            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
            }


            try
            {
                conexion = new SqlConnection(Properties.Settings.Default.conexionBD);

                dA.SelectCommand = new SqlCommand("SELECT * FROM [BaseTP4].[dbo].[pantalla] ", conexion);
                dA.InsertCommand = new SqlCommand("INSERT INTO [BaseTP4].[dbo].[pantalla] (producto, marca, resolucion, pulgadas, precio) VALUES (@producto, @marca, @resolucion, @pulgadas, @precio)", conexion);

                dA.InsertCommand.Parameters.Add("@producto", SqlDbType.VarChar, 50, "producto");
                dA.InsertCommand.Parameters.Add("@marca", SqlDbType.VarChar, 50, "marca");
                dA.InsertCommand.Parameters.Add("@pulgadas", SqlDbType.VarChar, 50, "pulgadas");
                dA.InsertCommand.Parameters.Add("@precio", SqlDbType.Float, 10, "precio");
                dA.InsertCommand.Parameters.Add("@resolucion", SqlDbType.VarChar, 50, "resolucion");

                Console.WriteLine("DATA ADAPTER CONFIGURADO CON EXITO");
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

            //Intento llenar la data table con los datos de la base de datos
            try
            {
                int i = dA.Fill(tabla);
                if (i != 0)
                {
                    Console.WriteLine("SE CARGO EL DATA TABLE CON EXITO");
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

            //INTENTO ACTUALIZAR LA BASE DE DATOS A TRAVES DEL DATA ADAPTER CON LOS DATOS DE LA TABLA

            try
            {
                dA.Update(tabla);

                Console.WriteLine("DATOS ACTUALIZADOS CON EXITO");
            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
            }

            //INTENTO LA ESCRITURA Y LECTURA DE ARCHIVOS .TXT Y .XML

            if (pantallas.Guardar("pantallas.txt", pantallas.ToString()))
            {
                Console.WriteLine("ARCHIVO CREADO CON EXITO");
            }
            else
            {
                Console.WriteLine("ERROR AL CREAR EL ARCHIVO");
            }

            string datos;

            if (pantallas.Leer("pantallas.txt", out datos))
            {
                Console.WriteLine(datos);
            }
            else
            {
                Console.WriteLine("ERROR AL LEER EL ARCHIVO");
            }

            Console.ReadKey(true);
            Console.Clear();

            if (Vendedora.GuardarXml("SmartPhone.xml",pantallas))
            {
                Console.WriteLine("VENDEDORA SERIALIZADA CON EXITO");
            }

            Vendedora v2 = new Vendedora();

            v2 = Vendedora.LeerXml("SmartPhone.xml");

            Console.WriteLine(v2.ToString());

            Console.ReadKey(true);
        }
    }
}
