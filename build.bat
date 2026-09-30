@echo off

gcc src/main.c src/food.c src/snake.c src/input.c src/render.c src/collision.c -Iinclude -o build/SnakeGame.exe

if %errorlevel% neq 0 (
    echo.
    echo Build failed!
    pause
    exit /b
)

echo.
echo Build successful!
echo.

build\SnakeGame.exe