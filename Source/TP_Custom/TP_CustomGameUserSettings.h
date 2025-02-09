// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "Kismet/GameplayStatics.h"
#include "TP_CustomGameUserSettings.generated.h"

/**
 *
 */
UCLASS()
class TP_CUSTOM_API UTP_CustomGameUserSettings : public UGameUserSettings
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    static UTP_CustomGameUserSettings* GetTP_CustomGameUserSettings()
    {
        return Cast<UTP_CustomGameUserSettings>(UGameUserSettings::GetGameUserSettings());
    }

    void ApplySettings(bool bCheckForCommandLineOverrides) override
    {
        if (MusicSoundClass && SFXSoundClass)
        {
            MusicSoundClass->Properties.Volume = FMath::Clamp(MusicVolume, 0.f, 1.f);
            SFXSoundClass->Properties.Volume = FMath::Clamp(SFXVolume, 0.f, 1.f);
        }

        Super::ApplySettings(bCheckForCommandLineOverrides);
    }

public:
    UFUNCTION(BlueprintCallable)
    void SetInitLaunch(bool InLaunch) { bInitLaunch = InLaunch; };

    UFUNCTION(BlueprintCallable)
    void SetMusicVolume(float InVolume) { MusicVolume = InVolume; };

    UFUNCTION(BlueprintCallable)
    void SetSFXVolume(float InVolume) { SFXVolume = InVolume; };

public:
    UFUNCTION(BlueprintCallable)
    bool GetInitLaunch() const { return bInitLaunch; };

    UFUNCTION(BlueprintCallable)
    float GetMusicVolume() const { return MusicVolume; };

    UFUNCTION(BlueprintCallable)
    float GetSFXVolume() const { return SFXVolume; };

public:
    UFUNCTION(BlueprintCallable)
    void SetMusicSoundClass(USoundClass* InSoundClass) { MusicSoundClass = InSoundClass; }

    UFUNCTION(BlueprintCallable)
    void SetSFXSoundClass(USoundClass* InSoundClass) { SFXSoundClass = InSoundClass; }

public:
    UFUNCTION(BlueprintCallable)
    USoundClass* GetMusicSoundClass() const { return MusicSoundClass; }

    UFUNCTION(BlueprintCallable)
    USoundClass* GetSFXSoundClass() const { return SFXSoundClass; }

protected:
    UPROPERTY(Config)
    bool bInitLaunch = true;

    UPROPERTY(Config)
    float MusicVolume = 1.0f;

    UPROPERTY(Config)
    float SFXVolume = 1.0f;

private:
    UPROPERTY()
    USoundClass* MusicSoundClass;

    UPROPERTY()
    USoundClass* SFXSoundClass;
};
