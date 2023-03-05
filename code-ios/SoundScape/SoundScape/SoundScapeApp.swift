//
//  SoundScapeApp.swift
//  SoundScape
//
//  Created by Michael Emborsky on 2/16/23.
//

import CoreMIDI
import SwiftUI

@main
class SoundScapeApp: App {
    @ObservedObject private var hostModel = AudioUnitHostModel()

    required init() {}

    var body: some Scene {
        WindowGroup {
            ContentView(hostModel: hostModel)
        }
    }
}
