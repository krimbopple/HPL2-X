////////////////////////////////////////////////////////
// Deferred Illumination - Fragment Shader
//
// Used in a sepperate pass to render illuminating parts of a material.
////////////////////////////////////////////////////////
#version 130

uniform sampler2D aDiffuse;
@define sampler_aDiffuse 0

uniform float afColorMul;

void main()
{
	vec4 vColor = texture(aDiffuse, gl_TexCoord[0].xy);
	
	@ifdef LinearSpace
		vColor.rgb = pow(vColor.rgb, vec3(2.2));
	@endif
	
	gl_FragColor = vColor * afColorMul;
}