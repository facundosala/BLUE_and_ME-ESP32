//----------------------------------------------- Tarea 2 -----------------------------------------------------//
//*****************************************************************************************************************

// Definicion de los codigos de teclas

#define UP_KEY 'a'
#define DOWN_KEY 's'
#define ENTER_KEY 'o'
#define EXIT_KEY 'e'

#include "BRAVO.h"

void displayMenu(MenuItem *menu);

void config_menu() {

  programa_ppal.label = "Menu";
  programa_ppal.next = NULL;
  programa_ppal.previous = NULL;
  programa_ppal.submenu = &datos;
  programa_ppal.isOn = false;

  // Establecer las conexiones del menú principal

  datos.label = "DATOS";
  datos.next = &configuracion;
  datos.previous = &salir;
  datos.submenu = &d1;
  datos.isOn = false;

  configuracion.label = "CONFIGURACION";
  configuracion.next = &bluetooth;
  configuracion.previous = &datos;
  configuracion.submenu = &c1;
  configuracion.isOn = false;

  bluetooth.label = "BLUETOOTH";
  bluetooth.next = &salir;
  bluetooth.previous = &configuracion;
  bluetooth.submenu = &t1;
  bluetooth.isOn = false;

  salir.label = "SALIR";
  salir.next = &datos;
  salir.previous = &bluetooth;
  salir.submenu = &programa_ppal;
  salir.isOn = false;

  // Establecer las conexiones del submenú "datos"

  d1.label = "BAT. CEL.";
  d1.next = &d2;
  d1.previous = &datos_salir;
  d1.submenu = NULL;
  d1.isOn = preferences.getBool("d1.isOn", "true");

  d2.label = "VELOCIDAD";
  d2.next = &d3;
  d2.previous = &d1;
  d2.submenu = NULL;
  d2.isOn = preferences.getBool("d2.isOn", "true");

  d3.label = "RPM";
  d3.next = &d4;
  d3.previous = &d2;
  d3.submenu = NULL;
  d3.isOn = preferences.getBool("d3.isOn", "true");

  d4.label = "TEMP. REF.";
  d4.next = &d5;
  d4.previous = &d3;
  d4.submenu = NULL;
  d4.isOn = preferences.getBool("d4.isOn", "true");

  d5.label = "BATERIA";
  d5.next = &d6;
  d5.previous = &d4;
  d5.submenu = NULL;
  d5.isOn = preferences.getBool("d5.isOn", "true");

  d6.label = "BOOST";
  d6.next = &datos_salir;
  d6.previous = &d5;
  d6.submenu = NULL;
  d6.isOn = preferences.getBool("d6.isOn", "true");

  d7.label = "VELOCIDAD CC";  // lo saque
  d7.next = &datos_salir;
  d7.previous = &d6;
  d7.submenu = NULL;
  d7.isOn = preferences.getBool("d7.isOn", "true");


  datos_salir.label = "ATRAS";
  datos_salir.next = &d1;
  datos_salir.previous = &d6;
  datos_salir.submenu = &datos;
  datos_salir.isOn = false;

  // Establecer las conexiones del submenú "configuracion"

  c1.label = "ESPEJOS";
  c1.next = &c2;
  c1.previous = &conf_salir;
  c1.submenu = NULL;
  c1.isOn = preferences.getBool("c1.isOn", "true");

  c2.label = "VEL. TECHO";
  c2.next = &c3;
  c2.previous = &c1;
  c2.submenu = NULL;
  c2.isOn = preferences.getBool("c2.isOn", "true");

  c3.label = "LLAVE TECHO";
  c3.next = &c4;
  c3.previous = &c2;
  c3.submenu = NULL;
  c3.isOn = preferences.getBool("c3.isOn", "true");

  c4.label = "MUTE PUERTA";
  c4.next = &c5;
  c4.previous = &c3;
  c4.submenu = NULL;
  c4.isOn = preferences.getBool("c4.isOn", "true");

  c5.label = "INF. DISPLAY";
  c5.next = &c6;
  c5.previous = &c4;
  c5.submenu = NULL;
  c5.isOn = preferences.getBool("c5.isOn", "true");

  c6.label = "WHATSAPP";
  c6.next = &c7;
  c6.previous = &c5;
  c6.submenu = NULL;
  c6.isOn = preferences.getBool("c6.isOn", "true");

  c7.label = "SPOTIFY";
  c7.next = &c8;
  c7.previous = &c6;
  c7.submenu = NULL;
  c7.isOn = preferences.getBool("c7.isOn", "true");

  c8.label = "ACTUALIZAR";
  c8.next = &conf_salir;
  c8.previous = &c7;
  c8.submenu = NULL;
  c8.isOn = preferences.getBool("c8.isOn", "true");

  conf_salir.label = "ATRAS";
  conf_salir.next = &c1;
  conf_salir.previous = &c8;
  conf_salir.submenu = &configuracion;
  conf_salir.isOn = false;

  // Establecer las conexiones del submenú "Buetooth"

  t1.label = "ACT. BT";
  t1.next = &t2;
  t1.previous = &Telefono_salir;
  t1.submenu = NULL;
  t1.isOn = preferences.getBool("t1.isOn", "true");

  t2.label = "CALL. ID";
  t2.next = &t4;
  t2.previous = &t1;
  t2.submenu = NULL;
  t2.isOn = preferences.getBool("t2.isOn", "true");

  t3.label = "EST. LLAMADA";  //Lo saque
  t3.next = &t4;
  t3.previous = &t2;
  t3.submenu = NULL;
  t3.isOn = preferences.getBool("t3.isOn", "true");

  t4.label = "NOMBRE BT";
  t4.next = &Telefono_salir;
  t4.previous = &t2;
  t4.submenu = &n1;
  t4.isOn = false;

  Telefono_salir.label = "ATRAS";
  Telefono_salir.next = &t1;
  Telefono_salir.previous = &t4;
  Telefono_salir.submenu = &bluetooth;
  Telefono_salir.isOn = false;

  // Establecer las conexiones del submenú "nombre"

  n1.label = "BRAVO";
  n1.next = &n2;
  n1.previous = &nombre_salir;
  n1.submenu = NULL;
  n1.isOn = preferences.getBool("n1.isOn", "true");

  n2.label = "PUNTO";
  n2.next = &n3;
  n2.previous = &n1;
  n2.submenu = NULL;
  n2.isOn = preferences.getBool("n2.isOn", "true");

  n3.label = "IDEA";
  n3.next = &n4;
  n3.previous = &n2;
  n3.submenu = NULL;
  n3.isOn = preferences.getBool("n3.isOn", "true");

  n4.label = "LINEA";
  n4.next = &nombre_salir;
  n4.previous = &n3;
  n4.submenu = NULL;
  n4.isOn = preferences.getBool("n4.isOn", "true");

  nombre_salir.label = "ATRAS";
  nombre_salir.next = &n1;
  nombre_salir.previous = &n4;
  nombre_salir.submenu = &t4;
  nombre_salir.isOn = false;
}


void loop_tarea2(void *pvParameters) {
  for (;;) {

    if (AudioModeUpCntrl == 1 && menu_on == true) {
      AudioModeUpCntrl = 0;

      time_out = true;
      millis_time_out = millis();

      if (currentMenu->previous != NULL) {
        currentMenu = currentMenu->previous;
        displayMenu(currentMenu);
      }
    }
    if (AudioModeDownCntrl == 1 && menu_on == true) {
      AudioModeDownCntrl = 0;

      time_out = true;
      millis_time_out = millis();

      if (currentMenu->next != NULL) {
        currentMenu = currentMenu->next;
        displayMenu(currentMenu);
      }
    }
    if (TelephoneCallSts == 1 && phone == false) {
      TelephoneCallSts = 0;

      time_out = true;
      millis_time_out = millis();

      if (currentMenu->submenu != NULL) {

        if (currentMenu->submenu == &programa_ppal) {  //si se le dio OK al Salir de primer nivel
          limpiar_display();
          menu_on = false;
          Serial.println("Si salir");
          currentMenu = &programa_ppal;
          displayMenu(currentMenu);



        } else {
          currentMenu = currentMenu->submenu;
          displayMenu(currentMenu);
          menu_on = true;
          escribiendo = true;

          scroll_Spotify = false;
          init_k = 0;  // Reinicio variables de scrol Spotify
          end_k = 14;
          mensaje_nuevo1 = false;
          mensaje_nuevo = false;

          init_m = 0;  // Reinicio variables de scrol whatsaap
          end_m = 14;
          Scroll_Whatsapp = false;
        }
      } else {
        currentMenu->isOn = !currentMenu->isOn;  //cambia estado de isOn para las variables di con i=1,2,...,7.
                                                 //A los ultimos nodos que no apuntan a un siguiente submenu. (finalizan en on / off)
        if (currentMenu == &c1) {
          preferences.putBool("c1.isOn", currentMenu->isOn);
          if (currentMenu->isOn == false) {
            desactivar_rebatimento();  // Display
          } else {
            activar_rebatimento();  //  // Display
          }
        } else if (currentMenu == &c2)
          preferences.putBool("c2.isOn", currentMenu->isOn);
        else if (currentMenu == &c3) {
          preferences.putBool("c3.isOn", currentMenu->isOn);
          if (currentMenu->isOn == false) {
            desactivar_cierre_techo();  // Display
          } else {
            activar_cierre_techo();  // Display
          }
        } else if (currentMenu == &c4)
          preferences.putBool("c4.isOn", currentMenu->isOn);
        else if (currentMenu == &c5)
          preferences.putBool("c5.isOn", currentMenu->isOn);
        else if (currentMenu == &c6)
          preferences.putBool("c6.isOn", currentMenu->isOn);
        else if (currentMenu == &c7)
          preferences.putBool("c7.isOn", currentMenu->isOn);
        else if (currentMenu == &c8)
          preferences.putBool("c8.isOn", currentMenu->isOn);
        else if (currentMenu == &d1)
          preferences.putBool("d1.isOn", currentMenu->isOn);
        else if (currentMenu == &d2)
          preferences.putBool("d2.isOn", currentMenu->isOn);
        else if (currentMenu == &d3)
          preferences.putBool("d3.isOn", currentMenu->isOn);
        else if (currentMenu == &d4)
          preferences.putBool("d4.isOn", currentMenu->isOn);
        else if (currentMenu == &d5)
          preferences.putBool("d5.isOn", currentMenu->isOn);
        else if (currentMenu == &d6)
          preferences.putBool("d6.isOn", currentMenu->isOn);
        else if (currentMenu == &t1)
          preferences.putBool("t1.isOn", currentMenu->isOn);  // Bluetooth
        else if (currentMenu == &t2)
          preferences.putBool("t2.isOn", currentMenu->isOn);  // Call ID
        else if (currentMenu == &t3)
          preferences.putBool("t3.isOn", currentMenu->isOn);  // muestra Llamada estado display
        else if (currentMenu == &n1) {
          if (currentMenu->isOn == true) {
            preferences.putBool("n1.isOn", currentMenu->isOn);  // nombres BRAVO
            preferences.putBool("n2.isOn", !currentMenu->isOn);
            preferences.putBool("n3.isOn", !currentMenu->isOn);
            preferences.putBool("n4.isOn", !currentMenu->isOn);

            Serial.println("n1 true");
            currentMenu->submenu = &t4;
          } else {
            preferences.putBool("n1.isOn", currentMenu->isOn);  // nombres PUNTO
            preferences.putBool("n2.isOn", !currentMenu->isOn);
            preferences.putBool("n3.isOn", currentMenu->isOn);
            preferences.putBool("n4.isOn", currentMenu->isOn);
            Serial.println("n1 false");
            currentMenu->submenu = &t4;
          }
        } else if (currentMenu == &n2) {
          if (currentMenu->isOn == true) {
            preferences.putBool("n1.isOn", !currentMenu->isOn);  // nombres PUNTO
            preferences.putBool("n2.isOn", currentMenu->isOn);
            preferences.putBool("n3.isOn", !currentMenu->isOn);
            preferences.putBool("n4.isOn", !currentMenu->isOn);
            Serial.println("n2 true");
            currentMenu->submenu = &t4;
          } else {
            preferences.putBool("n1.isOn", currentMenu->isOn);  // nombres IDEA
            preferences.putBool("n2.isOn", currentMenu->isOn);
            preferences.putBool("n3.isOn", !currentMenu->isOn);
            preferences.putBool("n4.isOn", currentMenu->isOn);
            currentMenu->submenu = &t4;
          }
        } else if (currentMenu == &n3) {
          if (currentMenu->isOn == true) {
            preferences.putBool("n1.isOn", !currentMenu->isOn);  // nombres IDEA
            preferences.putBool("n2.isOn", !currentMenu->isOn);
            preferences.putBool("n3.isOn", currentMenu->isOn);
            preferences.putBool("n4.isOn", !currentMenu->isOn);
            currentMenu->submenu = &t4;
            Serial.println("n3 true");
          } else {
            preferences.putBool("n1.isOn", currentMenu->isOn);  // nombres Linea
            preferences.putBool("n2.isOn", currentMenu->isOn);
            preferences.putBool("n3.isOn", currentMenu->isOn);
            preferences.putBool("n4.isOn", !currentMenu->isOn);
            currentMenu->submenu = &t4;
          }
        } else if (currentMenu == &n4) {
          if (currentMenu->isOn == true) {
            preferences.putBool("n1.isOn", !currentMenu->isOn);  // nombres Linea
            preferences.putBool("n2.isOn", !currentMenu->isOn);
            preferences.putBool("n3.isOn", !currentMenu->isOn);
            preferences.putBool("n4.isOn", currentMenu->isOn);
            currentMenu->submenu = &t4;
            Serial.println("n3 true");
          } else {
            preferences.putBool("n1.isOn", !currentMenu->isOn);  // nombres BRAVO
            preferences.putBool("n2.isOn", currentMenu->isOn);
            preferences.putBool("n3.isOn", currentMenu->isOn);
            preferences.putBool("n4.isOn", currentMenu->isOn);
            currentMenu->submenu = &t4;
          }
        }
        displayMenu(currentMenu);
      }
    }
    if ((MuteCntrl == 1) && (menu_on == true)) {

      time_out = true;
      millis_time_out = millis();

      if ((currentMenu == &c1) || (currentMenu == &c2) || (currentMenu == &c3) || (currentMenu == &c4) || (currentMenu == &c5) || (currentMenu == &c6) || (currentMenu == &c7) || (currentMenu == &c8) || (currentMenu == &conf_salir)) {
        currentMenu = &configuracion;
        displayMenu(currentMenu);
        MuteCntrl = 0;
      } else if ((currentMenu == &d1) || (currentMenu == &d2) || (currentMenu == &d3) || (currentMenu == &d4) || (currentMenu == &d5) || (currentMenu == &d6) || (currentMenu == &d7) || (currentMenu == &datos_salir)) {
        currentMenu = &datos;
        displayMenu(currentMenu);
        MuteCntrl = 0;
      } else if ((currentMenu == &t1) || (currentMenu == &t2) || (currentMenu == &t3) || (currentMenu == &t4) || (currentMenu == &Telefono_salir)) {
        currentMenu = &bluetooth;
        displayMenu(currentMenu);
        MuteCntrl = 0;
      } else if ((currentMenu == &n1) || (currentMenu == &n2) || (currentMenu == &n3) || (currentMenu == &n4) || (currentMenu == &nombre_salir)) {
        currentMenu = &t4;
        displayMenu(currentMenu);
        MuteCntrl = 0;
      } else {
        MuteCntrl = 0;
        menu_on = false;
        currentMenu = &programa_ppal;
        limpiar_display();
      }
    }

    if (phone == true) {

      MuteCntrl = 0;
      menu_on = false;
      currentMenu = &programa_ppal;
    }

    //------------------------------------------ millis tiempo fuera 30 seg -----------------------------------------------------//

    if ((time_out == true) && (millis() - millis_time_out >= 30000) && (menu_on == true)) {
      time_out = false;
      menu_on = false;
      currentMenu = &programa_ppal;
      Serial.println("Cierro menu por time out");
      limpiar_display();
    }
    //--------------------------------------------- suspendo tarea -----------------------------------------------------//

    // if (menu_on == false) {
    //   Serial.println("Suspendo tarea Menu");
    //   vTaskSuspend(NULL);
    // }
  }
}


void displayMenu(MenuItem *menu) {
  String Label = menu->label;
  // printf("===Actual: %s ===\n", Label);

  if ((menu->submenu == NULL) && (currentMenu != &n1) && (currentMenu != &n2) && (currentMenu != &n3) && (currentMenu != &n4) && (currentMenu != &c8)) {  //para los ultimos nodos de las ramas que terminan en config de off/on
    if (menu->isOn == false) {
      printf("status: OFF\n");
      Label = Label + "\nOFF";

    } else {
      printf("status: ON\n");
      Label = Label + "\nON";
    }
    vTaskDelay(pdMS_TO_TICKS(50));
  }

  while (semaforo_can == true) { vTaskDelay(pdMS_TO_TICKS(1)); }
  semaforo_can = true;

  ascii2sixbits(Label);

  if ((currentMenu == &datos) || (currentMenu == &configuracion) || (currentMenu == &bluetooth) || (currentMenu == &salir)) {

    Serial.println("nivel 1");

    byte can_msg[8]{ 0x30, 0x1C, 0x61, 0x06, 0x60, 0xFD, 0xB7, 0x54 };   // 79 A6 4C 64 F6 BF  // Enviar "MENU PRINCIPAL" Y DOS SALTOS DE LINEA
    byte can_msg1[8]{ 0x31, 0x1C, 0x64, 0xe5, 0x1b, 0x31, 0x7f, 0xc0 };  // 2C B0 00 00 00 3F
    byte can_msg2[8];                                                    //
    byte can_msg3[8];                                                    //

    can_msg2[0] = 0x32;
    can_msg2[1] = 0x1C;
    can_msg3[0] = 0x33;
    can_msg3[1] = 0x1C;
    can_msg2[2] = sixBit[0];
    can_msg2[3] = sixBit[1];
    can_msg2[4] = sixBit[2];
    can_msg2[5] = sixBit[3];
    can_msg2[6] = sixBit[4];
    can_msg2[7] = sixBit[5];

    can_msg3[2] = sixBit[6];
    can_msg3[3] = sixBit[7];
    can_msg3[4] = sixBit[8];
    can_msg3[5] = sixBit[9];
    can_msg3[6] = sixBit[10];
    can_msg3[7] = sixBit[11];

    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg);
    vTaskDelay(pdMS_TO_TICKS(20));
    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg1);
    vTaskDelay(pdMS_TO_TICKS(20));
    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg2);
    vTaskDelay(pdMS_TO_TICKS(20));
    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg3);
    vTaskDelay(pdMS_TO_TICKS(20));

  } else if ((currentMenu == &d1) || (currentMenu == &d2) || (currentMenu == &d3) || (currentMenu == &d4) || (currentMenu == &d5) || (currentMenu == &d6) || (currentMenu == &d7) || (currentMenu == &datos_salir)) {
    Serial.println("nivel d1");
    byte can_msg[8]{ 0x30, 0x1C, 0x3C, 0xC7, 0xDA, 0x7B, 0xF8, 0x50 };   // 79 A6 4C 64 F6 BF  // Enviar "DATOS VEHICULO" Y DOS SALTOS DE LINEA
    byte can_msg1[8]{ 0x31, 0x1C, 0x4d, 0x43, 0xa0, 0x5d, 0xaf, 0xc0 };  // 2C B0 00 00 00 3F
    byte can_msg2[8];                                                    //
    byte can_msg3[8];                                                    //

    can_msg2[0] = 0x32;
    can_msg2[1] = 0x1C;
    can_msg3[0] = 0x33;
    can_msg3[1] = 0x1C;
    can_msg2[2] = sixBit[0];
    can_msg2[3] = sixBit[1];
    can_msg2[4] = sixBit[2];
    can_msg2[5] = sixBit[3];
    can_msg2[6] = sixBit[4];
    can_msg2[7] = sixBit[5];

    can_msg3[2] = sixBit[6];
    can_msg3[3] = sixBit[7];
    can_msg3[4] = sixBit[8];
    can_msg3[5] = sixBit[9];
    can_msg3[6] = sixBit[10];
    can_msg3[7] = sixBit[11];

    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg);
    vTaskDelay(pdMS_TO_TICKS(20));
    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg1);
    vTaskDelay(pdMS_TO_TICKS(20));
    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg2);
    vTaskDelay(pdMS_TO_TICKS(20));
    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg3);
    vTaskDelay(pdMS_TO_TICKS(20));

  } else if ((currentMenu == &c1) || (currentMenu == &c2) || (currentMenu == &c3) || (currentMenu == &c4) || (currentMenu == &c5) || (currentMenu == &c6) || (currentMenu == &c7) || (currentMenu == &c8) || (currentMenu == &conf_salir)) {
    Serial.println("nivel c1");

    byte can_msg[8]{ 0x30, 0x1C, 0x39, 0xA6, 0x51, 0x51, 0x28, 0x1D };   // 79 A6 4C 64 F6 BF  // Enviar "CONFIGURACION" Y DOS SALTOS DE LINEA
    byte can_msg1[8]{ 0x31, 0x1C, 0x30, 0xE5, 0x1A, 0x67, 0xff, 0xc0 };  // 2C B0 00 00 00 3F
    byte can_msg2[8];                                                    //
    byte can_msg3[8];                                                    //

    can_msg2[0] = 0x32;
    can_msg2[1] = 0x1C;
    can_msg3[0] = 0x33;
    can_msg3[1] = 0x1C;
    can_msg2[2] = sixBit[0];
    can_msg2[3] = sixBit[1];
    can_msg2[4] = sixBit[2];
    can_msg2[5] = sixBit[3];
    can_msg2[6] = sixBit[4];
    can_msg2[7] = sixBit[5];

    can_msg3[2] = sixBit[6];
    can_msg3[3] = sixBit[7];
    can_msg3[4] = sixBit[8];
    can_msg3[5] = sixBit[9];
    can_msg3[6] = sixBit[10];
    can_msg3[7] = sixBit[11];

    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg);
    vTaskDelay(pdMS_TO_TICKS(20));
    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg1);
    vTaskDelay(pdMS_TO_TICKS(20));
    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg2);
    vTaskDelay(pdMS_TO_TICKS(20));
    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg3);
    vTaskDelay(pdMS_TO_TICKS(20));

  } else if ((currentMenu == &t1) || (currentMenu == &t2) || (currentMenu == &t3) || (currentMenu == &t4) || (currentMenu == &Telefono_salir)) {
    Serial.println("nivel t1");

    byte can_msg[8]{ 0x30, 0x1C, 0x7d, 0x05, 0xd0, 0x45, 0xa6, 0x5a };   // 79 A6 4C 64 F6 BF  // Enviar "Telefono" Y DOS SALTOS DE LINEA
    byte can_msg1[8]{ 0x31, 0x1C, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x3f };  // 2C B0 00 00 00 3F
    byte can_msg2[8];                                                    //
    byte can_msg3[8];                                                    //

    can_msg2[0] = 0x32;
    can_msg2[1] = 0x1C;
    can_msg3[0] = 0x33;
    can_msg3[1] = 0x1C;
    can_msg2[2] = sixBit[0];
    can_msg2[3] = sixBit[1];
    can_msg2[4] = sixBit[2];
    can_msg2[5] = sixBit[3];
    can_msg2[6] = sixBit[4];
    can_msg2[7] = sixBit[5];

    can_msg3[2] = sixBit[6];
    can_msg3[3] = sixBit[7];
    can_msg3[4] = sixBit[8];
    can_msg3[5] = sixBit[9];
    can_msg3[6] = sixBit[10];
    can_msg3[7] = sixBit[11];

    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg);
    vTaskDelay(pdMS_TO_TICKS(20));
    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg1);
    vTaskDelay(pdMS_TO_TICKS(20));
    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg2);
    vTaskDelay(pdMS_TO_TICKS(20));
    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg3);
    vTaskDelay(pdMS_TO_TICKS(20));

  } else if ((currentMenu == &n1) || (currentMenu == &n2) || (currentMenu == &n3) || (currentMenu == &n4) || (currentMenu == &nombre_salir)) {
    Serial.println("nivel n1");
    byte can_msg[8]{ 0x30, 0x1C, 0x41, 0x74, 0x12, 0x53, 0xf3, 0x20 };   // 79 A6 4C 64 F6 BF  // Enviar "Elegi \n AUTO" Y DOS SALTOS DE LINEA
    byte can_msg1[8]{ 0x31, 0x1C, 0x7d, 0xa0, 0x00, 0x00, 0x00, 0x3f };  // 2C B0 00 00 00 3F
    byte can_msg2[8];                                                    //
    byte can_msg3[8];                                                    //

    can_msg2[0] = 0x32;
    can_msg2[1] = 0x1C;
    can_msg3[0] = 0x33;
    can_msg3[1] = 0x1C;
    can_msg2[2] = sixBit[0];
    can_msg2[3] = sixBit[1];
    can_msg2[4] = sixBit[2];
    can_msg2[5] = sixBit[3];
    can_msg2[6] = sixBit[4];
    can_msg2[7] = sixBit[5];

    can_msg3[2] = sixBit[6];
    can_msg3[3] = sixBit[7];
    can_msg3[4] = sixBit[8];
    can_msg3[5] = sixBit[9];
    can_msg3[6] = sixBit[10];
    can_msg3[7] = sixBit[11];

    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg);
    vTaskDelay(pdMS_TO_TICKS(20));
    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg1);
    vTaskDelay(pdMS_TO_TICKS(20));
    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg2);
    vTaskDelay(pdMS_TO_TICKS(20));
    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg3);
    vTaskDelay(pdMS_TO_TICKS(20));
  }
  semaforo_can = false;
}
