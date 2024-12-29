// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "TP_CustomUserWidget.h"
#include "TP_CustomPauseMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class TP_CUSTOM_API UTP_CustomPauseMenuWidget : public UTP_CustomUserWidget
{
	GENERATED_BODY()

protected:
    virtual void NativeOnInitialized() override;

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* B_Resume;

    UPROPERTY(meta = (BindWidget))
    UButton* B_MainMenu;

protected:
    UFUNCTION()
    void OnResume();

    UFUNCTION()
    void OnMainMenu();
};
