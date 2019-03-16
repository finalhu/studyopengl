#version 330 core

out vec4 FragColor;

in vec3 Normal;
in vec3 Positon;

uniform vec3 cameraPos;
uniform samplerCube skybox;

void main()
{
	vec3 I = normalize(Positon - cameraPos);
	vec3 R = reflect(I, normalize(Normal));
	FragColor = vec4(texture(skybox, R).rgb, 1.0f);
}