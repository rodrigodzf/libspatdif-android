/** @file
 *
 * @ingroup spatdiflib
 *
 * @brief
 *
 * @details
 *
 * @authors Chikashi Miyama, Trond Lossius
 *
 * @copyright Copyright (C) 2013 - 2014 Zurich University of the Arts, Institute for Computer Music and Sound Technology @n
 * This code is licensed under the terms of the "New BSD License" @n
 * http://creativecommons.org/licenses/BSD/
 */

#include "sdEventExtensionMedia.h"


const int sdEventExtensionMedia::numberOfDescriptors = 6;
const sdDescriptor sdEventExtensionMedia::descriptors[sdEventExtensionMedia::numberOfDescriptors] = {
    sdDescriptor(SD_MEDIA_ID, std::string("id"), false),
    sdDescriptor(SD_MEDIA_TYPE, std::string("type"), false),
    sdDescriptor(SD_MEDIA_LOCATION, std::string("location"), true),
    sdDescriptor(SD_MEDIA_CHANNEL, std::string("channel"), false),
    sdDescriptor(SD_MEDIA_TIME_OFFSET, std::string("time-offset"), false),
    sdDescriptor(SD_MEDIA_GAIN, std::string("gain"), true)
};

// constructors
sdEventExtensionMedia::sdEventExtensionMedia(double time, EDescriptor descriptor, void* value){
    setTime(time); // declared in sdEntity.h
    setValue(descriptor, value);
}

sdEventExtensionMedia::sdEventExtensionMedia(std::string time, std::string descriptor, std::string value){
    setTime(time);
    setValue(descriptor, value);
}

// destructor
sdEventExtensionMedia::~sdEventExtensionMedia(){
    
    switch (descriptor) {
        case SD_MEDIA_ID:{
            std::string* valuePointer = static_cast<std::string*>(value);
            delete valuePointer;
            break;
        }
        case SD_MEDIA_TYPE:{
            std::string* valuePointer = static_cast<std::string*>(value);
            delete valuePointer;
            break;
        }
        case SD_MEDIA_LOCATION:{
            std::string* valuePointer = static_cast<std::string*>(value);
            delete valuePointer;
            break;
        }
        case SD_MEDIA_CHANNEL:{
            int *valuePointer = static_cast<int*>(value);
            delete valuePointer;
            break;
        }
        case SD_MEDIA_TIME_OFFSET:{
            double *valuePointer = static_cast<double*>(value);
            delete valuePointer;
            break;
        }
        case SD_MEDIA_GAIN:{
            double *valuePointer = static_cast<double*>(value);
            delete valuePointer;
            break;
        }
        default:
            break;
    }
}

// returns descriptor of the event as a string
std::string sdEventExtensionMedia::getDescriptorAsString(void) const{
    for(int i = 0; i< sdEventExtensionMedia::numberOfDescriptors; i++){
        if(sdEventExtensionMedia::descriptors[i].getDescriptor() == descriptor){
            return sdEventExtensionMedia::descriptors[i].getDescriptorAsString();
        }
    }
    return std::string("error");
}

// returns value of the event as a string
std::string sdEventExtensionMedia::getValueAsString(void) const{
    std::string str;
    switch (descriptor) {
        case SD_MEDIA_ID:
        case SD_MEDIA_TYPE:
        case SD_MEDIA_LOCATION:
            str = *static_cast<std::string*>(value);
            break;
        case SD_MEDIA_CHANNEL:{
            str = intToString(*static_cast<int *>(value));
            break;
        }
        case SD_MEDIA_TIME_OFFSET:
        case SD_MEDIA_GAIN:{
            str = doubleToString(*static_cast<double *>(value));
            break;
        }
        default:
            break;
    }
    return str;
}

// set value with enum and pointer
bool sdEventExtensionMedia::setValue(const EDescriptor descriptor, void* const value){
    
    sdEventExtensionMedia::descriptor = descriptor;
    switch (sdEventExtensionMedia::descriptor) {
        case SD_MEDIA_ID:
        case SD_MEDIA_TYPE:
        case SD_MEDIA_LOCATION:{
            std::string *valueString = new std::string(*static_cast<std::string*>(value));
            sdEventExtensionMedia::value = static_cast<void*>(valueString);
            break;
        }
        case SD_MEDIA_CHANNEL:{
            int *channelValue = static_cast<int*>(value);
            sdEvent::value = static_cast<int*>(new int(*channelValue));
            break;
        }
        case SD_MEDIA_TIME_OFFSET:
        case SD_MEDIA_GAIN:{
            double *doubleValue = static_cast<double*>(value);
            sdEvent::value = static_cast<double*>(new double(*doubleValue));
            break;
        }
        default:{
            return false;
            break;
        }
    }
    return true;
}

// set value with strings
bool sdEventExtensionMedia::setValue(const std::string descriptor, const std::string value){
    
    for(int i = 0; i < sdEventExtensionMedia::numberOfDescriptors; i++){
        if(sdEventExtensionMedia::descriptors[i].getDescriptorAsString() == descriptor){
            sdEventExtensionMedia::descriptor =
            sdEventExtensionMedia::descriptors[i].getDescriptor();
        }
    }
    
    switch (sdEventExtensionMedia::descriptor) {
        case SD_MEDIA_ID:
        case SD_MEDIA_TYPE:
        case SD_MEDIA_LOCATION:{
            sdEventExtensionMedia::value = static_cast<void*>(new std::string(value));
            break;
        }
        case SD_MEDIA_CHANNEL:{
            sdEventExtensionMedia::value = static_cast<void*>(new int(stringToInt(value)));
            break;
        }
        case SD_MEDIA_TIME_OFFSET:
        case SD_MEDIA_GAIN:{
            sdEventExtensionMedia::value = static_cast<void*>(new double(stringToDouble(value)));
            break;
        }
        default:{
            return false;
            break;
        }
    }
    
    return true;
}

