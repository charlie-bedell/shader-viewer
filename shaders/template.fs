#version 330 core

uniform float uTime;
uniform vec2 uMouse;
uniform vec2 uResolution;

out vec4 FragColor;

void main() {
    vec2 uv = gl_FragCoord.xy / uResolution.xy;
    float r = 0.5 + 0.5 * sin(uTime + uv.x * 10.0);
    float g = 0.5 + 0.5 * sin(uTime + uv.y * 10.0);
    float b = 0.5 + 0.5 * sin(uTime);
    FragColor = vec4(r, g, b, 1.0);
}
