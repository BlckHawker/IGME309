#version 330

in vec3 Color;

uniform vec3 SolidColor = vec3(-1,-1,-1);
uniform bool Complimentary = false;

out vec4 Fragment;

void main()
{
	vec3 colors = Color;
	if(SolidColor.r != -1.0 && SolidColor.g != -1.0 && SolidColor.b != -1.0)
	{
		colors = SolidColor;
	}
	
	if(Complimentary)
	{
		colors = vec3(1.0f, 1.0f, 1.0f) - colors;
	}
	
	Fragment = vec4(colors,1);
		
	return;
}