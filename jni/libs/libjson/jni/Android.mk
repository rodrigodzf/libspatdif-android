LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := libjson
# LOCAL_ARM_MODE := arm
LOCAL_C_INCLUDES = 	$(LOCAL_PATH)../_intenal/Dependecies/libbase64++ \
					$(LOCAL_PATH)../_intenal/Dependecies/mempool++
# LOCAL_C_INCLUDES += ../_intenal/Dependecies/mempool++
LOCAL_CFLAGS := -w -fexceptions -JSON_LIBRARY
FILE_LIST := $(wildcard $(LOCAL_PATH)/../_internal/Source/*.cpp)
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)
# LOCAL_SRC_FILES := ../_internal/Source/libjson.cpp

include $(BUILD_STATIC_LIBRARY)
# include $(BUILD_SHARED_LIBRARY)
