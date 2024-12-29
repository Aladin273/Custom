// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TP_CustomGameModeBase.h"
#include "UI/TP_CustomUserWidget.h"
#include "TP_CustomGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class TP_CUSTOM_API ATP_CustomGameHUD : public AHUD
{
	GENERATED_BODY()

public:
    static ATP_CustomGameHUD* ATP_CustomGameHUD::Get(APlayerController* PlayerController) { return PlayerController->GetHUD<ATP_CustomGameHUD>(); }

public:
    UFUNCTION(BlueprintCallable)
    void AddToScreen(UTP_CustomUserWidget* Widget, int32 ZOrder = 0);

    UFUNCTION(BlueprintCallable)
    void RemoveFromScreen(UTP_CustomUserWidget* Widget);

    UFUNCTION(BlueprintCallable)
    void RemoveAllWidgets();

protected:
    UFUNCTION()
    void OnGameModeStateChanged(ETP_CustomGameModeState State);

protected:
    UPROPERTY(EditDefaultsOnly)
    TMap<ETP_CustomGameModeState, TSubclassOf<UTP_CustomUserWidget>> GameStateWidgetClasses;

protected:
    virtual void BeginPlay();

    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);

private:
    UPROPERTY()
    TArray<UTP_CustomUserWidget*> WidgetStack;

    UPROPERTY()
    TMap<ETP_CustomGameModeState, UTP_CustomUserWidget*> GameStateWidgets;
};
