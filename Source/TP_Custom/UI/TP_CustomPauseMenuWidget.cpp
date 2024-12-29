// Fill out your copyright notice in the Description page of Project Settings.


#include "TP_CustomPauseMenuWidget.h"

#include "TP_Custom/TP_CustomGameInstance.h"
#include "TP_Custom/TP_CustomGameModeBase.h"

#include "Kismet/GameplayStatics.h"

void UTP_CustomPauseMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    B_Resume->OnClicked.AddUniqueDynamic(this, &UTP_CustomPauseMenuWidget::OnResume);
    B_MainMenu->OnClicked.AddUniqueDynamic(this, &UTP_CustomPauseMenuWidget::OnMainMenu);
}

void UTP_CustomPauseMenuWidget::OnResume()
{
    GetWorld()->GetAuthGameMode()->ClearPause();
}

void UTP_CustomPauseMenuWidget::OnMainMenu()
{
    UGameplayStatics::OpenLevel(this, GetGameInstance<UTP_CustomGameInstance>()->MainMenuLevelName);
}
