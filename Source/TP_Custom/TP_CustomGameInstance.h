// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TP_CustomGameInstance.generated.h"

/**
 *
 */
UCLASS()
class TP_CUSTOM_API UTP_CustomGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Levels")
    FName MainMenuLevelName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Levels")
    FName GameLevelName;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
    USoundClass* MusicSoundClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
    USoundClass* SFXSoundClass;

protected:
    virtual void Init() override;
};
