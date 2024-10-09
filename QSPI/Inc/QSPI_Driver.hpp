#ifndef QSPI_DRIVER_HPP
#define QSPI_DRIVER_HPP
#define QUADSPI

#include <stm32h743xx.h>
#include <stm32h7xx_hal_qspi.h>

// Forward declaration to satisfy linker without include statement
#include "QSPI_Command.hpp"
#include "QSPI_DeviceContext.hpp"
#include "QSPI_Result.hpp"

/**
 * This class provides another layer of abstraction over HAL.
 * It encapsulates a HAL QSPI handle to provide a safer and easier to use API.
 * The QSPI handle must be intialized prior to this wrapper being initialized.
 *
 * The intent is for only one instance of this class to exist.
 */
class QSPI_Driver {
 private:
  QSPI_HandleTypeDef &qspi_handle;

 public:
  QSPI_Driver(QSPI_HandleTypeDef &hqspi) : qspi_handle(hqspi) {}

  QSPI_Result send_command(const QSPI_DeviceContext &ctx,
                           const QSPI_Command &cmd) const;
  QSPI_Result read(QSPI_DeviceContext &ctx, uint8_t *cmd_ptr,
                   uint8_t *dest_ptr) const;
};

#endif  // QSPI_DRIVER_HPP
