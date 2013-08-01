########################################
####        DKAPP - Win32           ####
########################################

###### Supported Platform / Compilers  ######
#
# Visual Studio 8 2005
# Visual Studio 9 2008
# Visual Studio 10 2010
# Mac Intel / XCode 3.1+
# KDevelop

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

PROJECT(DKAPP)
SET(EXECUTABLE_OUTPUT_PATH ${DKAPP_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${DKAPP_SOURCE_DIR}/bin)

#### PATH VARIABLES ###############
set(LIBPATH ${DKAPP_SOURCE_DIR}/../../Libs)
set(BINPATH ${DKAPP_SOURCE_DIR}/../../Libs/bin)

##------------------------------------------
## DKAPP
##------------------------------------------
FILE(GLOB DKAPP_SRC 
src/*.*
src/icons/*.*
)

##----------------------------------------
##       ###### WINDOWS ######
##----------------------------------------
IF(WIN32)
	MESSAGE(STATUS "Detected WINDOWS environment")
	MESSAGE(STATUS "Creating Windows Project Files")
	
	INCLUDE_DIRECTORIES(${DKAPP_SOURCE_DIR})
	INCLUDE_DIRECTORIES(${LIBPATH}/digitalknob)
	INCLUDE_DIRECTORIES(${LIBPATH}/sdl/include)
	INCLUDE_DIRECTORIES(${LIBPATH}/sdl_image)
	INCLUDE_DIRECTORIES(${LIBPATH}/sdl_mixer)
	INCLUDE_DIRECTORIES(${LIBPATH}/zlib)
	INCLUDE_DIRECTORIES(${LIBPATH}/freetype/include)
	INCLUDE_DIRECTORIES(${LIBPATH}/ftgl)
	INCLUDE_DIRECTORIES(${LIBPATH}/ftgl/src/)
	INCLUDE_DIRECTORIES(${LIBPATH}/3ds/src/)
	INCLUDE_DIRECTORIES(${LIBPATH}/zlib)
	INCLUDE_DIRECTORIES(${LIBPATH}/directx)
	INCLUDE_DIRECTORIES(${LIBPATH}/ftgl/msvc/)

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

	
	### directx ###
	##FIND_LIBRARY(dxguid dxguid $ENV{DXSDK_DIR}/Lib/x86)
	FIND_LIBRARY(dxguid dxguid ${BINPATH}/WIN32/Debug)

	### digitalknob ###
	FIND_LIBRARY(dkd dkd ${BINPATH}/WIN32/Debug)
	FIND_LIBRARY(dk dk ${BINPATH}/WIN32/Release)
	
	### sdl ###
	FIND_LIBRARY(sdld sdld ${BINPATH}/WIN32/Debug)
	FIND_LIBRARY(sdl sdl ${BINPATH}/WIN32/Release)

	### sdl_Image ###
	FIND_LIBRARY(sdlimaged sdlimaged ${BINPATH}/WIN32/Debug)
	FIND_LIBRARY(sdlimage sdlimage ${BINPATH}/WIN32/Release)
	
	### sdl_mixer ###
	FIND_LIBRARY(sdlmixerd sdlmixerd ${BINPATH}/WIN32/Debug)
	FIND_LIBRARY(sdlmixer sdlmixer ${BINPATH}/WIN32/Release)

	### zlib ###
	FIND_LIBRARY(zlibd zlibd ${BINPATH}/WIN32/Debug)
	FIND_LIBRARY(zlib zlib ${BINPATH}/WIN32/Release)

	### png ###
	FIND_LIBRARY(pngd pngd ${BINPATH}/WIN32/Debug)
	FIND_LIBRARY(png png ${BINPATH}/WIN32/Release)

	### freetype ###
	FIND_LIBRARY(freetyped freetyped ${BINPATH}/WIN32/Debug)
	FIND_LIBRARY(freetype freetype ${BINPATH}/WIN32/Release)
	
	### ftgl ###
	FIND_LIBRARY(ftgld ftgld ${BINPATH}/WIN32/Debug)
	FIND_LIBRARY(ftgl ftgl ${BINPATH}/WIN32/Release)
	
	### 3ds ###
	FIND_LIBRARY(3dsd 3dsd ${BINPATH}/WIN32/Debug)
	FIND_LIBRARY(3ds 3ds ${BINPATH}/WIN32/Release)

	### DKAPP ###
	GET_TARGET_PROPERTY(MyExecutable_PATH DKAPP LOCATION)
	ADD_EXECUTABLE(DKAPP WIN32 ${DKAPP_SRC})
	TARGET_LINK_LIBRARIES(DKAPP debug ${dkd} 
								debug ${sdld}
								debug ${sdlimaged}
								debug ${sdlmixerd}
								debug ${zlibd}
								debug ${pngd}
								debug ${freetyped}
								debug ${ftgld}
								debug ${3dsd}
								optimized ${dk}
								optimized ${sdl}
								optimized ${sdlimage}
								optimized ${sdlmixer}
								optimized ${zlib}
								optimized ${png}
								optimized ${freetype}
								optimized ${ftgl}
								optimized ${3ds}
								${dxguid}
								winmm.lib
								opengl32.lib
								glu32.lib
								version.lib				
								imm32.lib
				      )
	SET_TARGET_PROPERTIES(DKAPP PROPERTIES LINK_FLAGS_DEBUG "/MANIFESTUAC:NO" LINK_FLAGS "/MANIFESTUAC:NO")
ENDIF(WIN32)

##----------------------------------------
##        ##### MAC #####
##----------------------------------------
IF(MAC)
	MESSAGE(STATUS "Creating Mac Project Files")

	ADD_DEFINITIONS(-DMAC)
	SET(CMAKE_CXX_FLAGS "-x objective-c++")
	
	INCLUDE_DIRECTORIES(${DKAPP_SOURCE_DIR})
	INCLUDE_DIRECTORIES(${LIBPATH}/digitalknob)
	INCLUDE_DIRECTORIES(${LIBPATH}/sdl/include)
	INCLUDE_DIRECTORIES(${LIBPATH}/sdl_image)
	INCLUDE_DIRECTORIES(${LIBPATH}/sdl_mixer)
	INCLUDE_DIRECTORIES(${LIBPATH}/zlib)
	INCLUDE_DIRECTORIES(${LIBPATH}/freetype/include)
	INCLUDE_DIRECTORIES(${LIBPATH}/ftgl)
	INCLUDE_DIRECTORIES(${LIBPATH}/ftgl/src/)
	INCLUDE_DIRECTORIES(${LIBPATH}/3ds/src/)
	INCLUDE_DIRECTORIES(${LIBPATH}/zlib)
	INCLUDE_DIRECTORIES(${LIBPATH}/freetype/include/freetype/config)
	INCLUDE_DIRECTORIES(${LIBPATH}/freetype/include/freetype/internal)
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
	FIND_LIBRARY(dkd dkd ${BINPATH}/MAC/Debug)
	FIND_LIBRARY(dk dk ${BINPATH}/MAC/Release)
	
	### sdl ###
	FIND_LIBRARY(sdld sdld ${BINPATH}/MAC/Debug)
	FIND_LIBRARY(sdl sdl ${BINPATH}/MAC/Release)
	
	### sdl_Image ###
	FIND_LIBRARY(sdlimaged sdlimaged ${BINPATH}/MAC/Debug)
	FIND_LIBRARY(sdlimage sdlimage ${BINPATH}/MAC/Release)
	
	### sdl_mixer ###
	FIND_LIBRARY(sdlmixerd sdlmixerd ${BINPATH}/MAC/Debug)
	FIND_LIBRARY(sdlmixer sdlmixer ${BINPATH}/MAC/Release)

	### zlib ###
	FIND_LIBRARY(zlibd zlibd ${BINPATH}/MAC/Debug)
	FIND_LIBRARY(zlib zlib ${BINPATH}/MAC/Release)

	### png ###
	FIND_LIBRARY(pngd pngd ${BINPATH}/MAC/Debug)
	FIND_LIBRARY(png png ${BINPATH}/MAC/Release)
	
	### freetype ###
	FIND_LIBRARY(freetyped freetyped ${BINPATH}/MAC/Debug)
	FIND_LIBRARY(freetype freetype ${BINPATH}/MAC/Release)
	
	### ftgl ###
	FIND_LIBRARY(ftgld ftgld ${BINPATH}/MAC/Debug)
	FIND_LIBRARY(ftgl ftgl ${BINPATH}/MAC/Release)

	### 3ds ###
	FIND_LIBRARY(3dsd 3dsd ${BINPATH}/MAC/Debug)
	FIND_LIBRARY(3ds 3ds ${BINPATH}/MAC/Release)
	
	
	### DKAPP ###
	GET_TARGET_PROPERTY(MyExecutable_PATH DKAPP LOCATION)
	ADD_EXECUTABLE(DKAPP MACOSX_BUNDLE ${DKAPP_SRC})
	TARGET_LINK_LIBRARIES(DKAPP debug ${dkd} 
								debug ${sdld}
								debug ${sdlimaged}
								debug ${sdlmixerd}
								debug ${zlibd}
								debug ${pngd}
								debug ${freetyped}
								debug ${ftgld}
								debug ${3dsd}
								optimized ${dk}
								optimized ${sdl}
								optimized ${sdlimage}
								optimized ${sdlmixer}
								optimized ${zlib}
								optimized ${png}
								optimized ${freetype}
								optimized ${ftgl}
								optimized ${3ds}
								${CF}
								${CO}
								${CB}
								${AT}
								${AU}
								${CA}
								${IO}
								${GL}
								${FF}
								)
ENDIF(MAC)

##----------------------------------------
##       ###### LINUX ######
##----------------------------------------
IF(LINUX)
	MESSAGE(STATUS "Detected LINUX environment")
	MESSAGE(STATUS "Creating LINUX Project Files")

	INCLUDE_DIRECTORIES(${DKAPP_SOURCE_DIR})
	INCLUDE_DIRECTORIES(${LIBPATH}/digitalknob)
	INCLUDE_DIRECTORIES(${LIBPATH}/sdl/include)
	INCLUDE_DIRECTORIES(${LIBPATH}/sdl_image)
	INCLUDE_DIRECTORIES(${LIBPATH}/sdl_mixer)
	INCLUDE_DIRECTORIES(${LIBPATH}/png)
	INCLUDE_DIRECTORIES(${LIBPATH}/zlib)
	INCLUDE_DIRECTORIES(${LIBPATH}/freetype/include)
	INCLUDE_DIRECTORIES(${LIBPATH}/ftgl)
	INCLUDE_DIRECTORIES(${LIBPATH}/ftgl/src/)
	INCLUDE_DIRECTORIES(${LIBPATH}/3ds/src/)
	INCLUDE_DIRECTORIES(${LIBPATH}/zlib)

	ADD_DEFINITIONS(-DLINUX)
	ADD_DEFINITIONS(-DFTGL_LIBRARY_STATIC)
	ADD_DEFINITIONS(-DHAVE_STDINT_H)

	### digitalknob ###
	FIND_LIBRARY(dkd dkd ${BINPATH}/LINUX/Debug)
	FIND_LIBRARY(dk dk ${BINPATH}/LINUX/Release)
	
	### sdl ###
	FIND_LIBRARY(sdld sdld ${BINPATH}/LINUX/Debug)
	FIND_LIBRARY(sdl sdl ${BINPATH}/LINUX/Release)
	
	### sdl_Image ###
	FIND_LIBRARY(sdlimaged sdlimaged ${BINPATH}/LINUX/Debug)
	FIND_LIBRARY(sdlimage sdlimage ${BINPATH}/LINUX/Release)
	
	### sdl_mixer ###
	FIND_LIBRARY(sdlmixerd sdlmixerd ${BINPATH}/LINUX/Debug)
	FIND_LIBRARY(sdlmixer sdlmixer ${BINPATH}/LINUX/Release)

	### zlib ###
	FIND_LIBRARY(zlibd zlibd ${BINPATH}/LINUX/Debug)
	FIND_LIBRARY(zlib zlib ${BINPATH}/LINUX/Release)

	### png ###
	FIND_LIBRARY(pngd pngd ${BINPATH}/LINUX/Debug)
	FIND_LIBRARY(png png ${BINPATH}/LINUX/Release)
	
	### freetype ###
	FIND_LIBRARY(freetyped freetyped ${BINPATH}/LINUX/Debug)
	FIND_LIBRARY(freetype freetype ${BINPATH}/LINUX/Release)
	
	### ftgl ###
	FIND_LIBRARY(ftgld ftgld ${BINPATH}/LINUX/Debug)
	FIND_LIBRARY(ftgl ftgl ${BINPATH}/LINUX/Release)

	### 3ds ###
	FIND_LIBRARY(3dsd 3dsd ${BINPATH}/LINUX/Debug)
	FIND_LIBRARY(3ds 3ds ${BINPATH}/LINUX/Release)

	### DKAPP ###
	GET_TARGET_PROPERTY(MyExecutable_PATH DKAPP LOCATION)
	ADD_EXECUTABLE(DKAPP WIN32 ${DKAPP_SRC})
	TARGET_LINK_LIBRARIES(DKAPP debug ${dkd} 
								debug ${sdld}
								debug ${sdlimaged}
								debug ${sdlmixerd}
								debug ${zlibd}
								debug ${pngd}
								debug ${freetyped}
								debug ${ftgld}
								debug ${3dsd}
								optimized ${dk}
								optimized ${sdl}
								optimized ${sdlimage}
								optimized ${sdlmixer}
								optimized ${zlib}
								optimized ${png}
								optimized ${freetype}
								optimized ${ftgl}
								optimized ${3ds}
								)
ENDIF(LINUX)

##----------------------------------------
##       ###### IOS ######
##----------------------------------------
IF(IOS)
	MESSAGE("Creating IPhone Project Files")
		
	ADD_DEFINITIONS(-DIOS)
	ADD_DEFINITIONS(-D__IPHONEOS__)
	#ADD_DEFINITIONS(-DSDL_IPHONE_KEYBOARD)

	INCLUDE_DIRECTORIES(${DKAPP_SOURCE_DIR})
	INCLUDE_DIRECTORIES(${LIBPATH}/digitalknob)
	INCLUDE_DIRECTORIES(${LIBPATH}/sdl/include )
	INCLUDE_DIRECTORIES(${LIBPATH}/sdl/src/events )
	INCLUDE_DIRECTORIES(${LIBPATH}/sdl/src/video )
	INCLUDE_DIRECTORIES(${LIBPATH}/sdl_image)
	INCLUDE_DIRECTORIES(${LIBPATH}/sdl_mixer)
	INCLUDE_DIRECTORIES(${LIBPATH}/png)
	INCLUDE_DIRECTORIES(${LIBPATH}/zlib)
	INCLUDE_DIRECTORIES(${LIBPATH}/freetype/include)
	INCLUDE_DIRECTORIES(${LIBPATH}/ftgles/)
	INCLUDE_DIRECTORIES(${LIBPATH}/ftgles/src/)
	INCLUDE_DIRECTORIES(${LIBPATH}/ftgles/src/iGLU-1.0.0/include)
	INCLUDE_DIRECTORIES(${LIBPATH}/3ds/src)
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
	FIND_LIBRARY(dkd dkd ${BINPATH}/IOS/Debug)
	FIND_LIBRARY(dk dk ${BINPATH}/IOS/Release)
	
	### sdl ###
	FIND_LIBRARY(sdld sdld ${BINPATH}/IOS/Debug)
	FIND_LIBRARY(sdl sdl ${BINPATH}/IOS/Release)

	### sdl_Image ###
	FIND_LIBRARY(sdlimaged sdlimaged ${BINPATH}/IOS/Debug)
	FIND_LIBRARY(sdlimage sdlimage ${BINPATH}/IOS/Release)
	
	### sdl_mixer ###
	FIND_LIBRARY(sdlmixerd sdlmixerd ${BINPATH}/IOS/Debug)
	FIND_LIBRARY(sdlmixer sdlmixer ${BINPATH}/IOS/Release)

	### zlib ###
	FIND_LIBRARY(zlibd zlibd ${BINPATH}/IOS/Debug)
	FIND_LIBRARY(zlib zlib ${BINPATH}/IOS/Release)

	### png ###
	FIND_LIBRARY(pngd pngd ${BINPATH}/IOS/Debug)
	FIND_LIBRARY(png png ${BINPATH}/IOS/Release)
	
	### freetype ###
	FIND_LIBRARY(freetyped freetyped ${BINPATH}/IOS/Debug)
	FIND_LIBRARY(freetype freetype ${BINPATH}/IOS/Release)
	
	### ftgles ###
	FIND_LIBRARY(ftglesd ftglesd ${BINPATH}/IOS/Debug)
	FIND_LIBRARY(ftgles ftgles ${BINPATH}/IOS/Release)

	### DKTestApp APP ###
	GET_TARGET_PROPERTY(MyExecutable_PATH DKAPP LOCATION)
	ADD_EXECUTABLE(DKAPP MACOSX_BUNDLE ${DKAPP_SRC})
	TARGET_LINK_LIBRARIES(DKAPP debug ${dkd}
								debug ${sdld}
								debug ${sdlimaged}
								debug ${sdlmixerd}
								debug ${zlibd}
								debug ${pngd}
								debug ${freetyped}
								debug ${ftglesd}
								optimized ${dk}
								optimized ${sdl}
								optimized ${sdlimage}
								optimized ${sdlmixer}
								optimized ${zlib}
								optimized ${png}
								optimized ${freetype}
								optimized ${ftgles}
								)

	SET_TARGET_PROPERTIES(DKAPP PROPERTIES XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "iPhone Developer: DigitalKnob")
		
ENDIF(IOS)

##----------------------------------------
##       ###### ANDROID ######
##----------------------------------------
IF(ANDROID)
	MESSAGE(STATUS "Detected Android environment")
	MESSAGE("Creating Android Project Files")
	MESSAGE("CMake script does not support android yet.")
		
	ADD_DEFINITIONS(-DANDROID)

ENDIF(ANDROID)