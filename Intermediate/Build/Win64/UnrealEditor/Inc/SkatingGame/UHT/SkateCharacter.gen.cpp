// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SkatingGame/Public/SkateCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSkateCharacter() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
SKATINGGAME_API UClass* Z_Construct_UClass_ASkateCharacter();
SKATINGGAME_API UClass* Z_Construct_UClass_ASkateCharacter_NoRegister();
UPackage* Z_Construct_UPackage__Script_SkatingGame();
// End Cross Module References

// Begin Class ASkateCharacter
void ASkateCharacter::StaticRegisterNativesASkateCharacter()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASkateCharacter);
UClass* Z_Construct_UClass_ASkateCharacter_NoRegister()
{
	return ASkateCharacter::StaticClass();
}
struct Z_Construct_UClass_ASkateCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "SkateCharacter.h" },
		{ "ModuleRelativePath", "Public/SkateCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputMapping_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Input mapping\n" },
#endif
		{ "ModuleRelativePath", "Public/SkateCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Input mapping" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/SkateCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeedUpAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/SkateCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpInputAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/SkateCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InputMapping;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpeedUpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpInputAction;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASkateCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASkateCharacter_Statics::NewProp_InputMapping = { "InputMapping", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASkateCharacter, InputMapping), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputMapping_MetaData), NewProp_InputMapping_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASkateCharacter_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASkateCharacter, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASkateCharacter_Statics::NewProp_SpeedUpAction = { "SpeedUpAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASkateCharacter, SpeedUpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeedUpAction_MetaData), NewProp_SpeedUpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASkateCharacter_Statics::NewProp_JumpInputAction = { "JumpInputAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASkateCharacter, JumpInputAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpInputAction_MetaData), NewProp_JumpInputAction_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASkateCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASkateCharacter_Statics::NewProp_InputMapping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASkateCharacter_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASkateCharacter_Statics::NewProp_SpeedUpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASkateCharacter_Statics::NewProp_JumpInputAction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASkateCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ASkateCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_SkatingGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASkateCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASkateCharacter_Statics::ClassParams = {
	&ASkateCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ASkateCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ASkateCharacter_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASkateCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_ASkateCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASkateCharacter()
{
	if (!Z_Registration_Info_UClass_ASkateCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASkateCharacter.OuterSingleton, Z_Construct_UClass_ASkateCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASkateCharacter.OuterSingleton;
}
template<> SKATINGGAME_API UClass* StaticClass<ASkateCharacter>()
{
	return ASkateCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASkateCharacter);
ASkateCharacter::~ASkateCharacter() {}
// End Class ASkateCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Administrator_Documents_Unreal_Projects_SkatingGame_Source_SkatingGame_Public_SkateCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASkateCharacter, ASkateCharacter::StaticClass, TEXT("ASkateCharacter"), &Z_Registration_Info_UClass_ASkateCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASkateCharacter), 2708025062U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Administrator_Documents_Unreal_Projects_SkatingGame_Source_SkatingGame_Public_SkateCharacter_h_928928023(TEXT("/Script/SkatingGame"),
	Z_CompiledInDeferFile_FID_Users_Administrator_Documents_Unreal_Projects_SkatingGame_Source_SkatingGame_Public_SkateCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Administrator_Documents_Unreal_Projects_SkatingGame_Source_SkatingGame_Public_SkateCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
