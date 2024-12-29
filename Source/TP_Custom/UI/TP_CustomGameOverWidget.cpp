// Fill out your copyright notice in the Description page of Project Settings.

#include "TP_CustomGameOverWidget.h"

#include "TP_Custom/TP_CustomGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UTP_CustomGameOverWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    B_Restart->OnClicked.AddUniqueDynamic(this, &UTP_CustomGameOverWidget::OnRestart);
    B_MainMenu->OnClicked.AddUniqueDynamic(this, &UTP_CustomGameOverWidget::OnMainMenu);
}

void UTP_CustomGameOverWidget::OnRestart()
{
    UGameplayStatics::OpenLevel(this, GetGameInstance<UTP_CustomGameInstance>()->GameLevelName);
}

void UTP_CustomGameOverWidget::OnMainMenu()
{
    UGameplayStatics::OpenLevel(this, GetGameInstance<UTP_CustomGameInstance>()->MainMenuLevelName);
}