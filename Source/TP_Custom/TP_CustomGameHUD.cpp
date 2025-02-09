// Fill out your copyright notice in the Description page of Project Settings.

#include "TP_CustomGameHUD.h"

void ATP_CustomGameHUD::AddToScreen(UTP_CustomUserWidget* Widget, int32 ZOrder /*= 0*/)
{
    if (WidgetStack.Num() && WidgetStack.Last() == Widget || WidgetStack.Contains(Widget))
        return;

    if (WidgetStack.Num())
        WidgetStack.Last()->SetVisibility(ESlateVisibility::Collapsed);

    WidgetStack.Add(Widget);
    Widget->SetVisibility(ESlateVisibility::Visible);

    if (!Widget->IsInViewport())
        Widget->AddToViewport(ZOrder);
}

void ATP_CustomGameHUD::RemoveFromScreen(UTP_CustomUserWidget* Widget)
{
    if (WidgetStack.Num() && WidgetStack.Last() == Widget)
    {
        WidgetStack.Remove(Widget);
        Widget->SetVisibility(ESlateVisibility::Collapsed);

        WidgetStack.Last()->SetVisibility(ESlateVisibility::Visible);
    }
}

void ATP_CustomGameHUD::RemoveAllWidgets()
{
    for (auto Widget : WidgetStack)
    {
        Widget->SetVisibility(ESlateVisibility::Collapsed);
    }

    WidgetStack.Reset();
}

void ATP_CustomGameHUD::OnGameModeStateChanged(ETP_CustomGameModeState State)
{
    RemoveAllWidgets();

    if (GameStateWidgets.Contains(State))
    {
        AddToScreen(GameStateWidgets[State]);
    }
}

void ATP_CustomGameHUD::BeginPlay()
{
    Super::BeginPlay();

    for (auto Tuple : GameStateWidgetClasses)
    {
        GameStateWidgets.Add(Tuple.Key, CreateWidget<UTP_CustomUserWidget>(GetWorld(), Tuple.Value));
    }

    for (auto Tuple : GameStateWidgets)
    {
        Tuple.Value->AddToViewport();
        Tuple.Value->SetVisibility(ESlateVisibility::Collapsed);
    }

    if (ATP_CustomGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ATP_CustomGameModeBase>())
    {
        GameMode->OnGameModeStateChanged.AddUniqueDynamic(this, &ATP_CustomGameHUD::OnGameModeStateChanged);
    }
}

void ATP_CustomGameHUD::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (ATP_CustomGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ATP_CustomGameModeBase>())
    {
        GameMode->OnGameModeStateChanged.RemoveDynamic(this, &ATP_CustomGameHUD::OnGameModeStateChanged);
    }

    Super::EndPlay(EndPlayReason);
}
