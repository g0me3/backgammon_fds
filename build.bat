@echo off

cd nas

echo assemble...

dasm BG-MAIN.nas -f3 -l!BG-MAIN.lst -oBG-MAIN.bin >> !err.log

for %%f in (*.nas) do call :dodasm %%f > NUL

goto :build

:dodasm
dasm %1 -f3 -o%~n1.bin
goto :eof

dasm hdr.nas -f3 -o!game.hdr > NUL
dasm chr.nas -f3 -o!game.chr > NUL

:build
echo build...

rem nesimage j !game > NUL

echo cleanup...
rem rem for %%f in (*.bin) do del %%f

rem copy /b !game.nes ..\!game.nes > NUL
cd ..

echo done.
