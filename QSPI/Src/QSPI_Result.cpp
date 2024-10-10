#include "../Inc/QSPI_Result.hpp"

QSPI_Result from_hal_status(HAL_StatusTypeDef status) {
  if (status == HAL_OK) {
    return QSPI_Result::Ok;
  }

  return static_cast<QSPI_Result>(static_cast<signed char>(status) * -1);
}
