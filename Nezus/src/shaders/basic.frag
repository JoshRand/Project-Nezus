#version 330 core

layout (location = 0) out vec4 color;

uniform vec4 col;
uniform vec2 light_pos;
uniform vec2 light_pos2;

in vec4 pos;
in vec4 pos2;

void main()
{
	float intensity = 1.0f / length(pos.xy - light_pos );
	//float intensity2 = 1.0f / length(pos2.xy - light_pos2 );
	
	color = col * intensity;
}