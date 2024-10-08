#ifndef QSPI_RESULT_HPP
#define QSPI_RESULT_HPP

#include <stm32h7xx_hal.h>

/**
 * The `Ok` variant is the only truthy variant
 */
enum class QSPI_Result { Ok = 1, Err = -1, Busy = -2, Timeout = -3 };

inline bool operator!(QSPI_Result error) { return error != QSPI_Result::Ok; }

inline bool operator==(QSPI_Result error, bool value) {
  return (error == QSPI_Result::Ok) == value;
}

inline bool operator!=(QSPI_Result error, bool value) {
  return !(error == value);
}

QSPI_Result from_hal_status(HAL_StatusTypeDef status) {
  if (status == HAL_OK) {
    return QSPI_Result::Ok;
  }

  return static_cast<QSPI_Result>(static_cast<signed char>(status) * -1);
}

#endif  // QSPI_RESULT_HPP
