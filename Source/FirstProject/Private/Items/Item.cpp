// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "FirstProject/DebugMacros.h"
#include "Components/SphereComponent.h"
#include "Characters/PedroCharacter.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));

	RootComponent = ItemMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnSphereOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AItem::OnSphereEndOverlap);
	/*UE_LOG(LogTemp, Warning, TEXT("Begin play called!"));

	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Orange, FString("GEngine used, debug message called!"));
	}
	UWorld* World = GetWorld();

	
	FVector Location = GetActorLocation();
	FVector Forward = GetActorForwardVector();

	DRAW_SPHERE(Location);
	DRAW_VECTOR(Location, Location + Forward * 100);
	DRAW_CYLINDER(Location);*/
}

float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

void AItem::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (APedroCharacter* PedroCharacter = Cast<APedroCharacter>(OtherActor))
	{
		PedroCharacter->SetOverlappingItem(this);
	}
}

void AItem::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (APedroCharacter* PedroCharacter = Cast<APedroCharacter>(OtherActor))
	{
		PedroCharacter->SetOverlappingItem(nullptr);
	}
}

// Called every frame
void AItem::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	//RunningTime += DeltaTime;

	/*UE_LOG(LogTemp, Warning, TEXT("Delta Time : %f"), DeltaTime);

	if (GEngine)
	{
		FString Name = GetName();

		FString Message = FString::Printf(TEXT("Item Name : %s"), *Name);

		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Orange, Message);

		UE_LOG(LogTemp, Warning, TEXT("Item Name : %s"), *Name);
	}
	// MovementRate = (cm/s)
	float MovementRate = 50.f;

	float RotationRate = 45.f;

	//MovementRate * DeltaTime = (cm/s) * (s/frame) = (cm/frame)
	AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, 0.f));

	AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));

	//float DeltaZ = AItem::TransformedSin(RunningTime);

	//AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));

	DRAW_SPHERE_SingleFrame(GetActorLocation());
	DRAW_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f)

	FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);
	DRAW_POINT_SingleFrame(AvgVector);*/

	//float RotationRate = 50.f;

	//AddActorWorldRotation(FRotator(0.f, 0.f, RotationRate * DeltaTime));
	
}

