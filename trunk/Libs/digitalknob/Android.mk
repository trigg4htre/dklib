LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_CFLAGS := -DANDROID

LOCAL_C_INCLUDES += \
        $(LOCAL_PATH) \
	$(LOCAL_PATH)/../sdl/include \
	$(LOCAL_PATH)/../sdl_image \
	$(LOCAL_PATH)/../sdl_mixer \
	$(LOCAL_PATH)/../freetype/include \
	$(LOCAL_PATH)/../ftgles/src \
	$(LOCAL_PATH)/../3ds/src

	FILE_LIST := $(wildcard $(LOCAL_PATH)/*.cpp)
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)
	

LOCAL_MODULE:= dk
include $(BUILD_STATIC_LIBRARY)