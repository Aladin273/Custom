// Fill out your copyright notice in the Description page of Project Settings.


#include "TP_CustomPlayerController.h"

void ATP_CustomPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (ATP_CustomGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ATP_CustomGameModeBase>())
    {
        GameMode->OnGameModeStateChanged.AddUniqueDynamic(this, &ATP_CustomPlayerController::OnGameModeStateChanged);
    }
}

void ATP_CustomPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (ATP_CustomGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ATP_CustomGameModeBase>())
    {
        GameMode->OnGameModeStateChanged.RemoveDynamic(this, &ATP_CustomPlayerController::OnGameModeStateChanged);
    }

    Super::EndPlay(EndPlayReason);
}

void ATP_CustomPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (InputComponent)
    {
        InputComponent->BindAction("PauseGame", IE_Pressed, this, &ATP_CustomPlayerController::OnPauseGame);
    }
}

void ATP_CustomPlayerController::OnGameModeStateChanged(ETP_CustomGameModeState State)
{
    if (State == ETP_CustomGameModeState::InProgress)
    {
        SetInputMode(FInputModeGameOnly());
        bShowMouseCursor = false;
    }
    else
    {
        SetInputMode(FInputModeUIOnly());
        bShowMouseCursor = true;
    }
}

void ATP_CustomPlayerController::OnPauseGame()
{
    if (GetWorld() && GetWorld()->GetAuthGameMode())
    {
        GetWorld()->GetAuthGameMode()->SetPause(this);
    }
}
