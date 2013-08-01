include $(CLEAR_VARS)

LOCAL_MODULE := main

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/../../Libs/digitalknob \
	$(LOCAL_PATH)/../../Libs/sdl/include \
	$(LOCAL_PATH)/../../Libs/freetype/include \
	$(LOCAL_PATH)/../../Libs/sdl_image \
	$(LOCAL_PATH)/../../Libs/sdl_mixer \
	$(LOCAL_PATH)/../../Libs/3ds/src \
	$(LOCAL_PATH)/../../Libs/ftgles/src

#### COMPILATION FLAGS ###
LOCAL_CFLAGS := -DANDROID -DFTGL_LIBRARY_STATIC 

#### This will add ALL *.cpp files from the "Project/src" directory ####
FILE_LIST := $(wildcard $(LOCAL_PATH)/../../Apps/DKBlank/src/*.cpp)
LOCAL_SRC_FILES := $(LOCAL_PATH)/../../Libs/sdl/src/main/android/SDL_android_main.cpp \
	$(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_STATIC_LIBRARIES := dk lib3ds FTGLES
LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_mixer 

LOCAL_LDLIBS := -lGLESv1_CM -llog

include $(BUILD_SHARED_LIBRARY)