using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace ClasesIntegrador
{
    public class ParaisoFiscal
    {
        private List<CuentaOffShore> _listadoCuentas;
        private eParaisosFiscales _lugar;
        public static int cantidadDeCuentas;
        public static DateTime fechaInicioActividades;

        static ParaisoFiscal()
        {
            cantidadDeCuentas = 0;
            fechaInicioActividades = DateTime.Now;
        }

        private ParaisoFiscal()
        {
            this._listadoCuentas = new List<CuentaOffShore>();
        }

        private ParaisoFiscal(eParaisosFiscales lugar) : this()
        {
            this._lugar = lugar;
        }

        public void MostrarParaiso()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendFormat("Fecha de inicio: {0}", fechaInicioActividades);
            sb.AppendLine();
            sb.AppendFormat("Locación: {0}", this._lugar);
            sb.AppendLine();
            sb.AppendFormat("Cantidad de 'cuentitas': {0}", cantidadDeCuentas);
            sb.AppendLine();
            sb.AppendLine("************ Listado de cuentas Cuentas Offshores************");
            foreach (CuentaOffShore i in this._listadoCuentas)
            {
                if (i != null)
                {
                    sb.AppendFormat(Cliente.RetornarDatos(i.Dueño));
                    sb.AppendFormat("Numero de cuenta: {0}", (int)i);
                    sb.AppendFormat("Saldo: {0}", i.Saldo);
                }

                Console.WriteLine(sb.ToString());
            }
        }

        public static implicit operator ParaisoFiscal(eParaisosFiscales epf)
        {
            ParaisoFiscal pf = new ParaisoFiscal(epf);

            return pf;
        }

        public static bool operator ==(ParaisoFiscal pf, CuentaOffShore cos)
        {
            bool valido = false;

            if ((object)pf != null && (object)cos != null)
            {
                foreach (CuentaOffShore aux in pf._listadoCuentas)
                {
                    if (aux == cos)
                    {
                        valido = true;
                    }
                }
            }

            return valido;
        }

        public static bool operator !=(ParaisoFiscal pf, CuentaOffShore cos)
        {
            return !(pf == cos);
        }

        public static ParaisoFiscal operator -(ParaisoFiscal pf, CuentaOffShore cos)
        {
            if (pf == cos)
            {
                cantidadDeCuentas--;
                pf._listadoCuentas.Remove(cos);
                Console.WriteLine("Se quito la cuenta del paraiso...");
            }
            else
            {
                Console.WriteLine("La cuenta no existe en el paraiso");
            }

            return pf;
        }

        public static ParaisoFiscal operator +(ParaisoFiscal pf, CuentaOffShore cos)
        {
            if (pf != cos)
            {
                cantidadDeCuentas++;
                pf._listadoCuentas.Add(cos);
                Console.WriteLine("Se agrego la cuenta al paraiso...");
            }
            else
            {
                foreach (CuentaOffShore aux in pf._listadoCuentas)
                {
                    if (aux == cos)
                    {
                        cos.Saldo += aux.Saldo;
                        Console.WriteLine("Se actualizo el saldo de la cuenta");
                    }
                }
            }

            return pf;
        }

    }
}
