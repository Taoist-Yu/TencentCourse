// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSHUD.h"
#include "CanvasItem.h"
#include "GameFramework/HUD.h"
#include "FPSCharacter.h"
#include "Engine/Canvas.h"

void AFPSHUD::DrawHUD()
{
	Super::DrawHUD();

	Canvas;

	//×¼ÐÇ
	if (CrosshairTexture)
	{
		FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

		FVector2D CrossHairDrawPosition(Center.X - (CrosshairTexture->GetSurfaceWidth() * 0.5f), Center.Y - (CrosshairTexture->GetSurfaceHeight() * 0.5f));

		FCanvasTileItem TileItem(CrossHairDrawPosition, CrosshairTexture->Resource, FLinearColor::White);
		TileItem.BlendMode = SE_BLEND_Translucent;
		Canvas->DrawItem(TileItem);
	}

	//µÃ·Ö
	FVector2D LU(Canvas->ClipX * 0.2f, Canvas->ClipY * 0.2f);
	FVector2D Pos(LU.X - (CrosshairTexture->GetSurfaceWidth() * 0.5f), LU.Y - (CrosshairTexture->GetSurfaceHeight() * 0.5f));
	FString ScoreStr = FString(TEXT("Score: ")).Append(FString::FromInt(AFPSCharacter::Score));
	DrawText(ScoreStr, FColor::Red, 0.2f * Canvas->SizeX, 0.2f * Canvas->SizeY);
}