#include <chrono>
#include <thread>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    // Elegir una raiz aleatoria para las funciones rand()
    srand((unsigned)time(NULL));

    float compra = 0, compraTotal = 0, total = 0, presupuesto, descuentoCupon, valorAgregado;
    int i = 1, eleccion, poderRezador, terminar = 1, escape;
    cout << "Bienvenido a la CETYS-mart!" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << endl;
    cout << "Dame tu presupuesto para este carrito (-1 para presupuesto ilimitado)" << endl;
    cout << "$";
    cin >> presupuesto;
    cout << endl;
    // Seguir comprando productos mientras el total sea menor que el presupuesto, o si el presupuesto es ilimitado
    while ((compraTotal <= presupuesto) || (presupuesto == -1)) {
        cout << "Compra " << i << endl;
        cout << "Cuanto cuesta esta compra? " << (presupuesto == -1 ? " (-1 para terminar)" : "") << endl;
        cout << "$";
        cin >> compra;
        if (compra == -1) {
            break;
        }
        cout << endl;
        compraTotal = compraTotal + compra;
        i++;
    }
    // Total excede el presupuesto y este no es ilimitado
    if (compraTotal >= presupuesto && presupuesto != -1) {
        cout << endl;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Parece que te haz excedido de tu presupuesto! Tienes diversas opciones para poder pagar los $" << (compraTotal - presupuesto) << " faltantes:" << endl;
        cout << "1: Credito, tendra intereses" << endl;
        cout << "2: Llamar a un familiar" << endl;
        cout << "3: Rezar" << endl;
        cout << "4: Usar cupon viejo" << endl;
        cout << "5: No pagar lo restante, no podras comprar el ultimo producto" << endl;
        cout << "6: Aumentar el presupuesto" << endl;
        cout << "(7: correr)" << endl;
        cin >> eleccion;
        cout << endl;
        this_thread::sleep_for(chrono::seconds(1));
        switch (eleccion) {
            // Pago con credito
        case 1:
            cout << "Elegiste pagar el extra con creditos.";
            cout << "El interes sera de 10%, tendras hasta el fin del mes para pagarlo, o el interes subira." << endl;
            cout << endl;
            // Mantener el ciclo de compras hasta que el usuario lo termine
            while (true) {
                cout << "Compra " << i << endl;
                cout << "Cuanto cuesta esta compra? (-1 para terminar)" << endl;
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
            cout << "Haz terminado tu compra!" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            cout << "A ser pagado en efectivo: $" << presupuesto << endl;
            cout << "A ser pagado en creditos con intereses aplicados: $" << ((compraTotal - presupuesto) * 1.1) << endl;
            cout << "Por lo que tu nuevo total por " << i << " productos es de : $" << (presupuesto + ((compraTotal - presupuesto) * 1.1)) << endl;
            break;
            // Llamar a un familiar
        case 2:
            cout << "Ring..." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            cout << "Ring..." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            cout << "Ring!" << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "Mama: \"cuanto dinero ocupas mijo? yo te lo pago\"" << endl;
            cout << endl;
            cout << "Parece que mama podra cubrir lo demas, puedes continuar." << endl;
            cout << endl;
            while (true) {
                cout << "Compra " << i << endl;
                cout << "Cuanto cuesta esta compra? (-1 para terminar)" << endl;
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
            cout << "Haz terminado tu compra!" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            cout << "A ser pagado en efectivo: $" << presupuesto << endl;
            cout << "A ser pagado por mama: $" << (compraTotal - presupuesto) << endl;
            cout << "Por lo que tu nuevo total por " << i << " productos es de: $" << compraTotal << endl;
            break;
            // Rezar
        case 3:
            poderRezador = rand() % 10;

            cout << "Rezas..." << endl;
            // Dar presupuesto ilimitado con un 50% de probabilidad
            if (poderRezador > 4) {
                cout << "Parece que haz sido bendecido!" << endl;
                cout << "Tienes presupuesto ilimitado." << endl;
                cout << endl;
                while (true) {
                    cout << "Compra " << i << endl;
                    cout << "Cuanto cuesta esta compra? (-1 para terminar)" << endl;
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
                cout << "Haz terminado tu compra divina!" << endl;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "A ser pagado en efectivo: $" << presupuesto << endl;
                cout << "Dinero bendecido: $" << (compraTotal - presupuesto) << endl;
                cout << "Tu total por " << i << " productos queda en: $" << presupuesto << endl;
            }
            else {
                // No ganar presupuesto ilimitado
                cout << "Parece que no tienes el favor de los dioses hoy." << endl;
                cout << "No podras pagar por el ultimo producto escaneado y terminara tu compra." << endl;
                cout << "Tu total queda en: " << (compraTotal - compra) << endl;
            }
            break;
            // Usar un cupon viejo
        case 4:
            // Determinar el descuento que aplicara el cupon
            descuentoCupon = 50 + (rand() % 49);
            // Aplicar el descuento
            compraTotal = compraTotal * (1 - (descuentoCupon / 100));

            cout << "A ver si este cupon te ayuda..." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            cout << "Es valido!" << endl;
            cout << "Este cupon aplica un descuento de " << descuentoCupon << "%!" << endl;
            cout << "El total de tu compra ahora es de: $" << compraTotal << endl;
            cout << "Este descuento tambien aplicara a todas las compras que te faltan, asi que puedes realizarlas" << endl;
            cout << endl;
            while ((compraTotal <= presupuesto) || (presupuesto == -1)) {
                cout << "Compra " << i << endl;
                cout << "Cuanto cuesta esta compra? " << (presupuesto == -1 ? " (-1 para terminar)" : "") << endl;
                cout << "$";
                cin >> compra;
                if (compra == -1) {
                    break;
                }
                cout << endl;
                // Aplicar compras con descuento
                compraTotal = compraTotal + (compra * (1 - (descuentoCupon / 100)));
                i++;
            }
            cout << endl;
            cout << "Haz terminado tu compra!" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            cout << "Utilizando tu cupon de " << descuentoCupon << "% de descuento" << endl;
            cout << "Haz ahorrado: $" << ((compraTotal / (1 - (descuentoCupon / 100))) - compraTotal) << endl;
            cout << "Tu total por " << i << "productos siendo: $" << compraTotal << endl;
            break;
            // No pagar lo restante
        case 5:
            cout << "Parece que no podras cubrir el precio del producto " << i << "." << endl;
            cout << "Por lo que no se contara, y terminaras la compra." << endl;
            cout << "Tu total por " << i << " productos es de : $" << (compraTotal - compra);
            break;
            // Aumentar el presupuesto
        case 6:
            while (terminar == 1) {
                cout << "Aumentaras tu presupuesto, espero traigas el dinero necesario." << endl;
                cout << "Cuanto dinero quieres agregar a este?" << endl;
                cout << "$";
                cin >> valorAgregado;
                // Asegurarse que el dinero agregado cubra la compra previa y que sea una cantidad valida
                while (valorAgregado <= 0 || (presupuesto + valorAgregado) < (compraTotal - 1)) {
                    cout << "Haz elegido un valor invalido o este no logra cubrir tu compra." << endl;
                    cout << "Agrega mas." << endl;
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
            cout << "Tu total por " << i << "productos es de : $" << compraTotal;
            break;
            // huir
        case 7:
            cout << "..." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            cout << "Espera que!" << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "Policia!!!" << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "(Escuchas a la sirena de la policia, decides escaparte por: " << endl;
            cout << "(1: La puerta principal)" << endl;
            cout << "(2: La puerta de atras)" << endl;
            cout << "(3: Una ventana)" << endl;
            cout << "(4: Dejar que te atrapen)" << endl;
            cin >> escape;
            cout << endl;
            switch (escape) {
            case 1:
                // Escapar por puerta principal, respuesta correcta
                this_thread::sleep_for(chrono::milliseconds(500));
                cout << "La policia creyo que no serias tan obvio como para salir por la puerta principal." << endl;
                this_thread::sleep_for(chrono::seconds(2));
                cout << "Disimulas, pasando por la gente como si nada" << endl;
                cout << endl;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "..." << endl;
                cout << endl;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "Lograste escapar!" << endl;
                cout << "Con un total de: $0 pagado" << endl;
                cout << (i - 1) << " productos robados" << endl;
                cout << "Con un valor de: $" << compraTotal << endl;
                break;
            case 2:
                // Escapar por puerta trasera, respuesta incorrecta
                cout << "Corres hacia la parte trasera de la tienda!" << endl;
                this_thread::sleep_for(chrono::seconds(2));
                cout << "Llegaste!" << endl;
                cout << endl;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "Pero la policia ya te esperaba" << endl;
                cout << "Te vas con nada y una multa de $500" << endl;
                break;
            case 3:
                // Escapar por ventana, respuesta incorrecta
                cout << "Corres hacia una de las ventanas de la tienda!" << endl;
                this_thread::sleep_for(chrono::seconds(2));
                cout << "Llegaste y logras romperla!" << endl;
                cout << endl;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "Pero la policia ya te esperaba" << endl;
                cout << "Te vas con nada y una multa de $1000 para reparar la ventana" << endl;
                break;
            case 4:
                // Rendirse, respuesta neutra
                cout << "Decides ser una persona honesta a ultimo momento y dejas que la policia te atrape." << endl;
                cout << "Te vas con nada y una multa de $200" << endl;
                break;
            default:
                // Usuario elige una opcion invalida
                cout << "No pensaste lo suficientemente rapido y la policia te atrapo." << endl;
                cout << "Te vas con nada y una multa de $500" << endl;
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
}