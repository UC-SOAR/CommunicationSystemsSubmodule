#ifndef QSPI_DEVICE_CTX_HPP
#define QSPI_DEVICE_CTX_HPP

#include <stdint.h>
#include <stm32h7xx_hal.h>

struct QSPI_DeviceContext {
 private:
  GPIO_TypeDef &cs_port;
  uint16_t cs_pin;
  uint32_t timeout;

 public:
  QSPI_DeviceContext(GPIO_TypeDef &cs_port, uint16_t cs_pin,
                     uint32_t timeout = HAL_MAX_DELAY)
      : cs_port(cs_port), cs_pin(cs_pin), timeout(timeout) {}

  GPIO_TypeDef *get_cs_port_as_ptr() const { return &this->cs_port; }
  GPIO_TypeDef &get_cs_port_as_ref() const { return this->cs_port; }

  uint16_t get_cs_pin() const { return this->cs_pin; }
  uint32_t get_timeout() const { return this->timeout; }
};

#endif  // QSPI_DEVICE_CTX_HPP
