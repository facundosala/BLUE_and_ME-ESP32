#ifndef BRAVO_H
#define BRAVO_H

// #include <BleKeyboard.h>
#include <stdio.h>
#include <stdlib.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Update.h>
#include <Arduino.h>
#include <ArduinoOTA.h>
#include <BLE2902.h>
#include <BLEDevice.h>
#include <BLEServer.h>  // https://github.com/h2zero/NimBLE-Arduino
#include <BLEUtils.h>
#include <BLEScan.h>
#include <mcp_can.h>  // https://downloads.arduino.cc/libraries/github.com/coryjfowler/mcp_can-1.5.0.zip // https://github.com/njh/arduino-libraries
#include <SPI.h>
// #include <Wire.h>
#include <Preferences.h>
#include "driver/twai.h"  // Lib de CAN interno de la ESP32
#include <BLEAdvertisedDevice.h>
// #include <BK8000L.h>

// #define resetBTPin 22
// BK8000L BT(&Serial2, resetBTPin); //in case of HW serial use for example: (&Serial1)

// #include <semphr.h>

// #define GENERIC_DISPLAY 320
// #define BUFF_LEN 256
// #define SCROLL_DELAY 6
// #define MAX_SCROLL_WINDOW_HEIGHT 75

const int GENERIC_DISPLAY = 320;
const int BUFF_LEN = 256;
const int SCROLL_DELAY = 6;
const int MAX_SCROLL_WINDOW_HEIGHT = 75;

// -------------------------------------- Declaraciones de pines de GPIO  ----------------------------------------------//

// #define CAN0_INT SDA  // Set INT to pin 21
// #define MIRR_OFF_DOWN 14
// #define CONTACT 27
// #define MIRROR_POS 0
// #define MIRROR_DOWN_REVERS 15
// #define MIRROR_UP_REVERS 2
// #define CLOSE_TECH 4
// #define OPEN_TECH 16
// #define MIRR_ON_UP 17
// #define PULL 33
// #define LED_1 22
// #define OPEN_MIRR 13
// #define CLOSE_MIRR 12
// #define RXCANH 26
// #define TXCANH 25
// #define POWER 32
// #define GPIO1 1
// #define GPIO36 36

typedef struct MenuItem {
  String label;
  struct MenuItem *next;
  struct MenuItem *previous;
  struct MenuItem *submenu;
  bool isOn;
} MenuItem;


const int CAN0_INT = SDA;  // Set INT to pin 21
// const int MIRR_OFF_DOWN = 14;
// const int CONTACT = 27;
// const int MIRROR_POS = 0;
// const int MIRROR_DOWN_REVERS = 15;
// const int MIRROR_UP_REVERS = 2;
const int CLOSE_TECH = 4;
const int OPEN_TECH = 15;
// const int MIRR_ON_UP = 17;
// const int PULL = 33;
// const int LED_1 = 22;
const int OPEN_MIRR = 13;
const int CLOSE_MIRR = 12;
// const int RXCANH = 26;
// const int TXCANH = 25;
const int POWER = 2;
// const int GPIO1 = 1;//
const int GPIO36 = 36; // sleep

// Declaracion de los elementos del menu del programa principal
MenuItem programa_ppal;

// Declaracion de los elementos del menu principal
MenuItem datos;
MenuItem configuracion;
MenuItem telefono;
MenuItem bluetooth;
MenuItem salir;

// Declaracion de los elementos del submenu "datos"
RTC_NOINIT_ATTR MenuItem d1, d2, d3, d4, d5, d6, d7;
MenuItem datos_salir;
RTC_NOINIT_ATTR MenuItem c1, c2, c3, c4, c5, c6, c7, c8;
MenuItem conf_salir;
RTC_NOINIT_ATTR MenuItem t1, t2, t3, t4;
MenuItem Telefono_salir;
MenuItem nombre_salir;
RTC_NOINIT_ATTR MenuItem n1, n2, n3, n4;


// ---------------------------------------- Declaracion de variables --------------------------------------------//

// extern bool btn_derecha;
// extern bool btn_izquierda;
extern bool AudioModeUpCntrl;
extern bool AudioModeDownCntrl;
extern bool AudioModeCntrl;
// extern bool flags_test_agujas;
extern bool MuteCntrl;
extern bool VolumeUpSts;
extern bool VolumeDownSts;
extern bool TelephoneCallSts;
extern bool VoiceRecognitionSts;
extern bool Luz;
extern bool reversa;
extern bool CompressorAcReqSts;
extern bool DriverDoorSts;
extern bool HandBrakeSts;
extern bool RHeatedWindowCntrl;
extern bool primera_vez_1;
extern bool primera_vez_2;
extern bool primera_vez_3;
extern bool primera_vez_4;
extern bool estado_puerta;
extern bool telefono_ACT;
extern bool reversa_anterior;
extern bool mensaje_nuevo;
extern bool espera;
extern bool movimiento;
extern bool abrir_cerrar;
extern bool abrir_cerrar_techo;
extern bool mensaje_nuevo1;
extern bool mensaje_nuevo2;
extern bool mensaje_sobre;
extern bool mensaje_whatsapp;
extern bool inicio;
extern bool scroll_Spotify;
extern bool Scroll_Whatsapp;
extern bool abrirx2;
extern bool POWER_VCC;
extern bool cerrarx2;
extern bool contacto;
extern bool arranque;
// extern bool sin_llave;
extern bool Estado_espejos;
extern bool contacto_evento;
extern bool no_contacto_evento;
extern bool subiendo;
extern bool estado;
extern bool estadoanterior;
extern bool primera_vez_espejos;
extern bool arranque_evento;
extern bool reversa_evento;
extern bool techo_km;
extern bool abrir_cerrar_techo_km;
extern bool on_km_techo;
extern bool on_llave_techo;
extern bool on_llave_espejos;
extern bool on_display_aire;
extern bool on_display_freno;
extern bool on_mute_puerta;
extern bool menu_on;
extern bool CC_ACTIVO;
extern bool time_out;

extern volatile bool semaforo_can;
extern volatile bool escribiendo;


extern Preferences preferences;

// extern uint8_t newMACAddress[];  // 28 => 2A Se restan son al ultimo valor de la MAC

extern byte controle;
extern byte controle1;
extern byte data_obd[];
extern byte hora;
extern byte info_bateria;
extern byte info_combustivel;
extern byte info_map;
extern byte info_AC_0;
extern byte info_AC_1;
extern byte STATUS_NCM_0;
extern byte STATUS_NCM_1;
extern byte STATUS_NCM_2;
extern byte VehicleSpeedSet;
extern byte info_sonda1;
extern byte info_sonda2;
extern byte info_sonda_correcao;
extern byte info_tps;
extern byte info_Velocidad;
extern byte info_Velocidad1;
extern byte info_Velocidad2;
extern byte IPC_VEHICLE_SETUP;
extern byte display;
extern byte mute;
// extern byte length_spotify;
// extern byte length_Whatsapp;
extern byte VPSRFTxButtonCntrl;
extern byte info_rpm1;
extern byte info_agua1;
extern byte BoostPressureIndication;

extern WebServer server;

extern String info_temp;
extern String info_valor;
extern String payload_Whatsapp_Aux;
extern String batt_level;
extern String batt_level_1;
extern String payload_Spotify_Anterior;
extern String payload_Spotify;
extern String payload_whatsapp;
extern String info_agua_1;
extern String info_rpm_1;
extern String *dato_display;
extern String Boost_1;

extern float VehicleSpeed;

extern int info_agua;
extern int info_rpm;

extern unsigned long prev;  // Temporizador (1 Dia)
extern unsigned long prevCL;
extern unsigned long prevwhatsapp;
extern unsigned long prevInfo;
extern unsigned long millis_abrir_cerrar;
extern unsigned long millis_abrir_cerrar_techo;
extern unsigned long millis_espejo_movimiento;
extern unsigned long millis_espejo_espera;
extern unsigned long millis_POWER_VCC;
extern unsigned long millis_sleep;
extern unsigned long millis_3E7;
extern unsigned long millis_time_out;
extern unsigned long prevInfo_SMS;
extern unsigned long prevInfo_Scroll;
// extern unsigned long prevInfo_Scroll_whatsapp;
extern unsigned long millis_abrir_cerrar_techo_km;
extern unsigned long prevOBD;
extern unsigned long prevRe;
extern unsigned long prevTx;

extern unsigned int init_k, end_k, cont3E7, init_m, end_m, init_L, end_L;

extern volatile bool connected;  // 0=advertising; 1=connected
extern volatile bool imp_no_conn;
extern volatile bool hasText, hasBattText;
extern volatile bool hasTimeText;
extern volatile bool hasLongText;
extern volatile int yScrollPos;
extern char *payload;
extern char *time_buffer;

extern MenuItem *currentMenu;  // Iniciar en el menu principal


extern MCP_CAN CAN0;  // Set CS to pin 5
extern long unsigned int can0_rxId;
extern unsigned char can0_len;
extern unsigned char can0_rxBuf[];


extern void mute_open_door_driver();
extern void Aire_AC();
extern void Freno_mano();
extern void abrir_espejos();
extern void cerrar_espejos();
// extern void bajar_tildown();
// extern void subir_tildown();
// extern void frenar_tildown();
extern void abrir_techo();
extern void cerrar_techo();
extern void ON_contacto();
extern void test_agujas();
extern void limpiar_sobre();
extern void aire_AC_encendido();
extern void aire_AC_apagado();
extern void limpiar_display();
extern void limpiar_sobre();
extern void aire_AC_encendido();
extern void aire_AC_apagado();
// extern void caletador_ventanas_on();
// extern void calentador_ventanas_off();
extern void freno_de_mano();
extern void activar_rebatimento();
extern void desactivar_rebatimento();
extern void desactivar_cierre_techo();
extern void activar_cierre_techo();
extern void send_Whatsapp();
extern void send_Name_Whatsapp();
extern void send_Spotify();
extern void Display_sobre();
extern void Mute_press();
extern void Info_telefono();
extern void setup_OTA();
extern void displayMenu();
extern void config_menu();
extern void Contro_CC();
extern void ascii2sixbits();
extern void radio_info();
extern void RDS_info();
extern void cambio_dato();
#endif