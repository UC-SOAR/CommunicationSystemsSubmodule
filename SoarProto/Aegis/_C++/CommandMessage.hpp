/*
 *  This file is generated with Embedded Proto, PLEASE DO NOT EDIT!
 *  source: CommandMessage.proto
 */

// This file is generated. Please do not edit!
#ifndef COMMANDMESSAGE_H
#define COMMANDMESSAGE_H

#include <cstdint>
#include <MessageInterface.h>
#include <WireFormatter.h>
#include <Fields.h>
#include <MessageSizeCalculator.h>
#include <ReadBufferSection.h>
#include <RepeatedFieldFixedSize.h>
#include <FieldStringBytes.h>
#include <Errors.h>
#include <Defines.h>
#include <limits>

// Include external proto definitions
#include "CoreProto.h"

namespace Proto {

class FcbCommand final: public ::EmbeddedProto::MessageInterface
{
  public:
    FcbCommand() = default;
    FcbCommand(const FcbCommand& rhs )
    {
      set_command_enum(rhs.get_command_enum());
    }

    FcbCommand(const FcbCommand&& rhs ) noexcept
    {
      set_command_enum(rhs.get_command_enum());
    }

    ~FcbCommand() override = default;

    enum class Command : uint32_t
    {
      RSC_FIRST_INVALID = 0,
      RSC_ANY_TO_ABORT = 1,
      RSC_OPEN_VENT = 2,
      RSC_CLOSE_VENT = 3,
      RSC_OPEN_DRAIN = 4,
      RSC_CLOSE_DRAIN = 5,
      RSC_MEV_CLOSE = 6,
      RSC_GOTO_FILL = 7,
      RSC_ARM_CONFIRM_1 = 8,
      RSC_ARM_CONFIRM_2 = 9,
      RSC_GOTO_ARM = 10,
      RSC_GOTO_PRELAUNCH = 11,
      RSC_GOTO_IGNITION = 12,
      RSC_IGNITION_TO_LAUNCH = 13,
      RSC_LAUNCH_TO_BURN = 14,
      RSC_BURN_TO_COAST = 15,
      RSC_COAST_TO_BRAKING = 16,
      RSC_COAST_TO_DESCENT = 17,
      RSC_BRAKING_TO_DESCENT = 18,
      RSC_DESCENT_TO_TOUCHDOWN = 19,
      RSC_MANUAL_IGNITION_CONFIRMED = 20,
      RSC_GOTO_TEST = 21,
      RSC_TEST_MEV_OPEN = 22,
      RSC_TEST_MEV_ENABLE = 23,
      RSC_TEST_MEV_DISABLE = 24,
      RSC_CAMERA1_SWITCH = 25,
      RSC_CAMERA2_SWITCH = 26,
      RSC_CAMERA3_SWITCH = 27,
      RSC_CAM1_ENABLE = 28,
      RSC_CAM1_DISABLE = 29,
      RSC_CAM2_ENABLE = 30,
      RSC_CAM2_DISABLE = 31,
      RSC_CAM3_ENABLE = 32,
      RSC_CAM3_DISABLE = 33,
      RSC_AIR_BRAKES_ENABLE = 34,
      RSC_AIR_BRAKES_DISABLE = 35,
      RSC_ERASE_FLASH = 36,
      RSC_NONE = 37
    };

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      COMMAND_ENUM = 1
    };

    FcbCommand& operator=(const FcbCommand& rhs)
    {
      set_command_enum(rhs.get_command_enum());
      return *this;
    }

    FcbCommand& operator=(const FcbCommand&& rhs) noexcept
    {
      set_command_enum(rhs.get_command_enum());
      return *this;
    }

    static constexpr char const* COMMAND_ENUM_NAME = "command_enum";
    inline void clear_command_enum() { command_enum_.clear(); }
    inline void set_command_enum(const Command& value) { command_enum_ = value; }
    inline void set_command_enum(const Command&& value) { command_enum_ = value; }
    inline const Command& get_command_enum() const { return command_enum_.get(); }
    inline Command command_enum() const { return command_enum_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((static_cast<Command>(0) != command_enum_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = command_enum_.serialize_with_id(static_cast<uint32_t>(FieldNumber::COMMAND_ENUM), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::COMMAND_ENUM:
            return_value = command_enum_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_command_enum();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::COMMAND_ENUM:
          name = COMMAND_ENUM_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = command_enum_.to_string(left_chars, indent_level + 2, COMMAND_ENUM_NAME, true);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::enumeration<Command> command_enum_ = static_cast<Command>(0);

};

class FsbCommand final: public ::EmbeddedProto::MessageInterface
{
  public:
    FsbCommand() = default;
    FsbCommand(const FsbCommand& rhs )
    {
      set_command_enum(rhs.get_command_enum());
      set_command_param(rhs.get_command_param());
    }

    FsbCommand(const FsbCommand&& rhs ) noexcept
    {
      set_command_enum(rhs.get_command_enum());
      set_command_param(rhs.get_command_param());
    }

    ~FsbCommand() override = default;

    enum class Command : uint32_t
    {
      FSB_NONE = 0,
      FSB_OPEN_AC1 = 3,
      FSB_CLOSE_AC1 = 4,
      FSB_OPEN_AC2 = 5,
      FSB_CLOSE_AC2 = 6,
      FSB_OPEN_PBV1 = 7,
      FSB_CLOSE_PBV1 = 8,
      FSB_OPEN_PBV2 = 9,
      FSB_CLOSE_PBV2 = 10,
      FSB_OPEN_PBV3 = 11,
      FSB_CLOSE_PBV3 = 12,
      FSB_OPEN_PBV4 = 13,
      FSB_CLOSE_PBV4 = 14,
      FSB_OPEN_SOL5 = 21,
      FSB_CLOSE_SOL5 = 22,
      FSB_OPEN_SOL6 = 23,
      FSB_CLOSE_SOL6 = 24,
      FSB_OPEN_SOL7 = 25,
      FSB_CLOSE_SOL7 = 26,
      FSB_OPEN_SOL8A = 27,
      FSB_CLOSE_SOL8A = 28,
      FSB_OPEN_SOL8B = 29,
      FSB_CLOSE_SOL8B = 30,
      FSB_TARE_NOS1_LOAD_CELL = 33,
      FSB_TARE_NOS2_LOAD_CELL = 34,
      FSB_CALIBRATE_NOS1_LOAD_CELL = 35,
      FSB_CALIBRATE_NOS2_LOAD_CELL = 36,
      FSB_IGNITE_PAD_BOX1 = 31,
      FSB_IGNITE_PAD_BOX2 = 32,
      FSB_KILL_PAD_BOX1 = 37,
      FSB_KILL_PAD_BOX2 = 38,
      FSB_LAST = 39
    };

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      COMMAND_ENUM = 1,
      COMMAND_PARAM = 2
    };

    FsbCommand& operator=(const FsbCommand& rhs)
    {
      set_command_enum(rhs.get_command_enum());
      set_command_param(rhs.get_command_param());
      return *this;
    }

    FsbCommand& operator=(const FsbCommand&& rhs) noexcept
    {
      set_command_enum(rhs.get_command_enum());
      set_command_param(rhs.get_command_param());
      return *this;
    }

    static constexpr char const* COMMAND_ENUM_NAME = "command_enum";
    inline void clear_command_enum() { command_enum_.clear(); }
    inline void set_command_enum(const Command& value) { command_enum_ = value; }
    inline void set_command_enum(const Command&& value) { command_enum_ = value; }
    inline const Command& get_command_enum() const { return command_enum_.get(); }
    inline Command command_enum() const { return command_enum_.get(); }

    static constexpr char const* COMMAND_PARAM_NAME = "command_param";
    inline void clear_command_param() { command_param_.clear(); }
    inline void set_command_param(const int32_t& value) { command_param_ = value; }
    inline void set_command_param(const int32_t&& value) { command_param_ = value; }
    inline int32_t& mutable_command_param() { return command_param_.get(); }
    inline const int32_t& get_command_param() const { return command_param_.get(); }
    inline int32_t command_param() const { return command_param_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((static_cast<Command>(0) != command_enum_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = command_enum_.serialize_with_id(static_cast<uint32_t>(FieldNumber::COMMAND_ENUM), buffer, false);
      }

      if((0 != command_param_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = command_param_.serialize_with_id(static_cast<uint32_t>(FieldNumber::COMMAND_PARAM), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::COMMAND_ENUM:
            return_value = command_enum_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::COMMAND_PARAM:
            return_value = command_param_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_command_enum();
      clear_command_param();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::COMMAND_ENUM:
          name = COMMAND_ENUM_NAME;
          break;
        case FieldNumber::COMMAND_PARAM:
          name = COMMAND_PARAM_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = command_enum_.to_string(left_chars, indent_level + 2, COMMAND_ENUM_NAME, true);
      left_chars = command_param_.to_string(left_chars, indent_level + 2, COMMAND_PARAM_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::enumeration<Command> command_enum_ = static_cast<Command>(0);
      EmbeddedProto::int32 command_param_ = 0;

};

class LrbCommand final: public ::EmbeddedProto::MessageInterface
{
  public:
    LrbCommand() = default;
    LrbCommand(const LrbCommand& rhs )
    {
      set_command_enum(rhs.get_command_enum());
      set_command_param(rhs.get_command_param());
    }

    LrbCommand(const LrbCommand&& rhs ) noexcept
    {
      set_command_enum(rhs.get_command_enum());
      set_command_param(rhs.get_command_param());
    }

    ~LrbCommand() override = default;

    enum class Command : uint32_t
    {
      LRB_NONE = 0,
      LRB_TARE_LOAD_CELL = 1,
      LRB_CALIBRATE_LOAD_CELL = 2,
      LRB_LAST = 3
    };

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      COMMAND_ENUM = 1,
      COMMAND_PARAM = 2
    };

    LrbCommand& operator=(const LrbCommand& rhs)
    {
      set_command_enum(rhs.get_command_enum());
      set_command_param(rhs.get_command_param());
      return *this;
    }

    LrbCommand& operator=(const LrbCommand&& rhs) noexcept
    {
      set_command_enum(rhs.get_command_enum());
      set_command_param(rhs.get_command_param());
      return *this;
    }

    static constexpr char const* COMMAND_ENUM_NAME = "command_enum";
    inline void clear_command_enum() { command_enum_.clear(); }
    inline void set_command_enum(const Command& value) { command_enum_ = value; }
    inline void set_command_enum(const Command&& value) { command_enum_ = value; }
    inline const Command& get_command_enum() const { return command_enum_.get(); }
    inline Command command_enum() const { return command_enum_.get(); }

    static constexpr char const* COMMAND_PARAM_NAME = "command_param";
    inline void clear_command_param() { command_param_.clear(); }
    inline void set_command_param(const int32_t& value) { command_param_ = value; }
    inline void set_command_param(const int32_t&& value) { command_param_ = value; }
    inline int32_t& mutable_command_param() { return command_param_.get(); }
    inline const int32_t& get_command_param() const { return command_param_.get(); }
    inline int32_t command_param() const { return command_param_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((static_cast<Command>(0) != command_enum_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = command_enum_.serialize_with_id(static_cast<uint32_t>(FieldNumber::COMMAND_ENUM), buffer, false);
      }

      if((0 != command_param_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = command_param_.serialize_with_id(static_cast<uint32_t>(FieldNumber::COMMAND_PARAM), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::COMMAND_ENUM:
            return_value = command_enum_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::COMMAND_PARAM:
            return_value = command_param_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_command_enum();
      clear_command_param();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::COMMAND_ENUM:
          name = COMMAND_ENUM_NAME;
          break;
        case FieldNumber::COMMAND_PARAM:
          name = COMMAND_PARAM_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = command_enum_.to_string(left_chars, indent_level + 2, COMMAND_ENUM_NAME, true);
      left_chars = command_param_.to_string(left_chars, indent_level + 2, COMMAND_PARAM_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::enumeration<Command> command_enum_ = static_cast<Command>(0);
      EmbeddedProto::int32 command_param_ = 0;

};

class PbbCommand final: public ::EmbeddedProto::MessageInterface
{
  public:
    PbbCommand() = default;
    PbbCommand(const PbbCommand& rhs )
    {
      set_command_enum(rhs.get_command_enum());
    }

    PbbCommand(const PbbCommand&& rhs ) noexcept
    {
      set_command_enum(rhs.get_command_enum());
    }

    ~PbbCommand() override = default;

    enum class Command : uint32_t
    {
      PBB_NONE = 0,
      PBB_OPEN_MEV = 1,
      PBB_CLOSE_MEV = 2,
      PBB_OPEN_DRAIN = 3,
      PBB_CLOSE_DRAIN = 4,
      PBB_LAST = 5
    };

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      COMMAND_ENUM = 1
    };

    PbbCommand& operator=(const PbbCommand& rhs)
    {
      set_command_enum(rhs.get_command_enum());
      return *this;
    }

    PbbCommand& operator=(const PbbCommand&& rhs) noexcept
    {
      set_command_enum(rhs.get_command_enum());
      return *this;
    }

    static constexpr char const* COMMAND_ENUM_NAME = "command_enum";
    inline void clear_command_enum() { command_enum_.clear(); }
    inline void set_command_enum(const Command& value) { command_enum_ = value; }
    inline void set_command_enum(const Command&& value) { command_enum_ = value; }
    inline const Command& get_command_enum() const { return command_enum_.get(); }
    inline Command command_enum() const { return command_enum_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((static_cast<Command>(0) != command_enum_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = command_enum_.serialize_with_id(static_cast<uint32_t>(FieldNumber::COMMAND_ENUM), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::COMMAND_ENUM:
            return_value = command_enum_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_command_enum();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::COMMAND_ENUM:
          name = COMMAND_ENUM_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = command_enum_.to_string(left_chars, indent_level + 2, COMMAND_ENUM_NAME, true);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::enumeration<Command> command_enum_ = static_cast<Command>(0);

};

class CommandMessage final: public ::EmbeddedProto::MessageInterface
{
  public:
    CommandMessage() = default;
    CommandMessage(const CommandMessage& rhs )
    {
      set_source(rhs.get_source());
      set_target(rhs.get_target());
      set_source_sequence_num(rhs.get_source_sequence_num());
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::FCB_COMMAND:
          set_fcb_command(rhs.get_fcb_command());
          break;

        case FieldNumber::PBB_COMMAND:
          set_pbb_command(rhs.get_pbb_command());
          break;

        case FieldNumber::FSB_COMMAND:
          set_fsb_command(rhs.get_fsb_command());
          break;

        case FieldNumber::LRB_COMMAND:
          set_lrb_command(rhs.get_lrb_command());
          break;

        default:
          break;
      }

    }

    CommandMessage(const CommandMessage&& rhs ) noexcept
    {
      set_source(rhs.get_source());
      set_target(rhs.get_target());
      set_source_sequence_num(rhs.get_source_sequence_num());
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::FCB_COMMAND:
          set_fcb_command(rhs.get_fcb_command());
          break;

        case FieldNumber::PBB_COMMAND:
          set_pbb_command(rhs.get_pbb_command());
          break;

        case FieldNumber::FSB_COMMAND:
          set_fsb_command(rhs.get_fsb_command());
          break;

        case FieldNumber::LRB_COMMAND:
          set_lrb_command(rhs.get_lrb_command());
          break;

        default:
          break;
      }

    }

    ~CommandMessage() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      SOURCE = 1,
      TARGET = 2,
      SOURCE_SEQUENCE_NUM = 3,
      FCB_COMMAND = 4,
      PBB_COMMAND = 5,
      FSB_COMMAND = 6,
      LRB_COMMAND = 7
    };

    CommandMessage& operator=(const CommandMessage& rhs)
    {
      set_source(rhs.get_source());
      set_target(rhs.get_target());
      set_source_sequence_num(rhs.get_source_sequence_num());
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::FCB_COMMAND:
          set_fcb_command(rhs.get_fcb_command());
          break;

        case FieldNumber::PBB_COMMAND:
          set_pbb_command(rhs.get_pbb_command());
          break;

        case FieldNumber::FSB_COMMAND:
          set_fsb_command(rhs.get_fsb_command());
          break;

        case FieldNumber::LRB_COMMAND:
          set_lrb_command(rhs.get_lrb_command());
          break;

        default:
          break;
      }

      return *this;
    }

    CommandMessage& operator=(const CommandMessage&& rhs) noexcept
    {
      set_source(rhs.get_source());
      set_target(rhs.get_target());
      set_source_sequence_num(rhs.get_source_sequence_num());
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::FCB_COMMAND:
          set_fcb_command(rhs.get_fcb_command());
          break;

        case FieldNumber::PBB_COMMAND:
          set_pbb_command(rhs.get_pbb_command());
          break;

        case FieldNumber::FSB_COMMAND:
          set_fsb_command(rhs.get_fsb_command());
          break;

        case FieldNumber::LRB_COMMAND:
          set_lrb_command(rhs.get_lrb_command());
          break;

        default:
          break;
      }

      return *this;
    }

    static constexpr char const* SOURCE_NAME = "source";
    inline void clear_source() { source_.clear(); }
    inline void set_source(const Node& value) { source_ = value; }
    inline void set_source(const Node&& value) { source_ = value; }
    inline const Node& get_source() const { return source_.get(); }
    inline Node source() const { return source_.get(); }

    static constexpr char const* TARGET_NAME = "target";
    inline void clear_target() { target_.clear(); }
    inline void set_target(const Node& value) { target_ = value; }
    inline void set_target(const Node&& value) { target_ = value; }
    inline const Node& get_target() const { return target_.get(); }
    inline Node target() const { return target_.get(); }

    static constexpr char const* SOURCE_SEQUENCE_NUM_NAME = "source_sequence_num";
    inline void clear_source_sequence_num() { source_sequence_num_.clear(); }
    inline void set_source_sequence_num(const uint32_t& value) { source_sequence_num_ = value; }
    inline void set_source_sequence_num(const uint32_t&& value) { source_sequence_num_ = value; }
    inline uint32_t& mutable_source_sequence_num() { return source_sequence_num_.get(); }
    inline const uint32_t& get_source_sequence_num() const { return source_sequence_num_.get(); }
    inline uint32_t source_sequence_num() const { return source_sequence_num_.get(); }

    FieldNumber get_which_message() const { return which_message_; }

    static constexpr char const* FCB_COMMAND_NAME = "fcb_command";
    inline bool has_fcb_command() const
    {
      return FieldNumber::FCB_COMMAND == which_message_;
    }
    inline void clear_fcb_command()
    {
      if(FieldNumber::FCB_COMMAND == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.fcb_command_.~FcbCommand();
      }
    }
    inline void set_fcb_command(const FcbCommand& value)
    {
      if(FieldNumber::FCB_COMMAND != which_message_)
      {
        init_message(FieldNumber::FCB_COMMAND);
      }
      message_.fcb_command_ = value;
    }
    inline void set_fcb_command(const FcbCommand&& value)
    {
      if(FieldNumber::FCB_COMMAND != which_message_)
      {
        init_message(FieldNumber::FCB_COMMAND);
      }
      message_.fcb_command_ = value;
    }
    inline FcbCommand& mutable_fcb_command()
    {
      if(FieldNumber::FCB_COMMAND != which_message_)
      {
        init_message(FieldNumber::FCB_COMMAND);
      }
      return message_.fcb_command_;
    }
    inline const FcbCommand& get_fcb_command() const { return message_.fcb_command_; }
    inline const FcbCommand& fcb_command() const { return message_.fcb_command_; }

    static constexpr char const* PBB_COMMAND_NAME = "pbb_command";
    inline bool has_pbb_command() const
    {
      return FieldNumber::PBB_COMMAND == which_message_;
    }
    inline void clear_pbb_command()
    {
      if(FieldNumber::PBB_COMMAND == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.pbb_command_.~PbbCommand();
      }
    }
    inline void set_pbb_command(const PbbCommand& value)
    {
      if(FieldNumber::PBB_COMMAND != which_message_)
      {
        init_message(FieldNumber::PBB_COMMAND);
      }
      message_.pbb_command_ = value;
    }
    inline void set_pbb_command(const PbbCommand&& value)
    {
      if(FieldNumber::PBB_COMMAND != which_message_)
      {
        init_message(FieldNumber::PBB_COMMAND);
      }
      message_.pbb_command_ = value;
    }
    inline PbbCommand& mutable_pbb_command()
    {
      if(FieldNumber::PBB_COMMAND != which_message_)
      {
        init_message(FieldNumber::PBB_COMMAND);
      }
      return message_.pbb_command_;
    }
    inline const PbbCommand& get_pbb_command() const { return message_.pbb_command_; }
    inline const PbbCommand& pbb_command() const { return message_.pbb_command_; }

    static constexpr char const* FSB_COMMAND_NAME = "fsb_command";
    inline bool has_fsb_command() const
    {
      return FieldNumber::FSB_COMMAND == which_message_;
    }
    inline void clear_fsb_command()
    {
      if(FieldNumber::FSB_COMMAND == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.fsb_command_.~FsbCommand();
      }
    }
    inline void set_fsb_command(const FsbCommand& value)
    {
      if(FieldNumber::FSB_COMMAND != which_message_)
      {
        init_message(FieldNumber::FSB_COMMAND);
      }
      message_.fsb_command_ = value;
    }
    inline void set_fsb_command(const FsbCommand&& value)
    {
      if(FieldNumber::FSB_COMMAND != which_message_)
      {
        init_message(FieldNumber::FSB_COMMAND);
      }
      message_.fsb_command_ = value;
    }
    inline FsbCommand& mutable_fsb_command()
    {
      if(FieldNumber::FSB_COMMAND != which_message_)
      {
        init_message(FieldNumber::FSB_COMMAND);
      }
      return message_.fsb_command_;
    }
    inline const FsbCommand& get_fsb_command() const { return message_.fsb_command_; }
    inline const FsbCommand& fsb_command() const { return message_.fsb_command_; }

    static constexpr char const* LRB_COMMAND_NAME = "lrb_command";
    inline bool has_lrb_command() const
    {
      return FieldNumber::LRB_COMMAND == which_message_;
    }
    inline void clear_lrb_command()
    {
      if(FieldNumber::LRB_COMMAND == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.lrb_command_.~LrbCommand();
      }
    }
    inline void set_lrb_command(const LrbCommand& value)
    {
      if(FieldNumber::LRB_COMMAND != which_message_)
      {
        init_message(FieldNumber::LRB_COMMAND);
      }
      message_.lrb_command_ = value;
    }
    inline void set_lrb_command(const LrbCommand&& value)
    {
      if(FieldNumber::LRB_COMMAND != which_message_)
      {
        init_message(FieldNumber::LRB_COMMAND);
      }
      message_.lrb_command_ = value;
    }
    inline LrbCommand& mutable_lrb_command()
    {
      if(FieldNumber::LRB_COMMAND != which_message_)
      {
        init_message(FieldNumber::LRB_COMMAND);
      }
      return message_.lrb_command_;
    }
    inline const LrbCommand& get_lrb_command() const { return message_.lrb_command_; }
    inline const LrbCommand& lrb_command() const { return message_.lrb_command_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((static_cast<Node>(0) != source_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = source_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SOURCE), buffer, false);
      }

      if((static_cast<Node>(0) != target_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = target_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TARGET), buffer, false);
      }

      if((0U != source_sequence_num_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = source_sequence_num_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SOURCE_SEQUENCE_NUM), buffer, false);
      }

      switch(which_message_)
      {
        case FieldNumber::FCB_COMMAND:
          if(has_fcb_command() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.fcb_command_.serialize_with_id(static_cast<uint32_t>(FieldNumber::FCB_COMMAND), buffer, true);
          }
          break;

        case FieldNumber::PBB_COMMAND:
          if(has_pbb_command() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.pbb_command_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PBB_COMMAND), buffer, true);
          }
          break;

        case FieldNumber::FSB_COMMAND:
          if(has_fsb_command() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.fsb_command_.serialize_with_id(static_cast<uint32_t>(FieldNumber::FSB_COMMAND), buffer, true);
          }
          break;

        case FieldNumber::LRB_COMMAND:
          if(has_lrb_command() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.lrb_command_.serialize_with_id(static_cast<uint32_t>(FieldNumber::LRB_COMMAND), buffer, true);
          }
          break;

        default:
          break;
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::SOURCE:
            return_value = source_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::TARGET:
            return_value = target_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SOURCE_SEQUENCE_NUM:
            return_value = source_sequence_num_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::FCB_COMMAND:
          case FieldNumber::PBB_COMMAND:
          case FieldNumber::FSB_COMMAND:
          case FieldNumber::LRB_COMMAND:
            return_value = deserialize_message(id_tag, buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_source();
      clear_target();
      clear_source_sequence_num();
      clear_message();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::SOURCE:
          name = SOURCE_NAME;
          break;
        case FieldNumber::TARGET:
          name = TARGET_NAME;
          break;
        case FieldNumber::SOURCE_SEQUENCE_NUM:
          name = SOURCE_SEQUENCE_NUM_NAME;
          break;
        case FieldNumber::FCB_COMMAND:
          name = FCB_COMMAND_NAME;
          break;
        case FieldNumber::PBB_COMMAND:
          name = PBB_COMMAND_NAME;
          break;
        case FieldNumber::FSB_COMMAND:
          name = FSB_COMMAND_NAME;
          break;
        case FieldNumber::LRB_COMMAND:
          name = LRB_COMMAND_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = source_.to_string(left_chars, indent_level + 2, SOURCE_NAME, true);
      left_chars = target_.to_string(left_chars, indent_level + 2, TARGET_NAME, false);
      left_chars = source_sequence_num_.to_string(left_chars, indent_level + 2, SOURCE_SEQUENCE_NUM_NAME, false);
      left_chars = to_string_message(left_chars, indent_level + 2, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::enumeration<Node> source_ = static_cast<Node>(0);
      EmbeddedProto::enumeration<Node> target_ = static_cast<Node>(0);
      EmbeddedProto::uint32 source_sequence_num_ = 0U;

      FieldNumber which_message_ = FieldNumber::NOT_SET;
      union message
      {
        message() {}
        ~message() {}
        FcbCommand fcb_command_;
        PbbCommand pbb_command_;
        FsbCommand fsb_command_;
        LrbCommand lrb_command_;
      };
      message message_;

      void init_message(const FieldNumber field_id)
      {
        if(FieldNumber::NOT_SET != which_message_)
        {
          // First delete the old object in the oneof.
          clear_message();
        }

        // C++11 unions only support nontrivial members when you explicitly call the placement new statement.
        switch(field_id)
        {
          case FieldNumber::FCB_COMMAND:
            new(&message_.fcb_command_) FcbCommand;
            break;

          case FieldNumber::PBB_COMMAND:
            new(&message_.pbb_command_) PbbCommand;
            break;

          case FieldNumber::FSB_COMMAND:
            new(&message_.fsb_command_) FsbCommand;
            break;

          case FieldNumber::LRB_COMMAND:
            new(&message_.lrb_command_) LrbCommand;
            break;

          default:
            break;
         }

         which_message_ = field_id;
      }

      void clear_message()
      {
        switch(which_message_)
        {
          case FieldNumber::FCB_COMMAND:
            ::EmbeddedProto::destroy_at(&message_.fcb_command_);
            break;
          case FieldNumber::PBB_COMMAND:
            ::EmbeddedProto::destroy_at(&message_.pbb_command_);
            break;
          case FieldNumber::FSB_COMMAND:
            ::EmbeddedProto::destroy_at(&message_.fsb_command_);
            break;
          case FieldNumber::LRB_COMMAND:
            ::EmbeddedProto::destroy_at(&message_.lrb_command_);
            break;
          default:
            break;
        }
        which_message_ = FieldNumber::NOT_SET;
      }

      ::EmbeddedProto::Error deserialize_message(const FieldNumber field_id, 
                                    ::EmbeddedProto::ReadBufferInterface& buffer,
                                    const ::EmbeddedProto::WireFormatter::WireType wire_type)
      {
        ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
        
        if(field_id != which_message_)
        {
          init_message(field_id);
        }

        switch(which_message_)
        {
          case FieldNumber::FCB_COMMAND:
            return_value = message_.fcb_command_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::PBB_COMMAND:
            return_value = message_.pbb_command_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::FSB_COMMAND:
            return_value = message_.fsb_command_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::LRB_COMMAND:
            return_value = message_.lrb_command_.deserialize_check_type(buffer, wire_type);
            break;
          default:
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS != return_value)
        {
          clear_message();
        }
        return return_value;
      }

#ifdef MSG_TO_STRING 
      ::EmbeddedProto::string_view to_string_message(::EmbeddedProto::string_view& str, const uint32_t indent_level, const bool first_field) const
      {
        ::EmbeddedProto::string_view left_chars = str;

        switch(which_message_)
        {
          case FieldNumber::FCB_COMMAND:
            left_chars = message_.fcb_command_.to_string(left_chars, indent_level, FCB_COMMAND_NAME, first_field);
            break;
          case FieldNumber::PBB_COMMAND:
            left_chars = message_.pbb_command_.to_string(left_chars, indent_level, PBB_COMMAND_NAME, first_field);
            break;
          case FieldNumber::FSB_COMMAND:
            left_chars = message_.fsb_command_.to_string(left_chars, indent_level, FSB_COMMAND_NAME, first_field);
            break;
          case FieldNumber::LRB_COMMAND:
            left_chars = message_.lrb_command_.to_string(left_chars, indent_level, LRB_COMMAND_NAME, first_field);
            break;
          default:
            break;
        }

        return left_chars;
      }

#endif // End of MSG_TO_STRING
};

} // End of namespace Proto
#endif // COMMANDMESSAGE_H