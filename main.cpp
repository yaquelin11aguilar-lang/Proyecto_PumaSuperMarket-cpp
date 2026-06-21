/* UNIVERSIDAD NACIONAL AUTÓNOMA DE HONDURAS
FACULTAD DE CIENCIAS ECONÓMICAS, ADMINISTRATIVAS Y CONTABLES
DEPARTAMENTO DE INFORMÁTICA
DIA 044 Programación Básica
Proyecto: PUMA SUPER-MARKET
Grupo N°5
*/

#include <iostream>
#include <string>//PARA USAR LA FUNCION GETLINE Y MANEJO DE CADENAS
#include <cstdlib>// PARA USAR LA FUNCION SYSTEM("cls") PARA LIMPIAR PANTALLA
#include <windows.h>// PARA CONFIGURAR EL IDIOMA ESPAÑOL

using namespace std;

// FUNCIÓN: VALIDACIÓN DE EDAD PARA RESTRICCIÓN DE VENTA DE LICORES
bool esMayorDeEdad(int edad) {
    return edad >= 18;
}

// FUNCIÓN: CAPTURA LOS DATOS DEL CLIENTE SUS VALIDACIONES Y GESTION DE DESCUENTOS
// POR DÍA DE LA SEMANA

void DatosCliente(string &nombreCliente, int &edadCliente, int &tipoCliente, int &diaSemana) {
    cout << "=========================================================" << endl;
    cout << "               REGISTRO DE CLIENTE                       " << endl;
    cout << "=========================================================" << endl;
    
    cout << "Por favor ingrese su nombre: ";
    getline(cin, nombreCliente);

    // VALIDACION DE EDAD RAZONABLE 
    do {
        cout << "Ingrese su edad: ";
        cin >> edadCliente;
        if (edadCliente < 0 || edadCliente > 100) {
            cout << "Error: Edad no válida. Intente de nuevo.\n" << endl;
        }
    } while (edadCliente < 0 || edadCliente > 100);

    // VALIDACIÓN DEL TIPO DE CLIENTE
    do {
        cout << "Ingrese Tipo de Cliente (1. Estrella / 2. Regular / 3. Nuevo): ";
        cin >> tipoCliente;
        if (tipoCliente < 1 || tipoCliente > 3) {
            cout << "Error: Tipo inválido. Intente de nuevo.\n" << endl;
        }
    } while (tipoCliente < 1 || tipoCliente > 3);

    // VALIDACIÓN DEL DÍA DE LA SEMANA PARA DESCUENTOS
    do {
        cout << "Ingrese el día de hoy (1.Lunes / 2.Martes / 3.Miercoles / 4.Jueves / 5.Viernes / 6.Sabado / 7.Domingo): ";
        cin >> diaSemana;
        if (diaSemana < 1 || diaSemana > 7) {
            cout << "Error: Día no válido. Intente de nuevo.\n" << endl;
        }
    } while (diaSemana < 1 || diaSemana > 7);
}

// 3. FUNCIÓN: MENÚ PRINCIPAL 
void menuPrincipal() {
    cout << "=========================================================" << endl;
    cout << "             PUMA SUPER-MARKET - MENÚ DE ÁREAS           " << endl;
    cout << "=========================================================" << endl;
    cout << " [ ÁREA DE VERDURAS ]" << endl;
    cout << "   1. Tomates          (L.10.00 / Libra)" << endl;
    cout << "   2. Repollo          (L.15.00 / Libra)" << endl;
    cout << "   3. Papas            (L.17.00 / Libra)" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << " [ ÁREA DE CARNES ]" << endl;
    cout << "   4. Carne molida     (L.50.00 / Libra)" << endl;
    cout << "   5. Carne de cerdo   (L.70.00 / Libra)" << endl;
    cout << "   6. Carne para asar  (L.75.00 / Libra)" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << " [ ÁREA DE LICORES ]" << endl;
    cout << "   7. Cerveza nacional (L.50.00 / Unidad)" << endl;
    cout << "   8. Cerveza extranjera(L.80.00 / Unidad)" << endl;
    cout << "   9. Vino             (L.200.00 / Botella)" << endl;
    cout << "   10. Vodka           (L.100.00 / Botella)" << endl;
    cout << "=========================================================" << endl;
}

// FUNCIÓN PRINCIPAL
int main() {

    SetConsoleOutputCP(CP_UTF8); 
    SetConsoleCP(CP_UTF8);//CARACTERES EN ESPAÑOL

    // VARIABLES DE DATOS DEL CLIENTE
    string nombreCliente;
    int edadCliente = 0;
    int tipoCliente = 0;
    int diaSemana = 0;

    //VARIABLES DEL BUCLE DE SELECCIÓN DE PRODUCTOS
    int codigoProducto = 0;
    int cantidadProducto = 0;
    char continuarCompra = 's';

    //CAPTURA DE DATOS DEL CLIENTE
    DatosCliente(nombreCliente, edadCliente, tipoCliente, diaSemana);
    
    system("cls"); // LIMPIEZA DE PANTALLA PARA EMPEZAR EL PROCESO DE COMPRA

    // BIENVENIDA E INFORMACIÓN DE RESTRICCIÓN DE EDAD PARA LICORES

    cout << "Bienvenido/a " << nombreCliente << " a PUMA SUPER-MARKET!" << endl;
    if (!esMayorDeEdad(edadCliente)) {
        cout << "* NOTA: Al ser menor de 18 años, el area de licores estara bloqueada. *" << endl;
    }
    cout << "---------------------------------------------------------\n" << endl;

    // CICLO PRINCIPAL DE COMPRA
    do {
        menuPrincipal();
        
        cout << "\nIngrese el Código del producto que desea llevar (1-10): ";
        cin >> codigoProducto;

        // VALIDACIÓN DE CÓDIGOS DE PRODUCTO
        if (codigoProducto < 1 || codigoProducto > 10) {
            cout << "=> Error: Codigo de producto inexistente." << endl;
        } 
        // CONTROL DE RESTRICCIÓN DE LICORES (Códigos del 7 al 10)
        else if ((codigoProducto >= 7 && codigoProducto <= 10) && !esMayorDeEdad(edadCliente)) {
            cout << "\n[ RESTRICCION DE EDAD ]" << endl;
            cout << "=> Error: Venta prohibida. Usted es menor de edad y no puede comprar licores.\n" << endl;
        } 
        // SI EL CÓDIGO ES VÁLIDO Y NO HAY RESTRICCIÓN, SE PROCEDE A CAPTURAR LA CANTIDAD
        else {
            cout << "Ingrese la cantidad a llevar: ";
            cin >> cantidadProducto;
            
            // --- AQUÍ CONECTARÁN TUS COMPAÑEROS ---
            // Aquí es donde el encargado de "Cálculos y Carrito" meterá sus funciones
            // Ej: agregarAlCarrito(codigoProducto, cantidadProducto);
            cout << "\n[OK] Se agregaron " << cantidadProducto << " unidades del producto " << codigoProducto << " al carrito." << endl;
            // --------------------------------------
        }

        // CONSULTA PARA SEGUIR COMPRANDO O IR AL CIERRE DE CAJA
        cout << "\n¿Desea seguir agregando productos al carrito? (s/n): ";
        cin >> continuarCompra;
        
        system("cls");

    } while (continuarCompra == 's' || continuarCompra == 'S');

    // 3. CIERRE DE CAJA Y FACTURACIÓN
    cout << "=========================================================" << endl;
    cout << "               PROCEDIENDO AL CIERRE DE CAJA             " << endl;
    cout << "=========================================================" << endl;
    
    // --- AQUÍ CONECTARÁ TU COMPAÑERO DE FACTURACIÓN ---
    // Aquí se llamará a la función que procesa los subtotales, ISV (15% o 18%), 
    // descuentos por día, tipo de cliente, tercera edad, y hace el cambio a Dólares (L.24.5)
    // Ej: mostrarFacturaFinal(nombreCliente, tipoCliente, edadCliente, diaSemana);
    
    cout << "\n[Espacio reservado para la Factura Final]" << endl;
    cout << "Gracias por su compra en PUMA SUPER-MARKET." << endl;

    return 0;
}
==================================================
// FUNCIÓN: MOTOR DE DESCUENTOS (Responsable: Aldo - Analista de Costos)
// ------------------------------------------------------------
// Calcula el descuento en Lempiras correspondiente a UN producto
// individual de la compra. Se llama UNA VEZ POR CADA PRODUCTO
// que el cliente agrega al carrito.
//
// Parametros por VALOR (la funcion los usa, no los modifica):
//   tipoCliente          -> 1=Estrella, 2=Regular, 3=Nuevo
//   edadCliente          -> edad del cliente
//   diaSemana            -> 1=Lunes ... 7=Domingo
//   areaProducto         -> "Carnes", "Verduras" o "Licores"
//   nombreProducto       -> nombre exacto del producto
//   cantidad             -> unidades/libras/botellas de ESE producto
//   precioUnitario       -> precio por unidad de ESE producto
//   subtotal             -> precioUnitario * cantidad (de ESE producto)
//   numeroProductoEnArea -> que numero de producto DISTINTO es este
//                           dentro de su area (1=primero, 2=segundo...)
//                           OJO: este dato debe contar solo productos
//                           NUEVOS, no repetir el contador si el cliente
//                           ya habia comprado ese mismo producto antes.
//
// Parametro por REFERENCIA (aqui se devuelve el resultado):
//   descuentoTotal -> descuento en Lempiras aplicable a ESTE producto
// ============================================================
void calcularDescuentos(
    int tipoCliente,
    int edadCliente,
    int diaSemana,
    string areaProducto,
    string nombreProducto,
    int cantidad,
    double precioUnitario,
    double subtotal,
    int numeroProductoEnArea,
    double &descuentoTotal)
{
    descuentoTotal = 0;
 
    // 1) Descuento por tipo de cliente
    if (tipoCliente == 1 &&
        (areaProducto == "Carnes" || areaProducto == "Verduras"))
    {
        // Estrella: 4% en carnes y verduras
        descuentoTotal += subtotal * 0.04;
    }
    if (tipoCliente == 2 &&
        areaProducto == "Carnes")
    {
        // Regular: 3% en carnes
        descuentoTotal += subtotal * 0.03;
    }
    if (tipoCliente == 3 &&
        areaProducto == "Licores")
    {
        // Nuevo: 2% en licores
        descuentoTotal += subtotal * 0.02;
    }
 
    // 2) Lunes o Miercoles: 3% adicional sobre el subtotal del producto
    if (diaSemana == 1 || diaSemana == 3)
    {
        descuentoTotal += subtotal * 0.03;
    }
 
    // 3) Tercera edad (65+) los viernes: 10% adicional
    if (edadCliente >= 65 && diaSemana == 5)
    {
        descuentoTotal += subtotal * 0.10;
    }
 
    // 4) Segundo producto DISTINTO en Carnes: 50% sobre su subtotal
    if (areaProducto == "Carnes" && numeroProductoEnArea == 2)
    {
        descuentoTotal += subtotal * 0.50;
    }
 
    // 5) Six-pack de cerveza: L.10 por cada six-pack completo (6 unidades)
    if (nombreProducto == "Cerveza nacional" ||
        nombreProducto == "Cerveza extranjera")
    {
        int cantidadSixPacks = cantidad / 6; // division entera
        descuentoTotal += cantidadSixPacks * 10.0;
    }
}