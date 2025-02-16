#version 330 core

uniform float uTime;
uniform vec2 uMouse;
uniform vec2 uResolution;

out vec4 FragColor;

float plot(vec2 uv) {
	return smoothstep(0.02, 0.0, abs(uv.y - uv.x));
}

void main() {
	vec2 uv = gl_FragCoord.xy/uResolution;

	float y = uv.x;

	vec3 color = vec3(y);

	float pct = plot(uv);
	color = (1.0-pct)*color+pct*vec3(0.0, 1.0, 0.0);

	FragColor = vec4(color, 1.0);
}
