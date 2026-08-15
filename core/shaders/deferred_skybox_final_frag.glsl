// Used to draw the sky box straight to the accumulation buffer
#version 130

uniform samplerCube aDiffuseMap;
@define sampler_aDiffuseMap 0

//------------------------------------

void main()
{
	vec3 vColor = texture(aDiffuseMap, gl_TexCoord[0].xyz).xyz;
	
	@ifdef LinearSpace
		vColor = pow(vColor, vec3(2.2));
	@endif
	
	gl_FragColor = vec4(vColor, 1.0);
}
