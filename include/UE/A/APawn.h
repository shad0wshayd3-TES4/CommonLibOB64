#pragma once

#include "UE/A/AActor.h"
#include "UE/E/EAutoPossessAI.h"
#include "UE/E/EAutoReceiveInput.h"
#include "UE/F/FQuat.h"
#include "UE/I/INavAgentInterface.h"
#include "UE/T/TBaseDynamicMulticastDelegate.h"
#include "UE/T/TSparseDynamicDelegate.h"
#include "UE/T/TSubclassOf.h"

namespace UE
{
	class AController;
	class APlayerState;
	class FPawnControllerChangedSignatureInfoGetter;
	class FPawnRestartedSignatureInfoGetter;
	class UPawnMovementComponent;
	class UPawnNoiseEmitterComponent;

	using FPawnControllerChangedSignature_MCSignature = TBaseDynamicMulticastDelegate<FNotThreadSafeDelegateMode, void, APawn*, AController*, AController*>;
	using FPawnControllerChangedSignature = TSparseDynamicDelegate<FPawnControllerChangedSignature_MCSignature, APawn, FPawnControllerChangedSignatureInfoGetter>;
	using FPawnRestartedSignature_MCSignature = TBaseDynamicMulticastDelegate<FNotThreadSafeDelegateMode, void, APawn*>;
	using FPawnRestartedSignature = TSparseDynamicDelegate<FPawnRestartedSignature_MCSignature, APawn, FPawnRestartedSignatureInfoGetter>;

	class APawn :
		public AActor,
		public INavAgentInterface
	{
	public:
		UE_DEFINE_UOBJECT(APawn, AActor, "Engine", "Pawn");

		// override
		virtual ~APawn();  // 000

		// add
		virtual UPawnMovementComponent*     GetMovementComponent();                                                                                          //
		virtual UPrimitiveComponent*        GetMovementBase();                                                                                               //
		virtual UPawnNoiseEmitterComponent* GetPawnNoiseEmitterComponent();                                                                                  //
		virtual void                        OnPlayerStateChanged(APlayerState* a_new, APlayerState* a_old);                                                  //
		virtual void                        TurnOff();                                                                                                       //
		virtual void                        PawnStartFire(std::uint8_t a_mode);                                                                              //
		virtual APhysicsVolume*             GetPawnPhysicsVolume();                                                                                          //
		virtual bool                        ReachedDesiredRotation();                                                                                        //
		virtual float                       GetDefaultHalfHeight();                                                                                          //
		virtual bool                        IsPawnControlled();                                                                                              //
		virtual void                        OnRep_Controller();                                                                                              //
		virtual void                        OnRep_PlayerState();                                                                                             //
		virtual void                        UpdateNavigationRelevance();                                                                                     //
		virtual bool                        ShouldTakeDamage(float a_damage, const FDamageEvent* a_event, AController* a_eventInstigator, AActor* a_cause);  //
		virtual FVector                     GetGravityDirection();                                                                                           //
		virtual FQuat                       GetGravityTransform();                                                                                           //
		virtual void                        SetPlayerDefaults();                                                                                             //
		virtual void                        RecalculateBaseEyeHeight();                                                                                      //
		virtual void                        PossessedBy(AController* a_controller);                                                                          //
		virtual void                        UnPossessed();                                                                                                   //
		virtual void                        NotifyControllerChanged();                                                                                       //
		virtual void                        NotifyRestarted();                                                                                               //
		virtual void                        Restart();                                                                                                       //
		virtual void                        PawnClientRestart();                                                                                             //
		virtual bool                        IsLocallyControlled();                                                                                           //
		virtual bool                        IsPlayerControlled();                                                                                            //
		virtual bool                        IsBotControlled();                                                                                               //
		virtual FRotator                    GetViewRotation();                                                                                               //
		virtual FVector                     GetPawnViewLocation();                                                                                           //
		virtual FRotator                    GetBaseAimRotation();                                                                                            //
		virtual bool                        InFreeCam();                                                                                                     //
		virtual void                        FaceRotation(FRotator a_rotation, float a_deltaTime = 0.0F);                                                     //
		virtual void                        DetachFromControllerPendingDestroy();                                                                            //
		virtual void                        SpawnDefaultController();                                                                                        //
		virtual AController*                GetDamageInstigator(AController* a_instigatedBy, const UDamageType& a_damageType);                               //
		virtual UInputComponent*            CreatePlayerInputComponent();                                                                                    //
		virtual void                        DestroyPlayerInputComponent();                                                                                   //
		virtual void                        SetupPlayerInputComponent(UInputComponent* a_component);                                                         //
		virtual void                        AddMovementInput(FVector a_worldDirection, float a_scale = 1.0F, bool a_force = false);                          //
		virtual FVector                     ConsumeMovementInputVector();                                                                                    //
		virtual void                        AddControllerPitchInput(float a_value);                                                                          //
		virtual void                        AddControllerYawInput(float a_value);                                                                            //
		virtual void                        AddControllerRollInput(float a_value);                                                                           //
		virtual bool                        IsMoveInputIgnored();                                                                                            //

		// members
		std::uint32_t                   useControllerRotationPitch: 1;     // 2A0:0
		std::uint32_t                   useControllerRotationYaw: 1;       // 2A0:1
		std::uint32_t                   useControllerRotationRoll: 1;      // 2A0:2
		std::uint32_t                   canAffectNavigationGeneration: 1;  // 2A0:3
		std::uint32_t                   inputEnabled: 1;                   // 2A0:4
		std::uint32_t                   processingOutsideWorldBounds: 1;   // 2A0:5
		std::uint32_t                   isLocalViewTarget: 1;              // 2A0:6
		float                           baseEyeHeight;                     // 2A4
		TEnumAsByte<EAutoReceiveInput>  autoPossessPlayer;                 // 2A8
		EAutoPossessAI                  autoPossessAI;                     // 2A9
		std::uint8_t                    remoteViewPitch;                   // 2AA
		TSubclassOf<AController>        aiControllerClass;                 // 2B0
		TObjectPtr<APlayerState>        playerState;                       // 2B8
		float                           blendedReplayViewPitch;            // 2C0
		TObjectPtr<AController>         lastHitBy;                         // 2C4
		TObjectPtr<AController>         controller;                        // 2D0
		TObjectPtr<AController>         previousController;                // 2D8
		float                           allowedYawError;                   // 2E0
		FPawnControllerChangedSignature receiveControllerChangedDelegate;  // 2E4
		FPawnRestartedSignature         receiveRestartedDelegate;          // 2E5
		FVector                         controlInputVector;                // 2E8
		FVector                         lastControlInputVector;            // 300
		TSubclassOf<UInputComponent>    overrideInputComponentClass;       // 318
	};
	static_assert(sizeof(APawn) == 0x320);
}
