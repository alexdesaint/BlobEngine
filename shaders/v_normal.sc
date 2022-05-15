$input a_position, a_normal, a_tangent, a_color0, a_texcoord0
$output v_wpos, v_color0, v_view, v_normal, v_tangent, v_bitangent, v_texcoord0

#include <bgfx_shader.sh>

void main()
{
	v_wpos = mul(u_model[0], vec4(a_position, 1.0)).xyz;
	v_texcoord0 = a_texcoord0;
	v_normal = normalize(mul(u_model[0], vec4(a_normal.xyz, 0.0)).xyz);
	v_color0 = a_color0;
	gl_Position = mul(u_viewProj, vec4(v_wpos, 1.0));
	v_color0 = a_color0;
}
