/**
 * @author Connell Reffo
 */

#include "../Inc/QSPI_Driver.hpp"

#include <stm32h743xx.h>
#include <stm32h7xx_hal.h>
#include <stm32h7xx_hal_qspi.h>

#include "../Inc/QSPI_DeviceContext.hpp"
#include "../Inc/QSPI_Result.hpp"

QSPI_Result QSPI_Driver::write(const QSPI_DeviceContext &ctx,
                               const QSPI_Command &cmd) const {
  // Pull chip select to low
  // Standard communiaction protocol before sending command
  HAL_GPIO_WritePin(ctx.get_cs_port_as_ptr(), ctx.get_cs_pin(), GPIO_PIN_RESET);

  // Setup command
  QSPI_CommandTypeDef hal_cmd = cmd.to_hal_cmd();

  const QSPI_Result write_cmd_result = from_hal_status(
      HAL_QSPI_Command(&this->qspi_handle, &hal_cmd, ctx.get_max_timeout()));

  if (!write_cmd_result) {
    return write_cmd_result;
  }

  // Transmit command
  const QSPI_Result transmit_cmd_result = from_hal_status(HAL_QSPI_Transmit(
      &this->qspi_handle, cmd.data_buffer, ctx.get_max_timeout()));

  if (!transmit_cmd_result) {
    return transmit_cmd_result;
  }

  // Pull CS back to high
  // This signifies the end of the command
  HAL_GPIO_WritePin(ctx.get_cs_port_as_ptr(), ctx.get_cs_pin(), GPIO_PIN_SET);

  return QSPI_Result::Ok;
}

QSPI_Result QSPI_Driver::read(const QSPI_DeviceContext &ctx,
                              const QSPI_Command &cmd) const {
  // Pull CS low
  HAL_GPIO_WritePin(ctx.get_cs_port_as_ptr(), ctx.get_cs_pin(), GPIO_PIN_RESET);

  // Setup command
  QSPI_CommandTypeDef hal_cmd = cmd.to_hal_cmd();

  const QSPI_Result read_cmd_result = from_hal_status(
      HAL_QSPI_Command(&this->qspi_handle, &hal_cmd, ctx.get_max_timeout()));

  if (!read_cmd_result) {
    return read_cmd_result;
  }

  // Receive data
  const QSPI_Result receive_cmd_result = from_hal_status(HAL_QSPI_Receive(
      &this->qspi_handle, cmd.data_buffer, ctx.get_max_timeout()));

  if (!receive_cmd_result) {
    return receive_cmd_result;
  }

  // Pull CS back high
  HAL_GPIO_WritePin(ctx.get_cs_port_as_ptr(), ctx.get_cs_pin(), GPIO_PIN_SET);

  return QSPI_Result::Ok;
}
