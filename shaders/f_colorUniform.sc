$input v_wpos, v_color0, v_view, v_normal, v_tangent, v_bitangent, v_texcoord0

#include <bgfx_shader.sh>
#include "shaderlib.sh"

uniform vec4 u_lightPosRadius;
uniform vec4 u_color;

vec2 blinn(vec3 _lightDir, vec3 _normal, vec3 _viewDir)
{
	float ndotl = dot(_normal, _lightDir);
	//vec3 reflected = _lightDir - 2.0*ndotl*_normal; // reflect(_lightDir, _normal);
	vec3 reflected = 2.0*ndotl*_normal - _lightDir;
	float rdotv = dot(reflected, _viewDir);
	return vec2(ndotl, rdotv);
}

float fresnel(float _ndotl, float _bias, float _pow)
{
	float facing = (1.0 - _ndotl);
	return max(_bias + (1.0 - _bias) * pow(facing, _pow), 0.0);
}

vec4 lit(float _ndotl, float _rdotv, float _m)
{
	float diff = max(0.0, _ndotl);
	float spec = step(0.0, _ndotl) * max(0.0, _rdotv * _m);
	return vec4(1.0, diff, spec, 1.0);
}

vec4 powRgba(vec4 _rgba, float _pow)
{
	vec4 result;
	result.xyz = pow(_rgba.xyz, vec3_splat(_pow) );
	result.w = _rgba.w;
	return result;
}

vec3 calculateLight(
	vec3 _lightPosition,
	float _lightPower,
	float _lightInnerR,
	mat3 _tbn, 
	vec3 _wpos, 
	vec3 _normal, 
	vec3 _view)
{
	vec3 lp = _lightPosition - _wpos;
	float attn = 1.0 - smoothstep(_lightInnerR, 1.0, length(lp) / _lightPower);
	vec3 lightDir = mul( normalize(lp), _tbn );
	vec2 bln = blinn(lightDir, _normal, _view);
	vec4 lc = lit(bln.x, bln.y, 1.0);
	vec3 rgb = saturate(lc.y) * attn;
	return rgb;
}

void main()
{
	mat3 tbn = mtxFromCols(v_tangent, v_bitangent, v_normal);

	vec3 lightColor = calculateLight(u_lightPosRadius.xyz, u_lightPosRadius.w, 1, tbn, v_wpos, v_normal, v_view);

	//gl_FragColor.xyz = max(vec3_splat(0.05), lightColor.xyz) * v_color0.xyz;
	gl_FragColor = u_color;
	gl_FragColor.w = 1.0;
	gl_FragColor = toGamma(gl_FragColor);
}
