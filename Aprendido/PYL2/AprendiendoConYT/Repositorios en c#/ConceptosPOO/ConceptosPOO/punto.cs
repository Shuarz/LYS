using System;
using System.Collections.Generic;
using System.Text;

namespace ConceptosPOO
{
    class punto
    {

        public punto(int x, int y)
        {
            this.x = x;

            this.y = y;

            contadorDeObjetos++;
           // Console.WriteLine($"coordenada x: {x}, coordenada y: {y}");

        }


        public punto()
        {
            this.x = 0;

            this.y = 0;

            contadorDeObjetos++;
           // Console.WriteLine("esto es el construtor por defecto");
        }

        public double distanciaHasta(punto otroPunto)
        {
            int xDif = this.x - otroPunto.x;

            int yDif = this.y - otroPunto.y;

            double distanciaPuntos = Math.Sqrt(Math.Pow(xDif, 2) + Math.Pow(yDif, 2));

            return distanciaPuntos;

        }

        public static int contadorDeObjetoss()
        {
            return contadorDeObjetos;

        }

        private int x, y;

        private static int contadorDeObjetos = 0;

    }
}
