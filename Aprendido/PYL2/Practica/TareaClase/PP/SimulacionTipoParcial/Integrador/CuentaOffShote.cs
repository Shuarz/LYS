using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Integrador
{
    public class CuentaOffShore
    {
        private Cliente _dueño;
        private int _numeroCuenta;
        private double _saldo;

        public Cliente Dueño
        {
            get
            {
                return this._dueño;
            }
        }
        public double Saldo
        {
            get
            {
                return this._saldo;
            }
            set
            {
                this._saldo = value;
            }
        }


        public CuentaOffShore(Cliente dueño, int numero, double saldoInicial)
        {
            this._dueño = dueño;
            this._numeroCuenta = numero;
            this._saldo = saldoInicial;
        }

        public CuentaOffShore(string nombre, eTipoCliente tipo, int numero, double saldoInicial) : this(new Cliente(tipo, nombre), numero, saldoInicial)
        {

        }

        public static explicit operator int(CuentaOffShore cos)
        {
            return cos._numeroCuenta;
        }

        public static bool operator !=(CuentaOffShore cos1, CuentaOffShore cos2)
        {
            return !(cos1 == cos2);
        }

        public static bool operator ==(CuentaOffShore cos1, CuentaOffShore cos2)
        {
            bool valido = false;

            if ((object)cos1 != null && (object)cos2 != null)
            {
                string aliasC1 = cos1._dueño.GetAlias();
                string aliasC2 = cos2._dueño.GetAlias();

                if (cos1._numeroCuenta == cos2._numeroCuenta && aliasC1 == aliasC2)
                {
                    valido = true;
                }
            }

            return valido;
        }
    }
}
