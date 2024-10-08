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
 *     "C:/.../AvionicsTemplateRepository/Drivers/STM32H7xx_HAL_Driver/Inc/**",
 *     "C:/.../AvionicsTemplateRepository/Core/Inc/**"
 * ]
 * ```
 */

#include "../Inc/QSPI_Driver.hpp"

#include <stm32h743xx.h>
#include <stm32h7xx_hal.h>
#include <stm32h7xx_hal_qspi.h>

#include "../Inc/QSPI_DeviceContext.hpp"
#include "../Inc/QSPI_Result.hpp"

QSPI_Result QSPI_Driver::send_command(QSPI_DeviceContext &ctx, uint8_t *reg_ptr,
                                      uint8_t *cmd_ptr) const {
  // Pull chip select to low
  // Standard communiaction protocol before sending command
  const QSPI_Result cs_low_result = from_hal_status(HAL_GPIO_WritePin(
      ctx.get_cs_port_as_ptr(), ctx.get_cs_pin(), GPIO_PIN_RESET));
  if (!cs_low_result) {
    return cs_low_result;
  }

  // Send address of target register
  const QSPI_Result send_addr_result = from_hal_status(
      HAL_QSPI_Transmit(&this->qspi_handle, reg_ptr, ctx.get_timeout()));
  if (!send_addr_result) {
    return send_addr_result;
  }

  // Write command to register
  const QSPI_Result write_cmd_result = from_hal_status(
      HAL_QSPI_Transmit(&this->qspi_handle, cmd_ptr, ctx.get_timeout()));
  if (!write_cmd_result) {
    return write_cmd_result;
  }

  // Pull CS back to high
  // This signifies the end of the command
  const QSPI_Result cs_high_result = from_hal_status(HAL_GPIO_WritePin(
      ctx.get_cs_port_as_ptr(), ctx.get_cs_pin(), GPIO_PIN_SET));
  if (!cs_high_result) {
    return cs_high_result;
  }

  return QSPI_Result::Ok;
}

QSPI_Result QSPI_Driver::read(QSPI_DeviceContext &ctx, uint8_t *cmd_ptr,
                              uint8_t *dest_ptr) const {}
