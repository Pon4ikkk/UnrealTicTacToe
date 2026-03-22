// TicTacToe, Copyright ArtemZykov. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Types.h"
#include "GameFramework/Actor.h"
#include "TTT_Grid.generated.h"

UCLASS()
class TICTACTOE_API ATTT_Grid : public AActor
{
    GENERATED_BODY()

public:
    ATTT_Grid();

protected:
    virtual void BeginPlay() override;

public:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    class UBoxComponent* CollisionBox;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    class UDecalComponent* IconDecal;

    UPROPERTY(EditAnywhere, Category = "Grid")
    int32 GridRow;

    UPROPERTY(EditAnywhere, Category = "Grid")
    int32 GridCol;

    UFUNCTION(BlueprintCallable, Category = "Gameplay")
    void SetCellType(ECellType State);

private:
    UFUNCTION()
    void OnBoxClicked(UPrimitiveComponent* TouchedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);
};