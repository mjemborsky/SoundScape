//
//  SoundScapeExtensionAudioUnit.h
//  SoundScapeExtension
//
//  Created by Michael Emborsky on 2/16/23.
//

#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>

@interface SoundScapeExtensionAudioUnit : AUAudioUnit
- (void)setupParameterTree:(AUParameterTree *)parameterTree;
@end
