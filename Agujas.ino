//----------------------------------------------- Tarea 1 -----------------------------------------------------//
// *****************************************************************************************************************

#include "BRAVO.h"

//----------------------------------------------- programa principal -----------------------------------------------------//


void loop_tarea1(void* pvParameters) {
  int delay_time = 50;

  for (;;) {

    // Serial.println("Saludo Agujas");

    vTaskDelay(pdMS_TO_TICKS(delay_time));

    //--------------------------------------- test de agujas "needle sweep" ----------------------------------------------//

    //8 --> 133  4  48  114  7  255  0  0  ;
    byte Test_Tablero[8];
    Test_Tablero[0] = 133;
    Test_Tablero[1] = 4;
    Test_Tablero[2] = 48;
    Test_Tablero[3] = 124;
    Test_Tablero[4] = 7;
    Test_Tablero[5] = 255;
    Test_Tablero[6] = 0;
    Test_Tablero[7] = 0;

    byte Encender_Test[8];
    Encender_Test[0] = 133;
    Encender_Test[1] = 2;
    Encender_Test[2] = 16;
    Encender_Test[3] = 129;
    Encender_Test[4] = 0;
    Encender_Test[5] = 0;
    Encender_Test[6] = 0;
    Encender_Test[7] = 0;


    CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo mess 1

    vTaskDelay(pdMS_TO_TICKS(delay_time));

    //8 --> 133  2  26  151  0  0  0  0  ;
    Encender_Test[0] = 133;
    Encender_Test[1] = 2;
    Encender_Test[2] = 26;
    Encender_Test[3] = 151;
    CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo mess 2


    vTaskDelay(pdMS_TO_TICKS(delay_time));

    //8 --> 133  48  255  0  0  0  0  0  ;
    Encender_Test[0] = 133;
    Encender_Test[1] = 48;
    Encender_Test[2] = 255;
    Encender_Test[3] = 0;
    CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo mess 3


    vTaskDelay(pdMS_TO_TICKS(delay_time));

    //8 --> 133  2  26  145  0  0  0  0  ;
    Encender_Test[0] = 133;
    Encender_Test[1] = 2;
    Encender_Test[2] = 26;
    Encender_Test[3] = 145;
    CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo mess 4


    vTaskDelay(pdMS_TO_TICKS(delay_time));

    //8 --> 133  48  255  0  0  0  0  0  ;
    Encender_Test[0] = 133;
    Encender_Test[1] = 48;
    Encender_Test[2] = 255;
    Encender_Test[3] = 0;
    CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo mess 5


    vTaskDelay(pdMS_TO_TICKS(delay_time));

    //8 --> 133  2  26  146  0  0  0  0  ;
    Encender_Test[0] = 133;
    Encender_Test[1] = 2;
    Encender_Test[2] = 26;
    Encender_Test[3] = 146;

    CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo mess 6


    vTaskDelay(pdMS_TO_TICKS(delay_time));

    //8 --> 133  48  255  0  0  0  0  0  ;
    Encender_Test[0] = 133;
    Encender_Test[1] = 48;
    Encender_Test[2] = 255;
    Encender_Test[3] = 0;

    CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo mess 7


    vTaskDelay(pdMS_TO_TICKS(delay_time));

    //8 --> 133  2  26  147  0  0  0  0  ;
    Encender_Test[0] = 133;
    Encender_Test[1] = 2;
    Encender_Test[2] = 26;
    Encender_Test[3] = 147;

    CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo mess 8


    vTaskDelay(pdMS_TO_TICKS(delay_time));

    //8 --> 133  2  26  148  0  0  0  0  ;
    Encender_Test[0] = 133;
    Encender_Test[1] = 2;
    Encender_Test[2] = 26;
    Encender_Test[3] = 148;

    CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo mess 9


    vTaskDelay(pdMS_TO_TICKS(delay_time));

    //8 --> 133  48  255  0  0  0  0  0  ;
    Encender_Test[0] = 133;
    Encender_Test[1] = 48;
    Encender_Test[2] = 255;
    Encender_Test[3] = 0;

    CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo mess 10


    vTaskDelay(pdMS_TO_TICKS(delay_time));

    //8 --> 133  2  26  149  0  0  0  0  ;
    Encender_Test[0] = 133;
    Encender_Test[1] = 2;
    Encender_Test[2] = 26;
    Encender_Test[3] = 149;

    CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo mess 11


    vTaskDelay(pdMS_TO_TICKS(delay_time));

    //8 --> 133  2  26  150  0  0  0  0  ;
    Encender_Test[0] = 133;
    Encender_Test[1] = 2;
    Encender_Test[2] = 26;
    Encender_Test[3] = 150;

    CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo mess 12


    vTaskDelay(pdMS_TO_TICKS(delay_time));

    //8 --> 133  48  255  0  0  0  0  0  ;
    Encender_Test[0] = 133;
    Encender_Test[1] = 48;
    Encender_Test[2] = 255;
    Encender_Test[3] = 0;

    CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo mess 13


    vTaskDelay(pdMS_TO_TICKS(delay_time));

    //8 --> 133  2  26  153  0  0  0  0  ;
    Encender_Test[0] = 133;
    Encender_Test[1] = 2;
    Encender_Test[2] = 26;
    Encender_Test[3] = 153;

    CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo mess 14


    vTaskDelay(pdMS_TO_TICKS(delay_time));

    //8 --> 133  1  62  0  0  0  0  0  ;
    Encender_Test[0] = 133;
    Encender_Test[1] = 1;
    Encender_Test[2] = 62;
    Encender_Test[3] = 0;

    CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo mess 15


    vTaskDelay(pdMS_TO_TICKS(delay_time));

    //-------------------------- Enciendo luz tablero ------------------------//

    CAN0.sendMsgBuf(1968, 0, 8, Test_Tablero);  //enciendo luz tablero
    vTaskDelay(pdMS_TO_TICKS(1000));

    CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo tablero


    vTaskDelay(pdMS_TO_TICKS(delay_time));
    // delay(150);
    //byte Test_Tablero_RPM_1[8]{ 133, 4, 48, 114, 7, 255, 0x00, 0x00 };

    //   for (int jj=0; jj<400; jj++){

    //-------------------------- RPM al maximo ------------------------//

    Test_Tablero[3] = 114;
    Test_Tablero[4] = 7;
    Test_Tablero[5] = 255;

    CAN0.sendMsgBuf(1968, 0, 8, Test_Tablero);  //RPM al maximo


    vTaskDelay(pdMS_TO_TICKS(delay_time));

    //-------------------------- Tacometro al maximo ------------------------//
    //   CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo tablero
    //

    vTaskDelay(pdMS_TO_TICKS(delay_time));
    Test_Tablero[3] = 115;
    Test_Tablero[4] = 7;
    Test_Tablero[5] = 255;

    CAN0.sendMsgBuf(1968, 0, 8, Test_Tablero);  //Tacometro al maximo


    vTaskDelay(pdMS_TO_TICKS(delay_time));

    //----------------------------------------------------------------------//


    vTaskDelay(pdMS_TO_TICKS(1000));

    CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo tablero


    vTaskDelay(pdMS_TO_TICKS(delay_time));

    Test_Tablero[3] = 114;
    Test_Tablero[4] = 7;
    Test_Tablero[5] = 0;

    //-------------------------- RPM al cero ------------------------//

    CAN0.sendMsgBuf(1968, 0, 8, Test_Tablero);  //RPM a 0



    vTaskDelay(pdMS_TO_TICKS(delay_time));

    // CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo tablero
    // delay(150);

    Test_Tablero[3] = 115;
    Test_Tablero[4] = 7;
    Test_Tablero[5] = 0;

    CAN0.sendMsgBuf(1968, 0, 8, Test_Tablero);  //Tacometro al 0


    vTaskDelay(pdMS_TO_TICKS(delay_time));

    /*CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo tablero
    delay(150);
    Test_Tablero[3] = 113;
    Test_Tablero[4] = 7;
    Test_Tablero[5] = 0;
    //byte Test_Tablero_Temp_2[8]{ 133, 4, 48, 112, 7, 0x00, 0x00, 0x00 };
    CAN0.sendMsgBuf(1968, 0, 8, Test_Tablero);  //Temp agua a 0
    delay(40);

    CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo tablero
    delay(150);
    Test_Tablero[3] = 114;
    Test_Tablero[4] = 7;
    Test_Tablero[5] = 0;
    //byte Test_Tablero_Comb_2[8]{ 133, 4, 48, 113, 7, 0x00, 0x00, 0x00 };
    CAN0.sendMsgBuf(1968, 0, 8, Test_Tablero);  //Combustible a 0
    */

    vTaskDelay(pdMS_TO_TICKS(600));

    //CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo tablero
    //

    vTaskDelay(pdMS_TO_TICKS(delay_time));

    //Test_Tablero[3] = 124;
    //Test_Tablero[4] = 7;
    //Test_Tablero[5] = 0;

    //CAN0.sendMsgBuf(1968, 0, 8, Test_Tablero); //apaga la luz del tablero
    //

    vTaskDelay(pdMS_TO_TICKS(delay_time));
    Test_Tablero[1] = 3;
    Test_Tablero[3] = 114;
    Test_Tablero[4] = 0;
    Test_Tablero[5] = 0;
    //CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo tablero
    //

    vTaskDelay(pdMS_TO_TICKS(delay_time));

    CAN0.sendMsgBuf(1968, 0, 8, Test_Tablero);  //RPM control al auto


    vTaskDelay(pdMS_TO_TICKS(delay_time));
    Test_Tablero[1] = 3;
    Test_Tablero[3] = 115;
    Test_Tablero[4] = 0;
    Test_Tablero[5] = 0;

    //CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo tablero
    //

    vTaskDelay(pdMS_TO_TICKS(delay_time));
    CAN0.sendMsgBuf(1968, 0, 8, Test_Tablero);  //Tacometro control al auto


    vTaskDelay(pdMS_TO_TICKS(delay_time));


    // Test_Tablero[3] = 113;
    // Test_Tablero[4] = 0;
    // Test_Tablero[5] = 0;
    // //byte Test_Tablero_Temp_2[8]{ 133, 4, 48, 112, 7, 0x00, 0x00, 0x00 };
    // CAN0.sendMsgBuf(1968, 0, 8, Test_Tablero);  //Temp agua a 0
    //     while (Continuar_Test == false) {
    //   if (!digitalRead(21)) {
    //     CAN0.readMsgBuf(&can0_rxId, &can0_len, can0_rxBuf);
    //     if (can0_rxId == 1987)
    //       Continuar_Test = true;
    //   }
    // }
    // Continuar_Test = false;

    // Test_Tablero[3] = 114;
    // Test_Tablero[4] = 0;
    // Test_Tablero[5] = 0;
    // //byte Test_Tablero_Comb_2[8]{ 133, 4, 48, 113, 7, 0x00, 0x00, 0x00 };
    // CAN0.sendMsgBuf(1968, 0, 8, Test_Tablero);  //Combustible a 0
    //     while (Continuar_Test == false) {
    //   if (!digitalRead(21)) {
    //     CAN0.readMsgBuf(&can0_rxId, &can0_len, can0_rxBuf);
    //     if (can0_rxId == 1987)
    //       Continuar_Test = true;
    //   }
    // }
    // Continuar_Test = false;
    Test_Tablero[1] = 3;
    Test_Tablero[3] = 124;
    Test_Tablero[4] = 0;
    Test_Tablero[5] = 0;
    vTaskDelay(pdMS_TO_TICKS(800));
    CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo tablero
    // delay(1000);
    // CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo tablero
    // delay(1000);
    // CAN0.sendMsgBuf(1968, 0, 8, Encender_Test);  //enciendo tablero
    vTaskDelay(pdMS_TO_TICKS(50));
    CAN0.sendMsgBuf(1968, 0, 8, Test_Tablero);  //control luz la tiene el auto

    // flags_test_agujas = false;
    vTaskDelay(pdMS_TO_TICKS(4000));
    cambio_dato();
    vTaskSuspend(NULL);

    // }
  }
}
