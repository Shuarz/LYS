using Entidades;
using WindowsForms;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Data.SqlClient;
using System.Data;

namespace TestUnitarios
{
    [TestClass]
    public class TestUnitarios
    {
        /// <summary>
        /// Pasa el test si los productos son iguales
        /// </summary>
       [TestMethod]
        public void ComprobarFuncionamientoProductoIgualProducto()
        {
            bool iguales;
            SmartPhone s1 = new SmartPhone(1, "Galaxy Core", 240, "Apple", ESistemaOperativo.iOS, EMemoria.GB32);
            SmartPhone s2 = new SmartPhone(1, "Galaxy Plus", 220, "Samsung", ESistemaOperativo.Android, EMemoria.GB16);

            iguales = s1 == s2;
                
            Assert.IsTrue(iguales);
        }

        /// <summary>
        /// Pasa el test si la serializacion se realiza correctamente
        /// </summary>
        [TestMethod]
        public void ComprobarSerializacion()
        {
            Vendedora v = new Vendedora();

            Assert.IsTrue(Vendedora.GuardarXml("SmartPhone.xml",v));
        }
        
        /// <summary>
        /// Pasa el test si la conexion con la base de datos se realiza correctamente
        /// </summary>
        [TestMethod]
        public void ComprobarConexionBaseDeDatos()
        {
            SqlConnection conexion = new SqlConnection(Properties.Settings.Default.conexionBD);
           
            conexion.Open();
            
            Assert.IsTrue(conexion.State == ConnectionState.Open);
        }
    }
}
