#include "CoreMinimal.h"
#include "FPSProjectile.h"
#include "FPSGameMode.h"
#include "FPSCharacter.h"
#include "GameFramework/GameModeBase.h"
#include <exception>
#include "Kismet/GameplayStatics.h"

// ����Ĭ��ֵ
AFPSProjectile::AFPSProjectile()
{
	// ���� actor ��Ϊÿ֡���� Tick()������Ҫʱ�ɽ��˹رգ���������ܡ�
	PrimaryActorTick.bCanEverTick = true;

	// ʹ������������ײ��
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
	CollisionComponent->OnComponentHit.AddDynamic(this, &AFPSProjectile::OnHit);
	// �����������ײ�뾶��
	CollisionComponent->InitSphereRadius(15.0f);
	// ����ײ�����Ϊ�������
	RootComponent = CollisionComponent;

	// ʹ�ô���������˷�������˶���
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
	ProjectileMovementComponent->InitialSpeed = 3000.0f;
	ProjectileMovementComponent->MaxSpeed = 3000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = true;
	ProjectileMovementComponent->Bounciness = 0.3f;

	// 3 ���������
	InitialLifeSpan = 3.0f;
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Project"));
}

// ��Ϸ��ʼʱ������ʱ����
void AFPSProjectile::BeginPlay()
{
	Super::BeginPlay();
}

// ÿ֡����
void AFPSProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	static float timeval = 0;
	timeval += DeltaTime;
	if (timeval > InitialLifeSpan)
	{
		//this->Destroy();
	}

}

// �ڷ��䷽�������÷�������ٶȵĺ�����
void AFPSProjectile::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}

// ��������������ʱ���õĺ�����
void AFPSProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{

	if (OtherActor != this && OtherActor && OtherActor->GetName().Equals("Target_5"))
	{
		AFPSCharacter::Score++;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Target"));
		this->Destroy();
	}
	

}