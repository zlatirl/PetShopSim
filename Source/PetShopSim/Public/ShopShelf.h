// Copyright (c) 2026 zlatirl. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "ShopItemData.h"
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

	UPROPERTY(EditAnywhere, Category = "Shelf")
	int32 StockQuantity = 0;

public:	
	UFUNCTION(BlueprintCallable, Category = "Shelf")
	void RefreshDisplay();
};
