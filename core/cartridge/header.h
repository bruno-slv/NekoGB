#ifndef HEADER_H
#define HEADER_H

#include <neko_types.h>
#include <string>

#define TITLE_STRING_SIZE 17
#define MANUFACTURER_CODE_SIZE 5
#define NEW_LICENSEE_CODE_SIZE 3

#define POSSIBLE_CARTRIDGE_TYPES_QUANTITY 28

enum {
    ADDRESS_ENTRYPOINT = 0x0100,
    ADDRESS_NINTENDO_LOGO = 0x0104,
    ADDRESS_TITLE = 0x0134,
    ADDRESS_MANUFACTURER_CODE = 0x013F,
    ADDRESS_CGB_FLAG = 0x0143,
    ADDRESS_NEW_LICENSEE_CODE,
    ADDRESS_SGB_FLAG = 0x0146,
    ADDRESS_CARTRIDGE_TYPE,
    ADDRESS_ROM_SIZE,
    ADDRESS_RAM_SIZE,
    ADDRESS_DESTINATION_CODE,
    ADDRESS_OLD_LICENSEE_CODE,
    ADDRESS_MASK_ROM_VERSION_NUMBER,
    ADDRESS_HEADER_CHECKSUM,
    ADDRESS_GLOBAL_CHECKSUM,
};

enum
{
    CGB_SUPPORTS_CGB = 0x80,
    CGB_CGB_ONLY = 0xC0
};

#define CARTRIDGE_TYPES(X)                  \
    X(ROM_ONLY, 0x00)                       \
    X(MBC1, 0x01)                           \
    X(MBC1_RAM, 0x02)                       \
    X(MBC1_RAM_BATTERY, 0x03)               \
    X(MBC2, 0x05)                           \
    X(MBC2_BATTERY, 0x06)                   \
    X(ROM_RAM, 0x08)                        \
    X(ROM_RAM_BATTERY, 0x09)                \
    X(MMM01, 0x0B)                          \
    X(MMM01_RAM, 0x0C)                      \
    X(MMM01_RAM_BATTERY, 0x0D)              \
    X(MBC3_TIMER_BATTERY, 0x0F)             \
    X(MBC3_TIMER_RAM_BATTERY, 0x10)         \
    X(MBC3, 0x11)                           \
    X(MBC3_RAM, 0x12)                       \
    X(MBC3_RAM_BATTERY, 0x13)               \
    X(MBC5, 0x19)                           \
    X(MBC5_RAM, 0x1A)                       \
    X(MBC5_RAM_BATTERY, 0x1B)               \
    X(MBC5_RUMBLE, 0x1C)                    \
    X(MBC5_RUMBLE_RAM, 0x1D)                \
    X(MBC5_RUMBLE_RAM_BATTERY, 0x1E)        \
    X(MBC6, 0x20)                           \
    X(MBC7_SENSOR_RUMBLE_RAM_BATTERY, 0x22) \
    X(POCKET_CAMERA, 0xFC)                  \
    X(BANDAI_TAMA5, 0xFD)                   \
    X(HuC3, 0xFE)                           \
    X(HuC1_RAM_BATTERY, 0xFF)

typedef enum
{
#define X(type, value) type = value,
    CARTRIDGE_TYPES(X)
#undef X
} cartridge_type_t;

typedef struct
{
    std::string title;
    std::string manufacturer_code;
    u8 cgb_flag;
    std::string new_licensee_code;
    u8 sgb_flag;
    cartridge_type_t cartridge_type;
    u8 rom_size;
    u8 ram_size;
    u8 destination_code;
    u8 old_licensee_code;
    u8 mask_rom_version_number;
} header_info_t;

/**
 * @brief load header info into structure
 * @param rom pointer to rom byte array
 * @param header_info_t pointer to current structure
 * @return void
 */
void load_header_info(const u8 *rom, header_info_t *info);

/**
 * @brief calculates header checksum and validates it
 * @param rom pointer to rom byte array
 * @return true if calculated checksum is valid
 */
bool is_header_checksum_valid(const u8 *rom);

#endif // HEADER_H
