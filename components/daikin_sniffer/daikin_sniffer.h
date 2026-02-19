#pragma once

#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"
#include "esphome/components/text_sensor/text_sensor.h"

namespace daikin_sniffer {

class DaikinSniffer : public esphome::Component, public esphome::uart::UARTDevice {
 public:
  esphome::text_sensor::TextSensor *sensor;

  explicit DaikinSniffer(esphome::uart::UARTComponent *parent);

  void setup() override;
  void loop() override;

 private:
  std::vector<uint8_t> buffer;
};

}  // namespace daikin_sniffer
