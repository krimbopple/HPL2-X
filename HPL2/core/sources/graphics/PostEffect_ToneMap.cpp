#include "graphics/PostEffect_ToneMap.h"

#include "graphics/Graphics.h"

#include "graphics/LowLevelGraphics.h"
#include "graphics/PostEffectComposite.h"
#include "graphics/FrameBuffer.h"
#include "graphics/Texture.h"
#include "graphics/GPUProgram.h"
#include "graphics/GPUShader.h"

#include "system/PreprocessParser.h"

namespace hpl {
	
	//////////////////////////////////////////////////////////////////////////
	// PROGRAM VARS
	//////////////////////////////////////////////////////////////////////////

	#define kVar_afExposure			0
	#define kVar_afGamma			1
	#define kVar_alTonemapType		2

	//////////////////////////////////////////////////////////////////////////
	// POST EFFECT BASE
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------
	
	cPostEffectType_ToneMap::cPostEffectType_ToneMap(cGraphics *apGraphics, cResources *apResources) : iPostEffectType("ToneMap",apGraphics,apResources)
	{
		cParserVarContainer vars;
		vars.Add("UseUv");

		mpProgram = mpGraphics->CreateGpuProgramFromShaders("ToneMap","deferred_base_vtx.glsl", "posteffect_tonemap_frag.glsl", &vars);
		if(mpProgram)
		{
			mpProgram->GetVariableAsId("afExposure",kVar_afExposure);
			mpProgram->GetVariableAsId("afGamma",kVar_afGamma);
			mpProgram->GetVariableAsId("alTonemapType", kVar_alTonemapType);
		}
	}
	
	//-----------------------------------------------------------------------

	cPostEffectType_ToneMap::~cPostEffectType_ToneMap()
	{

	}

	//-----------------------------------------------------------------------

	iPostEffect * cPostEffectType_ToneMap::CreatePostEffect(iPostEffectParams *apParams)
	{
		cPostEffect_ToneMap *pEffect = hplNew(cPostEffect_ToneMap, (mpGraphics,mpResources,this));
		cPostEffectParams_ToneMap *pToneMapParams = static_cast<cPostEffectParams_ToneMap*>(apParams);

		return pEffect;
	}
	
	//-----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// POST EFFECT
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	cPostEffect_ToneMap::cPostEffect_ToneMap(cGraphics *apGraphics, cResources *apResources, iPostEffectType *apType) : iPostEffect(apGraphics,apResources,apType)
	{
		mpToneMapType = static_cast<cPostEffectType_ToneMap*>(mpType);
	}

	//-----------------------------------------------------------------------

	cPostEffect_ToneMap::~cPostEffect_ToneMap()
	{

	}

	//-----------------------------------------------------------------------

	void cPostEffect_ToneMap::OnSetParams()
	{
	}

	//-----------------------------------------------------------------------


	iTexture* cPostEffect_ToneMap::RenderEffect(iTexture *apInputTexture, iFrameBuffer *apFinalTempBuffer)
	{
		/////////////////////////
		// Init render states
		mpCurrentComposite->SetFlatProjection();
		mpCurrentComposite->SetBlendMode(eMaterialBlendMode_None);
		mpCurrentComposite->SetChannelMode(eMaterialChannelMode_RGBA);
		mpCurrentComposite->SetTextureRange(NULL,1);

		/////////////////////////
		// Render to accum buffer
		// This function sets to frame buffer is post effect is last!
		SetFinalFrameBuffer(apFinalTempBuffer);

		mpCurrentComposite->SetProgram(mpToneMapType->mpProgram);
		
		if(mpToneMapType->mpProgram)
		{
			mpToneMapType->mpProgram->SetFloat(kVar_afExposure, mParams.mfExposure);
			mpToneMapType->mpProgram->SetFloat(kVar_afGamma, mParams.mfGamma);
			mpToneMapType->mpProgram->SetInt(kVar_alTonemapType, (int)mParams.mTonemapType);
		}
				
		mpCurrentComposite->SetTexture(0, apInputTexture);
					
		DrawQuad(0, 1, apInputTexture, true);

		mpCurrentComposite->SetProgram(NULL);
		mpCurrentComposite->SetBlendMode(eMaterialBlendMode_None);
		
		return apFinalTempBuffer->GetColorBuffer(0)->ToTexture();
	}

	//-----------------------------------------------------------------------

}
