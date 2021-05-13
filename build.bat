@echo off

cd nas

echo assemble...

rem to draw dasm output
dasm bank0.nas -f3 -obank0.bin
rem to generate lst and err filrs
dasm bank0.nas -f3 -l!bank0.lst -obank0.bin >> !err.log

dasm hdr.nas -f3 -ohdr.bin > NUL
dasm chr.nas -f3 -ochr.bin > NUL

:build
echo build...

rename hdr.bin !backgmm.hdr > NUL
rename chr.bin !backgmm.chr > NUL
rename bank0.bin !backgmm.prg > NUL
nesimage j !backgmm > NUL

echo cleanup...
for %%f in (*.bin) do del %%f > NUL
del !backgmm.hdr > NUL
del !backgmm.chr > NUL
del !backgmm.prg > NUL

copy /b !backgmm.nes ..\!backgmm.nes > NUL

del !backgmm.nes > NUL

cd ..

echo done.
