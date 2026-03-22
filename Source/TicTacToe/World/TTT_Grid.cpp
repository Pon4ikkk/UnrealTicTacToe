// TicTacToe, Copyright ArtemZykov. All Rights Reserved.


#include "TicTacToe/World/TTT_Grid.h"
#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"
#include "Materials/MaterialInterface.h"



ATTT_Grid::ATTT_Grid()
{
	PrimaryActorTick.bCanEverTick = false;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
    RootComponent = CollisionBox;

	CollisionBox->SetBoxExtent(FVector(50.0f, 50.0f, 5.0f));
    CollisionBox->SetCollisionProfileName(TEXT("UI"));
    //CollisionBox->OnComponentClicked.AddDynamic(this, &ATTT_Grid::OnBoxClicked);

	IconDecal = CreateDefaultSubobject<UDecalComponent>(TEXT("IconDecal"));
    IconDecal->SetupAttachment(RootComponent);
    IconDecal->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f)); 
    //IconDecal->SetDecalSize(FVector(40.0f, 40.0f, 1.0f));
}

void ATTT_Grid::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATTT_Grid::OnBoxClicked(UPrimitiveComponent* TouchedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    //OnCellClicked.Broadcast(GridRow, GridCol);
}

void ATTT_Grid::SetCellType(ECellType State)
{
    if (State == ECellType::Empty)
    {
        IconDecal->SetHiddenInGame(true);
    }
    else
    {
        IconDecal->SetHiddenInGame(false);
        // Здесь можно подгрузить материал X или O
    }
}