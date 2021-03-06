in vec4 Position;
in vec3 Normal;
out vec3 vNormal;
uniform mat4 ModelviewProjection;
uniform mat3 NormalMatrix;

void main()
{
    vNormal = NormalMatrix * Normal;
    gl_Position = ModelviewProjection * Position;
}
