/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere_uv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkuijte <alkuijte@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/10 11:21:12 by alkuijte      #+#    #+#                 */
/*   Updated: 2025/12/11 11:32:30 by alkuijte      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_math.h>
#include <math.h>

// Must be called before get_sphere_tangents
void	get_sphere_uv(t_uv *uv, t_vec3 p)
{
	uv->u = 0.5 + (atan2(p.z, p.x) / (PI * 2.0f));
	uv->v = 0.5 + (asin(p.y) / PI);
}
