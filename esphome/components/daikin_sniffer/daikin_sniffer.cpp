#include "daikin_sniffer.h"
#include "esphome/core/log.h"

namespace esphome {
namespace daikin_sniffer {

static const char *TAG = "daikin_sniffer";

DaikinSniffer::DaikinSniffer(uart::UARTComponent *parent)
    : Component(), UARTDevice(parent) {}

void DaikinSniffer::setup() {
  ESP_LOGI(TAG, "Daikin sniffer initialized");
}

void DaikinSniffer::loop() {
  while (this->available()) {
    uint8_t b = this->read();
    ESP_LOGD(TAG, "RX: %02X", b);
  }
}

}  // namespace daikin_sniffer
}  // namespace esphome
