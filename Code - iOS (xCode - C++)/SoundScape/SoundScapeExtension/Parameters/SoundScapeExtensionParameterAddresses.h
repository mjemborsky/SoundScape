//
//  SoundScapeExtensionParameterAddresses.h
//  SoundScapeExtension
//
//  Created by Michael Emborsky on 2/16/23.
//

#pragma once

#include <AudioToolbox/AUParameters.h>

#ifdef __cplusplus
namespace SoundScapeExtensionParameterAddress {
#endif

typedef NS_ENUM(AUParameterAddress, SoundScapeExtensionParameterAddress) {
    gain = 0
};

#ifdef __cplusplus
}
#endif
