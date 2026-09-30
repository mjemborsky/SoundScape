# SoundScape - Project State

## Project Overview
An application for Windows and Linux OS designed to give users granular, spatial control over individual system audio sources. The software automatically detects and intercepts audio output streams per application, places them inside an interactive 2D/3D virtual room, and enables custom positioning, routing, and DSP effects (panning, volume, stereo width, reverb, and spatial attenuation).

---

## Key Software Components
* **JUCE Audio Engine & UI:** Cross-platform C++ application framework managing DSP graphs, plugin hosting, state management (`juce::ValueTree`), and 2D/3D canvas rendering (`juce::OpenGLContext`).
* **OS Stream Interceptors:** Platform-specific low-level capture engines to isolate application audio without cross-talk.
* **Spatial DSP Engine:** Distance-based attenuation, HRTF 3D positioning, and room impulse reverb calculation (integrating Steam Audio SDK or Google Resonance Audio).
* **Virtual Stage UI:** Interactive spatial room canvas where running applications appear as draggable nodes.

---

## Operating Systems & Audio Capture Methods

### 1. Windows Operating System (Windows 10 2004+ / Windows 11)
Utilizes low-level Windows Audio Session APIs to capture and isolate application streams.
* **WASAPI Application Loopback:** Asynchronous capture via `ActivateAudioInterfaceAsync` using `AUDCLNT_PROCESS_LOOPBACK_PARAMS` targeted at specific Process IDs (PIDs).
* **Session Suppression:** Muting target process audio sessions at the OS level via `ISimpleAudioVolume` to prevent dry, un-spatialized audio leakage to primary outputs.

### 2. Linux Operating System
Leverages modern Linux multimedia server APIs for transparent application graph tapping.
* **PipeWire Audio Engine:** Native stream interception via `libpipewire` C API to capture and re-route granular application audio nodes.
* **PulseAudio Fallback:** Supporting legacy environments using `libpulse` monitor sinks attached to target audio channels.

---

## Signal Flow Diagram

[ OS Running Applications (PIDs) ]
|
v
[ OS Interceptor Layer ]
|
+---> (Windows) ---> [ WASAPI Application Loopback ] ---> [ Mute Native OS Session ]
|                                                                    |
+---> (Linux)   ---> [ PipeWire / PulseAudio Graph ] ────────────────┤
                                                                     v
                                                   [ JUCE Audio Input Engine ]
                                                                     |
                                                                     v
                                                   [ Interactive Spatial Room Stage ]
                                                   |-- Distance Attenuation (Volume)
                                                   |-- Angle Calculation (HRTF Panning)
                                                   |-- Room Acoustics (Reverb & EQ)
                                                                     |
                                                                     v
                                                   [ Master Output / Hardware Output ]

---

## Next Steps & Development

# Phase 1: OS Interceptor & Loopback Proof of Concept (Week 1)
* [ ] **Windows WASAPI Loopback Engine:** Build C++ test harness utilizing `ActivateAudioInterfaceAsync` and `AUDCLNT_PROCESS_LOOPBACK_PARAMS` to isolate specific process IDs (PIDs).
* [ ] **OS Session Muting:** Test session suppression via `ISimpleAudioVolume` to prevent dry audio leakage.
* [ ] **Linux PipeWire Engine:** Write C API script targeting `libpipewire` to tap and re-route granular application graph nodes.
* [ ] **PulseAudio Fallback:** Add `libpulse` monitor sink creation for legacy Linux system support.

## Phase 2: JUCE Audio Graph Engine (Week 2)
* [ ] **Custom Audio Source Wrappers:** Implement `juce::AudioSource` and `juce::AudioProcessor` modules to ingest external process PCM buffers.
* [ ] **Multi-Channel Routing Architecture:** Construct dynamic `juce::AudioProcessorGraph` allowing nodes to be added/removed on the fly.
* [ ] **Buffer & Thread Sync:** Build lock-free ring buffers to pass captured OS streams into JUCE's high-priority audio callback thread without drops.

## Phase 3: Spatialization Physics & DSP (Week 3)
* [ ] **Spatial SDK Integration:** Integrate Steam Audio SDK / Google Resonance Audio into the JUCE audio pipeline.
* [ ] **HRTF & Attenuation Calculation:** Implement distance-based volume roll-off and angle/elevation-based HRTF panning algorithms.
* [ ] **Acoustic Environment Modeling:** Add dynamic room impulse responses for reverb tail and spatial reflections based on virtual room dimensions.

## Phase 4: Virtual Stage UI & Visual Canvas (Week 4)
* [ ] **Interactive 2D/3D Canvas:** Build interactive virtual room GUI using JUCE vector graphics and `juce::OpenGLContext`.
* [ ] **Node Physics & Interaction:** Implement draggable process nodes mapped to coordinate vectors fed directly into the DSP engine.
* [ ] **State Persistence:** Utilize `juce::ValueTree` to save and restore user room layouts, process mappings, and DSP presets.