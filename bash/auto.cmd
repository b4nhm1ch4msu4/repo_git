@echo off

:LOOP
echo [%time%] Iteration %counter% - Starting...
echo.

adb wait-for-device
echo "Start first"
call "script1.bat"
echo "Done First"
echo.

echo "Start second"
call "script2.bat"
echo "Done Second"
echo.

echo [%time%] Iteration %counter% completed.
echo "DONE DONE DONE"

goto LOOP
