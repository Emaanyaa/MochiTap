#pragma once

#define _WIN32_WINNT 0X500  //noresize

#include <d3dx9.h>
#include <iostream>
#include <Windows.h>
#include <thread>
#include <intrin.h>

#include "Memory.h"
#include "XOR.h"
#include "Interface.h"
#include "LocalPlayer.h"
#include "w2sm.h"
#include "Offsets.hpp"
#include "Entity.h"

#include "bhop.h"
#include "Triggerbot.h"
#include "glowesp.h"
#include "Radar.h"
#include"NoRecoil.h"

// Flags
#define FL_ON_GROUND                     257
#define FL_ON_GROUND_CROUCHED             263
#define FL_IN_AIR_STAND                    256
#define FL_IN_AIR_MOVING_TO_STAND         258
#define FL_ON_GROUND_MOVING_TO_STAND     259
#define FL_IN_AIR_MOVING_TO_CROUCH         260
#define FL_ON_GROUND_MOVING_TO_CROUCH     261
#define FL_IN_AIR_CROUCHED                 262
#define FL_IN_WATER                     1280
#define FL_IN_PUDDLE                     1281
#define FL_IN_WATER_CROUCHED             1286
#define FL_IN_PUDDLE_CROUCHED             1287
#define FL_PARTIALGROUND (1 << 18)