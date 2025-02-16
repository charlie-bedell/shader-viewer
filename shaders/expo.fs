// Author: Inigo Quiles
// Title: Expo
#version 330 core

#define PI 3.14159265359

uniform vec2 uResolution;
uniform vec2 uMouse;
uniform float uTime;

out vec4 FragColor;

float plot(vec2 st, float pct){
  return  smoothstep( pct-0.02, pct, st.y) -
          smoothstep( pct, pct+0.02, st.y);
}

void main() {
    vec2 st = gl_FragCoord.xy/uResolution;

    float y = pow(st.x,5.0);

    vec3 color = vec3(y);

    float pct = plot(st,y);
    color = (1.0-pct)*color+pct*vec3(0.0,1.0,0.0);

    FragColor = vec4(color,1.0);
}
