#include "BRAVO.h"

// +++++++++++++++++++++++++++++++++++++++++++  Funcion Sleep +++++++++++++++++++++++++++++++++++++++++++++++++++++//

void enter_sleep() {
  Serial.println("Sleep...");
  preferences.end();

#ifdef DEEP_SLEEP_EXT0
  pinMode(36, INPUT_PUL);  // Defino estado alto y como entrada
  // pinMode(OPEN_MIRR, INPUT);   // Rele abrir espejos
  // pinMode(32, OUTPUT);       // Rele de alimentacion de techo y espejos
  rtc_gpio_hold_en(36);                            // Defino el GPIO para evento
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_36, LOW);  // Defino el GPIO36 como pin de evento para despertar
#endif
  // pinMode(POWER, OUTPUT);  // Rele
  // digitalWrite(POWER,LOW);
  // gpio_reset_pin(GPIO_NUM_32);
//   dato_mostrado = 0;
// dato_display = &fiat;
  esp_deep_sleep_start();  // Pongo a dormir a la ESP32
}
  