#include "server.h"
    


int main(void){     // Main sin argumentos ya que se maneja todo por Interfaz


    // SETEAMOS ESTRUCTURA PARA LUEGO HACER LA CONEXION
    int status;       // Seguimiento de errores
    int s; // Nuestro preciado socket. Sera el "socket descriptor" que devuelve la funcion socket
    struct addrinfo hintsTCP;    // Necesito especificar alguna información 
    struct addrinfo *servinfo;  // will point to the results

    memset(&hintsTCP, 0, sizeof hintsTCP); // make sure the struct is empty
    hintsTCP.ai_family = AF_UNSPEC;     // don't care IPv4 or IPv6
    hintsTCP.ai_socktype = SOCK_STREAM; // TCP stream sockets
    hintsTCP.ai_flags = AI_PASSIVE;   // Le dice a "getaddrinfo()" que llene con mi IP de Local Host en 
                                        // el Socket. Si quisiera poner uno paralelo, debo indicarlo en donde 
                                        // dice NULL mas abajo.


    if ((status = getaddrinfo(NULL, SERVER_PORT_NUMBER, &hintsTCP, &servinfo)) != 0) { // Ayuda a setear las Structs necesarias
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status)); // xxx: VER MANEJO DE ERRORES. getaddrinfo() regresa distinto de cero y sirve para troubleshooting. Se puede imprimir el error con "gai_sterror()"
        exit(1);
    }

    /*you should do error-checking on getaddrinfo(), and walk
     the "res" linked list looking for valid entries instead of just
     assuming the first one is good (like many of these examples do).
     See the section on client/server for real examples. */

    if (s = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol) == -1){ // Creamos el socket con la info dle server
        fprint(stderr, "Socket Failed\n");
    }

    if (bind(s, servinfo->ai_addr, servinfo->ai_addrlen) == -1){ // Asociamos el socket a nuestro Puerto
        fprint(stderr, "Binding Failed\n");
    } 



 

  // ... do everything until you don't need servinfo anymore ....

  freeaddrinfo(servinfo); // free the linked-list
}