#type vertex

#version 450 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCrood;

void main(){
    gl_Position = vec4(aPos, 1.0f);
}

#type fragment

#version 450 core		
layout(location = 0) out vec4 FragColor;

uniform vec4 u_Color;

void main()
{
    FragColor = u_Color;
}