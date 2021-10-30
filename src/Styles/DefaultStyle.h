#pragma once
#include "../Utils/StyleSheet.h"

static Style DefaultNormalStyle(0x00, 0xFF, 0x37, DefaultFont, 1);
static Style DefaultHoverStyle(0x00, 0xFF, 0x73, DefaultFont, 1);
static Style DefaultPressedStyle(0x00, 0xFF, 0x73, DefaultFont, 2);

static StyleSheet DefaultStyle(DefaultNormalStyle, DefaultHoverStyle, DefaultPressedStyle);


static Style DefaultWindowHeaderNormalStyle(0x37, 0xFF, 0x37, DefaultFont, 0);
static Style DefaultWindowHeaderHoverStyle(0x73, 0xFF, 0x73, DefaultFont, 0);
static Style DefaultWindowHeaderPressedStyle(0x73, 0xFF, 0x73, DefaultFont, 0);
static StyleSheet DefaultWindowHeaderStyle(DefaultWindowHeaderNormalStyle, DefaultWindowHeaderHoverStyle, DefaultWindowHeaderPressedStyle);


static Style DefaultButtonNormalStyle(0x36, 0xFF, 0x36, 0, DefaultFont, Center);
static Style DefaultButtonHoverStyle(0x36, 0x73, 0x73, 2, DefaultFont, Center);
static Style DefaultButtonPressedStyle(0x37, 0x73, 0x73, 1, DefaultFont, Center);

static StyleSheet DefaultButtonStyle(DefaultButtonNormalStyle, DefaultButtonHoverStyle, DefaultButtonPressedStyle);


static Style DefaultIconButtonNormalStyle(0x00, 0xFF, 0x37, 0, DefaultSymbolFont, Center);
static Style DefaultIconButtonHoverStyle(0x00, 0x73, 0x73, 1, DefaultSymbolFont, Center);
static Style DefaultIconButtonPressedStyle(0x00, 0x73, 0x73, 2, DefaultSymbolFont, Center);

static StyleSheet DefaultIconButtonStyle(DefaultIconButtonNormalStyle, DefaultIconButtonHoverStyle, DefaultIconButtonPressedStyle);


static Style DefaultRangeNormalStyle(0x00, 0xFF, 0x37, 0, DefaultFont, Center);
static Style DefaultRangeHoverStyle(0x00, 0x73, 0x37, 1, DefaultFont, Center);
static Style DefaultRangePressedStyle(0x00, 0x73, 0x37, 2, DefaultFont, Center);

static StyleSheet DefaultRangeStyle(DefaultRangeNormalStyle, DefaultRangeHoverStyle, DefaultRangePressedStyle);


static Style DefaultBorderlessIconButtonNormalStyle(0x00, 0xFF, 0x00, 0, DefaultSymbolFont, Center);
static Style DefaultBorderlessIconButtonHoverStyle(0x00, 0x73, 0x00, 0, DefaultSymbolFont, Center);
static Style DefaultBorderlessIconButtonPressedStyle(0x00, 0x37, 0x00, 0, DefaultSymbolFont, Center);

static StyleSheet DefaultBorderlessIconButtonStyle(DefaultBorderlessIconButtonNormalStyle, DefaultBorderlessIconButtonHoverStyle, DefaultBorderlessIconButtonPressedStyle);