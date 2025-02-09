// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "TP_CustomUserWidget.h"
#include "TP_CustomGameOverWidget.generated.h"

/**
 *
 */
UCLASS()
class TP_CUSTOM_API UTP_CustomGameOverWidget : public UTP_CustomUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeOnInitialized() override;

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* B_Restart;

    UPROPERTY(meta = (BindWidget))
    UButton* B_MainMenu;

protected:
    UFUNCTION()
    void OnRestart();

    UFUNCTION()
    void OnMainMenu();
};
