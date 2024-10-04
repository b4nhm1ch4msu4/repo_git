Remove-Item ./build/* -Recurse -Force -Confirm:$false
cd build
cmake -G "MinGW Makefiles" ..
make
call .\bin\tetris.exe

