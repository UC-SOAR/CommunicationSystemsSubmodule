#ifndef QSPI_COMMAND_HPP
#define QSPI_COMMAND_HPP

#include <stdint.h>
#include <stm32h7xx_hal_qspi.h>

/**
 * @brief Enum class representing the size of the QSPI address.
 */
enum class QSPI_AddressSize {
  OneByte = QSPI_ADDRESS_8_BITS,      ///< 8-bit address
  TwoBytes = QSPI_ADDRESS_16_BITS,    ///< 16-bit address
  ThreeBytes = QSPI_ADDRESS_24_BITS,  ///< 24-bit address
  FourBytes = QSPI_ADDRESS_32_BITS    ///< 32-bit address
};

/**
 * @brief Struct representing a QSPI command.
 *
 * This struct encapsulates the details of a QSPI command, including the
 * instruction, address, address size, transfer size, and data buffer. It also
 * provides a method to convert the command to a HAL-compatible QSPI command
 * structure.
 */
struct QSPI_Command {
  uint8_t instruction;  ///< The instruction byte for the QSPI command.
  uint32_t address;     ///< The address for the QSPI command.
  QSPI_AddressSize address_size;   ///< The size of the address.
  size_t transfer_size;            ///< The size of the data transfer.
  uint8_t *data_buffer = nullptr;  ///< Pointer to the data buffer.

  /**
   * @brief Converts the QSPI command to a HAL-compatible QSPI command
   * structure.
   *
   * @return QSPI_CommandTypeDef The HAL-compatible QSPI command structure.
   */
  QSPI_CommandTypeDef to_hal_cmd() const;
};

#endif  // QSPI_COMMAND_HPP
