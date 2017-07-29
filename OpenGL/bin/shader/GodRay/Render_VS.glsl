#version 330 core
layout(location=0)in	vec4	a_position;
layout(location=1)in	vec2	a_fragCoord;

uniform		mat4	g_ModelViewProjMatrix;

out		vec2	v_fragCoord;

void 	main()
{
	gl_Position = g_ModelViewProjMatrix * a_position;
	v_fragCoord = a_fragCoord;
}