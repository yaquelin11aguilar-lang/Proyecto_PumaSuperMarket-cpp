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

// Impuestos, Conversión y Facturación
// FUNCIÓN: CALCULA EL ISV SEGÚN EL ÁREA DEL PRODUCTO
double calcularISV(double subtotalConDescuento, bool esLicor) { 
    double tasaISV = 0.0;
    if (esLicor) {
        tasaISV = 0.18; // 18% para licores
    } else {
        tasaISV = 0.15; // 15% general
    }
    return subtotalConDescuento * tasaISV;
}

// FUNCIÓN: CONVIERTE LEMPIRAS A DÓLARES
double convertirADolares(double totalLempiras, double tipoCambiosUSD) {
    return totalLempiras / tipoCambiosUSD; // Conversión a dólares usando la tasa fija
}

// FUNCIÓN: IMPRIME LA FACTURA FINAL
void imprimirFactura (const string &nombreCliente, int tipoCliente, int edadCliente,
                     double subtotalBruto, double &totalDescuentos, double &totalISV) {

    const double tipoCambiosUSD = 24.5;

    double subtotalConDescuento = subtotalBruto - totalDescuentos;
    double totalLempiras = subtotalConDescuento + totalISV;
    double totalDolares = convertirADolares(totalLempiras, tipoCambiosUSD);

    // TIPO DE CLIENTE EN TEXTO
    string tipoClienteStr;
    switch (tipoCliente) {
        case 1: tipoClienteStr = "Estrella"; break;
        case 2: tipoClienteStr = "Regular";  break;
        case 3: tipoClienteStr = "Nuevo";    break;
        default: tipoClienteStr = "Desconocido"; break;
    }

    cout << "\n=========================================================" << endl;
    cout << "          PUMA SUPER-MARKET - FACTURA FINAL              " << endl;
    cout << "=========================================================" << endl;
    cout << " Cliente    : " << nombreCliente                           << endl;
    cout << " Tipo       : " << tipoClienteStr                          << endl;
    cout << " Edad       : " << edadCliente << " años"                  << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << " Subtotal bruto       : L." << subtotalBruto               << endl;
    cout << " (-) Descuentos       : L." << totalDescuentos             << endl;
    cout << " Subtotal con desc.   : L." << subtotalConDescuento        << endl;
    cout << " (+) ISV              : L." << totalISV                    << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << " TOTAL A PAGAR (L.)   : L." << totalLempiras               << endl;
    cout << " TOTAL A PAGAR (USD)  : $" << totalDolares                 << endl;
    cout << "=========================================================" << endl;
    cout << "   Gracias por su compra en PUMA SUPER-MARKET, "
         << nombreCliente << "!"                                         << endl;
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
    double subtotalTotal   = 0.0;
    double totalDescuentos = 0.0;
    double totalISV        = 0.0;

    /* PENDIENTE - conectar con Integrante 3:
    Dentro del bucle do-while, después de que calcule subtotalConDescuentoProducto:
    bool esLicor = (codigoProducto >= 7 && codigoProducto <= 10);
    totalISV += calcularISV(subtotalConDescuentoProducto, esLicor);
    */

    imprimirFactura(nombreCliente, tipoCliente, edadCliente,
                    subtotalTotal, totalDescuentos, totalISV);

    return 0;
}