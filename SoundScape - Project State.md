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
* **C++ Proof of Concept:** Build minimal C++ host applications testing per-PID WASAPI loopback capture on Windows and `libpipewire` graph node tapping on Linux.
* **JUCE Integration:** Implement custom `juce::AudioSource` and `juce::AudioProcessor` wrappers to pipe external process buffers directly into a multi-channel JUCE audio graph.
* **Spatialization Physics:** Integrate Steam Audio SDK to calculate HRTF filtering and distance-based reverb responses based on node coordinate vectors on the visual stage.
* **Canvas Development:** Design the interactive GUI using JUCE's vector graphics and `juce::OpenGLContext` for interactive 2D/3D app placement.