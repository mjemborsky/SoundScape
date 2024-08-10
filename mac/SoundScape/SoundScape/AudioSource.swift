//
//  AudioSource.swift
//  SoundScape
//
//  Created by Michael Emborsky on 2/23/23.
//

import Foundation

class AudioSource {
    
    // all the status's of the effects on the given audiosource
    var sourceName: String
    var volume: Int
    var hpan: Int
    var vpan: Int
    var stereo: Int
    var reverb: Int
    var effect: Int
    

    init(sourceName: String, volume: Int, hpan: Int, vpan: Int, stereo: Int, reverb: Int, effect: Int) {
        self.sourceName = sourceName
        self.volume = volume
        self.hpan = hpan
        self.vpan = vpan
        self.stereo = stereo
        self.reverb = reverb
        self.effect = effect
    }
}
