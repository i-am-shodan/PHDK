cd ..\..\
set FIRMWARE_DIR=.\firmware\K30\1.5\
set PATH=%PATH%;%CD%\gcc-arm-none-eabi\bin
set FILENAME=entry
set SOURCE_DIR=PHDK\core\
set SOURCE=%SOURCE_DIR%%FILENAME%.c
set TEMP=.\temp\
set OUTNAME=phdk.bin
set OUTDIR=release\PHDK

rmdir /S /Q %TEMP%
md %TEMP%

arm-none-eabi-gcc -Os -mbig-endian -mtune=cortex-m4 -c %SOURCE% -I. -I%FIRMWARE_DIR%
move *.o %TEMP%

cd %TEMP%
arm-none-eabi-ld -EB %FILENAME%.o -nostdlib -T ..\phdk_ldScript.txt
arm-none-eabi-objcopy -I elf32-big -O binary --strip-all patch.elf phdk.bin

cd ..

rmdir /S /Q %OUTDIR%
md %OUTDIR%
move %TEMP%phdk.bin %OUTDIR%\%OUTNAME%

pause