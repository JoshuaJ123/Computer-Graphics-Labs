#version 330 core

in vec2 UV;
//in vec2 TexCoord;

out vec3 colour;
//out vec4 FragColour;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    //vec2 flipped = vec2(1.0 - UV.x, UV.y);
    //FragColour = texture(texture1, flipped);

    colour = vec3(mix(texture(texture1, UV), texture(texture2, UV), 0.7)); 

    //exercise 3

    //blend 2 textures
    //vec4 texColour1 = texture(texture1, UV);
    //vec4 texColour2 = texture(texture2, UV);
    //vec4 mixColour = mix(texColour1, texColour2, 0.5);

    //swap red and green components
    //FragColour = vec4(mixColour.g, mixColour.r, mixColour.b, mixColour.a);
}
