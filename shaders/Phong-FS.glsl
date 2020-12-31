#version 330

#define LIGHT 10

struct Light {
    vec3 position;
    vec3 direction;
    int lightType;
    float cutOff;
};


in vec4 ex_worldPosition;
in vec3 ex_worldNormal;
in vec2 texCoord;


uniform vec3 lightPosition;
uniform vec3 viewPosition;
uniform vec3 lightArray[5];

uniform Light lightObjects[LIGHT];
uniform int light_count;

uniform sampler2D textura;
out vec4 out_Color;



vec3 point_light(vec3 color,Light l,vec3 worldPos) {

    float distance    = length(l.position - worldPos);

    float utlum = clamp(5.0 / distance, 0.0, 1.0);



    float dot_product = max(dot(normalize(l.position - worldPos.xyz), normalize(ex_worldNormal)), 0.0);
    vec3 diffuse = dot_product * color* utlum; //vec3( 0.385, 1.0, 0.812);

    vec3 V = normalize(viewPosition - vec3(worldPos));
    vec3 R = normalize(reflect(normalize(worldPos.xyz - l.position), normalize(ex_worldNormal)));
    float specularTerm = pow(max(dot(R, V),0.0), 64);

    vec3 specular = vec3(0);
    if(dot_product > 0.0){
        vec3 specular = vec3(1,1,1) * specularTerm;
    }

    return diffuse + specular;
}


vec3 direction_light(vec3 color,Light l,vec3 worldPos) {

    float dot_product = max(dot(normalize(l.direction - worldPos.xyz), normalize(ex_worldNormal)), 0.0);
    vec3 diffuse = dot_product * color; // misto vec 3 barvu svetla

    vec3 V = normalize(viewPosition - vec3(worldPos));
    vec3 R = normalize(reflect(normalize(worldPos.xyz - l.direction), normalize(ex_worldNormal)));
    float specularTerm = pow(max(dot(R, V),0.0), 64);

    vec3 specular = vec3(0);
    if(dot_product > 0.0){
        vec3 specular = vec3(1,1,1) * specularTerm;
    }

    return (diffuse + specular );
}

vec3 spot_light(vec3 color,Light l,vec3 worldPos) {

    vec3 lightDir = normalize(l.position - worldPos);
    float theta     = dot(lightDir, normalize(-l.direction));

    if (theta <= l.cutOff) {
        return vec3(0.0, 0.0, 0.0);
    }

    float dot_product = max(dot(normalize(l.position - worldPos.xyz), normalize(ex_worldNormal)), 0.0);
    vec3 diffuse = dot_product * color;

    vec3 V = normalize(viewPosition - vec3(worldPos));
    vec3 R = normalize(reflect(normalize(worldPos.xyz - l.position), normalize(ex_worldNormal)));
    float specularTerm = pow(max(dot(R, V),0.0), 64);

    vec3 specular = vec3(0);
    if(dot_product > 0.0){
        vec3 specular = vec3(1,1,1) * specularTerm;
    }
    return diffuse + specular;
}



void main () {
    vec3 ambient = vec3( 0.1, 0.1, 0.1);

    vec3 worldPos = vec3(ex_worldPosition);


    vec4 texur = texture(textura, texCoord);
    vec3 color_in = vec3(texur.x, texur.y, texur.z);
    vec3 color_out = vec3(0);

    for (int index = 0; index < light_count; ++index) {
        switch(lightObjects[index].lightType){
            case 1:
                color_out += point_light(color_in,lightObjects[index],worldPos);
                break;
            case 2:
                color_out += direction_light(color_in,lightObjects[index],worldPos);
                break;
            case 3:
                color_out += spot_light(color_in,lightObjects[index],worldPos);
                break;
        }
    }

    out_Color =  vec4( color_out + ambient, 1.0);
    //out_Color =  vec4(texCoord,0,0);

}



