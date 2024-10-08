/**
 * @author Connell Reffo
 * @brief This driver is specific to STM32H743XX chips
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

class QSPIDriver {};

#endif  // QSPI_DRIVER_H
