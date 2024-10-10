#ifndef QSPI_DRIVER_HPP
#define QSPI_DRIVER_HPP

#include <stm32h743xx.h>
#include <stm32h7xx_hal_qspi.h>

#include "QSPI_Command.hpp"
#include "QSPI_DeviceContext.hpp"
#include "QSPI_Result.hpp"

class QSPI_Driver {
 private:
  QSPI_HandleTypeDef &qspi_handle;

 public:
  QSPI_Driver(QSPI_HandleTypeDef &hqspi) : qspi_handle(hqspi) {}

  QSPI_Result write(const QSPI_DeviceContext &ctx,
                    const QSPI_Command &cmd) const;

  QSPI_Result read(const QSPI_DeviceContext &ctx,
                   const QSPI_Command &cmd) const;
};

#endif  // QSPI_DRIVER_HPP
