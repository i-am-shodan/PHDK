cd ..\..\
set PATH=%PATH%;%CD%\gcc-arm-none-eabi\bin
set FIRMWARE_DIR=.\firmware\K30\1.5\
set FIRMWARE_BIN=%FIRMWARE_DIR%decrypted.bin
set FILENAME=dump
set SOURCE=FWPatches\memdump\%FILENAME%.c
set TEMP=.\temp\
set PATCHPOINT=1331012
set OUTNAME=fwdc215b.bin
set OUTDIR=release\memdump

rmdir /S /Q %TEMP%
md %TEMP%

REM copy original firmware to temp dir
copy %FIRMWARE_BIN% %TEMP%out_fw_decrypt.bin

arm-none-eabi-gcc -mbig-endian -mtune=cortex-m4 -c %SOURCE% -I. -I%FIRMWARE_DIR%
move %FILENAME%.o %TEMP%

cd %TEMP%
arm-none-eabi-ld -EB %FILENAME%.o -nostdlib -T ..\ldScript.txt

arm-none-eabi-objcopy -j .text -O binary -I elf32-big patch.elf firmware-text.text
arm-none-eabi-objcopy -j .rodata -O binary -I elf32-big patch.elf firmware-rodata.text
copy /b firmware-text.text+firmware-rodata.text out.bin

..\tools\MergeBin out.bin out_fw_decrypt.bin %PATCHPOINT%
cd ..\tools
FirmwareTools.exe -in=..\%TEMP%out_fw_decrypt.bin -out=..\%TEMP%out_fw_decrypt_fixed.bin -f
FirmwareTools.exe -in=..\%TEMP%out_fw_decrypt_fixed.bin -out=..\%TEMP%out_fw_decrypt_fixed_encrypted.bin -e

cd ..

rmdir /S /Q %OUTDIR%
md %OUTDIR%
move %TEMP%out_fw_decrypt_fixed_encrypted.bin %OUTDIR%\%OUTNAME%

pause