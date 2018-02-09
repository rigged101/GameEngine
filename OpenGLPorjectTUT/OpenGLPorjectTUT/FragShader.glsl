#version 330 core
out vec4 FragColour;

struct TexMaterial{
    sampler2D diffuse;
    vec3 specular;
    float shininess;
};

struct Light{
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};


in vec3 normal;
in vec3 FragPos;
in vec2 texCoord;

uniform vec3 viewPos;
uniform TexMaterial texMaterial;
uniform Light light;

void main()
{

    vec3 ambient = light.ambient * texture(texMaterial.diffuse, texCoord).rgb;

    vec3 m_norm = normalize(normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(m_norm, lightDir), 0.0f);
    vec3 diffuse = light.diffuse * diff * texture(texMaterial.diffuse, texCoord).rgb;

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectionDir = reflect(-lightDir, m_norm);
    float m_specular = pow(max(dot(viewDir, reflectionDir), 0.0f), texMaterial.shininess);
    vec3 specular = light.specular * (m_specular * texMaterial.specular);

    vec3 result = ambient + diffuse + specular;
   // float gamma = 2.2f;
    FragColour = vec4(result, 1.0f);
    //FragColour.rgb = pow(result.rgb, vec3((1.0f/gamma)));

}