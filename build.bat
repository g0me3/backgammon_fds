@echo off

cd nas

echo assemble...

rem to generate lst and err filrs
dasm bank0.nas -f3 -l!bank0.lst -obank0.bin >> !err.log
rem to draw dasm output
dasm bank1.nas -f3 -obank1.bin

dasm bank2.nas -f3 -obank2.bin > NUL
dasm bank3.nas -f3 -obank3.bin > NUL

dasm hdr.nas -f3 -ohdr.bin > NUL

:build
echo build...

rename hdr.bin !backgmm.hdr > NUL
copy /b bank0.bin+bank1.bin+bank2.bin+bank3.bin !backgmm.prg > NUL
nesimage j !backgmm > NUL

echo cleanup...
for %%f in (*.bin) do del %%f > NUL
del !backgmm.hdr > NUL
del !backgmm.prg > NUL

copy /b !backgmm.nes ..\!backgmm.nes > NUL

del !backgmm.nes > NUL

cd ..

echo done.
