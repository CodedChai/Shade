#version 330 core

layout (location = 0) out vec4 color;

uniform vec4 col;
uniform vec2 light_pos;

in DATA 
{
	vec4 pos;
	vec4 color;
} fs_in;

in vec4 pos;

void main()
{
	float intensity = 1.0 / length(fs_in.pos.xy - light_pos);
	// color = col * intensity;
	color = fs_in.color * intensity;
}