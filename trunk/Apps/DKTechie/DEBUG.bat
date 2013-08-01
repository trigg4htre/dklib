call ndk-build clean
call ndk-build
call ant clean
call ant debug
cd bin
call adb install SDLActivity-debug.apk
echo off
pause