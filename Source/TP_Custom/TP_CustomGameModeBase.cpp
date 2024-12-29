// Copyright Epic Games, Inc. All Rights Reserved.


#include "TP_CustomGameModeBase.h"

void ATP_CustomGameModeBase::StartPlay()
{
    Super::StartPlay();

    SetGameModeState(GameModeState);
}

bool ATP_CustomGameModeBase::SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate /*= FCanUnpause()*/)
{
    bool bPauseSet = Super::SetPause(PC, CanUnpauseDelegate);

    if (bPauseSet)
        SetGameModeState(ETP_CustomGameModeState::Pause);

    return bPauseSet;
}

bool ATP_CustomGameModeBase::ClearPause()
{
    bool bPauseCleared = Super::ClearPause();

    if (bPauseCleared)
        SetGameModeState(ETP_CustomGameModeState::InProgress);

    return bPauseCleared;
}

void ATP_CustomGameModeBase::SetGameModeState(ETP_CustomGameModeState State)
{
    GameModeState = State;
    OnGameModeStateChanged.Broadcast(State);
}
