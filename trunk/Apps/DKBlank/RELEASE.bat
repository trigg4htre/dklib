call ndk-build clean
call ndk-build
call ant clean
call ant release
cd bin
call adb install SDLActivity-release-unsigned.apk
echo off
pause