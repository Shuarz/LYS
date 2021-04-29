using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Entidades;

namespace TestsUnitarios
{
    [TestClass]
    public class UnitTest1
    {
        /// <summary>
        /// Comprueba que la lista de paquetes de un pedido esté instanciada
        /// </summary>
        [TestMethod]
        public void ListaDePaquetesNula()
        {
            Hamburgueseria c = new Hamburgueseria();
            Assert.IsNotNull(c.Paquetes);      
        }

        /// <summary>
        /// Comprueba que no se pueden cargar dos paquetes con el mismo trackingID y, al intentar hacerlo, que se lance una
        /// excepción del tipo TrackingIdRepetidoException 
        /// </summary>
        [TestMethod]
        public void DosPaquetesConMismoTrackingID()
        {
            Hamburgueseria c = new Hamburgueseria();
            Paquete paq1 = new Paquete("Hamburguesa con queso", "1");
            Paquete paq2 = new Paquete("Helado", "1");
            
            try
            {
                c += paq1;
                c += paq2;
                Assert.Fail("Error. Carga dos paquetes con el mismo TrackingID");
            }
            catch(Exception e)
            {
                Assert.IsInstanceOfType(e, typeof(TrackingIdRepetidoException));
            }
        }
    }
}
