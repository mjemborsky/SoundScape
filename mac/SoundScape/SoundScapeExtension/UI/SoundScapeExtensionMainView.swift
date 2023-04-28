//
//  SoundScapeExtensionMainView.swift
//  SoundScapeExtension
//
//  Created by Michael Emborsky on 2/16/23.
//

import SwiftUI

struct SoundScapeExtensionMainView: View {
    var parameterTree: ObservableAUParameterGroup
    
    var body: some View {
        ParameterSlider(param: parameterTree.global.gain)
    }
}
