namespace Archivos
{
    public interface IArchivo<T>
    {
        bool Guardar(string path, T datos);

        bool Leer(string path, out T datos);
    }
}
