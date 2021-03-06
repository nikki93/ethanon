/*--------------------------------------------------------------------------------------
 Ethanon Engine (C) Copyright 2008-2012 Andre Santee
 http://www.asantee.net/ethanon/

	Permission is hereby granted, free of charge, to any person obtaining a copy of this
	software and associated documentation files (the "Software"), to deal in the
	Software without restriction, including without limitation the rights to use, copy,
	modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
	and to permit persons to whom the Software is furnished to do so, subject to the
	following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
	INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
	PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
	HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
	CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
	OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
--------------------------------------------------------------------------------------*/

#ifndef ETH_VERTEX_LIGHT_DIFFUSE_H_
#define ETH_VERTEX_LIGHT_DIFFUSE_H_

#include "ETHLightingProfile.h"

class ETHVertexLightDiffuse : public ETHLightingProfile
{
public:
	ETHVertexLightDiffuse(VideoPtr video, const str_type::string& shaderPath);

	bool BeginLightPass(ETHSpriteEntity *pRender, Vector3 &v3LightPos, const Vector2 &v2Size,
		const ETHLight* light, const float maxHeight, const float minHeight, const float lightIntensity,
		const bool drawToTarget);
	bool EndLightPass();

	bool IsSupportedByHardware() const;
	bool IsUsingPixelShader() const;
	SpritePtr GetDefaultNormalMap();

private:
	static const GS_SHADER_PROFILE m_profile;

	VideoPtr m_video;
	GS_ALPHA_MODE m_lastAM;
	ShaderPtr m_hVertexLightVS;
	ShaderPtr m_vVertexLightVS;
};

#endif