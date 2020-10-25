// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameMode.h"

void AFPSGameMode::StartPlay() 
{
	Super::StartPlay();

	UE_LOG(LogTemp, Warning, TEXT("Your message"));

	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameMode!"));
	}
}
