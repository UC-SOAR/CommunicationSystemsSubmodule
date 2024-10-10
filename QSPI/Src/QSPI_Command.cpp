#include "../Inc/QSPI_Command.hpp"

// If anything causes problems, it probably has to do with this function
// This requires testing along with the rest of the QSPI driver but this is the
// most likely source of issues
QSPI_CommandTypeDef QSPI_Command::to_hal_cmd() const {
  QSPI_CommandTypeDef hal_cmd;

  hal_cmd.Address = this->address;
  hal_cmd.AddressSize = static_cast<uint32_t>(this->address_size);
  hal_cmd.AddressMode = QSPI_ADDRESS_NONE;

  hal_cmd.Instruction = this->instruction;
  hal_cmd.InstructionMode = QSPI_INSTRUCTION_NONE;

  hal_cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_1_LINE;
  hal_cmd.AlternateBytes = 0;
  hal_cmd.AlternateBytesSize = 0;

  hal_cmd.DataMode = QSPI_DATA_1_LINE;
  hal_cmd.DummyCycles = 0;
  hal_cmd.NbData = this->transfer_size;
  hal_cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  hal_cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  hal_cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  return hal_cmd;
}
