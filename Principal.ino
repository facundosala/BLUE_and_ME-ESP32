//----------------------------------------------- Tarea 0 -----------------------------------------------------//
//*****************************************************************************************************************

#include "BRAVO.h"

//----------------------------------------------- programa principal -----------------------------------------------------//

void loop_tarea0(void *pvParameters) {

  for (;;) {

    //--------------------------------------- Coneccion con el Bluetooth Android ----------------------------------------------//

    if (connected) {
      BT_musica = true;  // fijate en el else tambien q lo pasa a false
      imp_no_conn = false;
      batt_level_2 = batt_level_1;
      if (hasText) {

        payload[strlen(payload) - 6] = '\0';  // Quitar la hora del string payload, formato de la hora es "@ hh:mm"

        //------------------------------------------ Mensaje Whatsapp -----------------------------------------------------//

        if (strstr(payload, "via WhatsApp @") && (!strstr(payload, "Comprobando si hay mensajes nuevos")) && (!strstr(payload, "Copia de seguridad en curso")) && (!strstr(payload, "Ubicación en tiempo real de WhatsApp")) && (!strstr(payload, "null")) && (escribiendo == false) && (c6.isOn == true) && (!strstr(payload, "Llamada en"))) {
          // escribiendo = true; // Saco de aca para probar sies por eso q cuelga 4/12/23
          Serial.println("Whatsapp");
          Display_sobre();

          if (menu_on == false && phone == false) {  // Si esta sin menu y sin Telefono funcionando mando continuo
            escribiendo = true;
            if (scroll_Spotify == true || scroll_Maps == true) {  // Freno scrol si es que estaba mostrando spotify
              scroll_Spotify = false;
              scroll_Maps = false;
              init_k = 0;  // Reinicio variables de scrol
              end_k = 14;
              mensaje_nuevo1 = false;
            }

            init_m = 0;
            end_m = 14;
            payload_Whatsapp_Aux = payload;
            payload_Whatsapp_Aux = payload_Whatsapp_Aux.substring(0, payload_Whatsapp_Aux.indexOf(":"));  // Texto hasta Â¨:Â¨
            if (payload_Whatsapp_Aux != "Tú") {
              if (payload_Whatsapp_Aux.length() > 14) {
                payload_Whatsapp_Aux = "   " + payload_Whatsapp_Aux + " ";  // Texto hasta Â¨:Â¨
                // length_Whatsapp = payload_Whatsapp_Aux.length();
                Scroll_Whatsapp = true;
              }
              send_Whatsapp();
            }
          }
          // send_Name_Whatsapp(payload_Whatsapp_Aux);
          // Serial.println(payload_Whatsapp_Aux);

          //------------------------------------------ Mensaje Spotify -----------------------------------------------------//

        }
        //------------------------------------------ Mensaje Spotify -----------------------------------------------------//

        else if (strstr(payload, "via Spotify @") && (escribiendo == false) && (menu_on == false) && (c7.isOn == true) && (phone == false)) {

          String payload_Spotify_Aux(payload);

          if (payload_Spotify_Aux.compareTo(payload_Spotify_Anterior) != 0) {  // Si es 0 los strings son iguales
            // Serial.println("Spotify");
            init_k = 0;
            end_k = 14;
            mensaje_nuevo1 = false;
            payload_Spotify = payload_Spotify_Aux.substring(payload_Spotify_Aux.indexOf(0x22) + 1, payload_Spotify_Aux.indexOf("@"));  // Texto entre primer comilla (0x22) y @
            payload_Spotify = payload_Spotify.substring(0, payload_Spotify.indexOf(0x22));                                             // Hasta segunda comilla
            String payload_Spotify_Song = payload_Spotify_Aux.substring(0, payload_Spotify_Aux.indexOf(":"));
            payload_Spotify = payload_Spotify + " - " + payload_Spotify_Song;
            if (payload_Spotify.length() > 14) {
              payload_Spotify = "   " + payload_Spotify + " ";
              // length_spotify = payload_Spotify.length();
              scroll_Spotify = true;
            }
            // Serial.println(payload_Spotify);
            send_Spotify(payload_Spotify);
          }
          payload_Spotify_Anterior = payload_Spotify_Aux.substring(0, payload_Spotify_Aux.length());  // Guardo el nuevo mensaje en el anterior
          // payload_Spotify="Spotify"; //+payload.c_str();
        }
        //------------------------------------------ Mensaje Maps -----------------------------------------------------//

        else if (strstr(payload, "via Maps @") && (escribiendo == false) && (menu_on == false) && (phone == false)) {
          // Serial.println(payload);
          // Serial.println("Gmap");

          String payload_Maps_Aux(payload);

          payload_Maps = payload_Maps_Aux.substring(payload_Maps_Aux.indexOf("con direción a") + 1, payload_Maps_Aux.indexOf("@"));
          payload_Maps = payload_Maps.substring(0, payload_Maps.indexOf(0x22));

          if (payload_Maps.compareTo(payload_Maps_Anterior) != 0) {
            if (strstr(payload, "Gira a la izquieda")) {
              Izquierda();
            } else if (strstr(payload, "Gira a la derecha")) {
              Derecha();
            } else if (strstr(payload, "Gira levemente a la izquieda") || strstr(payload, "girar levemente a la izquieda")) {
              Izquierda();
            } else if (strstr(payload, "Gira levemente a la derecha") || strstr(payload, "girar levemente a la derecha")) {
              Derecha();
            }
            Serial.println(payload_Maps);
            // if (payload_Spotify.length() > 14) {
            //   payload_Maps = "   " + payload_Maps + " ";
            //   scroll_Maps = true;
            // }
            // send_Maps(payload_Maps);
          }

          payload_Maps_Anterior = payload_Maps.substring(0, payload_Maps.length());  // Guardo el nuevo mensaje en el anterior
        }
        //------------------------------------------ Mensaje Telegram -----------------------------------------------------//

        else if (strstr(payload, "via Telegram @")) {
          // Serial.println(payload);
          // Serial.println("Telegrama");
        }
        //------------------------------------------ Mensaje Clima -----------------------------------------------------//

        else if (strstr(payload, "via Google @")) {
          // Serial.println(payload);
          // Serial.println("Clima");
        }
        //------------------------------------------ LLamada telefono -----------------------------------------------------//

        else if (strstr(payload, "via Teléfono @") && (t3.isOn == true) && (!strstr(payload, "Llamada perdida")) && (!strstr(payload, "Marcando"))) {

          String payload_telefono_Aux(payload);
          // String payload_telefono_name(payload);
          String payload_telefono_tipo(payload);

          if (payload_telefono_Aux.compareTo(payload_telefono_Anterior) != 0) {  // Si es 0 los strings son iguales

            Serial.println(payload);

            telefono_ACT = true;
            escribiendo = true;

            if (menu_on == false) {
              if (scroll_Spotify == true) {  // Freno scrol si es que estaba mostrando spotify
                scroll_Spotify = false;
                init_k = 0;  // Reinicio variables de scrol
                end_k = 14;
                mensaje_nuevo1 = false;
              } else if (Scroll_Whatsapp == true) {
                Scroll_Whatsapp = false;  // Reinicio variables de scrol whatsaap
                init_m = 0;
                end_m = 14;
              }
            }
            if (menu_on == true) {
              menu_on = false;  // Salgo del menu si es que estaba y reinicio toda las variables
              currentMenu = &programa_ppal;
            }

            payload_telefono_Aux = payload;

            payload_telefono_tipo = payload_telefono_Aux.substring(payload_telefono_Aux.indexOf(0x22) + 1, payload_telefono_Aux.indexOf(0x82));  // Texto entre primer comilla (0x22)
            payload_telefono_tipo = payload_telefono_tipo.substring(0, payload_telefono_tipo.indexOf(0x22));                                     // Hasta segunda comilla

            payload_telefono_name = payload_telefono_Aux.substring(0, payload_telefono_Aux.indexOf(":"));  // Texto hasta Â¨:Â¨


            if (payload_telefono_name.length() > 14) {
              payload_telefono_name = "   " + payload_telefono_name + "   ";  // Texto hasta Â¨:Â¨
              // length_llamada = payload_telefono_name.length();
              scroll_llamada = true;
            }

            if (payload_telefono_tipo == "Llamada en curso") {
              // imprimir "En\nllamada\ncon\n"

              llamada_en_curso = true;
              phone = true;

            } else if (payload_telefono_tipo == "Marcando") {
              // imprimir "Marcando\na\n\n "

              marcando = true;
              phone = true;

            } else if (payload_telefono_tipo == "Llamada entrante") {
              // imprimir "llamada\nentrande\nde\n"

              llamada_entrante = true;
              phone = true;
            }
            if (t2.isOn == false) {
              payload_telefono_name = "";
            }

            llamada_texto(payload_telefono_name);
            // Serial.println("Telefono");
          }
          payload_telefono_Anterior = payload_telefono_Aux;

        }

        //------------------------------------------ Mensaje extras -----------------------------------------------------//

        else {

          // Serial.print("PAYLOAD: ");
          // Serial.println(payload);
        }

        hasText = false;
      }

      //------------------------------------------ NO conectado -----------------------------------------------------//
    } else {
      if (BLE_TIMER == true) {
        millis_BLE = millis();
        BLE_TIMER = false;
        pServer->startAdvertising();  // Reinicia la publicidad para que lo encuentre despues de desconectarse al alejarte 19/10/24
        Serial.println("Reiniciando publicidad BLE...");
      }
      if (imp_no_conn == false) {
        BT_musica = false;  // Este despues cambiar al bluetooth de audio
        batt_level_2 = "SIN BT";
        Serial.println("No conectado al BT");
        imp_no_conn = true;
      }
    }

    //--------------------------------------------- millis Limpieza display -----------------------------------------------------//

    if ((mensaje_nuevo == true) && (millis() - prevInfo >= 3000)) {  // Limpia display de informacion
      limpiar_display();
      mensaje_nuevo = false;
      scroll_Spotify = false;
      scroll_Maps = false;
      // semaforo_can = false;
      // escribiendo = false;  // saco porque lo pongo dentro de la funcion limpiar_display
    }

    //------------------------------------------ millis limpiar sobre naranja -----------------------------------------------------//

    if ((mensaje_sobre == true) && (millis() - prevInfo_SMS >= 30000)) {  // Limpia sobre naranja
      limpiar_sobre();
      mensaje_sobre = false;
    }

    //------------------------------------------ Cambio de sobre grande a remitente -----------------------------------------------------//

    if ((mensaje_whatsapp == true) && (millis() - prevwhatsapp >= 4000)) {  // Limpia cambia de sobre grande a mensaje de remitente
      mensaje_whatsapp = false;
      send_Name_Whatsapp(payload_Whatsapp_Aux);
    }

    //------------------------------------------ Scrol de Whatsaap -----------------------------------------------------//

    if (Scroll_Whatsapp == true) {

      if ((mensaje_nuevo1 == true) && (millis() - prevInfo_Scroll >= 400)) {  // Manda otro char

        send_Name_Whatsapp(payload_Whatsapp_Aux);
        prevInfo_Scroll = millis();
      }
      if (end_m >= payload_Whatsapp_Aux.length() + 1) {
        Scroll_Whatsapp = false;
        init_m = 0;
        end_m = 14;
        prevInfo = millis();
        mensaje_nuevo = true;
        mensaje_nuevo1 = false;
      }
    }

    //------------------------------------------ Scrol de Spotify -----------------------------------------------------//

    if (scroll_Spotify == true) {

      if ((mensaje_nuevo1 == true) && (millis() - prevInfo_Scroll >= 400)) {  // Manda otro char

        send_Spotify(payload_Spotify);
        // prevInfo_Scroll = millis();
      }
      if (end_k >= payload_Spotify.length() + 1) {
        scroll_Spotify = false;
        init_k = 0;
        end_k = 14;
        prevInfo = millis();
        mensaje_nuevo = true;
        mensaje_nuevo1 = false;
      }
    }

    //------------------------------------------ Scrol de Maps -----------------------------------------------------//

    if (scroll_Maps == true) {

      if ((mensaje_nuevo1 == true) && (millis() - prevInfo_Scroll >= 400)) {  // Manda otro char

        send_Maps(payload_Maps);
        // prevInfo_Scroll = millis();
      }
      if (end_k >= payload_Maps.length() + 1) {
        scroll_Maps = false;
        init_k = 0;
        end_k = 14;
        prevInfo = millis();
        mensaje_nuevo = true;
        mensaje_nuevo1 = false;
      }
    }
    //------------------------------------------ Scroll de Telefono -----------------------------------------------------//

    if (scroll_llamada == true) {

      if ((mensaje_nuevo1 == true) && (millis() - prevInfo_Scroll >= 400)) {  // Manda otro char

        llamada_texto(payload_telefono_name);
        // prevInfo_Scroll = millis();
      }
      if (end_L >= payload_telefono_name.length() + 1) {
        // scroll_llamada = false;
        init_L = 0;
        end_L = 14;
        // mensaje_nuevo1 = false;
        // llamada_en_curso = false;
        // llamada_entrante = false;
        // marcando = false;
      }
    }

    //------------------------------------------ millis pulsador espejos 1 segundos -----------------------------------------------------//

    if ((abrir_cerrar == true) && (millis() - millis_abrir_cerrar >= 1000)) {  // tiempo de espera de pulsar
      abrir_cerrar = false;
      digitalWrite(OPEN_MIRR, LOW);
      digitalWrite(CLOSE_MIRR, LOW);
      vTaskDelay(pdMS_TO_TICKS(40));
      pinMode(CLOSE_MIRR, INPUT);
      pinMode(OPEN_MIRR, INPUT);
    }

    //------------------------------------------ millis pulsador techo 1 segundos -------------------------------------------------//

    if ((abrir_cerrar_techo == true) && (millis() - millis_abrir_cerrar_techo >= 1000)) {  // tiempo de espera de pulsar
      abrir_cerrar_techo = false;
      digitalWrite(CLOSE_TECH, LOW);
      digitalWrite(OPEN_TECH, LOW);
      vTaskDelay(pdMS_TO_TICKS(40));
      pinMode(CLOSE_TECH, INPUT_PULLDOWN);
      pinMode(OPEN_TECH, INPUT_PULLDOWN);
    }

    //---------------------------------------------- POWER 5 segundos ----------------------------------------------------//

    if ((POWER_VCC == true) && (millis() - millis_POWER_VCC >= 5000)) {  // tiempo de espera pulsador
      POWER_VCC = false;
      digitalWrite(POWER, LOW);
      vTaskDelay(pdMS_TO_TICKS(40));
      pinMode(POWER, INPUT_PULLDOWN);
      primera_vez_espejos = false;  // reseteo variable que hace entrar a la funcion de abrir y cerrar espejos
      Serial.println("Apago rele Power");
    }

    //------------------------------------------ 100km techo 60 segundos -------------------------------------------------//

    if ((abrir_cerrar_techo_km == true) && (millis() - millis_abrir_cerrar_techo_km >= 60000)) {  // tiempo de espera pulsador
      abrir_cerrar_techo_km = false;
      techo_km = true;
    }

    //++++++++++++++++++++++++++++++++++++++++++ sleep de ESP32 despues de 10seg sin CAN ++++++++++++++++++++++++++++++++++++++++++//

    if ((millis() - millis_sleep >= 10000) && (connected == false)) {
      millis_sleep = 0;
      enter_sleep();  // Llama a la funcion que lo duerme la ESP32
    }

    //++++++++++++++++++++++++++++++++++++++++++ Datos de envio de comandos telefono 3E7 ++++++++++++++++++++++++++++++++++++++++++//

    if (millis() - millis_3E7 > 450) {
      millis_3E7 = 0;
      Info_telefono();  // Llama a la funcion envio datos por 3E7
    }

    //++++++++++++++++++++++++++++++++++++++++++ ANTI REBOTE ++++++++++++++++++++++++++++++++++++++++++//

    if (anti_rebote == true && millis() - millis_rebote >= 700) {
      millis_rebote = 0;
      anti_rebote = false;
    }

    //++++++++++++++++++++++++++++++++++++++++++ reinicio BLE ++++++++++++++++++++++++++++++++++++++++++//

    if ((BLE_TIMER == false) && (millis() - millis_BLE >= 10000)) {
      millis_BLE = 0;
      BLE_TIMER = true;
    }

    //++++++++++++++++++++++++++++++++++++++++++ prueba de control por Ble ++++++++++++++++++++++++++++++++++++++++++//

    // if (Serial.available() > 0) {
    //   char comando = Serial.read();  // Lee el comando recibido

    //   if (comando == 'z') {  // Ejecuta una función según el comando recibido
    //     Serial2.print('r');
    //     Serial.println("Envio play");
    //   }
    // }
    //++++++++++++++++++++++++++++++++++++++++++ Lectura de CANBUS ++++++++++++++++++++++++++++++++++++++++++++++++++++//

    while (semaforo_can == true) { vTaskDelay(pdMS_TO_TICKS(1)); }
    semaforo_can = true;

    if (!digitalRead(CAN0_INT)) {  // Tendria q cambiarlo por el 19 para no tener conficto con el CAN de la ESP32 interno


      millis_sleep = millis();  // Reset contador millis de Sleep simpre que llega mensaje de CAN

      CAN0.readMsgBuf(&can0_rxId, &can0_len, can0_rxBuf);

      //++++++++++++++++++++++++++++++++++++++++++ Funcion play y pause dependiendo de musica_on +++++++++++++++++++++++++++++++++++++++++++++++++//

      reproductor();

      //++++++++++++++++++++++++++++++++++++++++++ Imprimo todos los mensajes de CAN ++++++++++++++++++++++++++++++++++++++++++++++++++++//

      // Serial.print("ID:");
      // Serial.println(can0_rxId);  // Imprime por UART el ID del mensaje recivido
      // Serial.print(",");
      // Serial.print(can0_len);  // Imprime por UART el len del mensaje recivido
      // Serial.print(" --> ");

      // for (int ii = 0; ii < can0_len; ii++) {
      //   Serial.print(can0_rxBuf[ii]);  // Imprime por UART todo los rxBuf de mensajes recividos
      //   Serial.print("  ");
      // }
      // Serial.println(";");

      // Serial.println(Estado_espejos);

      //++++++++++++++++++++++++++++++++++++++++++ Comienzo de casos segun ID recividos ++++++++++++++++++++++++++++++++++++++++++++++++++++//

      switch (can0_rxId) {

          //------------------------------------------------- 0x38A ----------------------------------------------------------------------//

        case 0x38A:  // Estado de AC - 0x38A

          if (can0_len == 2 && contacto == true) {

            info_AC_0 = can0_rxBuf[0];
            info_AC_1 = can0_rxBuf[1];
            Aire_AC();
          }
          break;

          //------------------------------------------------- control llave remoto ---------------------------------------------------------------------//

        case 0x1A0:  // control llave remoto

          if (can0_len == 8 && contacto == false) {

            /* 
                0  0  0  0  0  8  0  0       abrir
                0  0  0  0  0  4  0  0       abrir x 2
                0  0  0  0  0  128  0  0     cerrar
                0  0  0  0  0  64  0  0      cerrar x2
                0  0  0  0  0  2  0  0       mantener abrir
                0  0  0  0  0  32  0  0      mantener cerrar
                0  0  0  0  0  1  0  0       soltar abrir
                0  0  0  0  0  16  0  0      soltar cerrar   
            */

            VPSRFTxButtonCntrl = can0_rxBuf[5];

            if (VPSRFTxButtonCntrl == 2) {
              Serial.println("Mantener abrir");

            } else if (VPSRFTxButtonCntrl == 32) {
              Serial.println("Mantener cerrar");

            } else if (VPSRFTxButtonCntrl == 1) {
              Serial.println("Suelto abrir");
              abrirx2 = true;  // fuerzo el valor anterior de estado de techo
              abrir_techo();

            } else if (VPSRFTxButtonCntrl == 16) {
              Serial.println("Suelto cerrar");
              cerrarx2 = true;  // fuerzo el valor anterior de estado de techo
              cerrar_techo();
              // Estado_espejos = true; // fuerzo el valor anterior de estado de espejos
              // cerrar_espejos();

            } else if (VPSRFTxButtonCntrl == 4) {
              Serial.println("Dos veces abrir");
              contacto = true;
              Estado_espejos = false;  // fuerzo el valor anterior de estado de espejos
              primera_vez_espejos = false;
              
              abrir_espejos();
              contacto = false;

            } else if (VPSRFTxButtonCntrl == 64) {
              Serial.println("Dos veces cerrar");

            } else if (VPSRFTxButtonCntrl == 8) {
              Serial.println("Abrir");
              // cerrarx2 = true;

            } else if (VPSRFTxButtonCntrl == 128) {
              Serial.println("Cerrar");
              Serial.println("Toque cerrar");
              Estado_espejos = true;
              cerrar_espejos();
            }
          }
          break;

          //------------------------------------------------- 0x380 ---------------------------------------------------------------------//

        case 0x380:  // 896:  //Estado de puerta lado conductor, Freno de mano y estado de llave


          if (can0_len == 8) {

            STATUS_NCM_0 = can0_rxBuf[0];
            STATUS_NCM_1 = can0_rxBuf[1];
            STATUS_NCM_2 = can0_rxBuf[2];  // estado llave bit 4, 5, 6 y 7 (24 => Park, 72 => ON, 200 => Arranque)

            BatteryVoltageLevel = can0_rxBuf[3];
            BATT = ((BatteryVoltageLevel & 0x7F) * 0.16);
            BATT_1 = String(BATT) + " V";

            mute_reversa();

            // if (getBit(STATUS_NCM_2, 4) == 1) {  // Estado reposo, sin llave
            //   // Serial.println("Sin llave");
            //   sin_llave = true;
            // } else {
            //   sin_llave = false;
            // }

            if (getBit(STATUS_NCM_2, 6) == 1) {  // Contanto
              contacto = true;

              if (contacto_evento == 0) {
                Serial.println("Contacto");
                ON_contacto();
                contacto_evento = 1;
                no_contacto_evento = 0;
              }

              if (getBit(STATUS_NCM_2, 7) == 1) {
                arranque = true;
                if (arranque_evento == 0) {  // arranque
                  Estado_espejos = false;    // Fuerzo el estado anterior de los espejos
                  abrir_espejos();
                  Serial.println("Arranque");
                  arranque_evento = 1;
                }
              } else {
                arranque = false;
                arranque_evento = 0;
              }

            } else if (no_contacto_evento == 0) {
              Serial.println("Quito contacto");  // Saco contacto
              dato_mostrado = 0;
              dato_display = &fiat;
              se_movio = false;  // reset de variable que dice que ya se movio el auto
              contacto = false;
              contacto_evento = 0;
              no_contacto_evento = 1;
            }

            mute_open_door_driver();
            Freno_mano();
          }
          break;

          //------------------------------------------------- Velocidad ---------------------------------------------------------------------//

        case 0x2A0:  // Velocidad

          if (can0_len == 4 && contacto == true) {

            info_Velocidad1 = can0_rxBuf[0];
            info_Velocidad2 = can0_rxBuf[1];
            VehicleSpeed = ((info_Velocidad1 & 0x1F) * 256 + info_Velocidad2) * 0.0625;  // Odometro en km/h, resolucion 0.0625 km/h FUNCION OK
            VehicleSpeed_1 = String((int)VehicleSpeed) + " km/h";
            if (VehicleSpeed != 0) {
              se_movio = true;
            }
            if (c2.isOn == true && (VehicleSpeed >= 100)) {
              cerrar_techo();
            }
          }
          break;

          //------------------------------------------------- Conmando volante --------------------------------------------------------------//

        case 0x3A0:  // Comando Volante

          if (can0_len == 2 && contacto == true) {

            // for (int ii = 0; ii < can0_len; ii++) {
            //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
            //   Serial.print("  ");
            // }
            // Serial.println(";");

            can0rx = can0_rxBuf[0] + can0_rxBuf[1];
            if ((can0rx != 0) && (can0rx_anterior != can0rx) && (anti_rebote == false)) {
              // cambio_pul_volante = true;  // pone en true el valor para que no lleguen mas de un mensaje
              anti_rebote = true;
              // millis_rebote = millis();

              // btn_izquierda = (bitRead(can0_rxBuf[1], 3));
              // btn_derecha = (bitRead(can0_rxBuf[1], 4));
              AudioModeCntrl = (bitRead(can0_rxBuf[0], 2));  // Tecla SRC y OK
              AudioModeDownCntrl = (bitRead(can0_rxBuf[0], 3));
              AudioModeUpCntrl = (bitRead(can0_rxBuf[0], 4));
              MuteCntrl = (bitRead(can0_rxBuf[0], 5));  // Mute y ESCAPE
              VolumeDownSts = (bitRead(can0_rxBuf[0], 6));
              VolumeUpSts = (bitRead(can0_rxBuf[0], 7));
              VoiceRecognitionSts = (bitRead(can0_rxBuf[1], 6));  // Tecla Windows
              TelephoneCallSts = (bitRead(can0_rxBuf[1], 7));     // Tecla telefonito y MAIN (MENU)
              cont_ceros = 0;

              // cambio_pul_volante = true;  // pone en true el valor para que no lleguen mas de un mensaje

              if ((MuteCntrl == 1) && (menu_on == false) && (Tarea2 == NULL) && (phone == false)) {
                MuteCntrl = 0;
                Serial2.print('r');  // poner play a la musica aca
                Serial.println("Play o Pause tema");
              }

              if ((AudioModeDownCntrl == 1) && (menu_on == false) && (Tarea2 == NULL) && (phone == false)) {
                AudioModeDownCntrl = 0;
                Serial2.print('p');
                Serial.println("Anterior tema");
              }

              if ((AudioModeUpCntrl == 1) && (menu_on == false) && (Tarea2 == NULL) && (phone == false)) {
                AudioModeUpCntrl = 0;
                Serial2.print('n');
                Serial.println("Siguiente tema");
              }

              if ((TelephoneCallSts == 1) && (menu_on == false) && (Tarea2 != NULL) && (phone == false)) {

                vTaskResume(Tarea2);  // Llamo a la tarea 2 MENU
              }

              if ((AudioModeCntrl == 1) && (menu_on == false) && (Tarea2 != NULL) && (phone == false)) {
                AudioModeCntrl = 0;
                bym_on = true;
                fuente_primera_vez = false;
              }

              if ((VoiceRecognitionSts == 1) && (menu_on == false)) {
                VoiceRecognitionSts = 0;
                // Serial.print("pulsador windows");
                cambio_dato();
                can0rx_anterior = can0rx;
                break;
              }

            } else if ((can0_rxBuf[0] + can0_rxBuf[1]) == 0) {
              cont_ceros = cont_ceros + 1;
              if (cont_ceros == 2) {
                anti_rebote = false;
                cont_ceros = 0;
              }
            }
            can0rx_anterior = can0rx;
          }
          break;

          //------------------------------------------------- STATUS_B_ECM2--------------------------------------------------------------------//


        case 0x2A1:  //
          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
          //   Serial.print("  ");
          // }
          // Serial.println(";");

          if (can0_len == 8 && contacto == true) {

            BoostPressureIndication = can0_rxBuf[2];
            Boost = (BoostPressureIndication * 15);
            Boost_1 = String(Boost) + "mbar";


            // Serial.print(can0_rxBuf[3]);  // Imprime mensajes de rxBuf
            // CruiseControlSts = can0_rxBuf[3];
            // CC();
          }

          break;

          //------------------------------------------- Temp agua y RPM --------------------------------------------------------------//

        case 0x281:  //STATUS B-NCM

          if (can0_len == 8 && contacto == true) {

            info_rpm1 = can0_rxBuf[6];
            info_rpm = (info_rpm1 * 32);
            info_rpm_1 = String(info_rpm) + " RPM";

            info_agua1 = can0_rxBuf[3];
            info_agua = (info_agua1 - 40);
            info_agua_1 = String(info_agua) + " =C";
          }
          break;

          //------------------------------------------------- pausa del estereo ------------------------------------------------------------//

        case 0x3c5:  //RADIO PAUSE
          pauseNCV = (bitRead(can0_rxBuf[0], 5));
          if (pauseNCV == 1) {
            pause_estereo = true;
            // BT_musica = false;

          } else {
            pause_estereo = false;
            // BT_musica = true;
          }
          // Serial.println(pause_estereo);

          // Serial.print("ID: 0x3D8, ");
          // Serial.print(can0_len);  // Imprime largo del buf
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
          //   Serial.print("  ");
          // }
          // Serial.println(";");
          // Serial.println("");
          break;
          //------------------------------------------------- mensajes Sensor estacionamiento --------------------------------------------------------------------//

        case 0x3D8:  //  Sensores estacionamiento
          // Serial.print("ID: 0x3D8, ");
          // Serial.print(can0_len);  // Imprime largo del buf
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
          //   Serial.print("  ");
          // }
          // Serial.println(";");
          // Serial.println("");

          break;


        case 0x563:  //  Sensores estacionamiento
          // Serial.print("ID: 0x563, ");
          // Serial.print(can0_len);  // Imprime largo del buf
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
          //   Serial.print("  ");
          // }
          // Serial.println(";");
          // Serial.println("");


          break;

        case 0x503:  //  Control crucero    ¡¡¡¡NO LLEGA!!!!
          Serial.print("ID: 0x503, ");
          Serial.print(can0_len);  // Imprime largo del buf
          Serial.print(" --> ");

          for (int ii = 0; ii < can0_len; ii++) {
            Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
            Serial.print("  ");
          }
          Serial.println(";");

          break;

        case 0x400:  //  Control crucero  ¡¡¡¡NO LLEGA!!!!
          Serial.print("ID: 0x400, ");
          Serial.print(can0_len);  // Imprime largo del buf
          Serial.print(" --> ");

          for (int ii = 0; ii < can0_len; ii++) {
            Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
            Serial.print("  ");
          }
          Serial.println(";");

          break;

        case 0x427:  //
          // Serial.print("ID: 0x427, ");
          // Serial.print(can0_len);  // Imprime largo del buf
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
          //   Serial.print("  ");
          // }
          // Serial.println(";");

          break;

        case 0x3c7:  //
          // Serial.print("ID: 0x3c7, ");
          // Serial.print(can0_len);  // Imprime largo del buf
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
          //   Serial.print("  ");
          // }
          // Serial.println(";");

          break;

        case 0x4e7:  //
          // Serial.print("ID: 0x4e7, ");
          // Serial.print(can0_len);  // Imprime largo del buf
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
          //   Serial.print("  ");
          // }
          // Serial.println(";");

          break;

        case 0x525:  //
          // Serial.print("ID: 0x525, ");
          // Serial.print(can0_len);  // Imprime largo del buf
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
          //   Serial.print("  ");
          // }
          // Serial.println(";");

          break;

        case 0x545:  //  fuente de audio     FUNCIONA BIEN"!!

          if (can0_len == 6 && contacto == true) {
            if (can0_rxBuf[0] == 64 && fuente_primera_vez == true) {
              fuente_primera_vez = false;
              radio_on = true;
              bym_on = false;
              // Serial.println("Radio");
              Serial2.print('s');  // poner stop a la musica aca

            } else if (can0_rxBuf[0] == 160 && BT_musica == true && fuente_primera_vez == false) {
              fuente_primera_vez = true;
              bym_on = true;
              radio_on = false;
              Serial2.print('r');  // poner play a la musica aca
              // Serial.println("B&M");
            }
            // Serial.println(radio_on);

            // Serial.print("ID: 0x545, ");
            // Serial.print(can0_len);  // Imprime largo del buf
            // Serial.print(" --> ");

            // for (int ii = 0; ii < can0_len; ii++) {
            //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
            //   Serial.print("  ");
            // }
            // Serial.println(";");
          }
          break;

        case 0x565:  //
          // Serial.print("ID: 0x565, ");
          // Serial.print(can0_len);  // Imprime largo del buf
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
          //   Serial.print("  ");
          // }
          // Serial.println(";");

          break;

        case 0x5c7:  //
          // Serial.print("ID: 0x5c7, ");
          // Serial.print(can0_len);  // Imprime largo del buf
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
          //   Serial.print("  ");
          // }
          // Serial.println(";");

          break;

        case 0x707:  //
          // Serial.print("ID: 0x707, ");
          // Serial.print(can0_len);  // Imprime largo del buf
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
          //   Serial.print("  ");
          // }
          // Serial.println(";");

          break;

        case 0x747:  //
          // Serial.print("ID: 0x747, ");
          // Serial.print(can0_len);  // Imprime largo del buf
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
          //   Serial.print("  ");
          // }
          // Serial.println(";");

          break;

        case 0x7b0:  //   //DIAGNOSE_REQUEST Mensajes del OBD2 ESCANNER
          // Serial.print("ID: 0x7b0, ");
          // Serial.print(can0_len);  // Imprime largo del buf
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
          //   Serial.print("  ");
          // }
          // Serial.println(";");

          break;

          // case 0x7c7:  //
          //   Serial.print("ID: 0x7c7, ");
          //   Serial.print(can0_len);  // Imprime largo del buf
          //   Serial.print(" --> ");

          //   for (int ii = 0; ii < can0_len; ii++) {
          //     Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
          //     Serial.print("  ");
          //   }
          //   Serial.println(";");

          break;
        //------------------------------------------------- 0x3E7 -------------------------------------------------------------------//
        case 0x7C3:  //DIAGNOSE_RESPONSE_IPC(DIAGNOSE_RESPONSE_NQS) 1987

          // Serial.print("ID:");
          // Serial.print(can0_rxId);  // Imprime por UART el ID del mensaje recivido
          // Serial.print(" ,");
          // Serial.print(can0_len);  // Imprime por UART el len del mensaje recivido
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime por UART todo los rxBuf de mensajes recividos
          //   Serial.print("  ");
          // }
          // Serial.println(";");
          break;

        case 0x3E7:  // Mensages de B&M para la info del telefono

          // Serial.println("mensaje de b&m");
          // Serial.print(can0_len);  // Imprime largo del buf
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf del 3E7 recividos
          //   Serial.print("  ");
          // }
          // Serial.println(";");

          // if (can0_len == 8) {
          //   // radio_info();  // prueba

          //   cont3E7 = cont3E7 + 1;  // Defino un contador de mensajes entrantes correspondientes al ID 3E7
          //   if (connected == 1) {   // Si esta conectado al celular
          //     if (cont3E7 == 10) {  // Cuento mensajes de B&M y muestro el estado de la bateria dos veces
          //       Info_telefono();    // Envio porcentaje de bateria
          //     }
          //     if (cont3E7 == 20) {
          //       cont3E7 = 0;  // Resereo el contador
          //     }
          //   } else {                                 // Sin no esta conectado al celular
          //     if (cont3E7 == 17 && cont3E7 == 20) {  // Cuento mensajes de B&M y muestro el estado de la bateria dos veces
          //       batt_level_1 = "NO ALERT";           // Muestro en display NO ALERT
          //       Info_telefono();
          //     }
          //     if (cont3E7 == 20) {
          //       cont3E7 = 0;  // Resereo el contador
          //     }
          //   }
          // }
          break;

        case 0x5e7:
          // Serial.println("ID: 0x5e7, ");
          // Serial.print(can0_len);  // Imprime largo del buf
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
          //   Serial.print("  ");
          // }
          // Serial.println(";");

          break;

        case 0x607:
          // Serial.println("ID: 0x607, ");
          // Serial.print(can0_len);  // Imprime largo del buf
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
          //   Serial.print("  ");
          // }
          // Serial.println(";");

          break;

        case 0x507:  //
          // Serial.print("ID: 0x507, ");
          // Serial.print(can0_len);  // Imprime largo del buf
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
          //   Serial.print("  ");
          // }
          // Serial.println(";");

          break;

        case 0x6c7:  //
          // Serial.println("ID: 0x6c7, ");
          // Serial.print(can0_len);  // Imprime largo del buf
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
          //   Serial.print("  ");
          // }
          // Serial.println(";");

          break;

        case 0x6e7:  //
          // Serial.println("ID: 0x6e7, ");
          // Serial.print(can0_len);  // Imprime largo del buf
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
          //   Serial.print("  ");
          // }
          // Serial.println(";");

          break;

        case 0x286:  //STATUS B-NFR
          break;

        case 0x282:  //STATUS_B_EPS
          break;

        case 0x180:  //EXTERNAL_LIGHTS
          break;

        case 0x360:  //STATUS_C_CAN

          // Serial.print("ID: 0x360, ");
          // Serial.print(can0_len);  // Imprime largo del buf
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime mensajes de rxBuf
          //   Serial.print("  ");
          // }
          // Serial.println(";");

          break;

        case 0x39a:  //STATUS_SDM_V2(STATUS_NAB_V2)
          break;

        case 0x603:  //TRIP_A&B
          break;

        case 0x663:  //TRIP_B
          break;

        case 0x3c0:  //ENVIRONMENTAL_CONDITIONS
          // Serial.print("ID:");
          // Serial.print(can0_rxId);  // Imprime por UART el ID del mensaje recivido
          // Serial.print(" ,");
          // Serial.print(can0_len);  // Imprime por UART el len del mensaje recivido
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime por UART todo los rxBuf de mensajes recividos
          //   Serial.print("  ");
          // }
          // Serial.println(";");

          break;

        case 0x3e0:  //ENVIRONMENTAL_CONDITIONS
          break;

        case 0x683:  //Time_IPC
          break;

        case 0x643:  //TRIP
          break;

        case 0x6e3:  //Mensajes de configuracion de paramentros del vehiculo desde menu
          break;

        case 0x700:  //INFO NODOS
          break;

        case 0x3c3:  //
          break;

        default:  // Otros mensajes no filtrados

          // Serial.print("ID:");
          // Serial.print(can0_rxId);  // Imprime por UART el ID del mensaje recivido
          // Serial.print(" ,");
          // Serial.print(can0_len);  // Imprime por UART el len del mensaje recivido
          // Serial.print(" --> ");

          // for (int ii = 0; ii < can0_len; ii++) {
          //   Serial.print(can0_rxBuf[ii]);  // Imprime por UART todo los rxBuf de mensajes recividos
          //   Serial.print("  ");
          // }
          // Serial.println(";");

          break;
      }
    }
    semaforo_can = false;
  }
}