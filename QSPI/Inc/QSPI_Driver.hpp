#ifndef QSPI_DRIVER_HPP
#define QSPI_DRIVER_HPP

#include <stm32h7xx_hal_qspi.h>

#include "QSPI_Command.hpp"
#include "QSPI_DeviceContext.hpp"
#include "QSPI_Result.hpp"

/**
 * @brief Class representing a QSPI driver.
 *
 * This class provides methods to perform read and write operations using QSPI.
 * It encapsulates a QSPI handle and provides methods to interact with QSPI
 * devices.
 */
class QSPI_Driver {
 private:
  QSPI_HandleTypeDef &qspi_handle;  ///< Reference to the QSPI handle.

 public:
  /**
   * @brief Constructor for QSPI_Driver.
   *
   * @param hqspi Reference to the QSPI handle.
   */
  QSPI_Driver(QSPI_HandleTypeDef &hqspi) : qspi_handle(hqspi) {}

  /**
   * @brief Write data to a QSPI device.
   *
   * @param ctx The context of the QSPI device.
   * @param cmd The QSPI command to be executed.
   * @return QSPI_Result The result of the write operation.
   */
  QSPI_Result write(const QSPI_DeviceContext &ctx,
                    const QSPI_Command &cmd) const;

  /**
   * @brief Read data from a QSPI device.
   *
   * @param ctx The context of the QSPI device.
   * @param cmd The QSPI command to be executed.
   * @return QSPI_Result The result of the read operation.
   */
  QSPI_Result read(const QSPI_DeviceContext &ctx,
                   const QSPI_Command &cmd) const;
};

#endif  // QSPI_DRIVER_HPP
