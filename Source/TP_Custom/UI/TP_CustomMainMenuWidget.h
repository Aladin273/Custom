// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "TP_CustomUserWidget.h"
#include "TP_CustomMainMenuWidget.generated.h"

class UTP_CustomSettingsMenuWidget;
/**
 *
 */
UCLASS()
class TP_CUSTOM_API UTP_CustomMainMenuWidget : public UTP_CustomUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeOnInitialized() override;

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* B_Start;

    UPROPERTY(meta = (BindWidget))
    UButton* B_Settings;

    UPROPERTY(meta = (BindWidget))
    UButton* B_Exit;

protected:
    UFUNCTION()
    void OnStart();

    UFUNCTION()
    void OnSettings();

    UFUNCTION()
    void OnExit();

protected:
    UFUNCTION()
    void OnBackMenu();

protected:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UTP_CustomSettingsMenuWidget> SettingsWidgetClass;

private:
    UPROPERTY()
    UTP_CustomSettingsMenuWidget* SettingsWidget;
};
