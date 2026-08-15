#version 120

uniform sampler2D aDiffuseMap;
@define sampler_aDiffuseMap 0

uniform float afGamma;

void main()
{
	vec3 vColor = texture2D(aDiffuseMap, gl_TexCoord[0].xy).rgb;
	vColor = pow(max(vColor, vec3(0.0)), vec3(afGamma));

	gl_FragColor = vec4(vColor, 1.0);
}
