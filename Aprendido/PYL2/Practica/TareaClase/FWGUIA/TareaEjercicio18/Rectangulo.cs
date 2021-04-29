using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio18
{
    public class Rectangulo
    {
        private float area;
        private float perimetro;

        //4 vértices del rectángulo
        private Punto vertice1;
        private Punto vertice2;
        private Punto vertice3;
        private Punto vertice4;

        #region constructor

        public Rectangulo(Punto vertice1, Punto vertice3)
        {
            this.vertice1 = vertice1;
            this.vertice3 = vertice3;
        }

        #endregion

        #region metodos getters

        public float Area()
        {
            int flag = 0;
            if (flag == 0)
            {
                int baseRectangulo = this.Base();
                int alturaRectangulo = this.Altura(this.vertice2);

                this.area = baseRectangulo * alturaRectangulo;
                flag = 1;
            }

            return this.area;
        }

        public float Perimetro()
        {
            int flag = 0;
            if (flag == 0)
            {
                int baseRectangulo = this.Base();
                int alturaRectangulo = this.Altura(this.vertice2);

                this.perimetro = (baseRectangulo + alturaRectangulo) * 2;
                flag = 1;
            }

            return this.area;


        }

        public int Base()
        {
            //Base
            int xVertice1 = Math.Abs(this.vertice1.GetX());
            int xVertice3 = Math.Abs(this.vertice3.GetX());
            int baseRectangulo = xVertice3 - xVertice1;

            return baseRectangulo;
        }


        public int Altura(Punto dos)
        {
            //Altura
            //Necesito que yVertice2 sea SIEMPRE positivo.

            int yVertice2 = Math.Abs(dos.GetY());
            int yVertice1 = Math.Abs(this.vertice1.GetY());
            int alturaRectangulo = yVertice2 - yVertice1;

            return alturaRectangulo;
        }
        #endregion



    }
}
