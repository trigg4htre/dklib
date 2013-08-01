###############################################
####          DK All Libraries             ####
###############################################

###### Supported Platform / Compilers  ######
#
# Visual Studio 8 2005
# Visual Studio 9 2008
# Visual Studio 10 2010
# Mac Intel / XCode 3.1+

IF(APPLE)
	MESSAGE(STATUS "Detected MAC environment")
	option(MAC "Build MAC project files" OFF)
	option(IOS "Build IOS project files" OFF)
	IF(NOT MAC)
	IF(NOT IOS)
		message("Please select MAC or IOS")
	ENDIF()
	ENDIF()
ENDIF(APPLE)

cmake_minimum_required(VERSION 2.6)

if(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

SET(CMAKE_CONFIGURATION_TYPES Debug Release CACHE TYPE INTERNAL FORCE )

PROJECT(DKLIBS)

##----------------------------------------
##       ###### WINDOWS ######
##----------------------------------------
IF(WIN32)
	MESSAGE(STATUS "Detected WINDOWS environment")
	MESSAGE(STATUS "Creating Windows Project Files")
	
	SET(EXECUTABLE_OUTPUT_PATH ${DKLIBS_SOURCE_DIR}/bin/WIN32)
	SET(LIBRARY_OUTPUT_PATH ${DKLIBS_SOURCE_DIR}/bin/WIN32)

	##------------------------------------------
	## digitalknob
	##------------------------------------------
	SET(DIGITALKNOB_SRC
	digitalknob/arial.h
	digitalknob/StackWalker.h
	digitalknob/StackWalker.cpp
	digitalknob/LeakFinder.h
	digitalknob/LeakFinder.cpp
	digitalknob/DK.h
	digitalknob/DKDebug.h
	digitalknob/DKDebug.cpp
	digitalknob/DKFile.h
	digitalknob/DKFile.cpp
	digitalknob/DKObject.h
	digitalknob/DKObject.cpp
	digitalknob/DKObjectManager.h
	digitalknob/DKObjectManager.cpp
	digitalknob/DKEvent.h
	digitalknob/DKEvent.cpp
	digitalknob/DKFrame.h
	digitalknob/DKFrame.cpp
	digitalknob/DKWindow.h
	digitalknob/DKWindow.cpp
	digitalknob/DKPanel.h
	digitalknob/DKPanel.cpp
	digitalknob/DKAudio.h
	digitalknob/DKAudio.cpp
	digitalknob/DKFont.h
	digitalknob/DKFont.cpp
	digitalknob/DKTexture.h
	digitalknob/DKTexture.cpp
	digitalknob/DKText.h
	digitalknob/DKText.cpp
	digitalknob/DKImage.h
	digitalknob/DKImage.cpp
	digitalknob/DKSquare.h
	digitalknob/DKSquare.cpp
	digitalknob/DKTriangle.h
	digitalknob/DKTriangle.cpp
	digitalknob/DKCircle.h
	digitalknob/DKCircle.cpp
	digitalknob/DKLine.h
	digitalknob/DKLine.cpp
	digitalknob/DKXyz.h
	digitalknob/DKXyz.cpp
	digitalknob/DKCube.h
	digitalknob/DKCube.cpp
	digitalknob/DKButton.h
	digitalknob/DKButton.cpp
	digitalknob/DKTextBox.h
	digitalknob/DKTextBox.cpp
	digitalknob/DKTextButton.h
	digitalknob/DKTextButton.cpp
	digitalknob/DKToggle.h
	digitalknob/DKToggle.cpp
	digitalknob/DKListBox.h
	digitalknob/DKListBox.cpp
	digitalknob/DKSlider.h
	digitalknob/DKSlider.cpp
	digitalknob/DKFps.h
	digitalknob/DKFps.cpp
	digitalknob/DKAnimate.h
	digitalknob/DKAnimate.cpp
	digitalknob/DKCamera.h
	digitalknob/DKCamera.cpp
	digitalknob/DKMessage.h
	digitalknob/DKMessage.cpp
	digitalknob/DKFileDialog.h
	digitalknob/DKFileDialog.cpp
	digitalknob/DK3ds.h
	digitalknob/DK3ds.cpp
	digitalknob/DKString.h
	digitalknob/DKString.cpp
	digitalknob/DKZip.h
	digitalknob/DKZip.cpp
	digitalknob/DKOsInfo.h
	digitalknob/DKOsInfo.cpp
	digitalknob/DKMenuBar.h
	digitalknob/DKMenuBar.cpp
	digitalknob/DKDropDown.h
	digitalknob/DKDropDown.cpp
	digitalknob/DKColorPicker.h
	digitalknob/DKColorPicker.cpp
	digitalknob/DKColor.h
	digitalknob/DKColor.cpp
	digitalknob/DKAxis.h
	digitalknob/DKAxis.cpp
	digitalknob/DKTextEdit.h
	digitalknob/DKTextEdit.cpp
	digitalknob/DKKeyboard.h
	digitalknob/DKKeyboard.cpp
	digitalknob/DKFrameBase.h
	digitalknob/DKFrameBase.cpp
	digitalknob/DKOpengl.h
	digitalknob/DKScrollBar.h
	digitalknob/DKScrollBar.cpp
	digitalknob/DKGlobal.h
	digitalknob/DKGlobal.cpp
	digitalknob/DKScrollPanel.h
	digitalknob/DKScrollPanel.cpp
	)

	##------------------------------------------------
	##  sdl
	##------------------------------------------------
	SET(SDL_SRC
	sdl/include/SDL.h
	sdl/include/SDL_assert.h
	sdl/include/SDL_atomic.h
	sdl/include/SDL_audio.h
	sdl/include/SDL_bits.h
	sdl/include/SDL_blendmode.h
	sdl/include/SDL_clipboard.h
	sdl/include/SDL_config.h
	sdl/include/SDL_config_windows.h
	sdl/include/SDL_copying.h
	sdl/include/SDL_cpuinfo.h
	sdl/include/SDL_endian.h
	sdl/include/SDL_error.h
	sdl/include/SDL_events.h
	sdl/include/SDL_gamecontroller.h
	sdl/include/SDL_gesture.h
	sdl/include/SDL_haptic.h
	sdl/include/SDL_hints.h
	sdl/include/SDL_joystick.h
	sdl/include/SDL_keyboard.h
	sdl/include/SDL_keycode.h
	sdl/include/SDL_loadso.h
	sdl/include/SDL_log.h
	sdl/include/SDL_main.h
	sdl/include/SDL_messagebox.h
	sdl/include/SDL_mouse.h
	sdl/include/SDL_mutex.h
	sdl/include/SDL_name.h
	sdl/include/SDL_opengl.h
	sdl/include/SDL_opengles.h
	sdl/include/SDL_pixels.h
	sdl/include/SDL_platform.h
	sdl/include/SDL_power.h
	sdl/include/SDL_quit.h
	sdl/include/SDL_rect.h
	sdl/include/SDL_render.h
	sdl/include/SDL_revision.h
	sdl/include/SDL_rwops.h
	sdl/include/SDL_scancode.h
	sdl/include/SDL_shape.h
	sdl/include/SDL_stdinc.h
	sdl/include/SDL_surface.h
	sdl/include/SDL_system.h
	sdl/include/SDL_syswm.h
	sdl/include/SDL_thread.h
	sdl/include/SDL_timer.h
	sdl/include/SDL_touch.h
	sdl/include/SDL_types.h
	sdl/include/SDL_version.h
	sdl/include/SDL_video.h
	sdl/src/events/blank_cursor.h
	sdl/src/events/default_cursor.h
	sdl/src/audio/directsound/directx.h
	sdl/src/libm/e_atan2.c
	sdl/src/libm/e_log.c
	sdl/src/libm/e_pow.c
	sdl/src/libm/e_rem_pio2.c
	sdl/src/libm/e_sqrt.c
	sdl/src/libm/k_cos.c
	sdl/src/libm/k_rem_pio2.c
	sdl/src/libm/k_sin.c
	#sdl/src/libm/math.h
	sdl/src/libm/math_private.h
	sdl/src/render/mmx.h
	#sdl/VisualC/SDL/resource.h
	sdl/src/libm/s_atan.c
	sdl/src/libm/s_copysign.c
	sdl/src/libm/s_cos.c
	sdl/src/libm/s_fabs.c
	sdl/src/libm/s_floor.c
	sdl/src/libm/s_scalbn.c
	sdl/src/libm/s_sin.c
	sdl/src/SDL.c
	sdl/src/SDL_assert.c
	sdl/src/atomic/SDL_atomic.c
	sdl/src/audio/SDL_audio.c
	sdl/src/audio/SDL_audio_c.h
	sdl/src/audio/SDL_audiocvt.c
	sdl/src/audio/SDL_audiodev.c
	sdl/src/audio/SDL_audiodev_c.h
	sdl/src/audio/SDL_audiomem.h
	sdl/src/audio/SDL_audiotypecvt.c
	sdl/src/render/software/SDL_blendfillrect.c
	sdl/src/render/software/SDL_blendfillrect.h
	sdl/src/render/software/SDL_blendline.c
	sdl/src/render/software/SDL_blendline.h
	sdl/src/render/software/SDL_blendpoint.c
	sdl/src/render/software/SDL_blendpoint.h
	sdl/src/video/SDL_blit.c
	sdl/src/video/SDL_blit.h
	sdl/src/video/SDL_blit_0.c
	sdl/src/video/SDL_blit_1.c
	sdl/src/video/SDL_blit_A.c
	sdl/src/video/SDL_blit_auto.c
	sdl/src/video/SDL_blit_auto.h
	sdl/src/video/SDL_blit_copy.c
	sdl/src/video/SDL_blit_copy.h
	sdl/src/video/SDL_blit_N.c
	sdl/src/video/SDL_blit_slow.c
	sdl/src/video/SDL_blit_slow.h
	sdl/src/video/SDL_bmp.c
	sdl/src/video/SDL_clipboard.c
	sdl/src/events/SDL_clipboardevents.c
	sdl/src/events/SDL_clipboardevents_c.h
	sdl/src/cpuinfo/SDL_cpuinfo.c
	sdl/src/audio/directsound/SDL_directsound.c
	sdl/src/audio/directsound/SDL_directsound.h
	sdl/src/audio/disk/SDL_diskaudio.c
	sdl/src/audio/disk/SDL_diskaudio.h
	sdl/src/render/software/SDL_draw.h
	sdl/src/render/software/SDL_drawline.c
	sdl/src/render/software/SDL_drawline.h
	sdl/src/render/software/SDL_drawpoint.c
	sdl/src/render/software/SDL_drawpoint.h
	sdl/src/events/SDL_dropevents.c
	sdl/src/events/SDL_dropevents_c.h
	sdl/src/audio/dummy/SDL_dummyaudio.c
	sdl/src/audio/dummy/SDL_dummyaudio.h
	sdl/src/joystick/windows/SDL_dxjoystick.c
	sdl/src/SDL_error.c
	sdl/src/SDL_error_c.h
	sdl/src/events/SDL_events.c
	sdl/src/events/SDL_events_c.h
	sdl/src/SDL_fatal.c
	sdl/src/SDL_fatal.h
	sdl/src/video/SDL_fillrect.c
	sdl/src/joystick/SDL_gamecontroller.c
	sdl/src/events/SDL_gesture.c
	sdl/src/events/SDL_gesture_c.h
	sdl/src/stdlib/SDL_getenv.c
	#sdl/src/video/SDL_glesfuncs.h
	#sdl/src/video/SDL_glfuncs.h
	sdl/src/haptic/SDL_haptic.c
	sdl/src/SDL_hints.c
	#sdl/src/SDL_hints_c.h
	sdl/src/stdlib/SDL_iconv.c
	sdl/src/joystick/SDL_joystick.c
	sdl/src/joystick/SDL_joystick_c.h
	sdl/src/events/SDL_keyboard.c
	sdl/src/events/SDL_keyboard_c.h
	sdl/src/SDL_log.c
	sdl/src/stdlib/SDL_malloc.c
	sdl/src/audio/SDL_mixer.c
	sdl/src/joystick/windows/SDL_mmjoystick.c
	sdl/src/events/SDL_mouse.c
	sdl/src/events/SDL_mouse_c.h
	sdl/src/video/dummy/SDL_nullevents.c
	sdl/src/video/dummy/SDL_nullevents_c.h
	sdl/src/video/dummy/SDL_nullframebuffer.c
	sdl/src/video/dummy/SDL_nullframebuffer_c.h
	sdl/src/video/dummy/SDL_nullvideo.c
	sdl/src/video/dummy/SDL_nullvideo.h
	sdl/src/video/SDL_pixels.c
	sdl/src/video/SDL_pixels_c.h
	sdl/src/power/SDL_power.c
	sdl/src/stdlib/SDL_qsort.c
	sdl/src/events/SDL_quit.c
	sdl/src/video/SDL_rect.c
	sdl/src/video/SDL_rect_c.h
	sdl/src/render/SDL_render.c
	sdl/src/render/direct3d/SDL_render_d3d.c
	sdl/src/render/opengl/SDL_render_gl.c
	sdl/src/render/software/SDL_render_sw.c
	sdl/src/render/software/SDL_render_sw_c.h
	sdl/src/video/SDL_RLEaccel.c
	sdl/src/video/SDL_RLEaccel_c.h
	sdl/src/render/software/SDL_rotate.c
	sdl/src/render/software/SDL_rotate.h
	sdl/src/file/SDL_rwops.c
	sdl/src/render/opengl/SDL_shaders_gl.c
	sdl/src/render/opengl/SDL_shaders_gl.h
	sdl/src/video/SDL_shape.c
	sdl/src/video/SDL_shape_internals.h
	sdl/src/atomic/SDL_spinlock.c
	sdl/src/stdlib/SDL_stdlib.c
	sdl/src/video/SDL_stretch.c
	sdl/src/stdlib/SDL_string.c
	sdl/src/video/SDL_surface.c
	sdl/src/audio/SDL_sysaudio.h
	sdl/src/thread/generic/SDL_syscond.c
	sdl/src/events/SDL_sysevents.h
	sdl/src/haptic/windows/SDL_syshaptic.c
	sdl/src/haptic/SDL_syshaptic.h
	sdl/src/joystick/SDL_sysjoystick.h
	sdl/src/loadso/windows/SDL_sysloadso.c
	sdl/src/thread/windows/SDL_sysmutex.c
	sdl/src/power/windows/SDL_syspower.c
	sdl/src/render/SDL_sysrender.h
	sdl/src/thread/windows/SDL_syssem.c
	sdl/src/thread/windows/SDL_systhread.c
	sdl/src/thread/SDL_systhread.h
	sdl/src/thread/windows/SDL_systhread_c.h
    sdl/src/timer/windows/SDL_systimer.c
	#sdl/src/timer/SDL_systimer.h
	sdl/src/thread/windows/SDL_systls.c
	sdl/src/video/SDL_sysvideo.h
	sdl/src/thread/SDL_thread.c
	sdl/src/thread/SDL_thread_c.h
	sdl/src/timer/SDL_timer.c
	sdl/src/timer/SDL_timer_c.h
	sdl/src/events/SDL_touch.c
	sdl/src/events/SDL_touch_c.h
	sdl/src/video/SDL_video.c
	sdl/src/video/windows/SDL_vkeys.h
	sdl/src/audio/SDL_wave.c
	sdl/src/audio/SDL_wave.h
	sdl/src/events/SDL_windowevents.c
	sdl/src/events/SDL_windowevents_c.h
	sdl/src/core/windows/SDL_windows.c
	sdl/src/core/windows/SDL_windows.h
	sdl/src/video/windows/SDL_windowsclipboard.c
	sdl/src/video/windows/SDL_windowsclipboard.h
	sdl/src/video/windows/SDL_windowsevents.c
	sdl/src/video/windows/SDL_windowsevents.h
	sdl/src/video/windows/SDL_windowsframebuffer.c
	sdl/src/video/windows/SDL_windowsframebuffer.h
	sdl/src/video/windows/SDL_windowskeyboard.c
	sdl/src/video/windows/SDL_windowskeyboard.h
	sdl/src/video/windows/SDL_windowsmessagebox.c
	sdl/src/video/windows/SDL_windowsmessagebox.h
	sdl/src/video/windows/SDL_windowsmodes.c
	sdl/src/video/windows/SDL_windowsmodes.h
	sdl/src/video/windows/SDL_windowsmouse.c
	sdl/src/video/windows/SDL_windowsmouse.h
	sdl/src/video/windows/SDL_windowsopengl.c
	sdl/src/video/windows/SDL_windowsopengl.h
	sdl/src/video/windows/SDL_windowsshape.c
	sdl/src/video/windows/SDL_windowsshape.h
	sdl/src/video/windows/SDL_windowsvideo.c
	sdl/src/video/windows/SDL_windowsvideo.h
	sdl/src/video/windows/SDL_windowswindow.c
	sdl/src/video/windows/SDL_windowswindow.h
	sdl/src/audio/winmm/SDL_winmm.c
	sdl/src/audio/winmm/SDL_winmm.h
	sdl/src/audio/xaudio2/SDL_xaudio2.c
	sdl/src/render/SDL_yuv_mmx.c
	sdl/src/render/SDL_yuv_sw.c
	sdl/src/render/SDL_yuv_sw_c.h
	sdl/src/main/windows/version.rc
	sdl/src/video/windows/wmmsg.h
	sdl/src/main/windows/SDL_windows_main.c
	)

	##------------------------------------------------
	## sdl_image
	##------------------------------------------------
	SET(SDLIMAGE_SRC
	sdl_image/SDL_image.h
	sdl_image/IMG.c
	sdl_image/IMG_bmp.c
	sdl_image/IMG_gif.c
	sdl_image/IMG_jpg.c
	sdl_image/IMG_lbm.c
	sdl_image/IMG_pcx.c
	sdl_image/IMG_png.c
	sdl_image/IMG_pnm.c
	sdl_image/IMG_tga.c
	sdl_image/IMG_tif.c
	sdl_image/IMG_webp.c
	sdl_image/IMG_xcf.c
	sdl_image/IMG_xpm.c
	sdl_image/IMG_xv.c
	sdl_image/IMG_xxx.c
	sdl_image/VisualC/Version.rc
	)
	
	##---------------------------------------------
	## png
	##---------------------------------------------
	SET(PNG_SRC
	sdl_image/external/libpng-1.6.2/png.h
	sdl_image/external/libpng-1.6.2/pngconf.h
	sdl_image/external/libpng-1.6.2/pngpriv.h
	sdl_image/external/libpng-1.6.2/png.c
	sdl_image/external/libpng-1.6.2/pngerror.c
	sdl_image/external/libpng-1.6.2/pngget.c
	sdl_image/external/libpng-1.6.2/pngmem.c
	sdl_image/external/libpng-1.6.2/pngpread.c
	sdl_image/external/libpng-1.6.2/pngread.c
	sdl_image/external/libpng-1.6.2/pngrio.c
	sdl_image/external/libpng-1.6.2/pngrtran.c
	sdl_image/external/libpng-1.6.2/pngrutil.c
	sdl_image/external/libpng-1.6.2/pngset.c
	sdl_image/external/libpng-1.6.2/pngtrans.c
	sdl_image/external/libpng-1.6.2/pngwio.c
	sdl_image/external/libpng-1.6.2/pngwrite.c
	sdl_image/external/libpng-1.6.2/pngwtran.c
	sdl_image/external/libpng-1.6.2/pngwutil.c
	)

	##------------------------------------------------
	## sdl_mixer
	##------------------------------------------------
	SET(SDLMIXER_SRC
	sdl_mixer/dynamic_flac.c
	sdl_mixer/dynamic_flac.h
	sdl_mixer/dynamic_fluidsynth.c
	sdl_mixer/dynamic_fluidsynth.h
	sdl_mixer/dynamic_mod.c
	sdl_mixer/dynamic_mod.h
	sdl_mixer/dynamic_mp3.c
	sdl_mixer/dynamic_mp3.h
	sdl_mixer/dynamic_ogg.c
	sdl_mixer/dynamic_ogg.h
	sdl_mixer/effect_position.c
	sdl_mixer/effect_stereoreverse.c
	sdl_mixer/effects_internal.c
	sdl_mixer/effects_internal.h
	sdl_mixer/fluidsynth.c
	sdl_mixer/fluidsynth.h
	sdl_mixer/load_aiff.c
	sdl_mixer/load_aiff.h
	sdl_mixer/load_flac.c
	sdl_mixer/load_flac.h
	sdl_mixer/load_ogg.c
	sdl_mixer/load_ogg.h
	sdl_mixer/load_voc.c
	sdl_mixer/load_voc.h
	sdl_mixer/mixer.c
	sdl_mixer/music.c
	sdl_mixer/music_cmd.c
	sdl_mixer/music_cmd.h
	sdl_mixer/music_flac.c
	sdl_mixer/music_flac.h
	sdl_mixer/music_mad.c
	sdl_mixer/music_mad.h
	sdl_mixer/music_mod.c
	sdl_mixer/music_mod.h
	sdl_mixer/music_ogg.c
	sdl_mixer/music_ogg.h
	sdl_mixer/SDL_mixer.h
	sdl_mixer/wavestream.c
	sdl_mixer/wavestream.h
	)

	##-----------------------------------------------
	## zlib
	##-----------------------------------------------
	SET(ZLIB_SRC
	zlib/zlib.h
	zlib/crc32.h
	zlib/deflate.h
	zlib/gzguts.h
	zlib/inffast.h
	zlib/inffixed.h
	zlib/inflate.h
	zlib/inftrees.h
	zlib/trees.h
	zlib/zconf.h
	zlib/zutil.h
	zlib/adler32.c
	zlib/compress.c
	zlib/crc32.c
	zlib/deflate.c
	zlib/gzclose.c
	zlib/gzlib.c
	zlib/gzread.c
	zlib/gzwrite.c
	zlib/infback.c
	zlib/inffast.c
	zlib/inflate.c
	zlib/inftrees.c
	zlib/trees.c
	zlib/uncompr.c
	zlib/zutil.c
	)

	##------------------------------------------
	## freetype
	##------------------------------------------
	SET(FREETYPE_SRC
	freetype/src/base/ftsystem.c
	freetype/src/base/ftinit.c
	freetype/src/base/ftdebug.c
	freetype/src/base/ftbase.c
	freetype/src/base/ftbbox.c
	freetype/src/base/ftglyph.c
	freetype/src/truetype/truetype.c
	freetype/src/bdf/bdf.c
	freetype/src/cff/cff.c
	freetype/src/cid/type1cid.c
	freetype/src/pcf/pcf.c
	freetype/src/pfr/pfr.c
	freetype/src/sfnt/sfnt.c
	freetype/src/truetype/truetype.c
	freetype/src/type1/type1.c
	freetype/src/type42/type42.c
	freetype/src/winfonts/winfnt.c
	freetype/src/raster/raster.c
	freetype/src/smooth/smooth.c
	freetype/src/autofit/autofit.c
	freetype/src/psaux/psaux.c
	freetype/src/pshinter/pshinter.c
	freetype/src/psnames/psnames.c
	#freetype/src/gzip/ftgzip.c
	freetype/src/lzw/ftlzw.c
	)

	##------------------------------------------
	## ftgl
	##------------------------------------------
	SET(FTGL_SRC
	ftgl/src/FTGL/ftgl.h
	ftgl/msvc/config.h
	ftgl/src/FTGL/FTBBox.h
	ftgl/src/FTFont/FTBitmapFontImpl.h
	ftgl/src/FTGL/FTBitmapGlyph.h
	ftgl/src/FTGlyph/FTBitmapGlyphImpl.h
	ftgl/src/FTGL/FTBuffer.h
	ftgl/src/FTGL/FTBufferFont.h
	ftgl/src/FTFont/FTBufferFontImpl.h
	ftgl/src/FTGL/FTBufferGlyph.h
	ftgl/src/FTGlyph/FTBufferGlyphImpl.h
	ftgl/src/FTCharmap.h
	ftgl/src/FTCharToGlyphIndexMap.h
	ftgl/src/FTContour.h
	ftgl/src/FTGL/FTExtrdGlyph.h
	ftgl/src/FTFont/FTExtrudeFontImpl.h
	ftgl/src/FTGlyph/FTExtrudeGlyphImpl.h
	ftgl/src/FTFace.h
	ftgl/src/FTGL/FTFont.h
	ftgl/src/FTFont/FTFontImpl.h
	ftgl/src/FTGL/FTGLBitmapFont.h
	ftgl/src/FTGL/FTGLExtrdFont.h
	ftgl/src/FTGL/FTGLOutlineFont.h
	ftgl/src/FTGL/FTGLPixmapFont.h
	ftgl/src/FTGL/FTGLPolygonFont.h
	ftgl/src/FTGL/FTGLTextureFont.h
	ftgl/src/FTGL/FTGlyph.h
	ftgl/src/FTGlyphContainer.h
	ftgl/src/FTGlyph/FTGlyphImpl.h
	ftgl/src/FTInternals.h
	ftgl/src/FTGL/FTLayout.h
	ftgl/src/FTLayout/FTLayoutImpl.h
	ftgl/src/FTLibrary.h
	ftgl/src/FTList.h
	ftgl/src/FTFont/FTOutlineFontImpl.h
	ftgl/src/FTGL/FTOutlineGlyph.h
	ftgl/src/FTGlyph/FTOutlineGlyphImpl.h
	ftgl/src/FTFont/FTPixmapFontImpl.h
	ftgl/src/FTGL/FTPixmapGlyph.h
	ftgl/src/FTGlyph/FTPixmapGlyphImpl.h
	ftgl/src/FTGL/FTPoint.h
	ftgl/src/FTGL/FTPolyGlyph.h
	ftgl/src/FTFont/FTPolygonFontImpl.h
	ftgl/src/FTGlyph/FTPolygonGlyphImpl.h
	ftgl/src/FTGL/FTSimpleLayout.h
	ftgl/src/FTLayout/FTSimpleLayoutImpl.h
	ftgl/src/FTSize.h
	ftgl/src/FTFont/FTTextureFontImpl.h
	ftgl/src/FTGL/FTTextureGlyph.h
	ftgl/src/FTGlyph/FTTextureGlyphImpl.h
	ftgl/src/FTUnicode.h
	ftgl/src/FTVector.h
	ftgl/src/FTVectoriser.h
	ftgl/src/FTFont/FTBitmapFont.cpp
	ftgl/src/FTGlyph/FTBitmapGlyph.cpp
	ftgl/src/FTBuffer.cpp
	ftgl/src/FTFont/FTBufferFont.cpp
	ftgl/src/FTGlyph/FTBufferGlyph.cpp
	ftgl/src/FTCharmap.cpp
	ftgl/src/FTContour.cpp
	ftgl/src/FTFont/FTExtrudeFont.cpp
	ftgl/src/FTGlyph/FTExtrudeGlyph.cpp
	ftgl/src/FTFace.cpp
	ftgl/src/FTFont/FTFont.cpp
	ftgl/src/FTFont/FTFontGlue.cpp
	ftgl/src/FTGlyph/FTGlyph.cpp
	ftgl/src/FTGlyphContainer.cpp
	ftgl/src/FTGlyph/FTGlyphGlue.cpp
	ftgl/src/FTLayout/FTLayout.cpp
	ftgl/src/FTLayout/FTLayoutGlue.cpp
	ftgl/src/FTLibrary.cpp
	ftgl/src/FTFont/FTOutlineFont.cpp
	ftgl/src/FTGlyph/FTOutlineGlyph.cpp
	ftgl/src/FTFont/FTPixmapFont.cpp
	ftgl/src/FTGlyph/FTPixmapGlyph.cpp
	ftgl/src/FTPoint.cpp
	ftgl/src/FTFont/FTPolygonFont.cpp
	ftgl/src/FTGlyph/FTPolygonGlyph.cpp
	ftgl/src/FTLayout/FTSimpleLayout.cpp
	ftgl/src/FTSize.cpp
	ftgl/src/FTFont/FTTextureFont.cpp
	ftgl/src/FTGlyph/FTTextureGlyph.cpp
	ftgl/src/FTVectoriser.cpp
	)


	##------------------------------------------
	## 3ds
	##------------------------------------------
	SET(3DS_SRC
	3ds/src/lib3ds.h
	#3ds/src/lib3ds.rc
	3ds/src/lib3ds_atmosphere.c
	3ds/src/lib3ds_background.c
	3ds/src/lib3ds_camera.c
	3ds/src/lib3ds_chunk.c
	3ds/src/lib3ds_chunktable.c
	3ds/src/lib3ds_file.c
	3ds/src/lib3ds_impl.h
	3ds/src/lib3ds_io.c
	3ds/src/lib3ds_light.c
	3ds/src/lib3ds_material.c
	3ds/src/lib3ds_math.c
	3ds/src/lib3ds_matrix.c
	3ds/src/lib3ds_mesh.c
	3ds/src/lib3ds_node.c
	3ds/src/lib3ds_quat.c
	3ds/src/lib3ds_shadow.c
	3ds/src/lib3ds_track.c
	3ds/src/lib3ds_util.c
	3ds/src/lib3ds_vector.c
	3ds/src/lib3ds_viewport.c
	)

	IF(CMAKE_CXX_COMPILER MATCHES cl)
	##### Microsoft Visual Studio 2005 options #####
	IF(CMAKE_GENERATOR STREQUAL "Visual Studio 8 2005")
		SET(CMAKE_CXX_FLAGS "/nologo /W3 /Gy")
		SET(CMAKE_CXX_FLAGS_DEBUG "/MTd /Z7 /Od /EHsc /DDEBUG")
		SET(CMAKE_CXX_FLAGS_RELEASE "/MT /Z7 /O2 /EHsc")
		SET(CMAKE_CXX_FLAGS_MINSIZEREL "/MT /O2 /EHsc")
		SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MTd /Z7 /Od /EHsc")
	ENDIF(CMAKE_GENERATOR STREQUAL "Visual Studio 8 2005")

	##### Microsoft Visual Studio 2008 options #####
	IF(CMAKE_GENERATOR STREQUAL "Visual Studio 9 2008")
       	SET(CMAKE_CXX_FLAGS "/nologo /W3 /Gy")
       	SET(CMAKE_CXX_FLAGS_DEBUG "/MTd /Z7 /Od /EHsc /DDEBUG")
       	SET(CMAKE_CXX_FLAGS_RELEASE "/MT /Z7 /O2 /EHsc")
		SET(CMAKE_CXX_FLAGS_MINSIZEREL "/MT /O2 /EHsc")
     	SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MTd /Z7 /Od /EHsc")
	ENDIF(CMAKE_GENERATOR STREQUAL "Visual Studio 9 2008")

	##### Microsoft Visual Studio 2010 options #####
	IF(CMAKE_GENERATOR STREQUAL "Visual Studio 10")
       	SET(CMAKE_CXX_FLAGS "/nologo /W3 /Gy")
       	SET(CMAKE_CXX_FLAGS_DEBUG "/MTd /Z7 /Od /EHsc /DDEBUG")
       	SET(CMAKE_CXX_FLAGS_RELEASE "/MT /Z7 /O2 /EHsc")
		SET(CMAKE_CXX_FLAGS_MINSIZEREL "/MT /O2 /EHsc")
		SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MTd /Z7 /Od /EHsc")
	ENDIF(CMAKE_GENERATOR STREQUAL "Visual Studio 10")
	ENDIF(CMAKE_CXX_COMPILER MATCHES cl)

	ADD_DEFINITIONS(-DWIN32)
	ADD_DEFINITIONS(-D__FLTUSED__)
	ADD_DEFINITIONS(-DFTGL_LIBRARY_STATIC)

	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR})
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/directx)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/digitalknob)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/sdl/include)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/sdl_image)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/sdl_image/external/libpng-1.6.2)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/sdl_mixer)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/png)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/zlib)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/freetype/include)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/ftgl/msvc/)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/ftgl/src/)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/3ds/src/)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/zlib)

	### directx ###
	FIND_LIBRARY(dxguid dxguid ${DKLIBS_SOURCE_DIR}/bin/WIN32/Debug)

	### digitalknob ###
	FIND_LIBRARY(dkd dkd ${DKLIBS_SOURCE_DIR}/bin/WIN32/Debug)
	FIND_LIBRARY(dk dk ${DKLIBS_SOURCE_DIR}/bin/WIN32/Release)
	
	### sdl ###
	FIND_LIBRARY(sdld sdld ${DKLIBS_SOURCE_DIR}/bin/WIN32/Debug)
	FIND_LIBRARY(sdl sdl ${DKLIBS_SOURCE_DIR}/bin/WIN32/Release)

	### sdl_Image ###
	FIND_LIBRARY(sdlimaged sdlimaged ${DKLIBS_SOURCE_DIR}/bin/WIN32/Debug)
	FIND_LIBRARY(sdlimage sdlimage ${DKLIBS_SOURCE_DIR}/bin/WIN32/Release)
	
	### sdl_mixer ###
	FIND_LIBRARY(sdlmixerd sdlmixerd ${DKLIBS_SOURCE_DIR}/bin/WIN32/Debug)
	FIND_LIBRARY(sdlmixer sdlmixer ${DKLIBS_SOURCE_DIR}/bin/WIN32/Release)
	
	### zlib ###
	FIND_LIBRARY(zlibd zlibd ${DKLIBS_SOURCE_DIR}/bin/WIN32/Debug)
	FIND_LIBRARY(zlib zlib ${DKLIBS_SOURCE_DIR}/bin/WIN32/Release)

	### png ###
	FIND_LIBRARY(pngd pngd ${DKLIBS_SOURCE_DIR}/bin/WIN32/Debug)
	FIND_LIBRARY(png png ${DKLIBS_SOURCE_DIR}/bin/WIN32/Release)

	### freetype ###
	FIND_LIBRARY(freetyped freetyped ${DKLIBS_SOURCE_DIR}/bin/WIN32/Debug)
	FIND_LIBRARY(freetype freetype ${DKLIBS_SOURCE_DIR}/bin/WIN32/Release)
	
	### ftgl ###
	FIND_LIBRARY(ftgld ftgld ${DKLIBS_SOURCE_DIR}/bin/WIN32/Debug)
	FIND_LIBRARY(ftgl ftgl ${DKLIBS_SOURCE_DIR}/bin/WIN32/Release)
	
	### 3ds ###
	FIND_LIBRARY(3dsd 3dsd ${DKLIBS_SOURCE_DIR}/bin/WIN32/Debug)
	FIND_LIBRARY(3ds 3ds ${DKLIBS_SOURCE_DIR}/bin/WIN32/Release)

	### digitalknob ###
	ADD_LIBRARY(libdk STATIC ${DIGITALKNOB_SRC})
	SET_TARGET_PROPERTIES(libdk PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME dk DEBUG_OUTPUT_NAME dkd)
	SET_TARGET_PROPERTIES(libdk PROPERTIES COMPILE_DEFINITIONS WIN32)
	
	### sdl library ###
	ADD_LIBRARY(libsdl STATIC ${SDL_SRC})
	SET_TARGET_PROPERTIES(libsdl PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME sdl DEBUG_OUTPUT_NAME sdld)
	SET_TARGET_PROPERTIES(libsdl PROPERTIES COMPILE_DEFINITIONS WIN32)

	### sdl_image library ###
	ADD_LIBRARY(libsdlimage STATIC ${SDLIMAGE_SRC})
	SET_TARGET_PROPERTIES(libsdlimage PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME sdlimage DEBUG_OUTPUT_NAME sdlimaged)
	SET_TARGET_PROPERTIES(libsdlimage PROPERTIES COMPILE_DEFINITIONS WIN32,_WINDOWS,LOAD_BMP,LOAD_GIF,LOAD_LBM,LOAD_PCX,LOAD_PNG,LOAD_PNM,LOAD_TGA,LOAD_XPM,LOAD_XV)

	### sdl_mixer library ###
	ADD_LIBRARY(libsdlmixer STATIC ${SDLMIXER_SRC})
	SET_TARGET_PROPERTIES(libsdlmixer PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME sdlmixer DEBUG_OUTPUT_NAME sdlmixerd)
	SET_TARGET_PROPERTIES(libsdlmixer PROPERTIES COMPILE_DEFINITIONS WIN32,_WINDOWS,WAV_MUSIC,MID_MUSIC)
	
	### zlib library ###
	ADD_LIBRARY(libzlib STATIC ${ZLIB_SRC})
	SET_TARGET_PROPERTIES(libzlib PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME zlib DEBUG_OUTPUT_NAME zlibd)
	SET_TARGET_PROPERTIES(libzlib PROPERTIES COMPILE_DEFINITIONS NO_FSEEKO)

	### png library ###
	ADD_LIBRARY(libpng STATIC ${PNG_SRC})
	SET_TARGET_PROPERTIES(libpng PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME png DEBUG_OUTPUT_NAME pngd)
	SET_TARGET_PROPERTIES(libpng PROPERTIES COMPILE_DEFINITIONS WIN32)

	### freetype library ###
	ADD_LIBRARY(libfreetype STATIC ${FREETYPE_SRC})
	SET_TARGET_PROPERTIES(libfreetype PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME freetype DEBUG_OUTPUT_NAME freetyped)
	SET_TARGET_PROPERTIES(libfreetype PROPERTIES COMPILE_DEFINITIONS WIN32,_LIB,FT2_BUILD_LIBRARY)
	SET_TARGET_PROPERTIES(libfreetype PROPERTIES COMPILE_FLAGS "/Za")
	
	### ftgl library ###
	ADD_LIBRARY(libftgl STATIC ${FTGL_SRC})
	SET_TARGET_PROPERTIES(libftgl PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME ftgl DEBUG_OUTPUT_NAME ftgld)
	SET_TARGET_PROPERTIES(libftgl PROPERTIES COMPILE_DEFINITIONS WIN32,FTGL_LIBRARY_STATIC)
	
	### 3ds library ###
	ADD_LIBRARY(lib3ds STATIC ${3DS_SRC})
	SET_TARGET_PROPERTIES(lib3ds PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME 3ds DEBUG_OUTPUT_NAME 3dsd)
	SET_TARGET_PROPERTIES(lib3ds PROPERTIES COMPILE_DEFINITIONS WIN32,LIB3DS_STATIC)
					  
ENDIF(WIN32)


##----------------------------------------
##        ##### MAC #####
##----------------------------------------
IF(MAC)

	MESSAGE(STATUS "Detected MAC environment")
	MESSAGE(STATUS "Creating Mac Project Files")
	
	SET(EXECUTABLE_OUTPUT_PATH ${DKLIBS_SOURCE_DIR}/bin/MAC)
	SET(LIBRARY_OUTPUT_PATH ${DKLIBS_SOURCE_DIR}/bin/MAC)
	
	##------------------------------------------
	## digitalknob
	##------------------------------------------
	SET(DIGITALKNOB_SRC
	digitalknob/arial.h
	digitalknob/DK.h
	digitalknob/DKDebug.h
	digitalknob/DKDebug.cpp
	digitalknob/DKFile.h
	digitalknob/DKFile.cpp
	digitalknob/DKObject.h
	digitalknob/DKObject.cpp
	digitalknob/DKObjectManager.h
	digitalknob/DKObjectManager.cpp
	digitalknob/DKEvent.h
	digitalknob/DKEvent.cpp
	digitalknob/DKFrame.h
	digitalknob/DKFrame.cpp
	digitalknob/DKWindow.h
	digitalknob/DKWindow.cpp
	digitalknob/DKPanel.h
	digitalknob/DKPanel.cpp
	digitalknob/DKAudio.h
	digitalknob/DKAudio.cpp
	digitalknob/DKFont.h
	digitalknob/DKFont.cpp
	digitalknob/DKTexture.h
	digitalknob/DKTexture.cpp
	digitalknob/DKText.h
	digitalknob/DKText.cpp
	digitalknob/DKImage.h
	digitalknob/DKImage.cpp
	digitalknob/DKSquare.h
	digitalknob/DKSquare.cpp
	digitalknob/DKTriangle.h
	digitalknob/DKTriangle.cpp
	digitalknob/DKCircle.h
	digitalknob/DKCircle.cpp
	digitalknob/DKLine.h
	digitalknob/DKLine.cpp
	digitalknob/DKXyz.h
	digitalknob/DKXyz.cpp
	digitalknob/DKCube.h
	digitalknob/DKCube.cpp
	digitalknob/DKButton.h
	digitalknob/DKButton.cpp
	digitalknob/DKTextBox.h
	digitalknob/DKTextBox.cpp
	digitalknob/DKTextButton.h
	digitalknob/DKTextButton.cpp
	digitalknob/DKToggle.h
	digitalknob/DKToggle.cpp
	digitalknob/DKListBox.h
	digitalknob/DKListBox.cpp
	digitalknob/DKSlider.h
	digitalknob/DKSlider.cpp
	digitalknob/DKFps.h
	digitalknob/DKFps.cpp
	digitalknob/DKAnimate.h
	digitalknob/DKAnimate.cpp
	digitalknob/DKCamera.h
	digitalknob/DKCamera.cpp
	digitalknob/DKMessage.h
	digitalknob/DKMessage.cpp
	digitalknob/DKFileDialog.h
	digitalknob/DKFileDialog.cpp
	digitalknob/DK3ds.h
	digitalknob/DK3ds.cpp
	digitalknob/DKString.h
	digitalknob/DKString.cpp
	digitalknob/DKZip.h
	digitalknob/DKZip.cpp
	digitalknob/DKOsInfo.h
	digitalknob/DKOsInfo.cpp
	digitalknob/DKMenuBar.h
	digitalknob/DKMenuBar.cpp
	digitalknob/DKDropDown.h
	digitalknob/DKDropDown.cpp
	digitalknob/DKColorPicker.h
	digitalknob/DKColorPicker.cpp
	digitalknob/DKColor.h
	digitalknob/DKColor.cpp
	digitalknob/DKAxis.h
	digitalknob/DKAxis.cpp
	digitalknob/DKTextEdit.h
	digitalknob/DKTextEdit.cpp
	digitalknob/DKKeyboard.h
	digitalknob/DKKeyboard.cpp
	digitalknob/DKFrameBase.h
	digitalknob/DKFrameBase.cpp
	digitalknob/DKOpengl.h
	digitalknob/DKScrollBar.h
	digitalknob/DKScrollBar.cpp
	digitalknob/DKGlobal.h
	digitalknob/DKGlobal.cpp
	digitalknob/DKScrollPanel.h
	digitalknob/DKScrollPanel.cpp
	)

	##------------------------------------------------
	##  sdl
	##------------------------------------------------
	SET(SDL_SRCS
	sdl/include/begin_code.h
	sdl/include/close_code.h
	sdl/include/SDL.h
	sdl/include/SDL_assert.h
	sdl/include/SDL_atomic.h
	sdl/include/SDL_audio.h
	sdl/include/SDL_bits.h
	sdl/include/SDL_blendmode.h
	sdl/include/SDL_clipboard.h
	sdl/include/SDL_config.h
	sdl/include/SDL_config_macosx.h
	sdl/include/SDL_copying.h
	sdl/include/SDL_cpuinfo.h
	sdl/include/SDL_endian.h
	sdl/include/SDL_error.h
	sdl/include/SDL_events.h
	sdl/include/SDL_gamecontroller.h
	sdl/include/SDL_gesture.h
	sdl/include/SDL_haptic.h
	sdl/include/SDL_hints.h
	sdl/include/SDL_joystick.h
	sdl/include/SDL_keyboard.h
	sdl/include/SDL_keycode.h
	sdl/include/SDL_loadso.h
	sdl/include/SDL_log.h
	sdl/include/SDL_main.h
	sdl/include/SDL_messagebox.h
	sdl/include/SDL_mouse.h
	sdl/include/SDL_mutex.h
	sdl/include/SDL_name.h
	sdl/include/SDL_opengl.h
	sdl/include/SDL_opengles.h
	sdl/include/SDL_opengles2.h
	sdl/include/SDL_pixels.h
	sdl/include/SDL_platform.h
	sdl/include/SDL_power.h
	sdl/include/SDL_quit.h
	sdl/include/SDL_rect.h
	sdl/include/SDL_render.h
	sdl/include/SDL_revision.h
	sdl/include/SDL_rwops.h
	sdl/include/SDL_scancode.h
	sdl/include/SDL_shape.h
	sdl/include/SDL_stdinc.h
	sdl/include/SDL_surface.h
	sdl/include/SDL_system.h
	sdl/include/SDL_syswm.h
	sdl/include/SDL_thread.h
	sdl/include/SDL_timer.h
	sdl/include/SDL_touch.h
	sdl/include/SDL_types.h
	sdl/include/SDL_version.h
	sdl/include/SDL_video.h
	sdl/src/atomic/SDL_atomic.c
	sdl/src/atomic/SDL_spinlock.c
	sdl/src/audio/disk/SDL_diskaudio.c
	sdl/src/audio/disk/SDL_diskaudio.h
	sdl/src/audio/dummy/SDL_dummyaudio.c
	sdl/src/audio/dummy/SDL_dummyaudio.h
	sdl/src/audio/coreaudio/SDL_coreaudio.c
	sdl/src/audio/coreaudio/SDL_coreaudio.h
	sdl/src/audio/SDL_audio.c
	sdl/src/audio/SDL_audio_c.h
	sdl/src/audio/SDL_audiocvt.c
	sdl/src/audio/SDL_audiodev.c
	sdl/src/audio/SDL_audiodev_c.h
	sdl/src/audio/SDL_audiomem.h
	sdl/src/audio/SDL_audiotypecvt.c
	sdl/src/audio/SDL_mixer.c
	sdl/src/audio/SDL_sysaudio.h
	sdl/src/audio/SDL_wave.c
	sdl/src/audio/SDL_wave.h
	sdl/src/cpuinfo/SDL_cpuinfo.c
	sdl/src/events/blank_cursor.h
	sdl/src/events/default_cursor.h
	sdl/src/events/scancodes_darwin.h
	sdl/src/events/scancodes_linux.h
	sdl/src/events/scancodes_xfree86.h
	sdl/src/events/SDL_clipboardevents_c.h
	sdl/src/events/SDL_clipboardevents.c
	sdl/src/events/SDL_dropevents_c.h
	sdl/src/events/SDL_dropevents.c
	sdl/src/events/SDL_events.c
	sdl/src/events/SDL_events_c.h
	sdl/src/events/SDL_gesture_c.h
	sdl/src/events/SDL_gesture.c
	sdl/src/events/SDL_keyboard.c
	sdl/src/events/SDL_keyboard_c.h
	sdl/src/events/SDL_mouse.c
	sdl/src/events/SDL_mouse_c.h
	sdl/src/events/SDL_quit.c
	sdl/src/events/SDL_sysevents.h
	sdl/src/events/SDL_touch.c
	sdl/src/events/SDL_touch_c.h
	sdl/src/events/SDL_windowevents.c
	sdl/src/events/SDL_windowevents_c.h
	sdl/src/file/cocoa/SDL_rwopsbundlesupport.h
	sdl/src/file/cocoa/SDL_rwopsbundlesupport.m
	sdl/src/file/SDL_rwops.c
	sdl/src/haptic/darwin/SDL_syshaptic.c
	sdl/src/haptic/SDL_haptic.c
	sdl/src/haptic/SDL_haptic_c.h
	sdl/src/haptic/SDL_syshaptic.h
	sdl/src/joystick/darwin/SDL_sysjoystick.c
	sdl/src/joystick/darwin/SDL_sysjoystick_c.h
	sdl/src/joystick/SDL_joystick.c
	sdl/src/joystick/SDL_joystick_c.h
	sdl/src/joystick/SDL_gamecontroller.c
	sdl/src/joystick/SDL_sysjoystick.h
	sdl/src/loadso/dlopen/SDL_sysloadso.c
	sdl/src/power/macosx/SDL_syspower.c
	sdl/src/power/SDL_power.c
	sdl/src/render/opengl/SDL_glfuncs.h
	sdl/src/render/opengl/SDL_render_gl.c
	sdl/src/render/opengl/SDL_shaders_gl.c
	sdl/src/render/opengl/SDL_shaders_gl.h
	sdl/src/render/software/SDL_blendfillrect.c
	sdl/src/render/software/SDL_blendfillrect.h
	sdl/src/render/software/SDL_blendline.c
	sdl/src/render/software/SDL_blendline.h
	sdl/src/render/software/SDL_blendpoint.c
	sdl/src/render/software/SDL_blendpoint.h
	sdl/src/render/software/SDL_draw.h
	sdl/src/render/software/SDL_drawline.c
	sdl/src/render/software/SDL_drawline.h
	sdl/src/render/software/SDL_drawpoint.c
	sdl/src/render/software/SDL_drawpoint.c
	sdl/src/render/software/SDL_render_sw_c.h
	sdl/src/render/software/SDL_render_sw.c
	sdl/src/render/software/SDL_rotate.c
	sdl/src/render/software/SDL_rotate.h
	sdl/src/render/mmx.h
	sdl/src/render/SDL_render.c
	sdl/src/render/SDL_sysrender.h
	sdl/src/render/SDL_yuv_mmx.c
	sdl/src/render/SDL_yuv_sw_c.h
	sdl/src/render/SDL_yuv_sw.c
	sdl/src/stdlib/SDL_getenv.c
	sdl/src/stdlib/SDL_iconv.c
	sdl/src/stdlib/SDL_malloc.c
	sdl/src/stdlib/SDL_qsort.c
	sdl/src/stdlib/SDL_stdlib.c
	sdl/src/stdlib/SDL_string.c
	sdl/src/thread/pthread/SDL_syscond.c
	sdl/src/thread/pthread/SDL_sysmutex.c
	sdl/src/thread/pthread/SDL_sysmutex_c.h
	sdl/src/thread/pthread/SDL_syssem.c
	sdl/src/thread/pthread/SDL_systhread.c
	sdl/src/thread/pthread/SDL_systhread_c.h
	sdl/src/thread/pthread/SDL_systls.c
	sdl/src/thread/SDL_systhread.h
	sdl/src/thread/SDL_thread.c
	sdl/src/thread/SDL_thread_c.h
	sdl/src/timer/unix/SDL_systimer.c
	sdl/src/timer/SDL_timer.c
	sdl/src/timer/SDL_timer_c.h
	sdl/src/video/cocoa/SDL_cocoaclipboard.h
	sdl/src/video/cocoa/SDL_cocoaclipboard.m
	sdl/src/video/cocoa/SDL_cocoaevents.h
	sdl/src/video/cocoa/SDL_cocoaevents.m
	sdl/src/video/cocoa/SDL_cocoakeyboard.h
	sdl/src/video/cocoa/SDL_cocoakeyboard.m
	sdl/src/video/cocoa/SDL_cocoamessagebox.h
	sdl/src/video/cocoa/SDL_cocoamessagebox.m
	sdl/src/video/cocoa/SDL_cocoamodes.h
	sdl/src/video/cocoa/SDL_cocoamodes.m
	sdl/src/video/cocoa/SDL_cocoamouse.h
	sdl/src/video/cocoa/SDL_cocoamouse.m
	sdl/src/video/cocoa/SDL_cocoaopengl.h
	sdl/src/video/cocoa/SDL_cocoaopengl.m
	sdl/src/video/cocoa/SDL_cocoashape.h
	sdl/src/video/cocoa/SDL_cocoashape.m
	sdl/src/video/cocoa/SDL_cocoavideo.h
	sdl/src/video/cocoa/SDL_cocoavideo.m
	sdl/src/video/cocoa/SDL_cocoawindow.h
	sdl/src/video/cocoa/SDL_cocoawindow.m
	sdl/src/video/dummy/SDL_nullevents.c
	sdl/src/video/dummy/SDL_nullevents_c.h
	sdl/src/video/dummy/SDL_nullframebuffer_c.h
	sdl/src/video/dummy/SDL_nullframebuffer.c
	sdl/src/video/dummy/SDL_nullvideo.c
	sdl/src/video/dummy/SDL_nullvideo.h
	sdl/src/video/x11/imKStoUCS.c
	sdl/src/video/x11/imKStoUCS.h
	sdl/src/video/x11/SDL_x11clipboard.c
	sdl/src/video/x11/SDL_x11clipboard.h
	sdl/src/video/x11/SDL_x11dyn.c
	sdl/src/video/x11/SDL_x11dyn.h
	sdl/src/video/x11/SDL_x11events.c
	sdl/src/video/x11/SDL_x11events.h
	sdl/src/video/x11/SDL_x11framebuffer.c
	sdl/src/video/x11/SDL_x11framebuffer.h
	sdl/src/video/x11/SDL_x11keyboard.c
	sdl/src/video/x11/SDL_x11keyboard.h
	sdl/src/video/x11/SDL_x11messagebox.c
	sdl/src/video/x11/SDL_x11modes.c
	sdl/src/video/x11/SDL_x11modes.h
	sdl/src/video/x11/SDL_x11mouse.c
	sdl/src/video/x11/SDL_x11mouse.h
	sdl/src/video/x11/SDL_x11opengl.c
	sdl/src/video/x11/SDL_x11opengl.h
	sdl/src/video/x11/SDL_x11opengles.c
	sdl/src/video/x11/SDL_x11opengles.h
	sdl/src/video/x11/SDL_x11shape.c
	sdl/src/video/x11/SDL_x11shape.h
	sdl/src/video/x11/SDL_x11sym.h
	sdl/src/video/x11/SDL_x11touch.c
	sdl/src/video/x11/SDL_x11touch.h
	sdl/src/video/x11/SDL_x11video.c
	sdl/src/video/x11/SDL_x11video.h
	sdl/src/video/x11/SDL_x11window.c
	sdl/src/video/x11/SDL_x11window.h
	sdl/src/video/x11/SDL_x11xinput2.c
	sdl/src/video/x11/SDL_x11xinput2.h
	sdl/src/video/SDL_blit.c
	sdl/src/video/SDL_blit.h
	sdl/src/video/SDL_blit_0.c
	sdl/src/video/SDL_blit_1.c
	sdl/src/video/SDL_blit_A.c
	sdl/src/video/SDL_blit_auto.c
	sdl/src/video/SDL_blit_auto.h
	sdl/src/video/SDL_blit_copy.c
	sdl/src/video/SDL_blit_copy.h
	sdl/src/video/SDL_blit_N.c
	sdl/src/video/SDL_blit_slow.c
	sdl/src/video/SDL_blit_slow.h
	sdl/src/video/SDL_bmp.c
	sdl/src/video/SDL_clipboard.c
	sdl/src/video/SDL_fillrect.c
	sdl/src/video/SDL_pixels.c
	sdl/src/video/SDL_pixels_c.h
	sdl/src/video/SDL_rect.c
	sdl/src/video/SDL_RLEaccel.c
	sdl/src/video/SDL_RLEaccel_c.h
	sdl/src/video/SDL_shape.c
	sdl/src/video/SDL_shape_internals.h
	sdl/src/video/SDL_stretch.c
	sdl/src/video/SDL_surface.c
	sdl/src/video/SDL_sysvideo.h
	sdl/src/video/SDL_video.c
	sdl/src/SDL_assert.c
	sdl/src/SDL_assert_c.h
	sdl/src/SDL_error_c.h
	sdl/src/SDL_error.c
	sdl/src/SDL_fatal.c
	sdl/src/SDL_fatal.h
	sdl/src/SDL_hints.c
	#sdl/src/SDL_hints_c.h
	sdl/src/SDL_log.c
	sdl/src/SDL.c
	)

	##------------------------------------------------
	##  sdl_image
	##------------------------------------------------
	SET(SDLIMAGE_SRCS
	sdl_image/SDL_image.h
	sdl_image/IMG.c
	sdl_image/IMG_bmp.c
	sdl_image/IMG_gif.c
	sdl_image/IMG_jpg.c
	sdl_image/IMG_lbm.c
	sdl_image/IMG_pcx.c
	sdl_image/IMG_png.c
	sdl_image/IMG_pnm.c
	sdl_image/IMG_tga.c
	sdl_image/IMG_tif.c
	sdl_image/IMG_webp.c
	sdl_image/IMG_xcf.c
	sdl_image/IMG_xpm.c
	sdl_image/IMG_xv.c
	sdl_image/IMG_xxx.c
	sdl_image/IMG_ImageIO.m
	sdl_image/IMG_ImageIO.m
	)
	
	##---------------------------------------------
	## png
	##---------------------------------------------
	SET(PNG_SRCS
	sdl_image/external/libpng-1.6.2/png.h
	sdl_image/external/libpng-1.6.2/pngconf.h
	sdl_image/external/libpng-1.6.2/pngpriv.h
	sdl_image/external/libpng-1.6.2/png.c
	sdl_image/external/libpng-1.6.2/pngerror.c
	sdl_image/external/libpng-1.6.2/pngget.c
	sdl_image/external/libpng-1.6.2/pngmem.c
	sdl_image/external/libpng-1.6.2/pngpread.c
	sdl_image/external/libpng-1.6.2/pngread.c
	sdl_image/external/libpng-1.6.2/pngrio.c
	sdl_image/external/libpng-1.6.2/pngrtran.c
	sdl_image/external/libpng-1.6.2/pngrutil.c
	sdl_image/external/libpng-1.6.2/pngset.c
	sdl_image/external/libpng-1.6.2/pngtrans.c
	sdl_image/external/libpng-1.6.2/pngwio.c
	sdl_image/external/libpng-1.6.2/pngwrite.c
	sdl_image/external/libpng-1.6.2/pngwtran.c
	sdl_image/external/libpng-1.6.2/pngwutil.c
	)

	##------------------------------------------------
	## sdl_mixer
	##------------------------------------------------
	SET(SDLMIXER_SRCS
	sdl_mixer/dynamic_flac.c
	sdl_mixer/dynamic_flac.h
	sdl_mixer/dynamic_mod.c
	sdl_mixer/dynamic_mod.h
	sdl_mixer/dynamic_mp3.c
	sdl_mixer/dynamic_mp3.h
	sdl_mixer/dynamic_ogg.c
	sdl_mixer/dynamic_ogg.h
	sdl_mixer/effect_position.c
	sdl_mixer/effect_stereoreverse.c
	sdl_mixer/effects_internal.c
	sdl_mixer/effects_internal.h
	sdl_mixer/load_aiff.c
	sdl_mixer/load_aiff.h
	sdl_mixer/load_flac.c
	sdl_mixer/load_flac.h
	sdl_mixer/load_ogg.c
	sdl_mixer/load_ogg.h
	sdl_mixer/load_voc.c
	sdl_mixer/load_voc.h
	sdl_mixer/mixer.c
	sdl_mixer/music.c
	sdl_mixer/music_cmd.c
	sdl_mixer/music_cmd.h
	sdl_mixer/music_flac.c
	sdl_mixer/music_flac.h
	sdl_mixer/music_mad.c
	sdl_mixer/music_mad.h
	sdl_mixer/music_mod.c
	sdl_mixer/music_mod.h
	sdl_mixer/music_ogg.c
	sdl_mixer/music_ogg.h
	sdl_mixer/SDL_mixer.h
	sdl_mixer/wavestream.c
	sdl_mixer/wavestream.h
	)

	##-----------------------------------------------
	## zlib
	##-----------------------------------------------
	SET(ZLIB_SRCS
	zlib/zlib.h
	zlib/crc32.h
	zlib/deflate.h
	zlib/gzguts.h
	zlib/inffast.h
	zlib/inffixed.h
	zlib/inflate.h
	zlib/inftrees.h
	zlib/trees.h
	zlib/zconf.h
	zlib/zutil.h
	zlib/adler32.c
	zlib/compress.c
	zlib/crc32.c
	zlib/deflate.c
	zlib/gzclose.c
	zlib/gzlib.c
	zlib/gzread.c
	zlib/gzwrite.c
	zlib/infback.c
	zlib/inffast.c
	zlib/inflate.c
	zlib/inftrees.c
	zlib/trees.c
	zlib/uncompr.c
	zlib/zutil.c
	)

	##------------------------------------------
	## freetype
	##------------------------------------------
	SET(FREETYPE_SRCS
	freetype/src/autofit/autofit.c
	freetype/src/base/basepic.c
	freetype/src/base/ftapi.c
	freetype/src/base/ftbase.c
	freetype/src/base/ftbbox.c
	freetype/src/base/ftbitmap.c
	freetype/src/base/ftdbgmem.c
	freetype/src/base/ftdebug.c
	freetype/src/base/ftglyph.c
	freetype/src/base/ftinit.c
	freetype/src/base/ftpic.c
	freetype/src/base/ftstroke.c
	freetype/src/base/ftsynth.c
	freetype/src/base/ftsystem.c
	freetype/src/psnames/psnames.c
	freetype/src/cff/cff.c
	freetype/src/pshinter/pshinter.c
	freetype/src/raster/raster.c
	freetype/src/sfnt/sfnt.c
	freetype/src/smooth/smooth.c
	freetype/src/truetype/truetype.c
	freetype/src/bdf/bdf.c
	freetype/src/cid/type1cid.c
	freetype/src/type1/type1.c
	freetype/src/pfr/pfr.c
	freetype/src/winfonts/winfnt.c
	freetype/src/pcf/pcf.c
	freetype/src/psaux/psaux.c
	freetype/src/type42/type42.c
	freetype/src/gzip/ftgzip.c
	freetype/src/lzw/ftlzw.c
	)

	##------------------------------------------
	## ftgl
	##------------------------------------------
	SET(FTGL_SRCS
	ftgl/src/FTGL/ftgl.h
	ftgl/config.h
	ftgl/src/FTGL/FTBBox.h
	ftgl/src/FTFont/FTBitmapFontImpl.h
	ftgl/src/FTGL/FTBitmapGlyph.h
	ftgl/src/FTGlyph/FTBitmapGlyphImpl.h
	ftgl/src/FTGL/FTBuffer.h
	ftgl/src/FTGL/FTBufferFont.h
	ftgl/src/FTFont/FTBufferFontImpl.h
	ftgl/src/FTGL/FTBufferGlyph.h
	ftgl/src/FTGlyph/FTBufferGlyphImpl.h
	ftgl/src/FTCharmap.h
	ftgl/src/FTCharToGlyphIndexMap.h
	ftgl/src/FTContour.h
	ftgl/src/FTGL/FTExtrdGlyph.h
	ftgl/src/FTFont/FTExtrudeFontImpl.h
	ftgl/src/FTGlyph/FTExtrudeGlyphImpl.h
	ftgl/src/FTFace.h
	ftgl/src/FTGL/FTFont.h
	ftgl/src/FTFont/FTFontImpl.h
	ftgl/src/FTGL/FTGLBitmapFont.h
	ftgl/src/FTGL/FTGLExtrdFont.h
	ftgl/src/FTGL/FTGLOutlineFont.h
	ftgl/src/FTGL/FTGLPixmapFont.h
	ftgl/src/FTGL/FTGLPolygonFont.h
	ftgl/src/FTGL/FTGLTextureFont.h
	ftgl/src/FTGL/FTGlyph.h
	ftgl/src/FTGlyphContainer.h
	ftgl/src/FTGlyph/FTGlyphImpl.h
	ftgl/src/FTInternals.h
	ftgl/src/FTGL/FTLayout.h
	ftgl/src/FTLayout/FTLayoutImpl.h
	ftgl/src/FTLibrary.h
	ftgl/src/FTList.h
	ftgl/src/FTFont/FTOutlineFontImpl.h
	ftgl/src/FTGL/FTOutlineGlyph.h
	ftgl/src/FTGlyph/FTOutlineGlyphImpl.h
	ftgl/src/FTFont/FTPixmapFontImpl.h
	ftgl/src/FTGL/FTPixmapGlyph.h
	ftgl/src/FTGlyph/FTPixmapGlyphImpl.h
	ftgl/src/FTGL/FTPoint.h
	ftgl/src/FTGL/FTPolyGlyph.h
	ftgl/src/FTFont/FTPolygonFontImpl.h
	ftgl/src/FTGlyph/FTPolygonGlyphImpl.h
	ftgl/src/FTGL/FTSimpleLayout.h
	ftgl/src/FTLayout/FTSimpleLayoutImpl.h
	ftgl/src/FTSize.h
	ftgl/src/FTFont/FTTextureFontImpl.h
	ftgl/src/FTGL/FTTextureGlyph.h
	ftgl/src/FTGlyph/FTTextureGlyphImpl.h
	ftgl/src/FTUnicode.h
	ftgl/src/FTVector.h
	ftgl/src/FTVectoriser.h
	ftgl/src/FTFont/FTBitmapFont.cpp
	ftgl/src/FTGlyph/FTBitmapGlyph.cpp
	ftgl/src/FTBuffer.cpp
	ftgl/src/FTFont/FTBufferFont.cpp
	ftgl/src/FTGlyph/FTBufferGlyph.cpp
	ftgl/src/FTCharmap.cpp
	ftgl/src/FTContour.cpp
	ftgl/src/FTFont/FTExtrudeFont.cpp
	ftgl/src/FTGlyph/FTExtrudeGlyph.cpp
	ftgl/src/FTFace.cpp
	ftgl/src/FTFont/FTFont.cpp
	ftgl/src/FTFont/FTFontGlue.cpp
	ftgl/src/FTGlyph/FTGlyph.cpp
	ftgl/src/FTGlyphContainer.cpp
	ftgl/src/FTGlyph/FTGlyphGlue.cpp
	ftgl/src/FTLayout/FTLayout.cpp
	ftgl/src/FTLayout/FTLayoutGlue.cpp
	ftgl/src/FTLibrary.cpp
	ftgl/src/FTFont/FTOutlineFont.cpp
	ftgl/src/FTGlyph/FTOutlineGlyph.cpp
	ftgl/src/FTFont/FTPixmapFont.cpp
	ftgl/src/FTGlyph/FTPixmapGlyph.cpp
	ftgl/src/FTPoint.cpp
	ftgl/src/FTFont/FTPolygonFont.cpp
	ftgl/src/FTGlyph/FTPolygonGlyph.cpp
	ftgl/src/FTLayout/FTSimpleLayout.cpp
	ftgl/src/FTSize.cpp
	ftgl/src/FTFont/FTTextureFont.cpp
	ftgl/src/FTGlyph/FTTextureGlyph.cpp
	ftgl/src/FTVectoriser.cpp
	)

	##------------------------------------------
	## 3ds
	##------------------------------------------
	SET(3DS_SRC
	3ds/src/lib3ds.h
	#3ds/src/lib3ds.rc
	3ds/src/lib3ds_atmosphere.c
	3ds/src/lib3ds_background.c
	3ds/src/lib3ds_camera.c
	3ds/src/lib3ds_chunk.c
	3ds/src/lib3ds_chunktable.c
	3ds/src/lib3ds_file.c
	3ds/src/lib3ds_impl.h
	3ds/src/lib3ds_io.c
	3ds/src/lib3ds_light.c
	3ds/src/lib3ds_material.c
	3ds/src/lib3ds_math.c
	3ds/src/lib3ds_matrix.c
	3ds/src/lib3ds_mesh.c
	3ds/src/lib3ds_node.c
	3ds/src/lib3ds_quat.c
	3ds/src/lib3ds_shadow.c
	3ds/src/lib3ds_track.c
	3ds/src/lib3ds_util.c
	3ds/src/lib3ds_vector.c
	3ds/src/lib3ds_viewport.c
	)
	
	ADD_DEFINITIONS(-DMAC)
	SET(CMAKE_CXX_FLAGS "-x objective-c++")
		
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR})
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/digitalknob)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/sdl/include )
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/sdl_image)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/sdl_image/external/libpng-1.6.2)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/sdl_mixer)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/libpng)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/zlib)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/freetype/include)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/freetype/include/freetype/config)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/freetype/include/freetype/internal)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/ftgl)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/ftgl/src/)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/3ds/src/)
	INCLUDE_DIRECTORIES(/usr/X11/include)		
		
	### FrameWorks ###
	FIND_LIBRARY(CF CoreFoundation)
	FIND_LIBRARY(CO Cocoa)
	FIND_LIBRARY(CB Carbon)
	FIND_LIBRARY(AT AudioToolbox)
	FIND_LIBRARY(AU AudioUnit)
	FIND_LIBRARY(CA CoreAudio)
	FIND_LIBRARY(IO IOKit)
	FIND_LIBRARY(GL OpenGL)
	FIND_LIBRARY(FF ForceFeedback)

	### digitalknob ###
	FIND_LIBRARY(dkd dkd ${DKLIBS_SOURCE_DIR}/bin/MAC/Debug)
	FIND_LIBRARY(dk dk ${DKLIBS_SOURCE_DIR}/bin/MAC/Release)
	
	### sdl ###
	FIND_LIBRARY(sdld sdld ${DKLIBS_SOURCE_DIR}/bin/MAC/Debug)
	FIND_LIBRARY(sdl sdl ${DKLIBS_SOURCE_DIR}/bin/MAC/Release)
	
	### sdl_image ###
	FIND_LIBRARY(sdlimaged sdlimaged ${DKLIBS_SOURCE_DIR}/bin/MAC/Debug)
	FIND_LIBRARY(sdlimage sdlimage ${DKLIBS_SOURCE_DIR}/bin/MAC/Release)
	
	### sdl_mixer ###
	FIND_LIBRARY(sdlmixerd sdlmixerd ${DKLIBS_SOURCE_DIR}/bin/MAC/Debug)
	FIND_LIBRARY(sdlmixer sdlmixer ${DKLIBS_SOURCE_DIR}/bin/MAC/Release)

	### zlib ###
	FIND_LIBRARY(zlibd zlibd ${DKLIBS_SOURCE_DIR}/bin/MAC/Debug)
	FIND_LIBRARY(zlib zlib ${DKLIBS_SOURCE_DIR}/bin/MAC/Release)

	### png ###
	FIND_LIBRARY(pngd pngd ${DKLIBS_SOURCE_DIR}/bin/MAC/Debug)
	FIND_LIBRARY(png png ${DKLIBS_SOURCE_DIR}/bin/MAC/Release)
	
	### freetype ###
	FIND_LIBRARY(freetyped freetyped ${DKLIBS_SOURCE_DIR}/bin/MAC/Debug)
	FIND_LIBRARY(freetype freetype ${DKLIBS_SOURCE_DIR}/bin/MAC/Release)
	
	### ftgl ###
	FIND_LIBRARY(ftgld ftgld ${DKLIBS_SOURCE_DIR}/bin/MAC/Debug)
	FIND_LIBRARY(ftgl ftgl ${DKLIBS_SOURCE_DIR}/bin/MAC/Release)

	### 3ds ###
	FIND_LIBRARY(3dsd 3dsd ${DKLIBS_SOURCE_DIR}/bin/MAC/Debug)
	FIND_LIBRARY(3ds 3ds ${DKLIBS_SOURCE_DIR}/bin/MAC/Release)

	### digitalknob ###
	ADD_LIBRARY(libdk STATIC ${DIGITALKNOB_SRC})
	SET_TARGET_PROPERTIES(libdk PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME dk DEBUG_OUTPUT_NAME dkd)
	SET_TARGET_PROPERTIES(libdk PROPERTIES COMPILE_DEFINITIONS MAC)
	
	### sdl library ###
	ADD_LIBRARY(libsdl STATIC ${SDL_SRCS})
	## NOTE: for some reason lib is always added to the .a file name as in example ( 1234 makes lib1234.a )
	SET_TARGET_PROPERTIES(libsdl PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME sdl DEBUG_OUTPUT_NAME sdld)

	### sdl_image library ###
	ADD_LIBRARY(libsdlimage STATIC ${SDLIMAGE_SRCS})
	SET_TARGET_PROPERTIES(libsdlimage PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME sdlimage DEBUG_OUTPUT_NAME sdlimaged)
	SET_TARGET_PROPERTIES(libsdlimage PROPERTIES COMPILE_DEFINITIONS MAC,LOAD_BMP,LOAD_GIF,LOAD_LBM,LOAD_PCX,LOAD_PNG,LOAD_PNM,LOAD_TGA,LOAD_XPM,LOAD_XV)

	### sdl_mixer library ###
	ADD_LIBRARY(libsdlmixer STATIC ${SDLMIXER_SRCS})
	SET_TARGET_PROPERTIES(libsdlmixer PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME sdlmixer DEBUG_OUTPUT_NAME sdlmixerd)
	SET_TARGET_PROPERTIES(libsdlmixer PROPERTIES COMPILE_DEFINITIONS MAC,WAV_MUSIC,MID_MUSIC)
	
	### zlib library ###
	ADD_LIBRARY(libzlib STATIC ${ZLIB_SRCS})
	SET_TARGET_PROPERTIES(libzlib PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME zlib DEBUG_OUTPUT_NAME zlibd)
	SET_TARGET_PROPERTIES(libzlib PROPERTIES COMPILE_DEFINITIONS NO_FSEEKO)

	### png library ###
	ADD_LIBRARY(libpng STATIC ${PNG_SRCS})
	SET_TARGET_PROPERTIES(libpng PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME png DEBUG_OUTPUT_NAME pngd)
	SET_TARGET_PROPERTIES(libpng PROPERTIES COMPILE_DEFINITIONS MAC)
	
	### freetype library ###
	ADD_LIBRARY(libfreetype STATIC ${FREETYPE_SRCS})
	SET_TARGET_PROPERTIES(libfreetype PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME freetype DEBUG_OUTPUT_NAME freetyped)
	SET_TARGET_PROPERTIES(libfreetype PROPERTIES COMPILE_DEFINITIONS FT2_BUILD_LIBRARY=1,DARWIN_NO_CARBON)
	
	### ftgl library ###
	ADD_LIBRARY(libftgl STATIC ${FTGL_SRCS})
	SET_TARGET_PROPERTIES(libftgl PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME ftgl DEBUG_OUTPUT_NAME ftgld)
	SET_TARGET_PROPERTIES(libftgl PROPERTIES COMPILE_DEFINITIONS MAC,FTGL_LIBRARY_STATIC)

	### 3ds library ###
	ADD_LIBRARY(lib3ds STATIC ${3DS_SRC})
	SET_TARGET_PROPERTIES(lib3ds PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME 3ds DEBUG_OUTPUT_NAME 3dsd)
	SET_TARGET_PROPERTIES(lib3ds PROPERTIES COMPILE_DEFINITIONS MAC,LIB3DS_STATIC)

ENDIF(MAC)


##----------------------------------------
##       ###### LINUX ######
##----------------------------------------
IF(LINUX)

	MESSAGE(STATUS "Detected LINUX environment")
	MESSAGE(STATUS "Creating LINUX Project Files")

	SET(EXECUTABLE_OUTPUT_PATH ${DKLIBS_SOURCE_DIR}/bin/LINUX)
	SET(LIBRARY_OUTPUT_PATH ${DKLIBS_SOURCE_DIR}/bin/LINUX)
	
	##------------------------------------------
	## digitalknob
	##------------------------------------------
	SET(DIGITALKNOB_SRC
	digitalknob/arial.h	
	digitalknob/DK.h
	digitalknob/DKDebug.h
	digitalknob/DKDebug.cpp
	digitalknob/DKObject.h
	digitalknob/DKObject.cpp
	digitalknob/DKObjectManager.h
	digitalknob/DKObjectManager.cpp
	digitalknob/DKEvents.h
	digitalknob/DKEvents.cpp
	digitalknob/DKFrame.h
	digitalknob/DKFrame.cpp
	digitalknob/DKPanel.h
	digitalknob/DKPanel.cpp
	digitalknob/DKFont.h
	digitalknob/DKFont.cpp
	digitalknob/DKAudio.h
	digitalknob/DKAudio.cpp
	digitalknob/DKText.h
	digitalknob/DKText.cpp
	digitalknob/DKImage.h
	digitalknob/DKImage.cpp
	digitalknob/DKSquare.h
	digitalknob/DKSquare.cpp
	digitalknob/DKTriangle.h
	digitalknob/DKTriangle.cpp
	digitalknob/DKCircle.h
	digitalknob/DKCircle.cpp
	digitalknob/DKLine.h
	digitalknob/DKLine.cpp
	digitalknob/DKXyz.h
	digitalknob/DKXyz.cpp
	digitalknob/DKCube.h
	digitalknob/DKCube.cpp
	digitalknob/DKButton.h
	digitalknob/DKButton.cpp
	digitalknob/DKTextBox.h
	digitalknob/DKTextBox.cpp
	digitalknob/DKTextButton.h
	digitalknob/DKTextButton.cpp
	digitalknob/DKToggle.h
	digitalknob/DKToggle.cpp
	digitalknob/DKListBox.h
	digitalknob/DKListBox.cpp
	digitalknob/DKSlider.h
	digitalknob/DKSlider.cpp
	digitalknob/DKFps.h
	digitalknob/DKFps.cpp
	digitalknob/DKAnimate.h
	digitalknob/DKAnimate.cpp
	digitalknob/DK3ds.h
	digitalknob/DK3ds.cpp
	digitalknob/DKOsInfo.h
	digitalknob/DKOsInfo.cpp
	digitalknob/DKFile.h
	digitalknob/DKFile.cpp
	digitalknob/DKMenuBar.h
	digitalknob/DKMenuBar.cpp
	)

	##------------------------------------------------
	##  sdl
	##------------------------------------------------
	SET(SDL_SRCS
	sdl/src/SDL.c
	sdl/src/SDL_assert.c
	sdl/src/SDL_assert_c.h
	sdl/src/SDL_error.c
	sdl/src/SDL_error_c.h
	sdl/src/SDL_fatal.c
	sdl/src/SDL_fatal.h
	sdl/src/SDL_hints.c
	sdl/src/SDL_hints_c.h
	sdl/src/SDL_log.c
	sdl/src/atomic/SDL_atomic.c
	sdl/src/atomic/SDL_spinlock.c
	sdl/src/audio/SDL_audio.c
	sdl/src/audio/SDL_audio_c.h
	sdl/src/audio/SDL_audiocvt.c
	sdl/src/audio/SDL_audiodev.c
	sdl/src/audio/SDL_audiodev_c.h
	sdl/src/audio/SDL_audiomem.h
	sdl/src/audio/SDL_audiotypecvt.c
	sdl/src/audio/SDL_mixer.c
	sdl/src/audio/SDL_sysaudio.h
	sdl/src/audio/SDL_wave.c
	sdl/src/audio/SDL_wave.h
	sdl/src/audio/dummy/SDL_dummyaudio.c
	sdl/src/audio/dummy/SDL_dummyaudio.h
	sdl/src/cpuinfo/SDL_cpuinfo.c
	sdl/src/events/blank_cursor.h
	sdl/src/events/default_cursor.h
	sdl/src/events/scancodes_linux.h
	sdl/src/events/SDL_clipboardevents.c
	sdl/src/events/SDL_clipboardevents_c.h
	sdl/src/events/SDL_dropevents.c
	sdl/src/events/SDL_dropevents_c.h
	sdl/src/events/SDL_events.c
	sdl/src/events/SDL_events_c.h
	sdl/src/events/SDL_gesture.c
	sdl/src/events/SDL_gesture_c.h
	sdl/src/events/SDL_keyboard.c
	sdl/src/events/SDL_keyboard_c.h
	sdl/src/events/SDL_mouse.c
	sdl/src/events/SDL_mouse_c.h
	sdl/src/events/SDL_quit.c
	sdl/src/events/SDL_sysevents.h
	sdl/src/events/SDL_touch.c
	sdl/src/events/SDL_touch_c.h
	sdl/src/events/SDL_windowevents.c
	sdl/src/events/SDL_windowevents_c.h
	sdl/src/file/SDL_rwops.c
	sdl/src/haptic/SDL_haptic.c
	sdl/src/haptic/SDL_haptic_c.h
	sdl/src/haptic/SDL_syshaptic.h
	sdl/src/haptic/dummy/SDL_syshaptic.c
	sdl/src/haptic/linux/SDL_syshaptic.c
	sdl/src/joystick/SDL_joystick.c
	sdl/src/joystick/SDL_joystick_c.h
	sdl/src/joystick/SDL_sysjoystick.h
	sdl/src/joystick/dummy/SDL_sysjoystick.c
	sdl/src/joystick/linux/SDL_sysjoystick.c
	sdl/src/joystick/linux/SDL_sysjoystick_c.h
	sdl/src/loadso/dummy/SDL_sysloadso.c
	sdl/src/power/SDL_power.c
	sdl/src/power/linux/SDL_syspower.c
	sdl/src/render/mmx.h
	sdl/src/render/SDL_render.c
	sdl/src/render/SDL_sysrender.h
	sdl/src/render/SDL_yuv_mmx.c
	sdl/src/render/SDL_yuv_sw.c
	sdl/src/render/SDL_yuv_sw_c.h
	sdl/src/render/software/SDL_blendfillrect.c
	sdl/src/render/software/SDL_blendfillrect.h
	sdl/src/render/software/SDL_blendline.c
	sdl/src/render/software/SDL_blendline.h
	sdl/src/render/software/SDL_blendpoint.c
	sdl/src/render/software/SDL_blendpoint.h
	sdl/src/render/software/SDL_draw.h
	sdl/src/render/software/SDL_drawline.c
	sdl/src/render/software/SDL_drawline.h
	sdl/src/render/software/SDL_drawpoint.c
	sdl/src/render/software/SDL_drawpoint.h
	sdl/src/render/software/SDL_render_sw.c
	sdl/src/render/software/SDL_render_sw_c.h
	sdl/src/render/opengl/SDL_glfuncs.h
	sdl/src/render/opengl/SDL_render_gl.c
	sdl/src/render/opengl/SDL_shaders_gl.c
	sdl/src/render/opengl/SDL_shaders_gl.h
	sdl/src/stdlib/SDL_getenv.c
	sdl/src/stdlib/SDL_iconv.c
	sdl/src/stdlib/SDL_malloc.c
	sdl/src/stdlib/SDL_qsort.c
	sdl/src/stdlib/SDL_stdlib.c
	sdl/src/stdlib/SDL_string.c
	sdl/src/thread/SDL_systhread.h
	sdl/src/thread/SDL_thread.c
	sdl/src/thread/SDL_thread_c.h
	sdl/src/thread/generic/SDL_syscond.c
	sdl/src/thread/generic/SDL_sysmutex.c
	sdl/src/thread/generic/SDL_sysmutex_c.h
	sdl/src/thread/generic/SDL_syssem.c
	sdl/src/thread/generic/SDL_systhread.c
	sdl/src/thread/generic/SDL_systhread_c.h
	sdl/src/timer/SDL_timer.c
	sdl/src/timer/SDL_timer_c.h
	sdl/src/timer/dummy/SDL_systimer.c
	sdl/src/timer/unix/SDL_systimer.c
	sdl/src/video/SDL_blit.c
	sdl/src/video/SDL_blit.h
	sdl/src/video/SDL_blit_0.c
	sdl/src/video/SDL_blit_1.c
	sdl/src/video/SDL_blit_A.c
	sdl/src/video/SDL_blit_auto.c
	sdl/src/video/SDL_blit_auto.h
	sdl/src/video/SDL_blit_copy.c
	sdl/src/video/SDL_blit_copy.h
	sdl/src/video/SDL_blit_N.c
	sdl/src/video/SDL_blit_slow.c
	sdl/src/video/SDL_blit_slow.h
	sdl/src/video/SDL_bmp.c
	sdl/src/video/SDL_clipboard.c
	sdl/src/video/SDL_fillrect.c
	sdl/src/video/SDL_pixels.c
	sdl/src/video/SDL_pixels_c.h
	sdl/src/video/SDL_rect.c
	sdl/src/video/SDL_rect_c.h
	sdl/src/video/SDL_RLEaccel.c
	sdl/src/video/SDL_RLEaccel_c.h
	sdl/src/video/SDL_shape.c
	sdl/src/video/SDL_shape_internals.h
	sdl/src/video/SDL_stretch.c
	sdl/src/video/SDL_surface.c
	sdl/src/video/SDL_sysvideo.h
	sdl/src/video/SDL_video.c
	sdl/src/video/dummy/SDL_nullevents.c
	sdl/src/video/dummy/SDL_nullevents_c.h
	sdl/src/video/dummy/SDL_nullframebuffer.c
	sdl/src/video/dummy/SDL_nullframebuffer_c.h
	sdl/src/video/dummy/SDL_nullvideo.c
	sdl/src/video/dummy/SDL_nullvideo.h
	)

	##------------------------------------------------
	## sdl_image
	##------------------------------------------------
	SET(SDLIMAGE_SRCS
	sdl_image/SDL_image.h
	sdl_image/IMG.c
	sdl_image/IMG_bmp.c
	sdl_image/IMG_gif.c
	sdl_image/IMG_jpg.c
	sdl_image/IMG_lbm.c
	sdl_image/IMG_pcx.c
	sdl_image/IMG_png.c
	sdl_image/IMG_pnm.c
	sdl_image/IMG_tga.c
	sdl_image/IMG_tif.c
	sdl_image/IMG_webp.c
	sdl_image/IMG_xcf.c
	sdl_image/IMG_xpm.c
	sdl_image/IMG_xv.c
	sdl_image/IMG_xxx.c
	sdl_image/VisualC/Version.rc
	)
	
	##---------------------------------------------
	## png
	##---------------------------------------------
	SET(PNG_SRCS
	sdl_image/external/libpng-1.6.2/png.h
	sdl_image/external/libpng-1.6.2/pngconf.h
	sdl_image/external/libpng-1.6.2/pngpriv.h
	sdl_image/external/libpng-1.6.2/png.c
	sdl_image/external/libpng-1.6.2/pngerror.c
	sdl_image/external/libpng-1.6.2/pngget.c
	sdl_image/external/libpng-1.6.2/pngmem.c
	sdl_image/external/libpng-1.6.2/pngpread.c
	sdl_image/external/libpng-1.6.2/pngread.c
	sdl_image/external/libpng-1.6.2/pngrio.c
	sdl_image/external/libpng-1.6.2/pngrtran.c
	sdl_image/external/libpng-1.6.2/pngrutil.c
	sdl_image/external/libpng-1.6.2/pngset.c
	sdl_image/external/libpng-1.6.2/pngtrans.c
	sdl_image/external/libpng-1.6.2/pngwio.c
	sdl_image/external/libpng-1.6.2/pngwrite.c
	sdl_image/external/libpng-1.6.2/pngwtran.c
	sdl_image/external/libpng-1.6.2/pngwutil.c
	)

	##------------------------------------------------
	## sdl_mixer
	##------------------------------------------------
	SET(SDLMIXER_SRCS
	sdl_mixer/dynamic_flac.c
	sdl_mixer/dynamic_flac.h
	sdl_mixer/dynamic_fluidsynth.c
	sdl_mixer/dynamic_fluidsynth.h
	sdl_mixer/dynamic_mod.c
	sdl_mixer/dynamic_mod.h
	sdl_mixer/dynamic_mp3.c
	sdl_mixer/dynamic_mp3.h
	sdl_mixer/dynamic_ogg.c
	sdl_mixer/dynamic_ogg.h
	sdl_mixer/effect_position.c
	sdl_mixer/effect_stereoreverse.c
	sdl_mixer/effects_internal.c
	sdl_mixer/effects_internal.h
	sdl_mixer/fluidsynth.c
	sdl_mixer/fluidsynth.h
	sdl_mixer/load_aiff.c
	sdl_mixer/load_aiff.h
	sdl_mixer/load_flac.c
	sdl_mixer/load_flac.h
	sdl_mixer/load_ogg.c
	sdl_mixer/load_ogg.h
	sdl_mixer/load_voc.c
	sdl_mixer/load_voc.h
	sdl_mixer/mixer.c
	sdl_mixer/music.c
	sdl_mixer/music_cmd.c
	sdl_mixer/music_cmd.h
	sdl_mixer/music_flac.c
	sdl_mixer/music_flac.h
	sdl_mixer/music_mad.c
	sdl_mixer/music_mad.h
	sdl_mixer/music_mod.c
	sdl_mixer/music_mod.h
	sdl_mixer/music_ogg.c
	sdl_mixer/music_ogg.h
	sdl_mixer/SDL_mixer.h
	sdl_mixer/wavestream.c
	sdl_mixer/wavestream.h
	)

	##-----------------------------------------------
	## zlib
	##-----------------------------------------------
	SET(ZLIB_SRCS
	zlib/zlib.h
	zlib/crc32.h
	zlib/deflate.h
	zlib/gzguts.h
	zlib/inffast.h
	zlib/inffixed.h
	zlib/inflate.h
	zlib/inftrees.h
	zlib/trees.h
	zlib/zconf.h
	zlib/zutil.h
	zlib/adler32.c
	zlib/compress.c
	zlib/crc32.c
	zlib/deflate.c
	zlib/gzclose.c
	zlib/gzlib.c
	zlib/gzread.c
	zlib/gzwrite.c
	zlib/infback.c
	zlib/inffast.c
	zlib/inflate.c
	zlib/inftrees.c
	zlib/trees.c
	zlib/uncompr.c
	zlib/zutil.c
	)

	##------------------------------------------
	## freetype
	##------------------------------------------
	SET(FREETYPE_SRCS
	freetype/src/base/ftsystem.c
	freetype/src/base/ftinit.c
	freetype/src/base/ftdebug.c
	freetype/src/base/ftbase.c
	freetype/src/base/ftbbox.c
	freetype/src/base/ftglyph.c
	freetype/src/truetype/truetype.c
	freetype/src/bdf/bdf.c
	freetype/src/cff/cff.c
	freetype/src/cid/type1cid.c
	freetype/src/pcf/pcf.c
	freetype/src/pfr/pfr.c
	freetype/src/sfnt/sfnt.c
	freetype/src/truetype/truetype.c
	freetype/src/type1/type1.c
	freetype/src/type42/type42.c
	freetype/src/winfonts/winfnt.c
	freetype/src/raster/raster.c
	freetype/src/smooth/smooth.c
	freetype/src/autofit/autofit.c
	freetype/src/psaux/psaux.c
	freetype/src/pshinter/pshinter.c
	freetype/src/psnames/psnames.c
	#freetype/src/gzip/ftgzip.c
	freetype/src/lzw/ftlzw.c
	)

	##------------------------------------------
	## ftgl
	##------------------------------------------
	SET(FTGL_SRCS
	ftgl/src/FTGL/ftgl.h
	ftgl/msvc/config.h
	ftgl/src/FTGL/FTBBox.h
	ftgl/src/FTFont/FTBitmapFontImpl.h
	ftgl/src/FTGL/FTBitmapGlyph.h
	ftgl/src/FTGlyph/FTBitmapGlyphImpl.h
	ftgl/src/FTGL/FTBuffer.h
	ftgl/src/FTGL/FTBufferFont.h
	ftgl/src/FTFont/FTBufferFontImpl.h
	ftgl/src/FTGL/FTBufferGlyph.h
	ftgl/src/FTGlyph/FTBufferGlyphImpl.h
	ftgl/src/FTCharmap.h
	ftgl/src/FTCharToGlyphIndexMap.h
	ftgl/src/FTContour.h
	ftgl/src/FTGL/FTExtrdGlyph.h
	ftgl/src/FTFont/FTExtrudeFontImpl.h
	ftgl/src/FTGlyph/FTExtrudeGlyphImpl.h
	ftgl/src/FTFace.h
	ftgl/src/FTGL/FTFont.h
	ftgl/src/FTFont/FTFontImpl.h
	ftgl/src/FTGL/FTGLBitmapFont.h
	ftgl/src/FTGL/FTGLExtrdFont.h
	ftgl/src/FTGL/FTGLOutlineFont.h
	ftgl/src/FTGL/FTGLPixmapFont.h
	ftgl/src/FTGL/FTGLPolygonFont.h
	ftgl/src/FTGL/FTGLTextureFont.h
	ftgl/src/FTGL/FTGlyph.h
	ftgl/src/FTGlyphContainer.h
	ftgl/src/FTGlyph/FTGlyphImpl.h
	ftgl/src/FTInternals.h
	ftgl/src/FTGL/FTLayout.h
	ftgl/src/FTLayout/FTLayoutImpl.h
	ftgl/src/FTLibrary.h
	ftgl/src/FTList.h
	ftgl/src/FTFont/FTOutlineFontImpl.h
	ftgl/src/FTGL/FTOutlineGlyph.h
	ftgl/src/FTGlyph/FTOutlineGlyphImpl.h
	ftgl/src/FTFont/FTPixmapFontImpl.h
	ftgl/src/FTGL/FTPixmapGlyph.h
	ftgl/src/FTGlyph/FTPixmapGlyphImpl.h
	ftgl/src/FTGL/FTPoint.h
	ftgl/src/FTGL/FTPolyGlyph.h
	ftgl/src/FTFont/FTPolygonFontImpl.h
	ftgl/src/FTGlyph/FTPolygonGlyphImpl.h
	ftgl/src/FTGL/FTSimpleLayout.h
	ftgl/src/FTLayout/FTSimpleLayoutImpl.h
	ftgl/src/FTSize.h
	ftgl/src/FTFont/FTTextureFontImpl.h
	ftgl/src/FTGL/FTTextureGlyph.h
	ftgl/src/FTGlyph/FTTextureGlyphImpl.h
	ftgl/src/FTUnicode.h
	ftgl/src/FTVector.h
	ftgl/src/FTVectoriser.h
	ftgl/src/FTFont/FTBitmapFont.cpp
	ftgl/src/FTGlyph/FTBitmapGlyph.cpp
	ftgl/src/FTBuffer.cpp
	ftgl/src/FTFont/FTBufferFont.cpp
	ftgl/src/FTGlyph/FTBufferGlyph.cpp
	ftgl/src/FTCharmap.cpp
	ftgl/src/FTContour.cpp
	ftgl/src/FTFont/FTExtrudeFont.cpp
	ftgl/src/FTGlyph/FTExtrudeGlyph.cpp
	ftgl/src/FTFace.cpp
	ftgl/src/FTFont/FTFont.cpp
	ftgl/src/FTFont/FTFontGlue.cpp
	ftgl/src/FTGlyph/FTGlyph.cpp
	ftgl/src/FTGlyphContainer.cpp
	ftgl/src/FTGlyph/FTGlyphGlue.cpp
	ftgl/src/FTLayout/FTLayout.cpp
	ftgl/src/FTLayout/FTLayoutGlue.cpp
	ftgl/src/FTLibrary.cpp
	ftgl/src/FTFont/FTOutlineFont.cpp
	ftgl/src/FTGlyph/FTOutlineGlyph.cpp
	ftgl/src/FTFont/FTPixmapFont.cpp
	ftgl/src/FTGlyph/FTPixmapGlyph.cpp
	ftgl/src/FTPoint.cpp
	ftgl/src/FTFont/FTPolygonFont.cpp
	ftgl/src/FTGlyph/FTPolygonGlyph.cpp
	ftgl/src/FTLayout/FTSimpleLayout.cpp
	ftgl/src/FTSize.cpp
	ftgl/src/FTFont/FTTextureFont.cpp
	ftgl/src/FTGlyph/FTTextureGlyph.cpp
	ftgl/src/FTVectoriser.cpp
	)


	##------------------------------------------
	## 3ds
	##------------------------------------------
	SET(3DS_SRCS
	3ds/src/lib3ds.h
	#3ds/src/lib3ds.rc
	3ds/src/lib3ds_atmosphere.c
	3ds/src/lib3ds_background.c
	3ds/src/lib3ds_camera.c
	3ds/src/lib3ds_chunk.c
	3ds/src/lib3ds_chunktable.c
	3ds/src/lib3ds_file.c
	3ds/src/lib3ds_impl.h
	3ds/src/lib3ds_io.c
	3ds/src/lib3ds_light.c
	3ds/src/lib3ds_material.c
	3ds/src/lib3ds_math.c
	3ds/src/lib3ds_matrix.c
	3ds/src/lib3ds_mesh.c
	3ds/src/lib3ds_node.c
	3ds/src/lib3ds_quat.c
	3ds/src/lib3ds_shadow.c
	3ds/src/lib3ds_track.c
	3ds/src/lib3ds_util.c
	3ds/src/lib3ds_vector.c
	3ds/src/lib3ds_viewport.c
	)

	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR})
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/digitalknob)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/sdl/include)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/sdl_image)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/sdl_image/external/libpng-1.6.2)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/sdl_mixer)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/libpng)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/zlib)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/freetype/include)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/ftgl)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/ftgl/src/)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/3ds/src/)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/zlib)

	ADD_DEFINITIONS(-DLINUX)
	ADD_DEFINITIONS(-DFTGL_LIBRARY_STATIC)
	ADD_DEFINITIONS(-DHAVE_STDINT_H)

	### digitalknob ###
	FIND_LIBRARY(dkd dkd ${DKLIBS_SOURCE_DIR}/bin/LINUX/Debug)
	FIND_LIBRARY(dk dk ${DKLIBS_SOURCE_DIR}/bin/LINUX/Release)
	
	### sdl ###
	FIND_LIBRARY(sdld sdld ${DKLIBS_SOURCE_DIR}/bin/LINUX/Debug)
	FIND_LIBRARY(sdl sdl ${DKLIBS_SOURCE_DIR}/bin/LINUX/Release)
	
	### sdl_image ###
	FIND_LIBRARY(sdlimaged sdlimaged ${DKLIBS_SOURCE_DIR}/bin/LINUX/Debug)
	FIND_LIBRARY(sdlimage sdlimage ${DKLIBS_SOURCE_DIR}/bin/LINUX/Release)
	
	### sdl_mixer ###
	FIND_LIBRARY(sdlmixerd sdlmixerd ${DKLIBS_SOURCE_DIR}/bin/LINUX/Debug)
	FIND_LIBRARY(sdlmixer sdlmixer ${DKLIBS_SOURCE_DIR}/bin/LINUX/Release)

	### zlib ###
	FIND_LIBRARY(zlibd zlibd ${DKLIBS_SOURCE_DIR}/bin/LINUX/Debug)
	FIND_LIBRARY(zlib zlib ${DKLIBS_SOURCE_DIR}/bin/LINUX/Release)

	### png ###
	FIND_LIBRARY(pngd pngd ${DKLIBS_SOURCE_DIR}/bin/LINUX/Debug)
	FIND_LIBRARY(png png ${DKLIBS_SOURCE_DIR}/bin/LINUX/Release)
	
	### freetype ###
	FIND_LIBRARY(freetyped freetyped ${DKLIBS_SOURCE_DIR}/bin/LINUX/Debug)
	FIND_LIBRARY(freetype freetype ${DKLIBS_SOURCE_DIR}/bin/LINUX/Release)
	
	### ftgl ###
	FIND_LIBRARY(ftgld ftgld ${DKLIBS_SOURCE_DIR}/bin/LINUX/Debug)
	FIND_LIBRARY(ftgl ftgl ${DKLIBS_SOURCE_DIR}/bin/LINUX/Release)

	### 3ds ###
	FIND_LIBRARY(3dsd 3dsd ${DKLIBS_SOURCE_DIR}/bin/LINUX/Debug)
	FIND_LIBRARY(3ds 3ds ${DKLIBS_SOURCE_DIR}/bin/LINUX/Release)

	### digitalknob ###
	ADD_LIBRARY(libdk STATIC ${DIGITALKNOB_SRC})
	SET_TARGET_PROPERTIES(libdk PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME dk DEBUG_OUTPUT_NAME dkd)
	SET_TARGET_PROPERTIES(libdk PROPERTIES COMPILE_DEFINITIONS LINUX)
	
	### sdl library ###
	ADD_LIBRARY(libsdl STATIC ${SDL_SRCS})
	SET_TARGET_PROPERTIES(libsdl PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME sdl DEBUG_OUTPUT_NAME sdld)
	SET_TARGET_PROPERTIES(libsdl PROPERTIES COMPILE_DEFINITIONS LINUX,HAVE_STDINT_H)

	### sdl_image library ###
	ADD_LIBRARY(libsdlimage STATIC ${SDLIMAGE_SRCS})
	SET_TARGET_PROPERTIES(libsdlimage PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME sdlimage DEBUG_OUTPUT_NAME sdlimaged)
	SET_TARGET_PROPERTIES(libsdlimage PROPERTIES COMPILE_DEFINITIONS LINUX,LOAD_BMP,LOAD_GIF,LOAD_LBM,LOAD_PCX,LOAD_PNG,LOAD_PNM,LOAD_TGA,LOAD_XPM,LOAD_XV)

	### sdl_mixer library ###
	ADD_LIBRARY(libsdlmixer STATIC ${SDLMIXER_SRCS})
	SET_TARGET_PROPERTIES(libsdlmixer PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME sdlmixer DEBUG_OUTPUT_NAME sdlmixerd)
	SET_TARGET_PROPERTIES(libsdlmixer PROPERTIES COMPILE_DEFINITIONS LINUX,_WINDOWS,WAV_MUSIC,MID_MUSIC)
	
	### zlib library ###
	ADD_LIBRARY(libzlib STATIC ${ZLIB_SRCS})
	SET_TARGET_PROPERTIES(libzlib PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME zlib DEBUG_OUTPUT_NAME zlibd)
	SET_TARGET_PROPERTIES(libzlib PROPERTIES COMPILE_DEFINITIONS NO_FSEEKO)

	### png library ###
	ADD_LIBRARY(libpng STATIC ${PNG_SRCS})
	SET_TARGET_PROPERTIES(libpng PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME png DEBUG_OUTPUT_NAME pngd)
	SET_TARGET_PROPERTIES(libpng PROPERTIES COMPILE_DEFINITIONS LINUX)

	### freetype library ###
	ADD_LIBRARY(libfreetype STATIC ${FREETYPE_SRCS})
	SET_TARGET_PROPERTIES(libfreetype PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME freetype DEBUG_OUTPUT_NAME freetyped)
	SET_TARGET_PROPERTIES(libfreetype PROPERTIES COMPILE_DEFINITIONS LINUX,_LIB,FT2_BUILD_LIBRARY)
	
	### ftgl library ###
	ADD_LIBRARY(libftgl STATIC ${FTGL_SRCS})
	SET_TARGET_PROPERTIES(libftgl PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME ftgl DEBUG_OUTPUT_NAME ftgld)
	SET_TARGET_PROPERTIES(libftgl PROPERTIES COMPILE_DEFINITIONS LINUX,FTGL_LIBRARY_STATIC)
	
	### 3ds library ###
	ADD_LIBRARY(lib3ds STATIC ${3DS_SRCS})
	SET_TARGET_PROPERTIES(lib3ds PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME 3ds DEBUG_OUTPUT_NAME 3dsd)
	SET_TARGET_PROPERTIES(lib3ds PROPERTIES COMPILE_DEFINITIONS LINUX,LIB3DS_STATIC)
	
ENDIF(LINUX)


##----------------------------------------
##       ###### IOS ######
##----------------------------------------
IF(IOS)
	MESSAGE(STATUS "Detected MAC environment")
	MESSAGE("Creating IOS Project Files")
	
	SET(EXECUTABLE_OUTPUT_PATH ${DKLIBS_SOURCE_DIR}/bin/IOS)
	SET(LIBRARY_OUTPUT_PATH ${DKLIBS_SOURCE_DIR}/bin/IOS)
	
	##------------------------------------------
	## digitalknob
	##------------------------------------------
	SET(DIGITALKNOB_SRC
	digitalknob/arial.h
	digitalknob/DK.h
	digitalknob/DKDebug.h
	digitalknob/DKDebug.cpp
	digitalknob/DKFile.h
	digitalknob/DKFile.cpp
	digitalknob/DKObject.h
	digitalknob/DKObject.cpp
	digitalknob/DKObjectManager.h
	digitalknob/DKObjectManager.cpp
	digitalknob/DKEvent.h
	digitalknob/DKEvent.cpp
	digitalknob/DKFrame.h
	digitalknob/DKFrame.cpp
	digitalknob/DKWindow.h
	digitalknob/DKWindow.cpp
	digitalknob/DKPanel.h
	digitalknob/DKPanel.cpp
	digitalknob/DKAudio.h
	digitalknob/DKAudio.cpp
	digitalknob/DKFont.h
	digitalknob/DKFont.cpp
	digitalknob/DKTexture.h
	digitalknob/DKTexture.cpp
	digitalknob/DKText.h
	digitalknob/DKText.cpp
	digitalknob/DKImage.h
	digitalknob/DKImage.cpp
	digitalknob/DKSquare.h
	digitalknob/DKSquare.cpp
	digitalknob/DKTriangle.h
	digitalknob/DKTriangle.cpp
	digitalknob/DKCircle.h
	digitalknob/DKCircle.cpp
	digitalknob/DKLine.h
	digitalknob/DKLine.cpp
	digitalknob/DKXyz.h
	digitalknob/DKXyz.cpp
	digitalknob/DKCube.h
	digitalknob/DKCube.cpp
	digitalknob/DKButton.h
	digitalknob/DKButton.cpp
	digitalknob/DKTextBox.h
	digitalknob/DKTextBox.cpp
	digitalknob/DKTextButton.h
	digitalknob/DKTextButton.cpp
	digitalknob/DKToggle.h
	digitalknob/DKToggle.cpp
	digitalknob/DKListBox.h
	digitalknob/DKListBox.cpp
	digitalknob/DKSlider.h
	digitalknob/DKSlider.cpp
	digitalknob/DKFps.h
	digitalknob/DKFps.cpp
	digitalknob/DKAnimate.h
	digitalknob/DKAnimate.cpp
	digitalknob/DKCamera.h
	digitalknob/DKCamera.cpp
	digitalknob/DKMessage.h
	digitalknob/DKMessage.cpp
	digitalknob/DKFileDialog.h
	digitalknob/DKFileDialog.cpp
	digitalknob/DK3ds.h
	digitalknob/DK3ds.cpp
	digitalknob/DKString.h
	digitalknob/DKString.cpp
	digitalknob/DKZip.h
	digitalknob/DKZip.cpp
	digitalknob/DKOsInfo.h
	digitalknob/DKOsInfo.cpp
	digitalknob/DKMenuBar.h
	digitalknob/DKMenuBar.cpp
	digitalknob/DKDropDown.h
	digitalknob/DKDropDown.cpp
	digitalknob/DKColorPicker.h
	digitalknob/DKColorPicker.cpp
	digitalknob/DKColor.h
	digitalknob/DKColor.cpp
	digitalknob/DKAxis.h
	digitalknob/DKAxis.cpp
	digitalknob/DKTextEdit.h
	digitalknob/DKTextEdit.cpp
	digitalknob/DKKeyboard.h
	digitalknob/DKKeyboard.cpp
	digitalknob/DKFrameBase.h
	digitalknob/DKFrameBase.cpp
	digitalknob/DKOpengl.h
	digitalknob/DKScrollBar.h
	digitalknob/DKScrollBar.cpp
	digitalknob/DKGlobal.h
	digitalknob/DKGlobal.cpp
	digitalknob/DKScrollPanel.h
	digitalknob/DKScrollPanel.cpp
	)

	##------------------------------------------------
	##  sdl
	##------------------------------------------------
	SET(SDL_SRCS
	sdl/include/begin_code.h
	sdl/include/close_code.h
	sdl/include/SDL.h
	sdl/include/SDL_assert.h
	sdl/include/SDL_atomic.h
	sdl/include/SDL_audio.h
	sdl/include/SDL_bits.h
	sdl/include/SDL_blendmode.h
	sdl/include/SDL_clipboard.h
	sdl/include/SDL_config.h
	sdl/include/SDL_config_iphoneos.h
	sdl/include/SDL_copying.h
	sdl/include/SDL_cpuinfo.h
	sdl/include/SDL_endian.h
	sdl/include/SDL_error.h
	sdl/include/SDL_events.h
	sdl/include/SDL_gamecontroller.h
	sdl/include/SDL_gesture.h
	sdl/include/SDL_haptic.h
	sdl/include/SDL_hints.h
	sdl/include/SDL_joystick.h
	sdl/include/SDL_keyboard.h
	sdl/include/SDL_keycode.h
	sdl/include/SDL_loadso.h
	sdl/include/SDL_log.h
	sdl/include/SDL_main.h
	sdl/include/SDL_messagebox.h
	sdl/include/SDL_mouse.h
	sdl/include/SDL_mutex.h
	sdl/include/SDL_name.h
	sdl/include/SDL_opengl.h
	sdl/include/SDL_opengles.h
	sdl/include/SDL_opengles2.h
	sdl/include/SDL_pixels.h
	sdl/include/SDL_platform.h
	sdl/include/SDL_power.h
	sdl/include/SDL_quit.h
	sdl/include/SDL_rect.h
	sdl/include/SDL_render.h
	sdl/include/SDL_revision.h
	sdl/include/SDL_rwops.h
	sdl/include/SDL_scancode.h
	sdl/include/SDL_shape.h
	sdl/include/SDL_stdinc.h
	sdl/include/SDL_surface.h
	sdl/include/SDL_system.h
	sdl/include/SDL_syswm.h
	sdl/include/SDL_thread.h
	sdl/include/SDL_timer.h
	sdl/include/SDL_touch.h
	sdl/include/SDL_types.h
	sdl/include/SDL_version.h
	sdl/include/SDL_video.h
	sdl/src/atomic/SDL_atomic.c
	sdl/src/atomic/SDL_spinlock.c
	sdl/src/audio/coreaudio/SDL_coreaudio.c
	sdl/src/audio/coreaudio/SDL_coreaudio.h
	sdl/src/audio/dummy/SDL_dummyaudio.c
	sdl/src/audio/dummy/SDL_dummyaudio.h
	sdl/src/audio/SDL_audio.c
	sdl/src/audio/SDL_audio_c.h
	sdl/src/audio/SDL_audiocvt.c
	sdl/src/audio/SDL_audiomem.h
	sdl/src/audio/SDL_audiotypecvt.c
	sdl/src/audio/SDL_mixer.c
	sdl/src/audio/SDL_sysaudio.h
	sdl/src/audio/SDL_wave.c
	sdl/src/audio/SDL_wave.h
	sdl/src/cpuinfo/SDL_cpuinfo.c
	sdl/src/events/blank_cursor.h
	sdl/src/events/default_cursor.h
	sdl/src/events/scancodes_darwin.h
	sdl/src/events/scancodes_linux.h
	sdl/src/events/scancodes_xfree86.h
	sdl/src/events/SDL_clipboardevents_c.h
	sdl/src/events/SDL_clipboardevents.c
	sdl/src/events/SDL_dropevents.c
	sdl/src/events/SDL_dropevents_c.h
	sdl/src/events/SDL_events.c
	sdl/src/events/SDL_events_c.h
	sdl/src/events/SDL_gesture.c
	sdl/src/events/SDL_gesture_c.h
	sdl/src/events/SDL_keyboard.c
	sdl/src/events/SDL_keyboard_c.h
	sdl/src/events/SDL_mouse.c
	sdl/src/events/SDL_mouse_c.h
	sdl/src/events/SDL_quit.c
	sdl/src/events/SDL_sysevents.h
	sdl/src/events/SDL_touch.c
	sdl/src/events/SDL_touch_c.h
	sdl/src/events/SDL_windowevents.c
	sdl/src/events/SDL_windowevents_c.h
	sdl/src/file/cocoa/SDL_rwopsbundlesupport.h
	sdl/src/file/cocoa/SDL_rwopsbundlesupport.m
	sdl/src/file/SDL_rwops.c
	sdl/src/haptic/dummy/SDL_syshaptic.c
	sdl/src/haptic/SDL_haptic.c
	sdl/src/haptic/SDL_syshaptic.h
	sdl/src/joystick/iphoneos/SDL_sysjoystick.m
	sdl/src/joystick/iphoneos/SDLUIAccelerationDelegate.h
	sdl/src/joystick/iphoneos/SDLUIAccelerationDelegate.m
	sdl/src/joystick/SDL_gamecontroller.c
	sdl/src/joystick/SDL_joystick.c
	sdl/src/joystick/SDL_joystick_c.h
	sdl/src/joystick/SDL_sysjoystick.h
	sdl/src/loadso/dummy/SDL_sysloadso.c
	sdl/src/loadso/dlopen/SDL_sysloadso.c
	sdl/src/power/SDL_power.c
	sdl/src/power/uikit/SDL_syspower.m
	sdl/src/render/opengles/SDL_render_gles.c
	sdl/src/render/opengles2/SDL_render_gles2.c
	sdl/src/render/opengles2/SDL_shaders_gles2.c
	sdl/src/render/opengles2/SDL_shaders_gles2.h
	sdl/src/render/software/SDL_blendfillrect.c
	sdl/src/render/software/SDL_blendfillrect.h
	sdl/src/render/software/SDL_blendline.c
	sdl/src/render/software/SDL_blendline.h
	sdl/src/render/software/SDL_blendpoint.c
	sdl/src/render/software/SDL_blendpoint.h
	sdl/src/render/software/SDL_draw.h
	sdl/src/render/software/SDL_drawline.c
	sdl/src/render/software/SDL_drawline.h
	sdl/src/render/software/SDL_drawpoint.c
	sdl/src/render/software/SDL_drawpoint.c
	sdl/src/render/software/SDL_render_sw_c.h
	sdl/src/render/software/SDL_render_sw.c
	sdl/src/render/software/SDL_rotate.c
	sdl/src/render/software/SDL_rotate.h
	sdl/src/render/mmx.h
	sdl/src/render/SDL_render.c
	sdl/src/render/SDL_sysrender.h
	sdl/src/render/SDL_yuv_mmx.c
	sdl/src/render/SDL_yuv_sw_c.h
	sdl/src/render/SDL_yuv_sw.c
	sdl/src/stdlib/SDL_getenv.c
	sdl/src/stdlib/SDL_iconv.c
	sdl/src/stdlib/SDL_malloc.c
	sdl/src/stdlib/SDL_qsort.c
	sdl/src/stdlib/SDL_stdlib.c
	sdl/src/stdlib/SDL_string.c
	sdl/src/thread/pthread/SDL_syscond.c
	sdl/src/thread/pthread/SDL_sysmutex.c
	sdl/src/thread/pthread/SDL_sysmutex_c.h
	sdl/src/thread/pthread/SDL_syssem.c
	sdl/src/thread/pthread/SDL_systhread.c
	sdl/src/thread/pthread/SDL_systhread_c.h
	sdl/src/thread/pthread/SDL_systls.c
	sdl/src/thread/SDL_systhread.h
	sdl/src/thread/SDL_thread.c
	sdl/src/thread/SDL_thread_c.h
	sdl/src/timer/unix/SDL_systimer.c
	sdl/src/timer/SDL_timer.c
	sdl/src/timer/SDL_timer_c.h
	sdl/src/video/uikit/keyinfotable.h
	sdl/src/video/uikit/SDL_uikitappdelegate.h
	sdl/src/video/uikit/SDL_uikitappdelegate.m
	sdl/src/video/uikit/SDL_uikitevents.h
	sdl/src/video/uikit/SDL_uikitevents.m
	sdl/src/video/uikit/SDL_uikitmessagebox.h
	sdl/src/video/uikit/SDL_uikitmessagebox.m
	sdl/src/video/uikit/SDL_uikitmodes.h
	sdl/src/video/uikit/SDL_uikitmodes.m
	sdl/src/video/uikit/SDL_uikitopengles.h
	sdl/src/video/uikit/SDL_uikitopengles.m
	sdl/src/video/uikit/SDL_uikitopenglview.h
	sdl/src/video/uikit/SDL_uikitopenglview.m
	sdl/src/video/uikit/SDL_uikitvideo.h
	sdl/src/video/uikit/SDL_uikitvideo.m
	sdl/src/video/uikit/SDL_uikitview.h
	sdl/src/video/uikit/SDL_uikitview.m
	sdl/src/video/uikit/SDL_uikitviewcontroller.h
	sdl/src/video/uikit/SDL_uikitviewcontroller.m
	sdl/src/video/uikit/SDL_uikitwindow.h
	sdl/src/video/uikit/SDL_uikitwindow.m
	sdl/src/video/dummy/SDL_nullevents.c
	sdl/src/video/dummy/SDL_nullevents_c.h
	sdl/src/video/dummy/SDL_nullframebuffer_c.h
	sdl/src/video/dummy/SDL_nullframebuffer.c
	sdl/src/video/dummy/SDL_nullvideo.c
	sdl/src/video/dummy/SDL_nullvideo.h
	sdl/src/video/SDL_blit.c
	sdl/src/video/SDL_blit.h
	sdl/src/video/SDL_blit_0.c
	sdl/src/video/SDL_blit_1.c
	sdl/src/video/SDL_blit_A.c
	sdl/src/video/SDL_blit_auto.c
	sdl/src/video/SDL_blit_auto.h
	sdl/src/video/SDL_blit_copy.c
	sdl/src/video/SDL_blit_copy.h
	sdl/src/video/SDL_blit_N.c
	sdl/src/video/SDL_blit_slow.c
	sdl/src/video/SDL_blit_slow.h
	sdl/src/video/SDL_bmp.c
	sdl/src/video/SDL_clipboard.c
	sdl/src/video/SDL_fillrect.c
	sdl/src/video/SDL_pixels.c
	sdl/src/video/SDL_pixels_c.h
	sdl/src/video/SDL_rect.c
	sdl/src/video/SDL_RLEaccel.c
	sdl/src/video/SDL_RLEaccel_c.h
	sdl/src/video/SDL_stretch.c
	sdl/src/video/SDL_surface.c
	sdl/src/video/SDL_sysvideo.h
	sdl/src/video/SDL_video.c
	sdl/src/SDL_assert.c
	sdl/src/SDL_assert_c.h
	sdl/src/SDL_error_c.h
	sdl/src/SDL_error.c
	sdl/src/SDL_fatal.c
	sdl/src/SDL_fatal.h
	sdl/src/SDL_hints.c
	sdl/src/SDL_log.c
	sdl/src/SDL.c
	)

	##------------------------------------------------
	##  sdl_image
	##------------------------------------------------
	SET(SDLIMAGE_SRCS
	sdl_image/SDL_image.h
	sdl_image/IMG.c
	sdl_image/IMG_bmp.c
	sdl_image/IMG_gif.c
	sdl_image/IMG_jpg.c
	sdl_image/IMG_lbm.c
	sdl_image/IMG_pcx.c
	sdl_image/IMG_png.c
	sdl_image/IMG_pnm.c
	sdl_image/IMG_tga.c
	sdl_image/IMG_tif.c
	sdl_image/IMG_webp.c
	sdl_image/IMG_xcf.c
	sdl_image/IMG_xpm.c
	sdl_image/IMG_xv.c
	sdl_image/IMG_xxx.c
	sdl_image/IMG_imageIO.m
	)
	
	##---------------------------------------------
	## png
	##---------------------------------------------
	SET(PNG_SRCS
	sdl_image/external/libpng-1.6.2/png.h
	sdl_image/external/libpng-1.6.2/pngconf.h
	sdl_image/external/libpng-1.6.2/pngpriv.h
	sdl_image/external/libpng-1.6.2/png.c
	sdl_image/external/libpng-1.6.2/pngerror.c
	sdl_image/external/libpng-1.6.2/pngget.c
	sdl_image/external/libpng-1.6.2/pngmem.c
	sdl_image/external/libpng-1.6.2/pngpread.c
	sdl_image/external/libpng-1.6.2/pngread.c
	sdl_image/external/libpng-1.6.2/pngrio.c
	sdl_image/external/libpng-1.6.2/pngrtran.c
	sdl_image/external/libpng-1.6.2/pngrutil.c
	sdl_image/external/libpng-1.6.2/pngset.c
	sdl_image/external/libpng-1.6.2/pngtrans.c
	sdl_image/external/libpng-1.6.2/pngwio.c
	sdl_image/external/libpng-1.6.2/pngwrite.c
	sdl_image/external/libpng-1.6.2/pngwtran.c
	sdl_image/external/libpng-1.6.2/pngwutil.c
	)

	##------------------------------------------------
	## sdl_mixer
	##------------------------------------------------
	SET(SDLMIXER_SRCS
	sdl_mixer/dynamic_flac.c
	sdl_mixer/dynamic_flac.h
	sdl_mixer/dynamic_fluidsynth.c
	sdl_mixer/dynamic_fluidsynth.h
	sdl_mixer/dynamic_mod.c
	sdl_mixer/dynamic_mod.h
	sdl_mixer/dynamic_mp3.c
	sdl_mixer/dynamic_mp3.h
	sdl_mixer/dynamic_ogg.c
	sdl_mixer/dynamic_ogg.h
	sdl_mixer/effect_position.c
	sdl_mixer/effect_stereoreverse.c
	sdl_mixer/effects_internal.c
	sdl_mixer/effects_internal.h
	sdl_mixer/fluidsynth.c
	sdl_mixer/fluidsynth.h
	sdl_mixer/load_aiff.c
	sdl_mixer/load_aiff.h
	sdl_mixer/load_flac.c
	sdl_mixer/load_flac.h
	sdl_mixer/load_ogg.c
	sdl_mixer/load_ogg.h
	sdl_mixer/load_voc.c
	sdl_mixer/load_voc.h
	sdl_mixer/mixer.c
	sdl_mixer/music.c
	sdl_mixer/music_cmd.c
	sdl_mixer/music_cmd.h
	sdl_mixer/music_flac.c
	sdl_mixer/music_flac.h
	sdl_mixer/music_mad.c
	sdl_mixer/music_mad.h
	sdl_mixer/music_mod.c
	sdl_mixer/music_mod.h
	sdl_mixer/music_modplug.c
	sdl_mixer/music_modplug.h
	sdl_mixer/music_ogg.c
	sdl_mixer/music_ogg.h
	sdl_mixer/SDL_mixer.h
	sdl_mixer/wavestream.c
	sdl_mixer/wavestream.h
	)

	##-----------------------------------------------
	## zlib
	##-----------------------------------------------
	SET(ZLIB_SRCS
	zlib/zlib.h
	zlib/crc32.h
	zlib/deflate.h
	zlib/gzguts.h
	zlib/inffast.h
	zlib/inffixed.h
	zlib/inflate.h
	zlib/inftrees.h
	zlib/trees.h
	zlib/zconf.h
	zlib/zutil.h
	zlib/adler32.c
	zlib/compress.c
	zlib/crc32.c
	zlib/deflate.c
	zlib/gzclose.c
	zlib/gzlib.c
	zlib/gzread.c
	zlib/gzwrite.c
	zlib/infback.c
	zlib/inffast.c
	zlib/inflate.c
	zlib/inftrees.c
	zlib/trees.c
	zlib/uncompr.c
	zlib/zutil.c
	)

	##------------------------------------------
	## freetype
	##------------------------------------------
	SET(FREETYPE_SRCS
	freetype/src/autofit/autofit.c
	freetype/src/base/basepic.c
	freetype/src/base/ftapi.c
	freetype/src/base/ftbase.c
	freetype/src/base/ftbbox.c
	freetype/src/base/ftbitmap.c
	freetype/src/base/ftdbgmem.c
	freetype/src/base/ftdebug.c
	freetype/src/base/ftglyph.c
	freetype/src/base/ftinit.c
	freetype/src/base/ftpic.c
	freetype/src/base/ftstroke.c
	freetype/src/base/ftsynth.c
	freetype/src/base/ftsystem.c
	freetype/src/psnames/psnames.c
	freetype/src/cff/cff.c
	freetype/src/pshinter/pshinter.c
	freetype/src/raster/raster.c
	freetype/src/sfnt/sfnt.c
	freetype/src/smooth/smooth.c
	freetype/src/truetype/truetype.c
	freetype/src/bdf/bdf.c
	freetype/src/cid/type1cid.c
	freetype/src/type1/type1.c
	freetype/src/pfr/pfr.c
	freetype/src/winfonts/winfnt.c
	freetype/src/pcf/pcf.c
	freetype/src/psaux/psaux.c
	freetype/src/type42/type42.c
	freetype/src/gzip/ftgzip.c
	freetype/src/lzw/ftlzw.c
	)

	##------------------------------------------
	## ftgles
	##------------------------------------------
	SET(FTGLES_SRCS
	ftgles/src/FTBuffer.cpp
	ftgles/src/FTCharmap.cpp
	ftgles/src/FTContour.cpp
	ftgles/src/FTFace.cpp
	ftgles/src/FTFont/FTBitmapFont.cpp
	ftgles/src/FTFont/FTBufferFont.cpp
	ftgles/src/FTFont/FTFont.cpp
	ftgles/src/FTFont/FTFontGlue.cpp
	ftgles/src/FTFont/FTOutlineFont.cpp
	ftgles/src/FTFont/FTPixmapFont.cpp
	ftgles/src/FTFont/FTPolygonFont.cpp
	ftgles/src/FTFont/FTTextureFont.cpp
	ftgles/src/FTGL/ftglesGlue.cpp
	ftgles/src/FTGlyph/FTBitmapGlyph.cpp
	ftgles/src/FTGlyph/FTBufferGlyph.cpp
	ftgles/src/FTGlyph/FTGlyph.cpp
	ftgles/src/FTGlyph/FTGlyphGlue.cpp
	ftgles/src/FTGlyph/FTOutlineGlyph.cpp
	ftgles/src/FTGlyph/FTPixmapGlyph.cpp
	ftgles/src/FTGlyph/FTPolygonGlyph.cpp
	ftgles/src/FTGlyph/FTTextureGlyph.cpp
	ftgles/src/FTGlyphContainer.cpp
	ftgles/src/FTLayout/FTLayout.cpp
	ftgles/src/FTLayout/FTLayoutGlue.cpp
	ftgles/src/FTLayout/FTSimpleLayout.cpp
	ftgles/src/FTLibrary.cpp
	ftgles/src/FTPoint.cpp
	ftgles/src/FTSize.cpp
	ftgles/src/FTVectoriser.cpp
	ftgles/src/iGLU-1.0.0/libtess/dict.c
	ftgles/src/iGLU-1.0.0/libtess/geom.c
	ftgles/src/iGLU-1.0.0/libtess/memalloc.c
	ftgles/src/iGLU-1.0.0/libtess/mesh.c
	ftgles/src/iGLU-1.0.0/libtess/normal.c
	ftgles/src/iGLU-1.0.0/libtess/priorityq.c
	ftgles/src/iGLU-1.0.0/libtess/render.c
	ftgles/src/iGLU-1.0.0/libtess/sweep.c
	ftgles/src/iGLU-1.0.0/libtess/tess.c
	ftgles/src/iGLU-1.0.0/libtess/tessmono.c
	ftgles/src/iGLU-1.0.0/libutil/error.c
	ftgles/src/iGLU-1.0.0/libutil/glue.c
	ftgles/src/iGLU-1.0.0/libutil/project.c
	ftgles/src/iGLU-1.0.0/libutil/registry.c
	)

	ADD_DEFINITIONS(-DIOS)
	ADD_DEFINITIONS(-D__IPHONEOS__)
	#ADD_DEFINITIONS(-DSDL_IPHONE_KEYBOARD)

	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR})
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/digitalknob)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/sdl/include )
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/sdl/src/events )
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/sdl/src/video )
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/sdl_image)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/sdl_image/external/libpng-1.6.2)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/sdl_mixer)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/libpng)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/zlib)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/freetype/include)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/ftgles/)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/ftgles/src)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/ftgles/src/iGLU-1.0.0/include)
	INCLUDE_DIRECTORIES(${DKLIBS_SOURCE_DIR}/3ds/src)
	INCLUDE_DIRECTORIES(/usr/X11/include)	
	
	set(IOS_FRAMEWORKS
		Foundation
		AudioToolbox
		CoreGraphics
	   	QuartzCore
		UIKit
	    OpenGLES
		ImageIO
		MobileCoreServices
	)

	SET(CMAKE_OSX_SYSROOT iphonesimulator6.1)
	SET(CMAKE_OSK_ARCHITECTURES "$(ARCHS_STANDARD_32_BIT)")
	SET(CMAKE_CXX_FLAGS "-x objective-c++")
	foreach(FW ${IOS_FRAMEWORKS})
		set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework ${FW}")
	endforeach()
	
	SET(MACOSX_BUNDLE_GUI_IDENTIFIER "com.digitalknob.\${PRODUCT_NAME:identifier}")
	
	### digitalknob ###
	FIND_LIBRARY(dkd dkd ${DKLIBS_SOURCE_DIR}/bin/IOS/Debug)
	FIND_LIBRARY(dk dk ${DKLIBS_SOURCE_DIR}/bin/IOS/Release)
	
	### sdl ###
	FIND_LIBRARY(sdld sdld ${DKLIBS_SOURCE_DIR}/bin/IOS/Debug)
	FIND_LIBRARY(sdl sdl ${DKLIBS_SOURCE_DIR}/bin/IOS/Release)

	### sdl_image ###
	FIND_LIBRARY(sdlimaged sdlimaged ${DKLIBS_SOURCE_DIR}/bin/IOS/Debug)
	FIND_LIBRARY(sdlimage sdlimage ${DKLIBS_SOURCE_DIR}/bin/IOS/Release)
	
	### sdl_mixer ###
	FIND_LIBRARY(sdlmixerd sdlmixerd ${DKLIBS_SOURCE_DIR}/bin/IOS/Debug)
	FIND_LIBRARY(sdlmixer sdlmixer ${DKLIBS_SOURCE_DIR}/bin/IOS/Release)

	### zlib ###
	FIND_LIBRARY(zlibd zlibd ${DKLIBS_SOURCE_DIR}/bin/IOS/Debug)
	FIND_LIBRARY(zlib zlib ${DKLIBS_SOURCE_DIR}/bin/IOS/Release)

	### png ###
	FIND_LIBRARY(pngd pngd ${DKLIBS_SOURCE_DIR}/bin/IOS/Debug)
	FIND_LIBRARY(png png ${DKLIBS_SOURCE_DIR}/bin/IOS/Release)
	
	### freetype ###
	FIND_LIBRARY(freetyped freetyped ${DKLIBS_SOURCE_DIR}/bin/IOS/Debug)
	FIND_LIBRARY(freetype freetype ${DKLIBS_SOURCE_DIR}/bin/IOS/Release)
	
	### ftgles ###
	FIND_LIBRARY(ftglesd ftglesd ${DKLIBS_SOURCE_DIR}/bin/IOS/Debug)
	FIND_LIBRARY(ftgles ftgles ${DKLIBS_SOURCE_DIR}/bin/IOS/Release)

	### digitalknob ###
	ADD_LIBRARY(libdk STATIC ${DIGITALKNOB_SRC})
	SET_TARGET_PROPERTIES(libdk PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME dk DEBUG_OUTPUT_NAME dkd)
	SET_TARGET_PROPERTIES(libdk PROPERTIES COMPILE_DEFINITIONS IOS)
	
	### sdl library ###
	ADD_LIBRARY(libsdl STATIC ${SDL_SRCS})
	## NOTE: for some reason lib is always added to the .a file name as in example ( 1234 makes lib1234.a )
	SET_TARGET_PROPERTIES(libsdl PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME sdl DEBUG_OUTPUT_NAME sdld)

	### sdl_image library ###
	ADD_LIBRARY(libsdlimage STATIC ${SDLIMAGE_SRCS})
	SET_TARGET_PROPERTIES(libsdlimage PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME sdlimage DEBUG_OUTPUT_NAME sdlimaged)
	SET_TARGET_PROPERTIES(libsdlimage PROPERTIES COMPILE_DEFINITIONS IOS,LOAD_BMP,LOAD_GIF,LOAD_LBM,LOAD_PCX,LOAD_PNG,LOAD_PNM,LOAD_TGA,LOAD_XPM,LOAD_XV)

	### sdl_mixer library ###
	ADD_LIBRARY(libsdlmixer STATIC ${SDLMIXER_SRCS})
	SET_TARGET_PROPERTIES(libsdlmixer PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME sdlmixer DEBUG_OUTPUT_NAME sdlmixerd)
	SET_TARGET_PROPERTIES(libsdlmixer PROPERTIES COMPILE_DEFINITIONS IOS,WAV_MUSIC,MID_MUSIC)
	
	### zlib library ###
	ADD_LIBRARY(libzlib STATIC ${ZLIB_SRCS})
	SET_TARGET_PROPERTIES(libzlib PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME zlib DEBUG_OUTPUT_NAME zlibd)
	SET_TARGET_PROPERTIES(libzlib PROPERTIES COMPILE_DEFINITIONS IOS,NO_FSEEKO)

	### png library ###
	ADD_LIBRARY(libpng STATIC ${PNG_SRCS})
	SET_TARGET_PROPERTIES(libpng PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME png DEBUG_OUTPUT_NAME pngd)
	SET_TARGET_PROPERTIES(libpng PROPERTIES COMPILE_DEFINITIONS IOS)
	
	### freetype library ###
	ADD_LIBRARY(libfreetype STATIC ${FREETYPE_SRCS})
	SET_TARGET_PROPERTIES(libfreetype PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME freetype DEBUG_OUTPUT_NAME freetyped)
	SET_TARGET_PROPERTIES(libfreetype PROPERTIES COMPILE_DEFINITIONS FT2_BUILD_LIBRARY=1,DARWIN_NO_CARBON)
	
	### ftgles library ###
	ADD_LIBRARY(libftgles STATIC ${FTGLES_SRCS})
	SET_TARGET_PROPERTIES(libftgles PROPERTIES LINKER_LANGUAGE CXX OUTPUT_NAME ftgles DEBUG_OUTPUT_NAME ftglesd)
	SET_TARGET_PROPERTIES(libftgles PROPERTIES COMPILE_DEFINITIONS FTGL_LIBRARY_STATIC)
		
ENDIF(IOS)


##----------------------------------------
##       ###### ANDROID ######
##----------------------------------------
IF(ANDROID)
	MESSAGE(STATUS "Detected Android environment")
	MESSAGE("Creating Android Project Files")
	MESSAGE("CMake script does not support android yet.")
	
	SET(EXECUTABLE_OUTPUT_PATH ${DKLIBS_SOURCE_DIR}/bin/ANDROID)
	SET(LIBRARY_OUTPUT_PATH ${DKLIBS_SOURCE_DIR}/bin/ANDROID)
		
	ADD_DEFINITIONS(-DANDROID)

ENDIF(ANDROID)
