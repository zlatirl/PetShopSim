// Copyright (c) 2026 zlatirl. All Rights Reserved.

#include "ShopStockSubsystem.h"

void UShopStockSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	Cash = 500;
}

void UShopStockSubsystem::Deinitialize()
{
	StockLevels.Empty();
	Super::Deinitialize();
}

int32 UShopStockSubsystem::GetStock(FName ItemID) const
{
	const int32* Found = StockLevels.Find(ItemID);
	return Found ? *Found : 0;
}

void UShopStockSubsystem::AddStock(FName ItemID, int32 Amount)
{
	if (Amount <= 0)
	{
		return;
	}
	StockLevels.FindOrAdd(ItemID) += Amount;
}

bool UShopStockSubsystem::RemoveStock(FName ItemID, int32 Amount)
{
	if (Amount <= 0)
	{
		return false;
	}

	int32* Found = StockLevels.Find(ItemID);
	if (!Found || *Found < Amount)
	{
	    return false;
	}

	*Found -= Amount;
	if (*Found == 0)
	{
		StockLevels.Remove(ItemID);
	}
	return true;
}

void UShopStockSubsystem::AddCash(int32 Amount)
{
	if (Amount > 0)
	{
		Cash += Amount;
	}
}

bool UShopStockSubsystem::SpendCash(int32 Amount)
{
	if (Amount <= 0 || Cash < Amount)
	{
		return false;
	}
	Cash -= Amount;
	return true;
}
