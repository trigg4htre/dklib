LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

include $(LOCAL_PATH)/../../../Libs/digitalknob/Android.mk \
	$(LOCAL_PATH)/../../../Libs/sdl/Android.mk \
	$(LOCAL_PATH)/../../../Libs/sdl_image/Android.mk \
	$(LOCAL_PATH)/../../../Libs/sdl_mixer/Android.mk \
	$(LOCAL_PATH)/../../../Libs/3ds/Android.mk \
	$(LOCAL_PATH)/../../../Libs/freetype/Android.mk \
	$(LOCAL_PATH)/../../../Libs/ftgles/Android.mk \
	$(LOCAL_PATH)/src/Android.mk