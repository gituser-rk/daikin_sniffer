#include "daikin_sniffer.h"

DaikinSniffer::DaikinSniffer(esphome::uart::UARTComponent *parent)
    : esphome::uart::UARTDevice(parent) {
  sensor = new esphome::text_sensor::TextSensor();
}

void DaikinSniffer::setup() {
  sensor->set_name("Daikin Raw Frame");
  App.register_text_sensor(sensor);
}

void DaikinSniffer::loop() {
  while (available()) {
    uint8_t b = read();
    buffer.push_back(b);

    if (buffer.size() > 2 && buffer[0] == 0xAA && buffer[1] == 0x55) {
      if (buffer.size() > 5) {
        int len = buffer[4];
        if (buffer.size() >= 5 + len + 1) {
          char hex[512];
          int pos = 0;
          for (uint8_t v : buffer) pos += sprintf(hex + pos, "%02X ", v);
          sensor->publish_state(hex);
          buffer.clear();
        }
      }
    }

    if (buffer.size() > 200) buffer.clear();
  }
}
