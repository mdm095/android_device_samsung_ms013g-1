LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional
LOCAL_C_INCLUDES := system/core/init
LOCAL_CFLAGS := -Wall
LOCAL_SRC_FILES := init_ms013g.cpp
LOCAL_MODULE := libinit_ms013g
LOCAL_STATIC_LIBRARIES := libbase

include $(BUILD_STATIC_LIBRARY)
