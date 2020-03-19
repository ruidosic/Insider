// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "InsiderLoadingScreen.h"
#include "SlateBasics.h"
#include "SlateExtras.h"
#include "MoviePlayer.h"
#include "SThrobber.h"

/** struct that create Loading Screen Texture */
struct FInsiderLoadingScreenBrush : public FSlateDynamicImageBrush, public FGCObject
{
	FInsiderLoadingScreenBrush(const FName InTextureName, const FVector2D& InImageSize)
		: FSlateDynamicImageBrush(InTextureName, InImageSize)
	{
		SetResourceObject(LoadObject<UObject>(NULL, *InTextureName.ToString()));
	}

	virtual void AddReferencedObjects(FReferenceCollector& Collector)
	{
		if (UObject* CachedResourceObject = GetResourceObject())
		{
			Collector.AddReferencedObject(CachedResourceObject);
		}
	}
};


class SInsiderLoadingScreen : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SInsiderLoadingScreen) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs)
	{
		// Load version of the logo with text baked in, path is hardcoded because this loads very early in startup
		static const FName LoadingScreenName(TEXT("/Game/Insider/Blueprints/UI/T_Logo.T_Logo"));

		LoadingScreenBrush = MakeShareable(new FInsiderLoadingScreenBrush(LoadingScreenName, FVector2D(1024, 256)));
	
		FSlateBrush* BGBrush = new FSlateBrush();
		BGBrush->TintColor = FLinearColor(0.034f, 0.034f, 0.034f, 1.0f);

		ChildSlot
		[
			// Setup Border
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SBorder)
				.BorderImage(BGBrush)
			]
			// Setup Image
			+SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(SImage)
				.Image(LoadingScreenBrush.Get())
			]
			// Setup Throbber - its three dots: ...
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				.HAlign(HAlign_Right)
				.VAlign(VAlign_Bottom)
				.Padding(FMargin(10.0f))
				[
					SNew(SThrobber)
					.Visibility(this, &SInsiderLoadingScreen::GetLoadIndicatorVisibility)
				]
			]
		];
	}
private:
	/** Rather to show the ... indicator */
	EVisibility GetLoadIndicatorVisibility() const
	{
		bool Vis = GetMoviePlayer()->IsLoadingFinished();
		return GetMoviePlayer()->IsLoadingFinished() ? EVisibility::Collapsed : EVisibility::Visible;
	}

	/** Loading screen image brush */
	TSharedPtr<FSlateDynamicImageBrush> LoadingScreenBrush;
};

class FInsiderLoadingScreenModule : public IInsiderLoadingScreenModule
{
public:
	virtual void StartupModule() override
	{
		// Force load for cooker reference
		LoadObject<UObject>(nullptr, TEXT("/Game/Insider/Blueprints/UI/T_Logo.T_Logo"));

		if (IsMoviePlayerEnabled())
		{
			CreateScreen();
		}
	}

	virtual bool IsGameModule() const override
	{
		return true;
	}

	virtual void StartInGameLoadingScreen(bool bPlayUntilStopped, float PlayTime) override
	{
		FLoadingScreenAttributes LoadingScreen;
		LoadingScreen.bAutoCompleteWhenLoadingCompletes = !bPlayUntilStopped;
		LoadingScreen.bWaitForManualStop = bPlayUntilStopped;
		LoadingScreen.bAllowEngineTick = bPlayUntilStopped;
		LoadingScreen.MinimumLoadingScreenDisplayTime = PlayTime;
		LoadingScreen.WidgetLoadingScreen = SNew(SInsiderLoadingScreen);
		GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
	}

	virtual void StopInGameLoadingScreen() override
	{
		GetMoviePlayer()->StopMovie();
	}

	virtual void CreateScreen()
	{
		FLoadingScreenAttributes LoadingScreen;
		LoadingScreen.bAutoCompleteWhenLoadingCompletes = true;
		//screen minimum display time
		LoadingScreen.MinimumLoadingScreenDisplayTime = 3.f;
		// set slate widget
		LoadingScreen.WidgetLoadingScreen = SNew(SInsiderLoadingScreen);
		// setup Loading Screen async
		GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
	}
};

IMPLEMENT_GAME_MODULE(FInsiderLoadingScreenModule, InsiderLoadingScreen);