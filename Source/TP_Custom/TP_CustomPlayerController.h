// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TP_CustomGameModeBase.h"
#include "TP_CustomPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TP_CUSTOM_API ATP_CustomPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);

	virtual void SetupInputComponent() override;

protected:
    UFUNCTION()
    void OnGameModeStateChanged(ETP_CustomGameModeState State);

private:
    UFUNCTION()
	void OnPauseGame();
};
