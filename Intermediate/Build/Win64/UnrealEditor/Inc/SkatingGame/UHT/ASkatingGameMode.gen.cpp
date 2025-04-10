// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SkatingGame/ASkatingGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeASkatingGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
SKATINGGAME_API UClass* Z_Construct_UClass_ASkatingGameMode();
SKATINGGAME_API UClass* Z_Construct_UClass_ASkatingGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_SkatingGame();
// End Cross Module References

// Begin Class ASkatingGameMode
void ASkatingGameMode::StaticRegisterNativesASkatingGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASkatingGameMode);
UClass* Z_Construct_UClass_ASkatingGameMode_NoRegister()
{
	return ASkatingGameMode::StaticClass();
}
struct Z_Construct_UClass_ASkatingGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "ASkatingGameMode.h" },
		{ "ModuleRelativePath", "ASkatingGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASkatingGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ASkatingGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SkatingGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASkatingGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASkatingGameMode_Statics::ClassParams = {
	&ASkatingGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASkatingGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ASkatingGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASkatingGameMode()
{
	if (!Z_Registration_Info_UClass_ASkatingGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASkatingGameMode.OuterSingleton, Z_Construct_UClass_ASkatingGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASkatingGameMode.OuterSingleton;
}
template<> SKATINGGAME_API UClass* StaticClass<ASkatingGameMode>()
{
	return ASkatingGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASkatingGameMode);
ASkatingGameMode::~ASkatingGameMode() {}
// End Class ASkatingGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Administrator_Documents_Unreal_Projects_SkatingGame_Source_SkatingGame_ASkatingGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASkatingGameMode, ASkatingGameMode::StaticClass, TEXT("ASkatingGameMode"), &Z_Registration_Info_UClass_ASkatingGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASkatingGameMode), 3928213534U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Administrator_Documents_Unreal_Projects_SkatingGame_Source_SkatingGame_ASkatingGameMode_h_313345308(TEXT("/Script/SkatingGame"),
	Z_CompiledInDeferFile_FID_Users_Administrator_Documents_Unreal_Projects_SkatingGame_Source_SkatingGame_ASkatingGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Administrator_Documents_Unreal_Projects_SkatingGame_Source_SkatingGame_ASkatingGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
