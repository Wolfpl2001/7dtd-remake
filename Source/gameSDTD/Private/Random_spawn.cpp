// Fill out your copyright notice in the Description page of Project Settings.


#include "Random_spawn.h"

Random_spawn::Random_spawn()
{
    void AYourGameMode::RespawnPlayer(AController * PlayerController)
    {
        TArray<AActor*> PlayerStarts;
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), PlayerStarts);

        if (PlayerStarts.Num() > 0)
        {
            int32 RandomIndex = FMath::RandRange(0, PlayerStarts.Num() - 1);
            AActor* RandomSpawnPoint = PlayerStarts[RandomIndex];

            if (RandomSpawnPoint)
            {
                APawn* NewPawn = GetWorld()->SpawnActor<APawn>(DefaultPawnClass, RandomSpawnPoint->GetActorLocation(), RandomSpawnPoint->GetActorRotation());
                PlayerController->Possess(NewPawn);
            }
        }
    }

}

Random_spawn::~Random_spawn()
{
}
