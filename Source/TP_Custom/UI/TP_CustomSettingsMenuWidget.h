// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ComboBoxString.h"
#include "Components/Slider.h"
#include "Components/Button.h"
#include "TP_CustomUserWidget.h"
#include "TP_CustomSettingsMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class TP_CUSTOM_API UTP_CustomSettingsMenuWidget : public UTP_CustomUserWidget
{
	GENERATED_BODY()

protected:
    virtual void NativeOnInitialized() override;

public:
    UPROPERTY(meta = (BindWidget))
    UButton* B_BackMenu;

protected:
    UPROPERTY(meta = (BindWidget))
    UComboBoxString* CB_Resolution;

    UPROPERTY(meta = (BindWidget))
    UComboBoxString* CB_Quality;

    UPROPERTY(meta = (BindWidget))
    USlider* S_MusicVolume;

    UPROPERTY(meta = (BindWidget))
    USlider* S_SFXVolume;

protected:
    UFUNCTION()
    void OnResolutionChanged(FString Resolution, ESelectInfo::Type SelectionType);

    UFUNCTION()
    void OnQualityChanged(FString Quality, ESelectInfo::Type SelectionType);

    UFUNCTION()
    void OnMusicVolumeChanged(float Value);

    UFUNCTION()
    void OnSFXVolumeChanged(float Value);

protected:
    UPROPERTY(EditDefaultsOnly)
    TMap<FString, int32> OverallQualities;
};
