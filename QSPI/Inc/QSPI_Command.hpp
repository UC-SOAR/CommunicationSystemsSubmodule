#ifndef QSPI_COMMAND_HPP
#define QSPI_COMMAND_HPP

#include <stdint.h>
#include <stm32h7xx_hal_qspi.h>

enum class QSPI_AddressSize {
  OneByte = QSPI_ADDRESS_8_BITS,
  TwoBytes = QSPI_ADDRESS_16_BITS,
  ThreeBytes = QSPI_ADDRESS_24_BITS,
  FourBytes = QSPI_ADDRESS_32_BITS
};

struct QSPI_Command {
  uint8_t instruction;
  uint32_t address;
  QSPI_AddressSize address_size;
  size_t transfer_size;
  uint8_t *data_buffer = nullptr;

  QSPI_CommandTypeDef to_hal_cmd() const;
};

#endif  // QSPI_COMMAND_HPP
