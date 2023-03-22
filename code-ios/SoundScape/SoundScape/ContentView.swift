//
//  ContentView.swift
//  SoundScape
//
//  Created by Michael Emborsky on 2/16/23.
//

import AudioToolbox
import SwiftUI

struct ContentView: View {
    @ObservedObject var hostModel: AudioUnitHostModel
    var margin = 10.0
    var doubleMargin: Double {
        margin * 2.0
    }
    
    var body: some View {
        VStack() {
            HStack(spacing: 59) {
                Spacer()
                Text("SoundScape")
                    .textSelection(.enabled)
                Spacer()
                HStack() {
                    Image(systemName: "person.crop.circle.fill")
                                        .resizable()
                                        .scaledToFill()
                                        .frame(width: 25, height: 25)
                                        .clipShape(Circle())
                    Text("Profile/Settings")
                }
            }
            .padding()
            VStack(alignment: .center) {
                if let viewController = hostModel.viewModel.viewController {
                    AUViewControllerUI(viewController: viewController)
                        .padding(margin)
                } else {
                    VStack() {
                        Text(hostModel.viewModel.message)
                            .padding()
                    }
                    .frame(minWidth: 400, minHeight: 200)
                }
                if let viewController = hostModel.viewModel.viewController {
                    AUViewControllerUI(viewController: viewController)
                        .padding(margin)
                } else {
                    VStack() {
                        Text(hostModel.viewModel.message)
                            .padding()
                    }
                    .frame(minWidth: 400, minHeight: 200)
                }
            }
            .padding(doubleMargin)
            
            HStack() {
                if hostModel.viewModel.showAudioControls {
                    Button {
                        hostModel.isPlaying ? hostModel.stopPlaying() : hostModel.startPlaying()
                        
                    } label: {
                        Text(hostModel.isPlaying ? "Preset 1" : "Preset 1")
                    }
                }
                if hostModel.viewModel.showMIDIContols {
                    Text("MIDI Input: Enabled")
                }
                if hostModel.viewModel.showAudioControls {
                    Button {
                        hostModel.isPlaying ? hostModel.stopPlaying() : hostModel.startPlaying()
                        
                    } label: {
                        Text(hostModel.isPlaying ? "Preset 2" : "Preset 2")
                    }
                }
                if hostModel.viewModel.showMIDIContols {
                    Text("MIDI Input: Enabled")
                }
                if hostModel.viewModel.showAudioControls {
                    Button {
                        hostModel.isPlaying ? hostModel.stopPlaying() : hostModel.startPlaying()
                        
                    } label: {
                        Text(hostModel.isPlaying ? "Preset 3" : "Preset 3")
                    }
                }
                if hostModel.viewModel.showMIDIContols {
                    Text("MIDI Input: Enabled")
                }
                if hostModel.viewModel.showAudioControls {
                    Button {
                        hostModel.isPlaying ? hostModel.stopPlaying() : hostModel.startPlaying()
                        
                    } label: {
                        Text(hostModel.isPlaying ? "Preset 4" : "Preset 4")
                    }
                }
                if hostModel.viewModel.showMIDIContols {
                    Text("MIDI Input: Enabled")
                }
                if hostModel.viewModel.showAudioControls {
                    Button {
                        hostModel.isPlaying ? hostModel.stopPlaying() : hostModel.startPlaying()
                        
                    } label: {
                        Text(hostModel.isPlaying ? "Preset 5" : "Preset 5")
                    }
                }
                if hostModel.viewModel.showMIDIContols {
                    Text("MIDI Input: Enabled")
                }
            }
            
            Spacer()
                .frame(height: margin)
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView(hostModel: AudioUnitHostModel())
    }
}
