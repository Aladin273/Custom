// Fill out your copyright notice in the Description page of Project Settings.


#include "TP_CustomSettingsMenuWidget.h"

#include "TP_Custom/TP_CustomGameHUD.h"
#include "TP_Custom/TP_CustomGameUserSettings.h"

#include "Kismet/KismetSystemLibrary.h"

void UTP_CustomSettingsMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    CB_Resolution->OnSelectionChanged.AddUniqueDynamic(this, &UTP_CustomSettingsMenuWidget::OnResolutionChanged);
    CB_Quality->OnSelectionChanged.AddUniqueDynamic(this, &UTP_CustomSettingsMenuWidget::OnQualityChanged);
    S_MusicVolume->OnValueChanged.AddUniqueDynamic(this, &UTP_CustomSettingsMenuWidget::OnMusicVolumeChanged);
    S_SFXVolume->OnValueChanged.AddUniqueDynamic(this, &UTP_CustomSettingsMenuWidget::OnSFXVolumeChanged);

    TArray<FIntPoint> Resolutions;
    UKismetSystemLibrary::GetSupportedFullscreenResolutions(Resolutions);

    if (Resolutions.Num())
    {
        CB_Resolution->ClearOptions();

        for (auto Resolution : Resolutions)
        {
            CB_Resolution->AddOption(FString::FromInt(Resolution.X).Append(FString("X")).Append(FString::FromInt(Resolution.Y)));

            if (Resolution == UTP_CustomGameUserSettings::GetTP_CustomGameUserSettings()->GetScreenResolution())
                CB_Resolution->SetSelectedOption(CB_Resolution->GetOptionAtIndex(CB_Resolution->GetOptionCount() - 1));
        }
    }

    if (OverallQualities.Num())
    {
        CB_Quality->ClearOptions();

        for (auto Quality : OverallQualities)
        {
            CB_Quality->AddOption(Quality.Key);

            if (Quality.Value == UTP_CustomGameUserSettings::GetTP_CustomGameUserSettings()->GetOverallScalabilityLevel())
                CB_Quality->SetSelectedOption(Quality.Key);
        }
    }

    S_MusicVolume->SetValue(UTP_CustomGameUserSettings::GetTP_CustomGameUserSettings()->GetMusicVolume());
    S_SFXVolume->SetValue(UTP_CustomGameUserSettings::GetTP_CustomGameUserSettings()->GetSFXVolume());
}

void UTP_CustomSettingsMenuWidget::OnResolutionChanged(FString Resolution, ESelectInfo::Type SelectionType)
{
    FString ResolutionX, ResolutionY;
    Resolution.Split(FString("X"), &ResolutionX, &ResolutionY);

    UTP_CustomGameUserSettings::GetTP_CustomGameUserSettings()->SetScreenResolution(FIntPoint(FCString::Atoi(*ResolutionX), FCString::Atoi(*ResolutionY)));
    UTP_CustomGameUserSettings::GetTP_CustomGameUserSettings()->ApplySettings(false);
}

void UTP_CustomSettingsMenuWidget::OnQualityChanged(FString Quality, ESelectInfo::Type SelectionType)
{
    UTP_CustomGameUserSettings::GetTP_CustomGameUserSettings()->SetOverallScalabilityLevel(OverallQualities[Quality]);
    UTP_CustomGameUserSettings::GetTP_CustomGameUserSettings()->ApplySettings(false);
}

void UTP_CustomSettingsMenuWidget::OnMusicVolumeChanged(float Value)
{
    UTP_CustomGameUserSettings::GetTP_CustomGameUserSettings()->SetMusicVolume(Value);
    UTP_CustomGameUserSettings::GetTP_CustomGameUserSettings()->ApplySettings(false);
}

void UTP_CustomSettingsMenuWidget::OnSFXVolumeChanged(float Value)
{
    UTP_CustomGameUserSettings::GetTP_CustomGameUserSettings()->SetSFXVolume(Value);
    UTP_CustomGameUserSettings::GetTP_CustomGameUserSettings()->ApplySettings(false);
}