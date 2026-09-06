// Copyright (c) 2026 zlatirl. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ShopStockSubsystem.generated.h"

UCLASS()
class PETSHOPSIM_API UShopStockSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Current stock for an item. Returns 0 if not stocked */
	UFUNCTION(BlueprintCallable, Category = "Shop|Stock")
	int32 GetStock(FName ItemID) const;

	/** Adds to stock. Negative amounts are ignored. */
	UFUNCTION(BlueprintCallable, Category = "Shop|Stock")
	void AddStock(FName ItemID, int32 Amount);

	/** Removes stock if enough is available. Returns false and changes nothing otherwise. */
	UFUNCTION(BlueprintCallable, Category = "Shop|Stock")
	bool RemoveStock(FName ItemID, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Shop|Economy")
	int32 GetCash() const { return Cash; }

	UFUNCTION(BlueprintCallable, Category = "Shop|Economy")
	void AddCash(int32 Amount);

	/** Spends cash if affordable. Returns false and changes nothing otherwise. */
	UFUNCTION(BlueprintCallable, Category = "Shop|Economy")
	bool SpendCash(int32 Amount);

private:
	UPROPERTY()
	TMap<FName, int32> StockLevels;

	UPROPERTY()
	int32 Cash = 0;
};
