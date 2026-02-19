#pragma once
#include "esphome.h"

class DaikinSniffer : public esphome::Component, public esphome::uart::UARTDevice {
 public:
  esphome::text_sensor::TextSensor *sensor;

  DaikinSniffer(esphome::uart::UARTComponent *parent);

  void setup() override;
  void loop() override;

 private:
  std::vector<uint8_t> buffer;
};
