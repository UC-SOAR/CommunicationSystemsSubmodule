#ifndef QSPI_DEVICE_CTX_HPP
#define QSPI_DEVICE_CTX_HPP

#include <stdint.h>
#include <stm32h7xx_hal.h>

/**
 * @brief Struct representing the context of a QSPI device.
 *
 * This struct encapsulates the context required for QSPI communication,
 * including the chip select (CS) port and pin, and the maximum timeout for
 * operations.
 */
struct QSPI_DeviceContext {
 private:
  GPIO_TypeDef &cs_port;  ///< Reference to the GPIO port for chip select.
  uint16_t cs_pin;        ///< Pin number for chip select.
  uint32_t max_timeout;   ///< Maximum timeout for QSPI operations.

 public:
  /**
   * @brief Constructor for QSPI_DeviceContext.
   *
   * @param cs_port Reference to the GPIO port for chip select.
   * @param cs_pin Pin number for chip select.
   * @param max_timeout Maximum timeout for QSPI operations (default is
   * HAL_MAX_DELAY).
   */
  QSPI_DeviceContext(GPIO_TypeDef &cs_port, uint16_t cs_pin,
                     uint32_t max_timeout = HAL_MAX_DELAY)
      : cs_port(cs_port), cs_pin(cs_pin), max_timeout(max_timeout) {}

  /**
   * @brief Get the chip select port as a pointer.
   *
   * @return GPIO_TypeDef* Pointer to the GPIO port for chip select.
   */
  GPIO_TypeDef *get_cs_port_as_ptr() const { return &this->cs_port; }

  /**
   * @brief Get the chip select port as a reference.
   *
   * @return GPIO_TypeDef& Reference to the GPIO port for chip select.
   */
  GPIO_TypeDef &get_cs_port_as_ref() const { return this->cs_port; }

  /**
   * @brief Get the chip select pin number.
   *
   * @return uint16_t Pin number for chip select.
   */
  uint16_t get_cs_pin() const { return this->cs_pin; }

  /**
   * @brief Get the maximum timeout for QSPI operations.
   *
   * @return uint32_t Maximum timeout for QSPI operations.
   */
  uint32_t get_max_timeout() const { return this->max_timeout; }
};

#endif  // QSPI_DEVICE_CTX_HPP
