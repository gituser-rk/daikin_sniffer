#include "daikin_sniffer.h"
#include "esphome/core/log.h"

namespace daikin_sniffer {

static const char *TAG = "daikin";

DaikinSniffer::DaikinSniffer(esphome::uart::UARTComponent *parent)
    : esphome::uart::UARTDevice(parent) {
  sensor = new esphome::text_sensor::TextSensor();
}

void DaikinSniffer::setup() {
  sensor->set_name("Daikin Raw Frame");
  ESP_LOGI(TAG, "Daikin sniffer initialized");
}

void DaikinSniffer::loop() {
  while (available()) {
    uint8_t b = read();
    ESP_LOGD(TAG, "RX: %02X", b);
  }
}

}  // namespace daikin_sniffer
