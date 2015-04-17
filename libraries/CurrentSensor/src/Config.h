#include <SPI.h>

// Endereço MAC do Ethernet Shield
#define MAC_ADDRESS				{ 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }

// Endereço IP do Ethernet Shield
#define IP_ADDRESS				{ 192, 168, 1, 2 }

// Pino de entrada do sensor de corrente
#define CURRENT_SENSOR_INPUT	10

// Pino de entrada do sensor de tensão
#define VOLTAGE_SENSOR_INPUT	9

// Pino de entrada do sensor de movimento
#define MOTION_SENSOR_INPUT		9

// Pinos de saída dos relés
#define RELAY_OUTPUT			{ 32, 33, 34, 35 }

// Quantidade de relés que serão utilizados
#define MAX_RELAY_QUANTITY		4

// Número de amostras que serão lidas do sensor até definir uma valor correto para a corrente 
#define CURRENT_SENSOR_SAMPLES	250