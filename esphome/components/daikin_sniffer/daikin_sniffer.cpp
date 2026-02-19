#include "daikin_sniffer.h"
#include "esphome/core/log.h"

namespace daikin_sniffer {

static const char *TAG = "daikin_sniffer";

DaikinSniffer::DaikinSniffer(esphome::uart::UARTComponent *parent)
    : esphome::Component(), esphome::uart::UARTDevice(parent) {
}


void DaikinSniffer::setup() {
  ESP_LOGI(TAG, "Daikin sniffer initialized");
}

void DaikinSniffer::loop() {
  while (available()) {
    uint8_t b = read();
    ESP_LOGD(TAG, "RX: %02X", b);
  }
}

}  // namespace daikin_sniffer
