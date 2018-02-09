#version 330 core
out vec4 FragColour;

uniform vec3 objColour;
uniform vec3 sunColour;

void main()
{
    //FragColour = vec4(sunColour * objColour, 1.0f);
    //loat gamma = 2.2f;
    FragColour = vec4(1.0f);
}
