// Copyright (c) 2026 zlatirl. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "ShopItemData.h"
#include "ShopStockSubsystem.h"
#include "ShopShelf.generated.h"

UCLASS()
class PETSHOPSIM_API AShopShelf : public AActor
{
	GENERATED_BODY()
	
public:	
	AShopShelf();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Shelf")
	TObjectPtr<USceneComponent> SceneRoot;

	UPROPERTY(VisibleAnywhere, Category = "Shelf")
	TObjectPtr<UStaticMeshComponent> ItemMesh;

	UPROPERTY(EditAnywhere, Category = "Shelf", meta = (RequiredAssetDataTags = "RowStructure=/Script/PetShopSim.ShopItemData"))
	FDataTableRowHandle ItemRow;

public:
	/** How many of this item are on this shelf, from the stock subsystem. */
	UFUNCTION(BlueprintCallable, Category = "Shelf")
	int32 GetStock() const;

	/** Convenience for the row name this shield if bound to. */
	UFUNCTION(BlueprintCallable, Category = "Shelf")
	FName GetItemID() const { return ItemRow.RowName; }

	/** Editor/testing helper: adds stock for this shelf's item. */
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Shelf")
	void DebugAddStock();

	UFUNCTION(BlueprintCallable, Category = "Shelf")
	void RefreshDisplay();
};
