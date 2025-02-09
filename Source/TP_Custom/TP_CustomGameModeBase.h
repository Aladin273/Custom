// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TP_CustomGameModeBase.generated.h"

UENUM(BlueprintType)
enum class ETP_CustomGameModeState : uint8
{
    WaitingForStart,
    InProgress,
    Pause,
    GameOver
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameModeChangedSignature, ETP_CustomGameModeState, GameModeState);

UCLASS()
class TP_CUSTOM_API ATP_CustomGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    virtual void StartPlay() override;

    virtual bool SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate = FCanUnpause()) override;

    virtual bool ClearPause() override;

public:
    UPROPERTY(BlueprintAssignable)
    FOnGameModeChangedSignature OnGameModeStateChanged;

protected:
    UPROPERTY(EditDefaultsOnly)
    ETP_CustomGameModeState GameModeState = ETP_CustomGameModeState::InProgress;

protected:
    void SetGameModeState(ETP_CustomGameModeState State);
};
