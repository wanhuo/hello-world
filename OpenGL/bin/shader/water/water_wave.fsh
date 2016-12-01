#version 330 core
//precision  highp    float;
uniform   sampler2D  u_baseMap;
uniform   sampler2D  u_noiseMap;

uniform   float     u_time;
uniform   vec2      u_resolution;
uniform   vec4      u_fragColor;
layout(location=0)out    vec4     outColor;

const   float PI = 3.1415926535897932;

//speed
const float speed = 0.2;
const float speed_x = 0.3;
const float speed_y = 0.3;

// geometry
const float intensity = 3.;
const int   steps = 8;
const float frequency = 4.0;
const int   angle = 7; // better when a prime

// reflection and emboss
const float delta = 25.0;
const float intence = 400.;
const float emboss = 0.3;

//varying    vec4     v_fragColor;
in    vec2    v_texCoord;
//---------- crystals effect

float col(vec2 coord)
{
    float delta_theta = 2.0 * PI / float(angle);
    float col = 0.0;
    float theta = 0.0;
    for (int i = 0; i < steps; i++)
    {
        vec2 adjc = coord;
        theta = delta_theta*float(i);
        adjc.x += cos(theta)*u_time*speed + u_time * speed_x;
        adjc.y -= sin(theta)*u_time*speed - u_time * speed_y;
        col = col + cos( (adjc.x*cos(theta) - adjc.y*sin(theta))*frequency)*intensity;
    }

    return cos(col);
}

void main()
{
    float  _noiseValue=1.0;//texture(u_noiseMap,v_texCoord).r;
    vec2 p = v_texCoord, c1 = p, c2 = p;
    float cc1 = col(c1);

    c2.x += u_resolution.x/delta;
    float dx = emboss*(cc1-col(c2))/delta*_noiseValue;

    c2.x = p.x;
    c2.y += u_resolution.y/delta;
    float dy = emboss*(cc1-col(c2))/delta;

    c1.x += dx;
    c1.y += dy;

    float alpha = 1.0+dot(dx,dy)*intence;
    outColor = texture(u_baseMap,c1)*alpha*u_fragColor;
}