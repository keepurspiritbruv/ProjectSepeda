@echo off
g++ main.cpp implementation\*.cpp -o sepeda_app.exe
if %errorlevel%==0 (
    echo.
    echo ======== Compile berhasil ========
    echo Jalankan aplikasi: sepeda_app.exe
) else (
    echo.
    echo ======== Compile gagal ========
)
pause
