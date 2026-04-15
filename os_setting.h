/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:51:59 by mitsato           #+#    #+#             */
/*   Updated: 2026/04/11 15:08:10 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OS_SETTING_H
# define OS_SETTING_H

typedef enum e_os
{
	LINUX_OS = 0,
	MAC_OS,
}			t_os;

#define OS MAC_OS

#endif
