#include "BRAVO.h"


//------------------------------- Devuelve el valor del bit en la posición especificada ----------------------------------------//

bool getBit(byte b, int pos) {
  return bitRead(b, pos);  // b = byte y pos = posicion de interes
}

//--------------------------------------- Mute al abrir la puerta conductor ----------------------------------------------//

void mute_open_door_driver() {
  byte can_msg_mute[2]{ 0x20, 0x00 };  // Mensaje comando Mute

  DriverDoorSts = bitRead(STATUS_NCM_1, 2);

  if ((DriverDoorSts == 0) && (primera_vez_2 == 0)) {
    primera_vez_2 = 1;
    estado_puerta = 0;
  } else {
    if ((DriverDoorSts == 1) && (estado_puerta == 0) && (c4.isOn == true) && (se_movio == true)) {
      estado_puerta = 1;

      CAN0.sendMsgBuf(0x3A0, 0, 2, can_msg_mute);  // Mandar el comando mute
      vTaskDelay(pdMS_TO_TICKS(20));


      // Mute_press();
    }
    if ((DriverDoorSts != 1) && (estado_puerta == 1) && (c4.isOn == true) && (se_movio == true)) {
      estado_puerta = 0;

      CAN0.sendMsgBuf(0x3A0, 0, 2, can_msg_mute);  // Mandar el comando mute
      vTaskDelay(pdMS_TO_TICKS(20));
    }
  }
}

//---------------------------------------- Estado Aire Acondicionado -------------------------------------------//

void Aire_AC() {

  if (escribiendo == false && menu_on == false) {
    if (primera_vez_1 == 0) {
      CompressorAcReqSts = bitRead(info_AC_0, 2);
      primera_vez_1 = 1;
    } else {
      if (CompressorAcReqSts != bitRead(info_AC_0, 2) && (c5.isOn == true)) {
        CompressorAcReqSts = bitRead(info_AC_0, 2);
        if ((CompressorAcReqSts == 1)) {
          scroll_Spotify = false;  // freno el scrol de Spotify si es que estaba escribiendo
          scroll_Maps = false;
          init_m = 0;
          end_m = 14;
          aire_AC_encendido();
        } else {
          scroll_Spotify = false;  // freno el scrol de Spotify si es que estaba escribiendo
          scroll_Maps = false;
          init_m = 0;
          end_m = 14;
          aire_AC_apagado();
        }
      }
    }
  }
}

//---------------------------------------- Estado Freno de mano puesto -------------------------------------------//

void Freno_mano() {

  if (escribiendo == false && menu_on == false) {
    if (primera_vez_4 == 0) {
      HandBrakeSts = bitRead(STATUS_NCM_0, 5);
      primera_vez_4 = 1;
      // Serial.println("freno de mano");
    } else {
      if (HandBrakeSts != bitRead(STATUS_NCM_0, 5)) {
        HandBrakeSts = bitRead(STATUS_NCM_0, 5);
        if ((HandBrakeSts == 1) && (c5.isOn == true)) {
          scroll_Spotify = false;  // freno el scrol de Spotify si es que estaba escribiendo cuando se subio el freno de mano
          scroll_Maps = false;
          init_m = 0;
          end_m = 14;
          freno_de_mano();
        }
      }
    }
  }
}

//---------------------------------------- Estado Control Crucero -------------------------------------------//

void CC() {
  if (escribiendo == false && menu_on == false) {
    if (primera_vez_5 == 0) {
      CC_ACTIVO = bitRead(CruiseControlSts, 2);
      primera_vez_5 = 1;
    } else {
      if (CC_ACTIVO != bitRead(CruiseControlSts, 2)) {
        CC_ACTIVO = bitRead(CruiseControlSts, 2);
        if (CC_ACTIVO == 1) {
          scroll_Spotify = false;  // freno el scrol de Spotify si es que estaba escribiendo
          scroll_Maps = false;
          init_m = 0;
          end_m = 14;
          Contro_CC();
        }
      }
    }
  }
}
//--------------------------------------- Abrir espejos ----------------------------------------------------------//

void abrir_espejos() {
  if ((contacto == true) && (Estado_espejos == false) && (primera_vez_espejos == false) && (c3.isOn == true)) {
    pinMode(POWER, OUTPUT);
    digitalWrite(POWER, HIGH);
    vTaskDelay(pdMS_TO_TICKS(40));

    pinMode(OPEN_MIRR, OUTPUT);
    digitalWrite(OPEN_MIRR, HIGH);
    Serial.println("Abre Espejos");
    primera_vez_espejos = true;  // evita que vuelva a entrar

    POWER_VCC = true;
    millis_POWER_VCC = millis();
    abrir_cerrar = true;
    millis_abrir_cerrar = millis();
    Estado_espejos = true;
    // preferences.putBool("espejos_estado", true);  // GUardo un true en la variable espejos_estados
  }
}

//--------------------------------------------Cerrar espejos -----------------------------------------------------//

void cerrar_espejos() {
  if ((contacto == false) && (Estado_espejos == true) && (primera_vez_espejos == false) && (c3.isOn == true)) {
    pinMode(POWER, OUTPUT);
    digitalWrite(POWER, HIGH);
    vTaskDelay(pdMS_TO_TICKS(40));
    pinMode(CLOSE_MIRR, OUTPUT);
    digitalWrite(CLOSE_MIRR, HIGH);
    Serial.println("Cierra espejos");
    primera_vez_espejos = true;  // evita que vuelva a entrar
  
    POWER_VCC = true;
    millis_POWER_VCC = millis();
    abrir_cerrar = true;
    millis_abrir_cerrar = millis();
    Estado_espejos = false;
    // preferences.putBool("espejos_estado", false);  // Guardo un false en la variable espejos_estado
  }
}

//------------------------------------------- Abrir techo ------------------------------------------------------//

void abrir_techo() {
  if ((contacto == false) && (abrirx2 == true) && (c1.isOn == true)) {
    pinMode(POWER, OUTPUT);
    pinMode(OPEN_TECH, OUTPUT);
    vTaskDelay(pdMS_TO_TICKS(40));
    digitalWrite(POWER, HIGH);
    digitalWrite(OPEN_TECH, HIGH);
    Serial.println("Abre techo");
    abrirx2 = false;
    POWER_VCC = true;
    millis_POWER_VCC = millis();
    abrir_cerrar_techo = true;
    millis_abrir_cerrar_techo = millis();
  }
}

//-------------------------------------------- Cerrar techo -----------------------------------------------------//

void cerrar_techo() {
  if ((contacto == false) && (cerrarx2 == true) && (c1.isOn == true)) {
    pinMode(POWER, OUTPUT);
    pinMode(CLOSE_TECH, OUTPUT);
    vTaskDelay(pdMS_TO_TICKS(40));
    digitalWrite(POWER, HIGH);
    digitalWrite(CLOSE_TECH, HIGH);
    Serial.println("Cierra techo");
    cerrarx2 = false;
    POWER_VCC = true;
    millis_POWER_VCC = millis();
    abrir_cerrar_techo = true;
    millis_abrir_cerrar_techo = millis();
  }

  else if ((VehicleSpeed >= 100) && (c2.isOn == true)) {
    if (techo_km == true) {
      techo_km = false;
      pinMode(CLOSE_TECH, OUTPUT);
      vTaskDelay(pdMS_TO_TICKS(40));
      digitalWrite(CLOSE_TECH, HIGH);
      // Serial.println("Cierra techo por velocidad");
      abrir_cerrar_techo_km = true;
      millis_abrir_cerrar_techo_km = millis();
    }
  }
}

//-------------------------------------------- Mute reversa ---------------------------------------------------//

void mute_reversa() {

  // byte can_msg_mute[2]{ 0x20, 0x00 };  // Mensaje comando Mute

  if (getBit(STATUS_NCM_2, 2) == 1) {  // Reversa

    if (reversa_evento == 0) {
      reversa_evento = 1;

      // semaforo_can = true; // Saco los semaforos el 3/11/2023 para ver si es el problema con el S&S
      // CAN0.sendMsgBuf(0x3A0, 0, 2, can_msg_mute);  // Mandar el comando mute
      // vTaskDelay(pdMS_TO_TICKS(20));
      Serial2.print('r');  // poner play a la musica aca
      Serial.println("Envio stop de reversa");
      // semaforo_can = false;
    }
  } else {
    if (reversa_evento == 1) {
      reversa_evento = 0;

      // semaforo_can = true;
      // byte can_msg_mute[2]{ 0x20, 0x00 };          // Mensaje comando Mute
      // CAN0.sendMsgBuf(0x3A0, 0, 2, can_msg_mute);  // Mandar el comando mute
      // vTaskDelay(pdMS_TO_TICKS(20));
      Serial2.print('r');  // poner play a la musica aca
      Serial.println("Envio play de reversa");


      // semaforo_can = false;
    }
  }
}

//-------------------------------------------- Evento ON contacto ---------------------------------------------------//

void ON_contacto() {
  // Serial.println("Enciendo BLE");

  // flags_test_agujas = true;  // Pongo la bandera en true

  if (Tarea1 != NULL) {
    vTaskResume(Tarea1);  // Llamo a la tarea 1 Agujas
  }
  // flags_test_agujas = false;  // pongo la bandera en false

  contador = 0;  // reseteo el contador de 10 veses de envio datos de b&m cuando se saca el contacto

  byte INFO_BM[6]{ 0x04, 0x19, 0x80, 0x14, 0x37, 0x40 };
  CAN0.sendMsgBuf(0x747, 0, 6, INFO_BM);  // Envio mensaje que emula el B&M conectado normalmente


  limpiar_sobre();  // Limpio por si quedo el sobre al apagar el auto
}

//-------------------------------------------- Cambio datos que muestro arriba ---------------------------------------------------//

void cambio_dato() {

  if (dato_mostrado == 0) {
    dato_mostrado = 1;
    if (n1.isOn == true) {
      dato_display = &bravo;
    } else if (n2.isOn == true) {
      dato_display = &punto;
    } else if (n3.isOn == true) {
      dato_display = &idea;
    } else if (n4.isOn == true) {
      dato_display = &linea;
    }
  } else if (dato_mostrado == 1) {
    dato_mostrado = 2;
    if (d1.isOn == true) {
      dato_display = &batt_level_2;
    } else {
      dato_mostrado = 3;
      dato_display = &VehicleSpeed_1;
    }
  } else if (dato_mostrado == 2) {
    dato_mostrado = 3;
    if (d2.isOn == true) {
      dato_display = &VehicleSpeed_1;
    } else {
      dato_mostrado = 4;
      dato_display = &info_rpm_1;
    }
  } else if (dato_mostrado == 3) {
    dato_mostrado = 4;
    if (d3.isOn == true) {
      dato_display = &info_rpm_1;
    } else {
      dato_mostrado = 5;
      dato_display = &info_agua_1;
    }
  } else if (dato_mostrado == 4) {
    dato_mostrado = 5;
    if (d4.isOn == true) {
      dato_display = &info_agua_1;
    } else {
      dato_mostrado = 6;
      dato_display = &BATT_1;
    }
  } else if (dato_mostrado == 5) {
    dato_mostrado = 6;
    if (d5.isOn == true) {
      dato_display = &BATT_1;
    } else {
      dato_mostrado = 0;
      dato_display = &Boost_1;
    }
  } else if (dato_mostrado == 6) {
    dato_mostrado = 0;
    if (d6.isOn == true) {
      dato_display = &Boost_1;
    } else {
      dato_mostrado = 1;
      if (n1.isOn == true) {
        dato_display = &bravo;
      } else if (n2.isOn == true) {
        dato_display = &punto;
      } else if (n3.isOn == true) {
        dato_display = &idea;
      } else if (n4.isOn == true) {
        dato_display = &linea;
      }
    }
  }
}

//++++++++++++++++++++++++++++++++++++++++++ opcion en surce de musica cuando hay BT ++++++++++++++++++++++++++++++++++++++++++++++++++++//

void reproductor() {

  if (BT_musica == true) {
    if (primera_vez_6 == 0) {
      primera_vez_6 = 1;
      // Serial2.print('r');
      bitWrite(INFO_tel[7], 2, 1);  // Permite tener el windows media
    }
  } else {
    if (primera_vez_6 == 1) {
      primera_vez_6 = 0;
      // Serial2.print('r');
      bitWrite(INFO_tel[7], 2, 0);
    }
  }
}

//++++++++++++++++++++++++++++++++++++++++++ Play y stop ++++++++++++++++++++++++++++++++++++++++++++++++++++//


// void controlarReproduccionMusica(bool reproducir) {
//     // Implementa la lógica para controlar la reproducción de música aquí
//     if (reproducir) {
//         // Lógica para reproducir la música
//         Serial.println("Reproduciendo música");
//         // Añade aquí la lógica para reproducir música según tu implementación específica
//     } else {
//         // Lógica para pausar la música
//         Serial.println("Música en pausa");
//         // Añade aquí la lógica para pausar la música según tu implementación específica
//     }
// }
