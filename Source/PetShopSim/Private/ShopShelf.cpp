// Copyright (c) 2026 zlatirl. All Rights Reserved.

#include "ShopShelf.h"

AShopShelf::AShopShelf()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot     = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	ItemMesh->SetupAttachment(SceneRoot);
}

void AShopShelf::BeginPlay()
{
	Super::BeginPlay();
	RefreshDisplay();
}

void AShopShelf::RefreshDisplay()
{
	const FShopItemData* Row = ItemRow.GetRow<FShopItemData>(TEXT("ShopShelf::RefreshDisplay"));
	if (!Row)
	{
		ItemMesh->SetStaticMesh(nullptr);
		return;
	}

	if (UStaticMesh* Loaded = Row->Mesh.LoadSynchronous())
	{
		ItemMesh->SetStaticMesh(Loaded);
	}
}

int32 AShopShelf::GetStock() const
{
	const UGameInstance* GI = GetGameInstance();
	if (!GI)
	{
		return 0;
	}

	const UShopStockSubsystem* Stock = GI->GetSubsystem<UShopStockSubsystem>();
	return Stock ? Stock->GetStock(GetItemID()) : 0;
}

void AShopShelf::DebugAddStock()
{
	if (UGameInstance* GI = GetGameInstance())
	{
		if (UShopStockSubsystem* Stock = GI->GetSubsystem<UShopStockSubsystem>())
		{
			Stock->AddStock(GetItemID(), 5);
		}
	}
}
