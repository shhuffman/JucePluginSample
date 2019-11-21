/*
  ==============================================================================

    KAPInterfaceDefines.h
    Created: 20 Oct 2019 11:56:05pm
    Author:  Houston

  ==============================================================================
*/

#pragma once

constexpr auto MAIN_PANEL_WIDTH             = 750;
constexpr auto MAIN_PANEL_HEIGHT            = 300;

constexpr auto TOP_PANEL_WIDTH              = MAIN_PANEL_WIDTH;
constexpr auto TOP_PANEL_HEIGHT             = 45;

constexpr auto GAIN_PANEL_WIDTH             = 100;
constexpr auto GAIN_PANEL_HEIGHT            = MAIN_PANEL_HEIGHT - TOP_PANEL_HEIGHT;

constexpr auto CENTER_PANEL_WIDTH           = MAIN_PANEL_WIDTH - (GAIN_PANEL_WIDTH * 2);
constexpr auto CENTER_PANEL_HEIGHT          = GAIN_PANEL_HEIGHT;

constexpr auto CENTER_PANEL_MENU_BAR_WIDTH  = CENTER_PANEL_WIDTH;
constexpr auto CENTER_PANEL_MENU_BAR_HEIGHT = 35;

constexpr auto FX_PANEL_WIDTH               = CENTER_PANEL_WIDTH;
constexpr auto FX_PANEL_HEIGHT              = CENTER_PANEL_HEIGHT - CENTER_PANEL_MENU_BAR_HEIGHT;