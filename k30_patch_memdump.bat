set PATH=%PATH%;.\gcc-arm-none-eabi-4_8-2014q1-20140314-win32\bin

del patch.elf
del firmware-text.text
del firmware-rodata.text
del out.bin
del out_fw_decrypt.bin
del out_fw_decrypt_fixed.bin
del out_fw_decrypt_fixed_encrypted.bin

arm-none-eabi-gcc -mbig-endian -mtune=cortex-m4 -c Program.c
arm-none-eabi-ld -EB --just-symbols=symbols.txt Program.o -nostdlib -T ldScript.txt
del program.o
arm-none-eabi-objcopy -j .text -O binary -I elf32-big patch.elf firmware-text.text
arm-none-eabi-objcopy -j .rodata -O binary -I elf32-big patch.elf firmware-rodata.text
del patch.elf

copy /b firmware-text.text+firmware-rodata.text out.bin
del firmware-text.text
del firmware-rodata.text

copy original_fw_decrypted.bin out_fw_decrypt.bin
MergeBin out.bin out_fw_decrypt.bin 1331012
del out.bin
FirmwareTools.exe -in=out_fw_decrypt.bin -out=out_fw_decrypt_fixed.bin -f
FirmwareTools.exe -in=out_fw_decrypt_fixed.bin -out=out_fw_decrypt_fixed_encrypted.bin -e

copy out_fw_decrypt_fixed_encrypted.bin fwdc215b.bin
del out_fw_decrypt.bin
del out_fw_decrypt_fixed.bin
del out_fw_decrypt_fixed_encrypted.bin