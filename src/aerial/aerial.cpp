//
// Created by xixiliadorabarry on 2/26/19.
//
#include "aerial/aerial.h"

Aerial::Aerial() {
    initEnergyPartParam();

    video_mode = 0;
}

Aerial::~Aerial() = default;

void Aerial::setVideoMode(int mode){
    video_mode = mode;
}

void Aerial::setPcViewer(PCViewer pcviewer){
    pc = pcviewer;
}