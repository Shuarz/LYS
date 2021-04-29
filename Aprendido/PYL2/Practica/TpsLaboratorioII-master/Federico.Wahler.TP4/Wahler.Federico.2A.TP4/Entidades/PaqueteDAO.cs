using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Data;

namespace Entidades
{
    public static class PaqueteDAO
    {
        /// <summary>
        /// Evento relacionado en carga con base de datos
        /// </summary>
        public static event DelegadoDatoCargado DatoCargadoBaseDeDatos;

        /// <summary>
        /// Delegado relacionado en carga con base de datos
        /// </summary>
        /// <param name="mensaje">Detalle del error</param>
        public delegate void DelegadoDatoCargado(string mensaje);
        
        /// <summary>
        /// Atributos
        /// </summary>
        private static SqlCommand comando;
        private static SqlConnection conexion;

        /// <summary>
        /// Crea una instancia de la Clase PaqueteDAO
        /// </summary>
        static PaqueteDAO()
        {
            conexion = new SqlConnection(@"Server=localhost\MSSQLSERVER01;Database=master;Trusted_Connection=True;"); 
            comando = new SqlCommand("SELECT id, comida, tamaño FROM [HamburgueSav].[dbo].[Tabla_pedidos]", conexion);            
        }

        /// <summary>
        /// Inserta un paquete en la base de datos asociada a la aplicación
        /// </summary>
        /// <param name="p">Paquete a insertar</param>
        /// <returns>Retorno.
        public static bool Insertar(Paquete p)
        {
            bool retorno = true;

            comando.Connection = conexion;
            comando.CommandType = CommandType.Text;
            comando.CommandText = "INSERT INTO [HamburgueSav].[dbo].[Tabla_pedidos] (numeroPedido, trackingID, alumno) VALUES ('" + p.NumeroPedido
                + "', '" + p.TrackingID + "', 'Wahler, Federico')";

             
           PaqueteDAO.DatoCargadoBaseDeDatos("Pedido entregado, pulse aceptar para continuar");
           
            return retorno;
            
        }

        
    }
}
