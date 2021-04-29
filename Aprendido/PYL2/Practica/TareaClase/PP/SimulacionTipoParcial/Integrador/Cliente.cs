using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Integrador
{
    public class Cliente
    {
        private string _aliasParaIncognito;
        private string _nombre;
        private eTipoCliente _tipoDeCliente;

        private Cliente()
        {
            this._nombre = "NN";
            this._aliasParaIncognito = "Sin alias";
            this._tipoDeCliente = eTipoCliente.SinTipo;
        }

        public Cliente(eTipoCliente tipoCliente) : this()
        {
            this._tipoDeCliente = tipoCliente;
        }

        public Cliente(eTipoCliente tipoCliente, string nombre) : this(tipoCliente)
        {
            this._nombre = nombre;
        }

        private void CrearAlias()
        {
            Random numero = new Random();
            eTipoCliente tipo;
            tipo = (eTipoCliente)numero.Next(0, 4);
            this._aliasParaIncognito = Convert.ToString(numero.Next(1000, 9999)) + tipo;
        }

        public string GetAlias()
        {
            string alias = this._aliasParaIncognito;
            if (alias == "Sin alias")
            {
                CrearAlias();
            }

            return this._aliasParaIncognito;
        }

        private string RetornarDatos()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendFormat("Nombre: {0}", this._nombre);
            sb.AppendLine();
            sb.AppendFormat("Tipo: {0}", this._tipoDeCliente);
            sb.AppendLine();
            sb.AppendFormat("Alias: {0}", this._aliasParaIncognito);
            sb.AppendLine();

            return Convert.ToString(sb);
        }

        public static string RetornarDatos(Cliente unCliente)
        {
            return unCliente.RetornarDatos();
        }


    }
}
