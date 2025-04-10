// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSkatingGame_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_SkatingGame;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_SkatingGame()
	{
		if (!Z_Registration_Info_UPackage__Script_SkatingGame.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/SkatingGame",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x76A7ED9A,
				0x7E2ED864,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_SkatingGame.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_SkatingGame.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_SkatingGame(Z_Construct_UPackage__Script_SkatingGame, TEXT("/Script/SkatingGame"), Z_Registration_Info_UPackage__Script_SkatingGame, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x76A7ED9A, 0x7E2ED864));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
