#include "BRAVO.h"

/*
El display tiene para mostrar 14 caracteres por linea. El display se divide en 4 lineas. Total de 56 caracteres
La cantidad maxima de frames q se pueden enviar es 7. Cada frames contienen 8 caracteres. Total de 56 caracteres
Cada mensaje enviado por CANBUS tiene que tener un retraso de 20ms del anterior
*/

//------------------------------------ Funcion refresh display ---------------------------------------------//

void limpiar_display() {


  byte can_msg[8]{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };  // Borra los datos en la pantalla
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg);

  vTaskDelay(pdMS_TO_TICKS(10));
  escribiendo = false;
  scroll_llamada = false;
  llamada_en_curso = false;
  llamada_entrante = false;
  marcando = false;
  phone = false;
  Serial.println("Limpio Display");
}

//------------------------------------ Funcion refresh mensaje sobre ---------------------------------------------//

void limpiar_sobre() {

  byte can_msg[8]{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };  // Borro sobresito
  CAN0.sendMsgBuf(0x5C7, 0, 8, can_msg);

  vTaskDelay(pdMS_TO_TICKS(10));
}

//------------------------------------ Funcion Escribir Aire AC ON ---------------------------------------------//

void aire_AC_encendido() {

  byte can_msg[8]{ 0x30, 0x02, 0x31, 0x47, 0x50, 0xFC, 0xC3, 0x9A };   // 31 47 50 FC C3 9A (AIRE ACONDICIONO)
  byte can_msg1[8]{ 0x31, 0x02, 0x64, 0xF5, 0x0E, 0x51, 0xA6, 0x4C };  // 64 F5 0E 51 A6 4C
  byte can_msg2[8]{ 0x32, 0x02, 0x3D, 0xA0, 0x3F, 0x41, 0x93, 0x90 };  // 3D AO 3F 41 93 90 (DO ENCENDIDO)
  byte can_msg3[8]{ 0x33, 0x02, 0x64, 0xF5, 0x0F, 0x68, 0x00, 0x00 };  // 64 F5 0F 68 00 00
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg1);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg2);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg3);
  vTaskDelay(pdMS_TO_TICKS(20));


  mensaje_nuevo = true;
  prevInfo = millis();
}

//-------------------------------- Funcion Escribir Aire AC OFF ----------------------------------------------//

void aire_AC_apagado() {

  byte can_msg[8]{ 0x30, 0x02, 0x31, 0x47, 0x50, 0xFC, 0xC3, 0x9A };   // 31 47 50 FC C3 9A (AIRE ACONDICIONO)
  byte can_msg1[8]{ 0x31, 0x02, 0x64, 0xF5, 0x0E, 0x51, 0xA6, 0x4C };  // 64 F5 0E 51 A6 4C
  byte can_msg2[8]{ 0x32, 0x02, 0x3D, 0xA0, 0x3F, 0x31, 0xB3, 0x12 };  // 3D A0 3F 31 B3 12 (DO APAGADO)
  byte can_msg3[8]{ 0x33, 0x02, 0x30, 0XF6, 0x80, 0x00, 0x00, 0x00 };  // 30 F6 80 00 00 00
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg1);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg2);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg3);
  vTaskDelay(pdMS_TO_TICKS(20));


  mensaje_nuevo = true;
  prevInfo = millis();
}

//---------------------------------- Funcion Escribir Freno de mano puesto ---------------------------------------//

void freno_de_mano() {

  byte can_msg[8]{ 0x20, 0x02, 0x45, 0xD4, 0x19, 0x68, 0x03, 0xD0 };   // 45 D4 19 68 03 DO (FRENO DE MANO A)
  byte can_msg1[8]{ 0x21, 0x02, 0xFD, 0x83, 0x19, 0x6B, 0xF3, 0x1D };  // FD 83 19 6B F3 1D
  byte can_msg2[8]{ 0x22, 0x02, 0x75, 0x43, 0x4C, 0x00, 0x00, 0x00 };  // 75 D5 OD 00 00 00 (ARRIBA)
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg1);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg2);
  vTaskDelay(pdMS_TO_TICKS(20));


  mensaje_nuevo = true;
  prevInfo = millis();
}

//---------------------------------- Funcion Escribir rebatir espejos activado ---------------------------------------//

void activar_rebatimento() {

  byte can_msg[8]{ 0x40, 0x02, 0x75, 0x03, 0x4C, 0x7D, 0x46, 0x14 };
  byte can_msg1[8]{ 0x41, 0x02, 0x41, 0x97, 0xda, 0xfc, 0xc8, 0x1f };
  byte can_msg2[8]{ 0x42, 0x02, 0x69, 0x83, 0x1f, 0x50, 0xe6, 0xbF };
  byte can_msg3[8]{ 0x43, 0x02, 0xfc, 0xc3, 0x9f, 0x52, 0x13, 0x0f };
  byte can_msg4[8]{ 0x44, 0x02, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00 };
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg1);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg2);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg3);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg4);
  vTaskDelay(pdMS_TO_TICKS(2500));
}

//---------------------------------- Funcion Escribir rebatir espejos desactivado -------------------------------------//

void desactivar_rebatimento() {

  byte can_msg[8]{ 0x40, 0x02, 0x75, 0x03, 0x4C, 0x7D, 0x46, 0x14 };
  byte can_msg1[8]{ 0x41, 0x02, 0x41, 0x97, 0xda, 0xfc, 0xc8, 0x1f };
  byte can_msg2[8]{ 0x42, 0x02, 0x69, 0x83, 0x1f, 0x50, 0xe6, 0xbF };
  byte can_msg3[8]{ 0x43, 0x02, 0xfc, 0xf4, 0x1e, 0x30, 0xe7, 0xd4 };
  byte can_msg4[8]{ 0x44, 0x02, 0x84, 0xc3, 0xda, 0x00, 0x00, 0x00 };
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg1);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg2);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg3);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg4);
  vTaskDelay(pdMS_TO_TICKS(2500));
}

//------------------------------------- Funcion Escribir activar cierre de techo ----------------------------------------------//

void activar_cierre_techo() {

  byte can_msg[8]{ 0x30, 0x02, 0x39, 0x44, 0x1d, 0x75, 0x00, 0x1f };  // cierre techo \n techo \n\n activado
  byte can_msg1[8]{ 0x31, 0x02, 0x40, 0xe4, 0xDa, 0xfd, 0x75, 0xcc };
  byte can_msg2[8]{ 0x32, 0x02, 0x85, 0x0f, 0xff, 0x30, 0xe7, 0xd4 };
  byte can_msg3[8]{ 0x33, 0x02, 0x84, 0xc3, 0xda, 0x00, 0x00, 0x00 };
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg1);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg2);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg3);
  vTaskDelay(pdMS_TO_TICKS(2500));
}

//------------------------------------------ Funcion Escribir Desactivar cierre de techo ---------------------------------------------//

void desactivar_cierre_techo() {

  byte can_msg[8]{ 0x30, 0x02, 0x39, 0x44, 0x1d, 0x75, 0x00, 0x1f };  // cierre techo \n techo \n\n desactivado
  byte can_msg1[8]{ 0x31, 0x02, 0x40, 0xe4, 0xDa, 0xfd, 0x75, 0xcc };
  byte can_msg2[8]{ 0x32, 0x02, 0x85, 0x0f, 0xff, 0x3d, 0x07, 0x8c };
  byte can_msg3[8]{ 0x33, 0x02, 0x39, 0xf5, 0x21, 0x30, 0xf6, 0x80 };
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg1);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg2);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg3);
  vTaskDelay(pdMS_TO_TICKS(2500));
}

//------------------------------------------ Funcion Escribir Whatsapp y enviar sobre ---------------------------------------------//

void send_Whatsapp() {
  if (menu_on == false) {

    byte can_msg[8]{ 0x00, 0x0A, 0x89, 0x33, 0x1F, 0x78, 0xC6, 0xDB };  // WHATSAPP + Sobre
    CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg);

    // vTaskDelay(pdMS_TO_TICKS(20);
    mensaje_whatsapp = true;
    // Serial.println("mensaje whatsapp");
    prevwhatsapp = millis();
  }
}

//------------------------------------------ Funcion Escribir Mensaje Whatsapp + remitente ---------------------------------------------//

void send_Name_Whatsapp(String mensaje_W) {

  byte can_msgW[8]{ 0x30, 0x02, 0x75, 0x06, 0x14, 0x7D, 0x06, 0x5F };   // 75 06 14 7D 06 5F
  byte can_msg1W[8]{ 0x31, 0x02, 0x40, 0x00, 0x00, 0x00, 0x0F, 0xFF };  // 42 8A 28 A2 8A 3F
  byte can_msg2W[8];
  byte can_msg3W[8];

  //ascii2sixbits(mensaje_W);

  if (Scroll_Whatsapp == false) {
    ascii2sixbits(mensaje_W);
    prevInfo = millis();
    mensaje_nuevo = true;
  } else {
    mensaje_nuevo1 = true;
    prevInfo_Scroll = millis();
    // Serial.println(mensaje_Spotify.substring(init_k, end_k));
    // Serial.println(init_k);
    // Serial.println(end_k);
    ascii2sixbits(mensaje_W.substring(init_m, end_m));
    // Serial.println("mensaje spotify scroll");
    init_m = init_m + 1;
    end_m = end_m + 1;
  }


  can_msg2W[0] = 0x32;
  can_msg2W[1] = 0x02;
  can_msg2W[2] = sixBit[0];
  can_msg2W[3] = sixBit[1];
  can_msg2W[4] = sixBit[2];
  can_msg2W[5] = sixBit[3];
  can_msg2W[6] = sixBit[4];
  can_msg2W[7] = sixBit[5];

  can_msg3W[0] = 0x33;
  can_msg3W[1] = 0x02;
  can_msg3W[2] = sixBit[6];
  can_msg3W[3] = sixBit[7];
  can_msg3W[4] = sixBit[8];
  can_msg3W[5] = sixBit[9];
  can_msg3W[6] = sixBit[10];
  can_msg3W[7] = sixBit[11];


  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msgW);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg1W);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg2W);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg3W);
  vTaskDelay(pdMS_TO_TICKS(20));

  // Serial.println("remitente whatsapp");
  // mensaje_nuevo = true;
  // prevInfo = millis();
}

//------------------------------------------ Funcion Escribir Artista sonando Spotify ---------------------------------------------//

void send_Spotify(String mensaje_Spotify) {

  byte can_msgS[8]{ 0x30, 0x1C, 0x79, 0xA6, 0x4C, 0x64, 0xF6, 0x8B };   // 79 A6 4C 64 F6 BF  // Enviar "SONANDO..." Y DOS SALTOS DE LINEA
  byte can_msg1S[8]{ 0x31, 0x1C, 0x00, 0x0F, 0xFF, 0x00, 0x00, 0x3F };  // 2C B0 00 00 00 3F
  byte can_msg2S[8];                                                    // Artista Sonando ESCROL
  byte can_msg3S[8];                                                    //

  if (scroll_Spotify == false) {
    ascii2sixbits(mensaje_Spotify);
    prevInfo = millis();
    mensaje_nuevo = true;
    // Serial.println("mensaje spotify");
  } else {
    mensaje_nuevo1 = true;
    prevInfo_Scroll = millis();
    // Serial.println(mensaje_Spotify.substring(init_k, end_k));
    // Serial.println(init_k);
    // Serial.println(end_k);
    ascii2sixbits(mensaje_Spotify.substring(init_k, end_k));
    // Serial.println("mensaje spotify scroll");
    init_k = init_k + 1;
    end_k = end_k + 1;
  }

  can_msg2S[0] = 0x32;
  can_msg2S[1] = 0x1C;
  can_msg2S[2] = sixBit[0];
  can_msg2S[3] = sixBit[1];
  can_msg2S[4] = sixBit[2];
  can_msg2S[5] = sixBit[3];
  can_msg2S[6] = sixBit[4];
  can_msg2S[7] = sixBit[5];

  can_msg3S[0] = 0x33;
  can_msg3S[1] = 0x1C;
  can_msg3S[2] = sixBit[6];
  can_msg3S[3] = sixBit[7];
  can_msg3S[4] = sixBit[8];
  can_msg3S[5] = sixBit[9];
  can_msg3S[6] = sixBit[10];
  can_msg3S[7] = sixBit[11];

  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msgS);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg1S);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg2S);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg3S);
  vTaskDelay(pdMS_TO_TICKS(20));


  // if (init_k == 1) {
  //   vTaskDelay(pdMS_TO_TICKS(500);
  // }
}

//------------------------------------------ Funcion Escribir Calles de Maps ---------------------------------------------//

void send_Maps(String mensaje_Maps) {

  byte can_msgS[8]{ 0x30, 0x1C, 0x79, 0xA6, 0x4C, 0x64, 0xF6, 0x8B };   // 79 A6 4C 64 F6 BF  // Enviar "SONANDO..." Y DOS SALTOS DE LINEA
  byte can_msg1S[8]{ 0x31, 0x1C, 0x00, 0x0F, 0xFF, 0x00, 0x00, 0x3F };  // 2C B0 00 00 00 3F
  byte can_msg2S[8];                                                    // Artista Sonando ESCROL
  byte can_msg3S[8];                                                    //

  if (scroll_Maps == false) {
    ascii2sixbits(mensaje_Maps);
    prevInfo = millis();
    mensaje_nuevo = true;
  } else {
    mensaje_nuevo1 = true;
    prevInfo_Scroll = millis();
    ascii2sixbits(mensaje_Maps.substring(init_k, end_k));
    init_k = init_k + 1;
    end_k = end_k + 1;
  }

  can_msg2S[0] = 0x32;
  can_msg2S[1] = 0x1C;
  can_msg2S[2] = sixBit[0];
  can_msg2S[3] = sixBit[1];
  can_msg2S[4] = sixBit[2];
  can_msg2S[5] = sixBit[3];
  can_msg2S[6] = sixBit[4];
  can_msg2S[7] = sixBit[5];

  can_msg3S[0] = 0x33;
  can_msg3S[1] = 0x1C;
  can_msg3S[2] = sixBit[6];
  can_msg3S[3] = sixBit[7];
  can_msg3S[4] = sixBit[8];
  can_msg3S[5] = sixBit[9];
  can_msg3S[6] = sixBit[10];
  can_msg3S[7] = sixBit[11];

  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msgS);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg1S);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg2S);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg3S);
  vTaskDelay(pdMS_TO_TICKS(20));


  // if (init_k == 1) {
  //   vTaskDelay(pdMS_TO_TICKS(500);
  // }
}
//------------------------------------------ Funcion Escribir Enviar sobre mensaje al display ---------------------------------------------//

void Display_sobre() {

  byte SMS[8]{ 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24 };   // Solo mando los bit correspondientes al estado del sobresito naranja
  byte SMS1[8]{ 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24 };  //
  byte SMS2[8]{ 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24 };
  CAN0.sendMsgBuf(0x5C7, 0, 8, SMS);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5C7, 0, 8, SMS1);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5C7, 0, 8, SMS2);
  vTaskDelay(pdMS_TO_TICKS(20));


  // Serial.println("Envio Sobre");

  mensaje_sobre = true;
  prevInfo_SMS = millis();
}

//------------------------------------------ Funcion Escribir Mute + Parlante tachado ---------------------------------------------//

void Mute_press() {

  byte can_msg[8]{ 0x00, 0x0E, 0x62, 0x07, 0xD0, 0x00, 0x00, 0x00 };  // Mute + Parlante tachado
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg);
  vTaskDelay(pdMS_TO_TICKS(20));
  mensaje_nuevo = true;
  // Serial.println("Mute");
  prevInfo = millis();
}

//------------------------------------------ Funcion Escribir Enviar dato de bateria telefono ---------------------------------------------//

void Info_telefono() {  // B&M configuracion y datos de envio al menu de telefono

  millis_3E7 = millis();

  if (phone == true) {
    bitWrite(INFO_tel[7], 0, 1);  // 0001 llamada funcionando 
    bitWrite(INFO_tel[7], 2, 0); 
    // Serial.println("musica false 2");
  } else {
    bitWrite(INFO_tel[7], 0, 0);
    if (bym_on == true) {  // vuelvo al blue and me si lo estaba previamente
      bitWrite(INFO_tel[7], 2, 1);
    }
  }

  if (voice == true) {
    bitWrite(INFO_tel[7], 1, 1);
    // bitWrite(INFO_tel[7], 2, 0);
    // Serial.println("musica false 3");
  } else {
    bitWrite(INFO_tel[7], 1, 0);
    if (bym_on == true) {  // vuelvo al blue and me si lo estaba previamente
      // bitWrite(INFO_tel[7], 2, 1);
    }
  }

  while (semaforo_can == true) { vTaskDelay(pdMS_TO_TICKS(1)); }
  semaforo_can = true;  // tomo el uso de la CAN

  ascii2sixbits(*dato_display);  // envio datos para ser convertidos a formato AUTO

  INFO_tel[0] = sixBit[0];
  INFO_tel[1] = sixBit[1];
  INFO_tel[2] = sixBit[2];
  INFO_tel[3] = sixBit[3];
  INFO_tel[4] = sixBit[4];
  INFO_tel[5] = sixBit[5];

  if (contacto == true) {

    if (menu_on == true || phone == true) {  // compruevo si esta el menu activo asi mando el bit que no tiene que escuchar el estereo los pusadores
      INFO_tel[6] = 0xC4;
      if (phone == true) {
        INFO_tel[6] = 0xE4;
      }

      CAN0.sendMsgBuf(0x707, 0, 2, INFO_2);  //
      vTaskDelay(pdMS_TO_TICKS(20));

    } else {
      INFO_tel[6] = 0xc0;

      CAN0.sendMsgBuf(0x707, 0, 2, INFO_2);  //
      vTaskDelay(pdMS_TO_TICKS(20));
    }

    CAN0.sendMsgBuf(0x3E7, 0, 8, INFO_tel);  // el byte 4 y 5 son los 3 caracteres del porcentaje de bateria
    vTaskDelay(pdMS_TO_TICKS(20));

  } else if (contador <= 10) {

    contador++;
    CAN0.sendMsgBuf(0x707, 0, 2, INFO_1);  //
    vTaskDelay(pdMS_TO_TICKS(20));
  }
          // for (int ii = 0; ii < 7; ii++) {
          //   Serial.print(INFO_tel[ii]);  // Imprime mensajes de rxBuf
          //   Serial.print("  ");
          // }
          // Serial.println(";");

  semaforo_can = false;
}

//-------------------------------------------- Escribo control CC controlando ---------------------------------------------------//

void Contro_CC() {

  byte can_msg[8]{ 0x30, 0x02, 0x39, 0x0a6, 0x5f, 0x75, 0xa5, 0xFF };  // Control CC RUN
  byte can_msg1[8]{ 0x31, 0x02, 0x38, 0xef, 0xff, 0x76, 0x06, 0x40 };
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg1);
  vTaskDelay(pdMS_TO_TICKS(20));


  mensaje_nuevo = true;
  prevInfo = millis();
}
//------------------------------------------ Funcion Escribir Llamada + remitente ---------------------------------------------//

void llamada_texto(String llamada) {

  byte can_msg2L[8];
  byte can_msg3L[8];
  //   byte can_msgL[8]{ 0x30, 0x1C, 0x79, 0xA6, 0x4C, 0x64, 0xF6, 0x8B };   // 79 A6 4C 64 F6 BF  // Enviar "SONANDO..." Y DOS SALTOS DE LINEA
  // byte can_msg1L[8]{ 0x31, 0x1C, 0x00, 0x0F, 0xFF, 0x00, 0x00, 0x3F };  // 2C B0 00 00 00 3F
  byte can_msgL[8];
  byte can_msg1L[8];

  if (llamada_en_curso == true) {
    // Serial.println("remitente cursando");

    can_msgL[0] = 0x30;
    can_msgL[1] = 0x02;
    can_msgL[2] = 0x41;
    can_msgL[3] = 0x9f;
    can_msgL[4] = 0xd7;
    can_msgL[5] = 0x5c;
    can_msgL[6] = 0xc6;
    can_msgL[7] = 0x0c;

    can_msg1L[0] = 0x31;
    can_msg1L[1] = 0x02;
    can_msg1L[2] = 0x3c;
    can_msg1L[3] = 0xcf;
    can_msg1L[4] = 0xce;
    can_msg1L[5] = 0x69;
    can_msg1L[6] = 0x90;
    can_msg1L[7] = 0x3f;

    // llamada_en_curso = false;

  } else if (marcando == true) {
    // Serial.println("marcando");

    can_msgL[0] = 0x30;
    can_msgL[1] = 0x02;
    can_msgL[2] = 0x60;
    can_msgL[3] = 0xc7;
    can_msgL[4] = 0x4e;
    can_msgL[5] = 0x31;
    can_msgL[6] = 0x93;
    can_msgL[7] = 0xda;

    can_msg1L[0] = 0x31;
    can_msg1L[1] = 0x02;
    can_msg1L[2] = 0xfc;
    can_msg1L[3] = 0xcf;
    can_msg1L[4] = 0xc0;
    can_msg1L[5] = 0x00;
    can_msg1L[6] = 0x00;
    can_msg1L[7] = 0x3f;

    // marcando = false;

  } else if (llamada_entrante == true) {
    Serial.println("remitente entrante");

    can_msgL[0] = 0x30;
    can_msgL[1] = 0x02;
    can_msgL[2] = 0x5d;
    can_msgL[3] = 0x73;
    can_msgL[4] = 0x18;
    can_msgL[5] = 0x30;
    can_msgL[6] = 0xf3;
    can_msgL[7] = 0x3f;

    can_msg1L[0] = 0x31;
    can_msg1L[1] = 0x02;
    can_msg1L[2] = 0x3d;
    can_msg1L[3] = 0x0f;
    can_msg1L[4] = 0xc0;
    can_msg1L[5] = 0x00;
    can_msg1L[6] = 0x00;
    can_msg1L[7] = 0x3f;

    // llamada_entrante = false;
  }

  if (scroll_llamada == false) {
    ascii2sixbits(llamada);
  } else {
    mensaje_nuevo1 = true;
    prevInfo_Scroll = millis();
    ascii2sixbits(llamada.substring(init_L, end_L));
    init_L = init_L + 1;
    end_L = end_L + 1;
    // Serial.println("Activa el scroll al ver que es largo");
  }
  Serial.println(llamada.substring(init_L, end_L));


  can_msg2L[0] = 0x32;
  can_msg2L[1] = 0x02;
  can_msg2L[2] = sixBit[0];
  can_msg2L[3] = sixBit[1];
  can_msg2L[4] = sixBit[2];
  can_msg2L[5] = sixBit[3];
  can_msg2L[6] = sixBit[4];
  can_msg2L[7] = sixBit[5];

  can_msg3L[0] = 0x33;
  can_msg3L[1] = 0x02;
  can_msg3L[2] = sixBit[6];
  can_msg3L[3] = sixBit[7];
  can_msg3L[4] = sixBit[8];
  can_msg3L[5] = sixBit[9];
  can_msg3L[6] = sixBit[10];
  can_msg3L[7] = sixBit[11];

  // while (semaforo_can == true) { vTaskDelay(1); }
  // semaforo_can = true;

  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msgL);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg1L);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg2L);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x5e7, 0, 8, can_msg3L);
  vTaskDelay(pdMS_TO_TICKS(20));
  // semaforo_can = false;
}

// Serial.println("remitente Llamada");
