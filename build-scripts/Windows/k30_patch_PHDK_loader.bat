cd ..\..\
set PATH=%PATH%;%CD%\gcc-arm-none-eabi\bin
set FIRMWARE_DIR=.\firmware\K30\1.5\
set FIRMWARE_BIN=%FIRMWARE_DIR%decrypted.bin
set FILENAME=progloader
set SOURCE_DIR=FWPatches\progloader\
set SOURCE=%SOURCE_DIR%%FILENAME%.c
set TEMP=.\temp\
set PATCHPOINT=10670704
set OUTNAME=fwdc215b.bin
set OUTDIR=release\loader

rmdir /S /Q %TEMP%
md %TEMP%

REM copy original firmware to temp dir
copy %FIRMWARE_BIN% %TEMP%out_fw_decrypt.bin

arm-none-eabi-gcc -Os -mbig-endian -mtune=cortex-m4 -c %SOURCE% -I. -I%FIRMWARE_DIR%
move %FILENAME%.o %TEMP%

cd %TEMP%
arm-none-eabi-ld -EB %FILENAME%.o -nostdlib -T ..\ldScript.txt
arm-none-eabi-objcopy -I elf32-big -O binary --strip-all patch.elf out.bin
REM arm-none-eabi-objcopy -j .text -O binary -I elf32-big patch.elf firmware-text.text
REM arm-none-eabi-objcopy -j .rodata -O binary -I elf32-big patch.elf firmware-rodata.text
REM copy /b firmware-text.text+firmware-rodata.text out.bin

..\tools\MergeBin out.bin out_fw_decrypt.bin %PATCHPOINT%
..\tools\MergeBin ..\%SOURCE_DIR%patch_0xA0678860 out_fw_decrypt.bin 6785120
cd ..\tools
FirmwareTools.exe -in=..\%TEMP%out_fw_decrypt.bin -out=..\%TEMP%out_fw_decrypt_fixed.bin -f
FirmwareTools.exe -in=..\%TEMP%out_fw_decrypt_fixed.bin -out=..\%TEMP%out_fw_decrypt_fixed_encrypted.bin -e

cd ..

rmdir /S /Q %OUTDIR%
md %OUTDIR%
move %TEMP%out_fw_decrypt_fixed_encrypted.bin %OUTDIR%\%OUTNAME%

pause