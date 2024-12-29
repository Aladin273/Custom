// Fill out your copyright notice in the Description page of Project Settings.


#include "TP_CustomGameInstance.h"
#include "TP_CustomGameUserSettings.h"

void UTP_CustomGameInstance::Init()
{
    Super::Init();

    if (UTP_CustomGameUserSettings* GameUserSettings = UTP_CustomGameUserSettings::GetTP_CustomGameUserSettings())
    {
        GameUserSettings->LoadSettings();

        if (GameUserSettings->GetInitLaunch())
        {
            GameUserSettings->SetFullscreenMode(EWindowMode::Fullscreen);
            GameUserSettings->SetScreenResolution(GameUserSettings->GetDesktopResolution());
            GameUserSettings->SetOverallScalabilityLevel(3);
            GameUserSettings->SetMusicVolume(0.5f);
            GameUserSettings->SetSFXVolume(0.5f);
            GameUserSettings->SetInitLaunch(false);
        }

        GameUserSettings->SetMusicSoundClass(MusicSoundClass);
        GameUserSettings->SetSFXSoundClass(SFXSoundClass);

        GameUserSettings->ApplySettings(false);
    }
}
