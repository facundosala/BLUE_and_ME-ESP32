#include "BRAVO.h"

//------------------------------- Devuelve el valor del bit en la posición especificada ----------------------------------------//

bool getBit(byte b, int pos) {
  return bitRead(b, pos);  // b = byte y pos = posicion de interes
}

//--------------------------------------- Mute al abrir la puerta conductor ----------------------------------------------//

void mute_open_door_driver() {
  byte can_msg_mute[2]{ 0x20, 0x10 };  // Mensaje comando Mute

  DriverDoorSts = bitRead(STATUS_NCM_1, 2);

  if (DriverDoorSts == 0 && primera_vez_2 == 0) {
    primera_vez_2 = 1;
    estado_puerta = 0;
  } else {
    if (DriverDoorSts == 1 && estado_puerta == 0) {
      estado_puerta = 1;
      CAN0.sendMsgBuf(0x3A0, 0, 2, can_msg_mute);  // Mandar el comando mute
      // Mute_press();
    }
    if (DriverDoorSts != 1 && estado_puerta == 1) {
      estado_puerta = 0;
      CAN0.sendMsgBuf(0x3A0, 0, 2, can_msg_mute);  // Mandar el comando mute
    }
  }
}
//---------------------------------------- Estado Aire Acondicionado -------------------------------------------//
void Aire_AC() {

  if (escribiendo == 0) {
    if (primera_vez_1 == 0) {
      CompressorAcReqSts = bitRead(info_AC_0, 2);
      primera_vez_1 = 1;
    } else {
      if (CompressorAcReqSts != bitRead(info_AC_0, 2)) {
        CompressorAcReqSts = bitRead(info_AC_0, 2);
        if (CompressorAcReqSts) {
          scroll_Spotify = false;
          aire_AC_encendido();
        } else {
          scroll_Spotify = false;
          aire_AC_apagado();
        }
      }
    }
    // if (primera_vez_3 == 0) {
    //   RHeatedWindowCntrl = bitRead(info_AC_0, 5);
    //   primera_vez_3 = 1;
    // } else {
    //   if (RHeatedWindowCntrl != bitRead(info_AC_0, 5)) {
    //     RHeatedWindowCntrl = bitRead(info_AC_0, 5);
    //     if (RHeatedWindowCntrl) {
    //       caletador_ventanas_on();
    //     } else {
    //       calentador_ventanas_off();
    //     }
    //   }
    // }
  }
}

//---------------------------------------- Estado Freno de mano puesto -------------------------------------------//

void Freno_mano() {

  if (escribiendo == 0) {
    if (primera_vez_4 == 0) {
      HandBrakeSts = bitRead(STATUS_NCM_0, 5);
      primera_vez_4 = 1;
      // Serial.println("freno de mano");
    } else {
      if (HandBrakeSts != bitRead(STATUS_NCM_0, 5)) {
        HandBrakeSts = bitRead(STATUS_NCM_0, 5);
        if (HandBrakeSts) {
          scroll_Spotify = false;
          init_m = 0;
          end_m = 14;
          freno_de_mano();
        }
      }
    }
  }
}

//--------------------------------------- Abrir espejos ----------------------------------------------------------//

void abrir_espejos() {
  if (contacto == true && abrirx2 == true && Estado_espejos == false) {
    pinMode(OPEN_MIRR, OUTPUT);
    digitalWrite(OPEN_MIRR, HIGH);
    Serial.println("Abre Espejos");
    abrirx2 = false;
    abrir_cerrar = true;
    milis_abrir_cerrar = millis();
    preferences.putBool("Estado_espejos", true);
  }
}

//--------------------------------------------Cerrar espejos -----------------------------------------------------//

void cerrar_espejos() {
  if (cerrarx2 == true && sin_llave == true && Estado_espejos == true) {
    pinMode(CLOSE_MIRR, OUTPUT);
    digitalWrite(CLOSE_MIRR, HIGH);
    Serial.println("Cierra espejos");
    cerrarx2 = false;
    abrir_cerrar = true;
    milis_abrir_cerrar = millis();
    preferences.putBool("Estado Espejos", false);
  }
}

// --------------------------------------------Reversa espejos ---------------------------------------------------//

void bajar_tildown() {

  pinMode(MIRROR_DOWN_REVERS, OUTPUT);
  digitalWrite(POWER, HIGH);
  digitalWrite(MIRROR_DOWN_REVERS, HIGH);
  Serial.println("Baja espejo");

  movimiento = true;
  milis_espejo_movimiento = millis();
}

void subir_tildown() {
  pinMode(MIRROR_UP_REVERS, OUTPUT);
  digitalWrite(POWER, HIGH);
  digitalWrite(MIRROR_UP_REVERS, HIGH);
  Serial.println("Sube espejo");
  subiendo = true;
  movimiento = true;
  milis_espejo_movimiento = millis();
}

void frenar_tildown() {

  digitalWrite(MIRROR_DOWN_REVERS, LOW);
  digitalWrite(MIRROR_UP_REVERS, LOW);
  delay(40);
  pinMode(MIRROR_DOWN_REVERS, INPUT);
  pinMode(MIRROR_UP_REVERS, INPUT);
  Serial.println("Freno movimineto");


  milis_espejo_espera = millis();
}


//------------------------------------------- Abrir techo ------------------------------------------------------//

void abrir_techo() {
  techo_abierto();
}

//-------------------------------------------- Cerrar techo -----------------------------------------------------//

void cerrar_techo() {
  techo_cerrado();
}

//-------------------------------------------- Evento ON contacto ---------------------------------------------------//


void ON_contacto() {
  Serial.println("Enciendo BLE");


  limpiar_sobre();  // Limpio por si quedo el sobre al apagar el auto
  Serial.println("Saludo Agujas");
  test_agujas();  // Test de agujas "needle sweep"
}


//-------------------------------------------- Evento OFF contacto ---------------------------------------------------//

void Apago_BLE() {
  Serial.println("Apago BLE");

}