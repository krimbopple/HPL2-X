#ifndef HPL_POSTEFFECT_TONEMAP_H
#define HPL_POSTEFFECT_TONEMAP_H

#include "graphics/PostEffect.h"

namespace hpl {

	//------------------------------------------
	
	enum eTonemapType
	{
		eTonemapType_Reinhard,
		eTonemapType_ACES,
		eTonemapType_LastEnum
	};
	
	class cPostEffectParams_ToneMap : public iPostEffectParams
	{
	public:
		cPostEffectParams_ToneMap() : iPostEffectParams("ToneMap"),  
			mfExposure(1.0f),
			mfGamma(2.2f),
			mTonemapType(eTonemapType_ACES)
		{}
		
		kPostEffectParamsClassInit(cPostEffectParams_ToneMap)

		float mfExposure;
		float mfGamma;
		eTonemapType mTonemapType;
	};

	//------------------------------------------
	
	class cPostEffectType_ToneMap : public iPostEffectType
	{
	friend class cPostEffect_ToneMap;
	public:
		cPostEffectType_ToneMap(cGraphics *apGraphics, cResources *apResources);
		virtual ~cPostEffectType_ToneMap();

		iPostEffect *CreatePostEffect(iPostEffectParams *apParams);
	
	private:
		iGpuProgram *mpProgram;
	};
	
	//------------------------------------------

	class cPostEffect_ToneMap : public iPostEffect
	{
	public:
		cPostEffect_ToneMap(cGraphics *apGraphics,cResources *apResources, iPostEffectType *apType);
		~cPostEffect_ToneMap();

	private:
		void OnSetParams();
		iPostEffectParams *GetTypeSpecificParams() { return &mParams; }
		
		iTexture* RenderEffect(iTexture *apInputTexture, iFrameBuffer *apFinalTempBuffer);

		cPostEffectType_ToneMap *mpToneMapType;

		cPostEffectParams_ToneMap mParams;
	};

	//------------------------------------------

};
#endif
