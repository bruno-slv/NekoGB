#include <header.h>

void load_header_info(const u8 *rom, header_info_t *info)
{
    info->title = std::string(
        reinterpret_cast<const char *>(&rom[ADDRESS_TITLE]),
        TITLE_STRING_SIZE);

    info->manufacturer_code = std::string(
        reinterpret_cast<const char *>(&rom[ADDRESS_MANUFACTURER_CODE]),
        MANUFACTURER_CODE_SIZE);

    info->new_licensee_code = std::string(
        reinterpret_cast<const char *>(&rom[ADDRESS_NEW_LICENSEE_CODE]),
        NEW_LICENSEE_CODE_SIZE);

    info->cgb_flag = rom[ADDRESS_CGB_FLAG];
    info->sgb_flag = rom[ADDRESS_SGB_FLAG];
    info->cartridge_type = (cartridge_type_t)rom[ADDRESS_CARTRIDGE_TYPE];
    info->rom_size = rom[ADDRESS_ROM_SIZE];
    info->ram_size = rom[ADDRESS_RAM_SIZE];
    info->destination_code = rom[ADDRESS_DESTINATION_CODE];
    info->old_licensee_code = rom[ADDRESS_OLD_LICENSEE_CODE];
    info->mask_rom_version_number = rom[ADDRESS_MASK_ROM_VERSION_NUMBER];
}

bool is_header_checksum_valid(const u8 *rom)
{
    u8 _checksum = 0;

    for (u16 address = ADDRESS_TITLE; address <= ADDRESS_MASK_ROM_VERSION_NUMBER; address++)
    {
        _checksum = _checksum - rom[address] - 1;
    }

    return _checksum == rom[ADDRESS_HEADER_CHECKSUM];
}
