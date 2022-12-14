# Proyecto Integrador Qt + QML

Los comandos AT son un protocolo de comunicación ampliamente utilizado en comunicación serial, principalmente por módems.

Consisten en cadenas de caracteres (ASCII), que tienen varias formas:

    `AT+COMANDO`
    `ATCOMANDO`
    `AT?COMANDO`

y así sucesivamente.

Usted debe implementar en C++, utilizando el Framework Qt, un software que se comunique mediante comandos AT, a través de un puerto serie, con una aplicación que genera señales.

El protocolo que debe implementar tiene los siguientes comandos:

    `AT+SIGNALS=?` : Devuelve una lista con las señales disponibles, en el formato AT+señal.
    `AT+CURR`: Informa la señal actual que se está enviando, en el formato `AT+señal`.
    `AT+SIGNAL=señal` : Establece la señal a enviar. Responde AT+OK.
    `AT+START`: Inicia el envío de datos. Responde AT+OK.
    `AT+STOP`: Detiene el envío de datos. Responde AT+OK.
    `AT+MAX`: Informa el valor numérico máximo que tienen los datos.
    `AT+MIN`: Informa el valor numérico mínimo que tienen los datos.

    Si el comando es incorrecto, responte `AT+ERROR`.`

La aplicación se encuentra diponible para su descarga en Glodu.
El software que desarrolle debe:
    a - Pedir a la aplicación la lista con las señales disponibles, y presentárselas al usuario,
    generando dinámicamente un botón para cada señal.
    b -  Haciendo uso de los botones generados en a), debe solicitar a la aplicación que
    comience el envío de datos para la señal correspondiente.
    c -  Debe existir un botón que le permita al usuario preguntarle a la aplicación qué señal
    se está enviando.
    d -  Graficar la señal recibida, online.

1- Implementar una interfaz basada en Widgets y C++, graficando la señal con OpenGL.
2- Haciendo la menor cantidad de cambios posibles, reimplementar la interfaz, esta vez con
QML.

El software debe estar bien diseñado, con una clara división entre frontend y backend, que permita cambiar la interfaz de manera más sencilla.
