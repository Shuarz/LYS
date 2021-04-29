using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using EntidadesAbstractas;
using EntidadesInstanciables;
using Excepciones;


namespace TestsUnitarios
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void ListaAlumnosCorrecta()
        {
            Universidad u = new Universidad();
            Assert.IsNotNull(u.Alumnos);
        }

        [TestMethod] public void ValidarNacionalidadInvalidaExcepcion()
        {
            try
            {
                Alumno a1 = new Alumno(5, "Federico", "Sanchez", "20000000", Persona.ENacionalidad.Extranjero, Universidad.EClases.Legislacion);
                Assert.Fail("El DNI es incorrecto porque es extranjero. ");

            }
            catch (NacionalidadInvalidaException exception)
            {
                Assert.IsTrue(true);
            }

        }


        [TestMethod] public void ValidarDniInvalidoExcepcion()
        {
            try
            {
                Alumno a1 = new Alumno(5, "Federico", "Sanchez", "unodostres", Persona.ENacionalidad.Extranjero, Universidad.EClases.Legislacion);
                Assert.Fail("El DNI es incorrecto. Está en formato de letras y no numeros. ");
            }
            catch (DniInvalidoException exception)
            {
                Assert.IsTrue(true);
            }
        }



        [TestMethod] public void ValidarRepeticion()
        {
            Universidad universidadNueva = new Universidad();
            Alumno a1 = new Alumno(5, "Federico", "Sanchez", "39426432", Persona.ENacionalidad.Argentino, Universidad.EClases.SPD);
            Alumno a2 = new Alumno(5, "Federico", "Sanchez", "11111111", Persona.ENacionalidad.Argentino, Universidad.EClases.SPD);

            try
            {
                universidadNueva += a1;
                universidadNueva += a2;
                Assert.Fail("Mismo legajo. Y mismo tipo. Tiene que indicar error");
            }
            catch (AlumnoRepetidoException exception)
            {
                Assert.IsTrue(true);
            }
        }


        [TestMethod] public void ValidarValorNumerico()
        {
            Profesor p1 = new Profesor(1, "Jose", "Maria", "12345678", Persona.ENacionalidad.Argentino);
            Assert.IsInstanceOfType(p1.DNI, typeof(int));
        }



        [TestMethod] public void ValidarNulidadenAtributos()
        {
            Universidad universidadNueva = new Universidad();
            Alumno alumnoUno = new Alumno(6, "Federico", "Sanchez", "39426432", Persona.ENacionalidad.Argentino, Universidad.EClases.SPD);
            Profesor profesorUno = new Profesor(1, "Jose", "Maria", "16353423", Persona.ENacionalidad.Argentino);

            Assert.IsNotNull(universidadNueva.Alumnos);
            Assert.IsNotNull(universidadNueva.Instructores);
  
        }

        
    }
}
