/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 18:58:40 by mitsato           #+#    #+#             */
/*   Updated: 2026/04/18 19:34:06 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
#define HITTABLE_H

# include "minirt.h"

typedef struct s_hit_record {
  t_vec_three p;
  t_vec_three normal;
  double t;
  bool front_face;
}				t_hit_record;


//   inline void set_face_normal(const ray& r, const vec3& outward_normal) {
//     front_face = dot(r.direction(), outward_normal) < 0;
//     normal = front_face ? outward_normal :-outward_normal;
//   }

// class hittable {
// public:
// virtual ~hittable() {}
// bool hit( const ray& r, double t_min, double t_max, hit_record& rec );

#endif

// ----------------------------------------------------------------------- //

// #ifndef SPHERE_H
// #define SPHERE_H

// #include "hittable.h"
// #include "vec3.h"

// class sphere: public hittable {
// public:
//   sphere() {}
//   sphere(point3 cen, double r) : center(cen), radius(r) {}

//   virtual bool hit(
//     const ray& r, double tmin, double tmax, hit_record& rec
//   ) const;

// public:
//   point3 center;
//   double radius;
// };

// bool sphere::hit(
//   const ray& r, double t_min, double t_max, hit_record& rec
// ) const {
//   vec3 oc = r.origin() - center;
//   auto a = r.direction().length_squared();
//   auto half_b = dot(oc, r.direction());
//   auto c = oc.length_squared() - radius*radius;
//   auto discriminant = half_b*half_b - a*c;

//   if (discriminant > 0) {
//     auto root = sqrt(discriminant);
//     auto temp = (-half_b - root)/a;
//     if (temp < t_max && temp > t_min) {
//       rec.t = temp;
//       rec.p = r.at(rec.t);
//       rec.normal = (rec.p - center) / radius;
//       return true;
//     }
//     temp = (-half_b + root) / a;
//     if (temp < t_max && temp > t_min) {
//       rec.t = temp;
//       rec.p = r.at(rec.t);
//       rec.normal = (rec.p - center) / radius;
//       return true;
//     }
//   }
//   return false;
// }

// #endif
