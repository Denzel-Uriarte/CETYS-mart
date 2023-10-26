#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <windows.h>

using namespace std;

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   // Permitir cambio de color de texto en consola
    srand((unsigned)time(NULL));   // Elegir una raiz aleatoria para las funciones rand()

    float compra = 0, compraTotal = 0, total = 0, presupuesto, descuentoCupon, valorAgregado, cliente = 0, clienteTotal = 0, clienteIndividual = 0, productosCliente;
    int i = 1, j = 1, k = 1, eleccion, poderRezador, terminar = 1, escape, mentira;
    string scan;
    while (true)
    {
        compra = 0; compraTotal = 0; total = 0; cliente = 0; clienteTotal = 0;   // Reiniciar los valores en caso de repeticion
        clienteIndividual = 0; productosCliente; i = 1; j = 1; k = 1; terminar = 1; 
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Cambia el color de la consola a cyan
        cout << "Bienvenido a la CETYS-mart!" << endl;

        this_thread::sleep_for(chrono::seconds(1));
        cout << endl;
        SetConsoleTextAttribute(hConsole, 7);   // Regresar el color de la consola a normal
        cout << "Dame tu presupuesto para este carrito (-1 para presupuesto ilimitado)" << endl;
        cout << "$";
        cin >> presupuesto;
        cout << endl;
        // Seguir comprando productos mientras el total sea menor que el presupuesto, o si el presupuesto es ilimitado
        while ((compraTotal <= presupuesto) || (presupuesto == -1)) {
            cout << "Compra " << i << endl;
            cout << "Cuanto cuesta esta compra? " << (presupuesto == -1 ? " (-1 para terminar)" : "") << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            cout << "$";
            cin >> compra;
            SetConsoleTextAttribute(hConsole, 7);
            if (compra == -1) {
                break;
            }
            cout << endl;
            compraTotal = compraTotal + compra;
            i++;
        }

        if (compraTotal >= presupuesto && presupuesto != -1) {   // Si total excede el presupuesto y este no es ilimitado
            cout << endl;
            this_thread::sleep_for(chrono::seconds(1));

            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            cout << "Parece que te haz excedido de tu presupuesto! Tienes diversas opciones para poder pagar los $" << (compraTotal - presupuesto) << " faltantes:" << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "1: Credito, tendra intereses" << endl;
            cout << "2: Llamar a un familiar" << endl;
            cout << "3: Rezar" << endl;
            cout << "4: Usar cupon viejo" << endl;
            cout << "5: No pagar lo restante, no podras comprar el ultimo producto" << endl;
            cout << "6: Aumentar el presupuesto" << endl;
            cout << "(7: correr)" << endl;
            cout << "8: Trabajar" << endl;
            cout << "9: Mentir" << endl;
            cout << endl;
            cout << "Tu eleccion: ";
            cin >> eleccion;
            cout << endl;
            this_thread::sleep_for(chrono::seconds(1));
            switch (eleccion) {

            case 1:   // Pago con credito
                cout << "Elegiste pagar el extra con creditos." << endl;
                cout << "El interes sera de ";
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                cout << "10%";
                SetConsoleTextAttribute(hConsole, 7);
                cout << ", tendras hasta el fin del mes para pagarlo, o el interes subira." << endl;
                cout << endl;
                while (true) {   // Mantener el ciclo de compras hasta que el usuario lo termine
                    cout << "Compra " << i << endl;
                    cout << "Cuanto cuesta esta compra? (-1 para terminar)" << endl;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                    cout << "$";
                    cin >> compra;
                    SetConsoleTextAttribute(hConsole, 7);
                    if (compra == -1) {
                        break;
                    }
                    cout << endl;
                    compraTotal = compraTotal + compra;
                    i++;
                }
                cout << endl;
                cout << "Haz terminado tu compra!" << endl;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "A ser pagado en efectivo: $" << presupuesto << endl;
                cout << "A ser pagado en creditos con intereses aplicados: $" << ((compraTotal - presupuesto) * 1.1) << endl;
                cout << "Por lo que tu nuevo total por " << i << " productos es de : $" << (presupuesto + ((compraTotal - presupuesto) * 1.1)) << endl;
                break;

            case 2:   // Llamar a un familiar
                cout << "Ring..." << endl;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "Ring..." << endl;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "Ring!" << endl;
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "Mama: \"cuanto dinero ocupas mijo? yo tengo 1000\"" << endl;
                cout << endl;
                if ((compraTotal - 1000) < presupuesto) {
                    cout << "Parece que mama te podra aportar 1000." << endl;
                    cout << endl;
                    while (true) {
                        cout << "Compra " << i << endl;
                        cout << "Cuanto cuesta esta compra? (-1 para terminar)" << endl;
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                        cout << "$";
                        cin >> compra;
                        SetConsoleTextAttribute(hConsole, 7);
                        if (compra == -1) {
                            break;
                        }
                        cout << endl;
                        compraTotal = compraTotal + compra;
                        i++;
                    }
                }
                else {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    cout << "Parece que ni con los 1000 podras alcanzar el producto." << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    cout << "No se contara tu ultima compra." << endl;
                    compraTotal = compraTotal - compra;
                    i--;
                }
                cout << endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                cout << "Haz terminado tu compra!" << endl;
                SetConsoleTextAttribute(hConsole, 7);
                this_thread::sleep_for(chrono::seconds(1));
                cout << "A ser pagado en efectivo: $" << presupuesto << endl;
                cout << "A ser pagado por mama: $" << (compraTotal - presupuesto) << endl;
                cout << "Por lo que tu nuevo total por " << i << " productos es de: $" << compraTotal << endl;
                break;

            case 3:   // Rezar
                poderRezador = rand() % 10;

                cout << "Rezas..." << endl;
                if (poderRezador > 4) {   // Dar presupuesto ilimitado con un 50% de probabilidad
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                    cout << "Parece que haz sido bendecido!" << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    cout << "Tienes presupuesto ilimitado." << endl;
                    cout << endl;
                    while (true) {
                        cout << "Compra " << i << endl;
                        cout << "Cuanto cuesta esta compra? (-1 para terminar)" << endl;
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                        cout << "$";
                        cin >> compra;
                        SetConsoleTextAttribute(hConsole, 7);
                        if (compra == -1) {
                            break;
                        }
                        cout << endl;
                        compraTotal = compraTotal + compra;
                        i++;
                    }
                    cout << endl;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                    cout << "Haz terminado tu compra divina!" << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    this_thread::sleep_for(chrono::seconds(1));
                    cout << "A ser pagado en efectivo: $" << presupuesto << endl;
                    cout << "Dinero bendecido: $" << (compraTotal - presupuesto) << endl;
                    cout << "Tu total por " << i << " productos queda en: $" << presupuesto << endl;
                }
                else {   // No ganar presupuesto ilimitado
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    cout << "Parece que no tienes el favor de los dioses hoy." << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    cout << "No podras pagar por el ultimo producto escaneado y terminara tu compra." << endl;
                    cout << "Tu total queda en: " << (compraTotal - compra) << endl;
                }
                break;

            case 4:   // Usar un cupon viejo
                descuentoCupon = 50 + (rand() % 49);   // Determinar el descuento que aplicara el cupon
                compraTotal = compraTotal * (1 - (descuentoCupon / 100));   // Aplicar el descuento

                cout << "A ver si este cupon te ayuda..." << endl;
                this_thread::sleep_for(chrono::seconds(2));
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                cout << "Es valido!" << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cout << "Este cupon aplica un descuento de " << descuentoCupon << "%!" << endl;
                cout << "El total de tu compra ahora es de: $" << compraTotal << endl;
                cout << "Este descuento tambien aplicara a todas las compras que te faltan, asi que puedes realizarlas" << endl;
                cout << endl;
                while ((compraTotal <= presupuesto) || (presupuesto == -1)) {
                    cout << "Compra " << i << endl;
                    cout << "Cuanto cuesta esta compra? " << (presupuesto == -1 ? " (-1 para terminar)" : "") << endl;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                    cout << "$";
                    cin >> compra;
                    SetConsoleTextAttribute(hConsole, 7);
                    if (compra == -1) {
                        break;
                    }
                    cout << endl;
                    compraTotal = compraTotal + (compra * (1 - (descuentoCupon / 100)));   // Aplicar compras con descuento
                    i++;
                }
                cout << endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                cout << "Haz terminado tu compra!" << endl;
                SetConsoleTextAttribute(hConsole, 7);
                this_thread::sleep_for(chrono::seconds(1));
                cout << "Utilizando tu cupon de " << descuentoCupon << "% de descuento" << endl;
                cout << "Haz ahorrado: $" << ((compraTotal / (1 - (descuentoCupon / 100))) - compraTotal) << endl;
                cout << "Tu total por " << i << " productos siendo: $" << compraTotal << endl;
                break;

            case 5:   // No pagar lo restante
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                cout << "Parece que no podras cubrir el precio del producto " << (i - 1) << "." << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cout << "Por lo que no se contara, y terminaras la compra." << endl;
                cout << "Tu total por " << i << " productos es de : $" << (compraTotal - compra);
                break;

            case 6:   // Aumentar el presupuesto
                while (terminar == 1) {
                    cout << "Aumentaras tu presupuesto, espero traigas el dinero necesario." << endl;
                    cout << "Cuanto dinero quieres agregar a este?" << endl;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                    cout << "$";
                    cin >> valorAgregado;
                    SetConsoleTextAttribute(hConsole, 7);
                    // Asegurarse que el dinero agregado cubra la compra previa y que sea una cantidad valida
                    while (valorAgregado <= 0 || (presupuesto + valorAgregado) < (compraTotal - 1)) {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        cout << "Haz elegido un valor invalido o este no logra cubrir tu compra." << endl;
                        SetConsoleTextAttribute(hConsole, 7);
                        cout << "Agrega mas." << endl;
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                        cout << "$";
                        cin >> valorAgregado;
                    }
                    cout << endl;
                    presupuesto = presupuesto + valorAgregado;
                    while (compraTotal <= presupuesto) {
                        cout << "Compra " << i << endl;
                        cout << "Cuanto cuesta esta compra? " << endl;
                        cout << "$";
                        cin >> compra;
                        if (compra == -1) {
                            break;
                        }
                        cout << endl;
                        compraTotal = compraTotal + compra;
                        i++;
                    }
                    cout << endl;
                    // Repetir seccion a discrecion del usuario
                    cout << "Parece que ya alcanzaste tu nuevo presupuesto, quieres agregar mas o terminar tu compra?" << endl;
                    cout << "(0: terminar, 1: agregar mas)" << endl;
                    cin >> terminar;
                    if (terminar != 0 && terminar != 1) {
                        cout << "Opcion invalida!" << endl;
                        cout << "Elige 0 o 1" << endl;
                        cin >> terminar;
                    }
                    cout << endl;
                }
                cout << "Terminas tu compra." << endl;
                cout << "Tu total por " << i << " productos es de : $" << compraTotal;
                break;

            case 7:   // huir
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                cout << "..." << endl;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "Espera que!" << endl;
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "Policia!!!" << endl;
                this_thread::sleep_for(chrono::milliseconds(500));
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                cout << "Escuchas a la sirena de la policia!";
                SetConsoleTextAttribute(hConsole, 7);
                cout << ", ecides escaparte por : " << endl;
                cout << "(1: La puerta principal)" << endl;
                cout << "(2: La puerta de atras)" << endl;
                cout << "(3: Una ventana)" << endl;
                cout << "(4: Dejar que te atrapen)" << endl;
                cin >> escape;
                cout << endl;
                switch (escape) {

                case 1:   // Escapar por puerta principal, respuesta correcta
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout << "La policia creyo que no serias tan obvio como para salir por la puerta principal." << endl;
                    this_thread::sleep_for(chrono::seconds(2));
                    cout << "Disimulas, pasando por la gente como si nada" << endl;
                    cout << endl;
                    this_thread::sleep_for(chrono::seconds(1));
                    cout << "..." << endl;
                    cout << endl;
                    this_thread::sleep_for(chrono::seconds(1));
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                    cout << "Lograste escapar!" << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout << "Con un total de: $0 pagado" << endl;
                    cout << (i - 1) << " productos robados" << endl;
                    cout << "Con un valor de: $" << compraTotal << endl;
                    break;

                case 2:   // Escapar por puerta trasera, respuesta incorrecta
                    cout << "Corres hacia la parte trasera de la tienda!" << endl;
                    this_thread::sleep_for(chrono::seconds(2));
                    cout << "Llegaste!" << endl;
                    cout << endl;
                    this_thread::sleep_for(chrono::seconds(1));
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    cout << "Pero la policia ya te esperaba" << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout << "Te vas con nada y una multa de $500" << endl;
                    break;

                case 3:   // Escapar por ventana, respuesta incorrecta
                    cout << "Corres hacia una de las ventanas de la tienda!" << endl;
                    this_thread::sleep_for(chrono::seconds(2));
                    cout << "Llegaste y logras romperla!" << endl;
                    cout << endl;
                    this_thread::sleep_for(chrono::seconds(1));
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    cout << "Pero la policia ya te esperaba" << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout << "Te vas con nada y una multa de $1000 para reparar la ventana" << endl;
                    break;

                case 4:   // Rendirse, respuesta neutra
                    cout << "Decides ser una persona honesta a ultimo momento y dejas que la policia te atrape." << endl;
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout << "Te vas con nada y una multa de $200" << endl;
                    break;

                default:   // Usuario elige una opcion invalida
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    cout << "No pensaste lo suficientemente rapido y la policia te atrapo." << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    this_thread::sleep_for(chrono::milliseconds(500));
                    cout << "Te vas con nada y una multa de $500" << endl;
                    break;
                }
                break;

            case 8:   // Trabajar en la tiendra
                cout << "Bienvenido a tu nuevo trabajo!" << endl;
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "Por cada cliente a quien atiendas, tendras un pago de ";
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                cout << "$10";
                SetConsoleTextAttribute(hConsole, 7);
                cout << " y una comision de ";
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                cout << "5%" << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cout << "Escribe \"scan\" para escanear un producto" << endl;
                cout << endl;
                while (true) { // Seguir vendiendo hasta que usuario elija terminar
                    productosCliente = 1 + (rand() % 4);

                    cout << "Cliente " << j << endl;
                    for (k = 1; productosCliente >= k; k++) {
                        cout << "Producto " << k << endl;
                        cin >> scan;
                        while (scan != "scan") {
                            cout << endl;
                            FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
                            cin.clear(); // Limpia el estado de error del flujo de entrada
                            cin >> scan;
                        }
                        cliente = 100 + (rand() % 900);
                        cout << "Beep..." << endl;
                        this_thread::sleep_for(chrono::milliseconds(500));
                        clienteIndividual = clienteIndividual + cliente; // Almacenar lo ganado por este cliente
                        cout << "Escaneado! Producto vale: $" << cliente << endl;
                        cout << endl;
                    }
                    clienteTotal = clienteTotal + clienteIndividual; // Almacenar el total de todos los clientes
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                    cout << "Cliente satisfecho. Haz ganado $" << ((clienteIndividual * 0.05) + 10) << "!" << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    cout << endl;
                    clienteIndividual = 0;
                    if ((compraTotal - presupuesto) <= ((clienteTotal * 0.05) + ((j) * 10))) { // Si ya se gano suficiente dinero para pagar por lo faltante de la compra
                        this_thread::sleep_for(chrono::seconds(1));
                        cout << endl;
                        cout << "Felicidades!" << endl;
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                        cout << "Haz ganado suficiente dinero para pagar por el exceso en tu compra." << endl;
                        SetConsoleTextAttribute(hConsole, 7);
                        cout << "Deseas seguir trabajando o terminar tu compra? (1: seguir trabajando, 2: terminar mi compra)" << endl;
                        cin >> eleccion;
                        if (eleccion == 2) {
                            cout << endl;
                            cout << "Terminas tu compra." << endl;
                            this_thread::sleep_for(chrono::seconds(1));
                            cout << "A ser pagado de tu dinero: $" << presupuesto << endl;
                            cout << "A ser pagado por tu trabajo: $" << (compraTotal - presupuesto) << endl;
                            if ((compraTotal - presupuesto) > 0) {
                                cout << "Ganaste dinero extra! Te llevas a casa: $" << (((clienteTotal * 0.05) + (j * 10)) - compraTotal) << endl;
                            }
                            break;
                        }
                        else {
                            cout << "Continuaras trabajando." << endl;
                            cout << endl;
                        }
                    }
                    j++;
                }
                break;
            case 9:   // Hechar una mentirota
                cout << "(Decides mentir acerca de:)" << endl;
                cout << "(1: Hoy cumplo)" << endl;
                //cout << "(2: Mi abuelita tiene cancer)" << endl;
                //cout << "(3: Tu abuelita tiene cancer)" << endl;
                //cout << "(4: Es para mi novia)" << endl;
                //cout << "(5: Soy mrbeast y esto es un experimento social)" << endl;
                //cout << "(6: Vengo del futuro)" << endl;
                //cout << "(7: Soy el hijo de dios)" << endl;
                cout << endl;
                cout << "Tu mentira: ";
                cin >> mentira;
                cout << endl;
                switch (mentira) {
                case 1:
                    cout << "Asi que hoy cumples..." << endl;
                    cout << "Felices cumples pero aun ocupas pagar $" << (compraTotal - presupuesto) << endl;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    cout << "Parece que no podras cubrir el precio del producto " << (i - 1) << "." << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    cout << "Por lo que no se contara, y terminaras la compra." << endl;
                    cout << "Tu total por " << i << " productos es de : $" << (compraTotal - compra);
                    break;
                case 2:
                    cout << "Lamento escuchar eso, es verdad?" << endl;

                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                default:
                    break;
                }
                break;
            default:
                cout << "Eleccion invalida." << endl;
                break;
            }
            cout << endl;
        }
        else {
            cout << endl;
            cout << "El total de tu compra es de: $" << compraTotal << endl;
        }
        cout << endl;
        cout << "Deseas volver a CETYS-mart? (1: Si, 2: No)" << endl;
        cin >> eleccion;
        if (eleccion == 1) {

            system("cls");
        }
        else {
            break;
        }
    }
    return 0;
}