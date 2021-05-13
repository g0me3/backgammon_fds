@echo off

start "" "D:\work\tools\TextPad\TextPad.exe" "F:\nes\fds\backgammon_fds\ram.inc" "F:\nes\fds\backgammon_fds\macroses.inc" "F:\nes\fds\backgammon_fds\BG-DEMO.inc" "F:\nes\fds\backgammon_fds\BG-FINAL.inc" "F:\nes\fds\backgammon_fds\BG-MAIN.inc" "F:\nes\fds\backgammon_fds\CP.inc" "F:\nes\fds\backgammon_fds\SOUND.inc" "F:\nes\fds\backgammon_fds\bank0.inc" "F:\nes\fds\backgammon_fds\bank1.inc" "F:\nes\fds\backgammon_fds\bank2.inc" "F:\nes\fds\backgammon_fds\bank3.inc"

pause 0

:again

call build.bat

pause 0

goto :again

:eof
