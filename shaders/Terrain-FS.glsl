#version 330
in vec3 worldPosition;
in vec3 worldNormal;

out vec4 outColor;

uniform sampler2D grassTexture;
uniform sampler2D snowTexture;
uniform sampler2D waterTexture;

vec4 calculateTexture(vec2 pos, float height);

void main()
{
    vec3 svetlo = abs(worldNormal);
    svetlo = max(svetlo, 0.0001);
    svetlo = pow(svetlo, vec3(1, 5, 1));

    float scale = 0.5f;
    float height = worldPosition.y;
    vec4 axisX = calculateTexture(worldPosition.yz * scale, height) * svetlo.x;
    vec4 axisY = calculateTexture(worldPosition.xz * scale, height) * svetlo.y;
    vec4 axisZ = calculateTexture(worldPosition.xy * scale, height) * svetlo.z;

    outColor = axisX + axisY + axisZ;

    //outColor = vec4(abs(worldNormal), 1.0f);
    //outColor = vec4(color, 1.0f);
    //outColor = vec4(1.0f);
}

vec4 calculateTexture(vec2 pos, float height)
{
    float t = 0.5f; // vyska vrstva
    float l1 = -4.f; // konec vody
    float l2 = 3.f;  // konec travy

    // smooth dela plynuly prechod vraci 1,0 podle toho u jakych bodu je bliz vyska. umi i pomyl prechod WIKI
    vec4 result = mix(texture(waterTexture, pos), texture(grassTexture, pos), smoothstep(l1 - t, l1 + t, height));
    result = mix(result, texture(snowTexture, pos), smoothstep(l2 - t, l2 + t, height));

    return result;
}