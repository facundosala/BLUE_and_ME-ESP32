#include "BRAVO.h"

// +++++++++++++++++++++++++++++++++++++++ Funcion de codificacion de String +++++++++++++++++++++++++++++++++++++++ //

void ascii2sixbits(String p) {
  // La funciÃ³n toma una cadena de strings ascii y devuelve una cadena comprimida en hasta 12 bytes (de 8 bits) formado por 16 caracteres en un  formato de 6bits cada uno. "El ascii se comprime".
  // Permite reducir un string de 16 a 12 caracteres.
  // Ver hoja 1 y 2 del documento de google sheets "armar telegrama".

  int mensaje[16];
  //StringBuilder sb = new StringBuilder();
  if (p.length() > 16)
    p = p.substring(0, 15);
  int k = 0;
  if (p.length() <= 16) {
    for (int j = 0; j < p.length(); j++) {
      char c = p[j];
      // Serial.println(c);
      int i = int(c);

      //Serial.println(i);
      if (i != 195) {

        if (c >= 48 && c <= 57)  //entre "0" y "9"
          i -= 47;
        else if (c >= 65 && c <= 90)  //entre "A" y "Z"
          i -= 53;
        else if (c >= 97 && c <= 122)  //entre "A" y "Z"
          i -= 85;
        else if (c == 32)  //space
          i = 0;
        else if ((c == 46) || (c == 44))  //"." y ","
          i = 11;
        else if ((c == 145) || (c == 177)) {  //"Ã±"
          //Serial.println("llego una Enie");
          i = 38;
        } else if (c == 63)  //"?"
          i = 53;
        else if (c == 167)  //"Âº"
          i = 54;
        else if (c == 33)  //"!"
          i = 55;
        else if (c == 43)  //"+"
          i = 56;
        else if (c == 45)  //"-"
          i = 57;
        else if (c == 58)  //":"
          i = 58;
        else if (c == 47)  //"/"
          i = 59;
        else if (c == 35)  //"#"
          i = 60;
        else if (c == 42)  //"*"
          i = 61;
        else if (c == 10)  //"\n"
          i = 63;
        else if (c == 61)  // "°"
          i = 54;
        else if (c == 95)  // "_"
          i = 51;
        else if (c == 21)  // "§"
          i = 44;

        else if ((c == 129) || (c == 161)) {  //Ã¡ Ã
          //Serial.println("llego una ;Ã¡");
          i = 12;
        } else if ((c == 137) || (c == 169)) {  //Ã© Ã‰
          //Serial.println("llego una Ã©");
          i = 16;
        } else if ((c == 141) || (c == 173)) {  //Ã­ Ã
          //Serial.println("llego una ;Ã­");
          i = 20;
        } else if ((c == 147) || (c == 179)) {  //Ã³ Ã“
          //Serial.println("llego una Ã³");
          i = 26;
        } else if ((c == 154) || (c == 186)) {  //Ãº Ãš
          //Serial.println("llego una Ãº");
          i = 32;
        } else i = 61;  // Agrega asterisco frente a un caracter desconocidol {}
        // do something with c
        mensaje[k] = i;
        k = k + 1;
      }
      //SerialMonitor.println(i);
      //sixBit += String(i, BIN);
    }
    for (int j = k; j < 16; j++) {
      mensaje[j] = 0;  // Agrega espacios en blanco al final hasta completar el string de 16 caracteres
    }

    sixBit[0] = (mensaje[0] << 2) + ((mensaje[1] & 0x30) >> 4);
    sixBit[1] = ((mensaje[1] & 0x0F) << 4) + ((mensaje[2] & 0x3c) >> 2);
    sixBit[2] = ((mensaje[2] & 0x03) << 6) + ((mensaje[3] & 0x03F));  //
    sixBit[3] = (mensaje[4] << 2) + ((mensaje[5] & 0x30) >> 4);
    sixBit[4] = ((mensaje[5] & 0x0F) << 4) + ((mensaje[6] & 0x3c) >> 2);
    sixBit[5] = ((mensaje[6] & 0x03) << 6) + ((mensaje[7] & 0x03F));  //
    sixBit[6] = (mensaje[8] << 2) + ((mensaje[9] & 0x30) >> 4);
    sixBit[7] = ((mensaje[9] & 0x0F) << 4) + ((mensaje[10] & 0x3c) >> 2);
    sixBit[8] = ((mensaje[10] & 0x03) << 6) + ((mensaje[11] & 0x03F));  //
    sixBit[9] = (mensaje[12] << 2) + ((mensaje[13] & 0x30) >> 4);
    sixBit[10] = ((mensaje[13] & 0x0F) << 4) + ((mensaje[14] & 0x3c) >> 2);
    sixBit[11] = ((mensaje[14] & 0x03) << 6) + ((mensaje[15] & 0x03F));  //

    // for (int j = 0; j < 12; j++ ) {
    //   Serial.println(j);
    //   Serial.print(": ");
    //   Serial.println(sixBit[j], BIN);
    // }
  }
  // Entran 16 caracteres de 6 bits en un registro de 12 bytes
}