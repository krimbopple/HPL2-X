////////////////////////////////////////////////////////
// Deferred Fog - Vertex Shader
//
//
////////////////////////////////////////////////////////
#version 130

//---------------------------------------------

out vec3 gvVertexPos;	

//---------------------------------------------

@ifdef OutsideBox && UseBackside
	out vec3 gvLocalBoxRay;
	
	uniform mat4 a_mtxBoxInvViewModelRotation;
@endif

//---------------------------------------------

///////////////////////////////
// Main program
void main()
{	
	//////////////////////
	// Position
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
	
	
	gvVertexPos = (gl_ModelViewMatrix * gl_Vertex).xyz;
	
	@ifdef OutsideBox && UseBackside
		gvLocalBoxRay = (a_mtxBoxInvViewModelRotation * vec4(gvVertexPos,1)).xyz;
	@endif
}