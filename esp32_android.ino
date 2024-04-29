#include "BRAVO.h"


TaskHandle_t Tarea1 = NULL;  // defino una variable de paso a la tarea 1
TaskHandle_t Tarea2 = NULL;  // defino una variable de paso a la tarea 2

// ---------------------------------------- Declaracion de variables --------------------------------------------//

// bool btn_derecha = 0;
// bool btn_izquierda = 0;
bool AudioModeUpCntrl = 0;
bool AudioModeDownCntrl = 0;
bool AudioModeCntrl = 0;
// bool flags_test_agujas = false;
bool MuteCntrl;
bool VolumeUpSts = 0;
bool VolumeDownSts = 0;
bool TelephoneCallSts = 0;
bool VoiceRecognitionSts = 0;
bool Luz;
bool reversa;
bool CompressorAcReqSts;
bool DriverDoorSts;
bool HandBrakeSts;
bool RHeatedWindowCntrl;
bool primera_vez_1 = 0;
bool primera_vez_2 = 0;
bool primera_vez_3 = 0;
bool primera_vez_4 = 0;
bool primera_vez_5 = 0;
bool primera_vez_6 = 0;
bool estado_puerta = 1;
bool telefono_ACT = false;
bool mensaje_nuevo = false;
bool espera = false;
bool movimiento = false;
bool POWER_VCC = false;
bool abrir_cerrar = false;
bool abrir_cerrar_techo = false;
bool techo_km = true;
bool abrir_cerrar_techo_km = false;
bool mensaje_nuevo1 = false;
bool mensaje_nuevo2 = false;
bool mensaje_nuevo3 = false;
bool mensaje_sobre = true;
bool mensaje_whatsapp = false;
bool inicio = 0;
bool scroll_Spotify = false;
bool scroll_Maps = false;
bool Scroll_Whatsapp = false;
bool scroll_llamada = false;
bool abrirx2 = true;
bool cerrarx2 = false;
bool contacto = false;
bool arranque = false;
// bool sin_llave = false;
RTC_NOINIT_ATTR bool Estado_espejos;
// bool Estado_espejos;
bool contacto_evento = 0;
bool no_contacto_evento = 0;
bool pauseNCV = 0;
bool arriba_espejo = false;
bool estado = false;
bool time_out = false;
bool estadoanterior = false;
bool primera_vez_espejos = false;
bool arranque_evento = 0;
bool reversa_evento = 0;
bool menu_on = false;
bool cambio_pul_volante = false;
bool CC_ACTIVO = false;
bool anti_rebote = false;
bool llamada_en_curso = false;
bool llamada_entrante = false;
bool marcando = false;
bool musica_on = false;
bool phone = false;
bool voice = false;
bool BT_musica = false;
bool pause_estereo = false;
bool se_movio = false;
bool BLE_TIMER = true;
bool fuente_primera_vez = false;

volatile bool radio_on = false;
volatile bool bym_on = false;
volatile bool semaforo_can = false;
volatile bool escribiendo = false;



// ------------------------------------------------ MAC ADRESS PRUEBA ----------------------------------------------------------------------- //

// uint8_t newMACAddress[] = { 0x4C, 0xEB, 0xD6, 0x71, 0xEF, 0xD0 };  // 28 => 2A Se restan son al ultimo valor de la MAC

// ---------------------------------------------------- Variables ---------------------------------------------------------------------------- //

byte controle;
byte controle1;
byte data_obd[8]{ 0x02, 0x01, 0x00, 0x55, 0x55, 0x55, 0x55, 0x55 };
byte INFO_tel[8];  // defino byte de INFO telefono
byte INFO_1[2]{ 0x00, 0x1A };
byte INFO_2[2]{ 0x00, 0x1E };
byte hora;
byte info_bateria;
byte info_combustivel;
byte info_map;
byte info_AC_0;
byte info_AC_1;
byte STATUS_NCM_0;
byte STATUS_NCM_1;
byte STATUS_NCM_2;
byte VehicleSpeedSet;
byte info_sonda1;
byte info_sonda2;
byte info_sonda_correcao;
byte info_tps;
byte info_Velocidad;
byte info_Velocidad1;
byte info_Velocidad2;
byte IPC_VEHICLE_SETUP;
byte display;
byte mute;
// byte length_spotify;
// byte length_Whatsapp;
// byte length_llamada;
byte VPSRFTxButtonCntrl;
byte info_rpm1;
byte info_agua1;
byte BoostPressureIndication;
byte CruiseControlSts;
byte BatteryVoltageLevel;

String info_temp;
String info_valor;
String payload_Whatsapp_Aux;
String batt_level;
String batt_level_1 = "BATT: ";
String batt_level_2 = "SIN BT";
String VehicleSpeed_1;
String payload_Spotify_Anterior;
String payload_Maps_Anterior;
String payload_telefono_Anterior;
String payload_telefono;
String payload_telefono_name;
String payload_Spotify;
String payload_Maps;
String payload_whatsapp;
String info_agua_1;
String info_rpm_1;
String Boost_1;
String BATT_1;
String fiat = "FIAT";
String bravo = "BRAVO";
String punto = "PUNTO";
String idea = "IDEA";
String linea = "LINEA";

String *dato_display;
String Primer = "primera";

float VehicleSpeed = 0;
float BATT = 0;

int info_agua = 0;
int info_rpm = 0;
int Boost = 0;
int cont_ceros = 0;
int can0rx = 0;
int can0rx_anterior = 0;
int contador = 10;
int dato_mostrado = 0;

unsigned long prev = 86400000;  // Temporizador (1 Dia)

unsigned long prevCL = prev;
unsigned long prevwhatsapp = prev;
unsigned long prevInfo = prev;
unsigned long prevInfo_SMS = prev;
unsigned long prevInfo_Scroll = prev;
unsigned long millis_abrir_cerrar = prev;
unsigned long millis_espejo_movimiento = prev;
unsigned long millis_espejo_espera = prev;

unsigned long millis_abrir_cerrar_techo = 0;
unsigned long millis_abrir_cerrar_techo_km = 0;
unsigned long millis_POWER_VCC = 0;
unsigned long millis_sleep = 0;
unsigned long millis_3E7 = 0;
unsigned long millis_rebote = 0;
unsigned long millis_BLE = 0;
unsigned long millis_time_out = 0;
// unsigned long prevInfo_Scroll_whatsapp = prev;
// unsigned long prevInfo_Scroll_telefono = prev;

unsigned long prevOBD = 0;
unsigned long prevRe = prev;
unsigned long prevTx = 0;


unsigned int init_k = 0, end_k = 14, cont3E7 = 0, init_m = 0, end_m = 14, init_L = 0, end_L = 14;

// --------------------------------------------------- Blekeyboard ---------------------------------------------------------------------- //

// BleKeyboard bleKeyboard;

// ----------------------------------------------- Memoria no volatile ---------------------------------------------------------------------- //

Preferences preferences;  // lugar de guardado de variables en memoria

// ---------------------------------------------------- MENU ---------------------------------------------------------------------------- //

MenuItem *currentMenu = &programa_ppal;  // Iniciar en el menu principal

// ---------------------------------------------------- BLE ---------------------------------------------------------------------------- //

BLEServer *pServer;
BLEServer *pServer2;

BLEService *pService;
BLEAdvertising *pAdvertising;  // Declaro pAdvertising una variable global
BLECharacteristic *pCharacteristic;



// -------------------------------------- CS de uso CAN MCP 2515 externo  ----------------------------------------------//

MCP_CAN CAN0(SS);  // Set CS to pin 5
long unsigned int can0_rxId;
unsigned char can0_len;
unsigned char can0_rxBuf[8];

// ---------------------------------------- CAN ESP32 interno -------------------------------------------------//

// can_general_config_t g_config = CAN_GENERAL_CONFIG_DEFAULT(GPIO_NUM_26, GPIO_NUM_25, CAN_MODE_NORMAL);
// can_timing_config_t t_config = CAN_TIMING_CONFIG_50KBITS();
// can_filter_config_t f_config = CAN_FILTER_CONFIG_ACCEPT_ALL();

// -------------------------------------- BLE ----------------------------------------------------------//

// BLE UUIDs
#define GENERIC_DISPLAY 320
static const BLEUUID ALERT_DISPLAY_SERVICE_UUID = BLEUUID("3db02924-b2a6-4d47-be1f-0f90ad62a048");
static const BLEUUID DISPLAY_MESSAGE_CHARACTERISTIC_UUID = BLEUUID("8d8218b6-97bc-4527-a8db-13094ac06b1d");
static const BLEUUID DISPLAY_TIME_CHARACTERISTIC_UUID = BLEUUID("b7b0a14b-3e94-488f-b262-5d584a1ef9e1");
static const BLEUUID DISPLAY_DISPLAY_ORIENTATION_CHARACTERISTIC_UUID = BLEUUID("0070b87e-d825-43f5-be0c-7d86f75e4900");

volatile bool connected = false;  // 0=advertising; 1=connected
volatile bool imp_no_conn = false;
volatile bool hasText = false, hasBattText = false;
volatile bool hasTimeText = false;
volatile bool hasLongText = false;
volatile int yScrollPos = 0;
char *payload = new char[BUFF_LEN];
char *time_buffer = new char[BUFF_LEN];
volatile int display_orientation = 0;  //0=none;1=flip

// --------------------------------- CAN mensajes -----------------------------------------------------//

int sixBit[12];

class DisplayOrientationCharacteristicCallback : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {

    std::string str = pCharacteristic->getValue();  //read values
    Serial.println(str.c_str());

    display_orientation = (int)str[0];
    Serial.println(" DisplayOrientationCharacteristicCallback->onWrite()");
  }
};

//-------------------------- Devolucion de llamadas para manejar eventos -------------------------------//

class TimeCharacteristicCallback : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pTimeCharacteristic) {
    std::string str = pTimeCharacteristic->getValue();  // Leo los valores
    strcpy(time_buffer, &str.c_str()[1]);               // Primer char con el porcentaje de bateria
    batt_level = (int)str[0];                           // DE char a int
    batt_level_1 = "CEL" + batt_level + "=/.";
    char buff[16];
    sprintf(buff, "Bateria: %d%%", str[0]);
    if (telefono_ACT == true) {
      prevInfo = millis();
      mensaje_nuevo = true;
      telefono_ACT = false;
    }
    Serial.println(buff);

    hasLongText = false;
    hasText = false;
    hasTimeText = true;
  }
};

// -------------------------------------- LLamada a notificaciones ----------------------------------------------//

class DisplayCharacteristicCallback : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    std::string str = pCharacteristic->getValue();
    BLEUUID uuid = pCharacteristic->getUUID();
    std::string uuid_s = uuid.toString();

    strcpy(payload, str.c_str());
    yScrollPos = 0;

    hasLongText = str.length() > 40;
    hasText = true;
    hasTimeText = false;
  }
};

class MyServerCallback : public BLEServerCallbacks {
  void onConnect(BLEServer *pServer) {
    Serial.println("LE onConnect");

    connected = true;
    memset(payload, 0x00, BUFF_LEN);
    hasLongText = false;
    hasText = false;
    hasTimeText = false;
    yScrollPos = 0;
  }

  void onDisconnect(BLEServer *pServer) {
    Serial.println("LE onDisconnect");
    connected = false;
  }
};


void setupBLEServer() {
  // init BLE server
  BLEDevice::init("FIAT B&M");
  BLEDevice::setMTU(256);  //<<<< MTU SIZE
  pServer = BLEDevice::createServer();

  pServer->setCallbacks(new MyServerCallback());
  // Alert Display Service
  BLEService *pService = pServer->createService(ALERT_DISPLAY_SERVICE_UUID);

  // BLECharacteristic* pCharacteristic = pService->createCharacteristic(DISPLAY_MESSAGE_CHARACTERISTIC_UUID,BLECharacteristic::PROPERTY_WRITE);
  // pCharacteristic->setWriteProperty(true);

  pServer2->getAdvertising()->setAppearance(512);
  pServer2->getAdvertising()->addServiceUUID("0000180A-0000-1000-8000-00805F9B34FB");
  pServer2->startAdvertising();

  BLECharacteristic *pCharacteristicText = new BLECharacteristic(DISPLAY_MESSAGE_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_WRITE_NR);  // Respuesta MTU=500 del client
  pCharacteristicText->setCallbacks(new DisplayCharacteristicCallback());
  pService->addCharacteristic(pCharacteristicText);

  // Display Time Characteristic
  BLECharacteristic *pCharacteristicTime = new BLECharacteristic(DISPLAY_TIME_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_WRITE_NR);
  pCharacteristicTime->setCallbacks(new TimeCharacteristicCallback());
  pService->addCharacteristic(pCharacteristicTime);

  // Change Display Orientation
  BLECharacteristic *pCharacteristicDisplayOrientation = new BLECharacteristic(DISPLAY_DISPLAY_ORIENTATION_CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_WRITE_NR);
  pCharacteristicDisplayOrientation->setCallbacks(new DisplayOrientationCharacteristicCallback());
  pService->addCharacteristic(pCharacteristicDisplayOrientation);

  pService->start();

  BLEAdvertising *pAdvertising = pServer->getAdvertising();

  // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.characteristic.gap.appearance.xml

  pAdvertising->setAppearance(GENERIC_DISPLAY);  // Icono Impresora
  pAdvertising->start();
}

void setup() {


  // ------------------------------------------------- Variables de Configuracion del menu ------------------------------------------------------//


  preferences.begin("my-app", false);  // Abre el almacenamiento no volátil

  c1.isOn = preferences.getBool("c1.isOn", "true");
  c2.isOn = preferences.getBool("c2.isOn", "true");
  c3.isOn = preferences.getBool("c3.isOn", "true");
  c4.isOn = preferences.getBool("c4.isOn", "true");
  c5.isOn = preferences.getBool("c5.isOn", "true");
  c6.isOn = preferences.getBool("c6.isOn", "true");
  c7.isOn = preferences.getBool("c7.isOn", "true");
  c8.isOn = preferences.getBool("c8.isOn", "false");

  d1.isOn = preferences.getBool("d1.isOn", "true");
  d2.isOn = preferences.getBool("d2.isOn", "true");
  d3.isOn = preferences.getBool("d3.isOn", "true");
  d4.isOn = preferences.getBool("d4.isOn", "true");
  d5.isOn = preferences.getBool("d5.isOn", "true");
  d6.isOn = preferences.getBool("d6.isOn", "true");
  d7.isOn = preferences.getBool("d7.isOn", "true");

  t1.isOn = preferences.getBool("t1.isOn", "true");
  t2.isOn = preferences.getBool("t2.isOn", "true");
  t3.isOn = preferences.getBool("t3.isOn", "true");

  n1.isOn = preferences.getBool("n1.isOn", "true");
  n2.isOn = preferences.getBool("n2.isOn", "false");
  n3.isOn = preferences.getBool("n3.isOn", "false");
  n4.isOn = preferences.getBool("n4.isOn", "false");


  // ---------------------------------------- Task tarea 0 -------------------------------------------------//

  xTaskCreatePinnedToCore(
    loop_tarea0, /* Funcion de la tarea1 */
    "Tarea0",    /* Nombre de la tarea */
    8096,        /* Tamaño de la pila */
    NULL,        /* Parametros de entrada */
    1,           /* Prioridad de la tarea */
    NULL,        /* objeto TaskHandle_t. */
    1);

  // ---------------------------------------- Task tarea 1 -------------------------------------------------//

  xTaskCreatePinnedToCore(
    loop_tarea1, /* Funcion de la tarea1 */
    "Tarea1",    /* Nombre de la tarea */
    2024,        /* Tamaño de la pila */
    NULL,        /* Parametros de entrada */
    1,           /* Prioridad de la tarea */
    &Tarea1,     /* objeto TaskHandle_t. (aca digo que tiene una variable compartida)*/
    1);


  // ---------------------------------------- Task tarea 2 -------------------------------------------------//

  xTaskCreatePinnedToCore(
    loop_tarea2, /* Funcion de la tarea1 */
    "Tarea2",    /* Nombre de la tarea */
    8096,        /* Tamaño de la pila */
    NULL,        /* Parametros de entrada */
    1,           /* Prioridad de la tarea */
    NULL,        /* objeto TaskHandle_t. (aca digo que tiene una variable compartida)*/
    1);


  //---------------------------------- Saludo e inicio Serie --------------------------------------------//

  Serial.begin(115200);  // Comunicacion Serie USB
  Serial2.begin(9600);   // Comunicacion con Control BLE
  Serial.println("Welcome FIAT by MONZA");

  //------------------------------ Instalar e iniciar CAN Del ESP32 --------------------------------------- //

  // if (can_driver_install(&g_config, &t_config, &f_config) == ESP_OK) {
  // } else {
  //   Serial.println("Fallo inicio de CAN 50 kbps");
  //   return;
  // }

  // if (can_start() == ESP_OK) {
  //   // Serial.println("Comunicacion CAN 50 kbps lograda!");

  // } else {
  //   Serial.println("Error Inicializacion de CAN 50 kbps...");
  //   return;
  // }

  // // Iniciar la recepción de mensajes CAN

  // can_start();

  //------------------------------------ Instalar, filtrar e iniciar CAN MCP ------------------------------------------- //

  if (CAN0.begin(MCP_STDEXT, CAN_50KBPS, MCP_8MHZ) == CAN_OK) {
    // Serial.println("Comunicacion CAN 50 kbps lograda!");
  } else {
    Serial.println("Error Inicializacion de CAN 50 kbps...");
  }

  //------------------------------------------ Filtros ----------------------------------------------//

  /*
  0x38A // Compresor aire acondicionado
  0x1A0 // Alarma y mando llave a distancia
  0x380 // Estado llave, Freno de mano, Puertas 
  0x2A0 // Velocidad 
  0x3A0 // Comandos al volante
  0x2A1 // BOOST
  0x281 // RPM y Temp. Agua
  */

  //CAN0.init_Mask(0, 0, 0x3a00000);  // Init first mask...
  //CAN0.init_Filt(0, 0, 0x3a00000);  // Init first filter...
  // CAN0.init_Filt(1, 0, 0x2A0);  // Init second filter...
  // CAN0.init_Filt(1, 0, 0x2A0);  // Init second filter...
  // CAN0.init_Filt(1, 0, 0x2A0);  // Init second filter...
  // CAN0.init_Filt(1, 0, 0x2A0);  // Init second filter...

  //CAN0.init_Mask(1, 0, 0x3a00000);  // Init second mask...
  // CAN0.init_Filt(2,0,0x01030000);                // Init third filter...
  // CAN0.init_Filt(3,0,0x01040000);                // Init fouth filter...
  // CAN0.init_Filt(4,0,0x01060000);                // Init fifth filter...
  // CAN0.init_Filt(5,0,0x01070000);                // Init sixth filter...

  CAN0.setMode(MCP_NORMAL);

  //--------------------------------------- Coloco una MAC de forma manual -----------------------------------------//

  // esp_base_mac_addr_set(&newMACAddress[0]);  // Le coloco la MAC de la primer placa placa ESP32


  //--------------------------------------- Definicion de pines primera version ------------------------------------------------//

  pinMode(SS, OUTPUT);       // CS MCP2515 CAN0
  pinMode(CAN0_INT, INPUT);  // INT MCP2515 CAN0 // Cambiarlo por el 19 si uso el CAN interno de la ESP32
  // pinMode(LED_1, OUTPUT);    // Led debug
  // pinMode(MIRROR_UP_REVERS, OUTPUT);

  pinMode(OPEN_MIRR, INPUT_PULLDOWN);   // Rele abrir espejos
  pinMode(CLOSE_MIRR, INPUT_PULLDOWN);  // Rele cerrer espejos
  pinMode(POWER, INPUT_PULLDOWN);       // Rele de alimentacion de techo y espejos

  pinMode(OPEN_TECH, INPUT);   // Salida pulsador techo abrir
  pinMode(CLOSE_TECH, INPUT);  // Salida pulsador techo cerrar
  // pinMode(MIRROR_UP_REVERS, INPUT);    // Salida pulsador subir espejos
  // pinMode(MIRROR_DOWN_REVERS, INPUT);  // Salida pulsador bajar espejo

  // pinMode(MIRR_ON_UP, INPUT);
  // pinMode(MIRR_OFF_DOWN, INPUT);
  // pinMode(CONTACT, INPUT);
  // pinMode(MIRROR_POS, INPUT);

  // digitalWrite(MIRROR_UP_REVERS, LOW);

  digitalWrite(SS, HIGH);  // Pongo en alto el Chip Selec del MCP2515 CON0

  dato_display = &fiat;


  //------------------------------------------ Inicio menu ----------------------------------------------//

  config_menu();

  //------------------------------------------ Inicio Bluetooth ----------------------------------------------//

  setupBLEServer();  // Enciendo Bluetooth

  //------------------------------------------ Inicio mandos reproduccion ----------------------------------------------//

  // bleKeyboard.begin();

  //------------------------------------------ Inicio B&M mensaje ----------------------------------------------//

  byte INFO[4]{ 0x00, 0x00, 0x00, 0xFF };

  CAN0.sendMsgBuf(0x7b0, 0, 4, INFO);  // Envio mensaje que emula el B&M conectado (DIAGNOSE_REQUEST)


  //------------------------------------------ Sleep Wakeup ----------------------------------------------//


  esp_sleep_enable_ext0_wakeup(GPIO_NUM_36, LOW);  // le digo que el GPIO36 es quien la despierta con un estado bajo

  //------------------------------------------ Inicio comunicacion BT modulo audio ----------------------------------------------//

  // pinMode(22, INPUT);


  //BT.begin();  // Inicializa comunicacion BT - modulo BK8000L
  //   vTaskDelay(pdMS_TO_TICKS(1000));

  // while (1) {
  //   // Serial2.write("AT\r\n");

  //   vTaskDelay(pdMS_TO_TICKS(100));

  //   // Verificar si hay datos disponibles en el Serial2
  //   if (Serial2.available() > 0) {
  //     // Leer los datos del Serial2
  //     while (Serial2.available() > 0) {
  //       char data = Serial2.read();
  //       // Imprimir los datos en el Serial común
  //       Serial.print(data);
  //     }
  //   }
  // }

  //   Serial.println(BT.BT_NAME);
  //   Serial.println(BT.BT_ADDR);
  //   Serial.println(BT.BT_PIN);

  //   Serial.println(BT.getConnectionStatus());


  //   digitalWrite(resetBTPin, LOW);  // Pongo en elto el Chip Selec del MCP2515 CON0


}  // FIN DEL SETUP

//------------------------------------------ Inicio de programa -----------------------------------------------------//

void loop() {
  //----------------------------------------- ble kayboard ----------------------------------------------------------//

  // if (bleKeyboard.isConnected()) {
  //   // Serial.println("Sending 'Hello world'...");
  //   bleKeyboard.print("Hello world");
  // }

  //---------------------------------------------------------------------------------------------------------------//

  if (c8.isOn == true) {
    preferences.putBool("c8.isOn", !c8.isOn);
    //------------------------------------------ Inicio Config WiFi  ----------------------------------------------//

    setup_OTA();

    //------------------------------------------ Inicio WiFi UPDATE ----------------------------------------------//
    while (1) {
      server.handleClient();
      vTaskDelay(pdMS_TO_TICKS(1));
    }
  }
}
