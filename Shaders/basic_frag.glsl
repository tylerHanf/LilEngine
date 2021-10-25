#version 450 core

out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 objColor;
uniform float ambientStrength;

void main() {
     vec3 ambient = ambientStrength * lightColor;
     vec3 norm = normalize(Normal);
     vec3 lightDir = normalize(lightPos - FragPos);
     float diff = max(dot(norm, lightDir), 0.0);
     vec3 diffuse = diff * lightColor;

     vec3 result = (ambient + diffuse) * objColor;
     FragColor = vec4(result, 1.0);
}
