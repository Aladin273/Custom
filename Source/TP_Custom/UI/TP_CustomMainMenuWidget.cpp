// Fill out your copyright notice in the Description page of Project Settings.

#include "TP_CustomMainMenuWidget.h"

#include "TP_Custom/TP_CustomGameHUD.h"
#include "TP_Custom/TP_CustomGameInstance.h"

#include "TP_CustomSettingsMenuWidget.h"

#include "Kismet/GameplayStatics.h"

void UTP_CustomMainMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    B_Start->OnClicked.AddUniqueDynamic(this, &UTP_CustomMainMenuWidget::OnStart);
    B_Settings->OnClicked.AddUniqueDynamic(this, &UTP_CustomMainMenuWidget::OnSettings);
    B_Exit->OnClicked.AddUniqueDynamic(this, &UTP_CustomMainMenuWidget::OnExit);

    SettingsWidget = CreateWidget<UTP_CustomSettingsMenuWidget>(this, SettingsWidgetClass);
    SettingsWidget->B_BackMenu->OnClicked.AddUniqueDynamic(this, &UTP_CustomMainMenuWidget::OnBackMenu);
}

void UTP_CustomMainMenuWidget::OnStart()
{
    UGameplayStatics::OpenLevel(this, GetGameInstance<UTP_CustomGameInstance>()->GameLevelName);
}

void UTP_CustomMainMenuWidget::OnSettings()
{
    ATP_CustomGameHUD::Get(GetOwningPlayer())->AddToScreen(SettingsWidget);
}

void UTP_CustomMainMenuWidget::OnExit()
{
    FGenericPlatformMisc::RequestExit(false);
}

void UTP_CustomMainMenuWidget::OnBackMenu()
{
    ATP_CustomGameHUD::Get(GetOwningPlayer())->RemoveFromScreen(SettingsWidget);
}
