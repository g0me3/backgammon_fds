@echo off

start "" "D:\work\tools\TextPad\TextPad.exe" ram.inc macroses.inc BG-DEMO.inc BG-FINAL.inc BG-MAIN.inc CP.inc SOUND.inc

pause 0

:again

call build.bat

pause 0

goto :again

:eof
