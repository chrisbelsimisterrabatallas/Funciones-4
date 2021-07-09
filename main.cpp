#include <iostream>
#include <ctime>

void paso_por_referencia(int a);

using namespace std;

//3) Una función recibe 3 enteros como parámetros, que indican el año, mes y
// día de nacimiento de una persona. La función debe devolver la
// edad de la persona de la siguiente forma:
//"Hola Juan, tu tienes 28 años, 2 meses y 13 días de edad."


/*
    struct tm {
      int tm_sec;   // seconds of minutes from 0 to 61
      int tm_min;   // minutes of hour from 0 to 59
      int tm_hour;  // hours of day from 0 to 24
      int tm_mday;  // day of month from 1 to 31 (****)
      int tm_mon;   // month of year from 0 to 11 (****)
      int tm_year;  // year since 1900 (****)
      int tm_wday;  // days since sunday
      int tm_yday;  // days since January 1st
      int tm_isdst; // hours of daylight savings time
    }

*/
string edadEnDiasMesesyAnios(int dia, int mes, int anio, string nombre) {
/* fecha/hora actual basado en el sistema actual */
    time_t now = time(0);

/* Objeto de una estructura tm con fecha/hora local */
    tm *time = localtime(&now);

    int anioActual = 1900 + (time->tm_year), mesActual = (1 + time->tm_mon);
    int diaActual = time->tm_wday;
    int diasActuales = anioActual * 360 + mesActual * 30 + diaActual;
    int diasPersona = anio * 360 + mes * 30 + dia;

    double difdias = diasActuales - diasPersona;
    //operador para el residuo es "%", pero solo funciona en enteros
    //operador para obtener residuo en números de coma flotante es "div"
    div_t anios_vida = div(difdias, 360);
    //cout<<"cociente:"<< anios_vida.quot;
    //cout<<" residuo:"<< anios_vida.rem;
    div_t mes_vida = div(anios_vida.rem, 30);
    string aux = "Bienvenido, " + nombre + ", tu tienes " + to_string(anios_vida.quot) + " anios";
    aux = aux + ", meses: " + to_string(mes_vida.quot);
    aux = aux + ", dias: " + to_string(mes_vida.rem);
    return aux;
}

    int paso_por_valor(int a)
    {
        a=a*5;
        cout<<endl<<"Dentro de la FUNCION: El valor de la variable a: " <<a;
        return 1;
    }

int paso_por_referencia(int &a)
{
    a=a*5;
    cout<<endl<<"EPor referencia: l valor de la variable a:" <<a;
    return 1;
}

string saludos ()
{    return "Bienvenidos…";
}
string saludos(string nombre)
{    return "Bienvenido " + nombre;
}
string saludos(string nombre, int edad)
{    if(edad>=18)
        return "Bienvenido señor " + nombre;
    else
    return "Bienvenido joven " + nombre;
}


int main() {
    setlocale(LC_ALL, "spanish");
    string edad= edadEnDiasMesesyAnios(22, 6, 1971, "Juan Alaba");
    cout<<endl<<edad;
    cout<<endl<<edadEnDiasMesesyAnios(4, 4, 2002, "Steven Torres");


    int a=2;
    paso_por_valor(a);
    cout<<endl<<"En el main: El valor de la variable a:" <<a;

    cout<<endl;
    paso_por_referencia(10);
    cout<<endl<<"En el main por referencia: El valor de la variable a: " <<a;


    cout<<endl<<saludos("Juan");
    cout<<endl<<saludos();
    cout<<endl<<saludos("José");
    cout<<endl<<saludos("Pedro", 20);


    return 0;

}

