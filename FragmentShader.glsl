#version 330

in vec4 ex_worldPosition;
in vec3 ex_worldNormal;

uniform vec3 lightPosition;
uniform vec3 viewPosition;

out vec4 out_Color;

void main () {


    vec3 lightColor = normalize(vec3(1,1,1));

    /* --> ambient <-- */
    float ambientStrength = 0.2;
    vec3 ambient = ambientStrength * lightColor;
    //vec4 ambient = vec4( 0.1, 0.1, 0.1, 1.0);



    //float dot_product = max(dot(normalize(lightPosition - ex_worldPosition.xyz), normalize(ex_worldNormal)), 0.0);
    //vec4 diffuse = dot_product * vec4( 0.385, 1.647, 0.812, 1.0);

    /* --> diffuse <-- */
    // fragment <-> svetlo
    vec3 lightDirection = normalize(lightPosition - ex_worldPosition.xyz);
    vec3 normal = normalize(ex_worldNormal);
    //svetlost 1-0
    float diffuseImpact = max(dot(normal,lightDirection),0.0);

    vec3  diffuse = diffuseImpact * lightColor;


    // zrdcadlovy odlesk
    float specularStrength = 1;
    // fragment <-> kamera
    vec3 viewDirection = normalize(viewPosition - vec3(ex_worldPosition));
    // vektor odraz
    vec3 reflectionDirection = normalize(reflect(normalize(ex_worldPosition.xyz - lightPosition), normalize(ex_worldNormal)));

    /*interval 0 - 256*/
    int shininess = 30;
    float specularTerm = pow(max(dot(reflectionDirection, viewDirection),0.0), shininess);


    vec3 specular = specularStrength * specularTerm * lightColor;

    if (diffuseImpact <= 0.0) { specular = vec3(0); }

    // premapovat na ve4
    vec3 result = (ambient + diffuse + specular) * normalize(vec3(70,255,180));
    out_Color = vec4(result, 1.0);


    //out_Color = ex_worldPosition;
}