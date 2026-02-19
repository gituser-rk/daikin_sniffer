import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart
from esphome.const import CONF_ID, CONF_UART_ID

daikin_ns = cg.esphome_ns.namespace("daikin_sniffer")
DaikinSniffer = daikin_ns.class_("DaikinSniffer", cg.Component, uart.UARTDevice)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(DaikinSniffer),
    cv.Required(CONF_UART_ID): cv.use_id(uart.UARTComponent),
}).extend(cv.COMPONENT_SCHEMA).extend(uart.UART_DEVICE_SCHEMA)

async def to_code(config):
    uart_component = await cg.get_variable(config[CONF_UART_ID])
    var = cg.new_Pvariable(config[CONF_ID], uart_component)
    await cg.register_component(var, config)
    await uart.register_uart_device(var, config)
