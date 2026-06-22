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

// FUNCIÓN: CAPTURA LOS DATOS DEL CLIENTE SUS VALIDACIONES Y DIA DE LA SEMANA
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
            cout << "Error: Tipo inválido. Intente de nuevo." << endl;
        }
    } while (tipoCliente < 1 || tipoCliente > 3);

    // VALIDACIÓN DEL DÍA DE LA SEMANA PARA DESCUENTOS
    do {
        cout << "Ingrese el día de hoy (1.Lunes / 2.Martes / 3.Miercoles / 4.Jueves / 5.Viernes / 6.Sabado / 7.Domingo): ";
        cin >> diaSemana;
        if (diaSemana < 1 || diaSemana > 7) {
            cout << "Error: Día no válido. Intente de nuevo." << endl;
        }
    } while (diaSemana < 1 || diaSemana > 7);
}

// FUNCIÓN: MENÚ PRINCIPAL 
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


//FUNCIÓN DESCUENTOS
void calcularDescuentosGlobales(
   int tipoCliente, int diaSemana, int edadCliente, int totalUnidadesCarne, int totalCervezas,
   double subtotalVerduras, double subtotalCarnes, double subtotalLicores, 
   double subtotalCervezaN, double subtotalCervezaE, double &totalDescuentosAplicados)
{ 
    totalDescuentosAplicados = 0.0;
    double descVerduras = 0.0;
    double descCarnes = 0.0;
    double descLicoresGeneral = 0.0; 
    double descCervezaN = 0.0;
    double descCervezaE = 0.0;

    // REGLA 1, 2 y 3: Descuentos por Tipo de Cliente (Se calculan sobre el subtotal acumulado)
    switch (tipoCliente) {
        case 1: 
            descVerduras += subtotalVerduras * 0.04;
            descCarnes += subtotalCarnes * 0.04;
            break;
        case 2: 
            descCarnes += subtotalCarnes * 0.03;
            break;
        case 3: 
            descLicoresGeneral += subtotalLicores * 0.02;
            descCervezaN += subtotalCervezaN * 0.02;
            descCervezaE += subtotalCervezaE * 0.02;
            break;
    }

    // REGLA 4: Si es Lunes (1) o Miércoles (3), 3% en todas las áreas acumuladas
    if (diaSemana == 1 || diaSemana == 3) {
        descVerduras += subtotalVerduras * 0.03;
        descCarnes += subtotalCarnes * 0.03;
        descLicoresGeneral += subtotalLicores * 0.03;
        descCervezaN += subtotalCervezaN * 0.03;
        descCervezaE += subtotalCervezaE * 0.03;
    }

    // AREGLA 5: Para la mitad de precio en la segunda carne.
    if (totalUnidadesCarne >= 2) {
        int parejasDeCarne = totalUnidadesCarne / 2;
        double precioBasePromedio = subtotalCarnes / totalUnidadesCarne; 
        descCarnes += parejasDeCarne * (precioBasePromedio * 0.50);
    }

    // REGLA 6: Si es Viernes (5) y el cliente tiene 65 años o más, 10% en todo
    if (diaSemana == 5 && edadCliente >= 65) {
        descVerduras += subtotalVerduras * 0.10;
        descCarnes += subtotalCarnes * 0.10;
        descLicoresGeneral += subtotalLicores * 0.10;
        descCervezaN += subtotalCervezaN * 0.10;
        descCervezaE += subtotalCervezaE * 0.10;
    }

    // REGLA 7: Si lleva 6 cervezas o más, descuento fijo de 10 Lps
    if (totalCervezas >= 6) {
        if (subtotalCervezaN > 0) descCervezaN += 10.00;
        if (subtotalCervezaE > 0) descCervezaE += 10.00;
    }

    // ACUMULACIÓN FINAL DEL DESCUENTO
    totalDescuentosAplicados = descVerduras + descCarnes + descLicoresGeneral + descCervezaN + descCervezaE;
}

// FUNCIÓN: CALCULA EL ISV SEGÚN EL ÁREA DEL PRODUCTO
double calcularISV(double subtotalConDescuento, bool esLicor ) { 
    double tasaISV = 0.0;
    if (esLicor) {
        tasaISV = 0.18; // 18% para licores
    } else {
        tasaISV = 0.15; // 15% general
    }
    return tasaISV = subtotalConDescuento * tasaISV;
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
    string nombreProducto;
    string areaProducto;
    int codigoProducto = 0;
    int cantidadProducto = 0;
    char continuarCompra = 's';
    double precioProducto = 0.00;

//ACUMULADORES
    double subtotalVerduras = 0.00;
    double subtotalCarnes = 0.00;
    double subtotalLicores = 0.00;
    double subtotalCervezaN = 0.00;
    double subtotalCervezaE = 0.00;
    double subtotalGeneral = 0.00;
    double totalDescuentos = 0.0;
//CONTADORES DE LIBRAS/UNIDAD
    int contadorLibrasCarne = 0;
    int contadorCervezasN = 0;
    int contadorCervezasE = 0;

//FUNCIÓN PARA LOS DATOS DEL CLIENTE
    DatosCliente(nombreCliente, edadCliente, tipoCliente, diaSemana);
// LIMPIEZA DE PANTALLA PARA EMPEZAR EL PROCESO DE COMPRA
    system("cls"); 
// CICLO PRINCIPAL DE COMPRA
    do {
// BIENVENIDA E INFORMACIÓN DE RESTRICCIÓN DE EDAD PARA LICORES
        cout << "Bienvenido/a " << nombreCliente << " a PUMA SUPER-MARKET!" << endl;
            if (!esMayorDeEdad(edadCliente)) {
        cout << "* NOTA: Al ser menor de 18 años, el área de licores estara bloqueada. *" << endl;
        }
        cout << "---------------------------------------------------------" << endl;
// MOSTRAR EL MENÚ PRINCIPAL DE PRODUCTOS
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
// SI EL CÓDIGO ES VÁLIDO Y NO HAY RESTRICCIÓN, SE PROCEDE A PREGUNTAR LA CANTIDAD
        else {
            cout << "Ingrese la cantidad a llevar: ";
            cin >> cantidadProducto;
// CILCO PARA OBTENER LOS PRODUCTOS
    switch (codigoProducto) {
//ÁREA DE VERDURAS
        case 1: 
            nombreProducto = "Tomates";
            precioProducto = 10.00; 
            subtotalVerduras += (precioProducto * cantidadProducto); 
        break;
        case 2: 
            nombreProducto = "Repollo"; 
            precioProducto = 15.00;
            subtotalVerduras += (precioProducto * cantidadProducto); 
        break;
        case 3: 
            nombreProducto = "Papas";
            precioProducto = 17.00; 
            subtotalVerduras += (precioProducto * cantidadProducto); 
        break;
//ÁREA DE CARNES
        case 4: 
            nombreProducto = "Carne molida"; precioProducto = 50.00;
            subtotalCarnes += (precioProducto * cantidadProducto); 
            contadorLibrasCarne += cantidadProducto; //ACUMULA LAS LIBRAS PARA LA PROMOCIÓN DEL 50% LA SEGUNDA
        break;
        case 5: 
            nombreProducto = "Carne de cerdo"; precioProducto = 70.00;
            subtotalCarnes += (precioProducto * cantidadProducto); 
            contadorLibrasCarne += cantidadProducto;
        break;
        case 6: 
            nombreProducto = "Carne para asar"; precioProducto = 75.00;
            subtotalCarnes += (precioProducto * cantidadProducto); 
            contadorLibrasCarne += cantidadProducto; 
        break;
//ÁREA DE LICORES
        case 7: 
            nombreProducto = "Cerveza nacional";
            precioProducto = 50.00; // CervezaNacional (unidad)
            subtotalCervezaN += (precioProducto * cantidadProducto);
            contadorCervezasN += cantidadProducto;
        break;
        case 8: 
            nombreProducto = "Cerveza extranjera";
            precioProducto = 80.00;
            subtotalCervezaE += (precioProducto * cantidadProducto); 
            contadorCervezasE += cantidadProducto;
        break;
        case 9: 
            nombreProducto = "Vino";
            precioProducto = 200.00; // Vino (botella)
            subtotalLicores += precioProducto * cantidadProducto; 
        break;
        case 10: 
            nombreProducto = "Vodka";
            precioProducto = 100.00; // Vodka (botella)
            subtotalLicores += precioProducto * cantidadProducto; 
        break;
// CÓDIGOS INVÁLIDOS (CASO POR DEFECTO)
        default: 
        nombreProducto = "Código inválido";
        precioProducto = 0.00; 
        break;// Código inválido
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
    }cout << "| Área del producto | : " << areaProducto << endl;
            
// GESTION DE CANTIDADES (LIBRAS, UNIDADES Y BOTELLAS)
    if (codigoProducto >= 1 && codigoProducto <= 6) {
        cout << "Usted Selecciono: " << cantidadProducto << " libras de " << nombreProducto << "." << endl;
    } else if (codigoProducto >= 7 && codigoProducto <= 8) {
        cout << "Usted Selecciono: " << cantidadProducto << " unidades de " << nombreProducto << "." << endl;
    } else if (codigoProducto >= 9 && codigoProducto <= 10) { cout << "Usted Selecciono: " << cantidadProducto 
    << " botellas de " << nombreProducto << "." << endl;
    }
        cout << "[OK] Se agregaron " << cantidadProducto << " unidades del producto " << codigoProducto << " al carrito." << endl;
}
// CONSULTA PARA SEGUIR COMPRANDO O IR AL CIERRE DE CAJA
        cout << "\n¿Desea seguir agregando productos al carrito? (s/n): ";
        cin >> continuarCompra;
        system("cls");

    } while (continuarCompra == 's' || continuarCompra == 'S');

    subtotalGeneral = subtotalVerduras + subtotalCarnes + subtotalLicores + subtotalCervezaN + subtotalCervezaE;
    cout << "=========================================================" << endl;
    cout << "Subtotal General: L." << subtotalGeneral << endl;

// CREAMOS LA VARIABLE PARA EVALUAR CÚAL CERVEZA SE COMPRO MÁS
    int maxCervezas = 0;
    if (contadorCervezasN > contadorCervezasE) {
        maxCervezas = contadorCervezasN;
    } else {
        maxCervezas = contadorCervezasE;
    }
    
//DESGLOSE DE DESCUENTOS
    calcularDescuentosGlobales(tipoCliente, diaSemana, edadCliente, contadorLibrasCarne, maxCervezas,
                               subtotalVerduras, subtotalCarnes, subtotalLicores, 
                               subtotalCervezaN, subtotalCervezaE, totalDescuentos);

    subtotalGeneral = subtotalVerduras + subtotalCarnes + subtotalLicores + subtotalCervezaN + subtotalCervezaE;
    
    cout << "=========================================================" << endl;
    cout << "Subtotal General Bruto: L." << subtotalGeneral << endl;
    cout << "Total Descuentos Aplicados: L." << totalDescuentos << endl;
    cout << "Subtotal con Descuento: L." << (subtotalGeneral - totalDescuentos) << endl;
    cout << "=========================================================" << endl;

// FACTURACIÓN
    double totalISV        = 0.0;
    double subtotalConDescuento = subtotalGeneral - totalDescuentos;

    // CALCULAMOS EL ISV SEPARADO POR ÁREAS (Carnes/Verduras usa 15%, Licores usa 18%)
    double subtotalNormal = subtotalVerduras + subtotalCarnes;
    double subtotalAlcohol = subtotalLicores + subtotalCervezaN + subtotalCervezaE;

    // Aquí calculamos el ISV total combinando ambas tasas
    totalISV = calcularISV(subtotalNormal, false) + calcularISV(subtotalAlcohol, true);
    
    // LLAMADA A LA FACTURA (Pasando el totalISV ya calculado correctamente)
    imprimirFactura(nombreCliente, tipoCliente, edadCliente,
                    subtotalGeneral, totalDescuentos, totalISV);

    return 0;
}