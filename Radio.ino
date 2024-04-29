#include "BRAVO.h"

// +++++++++++++++++++++++++++++++++++++++++++  Funcion Radio +++++++++++++++++++++++++++++++++++++++++++++++++++++//

//-------------------------------------------- Info radio HZ ---------------------------------------------------//

void radio_info() {

  byte can_msg[6]{ 0x43, 0xff, 0xff, 0xff, 0x02, 0x00 };
  CAN0.sendMsgBuf(0x545, 0, 6, can_msg);
  vTaskDelay(pdMS_TO_TICKS(20));
}

//-------------------------------------------- RDS info radio ---------------------------------------------------//

void RDS_info() {

  byte can_msg[6]{ 0xB6, 0xff, 0xff, 0xff, 0x02, 0x00 };
  CAN0.sendMsgBuf(0x565, 0, 6, can_msg);
  vTaskDelay(pdMS_TO_TICKS(20));
}
//-------------------------------------------- RDS info NAV ---------------------------------------------------//

void Izquierda() {

  byte can_msg[8]{ 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x09 };   //  80  40  40  80  40
  byte can_msg1[8]{ 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09 };  // 40  40  80  80  00
  CAN0.sendMsgBuf(0x507, 0, 8, can_msg);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x507, 0, 8, can_msg1);
  vTaskDelay(pdMS_TO_TICKS(20));
}

void Derecha() {
  byte can_msg[8]{ 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x09 };   //  80  40  40  80  40
  byte can_msg1[8]{ 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x09 };  // 40  40  80  80  00
  CAN0.sendMsgBuf(0x507, 0, 8, can_msg);
  vTaskDelay(pdMS_TO_TICKS(20));
  CAN0.sendMsgBuf(0x507, 0, 8, can_msg1);
  vTaskDelay(pdMS_TO_TICKS(20));
}
