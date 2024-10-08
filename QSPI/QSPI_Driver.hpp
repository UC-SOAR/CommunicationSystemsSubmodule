/**
 * @author Connell Reffo
 * @brief This driver is specific to STM32H7xx chips
 *
 * To set up correctly in VS Code, add the following to c_cpp_properties.json:
 *
 * ```json
 * "includePath": [
 *     "${workspaceFolder}/**",
 *     "C:/.../AvionicsTemplateRepository/Drivers/CMSIS/Device/ST/STM32H7xx/Include/**",
 *     "C:/.../AvionicsTemplateRepository/Drivers/CMSIS/Include/**",
 *     "C:/.../AvionicsTemplateRepository/Drivers/STM32H7xx_HAL_Driver/Inc/**"
 * ]
 * ```
 */
#ifndef QSPI_DRIVER_H
#define QSPI_DRIVER_H
#define QUADSPI

#include <stdint.h>
#include <stm32h743xx.h>
#include <stm32h7xx_hal_qspi.h>

struct QSPIConfig {
 private:
  int frequency;
  int mode;
  int address_size;

 public:
  QSPIConfig(int frequency, int mode, int address_size)
      : frequency(frequency), mode(mode), address_size(address_size) {}

  int get_frequency() const { return this->frequency; }

  int get_mode() const { return this->mode; }

  int get_address_size() const { return this->address_size; }
};

class QSPIDriver {
 private:
  QSPI_HandleTypeDef *qspi_handle;

 public:
  QSPIDriver(QSPI_HandleTypeDef *hqspi) : qspi_handle(hqspi) {}
};

#endif  // QSPI_DRIVER_H
