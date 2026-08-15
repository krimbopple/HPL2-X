#version 130
#extension GL_ARB_texture_rectangle : enable

uniform sampler2DRect aDiffuseMap;
@define sampler_aDiffuseMap 0

uniform float afExposure;
uniform float afGamma;
uniform int alTonemapType;

//--------------------------------------------------------------

float Reinhard(float x)
{
	return x / (1.0 + x);
}

//Narkowicz ACES approximation
vec3 ACESFilm(vec3 x)
{
	const float a = 2.51;
	const float b = 0.03;
	const float c = 2.43;
	const float d = 0.59;
	const float e = 0.14;
	return clamp((x*(a*x+b))/(x*(c*x+d)+e), 0.0, 1.0);
}

//--------------------------------------------------------------

void main()
{
	vec3 vColor = texture(aDiffuseMap, gl_TexCoord[0].xy).rgb;
	
	vColor *= afExposure;
	
	if(alTonemapType == 0)
	{
		vColor = vec3(Reinhard(vColor.r), Reinhard(vColor.g), Reinhard(vColor.b));
	}
	else
	{
		vColor = ACESFilm(vColor);
	}
	
	vColor = pow(max(vColor, vec3(0.0)), vec3(1.0/afGamma));
	
	gl_FragColor = vec4(vColor, 1.0);
}
