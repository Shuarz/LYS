using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TareaEjercicio18
{
    public class Punto
    {
        private int x;
        private int y;

        #region constructores

        public Punto(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        #endregion


        #region metodos

        public int GetX()
        {
            return this.x;
        }

        public int GetY()
        {
            return this.y;
        }

        #endregion


    }
}
