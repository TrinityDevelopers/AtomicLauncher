#pragma once
#include <android/log.h>
#include "developer/mcpe.h"

#define LOG_TAG "AtomicLauncher"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

static Font* font;
static Level* currentLevel;
static TileSource* tileSource;
static MinecraftClient* minecraftClient;
static bool debug = true;
static Button* debugButton = NULL;
