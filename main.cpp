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
    string nombreProducto;
    string areaProducto;

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
            
            // OBTENER EL PRECIO SEGÚN EL CÓDIGO DE PRODUCTO
            double precioProducto = 0.00;
            switch (codigoProducto) {
                case 1: 
                nombreProducto = "Tomates";
                precioProducto = 10.00; break; // Tomates (lb)
                case 2: 
                nombreProducto = "Repollo"; 
                precioProducto = 15.00; break; // Repollo (lb)
                case 3: 
                nombreProducto = "Papas";
                precioProducto = 17.00; break; // Papas (lb)
                case 4: 
                nombreProducto = "Carne molida";
                precioProducto = 50.00; break; // CarneMolida (lb)
                case 5: 
                nombreProducto = "Carne de cerdo";
                precioProducto = 70.00; break; // CarneCerdo (lb)
                case 6: 
                nombreProducto = "Carne para asar";
                precioProducto = 75.00; break; // CarneParaAsar (lb)
                case 7: 
                nombreProducto = "Cerveza nacional";
                precioProducto = 50.00; break; // CervezaNacional (unidad)
                case 8: 
                nombreProducto = "Cerveza extranjera";
                precioProducto = 80.00; break; // CervezaExtranjera (unidad)
                case 9: 
                nombreProducto = "Vino";
                precioProducto = 200.00; break; // Vino (botella)
                case 10: 
                nombreProducto = "Vodka";
                precioProducto = 100.00; break; // Vodka (botella)
                default: 
                nombreProducto = "Código inválido";
                precioProducto = 0.00; break;// Código inválido
            }

            // CLASIFICACION DEL ÁREA QUE PERTENECE CADA CODIGO (PRODUCTO)
            if (codigoProducto >= 1 && codigoProducto <= 3) {
                areaProducto = "Verduras";
            } else if (codigoProducto >= 4 && codigoProducto <= 6) {
                areaProducto = "Carnes";
            } else if (codigoProducto >= 7 && codigoProducto <= 10) {
                areaProducto = "Licores";
            } else {
                areaProducto = "Desconocida";
            }
            cout << "|°.- Área del producto -.°| : " << areaProducto << endl;
            
            // GESTION DE CANTIDADES (LIBRAS, UNIDADES Y BOTELLAS)
             if (codigoProducto >= 1 && codigoProducto <= 6) {
                cout << "Selecciono: " << cantidadProducto 
                     << " libras de " << nombreProducto << "." << endl;
            } else if (codigoProducto >= 7 && codigoProducto <= 8) {
                cout << "Selecciono: " << cantidadProducto 
                     << " unidades de " << nombreProducto << "." << endl;
            } else if (codigoProducto >= 9 && codigoProducto <= 10) {
                cout << "Selecciono: " << cantidadProducto 
                     << " botellas de " << nombreProducto << "." << endl;
            }

            // CALCULO DEL SUBTOTAL DEL PRODUDUCTO
            double subtotalProducto = precioProducto * cantidadProducto;
            cout << "|°.- Subtotal por este producto -.°| : L." << subtotalProducto << endl;
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