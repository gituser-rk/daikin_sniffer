#pragma once

#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
namespace daikin_sniffer {

class DaikinSniffer : public Component, public uart::UARTDevice {
 public:
  explicit DaikinSniffer(uart::UARTComponent *parent);

  void setup() override;
  void loop() override;
};

}  // namespace daikin_sniffer
}  // namespace esphome
