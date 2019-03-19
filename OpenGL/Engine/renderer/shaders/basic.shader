[vertex]
#version core 330

layout (location=0) in vec3 aPos;
layout (location=1) in vec4 aColor;
layout (location=2) in vec2 aTexCoord;

out vec4 oColor;
out vec2 oTexCoord;

void main()
{
    oColor = aColor;
    oTexCoord = aTexCoord;
    gl_Position = vec4(aPos.xyz,1.0);
}

[fragment]
#version core 330

in vec4 oColor;
in vec2 oTexCoord;

uniform sampler2D uTexture;

out vec4 Frag_Color;

void main()
{
    Frag_Color = texture(uTexture, oTexCoord) * oColor;
}
