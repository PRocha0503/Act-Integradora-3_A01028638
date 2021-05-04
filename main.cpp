#include "heapporentradas.h"
#include "heap.h"
#include <sstream>
#include <algorithm>

using namespace std;
int convertirMes(string m)
{
    if (m == "Jan")
    {
        return 1;
    }
    else if (m == "Feb")
    {
        return 2;
    }
    else if (m == "Mar")
    {
        return 3;
    }
    else if (m == "Apr")
    {
        return 4;
    }
    else if (m == "May")
    {
        return 5;
    }
    else if (m == "Jun")
    {
        return 6;
    }
    else if (m == "Jul")
    {
        return 7;
    }
    else if (m == "Aug")
    {
        return 8;
    }
    else if (m == "Sep")
    {
        return 9;
    }
    else if (m == "Oct")
    {
        return 10;
    }
    else if (m == "Nov")
    {
        return 11;
    }
    else if (m == "Dec")
    {
        return 12;
    }
    return 100000;
}
formatoHora cambiarHora(string h)
{
    int hora;
    int minuto;
    int segundo;
    h.erase(remove(h.begin(), h.end(), ':'), h.end());
    string stringHora, stringMinuto, stringSegundo;
    stringHora = h.substr(0, 2);
    stringMinuto = h.substr(2, 2);
    stringSegundo = h.substr(4, 2);
    stringstream conv(stringHora);
    conv >> hora;
    stringstream conv1(stringMinuto);
    conv1 >> minuto;
    stringstream conv2(stringSegundo);
    conv2 >> segundo;
    formatoHora horaConFormato;
    horaConFormato.hora = hora;
    horaConFormato.minuto = minuto;
    horaConFormato.segundo = segundo;
    return horaConFormato;
}

void leerDatos(vector<entrada> &ve)
{
    string line;
    string mes;
    int dia;
    string hora;
    string ip;
    string razon;
    string razon1;
    string razon2;
    string razon3;
    string razon4;
    string razon5;
    ifstream bitacora("bitacora.txt");
    if (bitacora.is_open())
    {
        while (getline(bitacora, line))
        {
            entrada e;
            istringstream ss(line);
            ss >> mes >> dia >> hora >> ip >> razon >> razon1 >> razon2 >> razon3 >> razon4 >> razon5;
            string razonFinal;
            razonFinal = razon + " " + razon1 + " " + razon2 + " " + razon3 + " " + razon4 + " " + razon5;
            int mesInt;
            mesInt = convertirMes(mes);
            formatoHora horaCambiada = cambiarHora(hora);
            horaCambiada.mes = mesInt;
            horaCambiada.dia = dia;
            e.fecha = horaCambiada;
            e.ip = ip;
            e.razonFalla = razonFinal;
            ve.push_back(e);
            razon1 = ""; // Vuelvo a restablecer todos las palabras por si no se usan en la siguiente linea
            razon2 = "";
            razon3 = "";
            razon4 = "";
            razon5 = "";
        }
    }
    bitacora.close();
}

int main()
{
    vector<entrada> vectorEntradas;
    leerDatos(vectorEntradas);
    Heap heapEntradas(vectorEntradas);
    heapEntradas.heapSort();
    string ordenada = "Ordenada.txt";
    heapEntradas.sacarLista(0, heapEntradas.size(), ordenada);
    vector<entrada> vectorintermediario = heapEntradas.getVector();
    cout<<vectorintermediario.size()<<endl;
    HeapPorEntradas cantidades(vectorintermediario);
    cantidades.heapSort();
    int tamaño = cantidades.getSize();
    cantidades.sacarLista(0,tamaño,"MaxEntradas.txt");
    cantidades.printMaxEntradas();
    cantidades.getEntradasInfo(0);
    return 0;
}
