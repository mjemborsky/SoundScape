cmake_minimum_required(VERSION 3.15)

project(MyAudioApp VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# JUCE setup
add_subdirectory(libs/JUCE)

juce_add_gui_app(MyAudioApp
    COMPANY_NAME "YourName"
)

target_sources(MyAudioApp PRIVATE
    src/Main.cpp
    src/MainComponent.cpp
)

target_compile_definitions(MyAudioApp PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
)

target_link_libraries(MyAudioApp PRIVATE
    juce::juce_gui_extra
    juce::juce_audio_utils
    juce::juce_opengl
)
