////////////////////////////////////////////////////////
// PostEffect Bloom Blur - Fragment Shader
//
// Blur effect for the bloom post effect
////////////////////////////////////////////////////////
#version 130

#extension GL_ARB_texture_rectangle : enable

uniform sampler2DRect blurMap;
@define sampler_blurMap 0

uniform sampler2DRect diffuseMap;
@define sampler_diffuseMap 1

uniform vec3 avRgbToIntensity;

void main()
{
	vec4 vBlurColor = 	texture(blurMap, 	  gl_TexCoord[0].xy);
	vec4 vDiffuseColor = 	texture(diffuseMap, gl_TexCoord[1].xy);
	
	vBlurColor *= vBlurColor * dot(vBlurColor.xyz, avRgbToIntensity);
	
	gl_FragColor = vDiffuseColor + vBlurColor;
}