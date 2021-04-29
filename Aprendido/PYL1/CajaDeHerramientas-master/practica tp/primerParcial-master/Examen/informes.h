#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
int informes_clienteConMasVentasPorEstado(void* arrayVentasVoid, int lenVentas,void* arrayClientesVoid, int lenClientes, int estado);
int informes_clienteConMasVentas(void* arrayVentasVoid, int lenVentas,void* arrayClientesVoid, int lenClientes);
int informes_clienteConMasAfichesACobrar(void* arrayVentasVoid, int lenVentas,void* arrayClientesVoid, int lenClientes);
int informes_clienteConMasAfiches(void* arrayVentasVoid, int lenVentas,void* arrayClientesVoid, int lenClientes);
int informes_zonaConMenosAfiches(void* arrayVentasVoid, int lenVentas);
int informes_clientesConMenosDeTantosAfiches(   void* arrayVentasVoid, int lenVentas,
                                                void* arrayClientesVoid, int lenClientes, int cantidadAfiches);
int informes_cantidadAfichesPorZona(void* arrayVentasVoid, int lenVentas);
int informes_listaDeVentasPorZona(void* arrayVentasVoid, int lenVentas);
int informes_cantidadTotalDeAfiches(void* arrayVentasVoid, int lenVentas, int *cantidadTotalAfiches);
int informes_cantidadTotalClientes(void* arrayClientesVoid, int lenClientes, int *cantidadTotalClientes);
int informes_cantidadAfichesPorCliente(void* arrayVentasVoid, int lenVentas, void* arrayClientesVoid, int lenClientes);
/*
int informar_sortClientePorApellidoNombre(void* arrayClientesVoid, int lenClientes);
int informar_sortClientePorCuit(void* arrayClientesVoid, int lenClientes);
int informar_ventasMayorMenorAfichesNumero(void *arrayVentasVoid, int lenVentas, int *cantidadVentas,int mayorMenor, int numeroAfiches);
int informar_cantidadTotalDeVentas(void* arrayVentasVoid, int lenVentas, int *cantidadTotalVentas);
int informar_promedioAfichesPorVenta(void* arrayVentasVoid, int lenVentas, float *promedio);
int informar_ventasSuperaOrNoPromedioAfiches(void* arrayVentasVoid,int lenVentas,int *cantidadVentas,int SuperaOrNo);
int informar_mostrarVentaPorEstado(void* arrayVentasVoid, int len, int estado);
int informar_mostrarVentaPorZona(void* arrayVentasVoid, int len, int zona);
int informar_mostrarVentaPorEstadoAndZona(void* arrayVentasVoid, int len, int estado ,int zona);
int informar_ventaConMasAfiches(void* arrayVentasVoid, int lenVentas);
int informar_mostrarClientesPorZona(void* arrayClientesVoid, int lenClientes, void* arrayVentasVoid, int lenVentas, int zona);
int informar_afichesPorZona(void* arrayVentasVoid, int lenVentas, int zona);*/
#endif
