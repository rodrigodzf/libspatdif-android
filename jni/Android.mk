
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := libspatdif

LOCAL_C_INCLUDES += $(LOCAL_PATH)/libs/tinyxml2
LOCAL_C_INCLUDES += $(LOCAL_PATH)/libs/libjson
LOCAL_C_INCLUDES += $(LOCAL_PATH)/libs/libjson/_internal/Source


LOCAL_CFLAGS := -fexceptions -std=c++11 -lstdc++ -w -O3
FILE_LIST := $(wildcard $(LOCAL_PATH)/../src/*.cpp)
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)


LOCAL_STATIC_LIBRARIES += libtinyxml2 libjson

# include $(BUILD_STATIC_LIBRARY)
include $(BUILD_SHARED_LIBRARY)

$(call import-add-path, $(LOCAL_PATH))
$(call import-module,libs/tinyxml2/jni)
$(call import-module,libs/libjson/jni)
