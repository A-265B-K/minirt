/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   minirt_math_superquadrics.h                             :+:    :+:       */
/*                                                          +:+               */
/*   By: mde-beer <mde-beer@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2025/10/01 17:07:16 by mde-beer            #+#    #+#           */
/*   Updated: 2025/10/28 19:58:27 by mde-beer            ########   odam.nl   */
/*                                                                            */
/*   —————No norm compliance?——————                                           */
/*   ⠀⣞⢽⢪⢣⢣⢣⢫⡺⡵⣝⡮⣗⢷⢽⢽⢽⣮⡷⡽⣜⣜⢮⢺⣜⢷⢽⢝⡽⣝                                           */
/*   ⠸⡸⠜⠕⠕⠁⢁⢇⢏⢽⢺⣪⡳⡝⣎⣏⢯⢞⡿⣟⣷⣳⢯⡷⣽⢽⢯⣳⣫⠇                                           */
/*   ⠀⠀⢀⢀⢄⢬⢪⡪⡎⣆⡈⠚⠜⠕⠇⠗⠝⢕⢯⢫⣞⣯⣿⣻⡽⣏⢗⣗⠏⠀                                           */
/*   ⠀⠪⡪⡪⣪⢪⢺⢸⢢⢓⢆⢤⢀⠀⠀⠀⠀⠈⢊⢞⡾⣿⡯⣏⢮⠷⠁⠀⠀⠀                                           */
/*   ⠀⠀⠀⠈⠊⠆⡃⠕⢕⢇⢇⢇⢇⢇⢏⢎⢎⢆⢄⠀⢑⣽⣿⢝⠲⠉⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⠀⡿⠂⠠⠀⡇⢇⠕⢈⣀⠀⠁⠡⠣⡣⡫⣂⣿⠯⢪⠰⠂⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⡦⡙⡂⢀⢤⢣⠣⡈⣾⡃⠠⠄⠀⡄⢱⣌⣶⢏⢊⠂⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⢝⡲⣜⡮⡏⢎⢌⢂⠙⠢⠐⢀⢘⢵⣽⣿⡿⠁⠁⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⠨⣺⡺⡕⡕⡱⡑⡆⡕⡅⡕⡜⡼⢽⡻⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⣼⣳⣫⣾⣵⣗⡵⡱⡡⢣⢑⢕⢜⢕⡝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⣴⣿⣾⣿⣿⣿⡿⡽⡑⢌⠪⡢⡣⣣⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⡟⡾⣿⢿⢿⢵⣽⣾⣼⣘⢸⢸⣞⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ⠀⠀⠀⠀⠁⠇⠡⠩⡫⢿⣝⡻⡮⣒⢽⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           */
/*   ——————————————————————————————                                           */
/* ************************************************************************** */

#ifndef MINIRT_MATH_SUPERQUADRICS_H
# define MINIRT_MATH_SUPERQUADRICS_H

# include <minirt_declarations.h>
/*	Naming conventions
 *	sq_.* => functions belonging to the superquadric interface
 *	.*_e_.* => infix for functions belonging to the ellipsoid interface
 *	.*_h1_.* => infix for functions belonging to the hyperboloids of one sheet
 *	interface
 *	.*_h2_.* => infix for functions belonging to the hyperboloids of two sheets
 *	interface
 *	.*_t_.* => infix for functions belonging to the torus interface
 *	.*wp_op() => convert point in world-space to object-space
 *	.*wl_ol() => convert line in world-space to object-space
 *	.*_io() => determine wether a point in world-space is inside a given object
 *		return > 1 => outside object
 *		return < 1 => inside object
 *		return = 1 => on the object's surface
 *	.*derivative() => the derivative of the io function, in object space
 *	.*xyz_uv() => converts a given point in world-space on the surface of the
 *	object to angles u,v in terms of the object
 *	.*norm() => returns the unit normal of a point on an objects surface defined
 *	using the angles u,v
 */

t_vec3
	sq_wp_op(
		t_vec3 pw,
		struct s_rt_element_superquadric s
		);	// FILE: math/superquadric/worldspace_to_objectspace.c
t_line
	sq_wl_ol(
		t_line lw,
		struct s_rt_element_superquadric s
		);	// FILE: math/superquadric/worldspace_to_objectspace.c

/*	Ellipsoids */
double
	sq_e_io(
		t_vec3 pw,
		struct s_rt_element_superquadric s
		);	// FILE: math/superquadric/ellipsoid/e_io_func.c
t_uv
	sq_e_xyz_uv(
		t_vec3 pw,
		struct s_rt_element_superquadric s
		);	// FILE: math/superquadric/ellipsoid/e_xyz_to_uv.c
t_norm
	sq_e_norm(
		t_uv uv,
		struct s_rt_element_superquadric s
		);	// FILE: math/superquadric/ellipsoid/e_norm.c
double
	sq_e_int(
		t_line lw,
		struct s_rt_element_superquadric s
		);	// FILE: math/superquadric/ellipsoid/e_intersection.c
double
	sq_e_derivative(
		t_line l,
		t_vec3 p,
		struct s_rt_element_superquadric s
		);	// FILE: math/superquadric/ellipsoid/e_derivative.c
#endif // MINIRT_MATH_SUPERQUADRICS_H
