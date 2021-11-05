#pragma once

#include "../Utils/GColor.hpp"
#include "../Utils/StyleSheet.hpp"

// Base section style
static Style DefaultNormalStyle(GColor::fromRGB(255, 255, 255), GColor::fromRGB(32, 32, 32), GColor::fromRGB(160, 160, 160), DefaultFont, 1);
static Style DefaultHoverStyle(GColor::fromRGB(255, 255, 255), GColor::fromRGB(32, 32, 32), GColor::fromRGB(160, 160, 190), DefaultFont, 1);
static Style DefaultPressedStyle(GColor::fromRGB(255, 255, 255), GColor::fromRGB(32, 32, 32), GColor::fromRGB(160, 160, 190), DefaultFont, 2);

static StyleSheet DefaultStyle(DefaultNormalStyle, DefaultHoverStyle, DefaultPressedStyle);

// Widnow header style
static Style DefaultWindowHeaderNormalStyle(GColor::fromRGB(190, 190, 190), GColor::fromRGB(64, 64, 64), GColor(), DefaultFont, 0);
static Style DefaultWindowHeaderHoverStyle(GColor::fromRGB(190, 190, 230), GColor::fromRGB(64, 64, 88), GColor(), DefaultFont, 0);
static Style DefaultWindowHeaderPressedStyle(GColor::fromRGB(188, 188, 245), GColor::fromRGB(100, 100, 125), GColor(), DefaultFont, 0);
static StyleSheet DefaultWindowHeaderStyle(DefaultWindowHeaderNormalStyle, DefaultWindowHeaderHoverStyle, DefaultWindowHeaderPressedStyle);

// Button style
static Style DefaultButtonNormalStyle(GColor::fromRGB(222, 222, 222), GColor::fromRGB(64, 64, 64), GColor::fromRGB(120, 120, 120), 1, DefaultFont, Center);
static Style DefaultButtonHoverStyle(GColor::fromRGB(222, 222, 255), GColor::fromRGB(120, 120, 190), GColor::fromRGB(120, 120, 190), 1, DefaultFont, Center);
static Style DefaultButtonPressedStyle(GColor::fromRGB(230, 230, 255), GColor::fromRGB(150, 150, 240), GColor::fromRGB(150, 150, 240), 2, DefaultFont, Center);

static StyleSheet DefaultButtonStyle(DefaultButtonNormalStyle, DefaultButtonHoverStyle, DefaultButtonPressedStyle);
 
// Icon button style
static Style DefaultIconButtonNormalStyle(GColor::fromRGB(255, 255, 255), GColor::fromRGB(64, 64, 64), GColor(), 0, DefaultSymbolFont, Center);
static Style DefaultIconButtonHoverStyle(GColor::fromRGB(255, 255, 255), GColor::fromRGB(120, 120, 190), 0x73, 1, DefaultSymbolFont, Center);
static Style DefaultIconButtonPressedStyle(GColor::fromRGB(255, 255, 255), GColor::fromRGB(150, 150, 240), 0x73, 2, DefaultSymbolFont, Center);

static StyleSheet DefaultIconButtonStyle(DefaultIconButtonNormalStyle, DefaultIconButtonHoverStyle, DefaultIconButtonPressedStyle);

// Borderless button style
static Style DefaultBorderlessIconButtonNormalStyle(GColor::fromRGB(255, 255, 255), GColor::fromRGB(64, 64, 64), GColor(), 0, DefaultSymbolFont, Center);
static Style DefaultBorderlessIconButtonHoverStyle(GColor::fromRGB(255, 255, 255), GColor::fromRGB(120, 120, 190), GColor(), 0, DefaultSymbolFont, Center);
static Style DefaultBorderlessIconButtonPressedStyle(GColor::fromRGB(255, 255, 255), GColor::fromRGB(150, 150, 240), GColor(), 0, DefaultSymbolFont, Center);

static StyleSheet DefaultBorderlessIconButtonStyle(DefaultBorderlessIconButtonNormalStyle, DefaultBorderlessIconButtonHoverStyle, DefaultBorderlessIconButtonPressedStyle);

// Range style
static Style DefaultRangeNormalStyle(GColor::fromRGB(255, 255, 255), GColor::fromRGB(64, 64, 64), GColor(), 0, DefaultFont, Center);
static Style DefaultRangeHoverStyle(GColor::fromRGB(255, 255, 255), GColor::fromRGB(120, 120, 190), GColor::fromRGB(111, 111, 155), 1, DefaultFont, Center);
static Style DefaultRangePressedStyle(GColor::fromRGB(255, 255, 255), GColor::fromRGB(150, 150, 240), GColor::fromRGB(111, 111, 155), 2, DefaultFont, Center);

static StyleSheet DefaultRangeStyle(DefaultRangeNormalStyle, DefaultRangeHoverStyle, DefaultRangePressedStyle);
